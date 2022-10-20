#include <unordered_map>
#include <string>
#include <iostream>


using namespace std;
int characterReplacement(string, int);

int main(){

string s = "AABABBA";
int k = 1;

cout << characterReplacement(s, k);
    return 0;

}
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
     int currentMax = 0;
    int overallMax = 0;
        
        
        
        int i = 0;
        int j = 0;
        while(j < s.length()){
            int temp = 0;
            currentMax++;
            freq[s[j]]++;
        //find most frequent
        for(auto x : freq){
        if (temp < x.second) temp = x.second; }
       // cout << temp;
            // making sure current window works
        if((currentMax - temp) <= k){
            j++;
        }
            // finds the first val and decrements it;
            else if((currentMax - temp) > k){
               // cout << "Yes";
                freq[s[i]]--;
                currentMax --;
                overallMax = max(currentMax, overallMax);
                i++;
                j++;
            
            }
            
            
            
        }
       if(currentMax > overallMax) return currentMax;
         else 
             return overallMax;
       
    }


//size of the window - most frequent <= k

