//
//  Maze.cpp
//  Maze_routing
//
//  Created by 許佑任 on 2015/7/27.
//  Copyright (c) 2015年 許佑任. All rights reserved.
//

#include "Maze.h"

void log(std::string func, std::string msg) {
  fprintf(stdout, "%s: %s\n", func.c_str(), msg.c_str());
}

void scan(bool** array, int y, int x, std::string who, bool isPrint) {
  for (int i = 0; i < y; i++)
    for (int j = 0; j < x; j++) {
      int n;
      do {
        std::string msg = who
            + "[" + std::to_string(i) + "]"
            + "[" + std::to_string(j) + "]";
        log(__func__, msg);
        log(__func__, "please input 0 OR 1");
        cin >> n;
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        if (!cin || (cin.gcount() != 1) || !(n == 0 || n == 1))
          log(__func__, "invalid scan");
        else {
          array[i][j] = n;
          break;
        }
      } while (true);
    }

  if (!isPrint) return;

  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      printf("%d", array[i][j]);
    }
    printf("\n");
  }
}

Maze::Maze() {
  log(__func__, "Maze is created");
  start_coord = new Coord(6, 2);
  end_coord = new Coord(2, 6);
}

Maze::~Maze() {
  delete [] h_barrier;
  delete [] v_barrier;
  delete start_coord;
  delete end_coord;

  h_barrier = NULL;
  v_barrier = NULL;
  start_coord = NULL;
  end_coord = NULL;

  log(__func__, "Maze is deconstructor");
}

void Maze::input() {
  h_barrier = new bool *[MAZE_SIZE_Y + 2];
  for (int i = 0; i < MAZE_SIZE_Y + 2; i++)
      h_barrier[i] = new bool[MAZE_SIZE_X + 3];

  v_barrier = new bool *[MAZE_SIZE_Y + 3];
  for (int i = 0; i < MAZE_SIZE_Y + 3; i++)
      h_barrier[i] = new bool[MAZE_SIZE_X + 2];

  scan(h_barrier, MAZE_SIZE_Y + 2, MAZE_SIZE_X + 3, "h_barrier", true);
  scan(v_barrier, MAZE_SIZE_Y + 3, MAZE_SIZE_X + 2, "v_barrier", true);
}

bool Maze::check_h_barrier() {
  return false;
}

bool Maze::check_v_barrier() {
  return false;
}

Coord * Maze::get_start_coord() {
  return start_coord;
}

Coord * Maze::get_end_coord() {
  return end_coord;
}




