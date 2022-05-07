#include "ku_fs_input.h"
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
#define MSG_SIZE sizeof(int)
#define NAME "/m_queue"
#define MAX_PRIO 5
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>

void generateChild();
int searchFunc();
int main(int argc,char *argv[]){
    printf("\n들어온 인자수 : %d\n",argc);
    char * str=argv[1];
    int processNum=atoi(argv[2]);
 
    printf("\n검색할 패턴 값: %s\n",str);
    printf("\n생성할 프로세스 수: %d\n",processNum);
    pid_t one;

    if((one =fork())==0){
        struct mq_attr attr;
    int value;
    unsigned int prio=0;
    mqd_t mqdes;
    

    attr.mq_maxmsg=10;
    attr.mq_msgsize=sizeof(value);

    mqdes=mq_open(NAME, O_CREAT|O_RDWR,0666,&attr);
    

    /*for(int i=0;i<10;i++){
        printf("sending a message %d\n",value);

        mq_send(mqdes,(char*)&value,MSG_SIZE,prio);
        value++;
    }*/
       
         char *ptr=strstr(input,str);
    int count=0;
    while(ptr!=NULL){
        int value=(ptr-input);
        mq_send(mqdes,(char*)&value,sizeof(int),prio);
        ptr=strstr(ptr+1,str);
        count++;

    }
    mq_close(mqdes);
    }
    else{
         struct mq_attr attr;
    int value=0;
  
    int num_msg=0;
    unsigned int prio;
    mqd_t mqdes;

    attr.mq_maxmsg=10;
    attr.mq_msgsize=sizeof(value);

    mqdes=mq_open(NAME,O_CREAT|O_RDWR,0666,&attr);

    printf("\n받은 메세지 출력: ");
   for(int i=0;i<10;i++){

        mq_receive(mqdes,(char*)&value,MSG_SIZE,&prio);
        printf("%d ",value);
   }
    
       printf("\n");
    }
    //pid_t pid[processNum];
    //generateChild(processNum,pid);

    for(int i=0;i<MAXS;i++){
        printf("%c ",input[i]);
    }
    printf("\n");
    char *ptr=strstr(input,str);
    int count=0;
    while(ptr!=NULL){
        printf("%ld\n",(ptr-input));
        ptr=strstr(ptr+1,str);
        count++;

    }
    


}
void generateChild(int num,pid_t pid[]){
    int childCount=0;
    while(pid[childCount]=fork()){
        childCount++;
        if(childCount==num){
            break;
        }

    }
}
int searchFunc(){
    
}

