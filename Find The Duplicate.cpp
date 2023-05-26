class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>m ;

        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;           
    }
           for(auto &i:m)
               if(i.second>1)
               return i.first;
         return 0;  
    }
};

//   int tortoise = nums[0];
//         int hare = nums[0];

//         do {
//             tortoise = nums[tortoise];
//             hare = nums[nums[hare]];
//         } while (tortoise != hare);

//         // Find the "entrance" to the cycle.
//         tortoise = nums[0];
//         while (tortoise != hare) {
//             tortoise = nums[tortoise];
//             hare = nums[hare];
//         }

//         return hare;
