#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

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
        printf("child: pid1 = %d",pid);
    }
    else{
        pid1 = getpid();
        printf("parent: pid = %d",pid);
        printf("parent: pid1 = %d",pid1);
        wait(NULL);
    }
    return 0;
}