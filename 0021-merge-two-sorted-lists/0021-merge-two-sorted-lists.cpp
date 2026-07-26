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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l3 = new ListNode(-1);
        ListNode* temp=l3;
        if(!list1){
            return list2;
        }   
        if(!list2){
            return list1;
        }
        if(!list1&&list2){
            return list1;
        }

        while(list1&&list2){
            if(list1->val>=list2->val){
                temp->next=list2;
                ListNode* forward=list2->next;
                temp->next->next=nullptr;
                list2=forward;
            }
            else{
                temp->next=list1;
                ListNode* forward=list1->next;
                temp->next->next=nullptr;
                list1=forward;
            }
            temp=temp->next;
        }
        while(list1){
                temp->next=list1;
                ListNode* forward=list1->next;
                temp->next->next=nullptr;
                list1=forward;
                temp=temp->next;
        }
        while(list2){
                temp->next=list2;
                ListNode* forward=list2->next;
                temp->next->next=nullptr;
                list2=forward;
                temp=temp->next;
        }
        return l3->next;
    }
};