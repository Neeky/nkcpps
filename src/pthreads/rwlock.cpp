#include <pthread.h>
#include <stdio.h>

struct Foo
{
    int data = 100;
    pthread_rwlock_t lock;
};

void *thread_fun(void *arg)
{
    struct Foo *fp = (struct Foo *)arg;
    pthread_t tid = pthread_self();
    // 1. 上写锁
    printf("子线程 %d 准备申请写锁 \n", tid % 100);
    pthread_rwlock_wrlock(&fp->lock);

    // 2. 锁定成功
    printf("子线程 %d 更新数据 \n", tid % 100);
    fp->data = 200;

    // 3. 解锁
    pthread_rwlock_unlock(&fp->lock);
    printf("子线程 %d 释放锁 \n", tid % 100);
    return NULL;
}

int main()
{
    struct Foo foo;
    pthread_t tid;
    pthread_rwlock_init(&foo.lock, NULL);

    pthread_create(&tid, NULL, thread_fun, &foo);
    pthread_join(tid, NULL);

    // 1. 加锁
    printf("\n主线程准备加读锁 \n");
    pthread_rwlock_rdlock(&foo.lock);
    printf("主线程读到数据 foo.data = %d \n", foo.data);

    // 2. 释放锁
    printf("主线程释放锁 \n");
    pthread_rwlock_unlock(&foo.lock);

    // 3. 清理锁
    pthread_rwlock_destroy(&foo.lock);

    return 0;
}
