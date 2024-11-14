COSMOS := /opt/cosmos
CC = $(COSMOS)/bin/cosmocc
CXX = $(COSMOS)/bin/cosmoc++

CPPFLAGS := -I deps/sokol -I deps/cimgui -MMD -MP
CFLAGS := -mcosmo -g -ggdb -Wall -O2
CXXFLAGS := $(CFLAGS)
LINUX_CPPFLAGS := -Ishims/linux
WIN32_CPPFLAGS := -Ishims/win32 -I$(COSMOS)/include/libc/nt

BUILD_DIR := .build
BIN_DIR := bin

.PHONY: all clean

all: bin/cosmo-sokol

SRCS := \
	shims/sokol/sokol_windows.c \
	shims/sokol/sokol_linux.c   \
	shims/sokol/sokol_shared.c  \
	shims/sokol/sokol_cosmo.c   \

SRCS += \
	deps/cimgui/cimgui.cpp              \
	deps/cimgui/imgui/imgui.cpp         \
	deps/cimgui/imgui/imgui_demo.cpp    \
	deps/cimgui/imgui/imgui_draw.cpp    \
	deps/cimgui/imgui/imgui_tables.cpp  \
	deps/cimgui/imgui/imgui_widgets.cpp \

SRCS += \
	shims/linux/gl.c \
	shims/linux/x11.c

SRCS += \
	nvapi/nvapi.c \
	win32_tweaks.c

SRCS += main.c

OBJS := $(patsubst %.c,$(BUILD_DIR)/%.o,$(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS)))

DEPS := $(OBJS:.o=.d)

$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/shims/sokol/sokol_windows.o: CPPFLAGS += $(WIN32_CPPFLAGS)
$(BUILD_DIR)/shims/sokol/sokol_linux.o: CPPFLAGS += $(LINUX_CPPFLAGS)
$(BUILD_DIR)/shims/linux/%.o: CPPFLAGS += $(LINUX_CPPFLAGS)
$(BUILD_DIR)/nvapi/%.o: CPPFLAGS += $(WIN32_CPPFLAGS)
$(BUILD_DIR)/win32_%.o: CPPFLAGS += $(WIN32_CPPFLAGS)
$(BUILD_DIR)/main.o: CPPFLAGS += -Invapi

$(BUILD_DIR)/shims/linux/gl.c: shims/linux/gen-gl
	cd shims/linux && ./gen-gl

$(BUILD_DIR)/shims/linux/x11.c: shims/linux/gen-x11
	cd shims/linux && ./gen-x11


$(BIN_DIR)/cosmo-sokol: $(OBJS)
	mkdir -p $(dir $@)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

-include $(DEPS)
