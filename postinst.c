#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    if (getuid() != 0) {
        printf("Run this as root!\n");
        return 1;
    }

    chown("/sbin/apfs_deletefs", 0, 0);
    chmod("/sbin/apfs_deletefs", 06755);

    return 0;
}
