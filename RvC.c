#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void forward(int* xp,int* yp);
void backward(int* xp,int* yp);
void right(int* xp,int* yp);
void left(int* xp,int* yp);
void shoot(float range,int* HPc,int* ccount);
void cshoot(float range,int* HPp);
void spawnC(int* xc,int* yc);
float readrange(int xp,int yp,int xc, int yc);

int main() {
    int xp = 0;
    int yp = 0;
    int xc=1;
    int yc=1;
    float range;
    int HPp = 100;
    int HPc = 0;
    int inp;
    int ccount=0;

while(HPp>=0){
    if (HPc == 0){
        spawnC(&xc,&yc);
        while (xc==xp || yp==yc){
            spawnC(&xc,&yc);
        }
        HPc=10;
        printf("\nNew Crockroach spawned");
    }

    range = readrange(xp,yp,xc,yc);
    printf("\nJarak dengan kecoak %.2f",range);
    printf("\nHP : %d",HPp);
    printf("\nposisi : (%d,%d)",xp,yp);
    if(HPp==0){
        printf("\nKamu mati :((( \nJumlah kecoa yang terbunuh %d",ccount);
        break;
    }
    printf("\nPilih langkah : \n1 untuk maju\n2 untuk mundur\n3 untuk ke kanan\n4 untuk ke kiri\n5 untuk menembak\n");
    scanf("%d", &inp);
    if (inp==1){
        forward(&xp,&yp);
    }
    else if (inp==2){
        backward(&xp,&yp);
    }
    else if (inp==3){
        right(&xp,&yp);
    }
    else if (inp==4){
        left(&xp,&yp);
    }
    else if (inp==5){
        shoot(range,&HPc,&ccount);
    }
    cshoot(range,&HPp);
}
return 0;

}

void forward(int* xp,int* yp){
    if (*yp==20){
        printf("\nCant move forward!!!!");
    }
    else{
    *yp = *yp+1 ;
    }

}
void backward(int* xp,int* yp){
    if (*yp == 0){
        printf("\nCant move backward!!!");
    }
    else {
        *yp = *yp-1 ;
    }

}
void right(int* xp,int* yp){
    if (*xp == 20){
        printf("\nCant move right!!!");
    }
    else {
        *xp = *xp+1 ;
    }
}
void left(int* xp,int* yp){
    if (*xp == 0){
        printf("\nCant move left!!!");
    }
    else {
        *xp = *xp-1 ;
    }
}
void shoot(float range,int* HPc,int* ccount){
    if (range>10){
        printf("Cant shoot!!");
    }
    else {
        *HPc = 0;
        *ccount = *ccount +1;
        printf("Crockroach shooted!");

    }

}
void cshoot(float range,int* HPp){
    if (range<15){
        *HPp = *HPp-5;
    }
}

void spawnC(int* xc, int* yc){
    srand ( time(NULL) );
    *xc = rand()%20;
    *yc = rand()%20;
}

float readrange(int xp,int yp,int xc, int yc){
    int x = xp-xc;
    int y = yp-yc;
    return sqrt(x*x + y*y);
}