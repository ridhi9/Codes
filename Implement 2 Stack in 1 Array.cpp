//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
public:
   twoStacks(int n=100){size = n; arr = new int[n]; top1 = -1; top2 = size;}
 
   void push1(int x);
   void push2(int x);
   int pop1();
   int pop2();
};



int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        twoStacks *sq = new twoStacks();

        int Q;
        cin>>Q;
        while(Q--){
        int stack_no;
        cin>>stack_no;
        int QueryType=0;
        cin>>QueryType;
        
        if(QueryType==1)
        {
            int a;
            cin>>a;
            if(stack_no ==1)
            sq->push1(a);
            else if(stack_no==2)
            sq->push2(a);
        }else if(QueryType==2){
        	if(stack_no==1)
            cout<<sq->pop1()<<" ";
            else if(stack_no==2)
            cout<<sq->pop2()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends


// /The idea is to start two stacks from two extreme corners of arr[].
//stack1 starts from the leftmost element, the first element in stack1 is 
//pushed at index 0. The stack2 starts from the rightmost corner, the first
//element in stack2 is pushed at index (n-1). Both stacks grow (or shrink) 
//in opposite direction. To check for overflow, all we need to check is for 
//space between top elements of both stacks. 

//Function to push an integer into the stack1.
void twoStacks :: push1(int x)
{
    //if there is space between the top of both stacks 
    //we push the element at top1+1.
    if (top1 < top2 - 1)
    {
       top1++;
       arr[top1] = x;
    }
 
}

//Function to push an integer into the stack2.
void twoStacks ::push2(int x)
{
   //if there is space between the top of both stacks 
    //we push the element at top2-1.
   if (top1 < top2 - 1)
   {
       top2--;
       arr[top2] = x;
   }
 
}

//Function to remove an element from top of the stack1.
int twoStacks ::pop1()
{
   //if top1==-1, stack1 is empty so we return -1 else we 
   //return the top element of stack1.
   if (top1 >= 0 )
   {
      int x = arr[top1];
      top1--;
      return x;
   }
   else
      return -1;
}

//Function to remove an element from top of the stack2.
int twoStacks :: pop2()
{
   //if top2==size of array, stack2 is empty so we return -1 else we 
   //return the top element of stack2.
   if (top2 < size)
   {
      int x = arr[top2];
      top2++;
      return x;
   }
   else
      return -1;
}
