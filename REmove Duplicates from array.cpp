class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    //     set<int>s;
    // //   for(int i=0;i<nums.size();i++){
    // //       s.insert(i);
    // //   }  
    // s.insert(nums.begin(),nums.end());
    //   return s.size();
   sort(nums.begin(),nums.end());
   nums.erase(unique(nums.begin(),nums.end()),nums.end());
    return nums.size();
    }
};

// class Solution {
//     public int removeDuplicates(int[] arr) {
//         int i=0;
//         for(int j=1;j<arr.length;j++){
//             if(arr[i]!=arr[j]){
//                 i++;
//                 arr[i]=arr[j];
//             }
//         }
//         return i+1;
        
//     }
// }
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
        
//          int slow=0,fast=1;
//     while(fast<=nums.size()-1){
//         if(nums[slow]!=nums[fast]){
//             nums[++slow]=nums[fast];
//         }else{
//             fast++;
//         }
//     }
//     return slow+1;
//     }
// };
