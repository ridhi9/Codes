//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comparison(Job a,Job b){
        return (a.profit>b.profit);
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        int res=0;
        int count=0;
        //sprting all the jobs according to decreasing order of proft
        sort(arr,arr+n,comparison);
        
        bool slot[n+1];
        //initialisinng all slots to free
        for(int i=0;i<=n;i++)
        slot[i]=false;
        //iterating through all given jobs
        for(int i=0;i<n;i++){
            //finding a free slot for current job(Note that we start from last possible slot)
            for(int j=min(n,arr[i].dead);j>=1;j--){
                if(slot[j]==false){
                    slot[j]=true;
                    count++;
                    res+=arr[i].profit;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(res);
        return ans;
        //TC-O(nlogn)
        
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends
