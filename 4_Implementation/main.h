

/* 
 * File:   main.h
 * Author: ARCHANA RAVINDRA
 *
 * Created on 9 April, 2021, 9:09 PM
 */


#ifndef MAIN_H
#define MAIN_H

#define EQUAL   0

/* The choices for player and computer */

#define   PAPER   0
#define   ROCK    1
#define   SCISSOR 2
#define   QUIT    3

/* Game results */

#define   COMPUTER_WON  4
#define   PLAYER_WON    5
#define   DRAW          6

/* design by contract for poor C programmers */

#define   REQUIRE(cnd)  assert(cnd);
#define   ENSURE(cnd)   assert(cnd);

typedef struct
{
  int player;
  int computer;
  int result;
}GameResult;

/* lookup table for all possible outcomes */

static const GameResult results[] =
{
  {PAPER, PAPER, DRAW},
  {PAPER, ROCK, PLAYER_WON},
  {PAPER, SCISSOR, COMPUTER_WON},

  {ROCK, ROCK, DRAW},
  {ROCK, SCISSOR, PLAYER_WON},
  {ROCK, PAPER, COMPUTER_WON},

  {SCISSOR, SCISSOR, DRAW},
  {SCISSOR, PAPER, PLAYER_WON},
  {SCISSOR, ROCK, COMPUTER_WON},
};

#define NUM_RESULTS   sizeof(results) / sizeof(results[0])

/* Function prototypes */

int get_player_choice();
int get_computer_choice();
int get_result(int player, int computer);
void show_result(int player, int comp, int result);

#endif