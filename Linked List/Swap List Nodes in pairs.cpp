/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    
    if(A == NULL || A -> next == NULL){
        return A;
    }
    ListNode *temp = A;
    
    int cnt = 0;
    while(temp != NULL){
        temp = temp -> next;
        cnt++;
    }
    
    ListNode *temp1 = NULL, *temp2 = A, *temp3 = A-> next, *temp4, *temp5;
    
    int count = 1,sum;
    
    while(count!=2){
        temp2 -> next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3 -> next;
        count++;
    }
  
    temp2 -> next = temp1;
    temp4 = A;
    A = temp2;
    temp5 = temp3;
    sum = 1;
  
    while(sum != cnt/2){
        count = 1;
        temp1 = NULL;
        temp2 = temp3;
        temp3 = temp3 -> next;
        while(count != 2){
            temp2 -> next = temp1;
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp3 -> next;
            count++;
        }
        temp2-> next = temp1;
        temp4 -> next = temp2;
        temp4 = temp5;
        temp5 = temp3;
        sum++;
    }
    temp4-> next = temp5; //To handle the case when the number of elements in the list are not even
    return A;
}