// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;

        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
       unordered_set<int> Freq;
       for(auto[key,value]:m)
       Freq.insert(value);
       return Freq.size()==m.size();
    }
    
};
