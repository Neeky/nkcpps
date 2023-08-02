#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_SIZE 4096

int main()
{
    int n = -1;
    char buf[MAX_SIZE];

    /**
     * 从 stdin 中读取数据，只要讲到有数据就进入 while 循环
     */
    while ((n = read(STDIN_FILENO, buf, MAX_SIZE)) > 0)
    {
        if (write(STDOUT_FILENO, buf, n) != n)
        {
            printf("write got err, want write %d bytes, but fail .", n);
            break;
        }
    }

    if (n < 0)
    {
        printf("read fail .\n");
    }

    return 0;
}