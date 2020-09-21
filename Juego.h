//
// Created by Serch And JuanMa on 04/12/2018.
//

#ifndef PRUEBAS_JUEGO_H
#define PRUEBAS_JUEGO_H
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
        printf("%d",i);
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
        fprintf(fp,"%s\n",message[z]);
        printf("Top Score %d: %s\n",z+1,message[z]);
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
    fprintf(fp,"%s\n",userxn);
    fclose(fp);

}

//int resolv[][12]={};
struct USER user;
struct USER{
    char  username[30];
};
struct BALL ball;
struct BALL{
    int ball_x;
    int ball_y;
    int tempX;
    int tempY;
    int f;
    int score;
    int lives;
};
struct BLOCK block1,block2,block3,block4,block5,block6,block7,block8,block9,block10,block11,block12;
struct BLOCK bar;
struct BLOCK{
    int blockx1;
    int blocky1;
    int gross;
    int blockx2;
    int blocky2;
    int barx;
    int bary;


};

void BlockDestroy(){

}

void MoveBALL(){
    ball.tempX+=ball.ball_x;
    ball.tempY-=ball.ball_y;
    if(ball.tempY<=block1.blocky1 && ball.tempY>=block1.blocky1-30 && (ball.tempX<=block1.blockx1+80 && ball.tempX>=block1.blockx1-110)){
        ball.ball_y*=ball.f;
        ball.ball_x*=ball.f;
        block1.blockx1=0;
        block1.blocky1=0;
        block1.blockx2=0;
        block1.blocky2=0;
        ball.score++;
    }else if(ball.tempY<=block2.blocky1&& ball.tempY>=block2.blocky1-30 && (ball.tempX<=block2.blockx1+80 && ball.tempX>=block2.blockx1-110)){
        ball.ball_y*=ball.f;
        ball.ball_x*=ball.f;
        block2.blockx1=0;
        block2.blocky1=0;
        block2.blockx2=0;
        block2.blocky2=0;
        ball.score++;
    }else if(ball.tempY<=block3.blocky1&& ball.tempY>=block3.blocky1-30 && (ball.tempX<=block3.blockx1+80 && ball.tempX>=block3.blockx1-110)){
        ball.ball_y*=ball.f;
        ball.ball_x*=ball.f;
        block3.blockx1=0;
        block3.blocky1=0;
        block3.blockx2=0;
        block3.blocky2=0;
        ball.score++;
    }else if(ball.tempY<=block4.blocky1&& ball.tempY>=block4.blocky1-30 && (ball.tempX<=block4.blockx1+80 && ball.tempX>=block4.blockx1-120)){
        ball.ball_y*=ball.f;
        ball.ball_x*=ball.f;
        block4.blockx1=0;
        block4.blocky1=0;
        block4.blockx2=0;
        block4.blocky2=0;
        ball.score++;
    }else if(ball.tempY<=block5.blocky1&& ball.tempY>=block5.blocky1-30 && (ball.tempX<=block5.blockx1+80 && ball.tempX>=block5.blockx1-120)){
        ball.ball_y*=ball.f;
        ball.ball_x*=ball.f;
        block5.blockx1=0;
        block5.blocky1=0;
        block5.blockx2=0;
        block5.blocky2=0;
        ball.score++;
    }else if(ball.tempY<=block6.blocky1&& ball.tempY>=block6.blocky1-30 && (ball.tempX<=block6.blockx1+80 && ball.tempX>=block6.blockx1-120)){
        ball.ball_y*=ball.f;
        ball.ball_x*=ball.f;
        block6.blockx1=0;
        block6.blocky1=0;
        block6.blockx2=0;
        block6.blocky2=0;
        ball.score++;
    }else if(ball.tempY<=block7.blocky1&& ball.tempY>=block7.blocky1-30 && (ball.tempX<=block7.blockx1+80 && ball.tempX>=block7.blockx1-120)){
        ball.ball_y*=ball.f;
        ball.ball_x*=ball.f;
        block7.blockx1=0;
        block7.blocky1=0;
        block7.blockx2=0;
        block7.blocky2=0;
        ball.score++;
    }else if(ball.tempY<=block8.blocky1&& ball.tempY>=block8.blocky1-30 && (ball.tempX<=block8.blockx1+80 && ball.tempX>=block8.blockx1-120)){
        ball.ball_y*=ball.f;
        ball.ball_x*=ball.f;
        block8.blockx1=0;
        block8.blocky1=0;
        block8.blockx2=0;
        block8.blocky2=0;
        ball.score++;
    }else if(ball.tempY<=block9.blocky1&& ball.tempY>=block9.blocky1-30 && (ball.tempX<=block9.blockx1+80 && ball.tempX>=block9.blockx1-120)){
        ball.ball_y*=ball.f;
        ball.ball_x*=ball.f;
        block9.blockx1=0;
        block9.blocky1=0;
        block9.blockx2=0;
        block9.blocky2=0;
        ball.score++;
    }else if(ball.tempY<=block10.blocky1&& ball.tempY>=block10.blocky1-30 && (ball.tempX<=block10.blockx1+80 && ball.tempX>=block10.blockx1-120)){
        ball.ball_y*=ball.f;
        ball.ball_x*=ball.f;
        block10.blockx1=0;
        block10.blocky1=0;
        block10.blockx2=0;
        block10.blocky2=0;
        ball.score++;
    }


    if(ball.tempX>=589&& ball.tempY<760){
        ball.ball_x*=ball.f;
    }else if(ball.tempY<=5&&ball.tempY<500&&ball.tempX>0){
        ball.ball_y*=ball.f;
    }else if(ball.tempX<5&&ball.tempY<764&&ball.tempY>5){
        ball.ball_x*=ball.f;
    }else if(ball.tempY>=bar.bary && (ball.tempX<=bar.barx+100 && ball.tempX>=bar.barx-100)){
        ball.ball_y*=ball.f;
    }else if(ball.tempY>750&& ball.lives!= 0){
        ball.lives=0;

    }else{
        ball.tempX+ball.ball_x;
        ball.tempY+ball.ball_y;
    }
    ball.tempX+ball.ball_x;
    ball.tempY+ball.ball_y;




};

void barraRebote(){


}

void brick(){
    //int posi[][12]={};



    for (int i=0;i<8;i++) {
        for(int j=0; j<12;j++){ //504 630
            al_draw_rectangle(6+(50*j),50+(20*i),50+(50*j),60+(20*i),al_map_rgb(rand(),rand(),rand()),3);
           // resolv[i][j]+=posi[6+(50*j)][60+(20*i)];
        }
    }

}




/*
void printArray(char stringArray[][BUFFER], int stringCount){
int i;
for(i=0;i<stringCount;i++){
printf("%s ",stringArray[i]);
}
printf("\n");
}*/







#endif //PRUEBAS_JUEGO_H
