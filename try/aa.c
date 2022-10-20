#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
    pid = fork();
    if (pid < 0){
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if ( pid == 0){
        pid = getpid();
        printf("child: pid = %d",pid);
        printf("child: pid1 = %d",pid);
        
    }
}