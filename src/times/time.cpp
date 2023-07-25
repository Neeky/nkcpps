#include <time.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    /**
     * 获取当前的 timestamp 值，精度是 秒级
     */
    time_t t = time(NULL);
    printf("timestamp: %d \n", t);
    return 0;
}