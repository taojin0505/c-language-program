/**
 * File              : gettime.c
 * Author            : Tao Jin <tonytao0505@outlook.com>
 * Date              : 29.05.2019
 * Last Modified Date: 29.05.2019
 * Last Modified By  : Tao Jin <tonytao0505@outlook.com>
 */

#include <stdio.h>
#include <time.h>

int main()
{
    struct timespec start, end, time;

    clock_gettime(CLOCK_REALTIME, &start);
    for (int i = 0; i < 40000000; i++) {
        clock_gettime(CLOCK_REALTIME, &time);
    }
    clock_gettime(CLOCK_REALTIME, &end);
    printf("start sec %ld ns %ld\n",start.tv_sec,start.tv_nsec);
    printf("end sec %ld ns %ld\n",end.tv_sec,end.tv_nsec);
    return 0;
}
