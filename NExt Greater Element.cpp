//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
 public:
//     //Function to find the next greater element for each element of the array.
//     bool isEmpty(stack<long long>& s){
// 	if(s.size()==0)
// 		return true;
// 	return false;
// }
// int pop(stack<long long>& s){
// 	int a= s.top();
// 	s.pop();
// 	return a;
// }
//     int getMax(stack<long long>& s){
// 	int n=pop(s);
// 	while(!isEmpty(s)){
// 		int m=pop(s);
// 		if(n>m)
// 			n=m;
// 	}
// 	return n;
// }
  
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // // // Your code here
        // vector<long long> s(n,-1);
        // stack<long long> l;
        // l.push(0);
        // for(int i=1;i<n;i++){
        //     while(!l.empty() && arr[l.top()]<=arr[i]){
        //         s[l.top()]=arr[i];
        //         l.pop();
        //     }
        //     l.push(i);
        // }
        // // for(int i=0;i<n;i++){
        // //     l.push(arr[i]);
        // //     // s.push_back(getMax(l[i]));
        // // }
        // // for(int i=0;i<n;i++){
        // //     s.push_back(getMax(l));
        // // }
        // // // getMax(l);
        // // // s.push_back(getMax(l[i]));
        // // s[n-1]=-1;
        // // return s;
        // return s;
        
        
        
         stack<long long > s;
        vector<long long > res (n);
        
        //traversing the array from last element in backward direction.
        for (int i = n-1; i >= 0; i--)
        {
            //while element at top of stack is less than or equal to
            //current array element, we pop elements from the stack.
            while (!s.empty () and s.top () <= arr[i])
                s.pop ();
            
            //if stack becomes empty, we store -1 in the answer list 
            //else we store the top element of the stack.   
            if (s.empty ())
                res[i] = -1;
            else 
                res[i] = s.top ();
            
            //pushing the current array element into the stack.  
            s.push (arr[i]);
        }
        //returning the list.
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends
