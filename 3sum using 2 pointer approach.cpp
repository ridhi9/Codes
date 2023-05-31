class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    
            vector<vector<int>>ans;
            int n=nums.size();
            sort(nums.begin(),nums.end());
            for(int i=0;i<n;i++){
                //agar 2 i same hai toh dono se same ans aayega par uska kya fayda hme unique set chahiye that's why hm voh partiular i ko skkip kr denge aur next pe chl jaynge and that's why we are using continue statement
                if(i>0 && nums[i]==nums[i-1]) continue;
              
                int k=n-1;
                  int j=i+1;
                while(j<k){
                    int sum=nums[i]+nums[j]+nums[k];
                    if(sum<0) j++;
                    else if(sum>0) k--;
                    else{
                        //sum=0;

                        vector<int>temp= {nums[i],nums[j],nums[k]};
                        ans.push_back(temp);
                        j++;
                        k--;
                        while(j<k && nums[j]==nums[j-1]) j++;
                        while(j<k && nums[k]==nums[k+1]) k--;

                    }
                }
            }

return ans;
        // above solution gives TLE
    }
};
