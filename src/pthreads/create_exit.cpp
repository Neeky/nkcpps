#include <pthread.h>
#include <unistd.h>
#include <iostream>

pthread_t ntid;

/**
 * 线程真正要执行的逻辑，注意这里并没用按 ptread_create 约定的函数接口来定义
 * 如果使用了对应的函数接口，那就要求我们在要业务逻辑的函数中处理参数的类型转换(pthread_create 要求使用的是 void * 类型的形式参数)
 */
void printids(const char *s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    // 取得当前线程的线程 ID
    tid = pthread_self();
    printf("%s pid:%lu tid:%lu (0x%lx) \n", s, (unsigned long)pid,
           (unsigned long)tid, (unsigned long)tid);
}

/**
 * 定义一个符合 pthread_create 接口的包装函数，减少 pthread_create 对业务逻辑的侵入
 */
void *thr_fn(void *arg)
{
    printids("new  thread");
    return (void *)0;
}

int main()
{
    int err;
    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if (err != 0)
    { // err 不是 0 的时候，说明 pthread_create 失败了
        perror("pthread-create fail .");
    }

    printids("main thread");
    sleep(1);
    return 0;
}