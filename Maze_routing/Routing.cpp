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
  printf("cur %d %d, 終點 %d %d\n", curCoord.X, curCoord.Y, endCoord->X, endCoord->Y);

  if (curCoord.X == endCoord->X && curCoord.Y == endCoord->Y) return true;

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
  
  printf("curCoord %d %d\n", curCoord.X, curCoord.Y);

  route_path.push_back(curCoord);
  
  if (isReachEndGrid(curCoord, *maze_ptr)) {
    this->routing_success = true;
    printf("成功走到終點\n\n\n");

    for (int i = 0; i < route_path.size(); i++) {
      Coord coord = route_path[i];
      printf("%d %d\n", coord.X, coord.Y);
    }

    return true;
  }

//  bool isTop = maze_ptr->check_h_barrier(curCoord, Maze::HorizontalBarrier::Top);
//  bool isBottom = maze_ptr->check_h_barrier(curCoord, Maze::HorizontalBarrier::Bottom);
//  bool isRight = maze_ptr->check_v_barrier(curCoord, Maze::VerticalBarrier::Right);
//  bool isLeft = maze_ptr->check_v_barrier(curCoord, Maze::VerticalBarrier::Left);
//
//
//  printf("isTop = %d isBottm = %d\n", isTop, isBottom);
//  printf("isRight = %d isLeft = %d\n", isRight, isLeft);
//  printf("\n\n\n");
//
//
//  Coord top    = Coord(curCoord.X, curCoord.Y - 1);
//  Coord bottom = Coord(curCoord.X, curCoord.Y + 1);
//  Coord left   = Coord(curCoord.X - 1, curCoord.Y);
//  Coord right  = Coord(curCoord.X + 1, curCoord.Y);


//  if (route_path.size() > 1) {
//    Coord perCoord = route_path[route_path.size() - 1];
//
//    if (top.X == perCoord.X && top.Y == perCoord.Y) {
//      printf("top 重複\n");
//      isTop = false;
//    }
//
//    if (bottom.X == perCoord.X && bottom.Y == perCoord.Y) {
//      printf("bottom 重複\n");
//      isBottom = false;
//    }
//
//    if (left.X == perCoord.X && left.Y == perCoord.Y) {
//      printf("left 重複\n");
//      isLeft = false;
//    }
//
//    if (right.X == perCoord.X && right.Y == perCoord.Y) {
//      printf("right 重複\n");
//      isRight = false;
//    }
//  }

//  route_path.push_back(curCoord);

//  if (isLeft) {
//      printf("left\n");
//      route(left);
//  }
//
//  if (isBottom) {
//      printf("bottom\n");
//      route(bottom);
//  }
//
//  if (isTop) {
//      printf("top\n");
//      route(top);
//  }
//
//  if (isRight) {
//      printf("right\n");
//      route(right);
//  }
//
//  if (!isLeft && !isBottom && !isTop && !isRight) {
//    printf("死路\n\n\n");
//  }

  return doLeft(curCoord) || doBootom(curCoord) || doTop(curCoord) || doRight(curCoord);
}

Routing::~Routing() {
  fprintf(stdout, "Routing is deconstructor\n");
  delete this->maze_ptr;
}


