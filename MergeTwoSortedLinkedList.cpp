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
    insertAtHead(head,d);
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


node* MergeTwosortedLinkList(node* a,node* b){
  if(a==NULL){
    return b;
  }
  if(b==NULL){
    return a;
  }
  node*c;
  if(a->data < b->data){
    c=a;
    c->next=MergeTwosortedLinkList(a->next,b);
  }else{
    c=b;
    c->next=MergeTwosortedLinkList(a,b->next);
  }
  return c;
}

int main(){

  node* head;
  node* head2;
  cin>>head>>head2;
 
  cout<<head<<head2;

  node * newhead =MergeTwosortedLinkList(head,head2);
    cout<<newhead<<endl;
   return 0;
}

