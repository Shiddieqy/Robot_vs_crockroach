#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void forwards(int* xp,int* yp);
void backward(int* xp,int* yp);
void right(int* xp,int* yp);
void left(int* xp,int* yp);
void shoot(float range,int* HPc,int* ccount);
void cshoot(float range,int* HPp);
void spawnC(int* xc,int* yc);
float readrange(int xp,int yp,int xc, int yc);
void stopprogram(int *ccount);
void cmove(int* xc, int* xp, int* yc,int* yp, float range);

int main() {
    int xp = 0;
    int yp = 0;
    int xc,yc;
    float range;
    int HPp = 100;
    int HPc = 0;
    int inp;
    int ccount=0;

    while(HPp>=0){
        if (HPc == 0){
            spawnC(&xc,&yc);
            while (xc==xp && yp==yc){
                spawnC(&xc,&yc);
            }
            HPc=10;
            printf("\nNew Crockroach spawned");
        }

        range = readrange(xp,yp,xc,yc);
        printf("\nJarak dengan kecoak %.2f",range);
        printf("\nHP : %d",HPp);
        printf("\nposisi : (%d,%d)",xp,yp);
        printf("\nposisi kecoa : (%d,%d)",xc,yc);
        if(HPp==0){
            printf("\nKamu mati :((( \nJumlah kecoa yang terbunuh %d",ccount);
            break;
        }
        printf("\nPilih langkah : \n1 untuk maju\n2 untuk mundur\n3 untuk ke kanan\n4 untuk ke kiri\n5 untuk menembak\n6 untuk hentikan program\n");
        scanf("%d", &inp);
        if (inp==1){
            forwards(&xp,&yp);
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
        else if (inp == 6){
            stopprogram(&ccount);
            break;
        }
        cmove(&xc,&xp,&yc,&yp,readrange(xp,yp,xc,yc));
        cshoot(range,&HPp);
    }
    return 0;

}

void forwards(int* xp,int* yp){
    if (*yp==20){
        printf("\nCant move forward!!!!");
    }
    else{
    ++*yp ;
    }

}
void backward(int* xp,int* yp){
    if (*yp == 0){
        printf("\nCant move backward!!!");
    }
    else {
        --*yp;
    }

}
void right(int* xp,int* yp){
    if (*xp == 20){
        printf("\nCant move right!!!");
    }
    else {
        ++*xp;
    }
}
void left(int* xp,int* yp){
    if (*xp == 0){
        printf("\nCant move left!!!");
    }
    else {
        --*xp;
    }
}
void shoot(float range,int* HPc,int* ccount){
    if (range>10){
        printf("Cant shoot!!");
    }
    else {
        *HPc = 0;
        ++*ccount;
        printf("Cockroach shooted!");

    }

}
void cshoot(float range,int* HPp){
    if (range<15){
        *HPp-=5;
        printf("\nYou are shot");
        return;
    }
}

void spawnC(int* xc, int* yc){
    srand ( time(0) );
    *xc = rand()%20;
    *yc = rand()%20;
}

float readrange(int xp,int yp,int xc, int yc){
    int x = xp-xc;
    int y = yp-yc;
    return sqrt(x*x + y*y);
}

void stopprogram (int* ccount){
    printf("\n Program has been stopped\n Cockroach killed : (%d)",ccount);
}

void cmove(int* xc, int* xp, int* yc,int* yp, float range){
    if (range > 15){
        if (abs(*xc-*xp)>abs(*yc-*yp)){
            if (*xc-*xp>0){
                --*xc;
            }else{
                ++*xc;
            }
        }else {
            if (*yc-*yp>0){
                --*yc;
            }else{
                ++*yc;
            }
        }
    }
}
