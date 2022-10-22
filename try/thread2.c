#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<wait.h>
#include<pthread.h>
#include<sys/syscall.h>
#include<stdlib.h>

void * getId(void * tem){
    printf("child, the tid=%lu, pid=%d\n",pthread_self(),syscall(SYS_gettid));
    //system("./outer");
    execl("./outer",NULL);
}

int main(int argc,char *argv[])
{
    pthread_t tid1;
    pthread_create(&tid1,NULL,getId,NULL);
    pthread_join(tid1,NULL);
    printf("parent, the tid=%lu, pid=%d\n",pthread_self(),syscall(SYS_gettid));
    printf("parent, getpid()=%d\n",getpid());
    return 0;
}