#include <sokol_app.h>
#include <sokol_gfx.h>
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

extern void sg_Linux_setup(const sg_desc* desc);
extern void sg_Windows_setup(const sg_desc* desc);
void sg_setup(const sg_desc* desc) {
    if (IsLinux()) {
        sg_Linux_setup(desc);
        return;
    }
    if (IsWindows()) {
        sg_Windows_setup(desc);
        return;
    }
}

extern void sg_Linux_shutdown(void);
extern void sg_Windows_shutdown(void);
void sg_shutdown(void) {
    if (IsLinux()) {
        sg_Linux_shutdown();
        return;
    }
    if (IsWindows()) {
        sg_Windows_shutdown();
        return;
    }
}

extern bool sg_Linux_isvalid(void);
extern bool sg_Windows_isvalid(void);
bool sg_isvalid(void) {
    if (IsLinux()) {
        return sg_Linux_isvalid();
    }
    if (IsWindows()) {
        return sg_Windows_isvalid();
    }
}

extern void sg_Linux_reset_state_cache(void);
extern void sg_Windows_reset_state_cache(void);
void sg_reset_state_cache(void) {
    if (IsLinux()) {
        sg_Linux_reset_state_cache();
        return;
    }
    if (IsWindows()) {
        sg_Windows_reset_state_cache();
        return;
    }
}

extern sg_trace_hooks sg_Linux_install_trace_hooks(const sg_trace_hooks* trace_hooks);
extern sg_trace_hooks sg_Windows_install_trace_hooks(const sg_trace_hooks* trace_hooks);
sg_trace_hooks sg_install_trace_hooks(const sg_trace_hooks* trace_hooks) {
    if (IsLinux()) {
        return sg_Linux_install_trace_hooks(trace_hooks);
    }
    if (IsWindows()) {
        return sg_Windows_install_trace_hooks(trace_hooks);
    }
}

extern void sg_Linux_push_debug_group(const char* name);
extern void sg_Windows_push_debug_group(const char* name);
void sg_push_debug_group(const char* name) {
    if (IsLinux()) {
        sg_Linux_push_debug_group(name);
        return;
    }
    if (IsWindows()) {
        sg_Windows_push_debug_group(name);
        return;
    }
}

extern void sg_Linux_pop_debug_group(void);
extern void sg_Windows_pop_debug_group(void);
void sg_pop_debug_group(void) {
    if (IsLinux()) {
        sg_Linux_pop_debug_group();
        return;
    }
    if (IsWindows()) {
        sg_Windows_pop_debug_group();
        return;
    }
}

extern bool sg_Linux_add_commit_listener(sg_commit_listener listener);
extern bool sg_Windows_add_commit_listener(sg_commit_listener listener);
bool sg_add_commit_listener(sg_commit_listener listener) {
    if (IsLinux()) {
        return sg_Linux_add_commit_listener(listener);
    }
    if (IsWindows()) {
        return sg_Windows_add_commit_listener(listener);
    }
}

extern bool sg_Linux_remove_commit_listener(sg_commit_listener listener);
extern bool sg_Windows_remove_commit_listener(sg_commit_listener listener);
bool sg_remove_commit_listener(sg_commit_listener listener) {
    if (IsLinux()) {
        return sg_Linux_remove_commit_listener(listener);
    }
    if (IsWindows()) {
        return sg_Windows_remove_commit_listener(listener);
    }
}

extern sg_buffer sg_Linux_make_buffer(const sg_buffer_desc* desc);
extern sg_buffer sg_Windows_make_buffer(const sg_buffer_desc* desc);
sg_buffer sg_make_buffer(const sg_buffer_desc* desc) {
    if (IsLinux()) {
        return sg_Linux_make_buffer(desc);
    }
    if (IsWindows()) {
        return sg_Windows_make_buffer(desc);
    }
}

extern sg_image sg_Linux_make_image(const sg_image_desc* desc);
extern sg_image sg_Windows_make_image(const sg_image_desc* desc);
sg_image sg_make_image(const sg_image_desc* desc) {
    if (IsLinux()) {
        return sg_Linux_make_image(desc);
    }
    if (IsWindows()) {
        return sg_Windows_make_image(desc);
    }
}

extern sg_sampler sg_Linux_make_sampler(const sg_sampler_desc* desc);
extern sg_sampler sg_Windows_make_sampler(const sg_sampler_desc* desc);
sg_sampler sg_make_sampler(const sg_sampler_desc* desc) {
    if (IsLinux()) {
        return sg_Linux_make_sampler(desc);
    }
    if (IsWindows()) {
        return sg_Windows_make_sampler(desc);
    }
}

extern sg_shader sg_Linux_make_shader(const sg_shader_desc* desc);
extern sg_shader sg_Windows_make_shader(const sg_shader_desc* desc);
sg_shader sg_make_shader(const sg_shader_desc* desc) {
    if (IsLinux()) {
        return sg_Linux_make_shader(desc);
    }
    if (IsWindows()) {
        return sg_Windows_make_shader(desc);
    }
}

extern sg_pipeline sg_Linux_make_pipeline(const sg_pipeline_desc* desc);
extern sg_pipeline sg_Windows_make_pipeline(const sg_pipeline_desc* desc);
sg_pipeline sg_make_pipeline(const sg_pipeline_desc* desc) {
    if (IsLinux()) {
        return sg_Linux_make_pipeline(desc);
    }
    if (IsWindows()) {
        return sg_Windows_make_pipeline(desc);
    }
}

extern sg_attachments sg_Linux_make_attachments(const sg_attachments_desc* desc);
extern sg_attachments sg_Windows_make_attachments(const sg_attachments_desc* desc);
sg_attachments sg_make_attachments(const sg_attachments_desc* desc) {
    if (IsLinux()) {
        return sg_Linux_make_attachments(desc);
    }
    if (IsWindows()) {
        return sg_Windows_make_attachments(desc);
    }
}

extern void sg_Linux_destroy_buffer(sg_buffer buf);
extern void sg_Windows_destroy_buffer(sg_buffer buf);
void sg_destroy_buffer(sg_buffer buf) {
    if (IsLinux()) {
        sg_Linux_destroy_buffer(buf);
        return;
    }
    if (IsWindows()) {
        sg_Windows_destroy_buffer(buf);
        return;
    }
}

extern void sg_Linux_destroy_image(sg_image img);
extern void sg_Windows_destroy_image(sg_image img);
void sg_destroy_image(sg_image img) {
    if (IsLinux()) {
        sg_Linux_destroy_image(img);
        return;
    }
    if (IsWindows()) {
        sg_Windows_destroy_image(img);
        return;
    }
}

extern void sg_Linux_destroy_sampler(sg_sampler smp);
extern void sg_Windows_destroy_sampler(sg_sampler smp);
void sg_destroy_sampler(sg_sampler smp) {
    if (IsLinux()) {
        sg_Linux_destroy_sampler(smp);
        return;
    }
    if (IsWindows()) {
        sg_Windows_destroy_sampler(smp);
        return;
    }
}

extern void sg_Linux_destroy_shader(sg_shader shd);
extern void sg_Windows_destroy_shader(sg_shader shd);
void sg_destroy_shader(sg_shader shd) {
    if (IsLinux()) {
        sg_Linux_destroy_shader(shd);
        return;
    }
    if (IsWindows()) {
        sg_Windows_destroy_shader(shd);
        return;
    }
}

extern void sg_Linux_destroy_pipeline(sg_pipeline pip);
extern void sg_Windows_destroy_pipeline(sg_pipeline pip);
void sg_destroy_pipeline(sg_pipeline pip) {
    if (IsLinux()) {
        sg_Linux_destroy_pipeline(pip);
        return;
    }
    if (IsWindows()) {
        sg_Windows_destroy_pipeline(pip);
        return;
    }
}

extern void sg_Linux_destroy_attachments(sg_attachments atts);
extern void sg_Windows_destroy_attachments(sg_attachments atts);
void sg_destroy_attachments(sg_attachments atts) {
    if (IsLinux()) {
        sg_Linux_destroy_attachments(atts);
        return;
    }
    if (IsWindows()) {
        sg_Windows_destroy_attachments(atts);
        return;
    }
}

extern void sg_Linux_update_buffer(sg_buffer buf, const sg_range* data);
extern void sg_Windows_update_buffer(sg_buffer buf, const sg_range* data);
void sg_update_buffer(sg_buffer buf, const sg_range* data) {
    if (IsLinux()) {
        sg_Linux_update_buffer(buf, data);
        return;
    }
    if (IsWindows()) {
        sg_Windows_update_buffer(buf, data);
        return;
    }
}

extern void sg_Linux_update_image(sg_image img, const sg_image_data* data);
extern void sg_Windows_update_image(sg_image img, const sg_image_data* data);
void sg_update_image(sg_image img, const sg_image_data* data) {
    if (IsLinux()) {
        sg_Linux_update_image(img, data);
        return;
    }
    if (IsWindows()) {
        sg_Windows_update_image(img, data);
        return;
    }
}

extern int sg_Linux_append_buffer(sg_buffer buf, const sg_range* data);
extern int sg_Windows_append_buffer(sg_buffer buf, const sg_range* data);
int sg_append_buffer(sg_buffer buf, const sg_range* data) {
    if (IsLinux()) {
        return sg_Linux_append_buffer(buf, data);
    }
    if (IsWindows()) {
        return sg_Windows_append_buffer(buf, data);
    }
}

extern bool sg_Linux_query_buffer_overflow(sg_buffer buf);
extern bool sg_Windows_query_buffer_overflow(sg_buffer buf);
bool sg_query_buffer_overflow(sg_buffer buf) {
    if (IsLinux()) {
        return sg_Linux_query_buffer_overflow(buf);
    }
    if (IsWindows()) {
        return sg_Windows_query_buffer_overflow(buf);
    }
}

extern bool sg_Linux_query_buffer_will_overflow(sg_buffer buf, size_t size);
extern bool sg_Windows_query_buffer_will_overflow(sg_buffer buf, size_t size);
bool sg_query_buffer_will_overflow(sg_buffer buf, size_t size) {
    if (IsLinux()) {
        return sg_Linux_query_buffer_will_overflow(buf, size);
    }
    if (IsWindows()) {
        return sg_Windows_query_buffer_will_overflow(buf, size);
    }
}

extern void sg_Linux_begin_pass(const sg_pass* pass);
extern void sg_Windows_begin_pass(const sg_pass* pass);
void sg_begin_pass(const sg_pass* pass) {
    if (IsLinux()) {
        sg_Linux_begin_pass(pass);
        return;
    }
    if (IsWindows()) {
        sg_Windows_begin_pass(pass);
        return;
    }
}

extern void sg_Linux_apply_viewport(int x, int y, int width, int height, bool origin_top_left);
extern void sg_Windows_apply_viewport(int x, int y, int width, int height, bool origin_top_left);
void sg_apply_viewport(int x, int y, int width, int height, bool origin_top_left) {
    if (IsLinux()) {
        sg_Linux_apply_viewport(x, y, width, height, origin_top_left);
        return;
    }
    if (IsWindows()) {
        sg_Windows_apply_viewport(x, y, width, height, origin_top_left);
        return;
    }
}

extern void sg_Linux_apply_viewportf(float x, float y, float width, float height, bool origin_top_left);
extern void sg_Windows_apply_viewportf(float x, float y, float width, float height, bool origin_top_left);
void sg_apply_viewportf(float x, float y, float width, float height, bool origin_top_left) {
    if (IsLinux()) {
        sg_Linux_apply_viewportf(x, y, width, height, origin_top_left);
        return;
    }
    if (IsWindows()) {
        sg_Windows_apply_viewportf(x, y, width, height, origin_top_left);
        return;
    }
}

extern void sg_Linux_apply_scissor_rect(int x, int y, int width, int height, bool origin_top_left);
extern void sg_Windows_apply_scissor_rect(int x, int y, int width, int height, bool origin_top_left);
void sg_apply_scissor_rect(int x, int y, int width, int height, bool origin_top_left) {
    if (IsLinux()) {
        sg_Linux_apply_scissor_rect(x, y, width, height, origin_top_left);
        return;
    }
    if (IsWindows()) {
        sg_Windows_apply_scissor_rect(x, y, width, height, origin_top_left);
        return;
    }
}

extern void sg_Linux_apply_scissor_rectf(float x, float y, float width, float height, bool origin_top_left);
extern void sg_Windows_apply_scissor_rectf(float x, float y, float width, float height, bool origin_top_left);
void sg_apply_scissor_rectf(float x, float y, float width, float height, bool origin_top_left) {
    if (IsLinux()) {
        sg_Linux_apply_scissor_rectf(x, y, width, height, origin_top_left);
        return;
    }
    if (IsWindows()) {
        sg_Windows_apply_scissor_rectf(x, y, width, height, origin_top_left);
        return;
    }
}

extern void sg_Linux_apply_pipeline(sg_pipeline pip);
extern void sg_Windows_apply_pipeline(sg_pipeline pip);
void sg_apply_pipeline(sg_pipeline pip) {
    if (IsLinux()) {
        sg_Linux_apply_pipeline(pip);
        return;
    }
    if (IsWindows()) {
        sg_Windows_apply_pipeline(pip);
        return;
    }
}

extern void sg_Linux_apply_bindings(const sg_bindings* bindings);
extern void sg_Windows_apply_bindings(const sg_bindings* bindings);
void sg_apply_bindings(const sg_bindings* bindings) {
    if (IsLinux()) {
        sg_Linux_apply_bindings(bindings);
        return;
    }
    if (IsWindows()) {
        sg_Windows_apply_bindings(bindings);
        return;
    }
}

extern void sg_Linux_apply_uniforms(sg_shader_stage stage, int ub_index, const sg_range* data);
extern void sg_Windows_apply_uniforms(sg_shader_stage stage, int ub_index, const sg_range* data);
void sg_apply_uniforms(sg_shader_stage stage, int ub_index, const sg_range* data) {
    if (IsLinux()) {
        sg_Linux_apply_uniforms(stage, ub_index, data);
        return;
    }
    if (IsWindows()) {
        sg_Windows_apply_uniforms(stage, ub_index, data);
        return;
    }
}

extern void sg_Linux_draw(int base_element, int num_elements, int num_instances);
extern void sg_Windows_draw(int base_element, int num_elements, int num_instances);
void sg_draw(int base_element, int num_elements, int num_instances) {
    if (IsLinux()) {
        sg_Linux_draw(base_element, num_elements, num_instances);
        return;
    }
    if (IsWindows()) {
        sg_Windows_draw(base_element, num_elements, num_instances);
        return;
    }
}

extern void sg_Linux_end_pass(void);
extern void sg_Windows_end_pass(void);
void sg_end_pass(void) {
    if (IsLinux()) {
        sg_Linux_end_pass();
        return;
    }
    if (IsWindows()) {
        sg_Windows_end_pass();
        return;
    }
}

extern void sg_Linux_commit(void);
extern void sg_Windows_commit(void);
void sg_commit(void) {
    if (IsLinux()) {
        sg_Linux_commit();
        return;
    }
    if (IsWindows()) {
        sg_Windows_commit();
        return;
    }
}

extern sg_desc sg_Linux_query_desc(void);
extern sg_desc sg_Windows_query_desc(void);
sg_desc sg_query_desc(void) {
    if (IsLinux()) {
        return sg_Linux_query_desc();
    }
    if (IsWindows()) {
        return sg_Windows_query_desc();
    }
}

extern sg_backend sg_Linux_query_backend(void);
extern sg_backend sg_Windows_query_backend(void);
sg_backend sg_query_backend(void) {
    if (IsLinux()) {
        return sg_Linux_query_backend();
    }
    if (IsWindows()) {
        return sg_Windows_query_backend();
    }
}

extern sg_features sg_Linux_query_features(void);
extern sg_features sg_Windows_query_features(void);
sg_features sg_query_features(void) {
    if (IsLinux()) {
        return sg_Linux_query_features();
    }
    if (IsWindows()) {
        return sg_Windows_query_features();
    }
}

extern sg_limits sg_Linux_query_limits(void);
extern sg_limits sg_Windows_query_limits(void);
sg_limits sg_query_limits(void) {
    if (IsLinux()) {
        return sg_Linux_query_limits();
    }
    if (IsWindows()) {
        return sg_Windows_query_limits();
    }
}

extern sg_pixelformat_info sg_Linux_query_pixelformat(sg_pixel_format fmt);
extern sg_pixelformat_info sg_Windows_query_pixelformat(sg_pixel_format fmt);
sg_pixelformat_info sg_query_pixelformat(sg_pixel_format fmt) {
    if (IsLinux()) {
        return sg_Linux_query_pixelformat(fmt);
    }
    if (IsWindows()) {
        return sg_Windows_query_pixelformat(fmt);
    }
}

extern int sg_Linux_query_row_pitch(sg_pixel_format fmt, int width, int row_align_bytes);
extern int sg_Windows_query_row_pitch(sg_pixel_format fmt, int width, int row_align_bytes);
int sg_query_row_pitch(sg_pixel_format fmt, int width, int row_align_bytes) {
    if (IsLinux()) {
        return sg_Linux_query_row_pitch(fmt, width, row_align_bytes);
    }
    if (IsWindows()) {
        return sg_Windows_query_row_pitch(fmt, width, row_align_bytes);
    }
}

extern int sg_Linux_query_surface_pitch(sg_pixel_format fmt, int width, int height, int row_align_bytes);
extern int sg_Windows_query_surface_pitch(sg_pixel_format fmt, int width, int height, int row_align_bytes);
int sg_query_surface_pitch(sg_pixel_format fmt, int width, int height, int row_align_bytes) {
    if (IsLinux()) {
        return sg_Linux_query_surface_pitch(fmt, width, height, row_align_bytes);
    }
    if (IsWindows()) {
        return sg_Windows_query_surface_pitch(fmt, width, height, row_align_bytes);
    }
}

extern sg_resource_state sg_Linux_query_buffer_state(sg_buffer buf);
extern sg_resource_state sg_Windows_query_buffer_state(sg_buffer buf);
sg_resource_state sg_query_buffer_state(sg_buffer buf) {
    if (IsLinux()) {
        return sg_Linux_query_buffer_state(buf);
    }
    if (IsWindows()) {
        return sg_Windows_query_buffer_state(buf);
    }
}

extern sg_resource_state sg_Linux_query_image_state(sg_image img);
extern sg_resource_state sg_Windows_query_image_state(sg_image img);
sg_resource_state sg_query_image_state(sg_image img) {
    if (IsLinux()) {
        return sg_Linux_query_image_state(img);
    }
    if (IsWindows()) {
        return sg_Windows_query_image_state(img);
    }
}

extern sg_resource_state sg_Linux_query_sampler_state(sg_sampler smp);
extern sg_resource_state sg_Windows_query_sampler_state(sg_sampler smp);
sg_resource_state sg_query_sampler_state(sg_sampler smp) {
    if (IsLinux()) {
        return sg_Linux_query_sampler_state(smp);
    }
    if (IsWindows()) {
        return sg_Windows_query_sampler_state(smp);
    }
}

extern sg_resource_state sg_Linux_query_shader_state(sg_shader shd);
extern sg_resource_state sg_Windows_query_shader_state(sg_shader shd);
sg_resource_state sg_query_shader_state(sg_shader shd) {
    if (IsLinux()) {
        return sg_Linux_query_shader_state(shd);
    }
    if (IsWindows()) {
        return sg_Windows_query_shader_state(shd);
    }
}

extern sg_resource_state sg_Linux_query_pipeline_state(sg_pipeline pip);
extern sg_resource_state sg_Windows_query_pipeline_state(sg_pipeline pip);
sg_resource_state sg_query_pipeline_state(sg_pipeline pip) {
    if (IsLinux()) {
        return sg_Linux_query_pipeline_state(pip);
    }
    if (IsWindows()) {
        return sg_Windows_query_pipeline_state(pip);
    }
}

extern sg_resource_state sg_Linux_query_attachments_state(sg_attachments atts);
extern sg_resource_state sg_Windows_query_attachments_state(sg_attachments atts);
sg_resource_state sg_query_attachments_state(sg_attachments atts) {
    if (IsLinux()) {
        return sg_Linux_query_attachments_state(atts);
    }
    if (IsWindows()) {
        return sg_Windows_query_attachments_state(atts);
    }
}

extern sg_buffer_info sg_Linux_query_buffer_info(sg_buffer buf);
extern sg_buffer_info sg_Windows_query_buffer_info(sg_buffer buf);
sg_buffer_info sg_query_buffer_info(sg_buffer buf) {
    if (IsLinux()) {
        return sg_Linux_query_buffer_info(buf);
    }
    if (IsWindows()) {
        return sg_Windows_query_buffer_info(buf);
    }
}

extern sg_image_info sg_Linux_query_image_info(sg_image img);
extern sg_image_info sg_Windows_query_image_info(sg_image img);
sg_image_info sg_query_image_info(sg_image img) {
    if (IsLinux()) {
        return sg_Linux_query_image_info(img);
    }
    if (IsWindows()) {
        return sg_Windows_query_image_info(img);
    }
}

extern sg_sampler_info sg_Linux_query_sampler_info(sg_sampler smp);
extern sg_sampler_info sg_Windows_query_sampler_info(sg_sampler smp);
sg_sampler_info sg_query_sampler_info(sg_sampler smp) {
    if (IsLinux()) {
        return sg_Linux_query_sampler_info(smp);
    }
    if (IsWindows()) {
        return sg_Windows_query_sampler_info(smp);
    }
}

extern sg_shader_info sg_Linux_query_shader_info(sg_shader shd);
extern sg_shader_info sg_Windows_query_shader_info(sg_shader shd);
sg_shader_info sg_query_shader_info(sg_shader shd) {
    if (IsLinux()) {
        return sg_Linux_query_shader_info(shd);
    }
    if (IsWindows()) {
        return sg_Windows_query_shader_info(shd);
    }
}

extern sg_pipeline_info sg_Linux_query_pipeline_info(sg_pipeline pip);
extern sg_pipeline_info sg_Windows_query_pipeline_info(sg_pipeline pip);
sg_pipeline_info sg_query_pipeline_info(sg_pipeline pip) {
    if (IsLinux()) {
        return sg_Linux_query_pipeline_info(pip);
    }
    if (IsWindows()) {
        return sg_Windows_query_pipeline_info(pip);
    }
}

extern sg_attachments_info sg_Linux_query_attachments_info(sg_attachments atts);
extern sg_attachments_info sg_Windows_query_attachments_info(sg_attachments atts);
sg_attachments_info sg_query_attachments_info(sg_attachments atts) {
    if (IsLinux()) {
        return sg_Linux_query_attachments_info(atts);
    }
    if (IsWindows()) {
        return sg_Windows_query_attachments_info(atts);
    }
}

extern sg_buffer_desc sg_Linux_query_buffer_desc(sg_buffer buf);
extern sg_buffer_desc sg_Windows_query_buffer_desc(sg_buffer buf);
sg_buffer_desc sg_query_buffer_desc(sg_buffer buf) {
    if (IsLinux()) {
        return sg_Linux_query_buffer_desc(buf);
    }
    if (IsWindows()) {
        return sg_Windows_query_buffer_desc(buf);
    }
}

extern sg_image_desc sg_Linux_query_image_desc(sg_image img);
extern sg_image_desc sg_Windows_query_image_desc(sg_image img);
sg_image_desc sg_query_image_desc(sg_image img) {
    if (IsLinux()) {
        return sg_Linux_query_image_desc(img);
    }
    if (IsWindows()) {
        return sg_Windows_query_image_desc(img);
    }
}

extern sg_sampler_desc sg_Linux_query_sampler_desc(sg_sampler smp);
extern sg_sampler_desc sg_Windows_query_sampler_desc(sg_sampler smp);
sg_sampler_desc sg_query_sampler_desc(sg_sampler smp) {
    if (IsLinux()) {
        return sg_Linux_query_sampler_desc(smp);
    }
    if (IsWindows()) {
        return sg_Windows_query_sampler_desc(smp);
    }
}

extern sg_shader_desc sg_Linux_query_shader_desc(sg_shader shd);
extern sg_shader_desc sg_Windows_query_shader_desc(sg_shader shd);
sg_shader_desc sg_query_shader_desc(sg_shader shd) {
    if (IsLinux()) {
        return sg_Linux_query_shader_desc(shd);
    }
    if (IsWindows()) {
        return sg_Windows_query_shader_desc(shd);
    }
}

extern sg_pipeline_desc sg_Linux_query_pipeline_desc(sg_pipeline pip);
extern sg_pipeline_desc sg_Windows_query_pipeline_desc(sg_pipeline pip);
sg_pipeline_desc sg_query_pipeline_desc(sg_pipeline pip) {
    if (IsLinux()) {
        return sg_Linux_query_pipeline_desc(pip);
    }
    if (IsWindows()) {
        return sg_Windows_query_pipeline_desc(pip);
    }
}

extern sg_attachments_desc sg_Linux_query_attachments_desc(sg_attachments atts);
extern sg_attachments_desc sg_Windows_query_attachments_desc(sg_attachments atts);
sg_attachments_desc sg_query_attachments_desc(sg_attachments atts) {
    if (IsLinux()) {
        return sg_Linux_query_attachments_desc(atts);
    }
    if (IsWindows()) {
        return sg_Windows_query_attachments_desc(atts);
    }
}

extern sg_buffer_desc sg_Linux_query_buffer_defaults(const sg_buffer_desc* desc);
extern sg_buffer_desc sg_Windows_query_buffer_defaults(const sg_buffer_desc* desc);
sg_buffer_desc sg_query_buffer_defaults(const sg_buffer_desc* desc) {
    if (IsLinux()) {
        return sg_Linux_query_buffer_defaults(desc);
    }
    if (IsWindows()) {
        return sg_Windows_query_buffer_defaults(desc);
    }
}

extern sg_image_desc sg_Linux_query_image_defaults(const sg_image_desc* desc);
extern sg_image_desc sg_Windows_query_image_defaults(const sg_image_desc* desc);
sg_image_desc sg_query_image_defaults(const sg_image_desc* desc) {
    if (IsLinux()) {
        return sg_Linux_query_image_defaults(desc);
    }
    if (IsWindows()) {
        return sg_Windows_query_image_defaults(desc);
    }
}

extern sg_sampler_desc sg_Linux_query_sampler_defaults(const sg_sampler_desc* desc);
extern sg_sampler_desc sg_Windows_query_sampler_defaults(const sg_sampler_desc* desc);
sg_sampler_desc sg_query_sampler_defaults(const sg_sampler_desc* desc) {
    if (IsLinux()) {
        return sg_Linux_query_sampler_defaults(desc);
    }
    if (IsWindows()) {
        return sg_Windows_query_sampler_defaults(desc);
    }
}

extern sg_shader_desc sg_Linux_query_shader_defaults(const sg_shader_desc* desc);
extern sg_shader_desc sg_Windows_query_shader_defaults(const sg_shader_desc* desc);
sg_shader_desc sg_query_shader_defaults(const sg_shader_desc* desc) {
    if (IsLinux()) {
        return sg_Linux_query_shader_defaults(desc);
    }
    if (IsWindows()) {
        return sg_Windows_query_shader_defaults(desc);
    }
}

extern sg_pipeline_desc sg_Linux_query_pipeline_defaults(const sg_pipeline_desc* desc);
extern sg_pipeline_desc sg_Windows_query_pipeline_defaults(const sg_pipeline_desc* desc);
sg_pipeline_desc sg_query_pipeline_defaults(const sg_pipeline_desc* desc) {
    if (IsLinux()) {
        return sg_Linux_query_pipeline_defaults(desc);
    }
    if (IsWindows()) {
        return sg_Windows_query_pipeline_defaults(desc);
    }
}

extern sg_attachments_desc sg_Linux_query_attachments_defaults(const sg_attachments_desc* desc);
extern sg_attachments_desc sg_Windows_query_attachments_defaults(const sg_attachments_desc* desc);
sg_attachments_desc sg_query_attachments_defaults(const sg_attachments_desc* desc) {
    if (IsLinux()) {
        return sg_Linux_query_attachments_defaults(desc);
    }
    if (IsWindows()) {
        return sg_Windows_query_attachments_defaults(desc);
    }
}

extern sg_buffer sg_Linux_alloc_buffer(void);
extern sg_buffer sg_Windows_alloc_buffer(void);
sg_buffer sg_alloc_buffer(void) {
    if (IsLinux()) {
        return sg_Linux_alloc_buffer();
    }
    if (IsWindows()) {
        return sg_Windows_alloc_buffer();
    }
}

extern sg_image sg_Linux_alloc_image(void);
extern sg_image sg_Windows_alloc_image(void);
sg_image sg_alloc_image(void) {
    if (IsLinux()) {
        return sg_Linux_alloc_image();
    }
    if (IsWindows()) {
        return sg_Windows_alloc_image();
    }
}

extern sg_sampler sg_Linux_alloc_sampler(void);
extern sg_sampler sg_Windows_alloc_sampler(void);
sg_sampler sg_alloc_sampler(void) {
    if (IsLinux()) {
        return sg_Linux_alloc_sampler();
    }
    if (IsWindows()) {
        return sg_Windows_alloc_sampler();
    }
}

extern sg_shader sg_Linux_alloc_shader(void);
extern sg_shader sg_Windows_alloc_shader(void);
sg_shader sg_alloc_shader(void) {
    if (IsLinux()) {
        return sg_Linux_alloc_shader();
    }
    if (IsWindows()) {
        return sg_Windows_alloc_shader();
    }
}

extern sg_pipeline sg_Linux_alloc_pipeline(void);
extern sg_pipeline sg_Windows_alloc_pipeline(void);
sg_pipeline sg_alloc_pipeline(void) {
    if (IsLinux()) {
        return sg_Linux_alloc_pipeline();
    }
    if (IsWindows()) {
        return sg_Windows_alloc_pipeline();
    }
}

extern sg_attachments sg_Linux_alloc_attachments(void);
extern sg_attachments sg_Windows_alloc_attachments(void);
sg_attachments sg_alloc_attachments(void) {
    if (IsLinux()) {
        return sg_Linux_alloc_attachments();
    }
    if (IsWindows()) {
        return sg_Windows_alloc_attachments();
    }
}

extern void sg_Linux_dealloc_buffer(sg_buffer buf);
extern void sg_Windows_dealloc_buffer(sg_buffer buf);
void sg_dealloc_buffer(sg_buffer buf) {
    if (IsLinux()) {
        sg_Linux_dealloc_buffer(buf);
        return;
    }
    if (IsWindows()) {
        sg_Windows_dealloc_buffer(buf);
        return;
    }
}

extern void sg_Linux_dealloc_image(sg_image img);
extern void sg_Windows_dealloc_image(sg_image img);
void sg_dealloc_image(sg_image img) {
    if (IsLinux()) {
        sg_Linux_dealloc_image(img);
        return;
    }
    if (IsWindows()) {
        sg_Windows_dealloc_image(img);
        return;
    }
}

extern void sg_Linux_dealloc_sampler(sg_sampler smp);
extern void sg_Windows_dealloc_sampler(sg_sampler smp);
void sg_dealloc_sampler(sg_sampler smp) {
    if (IsLinux()) {
        sg_Linux_dealloc_sampler(smp);
        return;
    }
    if (IsWindows()) {
        sg_Windows_dealloc_sampler(smp);
        return;
    }
}

extern void sg_Linux_dealloc_shader(sg_shader shd);
extern void sg_Windows_dealloc_shader(sg_shader shd);
void sg_dealloc_shader(sg_shader shd) {
    if (IsLinux()) {
        sg_Linux_dealloc_shader(shd);
        return;
    }
    if (IsWindows()) {
        sg_Windows_dealloc_shader(shd);
        return;
    }
}

extern void sg_Linux_dealloc_pipeline(sg_pipeline pip);
extern void sg_Windows_dealloc_pipeline(sg_pipeline pip);
void sg_dealloc_pipeline(sg_pipeline pip) {
    if (IsLinux()) {
        sg_Linux_dealloc_pipeline(pip);
        return;
    }
    if (IsWindows()) {
        sg_Windows_dealloc_pipeline(pip);
        return;
    }
}

extern void sg_Linux_dealloc_attachments(sg_attachments attachments);
extern void sg_Windows_dealloc_attachments(sg_attachments attachments);
void sg_dealloc_attachments(sg_attachments attachments) {
    if (IsLinux()) {
        sg_Linux_dealloc_attachments(attachments);
        return;
    }
    if (IsWindows()) {
        sg_Windows_dealloc_attachments(attachments);
        return;
    }
}

extern void sg_Linux_init_buffer(sg_buffer buf, const sg_buffer_desc* desc);
extern void sg_Windows_init_buffer(sg_buffer buf, const sg_buffer_desc* desc);
void sg_init_buffer(sg_buffer buf, const sg_buffer_desc* desc) {
    if (IsLinux()) {
        sg_Linux_init_buffer(buf, desc);
        return;
    }
    if (IsWindows()) {
        sg_Windows_init_buffer(buf, desc);
        return;
    }
}

extern void sg_Linux_init_image(sg_image img, const sg_image_desc* desc);
extern void sg_Windows_init_image(sg_image img, const sg_image_desc* desc);
void sg_init_image(sg_image img, const sg_image_desc* desc) {
    if (IsLinux()) {
        sg_Linux_init_image(img, desc);
        return;
    }
    if (IsWindows()) {
        sg_Windows_init_image(img, desc);
        return;
    }
}

extern void sg_Linux_init_sampler(sg_sampler smg, const sg_sampler_desc* desc);
extern void sg_Windows_init_sampler(sg_sampler smg, const sg_sampler_desc* desc);
void sg_init_sampler(sg_sampler smg, const sg_sampler_desc* desc) {
    if (IsLinux()) {
        sg_Linux_init_sampler(smg, desc);
        return;
    }
    if (IsWindows()) {
        sg_Windows_init_sampler(smg, desc);
        return;
    }
}

extern void sg_Linux_init_shader(sg_shader shd, const sg_shader_desc* desc);
extern void sg_Windows_init_shader(sg_shader shd, const sg_shader_desc* desc);
void sg_init_shader(sg_shader shd, const sg_shader_desc* desc) {
    if (IsLinux()) {
        sg_Linux_init_shader(shd, desc);
        return;
    }
    if (IsWindows()) {
        sg_Windows_init_shader(shd, desc);
        return;
    }
}

extern void sg_Linux_init_pipeline(sg_pipeline pip, const sg_pipeline_desc* desc);
extern void sg_Windows_init_pipeline(sg_pipeline pip, const sg_pipeline_desc* desc);
void sg_init_pipeline(sg_pipeline pip, const sg_pipeline_desc* desc) {
    if (IsLinux()) {
        sg_Linux_init_pipeline(pip, desc);
        return;
    }
    if (IsWindows()) {
        sg_Windows_init_pipeline(pip, desc);
        return;
    }
}

extern void sg_Linux_init_attachments(sg_attachments attachments, const sg_attachments_desc* desc);
extern void sg_Windows_init_attachments(sg_attachments attachments, const sg_attachments_desc* desc);
void sg_init_attachments(sg_attachments attachments, const sg_attachments_desc* desc) {
    if (IsLinux()) {
        sg_Linux_init_attachments(attachments, desc);
        return;
    }
    if (IsWindows()) {
        sg_Windows_init_attachments(attachments, desc);
        return;
    }
}

extern void sg_Linux_uninit_buffer(sg_buffer buf);
extern void sg_Windows_uninit_buffer(sg_buffer buf);
void sg_uninit_buffer(sg_buffer buf) {
    if (IsLinux()) {
        sg_Linux_uninit_buffer(buf);
        return;
    }
    if (IsWindows()) {
        sg_Windows_uninit_buffer(buf);
        return;
    }
}

extern void sg_Linux_uninit_image(sg_image img);
extern void sg_Windows_uninit_image(sg_image img);
void sg_uninit_image(sg_image img) {
    if (IsLinux()) {
        sg_Linux_uninit_image(img);
        return;
    }
    if (IsWindows()) {
        sg_Windows_uninit_image(img);
        return;
    }
}

extern void sg_Linux_uninit_sampler(sg_sampler smp);
extern void sg_Windows_uninit_sampler(sg_sampler smp);
void sg_uninit_sampler(sg_sampler smp) {
    if (IsLinux()) {
        sg_Linux_uninit_sampler(smp);
        return;
    }
    if (IsWindows()) {
        sg_Windows_uninit_sampler(smp);
        return;
    }
}

extern void sg_Linux_uninit_shader(sg_shader shd);
extern void sg_Windows_uninit_shader(sg_shader shd);
void sg_uninit_shader(sg_shader shd) {
    if (IsLinux()) {
        sg_Linux_uninit_shader(shd);
        return;
    }
    if (IsWindows()) {
        sg_Windows_uninit_shader(shd);
        return;
    }
}

extern void sg_Linux_uninit_pipeline(sg_pipeline pip);
extern void sg_Windows_uninit_pipeline(sg_pipeline pip);
void sg_uninit_pipeline(sg_pipeline pip) {
    if (IsLinux()) {
        sg_Linux_uninit_pipeline(pip);
        return;
    }
    if (IsWindows()) {
        sg_Windows_uninit_pipeline(pip);
        return;
    }
}

extern void sg_Linux_uninit_attachments(sg_attachments atts);
extern void sg_Windows_uninit_attachments(sg_attachments atts);
void sg_uninit_attachments(sg_attachments atts) {
    if (IsLinux()) {
        sg_Linux_uninit_attachments(atts);
        return;
    }
    if (IsWindows()) {
        sg_Windows_uninit_attachments(atts);
        return;
    }
}

extern void sg_Linux_fail_buffer(sg_buffer buf);
extern void sg_Windows_fail_buffer(sg_buffer buf);
void sg_fail_buffer(sg_buffer buf) {
    if (IsLinux()) {
        sg_Linux_fail_buffer(buf);
        return;
    }
    if (IsWindows()) {
        sg_Windows_fail_buffer(buf);
        return;
    }
}

extern void sg_Linux_fail_image(sg_image img);
extern void sg_Windows_fail_image(sg_image img);
void sg_fail_image(sg_image img) {
    if (IsLinux()) {
        sg_Linux_fail_image(img);
        return;
    }
    if (IsWindows()) {
        sg_Windows_fail_image(img);
        return;
    }
}

extern void sg_Linux_fail_sampler(sg_sampler smp);
extern void sg_Windows_fail_sampler(sg_sampler smp);
void sg_fail_sampler(sg_sampler smp) {
    if (IsLinux()) {
        sg_Linux_fail_sampler(smp);
        return;
    }
    if (IsWindows()) {
        sg_Windows_fail_sampler(smp);
        return;
    }
}

extern void sg_Linux_fail_shader(sg_shader shd);
extern void sg_Windows_fail_shader(sg_shader shd);
void sg_fail_shader(sg_shader shd) {
    if (IsLinux()) {
        sg_Linux_fail_shader(shd);
        return;
    }
    if (IsWindows()) {
        sg_Windows_fail_shader(shd);
        return;
    }
}

extern void sg_Linux_fail_pipeline(sg_pipeline pip);
extern void sg_Windows_fail_pipeline(sg_pipeline pip);
void sg_fail_pipeline(sg_pipeline pip) {
    if (IsLinux()) {
        sg_Linux_fail_pipeline(pip);
        return;
    }
    if (IsWindows()) {
        sg_Windows_fail_pipeline(pip);
        return;
    }
}

extern void sg_Linux_fail_attachments(sg_attachments atts);
extern void sg_Windows_fail_attachments(sg_attachments atts);
void sg_fail_attachments(sg_attachments atts) {
    if (IsLinux()) {
        sg_Linux_fail_attachments(atts);
        return;
    }
    if (IsWindows()) {
        sg_Windows_fail_attachments(atts);
        return;
    }
}

extern void sg_Linux_enable_frame_stats(void);
extern void sg_Windows_enable_frame_stats(void);
void sg_enable_frame_stats(void) {
    if (IsLinux()) {
        sg_Linux_enable_frame_stats();
        return;
    }
    if (IsWindows()) {
        sg_Windows_enable_frame_stats();
        return;
    }
}

extern void sg_Linux_disable_frame_stats(void);
extern void sg_Windows_disable_frame_stats(void);
void sg_disable_frame_stats(void) {
    if (IsLinux()) {
        sg_Linux_disable_frame_stats();
        return;
    }
    if (IsWindows()) {
        sg_Windows_disable_frame_stats();
        return;
    }
}

extern bool sg_Linux_frame_stats_enabled(void);
extern bool sg_Windows_frame_stats_enabled(void);
bool sg_frame_stats_enabled(void) {
    if (IsLinux()) {
        return sg_Linux_frame_stats_enabled();
    }
    if (IsWindows()) {
        return sg_Windows_frame_stats_enabled();
    }
}

extern sg_frame_stats sg_Linux_query_frame_stats(void);
extern sg_frame_stats sg_Windows_query_frame_stats(void);
sg_frame_stats sg_query_frame_stats(void) {
    if (IsLinux()) {
        return sg_Linux_query_frame_stats();
    }
    if (IsWindows()) {
        return sg_Windows_query_frame_stats();
    }
}

extern const void* sg_Linux_d3d11_device(void);
extern const void* sg_Windows_d3d11_device(void);
const void* sg_d3d11_device(void) {
    if (IsLinux()) {
        return sg_Linux_d3d11_device();
    }
    if (IsWindows()) {
        return sg_Windows_d3d11_device();
    }
}

extern const void* sg_Linux_d3d11_device_context(void);
extern const void* sg_Windows_d3d11_device_context(void);
const void* sg_d3d11_device_context(void) {
    if (IsLinux()) {
        return sg_Linux_d3d11_device_context();
    }
    if (IsWindows()) {
        return sg_Windows_d3d11_device_context();
    }
}

extern sg_d3d11_buffer_info sg_Linux_d3d11_query_buffer_info(sg_buffer buf);
extern sg_d3d11_buffer_info sg_Windows_d3d11_query_buffer_info(sg_buffer buf);
sg_d3d11_buffer_info sg_d3d11_query_buffer_info(sg_buffer buf) {
    if (IsLinux()) {
        return sg_Linux_d3d11_query_buffer_info(buf);
    }
    if (IsWindows()) {
        return sg_Windows_d3d11_query_buffer_info(buf);
    }
}

extern sg_d3d11_image_info sg_Linux_d3d11_query_image_info(sg_image img);
extern sg_d3d11_image_info sg_Windows_d3d11_query_image_info(sg_image img);
sg_d3d11_image_info sg_d3d11_query_image_info(sg_image img) {
    if (IsLinux()) {
        return sg_Linux_d3d11_query_image_info(img);
    }
    if (IsWindows()) {
        return sg_Windows_d3d11_query_image_info(img);
    }
}

extern sg_d3d11_sampler_info sg_Linux_d3d11_query_sampler_info(sg_sampler smp);
extern sg_d3d11_sampler_info sg_Windows_d3d11_query_sampler_info(sg_sampler smp);
sg_d3d11_sampler_info sg_d3d11_query_sampler_info(sg_sampler smp) {
    if (IsLinux()) {
        return sg_Linux_d3d11_query_sampler_info(smp);
    }
    if (IsWindows()) {
        return sg_Windows_d3d11_query_sampler_info(smp);
    }
}

extern sg_d3d11_shader_info sg_Linux_d3d11_query_shader_info(sg_shader shd);
extern sg_d3d11_shader_info sg_Windows_d3d11_query_shader_info(sg_shader shd);
sg_d3d11_shader_info sg_d3d11_query_shader_info(sg_shader shd) {
    if (IsLinux()) {
        return sg_Linux_d3d11_query_shader_info(shd);
    }
    if (IsWindows()) {
        return sg_Windows_d3d11_query_shader_info(shd);
    }
}

extern sg_d3d11_pipeline_info sg_Linux_d3d11_query_pipeline_info(sg_pipeline pip);
extern sg_d3d11_pipeline_info sg_Windows_d3d11_query_pipeline_info(sg_pipeline pip);
sg_d3d11_pipeline_info sg_d3d11_query_pipeline_info(sg_pipeline pip) {
    if (IsLinux()) {
        return sg_Linux_d3d11_query_pipeline_info(pip);
    }
    if (IsWindows()) {
        return sg_Windows_d3d11_query_pipeline_info(pip);
    }
}

extern sg_d3d11_attachments_info sg_Linux_d3d11_query_attachments_info(sg_attachments atts);
extern sg_d3d11_attachments_info sg_Windows_d3d11_query_attachments_info(sg_attachments atts);
sg_d3d11_attachments_info sg_d3d11_query_attachments_info(sg_attachments atts) {
    if (IsLinux()) {
        return sg_Linux_d3d11_query_attachments_info(atts);
    }
    if (IsWindows()) {
        return sg_Windows_d3d11_query_attachments_info(atts);
    }
}

extern const void* sg_Linux_mtl_device(void);
extern const void* sg_Windows_mtl_device(void);
const void* sg_mtl_device(void) {
    if (IsLinux()) {
        return sg_Linux_mtl_device();
    }
    if (IsWindows()) {
        return sg_Windows_mtl_device();
    }
}

extern const void* sg_Linux_mtl_render_command_encoder(void);
extern const void* sg_Windows_mtl_render_command_encoder(void);
const void* sg_mtl_render_command_encoder(void) {
    if (IsLinux()) {
        return sg_Linux_mtl_render_command_encoder();
    }
    if (IsWindows()) {
        return sg_Windows_mtl_render_command_encoder();
    }
}

extern sg_mtl_buffer_info sg_Linux_mtl_query_buffer_info(sg_buffer buf);
extern sg_mtl_buffer_info sg_Windows_mtl_query_buffer_info(sg_buffer buf);
sg_mtl_buffer_info sg_mtl_query_buffer_info(sg_buffer buf) {
    if (IsLinux()) {
        return sg_Linux_mtl_query_buffer_info(buf);
    }
    if (IsWindows()) {
        return sg_Windows_mtl_query_buffer_info(buf);
    }
}

extern sg_mtl_image_info sg_Linux_mtl_query_image_info(sg_image img);
extern sg_mtl_image_info sg_Windows_mtl_query_image_info(sg_image img);
sg_mtl_image_info sg_mtl_query_image_info(sg_image img) {
    if (IsLinux()) {
        return sg_Linux_mtl_query_image_info(img);
    }
    if (IsWindows()) {
        return sg_Windows_mtl_query_image_info(img);
    }
}

extern sg_mtl_sampler_info sg_Linux_mtl_query_sampler_info(sg_sampler smp);
extern sg_mtl_sampler_info sg_Windows_mtl_query_sampler_info(sg_sampler smp);
sg_mtl_sampler_info sg_mtl_query_sampler_info(sg_sampler smp) {
    if (IsLinux()) {
        return sg_Linux_mtl_query_sampler_info(smp);
    }
    if (IsWindows()) {
        return sg_Windows_mtl_query_sampler_info(smp);
    }
}

extern sg_mtl_shader_info sg_Linux_mtl_query_shader_info(sg_shader shd);
extern sg_mtl_shader_info sg_Windows_mtl_query_shader_info(sg_shader shd);
sg_mtl_shader_info sg_mtl_query_shader_info(sg_shader shd) {
    if (IsLinux()) {
        return sg_Linux_mtl_query_shader_info(shd);
    }
    if (IsWindows()) {
        return sg_Windows_mtl_query_shader_info(shd);
    }
}

extern sg_mtl_pipeline_info sg_Linux_mtl_query_pipeline_info(sg_pipeline pip);
extern sg_mtl_pipeline_info sg_Windows_mtl_query_pipeline_info(sg_pipeline pip);
sg_mtl_pipeline_info sg_mtl_query_pipeline_info(sg_pipeline pip) {
    if (IsLinux()) {
        return sg_Linux_mtl_query_pipeline_info(pip);
    }
    if (IsWindows()) {
        return sg_Windows_mtl_query_pipeline_info(pip);
    }
}

extern const void* sg_Linux_wgpu_device(void);
extern const void* sg_Windows_wgpu_device(void);
const void* sg_wgpu_device(void) {
    if (IsLinux()) {
        return sg_Linux_wgpu_device();
    }
    if (IsWindows()) {
        return sg_Windows_wgpu_device();
    }
}

extern const void* sg_Linux_wgpu_queue(void);
extern const void* sg_Windows_wgpu_queue(void);
const void* sg_wgpu_queue(void) {
    if (IsLinux()) {
        return sg_Linux_wgpu_queue();
    }
    if (IsWindows()) {
        return sg_Windows_wgpu_queue();
    }
}

extern const void* sg_Linux_wgpu_command_encoder(void);
extern const void* sg_Windows_wgpu_command_encoder(void);
const void* sg_wgpu_command_encoder(void) {
    if (IsLinux()) {
        return sg_Linux_wgpu_command_encoder();
    }
    if (IsWindows()) {
        return sg_Windows_wgpu_command_encoder();
    }
}

extern const void* sg_Linux_wgpu_render_pass_encoder(void);
extern const void* sg_Windows_wgpu_render_pass_encoder(void);
const void* sg_wgpu_render_pass_encoder(void) {
    if (IsLinux()) {
        return sg_Linux_wgpu_render_pass_encoder();
    }
    if (IsWindows()) {
        return sg_Windows_wgpu_render_pass_encoder();
    }
}

extern sg_wgpu_buffer_info sg_Linux_wgpu_query_buffer_info(sg_buffer buf);
extern sg_wgpu_buffer_info sg_Windows_wgpu_query_buffer_info(sg_buffer buf);
sg_wgpu_buffer_info sg_wgpu_query_buffer_info(sg_buffer buf) {
    if (IsLinux()) {
        return sg_Linux_wgpu_query_buffer_info(buf);
    }
    if (IsWindows()) {
        return sg_Windows_wgpu_query_buffer_info(buf);
    }
}

extern sg_wgpu_image_info sg_Linux_wgpu_query_image_info(sg_image img);
extern sg_wgpu_image_info sg_Windows_wgpu_query_image_info(sg_image img);
sg_wgpu_image_info sg_wgpu_query_image_info(sg_image img) {
    if (IsLinux()) {
        return sg_Linux_wgpu_query_image_info(img);
    }
    if (IsWindows()) {
        return sg_Windows_wgpu_query_image_info(img);
    }
}

extern sg_wgpu_sampler_info sg_Linux_wgpu_query_sampler_info(sg_sampler smp);
extern sg_wgpu_sampler_info sg_Windows_wgpu_query_sampler_info(sg_sampler smp);
sg_wgpu_sampler_info sg_wgpu_query_sampler_info(sg_sampler smp) {
    if (IsLinux()) {
        return sg_Linux_wgpu_query_sampler_info(smp);
    }
    if (IsWindows()) {
        return sg_Windows_wgpu_query_sampler_info(smp);
    }
}

extern sg_wgpu_shader_info sg_Linux_wgpu_query_shader_info(sg_shader shd);
extern sg_wgpu_shader_info sg_Windows_wgpu_query_shader_info(sg_shader shd);
sg_wgpu_shader_info sg_wgpu_query_shader_info(sg_shader shd) {
    if (IsLinux()) {
        return sg_Linux_wgpu_query_shader_info(shd);
    }
    if (IsWindows()) {
        return sg_Windows_wgpu_query_shader_info(shd);
    }
}

extern sg_wgpu_pipeline_info sg_Linux_wgpu_query_pipeline_info(sg_pipeline pip);
extern sg_wgpu_pipeline_info sg_Windows_wgpu_query_pipeline_info(sg_pipeline pip);
sg_wgpu_pipeline_info sg_wgpu_query_pipeline_info(sg_pipeline pip) {
    if (IsLinux()) {
        return sg_Linux_wgpu_query_pipeline_info(pip);
    }
    if (IsWindows()) {
        return sg_Windows_wgpu_query_pipeline_info(pip);
    }
}

extern sg_wgpu_attachments_info sg_Linux_wgpu_query_attachments_info(sg_attachments atts);
extern sg_wgpu_attachments_info sg_Windows_wgpu_query_attachments_info(sg_attachments atts);
sg_wgpu_attachments_info sg_wgpu_query_attachments_info(sg_attachments atts) {
    if (IsLinux()) {
        return sg_Linux_wgpu_query_attachments_info(atts);
    }
    if (IsWindows()) {
        return sg_Windows_wgpu_query_attachments_info(atts);
    }
}

extern sg_gl_buffer_info sg_Linux_gl_query_buffer_info(sg_buffer buf);
extern sg_gl_buffer_info sg_Windows_gl_query_buffer_info(sg_buffer buf);
sg_gl_buffer_info sg_gl_query_buffer_info(sg_buffer buf) {
    if (IsLinux()) {
        return sg_Linux_gl_query_buffer_info(buf);
    }
    if (IsWindows()) {
        return sg_Windows_gl_query_buffer_info(buf);
    }
}

extern sg_gl_image_info sg_Linux_gl_query_image_info(sg_image img);
extern sg_gl_image_info sg_Windows_gl_query_image_info(sg_image img);
sg_gl_image_info sg_gl_query_image_info(sg_image img) {
    if (IsLinux()) {
        return sg_Linux_gl_query_image_info(img);
    }
    if (IsWindows()) {
        return sg_Windows_gl_query_image_info(img);
    }
}

extern sg_gl_sampler_info sg_Linux_gl_query_sampler_info(sg_sampler smp);
extern sg_gl_sampler_info sg_Windows_gl_query_sampler_info(sg_sampler smp);
sg_gl_sampler_info sg_gl_query_sampler_info(sg_sampler smp) {
    if (IsLinux()) {
        return sg_Linux_gl_query_sampler_info(smp);
    }
    if (IsWindows()) {
        return sg_Windows_gl_query_sampler_info(smp);
    }
}

extern sg_gl_shader_info sg_Linux_gl_query_shader_info(sg_shader shd);
extern sg_gl_shader_info sg_Windows_gl_query_shader_info(sg_shader shd);
sg_gl_shader_info sg_gl_query_shader_info(sg_shader shd) {
    if (IsLinux()) {
        return sg_Linux_gl_query_shader_info(shd);
    }
    if (IsWindows()) {
        return sg_Windows_gl_query_shader_info(shd);
    }
}

extern sg_gl_attachments_info sg_Linux_gl_query_attachments_info(sg_attachments atts);
extern sg_gl_attachments_info sg_Windows_gl_query_attachments_info(sg_attachments atts);
sg_gl_attachments_info sg_gl_query_attachments_info(sg_attachments atts) {
    if (IsLinux()) {
        return sg_Linux_gl_query_attachments_info(atts);
    }
    if (IsWindows()) {
        return sg_Windows_gl_query_attachments_info(atts);
    }
}

