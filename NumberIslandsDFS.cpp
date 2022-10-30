

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
    
void dfs(int row, int column, vector<vector<char>>& grid ){
   
    
    stack<pair<int,int>> depthFirst;
    depthFirst.push({row, column});
      // check all directions for current item in stack (make sure in bounds)
    // change current val in stack to visited 
    // top -1,0  below +1,0    left  0,-1 right 0,+1 
    while(!depthFirst.empty()){
     
        auto current = depthFirst.top();
         depthFirst.pop();
           //cout << grid[row][column]
        grid[current.first][current.second] = '0';
       
if(inBounds(current.first -1, current.second, grid) && grid[current.first -1][current.second] == '1'){
    grid[current.first-1][current.second] = '0';
      depthFirst.push({current.first -1,current.second});
  
}
if(inBounds(current.first +1, current.second, grid) && grid[current.first +1][current.second] == '1'){
     grid[current.first+1][current.second] = '0';
       depthFirst.push({current.first+1,current.second});
}
if(inBounds(current.first, current.second-1, grid) && grid[current.first][current.second-1] == '1'){
       grid[current.first][current.second-1] = '0';
    depthFirst.push({current.first,current.second-1});
    
 }
if(inBounds(current.first, current.second+1, grid) && grid[current.first][current.second+1] == '1'){
     grid[current.first][current.second+1] = '0';
          depthFirst.push({current.first,current.second+1});

 }
         
         
}
    
} 
    int numIslands(vector<vector<char>>& grid) {
    int numIslands = 0;
        
    for(int row = 0; row <grid.size(); row++){
        for(int column = 0; column <grid[row].size(); column++ ){
            
            if(grid[row][column] == '1'){
                
                dfs(row, column, grid);
                //preform dfs
                numIslands++;
                
            }
            
           
        }
   
        
    }
      
   
    return numIslands;    
        
        
    }
};

// iterate over grid 
// if 1 then increase the numIslands 
// traverse that position in all directions storing if that indix[row][colum] = '1'
// change the current val to 0 or 2  to mark as visited 
// check if in bounds 


//ex : 0,0 -> '1' check -1,0 1,-1 1,+1 +1,0 direction in bounds

  /*
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
  */
/*
iterate over the graph 
if grid[i][j] == '1' then we preform bfs and increase number of islands++; 
use bfs

*/
