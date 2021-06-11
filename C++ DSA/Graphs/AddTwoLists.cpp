#include<bits/stdc++.h>
using namespace std;
class ListNode{
public: 
    int val = 0;
    ListNode* next = NULL;
    ListNode(int val){
        this->val = val;
    }
};
void displayLL(ListNode* head){
    if(!head) return;
    while(head != NULL){
        cout<<head->val<<"->";
        head = head->next;
    }
    cout<<endl;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* p1;
        ListNode* p2;
        p1 = l1;
        p2 = l2;
        ListNode *head = NULL;
        ListNode *ptr = NULL;
        int c = 0;
        while(p1 && p2){
            if(!head){
                head = ptr = new ListNode((p1->val + p2->val)%10);
            }
            else{
                ListNode* nn = new ListNode((p1->val + p2->val + c)%10);
                ptr->next = nn;
                ptr = nn;
            }
            if(p1->val + p2->val + c >= 10)
                c = 1;
            else 
                c = 0;
            p1 = p1->next;
            p2 = p2->next;
        }
        if(!p1 && !p2 && c == 1){
            ListNode* nn = new ListNode(1);
            ptr->next = nn;
            ptr = nn;
            return head;
        }
        int c1 = c;
        int c2 = c;
        if(p1){
            while(p1){
                ListNode* nn = new ListNode((p1->val + c1)%10);
                ptr->next = nn;
                ptr = nn;
                if(p1->val + c1 >= 10)
                    c1 = 1;
                else 
                    c1 = 0;
                p1 = p1->next; 
            }
            if(c1 == 1){
                ListNode* nn = new ListNode(1);
                ptr->next = nn;
                ptr = nn;
            }
            return head;
        }
            while(p2){
                ListNode* nn = new ListNode((p2->val + c2)%10);
                ptr->next = nn;
                ptr = nn;
                if(p2->val + c2 >= 10)
                    c2 = 1;
                else
                    c2 = 0;
                p2 = p2->next; 
            }
            if(c2 == 1){
                ListNode* nn = new ListNode(1);
                ptr->next = nn;
                ptr = nn;
            }
        return head;
    }
ListNode* addFirst(vector<int> v){
    ListNode* head;
    for (int i = 0; i < v.size(); ++i)
    {
        ListNode* temp = new ListNode(v[i]);
        if(i == 0){
            head = temp;
            head->next = NULL;
        }
        else{
            temp->next = head;
            head = temp;
        }
    }
    return head;
}
ListNode* addLast(vector<int> v){
    ListNode* head;
    ListNode* tail;
    for (int i = 0; i < v.size(); ++i)
    {
        ListNode* temp = new ListNode(v[i]);
        if(i == 0){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}
int main(){
    int n1;
    cin>>n1;
    vector<int> v1(n1);
    for (int i = 0; i < n1; ++i)
    {
        cin>>v1[i];
    }
    int n2;
    cin>>n2;
    vector<int> v2(n2);
    for (int i = 0; i < n2; ++i)
    {
        cin>>v2[i];
    }
    ListNode* head1 = addFirst(v1);
    ListNode* head2 = addLast(v2);
    ListNode* head = addTwoNumbers(head1,head2);
    displayLL(head);
    return 0;
}