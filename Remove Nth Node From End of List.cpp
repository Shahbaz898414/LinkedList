#include <iostream>
using namespace std;

class ListNode
{
public:
  int val;
  ListNode *next;

  // constructor
  ListNode(int d)
  {
    val = d;
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
    cout << temp->val << " ->";
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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    struct ListNode *temp = head;

    int len = 0;

    while (temp != NULL)
    {
      temp = temp->next;
      len++;
    }

    if (n > len)
    {
      return NULL;
    }

    if (len - n == 0)
    {
      head = head->next;
      return head;
    }

    struct ListNode *pre = head;

    temp = head;

    for (int i = 0; i < len - n; i++)
    {
      pre = temp;
      temp = temp->next;
    }
    pre->next = temp->next;
    return head;
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
