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

class Solution {
public:
    
    void sortColors(vector<int>& nums) {
        // not able to pass question needs
        //sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            int mini=i;
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[mini])
                    mini=j;            
            }
            swap(nums[mini],nums[i]);   
        }
        
    }
};
