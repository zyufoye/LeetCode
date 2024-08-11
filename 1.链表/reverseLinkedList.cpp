#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList1(ListNode* head,ListNode *prev = nullptr) {
        if(!head) {
            return prev;
        }
        ListNode *next = head->next;
        head->next = prev;
        return reverseList1(next,head);
    }
    ListNode* reverseList2(ListNode* head) {
        ListNode *prev = nullptr, *next;
        while(head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
int main(){
    // 创建链表 [1, 2, 3, 4, 5]
    ListNode* node5 = new ListNode(5);
    ListNode* node4 = new ListNode(4, node5);
    ListNode* node3 = new ListNode(3, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* head = new ListNode(1, node2);
    // 创建 Solution 对象
    Solution solution;

    // 反转链表
    ListNode* reversedHead = solution.reverseList2(head);

    // 打印反转后的链表
    ListNode* current = reversedHead;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    // 释放内存（可选）
    current = reversedHead;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;

}