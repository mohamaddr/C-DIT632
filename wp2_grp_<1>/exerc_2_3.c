

/*====================================
File name: exerc_2_3.c 
Date: 2019-02-07
Group nr 1
Members that contributeto the solutions
Mohammad dergham
Majed Dalain
Amjad Alshihabi
Member not present at demonstration time:
none
Demonstration code: 16567
======================================*/


#include<stdio.h>
#include<string.h>



// to  add arguments to the command line run >> ./runem string1 string2

int compare_s(char *first, char *second) {
   while (*first == *second) {
      if (*first == '\0' || *second == '\0')
         break;
         
      first++;
      second++;
   }
 
   if (*first == '\0' && *second == '\0')
      return 0;
   else
      return -1;
}


int comparisonType (char *first, char *second){
int result ;
printf("please choose comparison method :\n");
printf("a.strcmp (library method).\n");
printf("b.compare_s (without the library method).\n");
char typ;
 scanf("%c" , &typ);
 if(typ=='a'){
 result=strcmp(first, second);
 return result;
 }else if (typ=='b'){
   result= compare_s(first,second);
   return result;
 }


return -3;

 }




  
int main(int argc,char* argv[]) 
{ 
 
    int result ;
    int counter; 

  

    if(argc==1) {
        printf("\nNo Extra Command Line Argument Passed Other Than Program Name\n");
        return 0;
    }
    if(argc==2 || argc>3 ){  
        printf("please input 2 string to compare \n");
        
    }
    if(argc==3) 
    {
        
          result = comparisonType(argv[1], argv[2]);
        if(result==0){
           
        printf("\n----Following Are The Command Line Arguments Passecd and the strings are equal----"); 
        for(counter=1;counter<argc;counter++) 
            printf("\n  %s ",argv[counter]); 
       }else if (result==-3){printf(" plese enter the right option (a or b)\n");}

    else
     printf("\nstrings are not equal \n"); 
    }
  
     
    return 0; 
} 

