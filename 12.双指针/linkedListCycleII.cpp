#include<vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head,*fast = head;
        //首先判断是否存在环路
        do {
            if(!fast || !fast->next)return nullptr;
            fast=fast->next->next;
            slow=slow->next;
        }while (fast!=slow);
        //如果存在环路，则找到环路入口
        slow = head;
        while (slow!=fast) {
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};

int main() {
    // 创建链表：1 -> 2 -> 3 -> 4 -> 5 -> 3 (环)
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);
    ListNode* fifth = new ListNode(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third; // 创建环，连接到第三个节点

    Solution solution;
    ListNode* cycleNode = solution.detectCycle(head);

    if (cycleNode) {
        cout << "Cycle detected at node with value: " << cycleNode->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    // 为简单起见，测试完毕后不释放内存（因为存在环）
    return 0;
}