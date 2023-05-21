#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int reverseList(int ans, ListNode *slow, ListNode *prev, ListNode *end)
    {
        if (prev->next->next == end)
        {
            if ((slow->val + prev->next->val) > ans)
            {
                ans = slow->val + prev->next->val;
            }
            cout << slow->val + prev->next->val;
            return ans;
        };
        ListNode *start = prev->next;
        ListNode *curr = prev->next;
        ListNode *tailPrev = start;
        while (curr->next != end)
        {
            tailPrev = curr;
            curr = curr->next;
        };
        if (start->next == curr)
        {
            ListNode *tmp;
            tmp = curr->next;
            prev->next = curr;
            curr->next = tailPrev;
            tailPrev->next = tmp;
            if ((slow->val + curr->val) > ans)
            {
                ans = slow->val + curr->val;
            }
            cout << slow->val + curr->val;
        }
        else
        {
            ListNode *tmp;
            tmp = curr;
            tmp = curr->next;
            prev->next = curr;
            curr->next = start->next;
            tailPrev->next = start;
            start->next = tmp;
            if ((slow->val + curr->val) > ans)
            {
                ans = slow->val + curr->val;
            }
            int temp;
            temp = reverseList(ans, slow->next, curr, start);
            cout << slow->val + curr->val;

            if (ans < temp)
            {
                ans = temp;
            };
        };
        return ans;
    };
    int pairSum(ListNode *head)
    {
        ListNode *slow, *fast, *mid, *start, *end;

        slow = head;
        fast = head->next;
        if (fast->next == nullptr)
        {
            return slow->val + fast->val;
        };
        while (fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        };

        // mid = slow->next;
        // slow = head;
        // int ans = 0;
        // while (mid != nullptr)
        // {
        //     int tmp;
        //     tmp = (mid->val + slow->val);
        //     if (tmp > ans)
        //     {
        //         ans = tmp;
        //     }
        //     slow = slow->next;
        //     mid = mid->next;
        // };
        return reverseList(0, head, slow, nullptr);
    }
};

int main()
{
    ListNode n4 = ListNode(1, nullptr);
    ListNode n3 = ListNode(2, &n4);
    ListNode n2 = ListNode(4, &n3);
    ListNode n1 = ListNode(5, &n2);
    Solution solObj;
    cout << solObj.pairSum(&n1);
}