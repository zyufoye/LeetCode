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
    bool isPalindrome(ListNode* head) {
        //定义两个快慢指针，用于分割链表
        ListNode *fast=head,*slow=head;
        if(!head || !head->next) {
            return true;
        }
        //利用快指针遍历全部链表，此时慢指针指向链表中间位置，或中间位置之前位置
        while (fast->next && fast->next->next) {
            slow= slow->next;
            fast = fast->next->next;
        }
        //此时更新完slow和fast指针位置，把慢指针之后的链表部分翻转
        ListNode *reverse_List_slow = reverseList(slow->next);
        while (reverse_List_slow) {
            if(head->val != reverse_List_slow->val) {
                return false;
            }
            reverse_List_slow = reverse_List_slow->next;
            head = head->next;
        }
        return true;
    }

    //辅助函数，用于翻转链表
    ListNode * reverseList(ListNode* head) {
        ListNode *p,*prev=nullptr;
        while (head) {
            p = head->next;
            head->next = prev;
            prev=head;
            head=p;
        }
        return prev;
    }
};
// 测试用例函数
void testIsPalindrome() {
    Solution solution;

    // Test Case 1: Empty list (not a palindrome)
    ListNode* head1 = nullptr;
    std::cout << "Test Case 1: " << (solution.isPalindrome(head1) ? "Passed" : "Failed") << std::endl;

    // Test Case 2: Single node (not a palindrome)
    ListNode* head2 = new ListNode(1);
    std::cout << "Test Case 2: " << (solution.isPalindrome(head2) ? "Passed" : "Failed") << std::endl;

    // Test Case 3: Two nodes, same value (palindrome)
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(1);
    std::cout << "Test Case 3: " << (solution.isPalindrome(head3) ? "Passed" : "Failed") << std::endl;

    // Test Case 4: Two nodes, different values (not a palindrome)
    ListNode* head4 = new ListNode(1);
    head4->next = new ListNode(2);
    std::cout << "Test Case 4: " << (solution.isPalindrome(head4) ? "Passed" : "Failed") << std::endl;

    // Test Case 5: Odd number of nodes, palindrome
    ListNode* head5 = new ListNode(1);
    head5->next = new ListNode(2);
    head5->next->next = new ListNode(1);
    std::cout << "Test Case 5: " << (solution.isPalindrome(head5) ? "Passed" : "Failed") << std::endl;

    // Test Case 6: Even number of nodes, palindrome
    ListNode* head6 = new ListNode(1);
    head6->next = new ListNode(2);
    head6->next->next = new ListNode(2);
    head6->next->next->next = new ListNode(1);
    std::cout << "Test Case 6: " << (solution.isPalindrome(head6) ? "Passed" : "Failed") << std::endl;

    // Test Case 7: Odd number of nodes, not a palindrome
    ListNode* head7 = new ListNode(1);
    head7->next = new ListNode(2);
    head7->next->next = new ListNode(3);
    std::cout << "Test Case 7: " << (solution.isPalindrome(head7) ? "Passed" : "Failed") << std::endl;

    // Test Case 8: Even number of nodes, not a palindrome
    ListNode* head8 = new ListNode(1);
    head8->next = new ListNode(2);
    head8->next->next = new ListNode(3);
    head8->next->next->next = new ListNode(4);
    std::cout << "Test Case 8: " << (solution.isPalindrome(head8) ? "Passed" : "Failed") << std::endl;
}

int main() {
    testIsPalindrome();
    return 0;
}