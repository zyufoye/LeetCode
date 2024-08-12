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
    //链表1
    ListNode *node4 = new ListNode(4,nullptr);
    ListNode *node3 = new ListNode(3,node4);
    ListNode *node2 = new ListNode(2,node3);
    ListNode *head1 = new ListNode(1,node2);

    //链表2
    ListNode *node31 = new ListNode(6,node4);
    ListNode *node21 = new ListNode(5,node31);
    ListNode *head2 = new ListNode(7,node21);

    //释放内存

    while (current!=nullptr) {
        ListNode *next = current->next;
        delete(current);
        current = next;
    }
    return 0;
}
