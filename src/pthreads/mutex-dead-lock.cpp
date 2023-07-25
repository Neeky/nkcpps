#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

struct Foo
{
    int counts = 0;
    pthread_mutex_t lock;
};

int main()
{
    Foo foo;
    pthread_mutex_init(&foo.lock, NULL);

    printf("第一次 pthread_mutex_lock(&foo.lock) 准备执行 \n");
    pthread_mutex_lock(&foo.lock);
    printf("第一次 pthread_mutex_lock(&foo.lock) 执行完成 \n");

    printf("第二次 pthread_mutex_lock(&foo.lock) 准备执行 \n");
    /**
     * pthread_mutex_lock 是互斥的，那怕是对自己；也就是说如果第一次上锁还没有释放，这个时候线程再去上锁的话会失败。
     * 哪怕这把锁自己之前已经申请到了
     */
    pthread_mutex_lock(&foo.lock);
    /**
     * 也就是说这面的代码永远都不会被执行
     */
    printf("第二次 pthread_mutex_lock(&foo.lock) 执行完成 \n");

    pthread_mutex_unlock(&foo.lock);
    pthread_mutex_destroy(&foo.lock);
    return 0;
}