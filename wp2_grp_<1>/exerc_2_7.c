/*====================================
File name: exerc_2_7.c (or cpp)
Date: 2019-02-07
Group nr 1
Members that contributeto the solutions
Majed Dalain
Amjad Alshihabi
Mohammad dergham
Member not present at demonstration time:
Demonstration code: [15479 ]
======================================*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int getPersonr (char persnr[]);

/*
calculate and check the control digit value, return 1 for true and 0 for flase.
*/

  int controlDigit(const char *pNumber) {
    int nSum       = 0;
    int nDigits    = strlen(pNumber);
    int nParity    = (nDigits-1) % 2;
    char cDigit[2] = "\0";
    for (int i = nDigits; i > 0 ; i--)  {
      cDigit[0]  = pNumber[i-1];
      int nDigit = atoi(cDigit);

      if (nParity == i % 2)
        nDigit = nDigit * 2;

      nSum += nDigit/10;
      nSum += nDigit%10;
    }

    if (nSum % 10 == 0){
        return 1;
    } else {
          return 0;
    }
  }

/*
 check the format of the entered personal number, and calls the controlDigit to check the validation of last digit.

*/
  int readPersnr (char *person){

    char year[3], month[3], day[3];
    int yearint, monthint, dayint, valid = 1;

    memcpy(year, &person[0],2);
    memcpy(month, &person[2], 2);
    memcpy(day, &person[4], 2);

    yearint  = atoi(year);
    monthint = atoi(month);
    dayint   = atoi(day);

    if ((yearint > 99 || yearint<10) || (monthint > 12 || monthint < 1) || (dayint >31 || dayint < 1)) {
          valid = 0;
    }
    if(controlDigit(person) != 1){
      valid = 0;
    }
    return valid;
  }


/*
main program, A to enter perosnal number and  Q to Quit.
*/

int main(int argc, char const *argv[]) {

  char persnr[11];
  char menu;

   do {
          printf("MAIN MENU\n");
          printf("[A] Check A Personal Number\n");
          printf("[Q] End program\n");

          scanf (" %c", &menu);

          if (menu != 'Q')  {

             switch(menu) {
                 case 'A':
                   getPersonr(persnr);
                   break;

                 default:
                   printf("wrong character. Print menu again\n\n");
                   break;
             }
          }
       } while(menu != 'Q');

  return 0;
}


int getPersonr (char persnr[] ){
  int len, year, valid = 0;
    printf("Enter a Valid Personal Number of 10 Numbers! \n" );

    if(fgets(persnr,11,stdin)){
      len = strlen(persnr);
      valid = readPersnr(persnr);

      while (len != 10 || valid!=1) {

        printf("Enter A valid number !  \n" );
        fgets(persnr,11,stdin);
        len = strlen(persnr);
        valid = readPersnr(persnr);
      }
    }

    printf("In PROGRESS....... \n");
    printf("%s %s \n", persnr, "is Correct ");

    return 0;
  }
// 15479 //
