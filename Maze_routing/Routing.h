//
//  Routing.h
//  Maze_routing
//
//  Created by 許佑任 on 2015/7/28.
//  Copyright (c) 2015年 許佑任. All rights reserved.
//

#ifndef __Maze_routing__Routing__
#define __Maze_routing__Routing__

#include <stdio.h>
#include <vector>
#include "Maze.h"


class Routing {
public:
  Maze *maze_ptr;
  bool routing_success = false;
  std::vector<Coord> route_path;

  /**
   * Set maze_ptr point to maze,
   * Reset routing_success, routh_path
   */
  Routing & select_maze();

  /* In the selected maze, get and return the starting grid */
  Coord get_start_grid();

  /*
   * Recursive function
   * traverses the maze from the starting grid toward the ending grid
   */
  bool route(Coord curCoord);

  ~Routing();


  bool doTop(Coord curCoord);
  bool doBootom(Coord curCoord);
  bool doLeft(Coord curCoord);
  bool doRight(Coord curCoord);

private:
  bool search(Coord curCoord);
};

#endif /* defined(__Maze_routing__Routing__) */
