 //TwoSum numbers sorted O(N^2)
 // second for loop j = i+1
 // dont have i iterate through entire array but array.size()-1;
 // j iterates through everything
 vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> indexes;
        
        int left = 0;
        int right = numbers.size() -1;
        // can't use same number twice
      for(int i =0; i < numbers.size()-1; i++){
          for(int j = i+1; j < numbers.size(); j++){
              
             if(numbers[i] + numbers[j] == target){
                 indexes.push_back(i+1);
                  indexes.push_back(j+1);
             return indexes;
             }
          }
      }
        
        return indexes;
        
        
    }

    class Solution {
public:
   // O(N)
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> indexPlus;
        
        int left = 0;
        int right = numbers.size()-1;
        // can't have left and right be on same index
        while(left < right){
            
            if((numbers[left] + numbers[right]) == target){
                indexPlus.push_back(left+1);
                 indexPlus.push_back(right+1);
                 break;
            }
            // left + right > target
            else if((numbers[left] + numbers[right]) > target){
                right--;
                     
            }
            // where left + right < target
            else {
                left++;
                
            }        
            
        }
        return indexPlus;
        
    }
};
// create vector to return;
//left and right pointers where left  = 0 and right = numbers.size()-1
// if number[left] + right = target push_back into vector then break; 
// if number[left] + right > target  then shift right to the left
// else opposite 