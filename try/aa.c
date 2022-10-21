#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include <wait.h>

int my_int = 1;

int main()
{
    pid_t pid,pid1;
    pid = fork();
    if (pid < 0){
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if ( pid == 0){
        pid1 = getpid();
        printf("child: pid = %d",pid);
        printf("child: pid1 = %d\n",pid1);
        my_int++;
        printf("子进程中my_int的值：%d,地址为：%d\n",my_int,&my_int);
    }
    else{
        pid1 = getpid();
        printf("parent: pid = %d",pid);
        printf("parent: pid1 = %d\n",pid1);
        my_int--;
        printf("父进程中my_int的值：%d,地址为：%d\n",my_int,&my_int);
        wait(NULL);
    }
    return 0;
}