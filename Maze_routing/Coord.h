//
//  Coord.h
//  Maze_routing
//
//  Created by 許佑任 on 2015/7/27.
//  Copyright (c) 2015年 許佑任. All rights reserved.
//

#ifndef __Maze_routing__Coord__
#define __Maze_routing__Coord__

#include <stdio.h>

struct Coord {
public:
  int X;
  int Y;

  Coord(int x, int y) {
    this->X = x;
    this->Y = y;
  }
};

#endif /* defined(__Maze_routing__Coord__) */
