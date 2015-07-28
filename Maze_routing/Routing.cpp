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
  Coord *endCoord = maze_ptr.get_end_coord();
//  printf("cur %d %d, 終點 %d %d\n", curCoord.X, curCoord.Y, endCoord->X, endCoord->Y);

  if (curCoord.X == endCoord->X && curCoord.Y == endCoord->Y) return true;

  return false;
}

Coord Routing::get_start_grid() {
  return *maze_ptr->get_start_coord();
}

bool Routing::doTop(Coord curCoord) {
  Coord top = Coord(curCoord.X, curCoord.Y - 1);
  bool isTop = maze_ptr->check_h_barrier(curCoord, Maze::HorizontalBarrier::Top);
//  printf("%d isTop\n", isTop);
  if (isTop)  route(top);
  return false;
}

bool Routing::doBootom(Coord curCoord) {
  Coord bottom = Coord(curCoord.X, curCoord.Y + 1);
  bool isBottom = maze_ptr->check_h_barrier(curCoord, Maze::HorizontalBarrier::Bottom);
//  printf("%d isBottom\n", isBottom);
  if (isBottom) route(bottom);
  return false;
}

bool Routing::doRight(Coord curCoord) {
  Coord right  = Coord(curCoord.X + 1, curCoord.Y);
  bool isRight = maze_ptr->check_v_barrier(curCoord, Maze::VerticalBarrier::Right);
//  printf("%d isRight\n", isRight);
  if (isRight)  route(right);
  return false;
}

bool Routing::doLeft(Coord curCoord) {
  Coord left = Coord(curCoord.X - 1, curCoord.Y);
  bool isLeft = maze_ptr->check_v_barrier(curCoord, Maze::VerticalBarrier::Left);
//  printf("%d isLeft\n", isLeft);
  if (isLeft)  route(left);
  return false;
}

void Routing::route(Coord curCoord) {
  
//  printf("curCoord %d %d\n", curCoord.X, curCoord.Y);

  route_path.push_back(curCoord);
  
  if (isReachEndGrid(curCoord, *maze_ptr)) {
    this->routing_success = true;
    printf("成功走到終點\n\n\n");

    for (int i = 0; i < route_path.size(); i++) {
      Coord coord = route_path[i];
      printf("%d %d\n", coord.X, coord.Y);
    }
    return;
  }

  if (doLeft(curCoord) || doBootom(curCoord) || doTop(curCoord) || doRight(curCoord)) {}
  else {
    route_path.pop_back();
  }
}

Routing::~Routing() {
  fprintf(stdout, "Routing is deconstructor\n");
  delete this->maze_ptr;
}


