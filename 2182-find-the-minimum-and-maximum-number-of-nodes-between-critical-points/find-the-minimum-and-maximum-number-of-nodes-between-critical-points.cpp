/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;

        int i = 1;

        int prevCriticalPos = -1;
        int firstCriticalPos =-1;

        int minDist = INT_MAX;

        while(curr->next != NULL) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
    (curr->val < prev->val && curr->val < curr->next->val)) {

              // First critical point
                if (firstCriticalPos == -1) {
                    firstCriticalPos = i;
                }

                // If this is not the first critical point
                if (prevCriticalPos != -1) {
                    minDist = min(minDist, i - prevCriticalPos);
                }

                prevCriticalPos = i;
            }
            
            i++;
            prev = curr;
            curr = curr->next;
        }
        if (minDist == INT_MAX) {
            return {-1, -1};
        }
        int maxDist = prevCriticalPos- firstCriticalPos;

        return {minDist, maxDist}; 
    } 
};