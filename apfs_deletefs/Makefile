export TARGET=iphone:clang:13.0:10.3
export ARCHS=arm64 arm64e
export DEBUG=0

include $(THEOS)/makefiles/common.mk

TOOL_NAME = apfs_deletefs

$(TOOL_NAME)_FILES = $(TOOL_NAME).c
$(TOOL_NAME)_PRIVATE_FRAMEWORKS = APFS
$(TOOL_NAME)_CODESIGN_FLAGS = -S../entitlements-disk.xml

include $(THEOS_MAKE_PATH)/tool.mk
