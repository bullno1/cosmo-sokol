#include "sokol_Linux.h"
#define SOKOL_GLCORE
#define SOKOL_IMPL
#define dlopen cosmo_dlopen
#define dlsym cosmo_dlsym
#define SOKOL_NO_ENTRY
#define sokol_main sokol_Linux_main
#include "sokol_app.h"
#include "sokol_gfx.h"
