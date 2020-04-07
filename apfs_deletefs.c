#include <dlfcn.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
typedef int (*apfs_delete_fs_func) (const char * dev_name);

int apfs_delete_fs(const char * dev_name){
    char *dylib_path = "/System/Library/PrivateFrameworks/APFS.framework/APFS";
    void *handle = dlopen(dylib_path, RTLD_GLOBAL | RTLD_NOW);
    if (handle == NULL) {
        fprintf(stderr, "%s\n", dlerror());
    } else {
        apfs_delete_fs_func func = dlsym(handle, "APFSVolumeDelete");
        if (func) {
            int ret = func(dev_name);
            return ret;
        }
        dlclose(handle);
    }
    return -1;
}

void usage(){
    printf("Usage:\tapfs_deletefs <dev name>\n");
    printf("\t-h\t\t\tPrint this help.\n");
}

int main(int argc, char **argv)
{
    if (getuid() != 0) {
        setuid(0);
    }
    
    if (getuid() != 0) {
        printf("Can't set uid as 0.\n");
        return 1;
    }
    
    if (argc != 2) {
        usage();
        return 1;
    } else if (strcmp(argv[1], "-h") == 0) {
        usage();
        return 1;
    }
    
    int ret = apfs_delete_fs(argv[1]);
    if (ret){
        printf("Failed to delete fs %s.\n", argv[1]);
    } else {
        printf("Successfully deleted fs %s.\n", argv[1]);
    }
    
    return ret;
}
