 /* ====================================
 File name: exerc_2_5.c
 Date: 2019-02-07
 Group nr 1
 Members that contribute to the solutions
 Amjad Alshihabi
 Majd Dalain
 Mohammad Dergham
 Member not present at demonstration time:
 none
 Demonstration code: 10156
 ====================================== */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
#define MAXNUMBER 20
// ------Function declaration   ----------
void create_random( int *tab);// Use pointer to fill the table
void count_frequency(int *tab, int *freq);// Use pointer
void draw_histogram(int *freq);//  Use pointer
int main (void){
    int table[MAX], n;
    int frequency[MAXNUMBER+1];
    srand( time(NULL) );
    // generating randon numbers and filling them in the array using pointers.
        create_random(table);    
    // counting the frequency of numbers in the array
        count_frequency(table, frequency);
    // draw histogram
        draw_histogram(frequency);
}

void create_random(int *tab){
    for(int n = 0; n<MAX; n++){
        *(tab+n) = rand()%(MAXNUMBER + 1);
    }
}

void count_frequency(int *tab, int *freq){
    for(int i = 0; i<MAX; i++){
        *(freq + *(tab+i)) = *(freq + *(tab+i)) + 1;
    }
}

void draw_histogram(int *freq){
    for(int i = 0; i<MAXNUMBER+1; i++){
        if(*(freq+i) != '\0'){
        printf("%d \t\t", i );
            for(int j=0; j<*(freq+i); j++){
                printf("x");
            }
        printf("\n");
        }
    }
}

// The program keeps printing 'x' to the terminal for some values of MAX, we could not figure out the reason.