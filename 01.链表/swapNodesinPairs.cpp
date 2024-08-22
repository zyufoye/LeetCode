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
    //交换链表中两个相邻节点，要求不修改节点内部值，只进行节点交换
    ListNode* swapPairs(ListNode* head) {
        //定义两个指向节点的指针，p被初始化为链表头节点，s为工作节点，指定s为每次交换的后一个节点
        ListNode *p=head,*s;
        //首先判断链表中是否存在两个可以交换的节点
        if( p && p->next) {
            s = p->next;
            p->next = s->next;
            s->next = p;
            head = s;
            //确定接下来有两个节点需要调换位置
            while (p->next && p->next->next) {
                s = p->next->next;
                p->next->next = s->next;
                s->next = p->next;
                p->next = s;
                p = s->next;
            }
        }
        return head;
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
    ListNode *node4 = new ListNode(4,nullptr);
    ListNode *node3 = new ListNode(3,node4);
    ListNode *node2 = new ListNode(2,node3);
    ListNode *head = new ListNode(1,node2);
    printList(head);

    Solution solution;
    ListNode *SwapNodeinPairs = solution.swapPairs(head);

    printList(SwapNodeinPairs);

    //释放内存
    ListNode* current = SwapNodeinPairs;
    while (current!=nullptr) {
        ListNode *next = current->next;
        delete(current);
        current = next;
    }
    return 0;
}