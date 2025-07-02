#include <stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;
    pid=fork();
    if (pid<0){
        perror("fork is not executed\n");
        exit (1);
    }
//Child process
    else if(pid==0){
        printf ("child process is created\n");
        printf("Child pid:%d\n",getpid());
        printf("Child is exit\n");
    }
//Parent process
    else{
        printf ("parent process is created\n");
        printf("Child pid:%d parent pid:%d\n",pid,getpid());
       wait(NULL);
        printf("parent is exit\n");
    }
    return 0;
}
