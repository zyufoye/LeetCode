#include <iostream>
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *l1=headA, *l2=headB;
        while(l1!=l2) {
            l1=l1?l1->next:headB;
            l2=l2?l2->next:headA;
        }
        return l1;
    }
};
void printList(ListNode *head) {
    while (head) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main() {
    // 创建相交部分链表 [8 -> 10]
    ListNode* common1 = new ListNode(8);
    ListNode* common2 = new ListNode(10, common1);

    // 创建第一个链表 [3 -> 6 -> 9 -> 8 -> 10]
    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(6);
    headA->next->next = new ListNode(9, common2);

    // 创建第二个链表 [4 -> 8 -> 10]
    ListNode* headB = new ListNode(4, common2);

    // 打印两个链表
    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    // 创建 Solution 对象
    Solution solution;

    // 查找交点
    ListNode* intersection = solution.getIntersectionNode(headA, headB);

    // 打印结果
    if (intersection) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection found." << endl;
    }

    //释放内存

    return 0;
}
