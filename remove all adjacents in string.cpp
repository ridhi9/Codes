// Input: s = "abbaca"
// Output: "ca"
// Explanation: 
// For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.
//   The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
		ans.push_back(s[0]);

		for(int i=1 ; i<s.length() ; i++){

			if(s[i] == ans.back()){
				ans.pop_back();
			}
			else{
				ans.push_back(s[i]);
			}
		}

		return ans;
    }
};
