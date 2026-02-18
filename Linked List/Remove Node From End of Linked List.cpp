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
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        int toremove=count-n;
        ListNode* temp1=head;
        if(toremove==0){
            return head->next;
        }
        for(int i=1;i<toremove;i++){
            temp1=temp1->next;
        }
       temp1->next=temp1->next->next;
       return head;
    }
};
