#include <windows.h>

#include <iostream>

#include "C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\um\psapi.h"
using namespace std;

size_t getProcessMemory() {
    PROCESS_MEMORY_COUNTERS_EX pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc))) {
        return pmc.WorkingSetSize;
    }
    return 0;
}

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /**
         * Note: The ListNodes in testbench has no header-node!
         *       So, we traverse list1&list2 from the first node.
         */
        auto* p1 = list1;
        auto* p2 = list2;
        auto* rtn = new ListNode();  // Here, we create a headerNode
        auto* pr = rtn;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                pr->next = p1;
                p1 = p1->next;
                pr = pr->next;
            } else {
                pr->next = p2;
                p2 = p2->next;
                pr = pr->next;
                /*
                 * **Leetcode OJ issue:
                 * Here, we use `pr = pr->next;` both in the braches of if-else,
                 * which results in about 88%-defeat for memory usage.
                 * Else, if we put this line outside the if-else, we achieve about
                 * 10%-defeat for memory usage.
                 **/
            }
        }
        ListNode* prest = p1;
        if (p1 == nullptr) prest = p2;
        pr->next = prest;
        return rtn->next;
    }
};

class Solution_recursive {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

int main() {
    auto* n0 = new ListNode(1);
    auto* n1 = new ListNode(2);
    auto* n2 = new ListNode(4);
    auto* n3 = new ListNode(1);
    auto* n4 = new ListNode(3);
    auto* n5 = new ListNode(4);
    auto* n6 = new ListNode(6);
    auto* list1 = new ListNode();
    list1 = n0;
    list1->next = n1;
    list1->next->next = n2;
    auto* list2 = new ListNode();
    list2 = n3;
    list2->next = n4;
    list2->next->next = n5;
    list2->next->next->next = n6;
    Solution s;
    auto* merged = s.mergeTwoLists(list1, list2);
    auto* p = merged->next;
    while (p != nullptr) {
        cout << p->val << " ";
        p = p->next;
    }

    cout << "Memory Usage: " << getProcessMemory() << " Bytes" << endl;

    return 0;
}