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

Better and Optimized Solution in TC=O(n/2)  SC=O(1)
class Solution {

public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL ||head->next==NULL){
            return head;
        }
      
//       No need to handle this case externally
//         if(head->next->next==NULL){
//             return head->next;
            
//         }
        ListNode*slow=head;
        ListNode *fast=head->next;
        while(fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
            fast=fast->next;
            }
            slow=slow->next;
        }
        return slow;
    }
};
