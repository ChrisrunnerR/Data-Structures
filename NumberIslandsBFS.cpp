class Solution {
public:

bool inBounds(int row, int column,vector<vector<char>>& grid){
     int rowSize = grid.size();
    int columnSize = grid[0].size();
    if(row < 0  ||  row >= rowSize ) return false;
    if(column < 0 || column >= columnSize) return false;
    else
        return true;   
}
    
void breadth(int row, int column, vector<vector<char>>& grid){
    
    queue<pair<int,int>> bfs;
    bfs.push({row, column});
    
    while(!bfs.empty()){
        int  row = bfs.front().first;
          int column = bfs.front().second;
        cout << row << " " << column << endl;
      bfs.pop(); 
        grid[row][column] = '2';
       // cout << grid[row][column] << endl;
        int k = bfs.size();

if(inBounds(row-1, column, grid) && grid[row-1][column] == '1'){
    grid[row-1][column] = '2';
     bfs.push({row-1,column});
    
}
 
if(inBounds(row+1, column, grid) && grid[row+1][column] == '1'){
     grid[row+1][column] = '2';
    bfs.push({row+1,column});
} 
            
if(inBounds(row, column-1, grid) && grid[row][column-1] == '1'){
     grid[row][column-1] = '2';
    bfs.push({row,column-1});
} 
    

if(inBounds(row, column+1, grid) && grid[row][column+1] == '1'){
     grid[row][column+1] = '2';
    bfs.push({row,column+1});
    
} 
    }  
 
    
}
    
     int numIslands(vector<vector<char>>& grid) {
      int numIslands = 0;
        
        for(int row = 0; row < grid.size(); row++){
            for(int column = 0;column < grid[row].size(); column++){
                
                if(grid[row][column] == '1'){
                    numIslands++;
                    breadth(row, column, grid);
                   // numIslands++;
                    
                }
               // cout << endl;
            }
         
        }
          
        return numIslands;
        
    }
};

// BFS 
// iterate through grid 
// if grid[i][j] == '1' -> numIslands++  then -> bfs 
// bfs with queue & helper funct for making sure we are in bounds

//
/*
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
  
*/




