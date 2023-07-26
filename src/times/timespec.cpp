#include <time.h>  // timespec, clock_gettime, CLOCK_REALTIME
#include <stdio.h> // printf

int main()
{
    timespec t;
    int err;
    err = clock_gettime(CLOCK_REALTIME, &t);
    if (err != 0)
    {
        printf("clock-gettime fail .\n");
    }
    /**
     * nsec 纳秒 10 负 9 次方秒
     */
    printf("sec: %d, nsec: %d \n", t.tv_sec, t.tv_nsec);
    return 0;
}