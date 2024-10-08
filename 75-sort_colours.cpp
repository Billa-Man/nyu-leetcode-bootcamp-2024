class Solution {
public:

    void swap(int &a, int&b){
        int temp = a;
        a = b;
        b = temp;
    }

    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        
        int low_pointer = 0;
        int mid_pointer = 0;
        int high_pointer = n-1;

        while(mid_pointer<=high_pointer){
            if(nums[mid_pointer] == 0){
                swap(nums[mid_pointer], nums[low_pointer]);
                low_pointer++;
                mid_pointer++;
            }
            else if(nums[mid_pointer] == 1){
                mid_pointer++;
            }
            else{
                swap(nums[mid_pointer], nums[high_pointer]);
                high_pointer--;
            }
        }
    }
};