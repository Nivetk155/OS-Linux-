#include<stdio.h>
#include<stdlib.h>
int main(){
char buffer[200];
FILE *file1;

// To write the content in a file..
printf("The file is opened for writing the content...");
file1=fopen("suba.txt","w");
fprintf(file1,"Hii!!! I am Nivetha..\n");
fprintf(file1,"I am learning linux..\n");
if(file1==NULL){
    perror("file is not created and written anything...\n");
    return 0;
}
fclose(file1);

// To read the content in a file and store in a buffer..
printf("The file is opened for reading the content in a file..\n");
file1=fopen("suba.txt","r");
while((fgets(buffer,sizeof(buffer),file1))!=NULL){
   printf("%s",buffer);
}
if(file1==NULL){
   perror("file is not created and written anything...");
   return 0;
}

// To append the content in a file...
printf("The file is opened for appending the content...\n");
file1=fopen("suba.txt","a");
fprintf(file1,"And also I am learning Data Structure..\n");
if(file1==NULL){
    perror("file is not created and written anything...");
    return 0;
}
fclose(file1);

// To read the appened content in a file and store in a buffer..
printf("The file is opened for reading the appened content in a file..\n");
file1=fopen("suba.txt","r");
while((fgets(buffer,sizeof(buffer),file1))!=NULL){
   printf("%s",buffer);
}
fclose(file1);

//rename the file..
if(rename("suba.txt","Nivi.txt")==0){
   printf("The file is renamed successfully..\n");
}
else{
  printf("The file is not renamed..\n");
  } 
   
//Delete the file...
if(remove("Nivi.txt")==0){
   printf("The file is deleted..\n");
}
else {
 printf("The file is not deleted..\n");
}
return 0;
}
