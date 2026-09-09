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
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         stack<int> st;
//         ListNode* temp = head;
//         //all values are stored in linked list
//         while(temp != nullptr){
//             st.push(temp->val);
//             temp = temp->next;
//         }
//         temp = head;
//         //store the top value to stack and pop the values
//         while(temp != nullptr){
//             temp->val = st.top();
//             st.pop();
//             temp = temp->next;
//         }
//         return head;
//     }
// };

//another way for this use pointer concept
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return NULL;
        if(head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
        return head;
    }
};