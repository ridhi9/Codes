class Solution {
public:
    void sortColors(vector<int>& nums) {
        //bubble sprt
   int i, j;
    for (i = 0; i < nums.size() - 1; i++)
 
        // Last i elements are already
        // in place
        for (j = 0; j < nums.size() - i - 1; j++)
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
    }
};
