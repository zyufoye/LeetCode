## 一、算法介绍
Floyd判圈算法用于判断链表中是否存在环，环的入口在什么位置以及环的长度。  
首先，假设起始位置到环入口的长度为l，环长为r，慢指针绕n圈，快指针绕m圈后在环上k处相遇。此时慢指针走过的路程为S=l+nxr+k，快指针走过的路程为2S=l+mxr+k，用快指针走过的路程减去慢指针路程，得到S=(m-n)r。因为m和n都是正整数，所以快慢指针相遇时走过的路程为环长的整数倍，此时要求还的入口，只需要让慢指针回到起始位置，让快指针在原地以慢指针的速度继续前进，知道两个节点再次相遇，相遇位置就是环的入口位置。因为此时快指针走了2S+l，慢指针走了l，而2S正是圈长的整数倍，所以两个节点会在环入口处相遇。
```C++
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
```