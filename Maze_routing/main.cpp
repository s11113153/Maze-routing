//
//  main.cpp
//  Maze_routing
//
//  Created by 許佑任 on 2015/7/27.
//  Copyright (c) 2015年 許佑任. All rights reserved.
//

#include <iostream>
#include "Maze.h"
#include "Routing.h"
#include <vector>

using std::cout;
using std::endl;


int main(int argc, const char * argv[]) {
  Routing routing;
  routing.select_maze()
         .route(routing.get_start_grid());

  if (routing.routing_success) {
    routing.route_path.size();
    fprintf(stdout, "leave\n");
  } else {
    fprintf(stdout, "被困死了\n");
  }

  return EXIT_SUCCESS;
}
