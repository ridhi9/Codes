// Method 2 (By making pop operation costly):
// In a push operation, the new element is always enqueued to q1. In pop() operation, if q2 is empty then all the elements except the last, are moved to q2. 
// Finally, the last element is dequeued from q1 and returned.

// push(s, x) operation: 
      // Enqueue x to q1 (assuming size of q1 is unlimited).
// pop(s) operation: 
    // One by one dequeue everything except the last element from q1 and enqueue to q2.
    // Dequeue the last item of q1, the dequeued item is result, store it.
    // Swap the names of q1 and q2
    // Return the item stored in step 2.
// Program to implement a stack 
// using two queue
#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void pop()
    {
        if (q1.empty())
            return;

        // Leave one element in q1 and
        // push others in q2.
        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Pop the only left element
        // from q1
        q1.pop();

        // swap the names of two queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    void push(int x)
    {
        q1.push(x);
    }

    int top()
    {
        if (q1.empty())
            return -1;

        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // last pushed element
        int temp = q1.front();

        // to empty the auxiliary queue after
        // last operation
        q1.pop();

        // push last element to q2
        q2.push(temp);

        // swap the two queues names
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
        return temp;
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
    s.push(4);

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

// Method 3 (Implement Stack using only 1 queue):
// In this method, we will be using only one queue and make the queue act as a stack by using following steps: 

// The idea behind this approach is to make one queue and push the first element in it. 
// After the first element, we push the next element and then push the first element again and finally pop the first element. 
// So, according to the FIFO rule of the queue, the second element that was inserted will be at the front and then 
// the first element as it was pushed again later and its first copy was popped out. 
// So, this acts as a stack and we do this at every step i.e. from the initial element to the second last element, 
// and the last element will be the one which we are inserting and since we will be pushing the 
// initial elements after pushing the last element, our last element becomes the first element.

#include <bits/stdc++.h>
using namespace std;

// Stack Class that acts as a queue
class Stack {

    queue<int> q;

public:
    void push(int data);
    void pop();
    int top();
    bool empty();
};

// Push operation
void Stack::push(int data)
{
    //  Get previous size of queue
    int s = q.size();

    // Push the current element
    q.push(data);

    // Pop all the previous elements and put them after
    // current element

    for (int i = 0; i < s; i++) {
        // Add the front element again
        q.push(q.front());

        // Delete front element
        q.pop();
    }
}

// Removes the top element
void Stack::pop()
{
    if (q.empty())
        cout << "No elements\n";
    else
        q.pop();
}

// Returns top of stack
int Stack::top() { return (q.empty()) ? -1 : q.front(); }

// Returns true if Stack is empty else false
bool Stack::empty() { return (q.empty()); }

int main()
{
    Stack st;
    st.push(40);
    st.push(50);
    st.push(70);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.push(80);
    st.push(90);
    st.push(100);
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    st.pop();
    cout << st.top() << "\n";
    return 0;
}
