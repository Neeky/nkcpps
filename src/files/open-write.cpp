#include <fcntl.h>
#include <error.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <error.h>

int main()
{
    char message[128] = "hello world";
    char filename[128] = "/tmp/test.txt";
    /**
     * 打开
     */
    int fd = open(filename, O_CREAT | O_RDWR);
    if (fd == -1)
    {
        perror("open");
    }
    printf("open file '%s' success .\n", filename);
    /**
     * 写入
     */
    size_t nwrite = write(fd, message, strlen(message));
    printf("write %d byte to file .\n", nwrite);
    /**
     * 关闭
     */
    close(fd);
    return 0;
}