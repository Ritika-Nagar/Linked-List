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
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         stack<int>st;
//         ListNode* prev=NULL;
//         ListNode* curr=head;
//         ListNode* lef=NULL;
//         ListNode* forw=NULL;
//         int cnt=1;
//         while(cnt<=right && curr!=NULL){
//             if(cnt==left)lef=prev;
//             else if(cnt==right)lef->next=curr->next;curr->next=prev;curr->next=lef;
//             else if(cnt>left && cnt<right){forw=curr->next;curr->next=prev;prev=curr;curr=forw;}
//             else prev=curr; curr=curr->next;
//             cnt++;
            
//         }
    
//         return head;
//     }
    
     ListNode* reverseBetween(ListNode* head, int left, int right) {
         ListNode* dummy= new ListNode(0);
         ListNode* leftprev=dummy;
         ListNode* curr= head;
         dummy->next=head;
         
         // reach node at left position 
         for(int i=0 ;i<left-1; i++){
             leftprev=curr;
             curr=curr->next;
         }
            
          // now curr= left, leftPrev=" node before left"
         // reverse from left to right 
         ListNode* prev=NULL;
         for(int i=0 ;i<=right-left;i++){
             ListNode* forw= curr->next;
             curr->next= prev;
             prev=curr;
             curr=forw;
         }
         
         //
         ListNode* lef= leftprev->next;
         lef->next=curr;
         leftprev->next=prev;
         return dummy->next;
         
     }
    
};



            
         
    
        
        
        
        
    
