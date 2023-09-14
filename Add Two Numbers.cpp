#include <iostream>
using namespace std;

class ListNode
{
public:
  int data;
  ListNode *next;

  // constructor
  ListNode(int d)
  {
    data = d;
    next = NULL;
  }
};

void insertAtHead(ListNode *&head, int val)
{
  ListNode *n = new ListNode(val);
  n->next = head;
  head = n;
}
void insertAtTail(ListNode *&head, int val)
{
  ListNode *n = new ListNode(val);

  if (head == NULL)
  {
    head = n;
    return;
  }
  ListNode *temp = head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = n;
}

void display(ListNode *head)
{
  ListNode *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ->";
    temp = temp->next;
  }
  cout << endl;
}

ListNode *take_Input()
{
  int d;
  ListNode *head = NULL;

  while (cin >> d)
  {
    insertAtHead(head, d);
    //  insertAtTail(head,d);
    // cin>>d;
  }

  return head;
}

ListNode *take_Input_file()
{
  int d;
  cin >> d;
  ListNode *head = NULL;

  while (d != -1)
  {
    insertAtHead(head, d);
    //  insertAtTail(head,d);
    cin >> d;
  }

  return head;
}
// void operator<<(ostream &os,ListNode*head){
//   display(head);
//   return;
// }

ostream &operator<<(ostream &os, ListNode *head)
{
  display(head);
  return os;
}

istream &operator>>(istream &is, ListNode *&head)
{
  head = take_Input_file();
  return is;
}

class Solution
{
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *l3 = new ListNode(0);
    int cnt = 0;
    ListNode *head = l3;

    while (l1 and l2)
    {
      int value = l1-> val + l2-> val + cnt;
      cnt = value / 10;
      l3->next = new ListNode(value % 10);
      l3 = l3->next;
      l2 = l2->next;
      l1 = l1->next;
    }

    while (l1)
    {
      int value = l1-> val + cnt;
      cnt = value / 10;
      l3->next = new ListNode(value % 10);
      l3 = l3->next;
      // l2=l2->next;
      l1 = l1->next;
    }

    while (l2)
    {
      int value = l2-> val + cnt;
      cnt = value / 10;
      l3->next = new ListNode(value % 10);
      l3 = l3->next;
      l2 = l2->next;
      // l1=l1->next;
    }

    if (cnt)
      l3->next = new ListNode(cnt);

    return head->next;
    // return head->next;
  }
};

int main()
{

  // node* head=take_Input_file();
  // node* head2=take_Input();

  ListNode *head;
  ListNode *head2;
  cin >> head >> head2;
  cout << head << head2;

  // cout<<head;
  // cout<<endl;
  // cout<<head2;
  return 0;
}
