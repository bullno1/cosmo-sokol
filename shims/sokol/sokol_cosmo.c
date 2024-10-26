
#include <sokol_app.h>
#include <cosmo.h>
#pragma GCC diagnostic ignored "-Wreturn-type"

extern bool sapp_Linux_isvalid(void);
extern bool sapp_Windows_isvalid(void);
bool sapp_isvalid(void) {
    if (IsLinux()) {
        return sapp_Linux_isvalid();
    }
    if (IsWindows()) {
        return sapp_Windows_isvalid();
    }
}

extern int sapp_Linux_width(void);
extern int sapp_Windows_width(void);
int sapp_width(void) {
    if (IsLinux()) {
        return sapp_Linux_width();
    }
    if (IsWindows()) {
        return sapp_Windows_width();
    }
}

extern float sapp_Linux_widthf(void);
extern float sapp_Windows_widthf(void);
float sapp_widthf(void) {
    if (IsLinux()) {
        return sapp_Linux_widthf();
    }
    if (IsWindows()) {
        return sapp_Windows_widthf();
    }
}

extern int sapp_Linux_height(void);
extern int sapp_Windows_height(void);
int sapp_height(void) {
    if (IsLinux()) {
        return sapp_Linux_height();
    }
    if (IsWindows()) {
        return sapp_Windows_height();
    }
}

extern float sapp_Linux_heightf(void);
extern float sapp_Windows_heightf(void);
float sapp_heightf(void) {
    if (IsLinux()) {
        return sapp_Linux_heightf();
    }
    if (IsWindows()) {
        return sapp_Windows_heightf();
    }
}

extern int sapp_Linux_color_format(void);
extern int sapp_Windows_color_format(void);
int sapp_color_format(void) {
    if (IsLinux()) {
        return sapp_Linux_color_format();
    }
    if (IsWindows()) {
        return sapp_Windows_color_format();
    }
}

extern int sapp_Linux_depth_format(void);
extern int sapp_Windows_depth_format(void);
int sapp_depth_format(void) {
    if (IsLinux()) {
        return sapp_Linux_depth_format();
    }
    if (IsWindows()) {
        return sapp_Windows_depth_format();
    }
}

extern int sapp_Linux_sample_count(void);
extern int sapp_Windows_sample_count(void);
int sapp_sample_count(void) {
    if (IsLinux()) {
        return sapp_Linux_sample_count();
    }
    if (IsWindows()) {
        return sapp_Windows_sample_count();
    }
}

extern bool sapp_Linux_high_dpi(void);
extern bool sapp_Windows_high_dpi(void);
bool sapp_high_dpi(void) {
    if (IsLinux()) {
        return sapp_Linux_high_dpi();
    }
    if (IsWindows()) {
        return sapp_Windows_high_dpi();
    }
}

extern float sapp_Linux_dpi_scale(void);
extern float sapp_Windows_dpi_scale(void);
float sapp_dpi_scale(void) {
    if (IsLinux()) {
        return sapp_Linux_dpi_scale();
    }
    if (IsWindows()) {
        return sapp_Windows_dpi_scale();
    }
}

extern void sapp_Linux_show_keyboard(bool show);
extern void sapp_Windows_show_keyboard(bool show);
void sapp_show_keyboard(bool show) {
    if (IsLinux()) {
        sapp_Linux_show_keyboard(show);
        return;
    }
    if (IsWindows()) {
        sapp_Windows_show_keyboard(show);
        return;
    }
}

extern bool sapp_Linux_keyboard_shown(void);
extern bool sapp_Windows_keyboard_shown(void);
bool sapp_keyboard_shown(void) {
    if (IsLinux()) {
        return sapp_Linux_keyboard_shown();
    }
    if (IsWindows()) {
        return sapp_Windows_keyboard_shown();
    }
}

extern bool sapp_Linux_is_fullscreen(void);
extern bool sapp_Windows_is_fullscreen(void);
bool sapp_is_fullscreen(void) {
    if (IsLinux()) {
        return sapp_Linux_is_fullscreen();
    }
    if (IsWindows()) {
        return sapp_Windows_is_fullscreen();
    }
}

extern void sapp_Linux_toggle_fullscreen(void);
extern void sapp_Windows_toggle_fullscreen(void);
void sapp_toggle_fullscreen(void) {
    if (IsLinux()) {
        sapp_Linux_toggle_fullscreen();
        return;
    }
    if (IsWindows()) {
        sapp_Windows_toggle_fullscreen();
        return;
    }
}

extern void sapp_Linux_show_mouse(bool show);
extern void sapp_Windows_show_mouse(bool show);
void sapp_show_mouse(bool show) {
    if (IsLinux()) {
        sapp_Linux_show_mouse(show);
        return;
    }
    if (IsWindows()) {
        sapp_Windows_show_mouse(show);
        return;
    }
}

extern bool sapp_Linux_mouse_shown(void);
extern bool sapp_Windows_mouse_shown(void);
bool sapp_mouse_shown(void) {
    if (IsLinux()) {
        return sapp_Linux_mouse_shown();
    }
    if (IsWindows()) {
        return sapp_Windows_mouse_shown();
    }
}

extern void sapp_Linux_lock_mouse(bool lock);
extern void sapp_Windows_lock_mouse(bool lock);
void sapp_lock_mouse(bool lock) {
    if (IsLinux()) {
        sapp_Linux_lock_mouse(lock);
        return;
    }
    if (IsWindows()) {
        sapp_Windows_lock_mouse(lock);
        return;
    }
}

extern bool sapp_Linux_mouse_locked(void);
extern bool sapp_Windows_mouse_locked(void);
bool sapp_mouse_locked(void) {
    if (IsLinux()) {
        return sapp_Linux_mouse_locked();
    }
    if (IsWindows()) {
        return sapp_Windows_mouse_locked();
    }
}

extern void sapp_Linux_set_mouse_cursor(sapp_mouse_cursor cursor);
extern void sapp_Windows_set_mouse_cursor(sapp_mouse_cursor cursor);
void sapp_set_mouse_cursor(sapp_mouse_cursor cursor) {
    if (IsLinux()) {
        sapp_Linux_set_mouse_cursor(cursor);
        return;
    }
    if (IsWindows()) {
        sapp_Windows_set_mouse_cursor(cursor);
        return;
    }
}

extern sapp_mouse_cursor sapp_Linux_get_mouse_cursor(void);
extern sapp_mouse_cursor sapp_Windows_get_mouse_cursor(void);
sapp_mouse_cursor sapp_get_mouse_cursor(void) {
    if (IsLinux()) {
        return sapp_Linux_get_mouse_cursor();
    }
    if (IsWindows()) {
        return sapp_Windows_get_mouse_cursor();
    }
}

extern void* sapp_Linux_userdata(void);
extern void* sapp_Windows_userdata(void);
void* sapp_userdata(void) {
    if (IsLinux()) {
        return sapp_Linux_userdata();
    }
    if (IsWindows()) {
        return sapp_Windows_userdata();
    }
}

extern sapp_desc sapp_Linux_query_desc(void);
extern sapp_desc sapp_Windows_query_desc(void);
sapp_desc sapp_query_desc(void) {
    if (IsLinux()) {
        return sapp_Linux_query_desc();
    }
    if (IsWindows()) {
        return sapp_Windows_query_desc();
    }
}

extern void sapp_Linux_request_quit(void);
extern void sapp_Windows_request_quit(void);
void sapp_request_quit(void) {
    if (IsLinux()) {
        sapp_Linux_request_quit();
        return;
    }
    if (IsWindows()) {
        sapp_Windows_request_quit();
        return;
    }
}

extern void sapp_Linux_cancel_quit(void);
extern void sapp_Windows_cancel_quit(void);
void sapp_cancel_quit(void) {
    if (IsLinux()) {
        sapp_Linux_cancel_quit();
        return;
    }
    if (IsWindows()) {
        sapp_Windows_cancel_quit();
        return;
    }
}

extern void sapp_Linux_quit(void);
extern void sapp_Windows_quit(void);
void sapp_quit(void) {
    if (IsLinux()) {
        sapp_Linux_quit();
        return;
    }
    if (IsWindows()) {
        sapp_Windows_quit();
        return;
    }
}

extern void sapp_Linux_consume_event(void);
extern void sapp_Windows_consume_event(void);
void sapp_consume_event(void) {
    if (IsLinux()) {
        sapp_Linux_consume_event();
        return;
    }
    if (IsWindows()) {
        sapp_Windows_consume_event();
        return;
    }
}

extern uint64_t sapp_Linux_frame_count(void);
extern uint64_t sapp_Windows_frame_count(void);
uint64_t sapp_frame_count(void) {
    if (IsLinux()) {
        return sapp_Linux_frame_count();
    }
    if (IsWindows()) {
        return sapp_Windows_frame_count();
    }
}

extern double sapp_Linux_frame_duration(void);
extern double sapp_Windows_frame_duration(void);
double sapp_frame_duration(void) {
    if (IsLinux()) {
        return sapp_Linux_frame_duration();
    }
    if (IsWindows()) {
        return sapp_Windows_frame_duration();
    }
}

extern void sapp_Linux_set_clipboard_string(const char* str);
extern void sapp_Windows_set_clipboard_string(const char* str);
void sapp_set_clipboard_string(const char* str) {
    if (IsLinux()) {
        sapp_Linux_set_clipboard_string(str);
        return;
    }
    if (IsWindows()) {
        sapp_Windows_set_clipboard_string(str);
        return;
    }
}

extern const char* sapp_Linux_get_clipboard_string(void);
extern const char* sapp_Windows_get_clipboard_string(void);
const char* sapp_get_clipboard_string(void) {
    if (IsLinux()) {
        return sapp_Linux_get_clipboard_string();
    }
    if (IsWindows()) {
        return sapp_Windows_get_clipboard_string();
    }
}

extern void sapp_Linux_set_window_title(const char* str);
extern void sapp_Windows_set_window_title(const char* str);
void sapp_set_window_title(const char* str) {
    if (IsLinux()) {
        sapp_Linux_set_window_title(str);
        return;
    }
    if (IsWindows()) {
        sapp_Windows_set_window_title(str);
        return;
    }
}

extern void sapp_Linux_set_icon(const sapp_icon_desc* icon_desc);
extern void sapp_Windows_set_icon(const sapp_icon_desc* icon_desc);
void sapp_set_icon(const sapp_icon_desc* icon_desc) {
    if (IsLinux()) {
        sapp_Linux_set_icon(icon_desc);
        return;
    }
    if (IsWindows()) {
        sapp_Windows_set_icon(icon_desc);
        return;
    }
}

extern int sapp_Linux_get_num_dropped_files(void);
extern int sapp_Windows_get_num_dropped_files(void);
int sapp_get_num_dropped_files(void) {
    if (IsLinux()) {
        return sapp_Linux_get_num_dropped_files();
    }
    if (IsWindows()) {
        return sapp_Windows_get_num_dropped_files();
    }
}

extern const char* sapp_Linux_get_dropped_file_path(int index);
extern const char* sapp_Windows_get_dropped_file_path(int index);
const char* sapp_get_dropped_file_path(int index) {
    if (IsLinux()) {
        return sapp_Linux_get_dropped_file_path(index);
    }
    if (IsWindows()) {
        return sapp_Windows_get_dropped_file_path(index);
    }
}

extern void sapp_Linux_run(const sapp_desc* desc);
extern void sapp_Windows_run(const sapp_desc* desc);
void sapp_run(const sapp_desc* desc) {
    if (IsLinux()) {
        sapp_Linux_run(desc);
        return;
    }
    if (IsWindows()) {
        sapp_Windows_run(desc);
        return;
    }
}

extern const void* sapp_Linux_egl_get_display(void);
extern const void* sapp_Windows_egl_get_display(void);
const void* sapp_egl_get_display(void) {
    if (IsLinux()) {
        return sapp_Linux_egl_get_display();
    }
    if (IsWindows()) {
        return sapp_Windows_egl_get_display();
    }
}

extern const void* sapp_Linux_egl_get_context(void);
extern const void* sapp_Windows_egl_get_context(void);
const void* sapp_egl_get_context(void) {
    if (IsLinux()) {
        return sapp_Linux_egl_get_context();
    }
    if (IsWindows()) {
        return sapp_Windows_egl_get_context();
    }
}

extern void sapp_Linux_html5_ask_leave_site(bool ask);
extern void sapp_Windows_html5_ask_leave_site(bool ask);
void sapp_html5_ask_leave_site(bool ask) {
    if (IsLinux()) {
        sapp_Linux_html5_ask_leave_site(ask);
        return;
    }
    if (IsWindows()) {
        sapp_Windows_html5_ask_leave_site(ask);
        return;
    }
}

extern uint32_t sapp_Linux_html5_get_dropped_file_size(int index);
extern uint32_t sapp_Windows_html5_get_dropped_file_size(int index);
uint32_t sapp_html5_get_dropped_file_size(int index) {
    if (IsLinux()) {
        return sapp_Linux_html5_get_dropped_file_size(index);
    }
    if (IsWindows()) {
        return sapp_Windows_html5_get_dropped_file_size(index);
    }
}

extern void sapp_Linux_html5_fetch_dropped_file(const sapp_html5_fetch_request* request);
extern void sapp_Windows_html5_fetch_dropped_file(const sapp_html5_fetch_request* request);
void sapp_html5_fetch_dropped_file(const sapp_html5_fetch_request* request) {
    if (IsLinux()) {
        sapp_Linux_html5_fetch_dropped_file(request);
        return;
    }
    if (IsWindows()) {
        sapp_Windows_html5_fetch_dropped_file(request);
        return;
    }
}

extern const void* sapp_Linux_metal_get_device(void);
extern const void* sapp_Windows_metal_get_device(void);
const void* sapp_metal_get_device(void) {
    if (IsLinux()) {
        return sapp_Linux_metal_get_device();
    }
    if (IsWindows()) {
        return sapp_Windows_metal_get_device();
    }
}

extern const void* sapp_Linux_metal_get_current_drawable(void);
extern const void* sapp_Windows_metal_get_current_drawable(void);
const void* sapp_metal_get_current_drawable(void) {
    if (IsLinux()) {
        return sapp_Linux_metal_get_current_drawable();
    }
    if (IsWindows()) {
        return sapp_Windows_metal_get_current_drawable();
    }
}

extern const void* sapp_Linux_metal_get_depth_stencil_texture(void);
extern const void* sapp_Windows_metal_get_depth_stencil_texture(void);
const void* sapp_metal_get_depth_stencil_texture(void) {
    if (IsLinux()) {
        return sapp_Linux_metal_get_depth_stencil_texture();
    }
    if (IsWindows()) {
        return sapp_Windows_metal_get_depth_stencil_texture();
    }
}

extern const void* sapp_Linux_metal_get_msaa_color_texture(void);
extern const void* sapp_Windows_metal_get_msaa_color_texture(void);
const void* sapp_metal_get_msaa_color_texture(void) {
    if (IsLinux()) {
        return sapp_Linux_metal_get_msaa_color_texture();
    }
    if (IsWindows()) {
        return sapp_Windows_metal_get_msaa_color_texture();
    }
}

extern const void* sapp_Linux_macos_get_window(void);
extern const void* sapp_Windows_macos_get_window(void);
const void* sapp_macos_get_window(void) {
    if (IsLinux()) {
        return sapp_Linux_macos_get_window();
    }
    if (IsWindows()) {
        return sapp_Windows_macos_get_window();
    }
}

extern const void* sapp_Linux_ios_get_window(void);
extern const void* sapp_Windows_ios_get_window(void);
const void* sapp_ios_get_window(void) {
    if (IsLinux()) {
        return sapp_Linux_ios_get_window();
    }
    if (IsWindows()) {
        return sapp_Windows_ios_get_window();
    }
}

extern const void* sapp_Linux_d3d11_get_device(void);
extern const void* sapp_Windows_d3d11_get_device(void);
const void* sapp_d3d11_get_device(void) {
    if (IsLinux()) {
        return sapp_Linux_d3d11_get_device();
    }
    if (IsWindows()) {
        return sapp_Windows_d3d11_get_device();
    }
}

extern const void* sapp_Linux_d3d11_get_device_context(void);
extern const void* sapp_Windows_d3d11_get_device_context(void);
const void* sapp_d3d11_get_device_context(void) {
    if (IsLinux()) {
        return sapp_Linux_d3d11_get_device_context();
    }
    if (IsWindows()) {
        return sapp_Windows_d3d11_get_device_context();
    }
}

extern const void* sapp_Linux_d3d11_get_swap_chain(void);
extern const void* sapp_Windows_d3d11_get_swap_chain(void);
const void* sapp_d3d11_get_swap_chain(void) {
    if (IsLinux()) {
        return sapp_Linux_d3d11_get_swap_chain();
    }
    if (IsWindows()) {
        return sapp_Windows_d3d11_get_swap_chain();
    }
}

extern const void* sapp_Linux_d3d11_get_render_view(void);
extern const void* sapp_Windows_d3d11_get_render_view(void);
const void* sapp_d3d11_get_render_view(void) {
    if (IsLinux()) {
        return sapp_Linux_d3d11_get_render_view();
    }
    if (IsWindows()) {
        return sapp_Windows_d3d11_get_render_view();
    }
}

extern const void* sapp_Linux_d3d11_get_resolve_view(void);
extern const void* sapp_Windows_d3d11_get_resolve_view(void);
const void* sapp_d3d11_get_resolve_view(void) {
    if (IsLinux()) {
        return sapp_Linux_d3d11_get_resolve_view();
    }
    if (IsWindows()) {
        return sapp_Windows_d3d11_get_resolve_view();
    }
}

extern const void* sapp_Linux_d3d11_get_depth_stencil_view(void);
extern const void* sapp_Windows_d3d11_get_depth_stencil_view(void);
const void* sapp_d3d11_get_depth_stencil_view(void) {
    if (IsLinux()) {
        return sapp_Linux_d3d11_get_depth_stencil_view();
    }
    if (IsWindows()) {
        return sapp_Windows_d3d11_get_depth_stencil_view();
    }
}

extern const void* sapp_Linux_win32_get_hwnd(void);
extern const void* sapp_Windows_win32_get_hwnd(void);
const void* sapp_win32_get_hwnd(void) {
    if (IsLinux()) {
        return sapp_Linux_win32_get_hwnd();
    }
    if (IsWindows()) {
        return sapp_Windows_win32_get_hwnd();
    }
}

extern const void* sapp_Linux_wgpu_get_device(void);
extern const void* sapp_Windows_wgpu_get_device(void);
const void* sapp_wgpu_get_device(void) {
    if (IsLinux()) {
        return sapp_Linux_wgpu_get_device();
    }
    if (IsWindows()) {
        return sapp_Windows_wgpu_get_device();
    }
}

extern const void* sapp_Linux_wgpu_get_render_view(void);
extern const void* sapp_Windows_wgpu_get_render_view(void);
const void* sapp_wgpu_get_render_view(void) {
    if (IsLinux()) {
        return sapp_Linux_wgpu_get_render_view();
    }
    if (IsWindows()) {
        return sapp_Windows_wgpu_get_render_view();
    }
}

extern const void* sapp_Linux_wgpu_get_resolve_view(void);
extern const void* sapp_Windows_wgpu_get_resolve_view(void);
const void* sapp_wgpu_get_resolve_view(void) {
    if (IsLinux()) {
        return sapp_Linux_wgpu_get_resolve_view();
    }
    if (IsWindows()) {
        return sapp_Windows_wgpu_get_resolve_view();
    }
}

extern const void* sapp_Linux_wgpu_get_depth_stencil_view(void);
extern const void* sapp_Windows_wgpu_get_depth_stencil_view(void);
const void* sapp_wgpu_get_depth_stencil_view(void) {
    if (IsLinux()) {
        return sapp_Linux_wgpu_get_depth_stencil_view();
    }
    if (IsWindows()) {
        return sapp_Windows_wgpu_get_depth_stencil_view();
    }
}

extern uint32_t sapp_Linux_gl_get_framebuffer(void);
extern uint32_t sapp_Windows_gl_get_framebuffer(void);
uint32_t sapp_gl_get_framebuffer(void) {
    if (IsLinux()) {
        return sapp_Linux_gl_get_framebuffer();
    }
    if (IsWindows()) {
        return sapp_Windows_gl_get_framebuffer();
    }
}

extern int sapp_Linux_gl_get_major_version(void);
extern int sapp_Windows_gl_get_major_version(void);
int sapp_gl_get_major_version(void) {
    if (IsLinux()) {
        return sapp_Linux_gl_get_major_version();
    }
    if (IsWindows()) {
        return sapp_Windows_gl_get_major_version();
    }
}

extern int sapp_Linux_gl_get_minor_version(void);
extern int sapp_Windows_gl_get_minor_version(void);
int sapp_gl_get_minor_version(void) {
    if (IsLinux()) {
        return sapp_Linux_gl_get_minor_version();
    }
    if (IsWindows()) {
        return sapp_Windows_gl_get_minor_version();
    }
}

extern const void* sapp_Linux_android_get_native_activity(void);
extern const void* sapp_Windows_android_get_native_activity(void);
const void* sapp_android_get_native_activity(void) {
    if (IsLinux()) {
        return sapp_Linux_android_get_native_activity();
    }
    if (IsWindows()) {
        return sapp_Windows_android_get_native_activity();
    }
}

