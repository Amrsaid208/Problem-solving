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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode * prev=nullptr;
        ListNode * dum=new ListNode(305);
        dum->next=head;
        ListNode * root=dum;
        while(root)
        {   
        bool d5l=false;
            while(root->next  && root->val == root->next->val) 
            {
                d5l=true;
                root=root->next;
            }
            if(d5l)
            {
                root=root->next;
                prev->next=root;
                continue;
            }
            prev=root;
            root=root->next;

        }
        return dum->next;
    }
};