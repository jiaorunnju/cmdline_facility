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
char backup[MAX];

int tag = 0;
void handleLine(){
    strcpy(backup,buff);
    char *temp = strtok(buff," \t");
    char *t;
    if(strcmp(temp,head) == 0){
        t = temp+strlen(temp)+1;
        strcat(before," ");
        strcat(before,t);
    }else{
        if(tag != 0){
            printf("%s\n",before);
        }
        strcpy(before,backup);
        strcpy(head,temp);
        ++tag;
    }
}

int main(int argc,char *argv[]){
    head[0] = '\0';
    before[0] = '\0';

    while (fgets(buff,LINE,stdin) != NULL){
        buff[strlen(buff)-1] = '\0';
        handleLine();
    }
    printf("%s\n",before);
}
