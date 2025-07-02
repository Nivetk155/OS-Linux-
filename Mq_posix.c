#include<stdio.h>
#include<stdlib.h>
#include<mqueue.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main()
{   mqd_t mq;
char buffer[100];
    struct mq_attr attr;
       attr.mq_flags =0;
        attr.mq_maxmsg=10;
        attr.mq_msgsize=100;
       attr.mq_curmsgs=0;
    mq=mq_open("/mq",O_CREAT|O_WRONLY,0644,&attr);
    if(mq==-1){
        perror("It is not opened");
        exit(1);
    }
    for(int i=0;i<10;i++){
        fgets(buffer,sizeof(buffer),stdin);// to get the string
          buffer[strcspn(buffer, "\n")] = '\0';  // remove newline
//to check the messagequeue
            if (mq_send(mq, buffer, strlen(buffer) + 1,0) == -1) {
                perror("mg is not sent");
            } else {
                printf("Sent: %s\n", buffer);
            }
        }
        mq_close(mq);
        mq=mq_open("/mq",O_RDONLY);  
         for(int i=0;i<10;i++){
        if(mq_receive(mq,buffer,sizeof(buffer),NULL)==-1){
            perror("mq is not recieve");
        }
        else{
            printf("Recieved Content:%s\n",buffer);
        }
         }
        mq_close(mq);
        mq_unlink("/mq");
    
    return 0;
}
