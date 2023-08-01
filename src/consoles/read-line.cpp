#include <unistd.h>
#include <stdio.h>  // stdin, stdout
#include <string.h> // strlen

int main()
{
    char buf[512];
    printf("please input: ");

    /**
     * fgets 会包括行尾的换行
     */
    fgets(buf, 512, stdin);
    printf("your input-len: %d\n", strlen(buf));
    printf("your inputs: %s", buf);
}