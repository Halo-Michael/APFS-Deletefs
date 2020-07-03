#include <stdio.h>
#include <string.h>
#include <unistd.h>
int APFSVolumeDelete(const char *);

void usage(){
    printf("Usage:\tapfs_deletefs <dev name>\n");
    printf("\t-h\tPrint this help.\n");
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
        return 3;
    } else if (strcmp(argv[1], "-h") == 0) {
        usage();
        return 2;
    }

    int ret = APFSVolumeDelete(argv[1]);
    if (ret) {
        printf("Failed to delete fs %s.\n", argv[1]);
    } else {
        printf("Successfully deleted fs %s.\n", argv[1]);
    }

    return ret;
}
