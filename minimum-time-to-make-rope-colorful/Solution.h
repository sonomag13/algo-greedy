// 1578. Minimum Time to Make Rope Colorful

#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

        int totalTime = 0; 
        int maxTime = neededTime[0]; 
        char preColor = colors[0]; 

        for (size_t i = 1; i < colors.length(); ++i) {  
            char curColor = colors[i]; 
            if (preColor != curColor) {
                preColor = curColor; 
                maxTime = neededTime[i]; 
                continue; 
            }

            // current color = previous color
            if (neededTime[i] >= maxTime) {
                // release the previous bloon
                totalTime += maxTime; 
                maxTime = neededTime[i]; 
                preColor = colors[i];
            }
            else {
                // remove the current bloon and keep the previous bloon
                totalTime += neededTime[i]; 
            }

        }
        
        return totalTime; 
    }
};