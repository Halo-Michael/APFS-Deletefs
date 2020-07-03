TARGET = APFS Deletefs
VERSION = 0.2.1
CC = xcrun -sdk ${THEOS}/sdks/iPhoneOS13.0.sdk clang -arch arm64 -arch arm64e -miphoneos-version-min=10.3
LDID = ldid

.PHONY: all clean

all: clean postinst apfs_deletefs
	mkdir com.michael.apfs-deletefs_$(VERSION)_iphoneos-arm
	mkdir com.michael.apfs-deletefs_$(VERSION)_iphoneos-arm/DEBIAN
	cp control com.michael.apfs-deletefs_$(VERSION)_iphoneos-arm/DEBIAN
	mv postinst com.michael.apfs-deletefs_$(VERSION)_iphoneos-arm/DEBIAN
	mkdir com.michael.apfs-deletefs_$(VERSION)_iphoneos-arm/sbin
	mv apfs_deletefs com.michael.apfs-deletefs_$(VERSION)_iphoneos-arm/sbin
	dpkg -b com.michael.apfs-deletefs_$(VERSION)_iphoneos-arm

postinst: clean
	$(CC) postinst.c -o postinst
	strip postinst
	$(LDID) -Sentitlements.xml postinst

apfs_deletefs: clean
	$(CC) ${THEOS}/sdks/iPhoneOS13.0.sdk/System/Library/PrivateFrameworks/APFS.framework/APFS.tbd apfs_deletefs.c -o apfs_deletefs
	strip apfs_deletefs
	$(LDID) -Sentitlements-disk.xml apfs_deletefs

clean:
	rm -rf com.michael.apfs-deletefs_* postinst apfs_deletefs

