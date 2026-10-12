
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *oddEvenList(ListNode *head)
{
    if (!head || !head->next)
        return head;

    ListNode *odd = head, *even = head->next;
    ListNode *evenHead = even;

    while (even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return head;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;

    for (int i = 1; i < 5; i++)
    {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }

    head = oddEvenList(head);

    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}
