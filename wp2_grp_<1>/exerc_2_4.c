


/*====================================
File name: exerc_2_4.c (or cpp)
Date: 2019-02-07
Group nr 1
Members that contributeto the solutions
Mohammad dergham
Amjad Alshihabi
Majed Dalain
Member not present at demonstration time:
none
Demonstration code: 14245
======================================*/

#include <stdio.h> 

#include <string.h> 

void isPalindrome(char str[]) 
{ 
    // Start from leftmost and rightmost corners of str 
    int l = 0; 
    int h = strlen(str) - 1; 
  
    // Keep comparing characters while they are same 
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
            printf("\n %s is Not Palindrome\n", str); 
            return; 
        } 
    } 
    printf("\n %s is palindrome \n ", str); 
} 


int main() 
{ 

   char *text ;
   printf("enter a string \n ");
   scanf("%s" , text);
    isPalindrome(text); 

       
    return 0; 
}