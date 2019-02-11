/* ====================================
 File name: exerc_2_6.c
 Date: 2019-02-07
 Group nr 1
 Members that contribute to the solutions
 Amjad Alshihabi
 Majd Dalain
 Mohammad Dergham
 Member not present at demonstration time:
 none
 Demonstration code: 18983
 ====================================== */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

void initQue (int list [], int max);
int input (int list [] , int number, int max);
int output( int list[], int max);
void print_array(int list[], int max);

int main(void){
    srand( time(NULL) );
    int queue[MAX];
    // initializing the array
    initQue(queue, MAX);
    // filling the array with random numbers
    for (int i = 0; i<MAX; i++){
        input(queue, rand() +1, MAX);
        print_array(queue, MAX);
    }
    // trying to add number to the array after it have been fully filled
    input(queue, rand() +1, MAX);
    // emptying the array
    for (int i = 0; i<MAX; i++){
        output(queue, MAX);
        print_array(queue, MAX);
    }
    // trying to empty the array when it is already emtpy
    printf("%d \n", output(queue, MAX));
}

void initQue (int list [], int max){
    for(int i = 0; i < max; i++){
        *(list + i) = -1;
    }
    print_array(list, max);
}

int input( int list[], int number, int max){
    for(int i = 0; i<max; i++){
        if(*(list+i) == -1){
            *(list+i)=number;
            // printf("the integer is entered to the array \n");
            return 1;
            break;
        }
    }
    return 0;
}

void print_array(int list[], int max){
    for(int i = 0; i<max; i++){
        printf("%d \t ", *(list+i));
    }
    printf("\n");
}

int output (int list[], int max){
    if (*(list) != -1){
        int number = *(list);
        for (int i = 0; i<max-1; i++){
            if (*(list+i+1) != -1){
                *(list+i) = *(list+i+1);
            }else{
                *(list + i) = -1;
                break;
            }
        }
        *(list + max-1) = -1;
        return number;
    }
    return 0;
}