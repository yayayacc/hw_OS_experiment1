#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include <wait.h>
#include<stdlib.h>
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
        //system("./outer");
        //execl("./outer",NULL);//execl使用时第一个参数好像是绝对路径，但如果不加的话就是当前路径
    }
    else{
        pid1 = getpid();
        printf("parent: pid = %d",pid);
        printf("parent: pid1 = %d\n",pid1);
        my_int--;
        printf("父进程中my_int的值：%d,地址为：%d\n",my_int,&my_int);
        wait(NULL);
    }
    my_int += pid1;
    printf("return前修改my_int并且输出的值为：%d\n",my_int);
    return 0;
}