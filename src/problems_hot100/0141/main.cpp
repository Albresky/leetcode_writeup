#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> set;
        ListNode *p = head;
        while (p != nullptr) {
            if (set.count(p)) return true;
            set.insert(p);
            p = p->next;
        }
        return false;
    }
};

class Solution_floyd {
   public:
    bool hasCycle(ListNode *head) {
        ListNode *s = head, *f = head;
        do {
            if (f == nullptr || f->next == nullptr) return false;
            s = s->next;
            f = f->next->next;
        } while (s != f);
        return true;
    }
};

int main() {
    Solution_floyd s;
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    head->next = second;
    second->next = third;
    third->next = head;  // Creating a cycle for testing
    cout << (s.hasCycle(head) ? "Cycle detected" : "No cycle detected") << endl;
}