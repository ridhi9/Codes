//For reverse a vector of any thing by simply using reverse function ->   v.begin(),v.end() takes O(n) time complexity but O(1) space complexity
//Same complexity with swap function
//By Swap function
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
       for(int i=0;i<floor((n+1)/2);i++){
           swap(s[i],s[n-1-i]);
       }
        
    }
};
//2 by reverse

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(),s.end());
        
    }
};

//3
class Solution {
public:
    
    void reverseString(vector<char>& s) {
       int p=0;
        int e=s.size()-1;
        while(p<e){
        swap(s[p++],s[e--]);
        }    }
};
