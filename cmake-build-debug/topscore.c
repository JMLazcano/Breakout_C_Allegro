#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER 150

void selectionSort(char array[][BUFFER], int n){
char temp[BUFFER];
int i,j;
for (i = 0; i < n - 1 ; i++){
for (j = i + 1; j < n; j++){
if (strcmp(array[i], array[j]) < 0){
strcpy(temp, array[i]);
strcpy(array[i], array[j]);
strcpy(array[j], temp);
}
}
}
}

void TopScores(){
char message[12][150],buffer[150];
int i=0,z=0;
FILE *file_in;
file_in=fopen("UserScores.txt", "r");

while(fgets(buffer,150,file_in)){
strcpy(message[i],buffer);
//printf("Top Score %d: %s",i,message[i]);
i++;
}
//int n=sizeof(message)/sizeof(message[0]);
selectionSort(message,i);
fclose(file_in);
FILE *fp;
int cant=10;
if(i<10){
cant=i;
}
fp = fopen("UserScores.txt", "w+");
for(z=0;z<cant;z++){
fprintf(fp,"%s",message[z]);
printf("Top Score %d: %s",z+1,message[z]);
}
fclose(fp);
}

void userScore(char userx[],long int scorex){

FILE *fp;
fp = fopen("UserScores.txt", "a+");
fprintf(fp,"%d %s\n",scorex,userx);
fclose(fp);
TopScores();
}
void users(char userxn[]){
FILE *fp;
fp = fopen("UserS.txt", "a+");
fprintf(fp,"%d %s\n",userxn);
fclose(fp);

}

void printArray(char stringArray[][BUFFER], int stringCount){
int i;
for(i=0;i<stringCount;i++){
printf("%s ",stringArray[i]);
}
printf("\n");
}



int main() {
setbuf(stdout,NULL);

char user[]="JuanMa",user2[]="sergio";
long int score =9000,score2=1;

userScore(user2,score2);
//userScore(user,score);



return 0;
}
