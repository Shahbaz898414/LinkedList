#include<iostream>
using namespace std;

class node {
  public:
  int data;
  node*next;
    
  node(int d){
    data=d;
    next=NULL;
  }
};

void insertAtHead(node* &head,int val){
  node* n = new node(val);
  n->next = head;
  head = n;
}
void insertAtTail(node* &head,int val){
  node* n=new node(val);

  if(head==NULL){
    head=n;
    return;
  }
  node*temp = head;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=n;
}


void display(node* head){
  node* temp=head;
  while(temp!=NULL){
    cout<< temp->data << " ->";
    temp=temp->next;
  }
  cout << endl;
}


node* reverseRecursion(node* &head){
  if(head ==NULL || head->next==NULL){
    return head;
  }

  node* newhead =reverseRecursion(head->next);
  head->next->next=head;
  head->next=NULL;
  return newhead;
}

node* take_Input(){
  int d;
  node* head=NULL;

  while(cin>>d){
    // insertAtHead(head,d);
     insertAtTail(head,d);
    // cin>>d;
  }
  
  return head;
}

node* take_Input_file(){
  int d;
  cin>>d;
  node* head=NULL;
  while(d!=-1){
    insertAtTail(head,d);
    cin>>d;
  }
  
  return head;
}

ostream& operator<<(ostream &os,node* head){
  display(head);
  return os;
}

istream& operator>>(istream &is,node*& head){
  head = take_Input_file();
  return is;
}


void reverse(node* &head){
  node* P=NULL;
  node* C=head;
  node* N;
  while(C!=NULL){
    N=C->next;
    C->next=P;
    P=C;
    C=N;
  }
  head=P;
}

node* midpoint(node*head){
  if(head==NULL or head->next==NULL){
    return head;
  } 

  node*slow =head;
  node*fast=head->next;
  while(fast->next!=NULL and fast!=NULL){
    fast=fast->next->next;
    slow=slow->next;
  }
  return slow;
}
//   find one more member for team I had a plan 
int main(){
  node* head;
  node* head2;
  cin>>head>>head2;
  cout<<head<<head2;
  // cout<<head2;
  //    node* mid = midpoint(head);
  // cout<<mid->data<<endl;
   return 0;
}
