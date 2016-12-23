/*************************************************************************
# File Name: mergecol.c
# Author :Jiaorun
# Created Time: Tue 20 Dec 2016 11:50:22 PM CST
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 512
#define LINE 500
#define HEAD 128

char buff[MAX];
char before[MAX];
char head[HEAD];
char headbefore[HEAD];

int tag = 0;
void handleLine(){
    if(strcmp(head,headbefore) != 0 && tag !=0){
        printf("%s%s\n",headbefore,before);
        strcpy(headbefore,head);
        strcpy(before,buff);
    }else{
        strcpy(headbefore,head);
        strcat(before,buff);
    }
    ++tag;
}

int main(int argc,char *argv[]){
    head[0] = '\0';
    before[0] = '\0';
    while(scanf("%s",head) != EOF){
        fgets(buff,LINE,stdin);
        buff[strlen(buff)-1] = '\0';
        handleLine();
    }
    printf("%s%s\n",headbefore,before);
}
