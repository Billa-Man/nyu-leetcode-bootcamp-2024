#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();
        vector<int> ans;
        
        int left_ptr = 0;
        int right_ptr = n-1;

        while(right_ptr>left_ptr){
            if(numbers[left_ptr] + numbers[right_ptr] == target){
                ans.push_back(left_ptr+1);
                ans.push_back(right_ptr+1);
                return ans;
            }
            else if(numbers[left_ptr] + numbers[right_ptr] > target){
                right_ptr--;
            }
            else{
                left_ptr++;
            }
        }

        return ans;
    }
};