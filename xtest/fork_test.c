#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *thread_1()
{
    printf("A\n");

}
void *thread_2()
{
    printf("B\n");

}
void *thread_3()
{
    printf("C\n");

}
int main()
{
    int pid;
    pthread_t tid_1,tid_2,tid_3;
    int ret;
    int x=0;
    pid=fork();
    printf("pid=%d,x=%d \n",pid,x);
    if(pid==0)//child process
    {
        printf("pid: %d child process\n",pid);
        ret = pthread_create(&tid_1,NULL, thread_1, NULL);
        ret = pthread_create(&tid_2,NULL, thread_2, NULL);
        ret = pthread_create(&tid_3,NULL, thread_3, NULL);
        pthread_join(tid_1,NULL);
        pthread_join(tid_2,NULL);
        pthread_join(tid_3,NULL);
        printf("child process exit\n");
    }
    else
    {
        printf("pid:%d  parent process\n",pid);
    }
    return 0;
}