#include <iostream>

using namespace std;

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

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* enode, *p;
        enode = head;
        if(head == nullptr || head->next == nullptr) return head;
        p = head->next;
        while(p!=nullptr){
            auto nxt = p->next;
            p->next = enode;
            enode = p;
            p = nxt;
        }
        head->next = nullptr;
        return enode;
    }
};


// Recursive solution
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution2 sol;
    ListNode* reversed = sol.reverseList(head);

    // Print reversed list
    ListNode* curr = reversed;
    while(curr != nullptr){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}

