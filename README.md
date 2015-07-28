# Project 3: Maze-routing

## Description
>  maze routing in C++ program.  
>  output: true, false

## First
  - define a struct of **coord**  
  - struct of coord has int members: x, y  

## Second: represent a 5x5 maze in a **maze** class
### &ensp;maze class has data members:
  - **h_barrier**, **v_barrier**
  - **maze_x_size**, and **maze_y_size** = 5
  - **start_coord**, **end_coord**

### &ensp;maze class has members functions:
- **input()**:  
    &ensp;&ensp;&ensp;&ensp; **h_barrier**, **v_barrier**, **start_coord**, **end_coord**。  
    &ensp;&ensp;&ensp;&ensp; set **maze_x_size** = 5, **maze_y_size** = 5。
- **check_h_barrier()**:  
    &ensp;&ensp;&ensp;&ensp; Check and return whether a coordinate parameter is on the horizontal barrier。
- **check_v_barrier()**:  
    &ensp;&ensp;&ensp;&ensp; Check and return whether a coordinate parameter is on the vertical barrier。
- **get_start_coord()**:  
    &ensp;&ensp;&ensp;&ensp; Return the starting coordinate。
- **get_end_coord()**:  
    &ensp;&ensp;&ensp;&ensp; Return the ending coordinate。

## Thirdly:&ensp;define a routing class 
### &ensp;routing class had data members:
  - **maze_ptr**:  
      &ensp;&ensp;&ensp;&ensp; points to a selectd maze object.
  - **routing_success**:  
      &ensp;&ensp;&ensp;&ensp; Initially, set to false.&ensp; When  maze routing reaches the ending grid, it is set to true.
  - **route_path**:  
      &ensp;&ensp;&ensp;&ensp; a vector of grid coordnates from the starting grid to the ending grid if a route is found,  
      &ensp;&ensp;&ensp;&ensp; an empty vector otherwise.

### &ensp; routing class has member functions:  
  - **select_maze()**:  
    &ensp;&ensp;&ensp;&ensp; Given a maze number, set the **maze_ptr**.  
    &ensp;&ensp;&ensp;&ensp; Rest **routing_success** and **route_path**
  - **get_start_grid()**:  
      &ensp;&ensp;&ensp;&ensp; In the selected maze, get and return the starting grid.
  - **route(coord_current_grid)**:  
      &ensp;&ensp;&ensp;&ensp; This is a recursive function that traverses the maze from the starting grid toward the ending grid.  
      &ensp;&ensp;&ensp;&ensp; As shown in the following figures, route() design should follow certain principles:    

> &ensp;&ensp;&ensp; (1) route() will recursively try scan non-barrier neighbor for routing except the current source.  
> &ensp;&ensp;&ensp; (2) route() will return when exhausting all scanned neighbors or finding the ending grid.  
> &ensp;&ensp;&ensp; (3) route() will output grids when entering(calling) and leaving(returning).  
> &ensp;&ensp;&ensp; (4) route() will record forward traversed grid in a path and remove   
  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;if from the path when returning if still not finding the ending grid.


