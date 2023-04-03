// Method 1 (By making push operation costly):

// This method ensures that the newly entered element is always at the front of 'q1' so that pop operation dequeues from 'q1'. 
// 'q2' is used to put every new element in front of 'q1'.

// push(s, x) operation's steps are described below: 
//       Enqueue x to q2
//       One by one dequeue everything from q1 and enqueue to q2.
//       Swap the names of q1 and q2
// pop(s) operation's function is described below: 
//       Dequeue an item from q1 and return it.

/* Program to implement a stack using 
two queue */
#include <bits/stdc++.h>

using namespace std;

class Stack {
    // Two inbuilt queues
    queue<int> q1, q2;

public:
    void push(int x)
    {
        // Push x first in empty q2
        q2.push(x);

        // Push all the remaining
        // elements in q1 to q2.
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // swap the names of two queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void pop()
    {
        // if no elements are there in q1
        if (q1.empty())
            return;
        q1.pop();
    }

    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    int size()
    {
        return q1.size();
    }
};

// Driver code
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "current size: " << s.size()
         << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << "current size: " << s.size()
         << endl;
    return 0;
}
