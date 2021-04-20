#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 20


/*
 *  ROMAN OSADSKÝ
 *
 *  SEMESTRÁLNY PROJEKT
 *
 *  TSP PROBLÉM
 *
 */


// ----------------------- FUNKCIA NA VYMENU ČÍSEL PRI GENEROVANÍ KOMBINÁCIÍ MIEST  --------------------//


void swap(char *x, char *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int cesta = 999;

// ---- HLAVNÁ REKURZÍVNA FUNKCIA NA VYTVÁRANIE PERMUTÁCIA + V NEJ RIEŠIME TSP PRACUJEME S MESTAMI
//
// ---- NAJPRV FUNKCIA PERMUTE V VYGENERUJE POČET ČÍSEL, A POTOM VYSKÚŠAME AKO DLHO NÁM ZABERIE CESTA
//
// ---- NESKÔR ZAPISUJEME NAJMENŠIE HODNOTY, A NA KONCI PROGRAMU SA HODNOTY VYPÍŠU



int permute(int *a, int l, int r,int pocet,int mesta[N][N]) {

    int sucet = 0;


    if(a[0]!=0) // ABY SME ZAČÍNALI IBA OD MESTA 0
        return 0;


    int i = 0;
    if (l == r) {

        int x = 0;

        // ---------- PRACUJEME S MESTAMI POSÚVAME SA V POLI A SPOČÍTAVAME SÚČET -----------//
        for (int j = 0; j < pocet ; j++) {
            sucet+=mesta[x][a[j]]; //spočítavame súčet
            x = a[j];

        }

        sucet+=mesta[x][0]; //vraciame sa naspať do prvého mesta

        if(sucet<cesta)
            cesta = sucet; // najnižšiu hodnotu zapisujume

    }
    //tu swapujeme hodnoty aby sme vyskúšali kombinácie, voláme funkciu znova takže je rekurzívna
    else{
        for (i = l; i <= r; i++){
            swap((a+l), (a+i));
            permute(a, l+1, r,pocet,mesta);
            swap((a+l), (a+i));
        }
    }


}

int main(){
    int pocet;
    int polecisel[N];
    int indexs = 0;
    int str[N];
    int mesta[N][N];

    while (scanf("%d",&pocet)==1) {

        //načítanie miest
        for (int i = 0; i < pocet; i++) {
            for (int j = 0; j < pocet; j++)
                scanf("%d", &mesta[i][j]);
        }

        //výpis miest
        for (int i = 0; i < pocet; i++) {
            printf("\n");

            for (int j = 0; j < pocet; j++)
                printf("%d ", mesta[i][j]);
        }

        printf("\n");

        //vypočítanie n! číže hodnoty od nuly po naše zadane číslo
        for (int i = pocet; i > 0; i--) {
            polecisel[indexs] = pocet - i;
            indexs++;
        }

        printf("\n");

        //zapisujem ho do stringu to pole čísel čo som vytvoril vyšie
        for (int j = 0; j < pocet; j++)
            str[j] = (polecisel[j]);

        str[pocet] = 0;

        //printf("%s\n",str);

        int n = pocet;

        permute(str, 0, n - 1, pocet, mesta);

        printf("%d\n", cesta); //výpis výsledku
        indexs = 0; //reset hodnôt
        cesta = 999;
    }
}