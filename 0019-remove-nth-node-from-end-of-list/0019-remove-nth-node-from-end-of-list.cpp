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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return head;
        }
        if(!head->next&&n==1){
            return nullptr;
        }
        ListNode* tempNode = new ListNode(-1);
        tempNode->next=head;
        ListNode* slow=tempNode;
        ListNode* fast=tempNode;
        while(n!=0){
            fast=fast->next;
            n--;
        }
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return tempNode->next;
    }
};