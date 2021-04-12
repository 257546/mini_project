/**
 * @file main.c
 * @author ARCHANA R BAILKERI
 * @brief c program to recreate the well-known hand game ROCK-PAPER-SCISSORS
 * @version 0.1
 * @date 2021-04-11
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include "main.h"
/**
 * @brief main function which includes the call arguement for the entire game
 * 
 * @return int 
 */
int main(void)
{
  int player, comp, result;

  srand((unsigned)time(NULL));
  for(;;)
  {
    player = get_player_choice();
    if (player == QUIT)
      return 0;
    comp = get_computer_choice();
    result = get_result(player, comp);
    show_result(player, comp, result);
  }
  return 0;
}
/**
 * @brief Get the player choice object: one of the multifile which gets the players choice i.e ROCK PAPER OR SCISSOR
 * 
 * @return int 
 */
int get_player_choice()
{
  char buffer[8];
  char *pos;

  for(;;)
  {
    printf("\nPlease choose rock, paper, scissor or quit: ");
    fgets(buffer,sizeof(buffer), stdin); 
    
    pos = strrchr(buffer, '\n');
    if (pos != NULL)
      *pos = '\0'; // remove trailing \n

    if (strcmp(buffer, "rock") == EQUAL)
      return ROCK;
    else if (strcmp(buffer, "scissor") == EQUAL)
      return SCISSOR;
    else if (strcmp(buffer, "paper") == EQUAL)
      return PAPER;
    else if (strcmp(buffer, "quit") == EQUAL)
      return QUIT;
  }
  return 0;
}
/**
 * @brief Get the computer choice object: the sub function which decided the computer choice 
 * 
 * @return int 
 */
int get_computer_choice()
{
  return rand() % 3;
}
/**
 * @brief Get the result object: the sub function which decides the winner of the match by comparing the player's choice and the computer's choice
 * 
 * @param player 
 * @param computer 
 * @return int 
 */
int get_result(int player, int computer)
{
  int idx;

  REQUIRE(player >= 0 && player <= 2);
  REQUIRE(computer >= 0 && computer <= 2);

  for (idx = 0; idx < NUM_RESULTS; ++idx)
  {
    if (results[idx].player == player && results[idx].computer == computer)
      break;
  }
  ENSURE(idx >= 0 && idx < NUM_RESULTS);

  return results[idx].result;
}
/**
 * @brief a function which displays the result of the match
 * 
 * @param player 
 * @param comp 
 * @param result 
 */
void show_result(int player, int comp, int result)
{
  const char *result_names[] = {"Computer won", "Player won", "Draw"}; 
  const char *choises[] = {"Paper", "Rock", "Scissor"};

  REQUIRE(result >= COMPUTER_WON && result <= DRAW);
  REQUIRE(player >= PAPER && player <= SCISSOR);
  REQUIRE(comp >= PAPER && comp <= SCISSOR);

  printf("\nYou chose: %s", choises[player]);
  printf("\nComputer choose: %s", choises[comp]);
  printf("\nResult: %s", result_names[result - 4]);
}
