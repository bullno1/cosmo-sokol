# cosmo-sokol

![Build status](https://github.com/bullno1/cosmo-sokol/actions/workflows/build.yml/badge.svg)

Sample sokol+dearimgui application compiled with [cosmopolitan toolchain](https://github.com/jart/cosmopolitan/).

## Build instruction

Download cosmocc at: https://github.com/jart/cosmopolitan/releases.
At least v3.9.5 is required.
With cosmocc in your PATH, run `./build`.

Then run `bin/cosmo-sokol`.

Note: On Windows, if you are using a NVIDIA graphic card, you may have to disable "Threaded optimization".

Checkout the [github workflow](.github/workflows/build.yml) for all the required dependencies.

## How it works
### Linux

Platform header directories are symlinked into the `shims/linux`.
This is done instead of adding `-I/usr/include` so that we can restrict what is exposed to the compiler.

Using dlopen, all required dynamic libraries can be dynamically loaded.
Instead of linking directly to those libraries (e.g: libgl, libx11...), we can link to a stub implementation.
When called, it will load the actual library and forward the call to the actual implementation.
e.g: the stub `XPending` dynamically loads `libX11.so` and then forward the call to the actual `XPending` retrieved through dlsym.

[gen-x11](shims/linux/gen-x11) is a Python script that generates [x11.c](shims/linux/x11.c).
All undefined references have to be manually added to the list of generated functions.
Take note that a nullary function such as [XInitThreads](https://www.x.org/archive/X11R7.5/doc/man/man3/XInitThreads.3.html) have to be declared as: `Status XInitThreads()`.

For OpenGL, the exhaustive list of functions can be found at: https://github.com/KhronosGroup/OpenGL-Registry/blob/main/xml/gl.xml.
[gen-gl](shims/linux/gen-gl) simply requires a minimum version number to generate [gl.c](shims/linux/gl.c).

### Windows

cosmopolitan's own headers lack a lot of Windows function prototype so we have to ignore `implicit-function-declaration`.
However, it has a simple way to import required win32 functions: https://github.com/jart/cosmopolitan/blob/master/libc/nt/master.sh.
Simply list the name, dll and arity in that file.
This requires making upstream changes to cosmopolitan.
As of this writing, the required changes are merged and `sokol_app` + `sokol_gfx` can run on Windows.

### Multi-platform runtime

sokol makes use of platform ifdef to selectively compile platform-dependent code.
In cosmopolitan, we want to compile all platform-dependent code paths and select the right implementation at runtime instead.

In order to do that with the same library, we can use the following preprocessor trick:

1. For each platform, prefix every sokol public function with its platform name.
   e.g: `sapp_show_keyboard` becomes `linux_sapp_show_keyboard` and `windows_sapp_show_keyboard`.

   This can simply be done by `#define sapp_show_keyboard linux_sapp_show_keyboard` right before including `sokol_app.h`.
2. Create a multi-platform shim ([`sokol_cosmo.c`](shims/sokol/sokol_cosmo.c)) that selects the right implementation at runtime.

[gen-sokol](shims/sokol/gen-sokol) takes in a list of sokol public functions and generate the required `#define`-s and the cosmo shim.
