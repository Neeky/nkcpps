#include <dirent.h>
#include <stdio.h>
#include <error.h>

/**
 * 打印出 /tmp/ 目录下的目录项(名)
 */
int main()
{
    DIR *dp;
    struct dirent *dirp;

    /**
     * 打开目录
     */
    dp = opendir("/tmp/");
    if (dp == NULL)
    {
        perror("open-dir fail ");
    }

    /**
     * 读取目录项
     */
    while ((dirp = readdir(dp)) != NULL)
    {
        printf("item: %s \n", dirp->d_name);
    }

    /**
     * 关闭目录句柄
     */
    closedir(dp);
    return 0;
}