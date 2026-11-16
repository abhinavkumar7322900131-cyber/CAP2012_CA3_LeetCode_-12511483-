// LeetCode Problem 23
// Title: Merge k Sorted Lists
// Difficulty: Hard

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<ListNode*, vector<ListNode*>, 
        function<bool(ListNode*, ListNode*)>> pq(
            [](ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        );

        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }

        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (!pq.empty()) {
            ListNode* temp = pq.top();
            pq.pop();

            curr->next = temp;
            curr = curr->next;

            if (temp->next != nullptr) {
                pq.push(temp->next);
            }
        }

        return dummy.next;
    }
};