#include "sokol_Linux.h"
#define SOKOL_GLCORE
#define SOKOL_IMPL
#define dlopen cosmo_dlopen
#define dlsym cosmo_dlsym
#define SOKOL_NO_ENTRY
#include "sokol_app.h"
