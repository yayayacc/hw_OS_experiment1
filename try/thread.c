#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<wait.h>
#include<pthread.h>
#include <sys/syscall.h>

struct message{
    int my_int;
    int times;
    int mutex;
};

// void * test(void * aa){
//     *(int * )aa ++;
//     printf("4654");
//     return aa;
// }


void *subtraction(void *);
void *plus(void *);

int main(int argc, char *argv[])
{
    struct message tem;
    tem.my_int = 0;
    tem.times = 0;
    tem.mutex = 1;//用于解决同步互斥问题
    //int test2 = 0;
    pthread_t tid1, tid2;
    //pthread_t test1;
    //pthread_create(&test1,NULL, test,&test2);
    pthread_create(&tid1,NULL, subtraction,&tem);
    pthread_create(&tid2,NULL, plus,&tem);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    //pthread_join(test1,NULL);
    return 0;
}

void *subtraction(void * a){
    struct message* tem = (struct message *)a;
    while(!tem->mutex);
    tem->mutex = 0;
    for(int i = 0;i < 5000;i++){
        tem->my_int--;
        tem->times++;
        printf("%d  ",tem->my_int);
        if(tem->times%50 == 0) printf("\n");
    }
    tem->mutex = 1;
}

void *plus(void * a){
    struct message* tem = (struct message *)a;
    while(!tem->mutex);
    tem->mutex = 0;
    for(int i = 0;i < 5000;i++){
        tem->my_int++;
        tem->times++;
        printf("%d  ",tem->my_int);
        if(tem->times%50 == 0) printf("\n");
    }
    tem->mutex = 1;
}