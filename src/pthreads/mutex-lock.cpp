#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

struct Foo
{
    int counts = 0;
    pthread_mutex_t lock;
};

void *thread_fun_1(void *arg)
{
    struct Foo *fp = (struct Foo *)arg;
    pthread_t tid = pthread_self();
    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&fp->lock);

        printf("thread:%lu 取得了锁，准备 +1 \n", tid % 1000);
        fp->counts++;
        printf("thread:%lu 完成了操作准备释放锁,当前 counts:%d \n", tid % 1000, fp->counts);

        pthread_mutex_unlock(&fp->lock);

        sleep(1);
    }
    return NULL;
}

int main()
{
    Foo foo;
    pthread_t tid1, tid2;
    pthread_mutex_init(&foo.lock, NULL);
    printf("Foo.counts:%d \n", foo.counts);

    /**
     * 在子线程中对 foo.lock 进行 ++ 10 次的操作
     */
    pthread_create(&tid1, NULL, thread_fun_1, (void *)&foo);
    pthread_create(&tid2, NULL, thread_fun_1, (void *)&foo);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("Foo.counts:%d \n", foo.counts);

    pthread_mutex_destroy(&foo.lock);
    return 0;
}