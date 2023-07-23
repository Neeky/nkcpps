#include <pthread.h> // pthread_create, pthread_join, pthread_exit
#include <unistd.h>
#include <stdio.h>

/**
 * 在堆上申请一个 int 的长度，并把值设置为 10086， 最后把堆上的地址返回
 */
void *
thread_fun(void *arg)
{
    printf("thread starts running ... \n");
    int *ip = new int;
    *ip = 10086;
    printf("thread well return %d .\n", *ip);
    return ((void *)ip);
}

int main()
{
    int err;
    pthread_t tid;
    void *tret;

    /**
     * 创建一个子线程，在子线程执行完成之后，职得子线程上堆上保存的值，并打印+回收堆上的空间
     */
    // 1. 创建线程
    err = pthread_create(&tid, NULL, thread_fun, NULL);
    if (err != 0)
        perror("can't create thread fail . \n");

    // 2. join 的时候并收回值
    err = pthread_join(tid, &tret);
    if (err != 0)
        perror("join thread fail . \n");
    printf("thread joined, main thread gots return value = %d. \n", *(int *)tret);

    // 3. 回收堆内存
    printf("free mem .\n");
    delete (int *)tret;

    return 0;
}