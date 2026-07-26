/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head||!head->next){
            return false;
        }
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast&&fast->next){
            if(fast==slow){
                return true;
            }
            fast=fast->next->next;
            slow=slow->next;
        }   
        return false;

        // unordered_map<ListNode* , bool> m;
        // ListNode* temp=head;
        // while(temp!=nullptr){
        //     if(m.find(temp)!=m.end()){
        //         return true;
        //     }
        //     m[temp]=true;
        //     temp=temp->next;
        // }
        // return false;
    }
};