long long//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define MAX 1000
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
     vector< long long> nextSmallerElement(    long long *arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<long long> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<    long long> prevSmallerElement(    long long* arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<    long long> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }   
    
           long long maxArea(long long M[MAX][MAX], int n, int m) {
        
       //compute area for first row
            long long area = getMaxArea(M[0], m);
        
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                
                //row udpate: by adding previous row's value
                if(M[i][j] != 0)
                    M[i][j] = M[i][j] + M[i-1][j];
                else
                    M[i][j] = 0;
            }
            
            //entire row is updated now
            area = max(area, getMaxArea(M[i],m));
            
        }
        return area;
    }
    
  
    
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
           
        vector<    long long> next(n);
        next = nextSmallerElement(arr, n);
            
        vector< long long> prev(n);
        prev = prevSmallerElement(arr, n);
        
            long long area = INT_MIN;
        for(int i=0; i<n; i++) {
                long long l = arr[i];
            
            if(next[i] == -1) {
                next[i] = n;
            }
                 long long b = next[i] - prev[i] - 1;
                long long newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends
