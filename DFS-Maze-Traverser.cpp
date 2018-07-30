/*------------------------------------------*/
/*               Maze1.cpp                  */
/*                                          */
/*  Author: Zwe Phone Shein                 */
/*                                          */
/*  Date: 03/11/2016                        */
/*==========================================*/


#include "Maze1.h"
#include <iostream>
#include <cassert>

using namespace std;

Maze1::~Maze1()
{
  delete [] M; // deallocates the state array.
}

void Maze1::find_exit()
// Use the DFS method to fill the path stack with the exit path Positions
// If there is no path to the exit, then after execution of this function
// the stack path should be empty
// This function does no input and no output
{
  Position nbr, current;
  direction d;

  // Set starting position as VISITED.
  M[start.row][start.col] = VISITED;

  // Set the starting position the current position
  current = start;

  // Start by checking downwards
  d = DOWN;

  // Set current's neighbor in order to check validity
  nbr = current.Neighbor(d);

  // Done if exit is in starting position
  if (current == exitpos)
  {
    path.push(current); // Push the position onto the stack
    return;
  }

  // Starts the search process
  while (1)
  {
    // Moves to the position if it is open and valid.
    if (validPosition(nbr) && (M[nbr.row][nbr.col]) == OPEN)
    {
      path.push(current);
          
      current = nbr;
      M[current.row][current.col] = VISITED; // Mark the position visited.

      // If the exit is found, return.
      if (current == exitpos)
      {
        path.push(current);
        return;
      }
      
      // Restart searching downwards.    
      d = DOWN;
      nbr = current.Neighbor(d);
      continue;

      }

      // Change direction if the current direction is not valid and open.
      d = next_direction(d);
      nbr = current.Neighbor(d);

      // If no neighbors found, pop the stack and return to previous position.
      if (d == NONE)
      {
          // If no exit is found, then return
          if (current == start)
              return;

          // Pop the stack and set current position to previous position
          d = DOWN;
          current = path.top();
          path.pop();
          nbr = current.Neighbor(d);
            
      }
  }
}







