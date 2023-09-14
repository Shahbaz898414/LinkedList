//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  char data;
  struct Node *next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};

void printlist(Node *head)
{
  if (head == NULL)
    return;
  while (head != NULL)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

void append(struct Node **headRef, char data)
{
  struct Node *new_node = new Node(data);
  struct Node *last = *headRef;

  if (*headRef == NULL)
  {
    *headRef = new_node;
    return;
  }
  while (last->next != NULL)
    last = last->next;
  last->next = new_node;
  return;
}




struct Node *removeNthFromEnd(Node *head,int n);









int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n,k; char tmp;
    struct Node *head = NULL;
    cin >> n>>k;
    while (n--) {
      cin >> tmp;
      append(&head, tmp);
    }


    head = removeNthFromEnd(head,k);
    printlist(head);


  }

  return 0;
}








Node *removeNthFromEnd(Node *head, int n) {


  struct Node *temp = head;

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



  struct Node *pre = head;

  temp = head;


  for (int i = 0; i < len - n; i++) {
    pre = temp;
    temp = temp->next;
  }


  pre->next = temp->next;


  return head;



}