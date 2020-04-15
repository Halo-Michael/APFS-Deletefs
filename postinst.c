#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    if (getuid() != 0) {
        printf("Run this as root!\n");
        return 1;
    }
    system("chown root:wheel /sbin/apfs_deletefs");
    system("chmod 6755 /sbin/apfs_deletefs");
    return 0;
}
