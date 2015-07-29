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
> &ensp;&ensp;&ensp;&ensp;&ensp;&ensp;&ensp;if from the path when returning if still not finding the ending grid.

## 設計五步驟:
### &ensp;&ensp; 領域知識探索掌握:
  &ensp;&ensp;&ensp;&ensp;
  這是遞迴的概念, 給定初始值(start coord)、終止步驟(迷宮都scan過 OR 當前點位置出口)，否則一直呼叫本身。
  
### &ensp;&ensp; 系統層設計:
  &ensp;&ensp;&ensp;&ensp; **struct**: Coord,     
  &ensp;&ensp;&ensp;&ensp; **class**: Maze, Routing    
  
  &ensp;&ensp;&ensp;&ensp; Coord 用來表示座標點  
  &ensp;&ensp;&ensp;&ensp; Maze 用來設定迷宮的障礙物以及出入口  
  &ensp;&ensp;&ensp;&ensp; Routing 用來紀錄你所走的路徑(會根據 Maze 障礙物, 並且不會往回走)  
  
### &ensp;&ensp; 邏輯層設計:
  &ensp;&ensp;&ensp;&ensp; Coord 用來表示(x,y) 座標。
  
  &ensp;&ensp;&ensp;&ensp; Maze 會有出入口以及多數障礙物, 並要求 Maze 大小為 5*5 矩陣: 這步驟由 input 處理出入口以及障礙物的座標。  
  
  &ensp;&ensp;&ensp;&ensp; Routing 選擇要挑戰的迷宮以及入口: 由 select_maze 設定迷宮, get_start_grid 獲得入口。  
  &ensp;&ensp;&ensp;&ensp; Routing 要走下一步之前會先詢問 Maze 是否可以通行(check_h_barrier, check_v_barrier) 以及是否已經走到終點。  
  &ensp;&ensp;&ensp;&ensp; Routing 如果都走遍路徑, 還是沒走到終點: output leave，否則的話: output leave + 如何走出去的路徑(route_path)。  
  
### &ensp;&ensp; 程式層設計:
  &ensp;&ensp;&ensp;&ensp;
  此 Project 就有程式設計。
### &ensp;&ensp; 程式碼設計:
  &ensp;&ensp;&ensp;&ensp;
  此 Project 內有自定義 6 張迷宮, 並且已經測試過。  
  &ensp;&ensp;&ensp;&ensp;
  若有 Bug 或是邏輯錯誤, 會在修正此專案的版本。  

## 心得
  &ensp;&ensp;&ensp;&ensp; 
  學長查看程式碼的時候有問到這些函數回傳 fasle (doTop, doRight, doLeft, doBottom) 的原因,  
  &ensp;&ensp;&ensp;&ensp; 
  我的想法跟實作的方法有差異, 原本是想說會走到終點的座標會回傳給之前呼叫它的座標為true...一直到起始點,  
  &ensp;&ensp;&ensp;&ensp; 如果都為true, 那麼這就是一條通往出口的正確道路, 否則回傳 false。  
  &ensp;&ensp;&ensp;&ensp; 但是我程式執行最後好像都會 return false ，經過學長提醒後, 已經修正過了。  
  &ensp;&ensp;&ensp;&ensp; 此外學長還有講到到進一步處理多重出口的路徑，開一個資料結構(Array, Map, List...) 用來儲存,  
  &ensp;&ensp;&ensp;&ensp;
  並把走到終點就停止遞迴的步驟拿掉,這樣就可以了。
  



