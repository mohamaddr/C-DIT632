/*====================================
File name: exerc_2_2.c (or cpp)
Date: 2019-02-07
Group nr 1
Members that contributeto the solutions
Majed Dalain
Amjad Alshihabi
Mohammad dergham
Member not present at demonstration time:
Demonstration code: [10954]
======================================*/

#include <stdio.h>
#include <stdlib.h>
#include  <time.h>
int main (){

 srand(time(NULL));
 int myInts[10];
 int i ;
  double *p;

int size= sizeof(myInts)/ sizeof(myInts[0]);
 for (i=0; i < size; i++){

     myInts[i] = rand() % 99+1;

 }



printf(" the array is at address %p \n", &myInts);
printf(" the first integer in the array is : %d  \n ",  myInts[0]);
printf("  the size of the array is %d  \n " , size);
printf("The size of an integer (size of the memory ):%lu \n",sizeof(int));
 printf( "Array values using pointer \n");



   for(i = 0; i < size; ++i){
   printf("%i \n ", *(myInts + i));


}

  printf("Array values times two \n");
   for(i = 0; i < size; ++i){
  printf("%i\n", *(myInts + i)*(2));

}

 //system("PAUSEE");




    return 0;

}

// 10954//
