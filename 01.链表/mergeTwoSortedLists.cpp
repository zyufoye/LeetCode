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
    //非递归写法
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //创建一个智能指针dummy，一个工作指针node，工作指针调整链表，智能指针返回合并结果
        ListNode *dummy = new ListNode(0), *node=dummy;
        while (list1 && list2) {
            if(list1->val<=list2->val) {
                node->next=list1;
                list1=list1->next;
            }else {
                node->next=list2;
                list2=list2->next;
            }
            node=node->next;
        }
        node->next=list1?list1:list2;
        //第一个节点是node->next，所以也要返回dummy->next，其作为新链表的头节点
        return dummy->next;
    }
    //递归
    ListNode* mergeTwoLists1(ListNode* list1, ListNode* list2) {
        if(!list1) {
            return list2;
        }
        if(!list2) {
            return list1;
        }
        if(list1->val>list2->val) {
            list2->next = mergeTwoLists1(list1,list2->next);
            return list2;
        }
        list1->next = mergeTwoLists1(list1->next,list2);
        return list1;
    }
};
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // 创建第一个有序链表 [1, 3, 5]
    ListNode* node3 = new ListNode(5);
    ListNode* node2 = new ListNode(3, node3);
    ListNode* list1 = new ListNode(1, node2);

    // 创建第二个有序链表 [2, 4, 6]
    ListNode* node6 = new ListNode(6);
    ListNode* node5 = new ListNode(4, node6);
    ListNode* list2 = new ListNode(2, node5);

    // 创建 Solution 对象并合并两个链表
    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists1(list1, list2);

    // 打印合并后的链表
    cout << "Merged list: ";
    printList(mergedList);

    // 释放内存
    ListNode* current = mergedList;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}