/*====================================
File name: exerc_2_8.c (or cpp)
Date: 2019-02-07
Group nr 1
Members that contributeto the solutions
Majed Dalain
Amjad Alshihabi
Mohammad dergham
Member not present at demonstration time:
Demonstration code: [11932]
======================================*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>


#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;

/* ------------- IO --------------- */

/*
 * human_choice
 * Get human choce as an int from stdin.
 * Clears stdin.
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int human_choice(int pile);

/*
 * write_winner
 * Write winner as a string on stdout.
 * in: Values HUMAN or COMPUTER.
 * out:
 */
void write_winner( int player );

/*
 * play_again
 * Ask human if he/she wants to play
 * another round. If 'n' or 'N' selected
 * (single char) return false else true.
 * Clears stdin.
 * in:
 * out: true or false
 */
int play_again();

/* ---------------- Logic ----------------*/

/*
 * computer_choice
 * Get computers choice (including some AI,
 * if 4 coins or less left, function makes a
 * smart choice else random).
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int computer_choice(int pile);

/*
 * toggle
 * Switches player, if HUMAN in COMPUTER out
 * etc.
 * in:  actual player
 * out: next player
 */
int toggle( int player );

/* --------------------- Utilities -------------*/
void clear_stdin();

/***************************************************
 *
 *    MAIN
 *
 ***************************************************/
int main()
{
  int pile,			/* This is how many coins we have */
    player,
    playAgain,			/* Who is playing? */
    n_coins;			/* Number of coins taken */

  srand( time(0) );		/* Setup random */

  printf("V�lkommen till NIM by ...");



  pile = MAX_COINS;		/* Set start values (= init) */
  player = HUMAN;
  playAgain = 0;

  /*
   *  Program main loop
   */
  while( true ) {

    printf("Det ligger %d  mynt i h�gen\n", pile );

    if( player == HUMAN ){
      n_coins = human_choice(pile);
    }else{
      n_coins = computer_choice(pile);
      printf("- Jag tog %d\n", n_coins);
    }
    pile -= n_coins;
    player = toggle( player );

    if( pile <= 1 ){
      write_winner( player );
      printf("Avslutat\n");
      playAgain = play_again();

      if(playAgain == 1){
        break;
      }
      else {
        pile = MAX_COINS;
        player = HUMAN;
      }

    }

  }
  /*
   * end main loop
   */
  return 0;
}

/******************************************************
 *
 *  DEFINITIONS
 *
 ******************************************************/


void clear_stdin()
{
  int ch;
  while((ch = getchar()) != '\n' && ch != EOF  ) {
    ;
  }
}

int human_choice(int pile) {
  int value;
  printf("Enter a value between 1-3\n");
  scanf("%d",&value );
  while(value > 3 || value < 1){
    printf("Enter value between 1 - 3 only !!\n" );
    scanf("%d",&value );
  }
  clear_stdin();
  printf("%s %d\n","the value User entered is",value );
  return value;
}


int computer_choice(int pile)
{
  srand( time(0) );

  if(pile <= 4 && pile >1){
    return (pile-1);
  }
  else if ( pile == 1){
    return pile;
  }
  else {
    int random = (rand() % 3) + 1;
    printf("%s %d\n","the rando is ", random );
    return random;
  }
}

void write_winner(int player ) {
  if(player == HUMAN){
    printf("Computer is the Winner!\n" );
  } else {
    printf("Human is the Winner!\n" );
  }
}

int play_again(){
  char ch;
  printf("Press n or N to Quit or any other Key to play Again!!\n" );
  scanf("%1s",&ch);
  // ch = tolower(ch)
  if(ch == 'n'){
    return 1;
  }
  else {
    return 0;
  }

}

int toggle( int player ) {
  if(player == HUMAN){
    player = COMPUTER;
  }
  else {
    player = HUMAN;
  }
  return player;
}
// 11932//
