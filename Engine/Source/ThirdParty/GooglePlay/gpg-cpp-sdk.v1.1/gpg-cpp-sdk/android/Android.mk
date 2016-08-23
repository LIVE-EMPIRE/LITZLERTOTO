LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

PRIVATE_APP_STL := $(APP_STL)
PRIVATE_APP_STL := $(PRIVATE_APP_STL:_shared=)
PRIVATE_APP_STL := $(PRIVATE_APP_STL:_static=)

LOCAL_MODULE := libgpg-1
LOCAL_SRC_FILES := lib/$(PRIVATE_APP_STL)/$(TARGET_ARCH_ABI)/libgpg.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include

include $(PREBUILT_STATIC_LIBRARY)