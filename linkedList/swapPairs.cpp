class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
     ListNode* curr = head;
     ListNode* prev = NULL;
     ListNode* next = NULL;
     int cnt = 0;

     while(curr!=NULL && cnt<2){
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
         cnt++;
     }
     if(next!=NULL) head->next = swapPairs(next);

     return prev;
    }
};