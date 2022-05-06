#include "ku_fs_input.h"
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>

void generateChild();
int main(int argc,char *argv[]){
    printf("\n들어온 인자수 : %d\n",argc);

    char * str=argv[1];
    int processNum=atoi(argv[2]);

    printf("\n검색할 패턴 값: %s\n",str);
    printf("\n생성할 프로세스 수: %d\n",processNum);
    pid_t pid[processNum];
    generateChild(processNum,pid);

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
    while(pid=fork){
        childCount++;
        if(childCount==num){
            break;
        }

    }
}

