/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // ListNode* reverse(ListNode* &head){
    //     //base case
    //     if(head==NULL || head->next==NULL)
    //     return head;
    //     ListNode* temp=reverse(head->next);
    //     head->next->next=head;
    //     head->next=NULL;
    //     return temp;
    // }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ListNode* temp1=reverse(head);

        
    //     if(n==1){
    //         ListNode* temp2=temp1;
    //         temp1=temp1->next;
    //         temp2->next=NULL;
    //         delete temp2;
    //     }
    //     else{
    //     ListNode* curr=temp1;
    //     ListNode* prev=NULL;
    //     int count=1;
    //     while(count<n){
    //         // int count=1;
    //         prev=curr;
    //         curr=curr->next;
    //         count++;
    //     }
        
    //     prev->next=curr->next;
    //     curr->next=NULL;
    //     delete(curr);
    //     }
    //    ListNode* head2= reverse(temp1);
    //     return head2;


    ListNode* start=new ListNode();
    start->next=head;
    ListNode* slow=start;
    ListNode* fast=start;
    for(int i=1;i<=n;i++){
        fast=fast->next;
    
    }
//       TC=O(n)  SC=1
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    ListNode* deletedNode=slow->next;
    slow->next=slow->next->next;
    deletedNode->next=NULL;
    delete(deletedNode);
    return start->next;
    }

};
