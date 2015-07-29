//
//  Routing.cpp
//  Maze_routing
//
//  Created by 許佑任 on 2015/7/28.
//  Copyright (c) 2015年 許佑任. All rights reserved.
//

#include "Routing.h"

Routing & Routing::select_maze() {
  this->maze_ptr = new Maze;
  this->routing_success= false;
  route_path.clear();
  return *this;
}

bool isReachEndGrid(Coord curCoord, Maze & maze_ptr) {
  Coord endCoord = *maze_ptr.get_end_coord();
  if (curCoord.X == endCoord.X && curCoord.Y == endCoord.Y) return true;
  return false;
}

Coord Routing::get_start_grid() {
  return *maze_ptr->get_start_coord();
}

bool Routing::doTop(Coord curCoord) {
  Coord top = Coord(curCoord.X, curCoord.Y - 1);
  bool isTop = maze_ptr->check_h_barrier(curCoord, Maze::HorizontalBarrier::Top);
  if (isTop) return route(top);
  return false;
}

bool Routing::doBootom(Coord curCoord) {
  Coord bottom = Coord(curCoord.X, curCoord.Y + 1);
  bool isBottom = maze_ptr->check_h_barrier(curCoord, Maze::HorizontalBarrier::Bottom);
  if (isBottom) return route(bottom);
  return false;
}

bool Routing::doRight(Coord curCoord) {
  Coord right  = Coord(curCoord.X + 1, curCoord.Y);
  bool isRight = maze_ptr->check_v_barrier(curCoord, Maze::VerticalBarrier::Right);
  if (isRight) return route(right);
  return false;
}

bool Routing::doLeft(Coord curCoord) {
  Coord left = Coord(curCoord.X - 1, curCoord.Y);
  bool isLeft = maze_ptr->check_v_barrier(curCoord, Maze::VerticalBarrier::Left);
  if (isLeft) return route(left);
  return false;
}

bool Routing::route(Coord curCoord) {
  route_path.push_back(curCoord);
  
  if (isReachEndGrid(curCoord, *maze_ptr)) {
    this->routing_success = true;
    for (int i = 0; i < route_path.size(); i++) {
      Coord c = route_path[i];
      fprintf(stdout, "%d %d \n", c.X, c.Y);
    }
    return true;
  }

  if (doLeft(curCoord) || doBootom(curCoord) || doTop(curCoord) || doRight(curCoord)) {}
  else {
    route_path.pop_back();
  }

//    if (doRight(curCoord) || doTop(curCoord) || doLeft(curCoord) || doBootom(curCoord)) {}
//    else {
//      route_path.pop_back();
//    }

  return false;
}

Routing::~Routing() {
  fprintf(stdout, "Routing is deconstructor\n");
  delete this->maze_ptr;
}


