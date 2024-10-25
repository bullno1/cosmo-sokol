#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xresource.h>
#include <X11/Xcursor/Xcursor.h>
#include <X11/extensions/XKBstr.h>
#include <X11/extensions/XInput2.h>
#include <stddef.h>
#include <dlfcn.h>

static void* libx11 = NULL;

static Display * (*proc_XOpenDisplay)(const char* display_name) = NULL;
static int (*proc_XCloseDisplay)(Display* display) = NULL;
static int (*proc_XFlush)(Display* display) = NULL;
static int (*proc_XNextEvent)(Display* display, XEvent* event_return) = NULL;
static int (*proc_XPending)(Display* display) = NULL;
static Status (*proc_XInitThreads)(void) = NULL;
static Bool (*proc_XFilterEvent)(XEvent* event, Window w) = NULL;
static Bool (*proc_XkbSetDetectableAutoRepeat)(Display* display, Bool detectable, Bool* supported_rtrn) = NULL;
static int (*proc_XSync)(Display* display, Bool discard) = NULL;
static void (*proc_XrmInitialize)(void) = NULL;
static int (*proc_XChangeProperty)(Display* display, Window w, Atom property, Atom type, int format, int mode, const unsigned char* data, int nelements) = NULL;
static Status (*proc_XSendEvent)(Display* display, Window w, Bool propagate, long event_mask, XEvent* event_send) = NULL;
static int (*proc_XFree)(void* data) = NULL;
static XErrorHandler (*proc_XSetErrorHandler)(XErrorHandler handler) = NULL;
static int (*proc_XConvertSelection)(Display* display, Atom selection, Atom target, Atom property, Window requestor, Time time) = NULL;
static int (*proc_XLookupString)(XKeyEvent* event_struct, char* buffer_return, int bytes_buffer, KeySym* keysym_return, XComposeStatus* status_in_out) = NULL;
static Bool (*proc_XGetEventData)(Display* display, XGenericEventCookie* cookie) = NULL;
static void (*proc_XFreeEventData)(Display* display, XGenericEventCookie* cookie) = NULL;
static int (*proc_XGetWindowProperty)(Display* display, Window w, Atom property, long long_offset, long long_length, Bool delete, Atom req_type, Atom* actual_type_return, int* actual_format_return, unsigned long* nitems_return, unsigned long* bytes_after_return, unsigned char** prop_return) = NULL;
static int (*proc_XMapWindow)(Display* display, Window w) = NULL;
static int (*proc_XUnmapWindow)(Display* display, Window w) = NULL;
static int (*proc_XRaiseWindow)(Display* display, Window w) = NULL;
static Status (*proc_XGetWindowAttributes)(Display* display, Window w, XWindowAttributes* window_attributes_return) = NULL;
static XSizeHints * (*proc_XAllocSizeHints)(void) = NULL;
static Bool (*proc_XCheckTypedWindowEvent)(Display* display, Window w, int event_type, XEvent* event_return) = NULL;
static Colormap (*proc_XCreateColormap)(Display* display, Window w, Visual* visual, int alloc) = NULL;
static Cursor (*proc_XCreateFontCursor)(Display* display, unsigned int shape) = NULL;
static Window (*proc_XCreateWindow)(Display* display, Window parent, int x, int y, unsigned int width, unsigned int height, unsigned int border_width, int depth, unsigned int class, Visual* visual, unsigned long valuemask, XSetWindowAttributes* attributes) = NULL;
static int (*proc_XWarpPointer)(Display* display, Window src_w, Window dest_w, int src_x, int src_y, unsigned int src_width, unsigned int src_height, int dest_x, int dest_y) = NULL;
static int (*proc_XDefineCursor)(Display* display, Window w, Cursor cursor) = NULL;
static int (*proc_XDestroyWindow)(Display* display, Window w) = NULL;
static int (*proc_XFreeColormap)(Display* display, Colormap colormap) = NULL;
static int (*proc_XFreeCursor)(Display* display, Cursor cursor) = NULL;
static KeySym * (*proc_XGetKeyboardMapping)(Display* display, unsigned int first_keycode, int keycode_count, int* keysyms_per_keycode_return) = NULL;
static Window (*proc_XGetSelectionOwner)(Display* display, Atom selection) = NULL;
static int (*proc_XGrabPointer)(Display* display, Window grab_window, Bool owner_events, unsigned int event_mask, int pointer_mode, int keyboard_mode, Window confine_to, Cursor cursor, Time time) = NULL;
static Atom (*proc_XInternAtom)(Display* display, const char* atom_name, Bool only_if_exists) = NULL;
static Status (*proc_XInternAtoms)(Display* display, char** names, int count, Bool only_if_exists, Atom* atoms_return) = NULL;
static int (*proc_XSetSelectionOwner)(Display* display, Atom selection, Window owner, Time time) = NULL;
static void (*proc_XSetWMNormalHints)(Display* display, Window w, XSizeHints* hints) = NULL;
static Status (*proc_XSetWMProtocols)(Display* display, Window w, Atom* protocols, int count) = NULL;
static int (*proc_XUndefineCursor)(Display* display, Window w) = NULL;
static int (*proc_XUngrabPointer)(Display* display, Time time) = NULL;
static void (*proc_Xutf8SetWMProperties)(Display* display, Window w, const char* window_name, const char* icon_name, char** argv, int argc, XSizeHints* normal_hints, XWMHints* wm_hints, XClassHint* class_hints) = NULL;
static void (*proc_XkbFreeKeyboard)(XkbDescPtr xkb, unsigned int which, Bool free_all) = NULL;
static void (*proc_XkbFreeNames)(XkbDescPtr xkb, unsigned int which, Bool free_map) = NULL;
static char * (*proc_XResourceManagerString)(Display* display) = NULL;
static void (*proc_XrmDestroyDatabase)(XrmDatabase database) = NULL;
static Bool (*proc_XrmGetResource)(XrmDatabase database, const char* str_name, const char* str_class, char** str_type_return, XrmValue* value_return) = NULL;
static XkbDescPtr (*proc_XkbGetMap)(Display* display, unsigned int which, unsigned int device_spec) = NULL;
static Status (*proc_XkbGetNames)(Display* dpy, unsigned int which, XkbDescPtr xkb) = NULL;
static XrmDatabase (*proc_XrmGetStringDatabase)(const char* data) = NULL;
static Bool (*proc_XQueryExtension)(Display* display, const char* name, int* major_opcode_return, int* first_event_return, int* first_error_return) = NULL;
static int (*proc_XcursorGetDefaultSize)(Display* dpy) = NULL;
static char * (*proc_XcursorGetTheme)(Display* dpy) = NULL;
static XcursorImage * (*proc_XcursorImageCreate)(int width, int height) = NULL;
static void (*proc_XcursorImageDestroy)(XcursorImage* image) = NULL;
static Cursor (*proc_XcursorImageLoadCursor)(Display* dpy, const XcursorImage* image) = NULL;
static XcursorImage * (*proc_XcursorLibraryLoadImage)(const char* library, const char* theme, int size) = NULL;
static Status (*proc_XIQueryVersion)(Display* dpy, int* major_version_inout, int* minor_version_inout) = NULL;
static int (*proc_XISelectEvents)(Display* dpy, Window win, XIEventMask* masks, int num_masks) = NULL;

static void load_x11_shims(void) {
    libx11 = cosmo_dlopen("libX11.so", RTLD_NOW | RTLD_GLOBAL);
    proc_XOpenDisplay = cosmo_dltramp(cosmo_dlsym(libx11, "XOpenDisplay"));
    proc_XCloseDisplay = cosmo_dltramp(cosmo_dlsym(libx11, "XCloseDisplay"));
    proc_XFlush = cosmo_dltramp(cosmo_dlsym(libx11, "XFlush"));
    proc_XNextEvent = cosmo_dltramp(cosmo_dlsym(libx11, "XNextEvent"));
    proc_XPending = cosmo_dltramp(cosmo_dlsym(libx11, "XPending"));
    proc_XInitThreads = cosmo_dltramp(cosmo_dlsym(libx11, "XInitThreads"));
    proc_XFilterEvent = cosmo_dltramp(cosmo_dlsym(libx11, "XFilterEvent"));
    proc_XkbSetDetectableAutoRepeat = cosmo_dltramp(cosmo_dlsym(libx11, "XkbSetDetectableAutoRepeat"));
    proc_XSync = cosmo_dltramp(cosmo_dlsym(libx11, "XSync"));
    proc_XrmInitialize = cosmo_dltramp(cosmo_dlsym(libx11, "XrmInitialize"));
    proc_XChangeProperty = cosmo_dltramp(cosmo_dlsym(libx11, "XChangeProperty"));
    proc_XSendEvent = cosmo_dltramp(cosmo_dlsym(libx11, "XSendEvent"));
    proc_XFree = cosmo_dltramp(cosmo_dlsym(libx11, "XFree"));
    proc_XSetErrorHandler = cosmo_dltramp(cosmo_dlsym(libx11, "XSetErrorHandler"));
    proc_XConvertSelection = cosmo_dltramp(cosmo_dlsym(libx11, "XConvertSelection"));
    proc_XLookupString = cosmo_dltramp(cosmo_dlsym(libx11, "XLookupString"));
    proc_XGetEventData = cosmo_dltramp(cosmo_dlsym(libx11, "XGetEventData"));
    proc_XFreeEventData = cosmo_dltramp(cosmo_dlsym(libx11, "XFreeEventData"));
    proc_XGetWindowProperty = cosmo_dltramp(cosmo_dlsym(libx11, "XGetWindowProperty"));
    proc_XMapWindow = cosmo_dltramp(cosmo_dlsym(libx11, "XMapWindow"));
    proc_XUnmapWindow = cosmo_dltramp(cosmo_dlsym(libx11, "XUnmapWindow"));
    proc_XRaiseWindow = cosmo_dltramp(cosmo_dlsym(libx11, "XRaiseWindow"));
    proc_XGetWindowAttributes = cosmo_dltramp(cosmo_dlsym(libx11, "XGetWindowAttributes"));
    proc_XAllocSizeHints = cosmo_dltramp(cosmo_dlsym(libx11, "XAllocSizeHints"));
    proc_XCheckTypedWindowEvent = cosmo_dltramp(cosmo_dlsym(libx11, "XCheckTypedWindowEvent"));
    proc_XCreateColormap = cosmo_dltramp(cosmo_dlsym(libx11, "XCreateColormap"));
    proc_XCreateFontCursor = cosmo_dltramp(cosmo_dlsym(libx11, "XCreateFontCursor"));
    proc_XCreateWindow = cosmo_dltramp(cosmo_dlsym(libx11, "XCreateWindow"));
    proc_XWarpPointer = cosmo_dltramp(cosmo_dlsym(libx11, "XWarpPointer"));
    proc_XDefineCursor = cosmo_dltramp(cosmo_dlsym(libx11, "XDefineCursor"));
    proc_XDestroyWindow = cosmo_dltramp(cosmo_dlsym(libx11, "XDestroyWindow"));
    proc_XFreeColormap = cosmo_dltramp(cosmo_dlsym(libx11, "XFreeColormap"));
    proc_XFreeCursor = cosmo_dltramp(cosmo_dlsym(libx11, "XFreeCursor"));
    proc_XGetKeyboardMapping = cosmo_dltramp(cosmo_dlsym(libx11, "XGetKeyboardMapping"));
    proc_XGetSelectionOwner = cosmo_dltramp(cosmo_dlsym(libx11, "XGetSelectionOwner"));
    proc_XGrabPointer = cosmo_dltramp(cosmo_dlsym(libx11, "XGrabPointer"));
    proc_XInternAtom = cosmo_dltramp(cosmo_dlsym(libx11, "XInternAtom"));
    proc_XInternAtoms = cosmo_dltramp(cosmo_dlsym(libx11, "XInternAtoms"));
    proc_XSetSelectionOwner = cosmo_dltramp(cosmo_dlsym(libx11, "XSetSelectionOwner"));
    proc_XSetWMNormalHints = cosmo_dltramp(cosmo_dlsym(libx11, "XSetWMNormalHints"));
    proc_XSetWMProtocols = cosmo_dltramp(cosmo_dlsym(libx11, "XSetWMProtocols"));
    proc_XUndefineCursor = cosmo_dltramp(cosmo_dlsym(libx11, "XUndefineCursor"));
    proc_XUngrabPointer = cosmo_dltramp(cosmo_dlsym(libx11, "XUngrabPointer"));
    proc_Xutf8SetWMProperties = cosmo_dltramp(cosmo_dlsym(libx11, "Xutf8SetWMProperties"));
    proc_XkbFreeKeyboard = cosmo_dltramp(cosmo_dlsym(libx11, "XkbFreeKeyboard"));
    proc_XkbFreeNames = cosmo_dltramp(cosmo_dlsym(libx11, "XkbFreeNames"));
    proc_XResourceManagerString = cosmo_dltramp(cosmo_dlsym(libx11, "XResourceManagerString"));
    proc_XrmDestroyDatabase = cosmo_dltramp(cosmo_dlsym(libx11, "XrmDestroyDatabase"));
    proc_XrmGetResource = cosmo_dltramp(cosmo_dlsym(libx11, "XrmGetResource"));
    proc_XkbGetMap = cosmo_dltramp(cosmo_dlsym(libx11, "XkbGetMap"));
    proc_XkbGetNames = cosmo_dltramp(cosmo_dlsym(libx11, "XkbGetNames"));
    proc_XrmGetStringDatabase = cosmo_dltramp(cosmo_dlsym(libx11, "XrmGetStringDatabase"));
    proc_XQueryExtension = cosmo_dltramp(cosmo_dlsym(libx11, "XQueryExtension"));
    proc_XcursorGetDefaultSize = cosmo_dltramp(cosmo_dlsym(libx11, "XcursorGetDefaultSize"));
    proc_XcursorGetTheme = cosmo_dltramp(cosmo_dlsym(libx11, "XcursorGetTheme"));
    proc_XcursorImageCreate = cosmo_dltramp(cosmo_dlsym(libx11, "XcursorImageCreate"));
    proc_XcursorImageDestroy = cosmo_dltramp(cosmo_dlsym(libx11, "XcursorImageDestroy"));
    proc_XcursorImageLoadCursor = cosmo_dltramp(cosmo_dlsym(libx11, "XcursorImageLoadCursor"));
    proc_XcursorLibraryLoadImage = cosmo_dltramp(cosmo_dlsym(libx11, "XcursorLibraryLoadImage"));
    proc_XIQueryVersion = cosmo_dltramp(cosmo_dlsym(libx11, "XIQueryVersion"));
    proc_XISelectEvents = cosmo_dltramp(cosmo_dlsym(libx11, "XISelectEvents"));
}

Display * XOpenDisplay(const char* display_name) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XOpenDisplay(display_name);
}

int XCloseDisplay(Display* display) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XCloseDisplay(display);
}

int XFlush(Display* display) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XFlush(display);
}

int XNextEvent(Display* display, XEvent* event_return) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XNextEvent(display, event_return);
}

int XPending(Display* display) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XPending(display);
}

Status XInitThreads(void) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XInitThreads();
}

Bool XFilterEvent(XEvent* event, Window w) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XFilterEvent(event, w);
}

Bool XkbSetDetectableAutoRepeat(Display* display, Bool detectable, Bool* supported_rtrn) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XkbSetDetectableAutoRepeat(display, detectable, supported_rtrn);
}

int XSync(Display* display, Bool discard) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XSync(display, discard);
}

void XrmInitialize(void) {
    if (libx11 == NULL) { load_x11_shims(); }

    proc_XrmInitialize();
}

int XChangeProperty(Display* display, Window w, Atom property, Atom type, int format, int mode, const unsigned char* data, int nelements) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XChangeProperty(display, w, property, type, format, mode, data, nelements);
}

Status XSendEvent(Display* display, Window w, Bool propagate, long event_mask, XEvent* event_send) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XSendEvent(display, w, propagate, event_mask, event_send);
}

int XFree(void* data) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XFree(data);
}

XErrorHandler XSetErrorHandler(XErrorHandler handler) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XSetErrorHandler(handler);
}

int XConvertSelection(Display* display, Atom selection, Atom target, Atom property, Window requestor, Time time) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XConvertSelection(display, selection, target, property, requestor, time);
}

int XLookupString(XKeyEvent* event_struct, char* buffer_return, int bytes_buffer, KeySym* keysym_return, XComposeStatus* status_in_out) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XLookupString(event_struct, buffer_return, bytes_buffer, keysym_return, status_in_out);
}

Bool XGetEventData(Display* display, XGenericEventCookie* cookie) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XGetEventData(display, cookie);
}

void XFreeEventData(Display* display, XGenericEventCookie* cookie) {
    if (libx11 == NULL) { load_x11_shims(); }

    proc_XFreeEventData(display, cookie);
}

int XGetWindowProperty(Display* display, Window w, Atom property, long long_offset, long long_length, Bool delete, Atom req_type, Atom* actual_type_return, int* actual_format_return, unsigned long* nitems_return, unsigned long* bytes_after_return, unsigned char** prop_return) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XGetWindowProperty(display, w, property, long_offset, long_length, delete, req_type, actual_type_return, actual_format_return, nitems_return, bytes_after_return, prop_return);
}

int XMapWindow(Display* display, Window w) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XMapWindow(display, w);
}

int XUnmapWindow(Display* display, Window w) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XUnmapWindow(display, w);
}

int XRaiseWindow(Display* display, Window w) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XRaiseWindow(display, w);
}

Status XGetWindowAttributes(Display* display, Window w, XWindowAttributes* window_attributes_return) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XGetWindowAttributes(display, w, window_attributes_return);
}

XSizeHints * XAllocSizeHints(void) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XAllocSizeHints();
}

Bool XCheckTypedWindowEvent(Display* display, Window w, int event_type, XEvent* event_return) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XCheckTypedWindowEvent(display, w, event_type, event_return);
}

Colormap XCreateColormap(Display* display, Window w, Visual* visual, int alloc) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XCreateColormap(display, w, visual, alloc);
}

Cursor XCreateFontCursor(Display* display, unsigned int shape) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XCreateFontCursor(display, shape);
}

Window XCreateWindow(Display* display, Window parent, int x, int y, unsigned int width, unsigned int height, unsigned int border_width, int depth, unsigned int class, Visual* visual, unsigned long valuemask, XSetWindowAttributes* attributes) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XCreateWindow(display, parent, x, y, width, height, border_width, depth, class, visual, valuemask, attributes);
}

int XWarpPointer(Display* display, Window src_w, Window dest_w, int src_x, int src_y, unsigned int src_width, unsigned int src_height, int dest_x, int dest_y) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XWarpPointer(display, src_w, dest_w, src_x, src_y, src_width, src_height, dest_x, dest_y);
}

int XDefineCursor(Display* display, Window w, Cursor cursor) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XDefineCursor(display, w, cursor);
}

int XDestroyWindow(Display* display, Window w) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XDestroyWindow(display, w);
}

int XFreeColormap(Display* display, Colormap colormap) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XFreeColormap(display, colormap);
}

int XFreeCursor(Display* display, Cursor cursor) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XFreeCursor(display, cursor);
}

KeySym * XGetKeyboardMapping(Display* display, unsigned int first_keycode, int keycode_count, int* keysyms_per_keycode_return) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XGetKeyboardMapping(display, first_keycode, keycode_count, keysyms_per_keycode_return);
}

Window XGetSelectionOwner(Display* display, Atom selection) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XGetSelectionOwner(display, selection);
}

int XGrabPointer(Display* display, Window grab_window, Bool owner_events, unsigned int event_mask, int pointer_mode, int keyboard_mode, Window confine_to, Cursor cursor, Time time) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XGrabPointer(display, grab_window, owner_events, event_mask, pointer_mode, keyboard_mode, confine_to, cursor, time);
}

Atom XInternAtom(Display* display, const char* atom_name, Bool only_if_exists) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XInternAtom(display, atom_name, only_if_exists);
}

Status XInternAtoms(Display* display, char** names, int count, Bool only_if_exists, Atom* atoms_return) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XInternAtoms(display, names, count, only_if_exists, atoms_return);
}

int XSetSelectionOwner(Display* display, Atom selection, Window owner, Time time) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XSetSelectionOwner(display, selection, owner, time);
}

void XSetWMNormalHints(Display* display, Window w, XSizeHints* hints) {
    if (libx11 == NULL) { load_x11_shims(); }

    proc_XSetWMNormalHints(display, w, hints);
}

Status XSetWMProtocols(Display* display, Window w, Atom* protocols, int count) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XSetWMProtocols(display, w, protocols, count);
}

int XUndefineCursor(Display* display, Window w) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XUndefineCursor(display, w);
}

int XUngrabPointer(Display* display, Time time) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XUngrabPointer(display, time);
}

void Xutf8SetWMProperties(Display* display, Window w, const char* window_name, const char* icon_name, char** argv, int argc, XSizeHints* normal_hints, XWMHints* wm_hints, XClassHint* class_hints) {
    if (libx11 == NULL) { load_x11_shims(); }

    proc_Xutf8SetWMProperties(display, w, window_name, icon_name, argv, argc, normal_hints, wm_hints, class_hints);
}

void XkbFreeKeyboard(XkbDescPtr xkb, unsigned int which, Bool free_all) {
    if (libx11 == NULL) { load_x11_shims(); }

    proc_XkbFreeKeyboard(xkb, which, free_all);
}

void XkbFreeNames(XkbDescPtr xkb, unsigned int which, Bool free_map) {
    if (libx11 == NULL) { load_x11_shims(); }

    proc_XkbFreeNames(xkb, which, free_map);
}

char * XResourceManagerString(Display* display) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XResourceManagerString(display);
}

void XrmDestroyDatabase(XrmDatabase database) {
    if (libx11 == NULL) { load_x11_shims(); }

    proc_XrmDestroyDatabase(database);
}

Bool XrmGetResource(XrmDatabase database, const char* str_name, const char* str_class, char** str_type_return, XrmValue* value_return) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XrmGetResource(database, str_name, str_class, str_type_return, value_return);
}

XkbDescPtr XkbGetMap(Display* display, unsigned int which, unsigned int device_spec) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XkbGetMap(display, which, device_spec);
}

Status XkbGetNames(Display* dpy, unsigned int which, XkbDescPtr xkb) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XkbGetNames(dpy, which, xkb);
}

XrmDatabase XrmGetStringDatabase(const char* data) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XrmGetStringDatabase(data);
}

Bool XQueryExtension(Display* display, const char* name, int* major_opcode_return, int* first_event_return, int* first_error_return) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XQueryExtension(display, name, major_opcode_return, first_event_return, first_error_return);
}

int XcursorGetDefaultSize(Display* dpy) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XcursorGetDefaultSize(dpy);
}

char * XcursorGetTheme(Display* dpy) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XcursorGetTheme(dpy);
}

XcursorImage * XcursorImageCreate(int width, int height) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XcursorImageCreate(width, height);
}

void XcursorImageDestroy(XcursorImage* image) {
    if (libx11 == NULL) { load_x11_shims(); }

    proc_XcursorImageDestroy(image);
}

Cursor XcursorImageLoadCursor(Display* dpy, const XcursorImage* image) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XcursorImageLoadCursor(dpy, image);
}

XcursorImage * XcursorLibraryLoadImage(const char* library, const char* theme, int size) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XcursorLibraryLoadImage(library, theme, size);
}

Status XIQueryVersion(Display* dpy, int* major_version_inout, int* minor_version_inout) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XIQueryVersion(dpy, major_version_inout, minor_version_inout);
}

int XISelectEvents(Display* dpy, Window win, XIEventMask* masks, int num_masks) {
    if (libx11 == NULL) { load_x11_shims(); }

    return proc_XISelectEvents(dpy, win, masks, num_masks);
}
