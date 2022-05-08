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
void searchFunc();
int main(int argc,char *argv[]){
   // printf("\n들어온 인자수 : %d\n",argc);
     char * str=argv[1];
    int processNum=atoi(argv[2]);
 
   // printf("\n검색할 패턴 값: %s\n",str);
    //printf("\n생성할 프로세스 수: %d\n",processNum);
    pid_t one;
    pid_t pid[processNum];

    if((one =fork())==0){
       // printf("\n 자식 프로세스의 PID : %d", getpid());
      generateChild(processNum,pid,str);
    }
    else{
      //  printf("\n 부모프로세스의 PID : %d",getpid());
         struct mq_attr attr;
    int value=0;
  
    int num_msg=0;
    unsigned int prio;
    mqd_t mqdes;

    attr.mq_maxmsg=10;
    attr.mq_msgsize=sizeof(value);

    mqdes=mq_open(NAME,O_CREAT|O_RDWR,0666,&attr);

//    printf("\n받은 메세지 출력: ");
    char *ptr =strstr(input,str);
   while(ptr!=NULL){

        mq_receive(mqdes,(char*)&value,MSG_SIZE,&prio);
        printf("%d\n",value);
        ptr=strstr(ptr+1,str);

   }
   
   mq_close(mqdes);
   mq_unlink(NAME);
   exit(0);
    
    }
   
  
    exit(0);
 

}
void generateChild(int num,pid_t pid[],char* str){
    int childCount=0;
    for(int i=0;i<childCount;i++){
        if((pid[i]=fork())==0){
            exit(0);
        }
    }
    searchFunc(str);

}
void searchFunc(char* str){
        struct mq_attr attr;
    int value;
    unsigned int prio=0;
    mqd_t mqdes;
    

    attr.mq_maxmsg=10;
    attr.mq_msgsize=sizeof(value);

    mqdes=mq_open(NAME, O_CREAT|O_RDWR,0666,&attr);
    
         char *ptr=strstr(input,str);
    int count=0;
    
    while(ptr!=NULL){
        value=(ptr-input);
        mq_send(mqdes,(char*)&value,sizeof(int),prio);
       // printf("\nsending val : %d",value);
        ptr=strstr(ptr+1,str);
        count++;

    }
    mq_close(mqdes);
    
}

