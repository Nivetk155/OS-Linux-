#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(){
int fd[2];
 //pipe(fd)-create the pipe
if(pipe(fd)==-1){
perror("Pipe is not created");
return 0;
}
pid_t pid;
pid= fork();
 if(pid==-1){
 perror("fork failed..\n");
 return 0;
 }
 //parent process
 else if(pid>0){
 char str[20]="hello linux...";
 close(fd[0]);
 write(fd[1],str,strlen(str)+1);
 close(fd[1]);
 }
  //child process
 else{
 char str1[20];
 close(fd[1]);
 read(fd[0],str2,sizeof(str1));
 printf("%s\n",str2);
 close(fd[0]);
 }
 return 0;
 }
