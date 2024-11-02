#define SOKOL_GLCORE
#define SOKOL_IMPL
#define dlopen cosmo_dlopen
#define dlsym cosmo_dlsym
#define SOKOL_NO_ENTRY
#define sokol_main linux_sokol_main

#ifndef __linux__
#define __linux__
#endif

#include "sokol_linux.h"
#include "sokol_app.h"
#include "sokol_gfx.h"
