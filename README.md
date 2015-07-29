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
  &ensp;&ensp;&ensp;&ensp; 迷宮如果能走到終點印出 leave + 走過的 path, 否則印出 leave。
  
### &ensp;&ensp; 系統層設計:
  &ensp;&ensp;&ensp;&ensp; 迷宮會有障礙物以及出入口, **path** 代表的是由入口正確走到出口的路徑  
  &ensp;&ensp;&ensp;&ensp; 迷宮由入口走入,並且嘗試往可以走的方向前進,   
  &ensp;&ensp;&ensp;&ensp; 如果走到死路就退回上一個選擇路口的分叉點並換條另一條路繼續走, 直到迷宮走完, 或是走到出口。 
  &ensp;&ensp;&ensp;&ensp; 如果能走迷宮印出 leave + path。  
  &ensp;&ensp;&ensp;&ensp; 如果發現路已經走過, 返回去另一條路, 如果每個路口都走過了還是走不出去, 印出 leave。  
  
### &ensp;&ensp; 邏輯層設計:
  &ensp;&ensp;&ensp;&ensp; 如果每個路口都走過了還是走不出去, 印出 leave。  
  &ensp;&ensp;&ensp;&ensp; 迷宮障礙物: 一個二維陣列表示垂直障礙物, 另一個表示橫向障礙物。  
  &ensp;&ensp;&ensp;&ensp; path的組成: 入口的位置到走到出口的位置(coord代表位置)。  
  &ensp;&ensp;&ensp;&ensp; 走迷宮的解決辦法:  
  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp; 從迷宮入口走起,並且往可以走的方向前進(方向選擇優先權右下左上):  
  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp; 如果最高優先權不會碰到障礙物, 就往最高優先權方向前進,  
  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp; 否則最高優先權碰到障礙物就採用次之的優先權, 以此類推..。
  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp; 如果能夠走到迷宮的出口位置, 就把入口到出口每次選擇的路徑給印下來。  
  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp; 如果走到死路,就折返到當前選擇權 > 1的路徑, 並換次之可以走的優先權(不會到碰礙物) 繼續走  
  &ensp;&ensp;&ensp;&ensp;&ensp;&ensp; 如果到最後, 迷宮所有可走的路徑都走過了, 就印出 leave  
  
  
  
  
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
  



