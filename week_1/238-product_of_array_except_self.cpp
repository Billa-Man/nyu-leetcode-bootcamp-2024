class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        int num_zeros = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                num_zeros++;
            }
            if(num_zeros > 1){
                return vector<int> (n, 0);
            }
        }

        vector<int> pre_product(n+1, 1);
        vector<int> suf_product(n+1, 1);

        int pre = 1;
        int suf = 1;

        for(int i=0; i<n; i++){
            pre = pre*nums[i];
            suf = suf*nums[n-1-i];
            pre_product[i] = pre;
            suf_product[n-1-i] = suf;
        }

        vector<int> ans(n);
        ans[0] = suf_product[1];
        ans[n-1] = pre_product[n-2];

        for(int i=1; i<n-1; i++){
            ans[i] = pre_product[i-1]*suf_product[i+1];
        }

        return ans;
    }
};