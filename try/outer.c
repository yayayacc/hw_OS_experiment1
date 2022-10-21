#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
    pid_t pid;
    pid = getpid();
    printf("外部函数执行后的pid为：%d\n",pid);
    return 0;
}