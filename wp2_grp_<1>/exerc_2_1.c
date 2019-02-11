

/*====================================
File name: exerc_2_1.c
Date: 2019-02-07
Group nr 1
Members that contributeto the solutions
mohammad dergham
Amjad Alshihabi
Majed Dalain
Member not present at demonstration time:
none
Demonstration code: 19009 
======================================*/


#include <stdio.h>
#include<string.h>
#include <ctype.h>
 #include <math.h>
 
void copy_string(char [], char []);
 
int main() {
  char first[20], second[20]=" nice veiw  ";
  char myStr[20];
  char myStr2[20]= " cool tree  ";
  
   
  printf("Input a string\n");
  fgets(first, sizeof first, stdin);
  printf("Input one more string\n");
  fgets(myStr, sizeof first, stdin);
  printf("the string number 2 is  %s \n", myStr2 );
   strcpy(myStr2,myStr );
  //sputs(first);
  
  
printf("string 1 icopied with the built in function is  %s \n ", myStr);
printf("string 2 became %s  after using the built in function  \n ", myStr2);
printf("the string number 3 you stored it with is %s \n", first);
printf("the string number 4 is  %s \n", second );
  copy_string(second, first);
printf("The string variable  number 4 became : %s after manual copying  \n", second);
 
  return 0;
}
 
void copy_string(char second[], char first[]) {
  int c = 0;
   
  while (first[c] != '\0') {
    second[c] = first[c];
    c++;
  }
  second[c] = '\0';
}


