//
//  Maze.h
//  Maze_routing
//
//  Created by 許佑任 on 2015/7/27.
//  Copyright (c) 2015年 許佑任. All rights reserved.
//

#ifndef __Maze_routing__Maze__
#define __Maze_routing__Maze__

#include <stdio.h>
#include "Coord.h"
#include <string>
#include <iostream>

using std::cin;

class Maze {
public:
  // constructor
  Maze();

  // destructor
  ~Maze();

  const int MAZE_SIZE_X = 5;
  const int MAZE_SIZE_Y = 5;

  void input();
  bool check_h_barrier();
  bool check_v_barrier();
  Coord * get_start_coord();
  Coord * get_end_coord();

private:
  bool ** v_barrier;
  bool ** h_barrier;
  Coord * start_coord;
  Coord * end_coord;

  struct Case {
    bool v_barrier[8][7] = {
      {1, 1, 1, 1, 1, 1, 1},
      {0, 1, 1, 1, 1, 1, 0},
      {0, 0, 0, 0, 1, 0, 1},
      {0, 0, 1, 1, 0, 1, 1},
      {0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 1, 0, 0, 0},
      {0, 1, 0, 1, 1, 1, 0},
      {1, 1, 1, 1, 1, 1, 1}
    };
    bool h_barrier[7][8] = {
      {1, 0, 0, 0, 0, 0, 0, 1},
      {1, 1, 0, 1, 0, 0, 1, 1},
      {1, 1, 1, 1, 0, 1, 0, 1},
      {1, 1, 0, 1, 1, 0, 1, 1},
      {1, 1, 1, 1, 0, 1, 1, 1},
      {1, 1, 1, 0, 0, 0, 1, 1},
      {1, 0, 1, 1, 0, 0, 0, 1}
    };
  } _case;

};

#endif /* defined(__Maze_routing__Maze__) */
