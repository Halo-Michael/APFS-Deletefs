TARGET = APFS Deletefs
VERSION = 0.2.0
CC = xcrun -sdk iphoneos clang -arch arm64 -arch arm64e -miphoneos-version-min=10.3
LDID = ldid

.PHONY: all clean

all: clean postinst apfs_deletefs
	mkdir com.michael.apfs-deletefs_$(VERSION)_iphoneos-arm
	mkdir com.michael.apfs-deletefs_$(VERSION)_iphoneos-arm/DEBIAN
	cp control com.michael.apfs-deletefs_$(VERSION)_iphoneos-arm/DEBIAN
	mv postinst com.michael.apfs-deletefs_$(VERSION)_iphoneos-arm/DEBIAN
	mkdir com.michael.apfs-deletefs_$(VERSION)_iphoneos-arm/sbin
	mv apfs_deletefs/.theos/obj/apfs_deletefs com.michael.apfs-deletefs_$(VERSION)_iphoneos-arm/sbin
	dpkg -b com.michael.apfs-deletefs_$(VERSION)_iphoneos-arm

postinst: clean
	$(CC) postinst.c -o postinst
	strip postinst
	$(LDID) -Sentitlements.xml postinst

apfs_deletefs: clean
	bash make-apfs_deletefs.sh

clean:
	rm -rf com.michael.apfs-deletefs_* postinst apfs_deletefs/.theos

