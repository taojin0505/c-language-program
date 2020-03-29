/**
 * File              : testtmp.c
 * Author            : Tao Jin <tonytao0505@outlook.com>
 * Date              : 13.07.2019
 * Last Modified Date: 13.07.2019
 * Last Modified By  : Tao Jin <tonytao0505@outlook.com>
 */
#include "stdlib.h"
#include <unistd.h>

int main()
{
    int fd;
    char templates[] = "./100_XXXXXX";
    char buffer[100];

    fd = mkstemp(templates);
    for (int i = 0; i < 100; i++) {
        write(fd, buffer, 100);
    }
    close(fd);

    return 0;
}
