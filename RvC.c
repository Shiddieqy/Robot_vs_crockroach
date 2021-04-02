//Robot Vs Crockroach
//program dari sebuah robot yang ditugaskan untuk membasmi kecoak mutan

//import library
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//deklarasi fungsi
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
    //deklarasi variabel
    int xp = 0;
    int yp = 0;
    int xc,yc;
    float range;
    int HPp = 100;
    int HPc = 0;
    int inp;
    int ccount=0;

    //loop utama
    while(HPp>=0){

        //mengecek apakah kecoak sudah mati atau masih ada di arena
        if (HPc == 0){
            //jika mati akan dimunculkan kecoak baru
            spawnC(&xc,&yc);
            //lokasi kecoak tidak boleh sama dengan lokasi robot
            while (xc==xp && yp==yc){
                spawnC(&xc,&yc);
            }

            //mengatur Hit Point dari kecoak
            HPc=10;
            printf("\nNew Crockroach spawned");
        }

        //membaca jarak dengan kecoak dan menampilkan informasi jarak, HP, dan posisi.
        range = readrange(xp,yp,xc,yc);
        printf("\nJarak dengan kecoak %.2f",range);
        printf("\nHP : %d",HPp);
        printf("\nposisi : (%d,%d)",xp,yp);
        printf("\nposisi kecoa : (%d,%d)",xc,yc);

        //Program berhenti jika robot mati
        if(HPp==0){
            printf("\nKamu mati :((( \nJumlah kecoa yang terbunuh %d",ccount);
            break;
        }

        //Menampikan instruksi untuk input
        printf("\nPilih langkah : \n1 untuk maju\n2 untuk mundur\n3 untuk ke kanan\n4 untuk ke kiri\n5 untuk menembak\n6 untuk hentikan program\n");
        scanf("%d", &inp);

        //Menjaankan prosedur sesuai input yang diterima
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

        //Kecoak akan bergerak dan menembak tiap loop berjalan
        cmove(&xc,&xp,&yc,&yp,readrange(xp,yp,xc,yc));
        cshoot(range,&HPp);
    }
    return 0;

}

//Fungsi untuk maju, karena area dibatasi hanya 20 x 20. Robot tidak bisa maju lagi ketika yp=20
void forwards(int* xp,int* yp){
    if (*yp==20){
        printf("\nCant move forward!!!!");
    }
    else{
    ++*yp ;
    }

}

//Fungsi untuk mundur, karena area dibatasi hanya 20 x 20. Robot tidak bisa mundur lagi ketika yp=0
void backward(int* xp,int* yp){
    if (*yp == 0){
        printf("\nCant move backward!!!");
    }
    else {
        --*yp;
    }

}

//Fungsi untuk ke kanan,karena area dibatasi hanya 20 x 20. Robot tidak ke kanan lagi ketika xp=20
void right(int* xp,int* yp){
    if (*xp == 20){
        printf("\nCant move right!!!");
    }
    else {
        ++*xp;
    }
}

//Fungsi untuk ke kiri,karena area dibatasi hanya 20 x 20. Robot tidak ke kiri lagi ketika xp=0
void left(int* xp,int* yp){
    if (*xp == 0){
        printf("\nCant move left!!!");
    }
    else {
        --*xp;
    }
}

//Fungsi untuk menembak
void shoot(float range,int* HPc,int* ccount){
    //Hanya bisa menembak jika kecoak dalam jangkauan
    if (range>10){
        printf("Cant shoot!!");
    }
    //Jika dalam jangkauan, kecoak akan tertembak dan langsung mati
    else {
        *HPc = 0;
        ++*ccount;
        printf("Cockroach shooted!");

    }

}

//Fungsi menembak untuk kecoak
void cshoot(float range,int* HPp){
    //kecoak menembak hanya ketika dalam jangkauan
    if (range<15){
        *HPp-=5;
        printf("\nYou are shot");
        return;
    }
}

//Fungsi untuk memunculkan kecoak
void spawnC(int* xc, int* yc){
    //Perlu dilakukan refresh seed agar selalu didapat angka random baru
    /*rand adalah fungsi untuk memanggil integer secara acak, agar 
    didapat integer dalam range 0-20 dilakukan operasi modulus terhadap 20*/
    srand ( time(0) );
    *xc = rand()%20;
    *yc = rand()%20;
}

//Fungsi untuk membaca jarak antara player (robot) dengan kecoak
float readrange(int xp,int yp,int xc, int yc){
    int x = xp-xc;
    int y = yp-yc;
    return sqrt(x*x + y*y);
}

//Fungsi ketika user memilih menghentikan program
//Akan dimunculkan jumlah kecoak yang terbunuh
void stopprogram (int* ccount){
    printf("\n Program has been stopped\n Cockroach killed : (%d)",ccount);
}

//Fungsi bergerak untuk kecoak
//Kecoak akan berusaha mendekati robot ketika robot berada di luar jangkauannya
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
