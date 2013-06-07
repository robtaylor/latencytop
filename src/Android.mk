include $(CLEAR_VARS)

LOCAL_MODULE:= latencytop-real

LOCAL_MODULE_TAGS:= eng debug

LOCAL_SRC_FILES:= \
	src/latencytop.c \
	src/text_dump.c \
	src/translate.c \
	src/android.c

LOCAL_SHARED_LIBRARIES:= \
	libglib-2.0

LOCAL_C_INCLUDES:= \
	-ggdb3 -00 \
	$(latencytop_real_TOP)/src \
	external/glib         \
	external/glib/glib    \
	external/glib/android

LOCAL_CFLAGS := -include $(latencytop_real_TOP)/src/android.h

LOCAL_PRELINK_MODULE:= false

LOCAL_ARM_MODE:= arm

include $(BUILD_EXECUTABLE)
