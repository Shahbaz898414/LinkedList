#include<iostream>
using namespace std;

class node {
  public:
  int data;
  node*next;

  // constructor
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

bool search(node* head,int key){
  node* temp=head;
  while(temp !=NULL){
    if(temp->data==key){
      return true;
    }
    temp=temp->next;
  }
  return false;
}

int length(node* head){
  int cnt=0;

  while(head!=NULL){
    cnt++;
    head=head->next;
  }

  return cnt;
}

void insertMiddle(node* &head,int d,int p){

  if(head==NULL or p==0){
    insertAtHead(head,d);
    return;
  }else if(p>length(head)){
    insertAtTail(head,d);
  }else{
    int jump=1;
    node* temp=head;
    while(jump<=p-1){
      temp=temp->next;  
      jump++;
    }
    node*n=new node(p);
    n->next=temp->next;
    temp->next=n;
  }
  // head=head->next;
  // node* n=new node(p);
  // n->next=temp->next;

}

void deleteAtHead(node* &head){
  node* todelete=head;
  head=head->next;
  delete todelete;
  cout<<"Head"<<endl;
}

void deletion(node* &head,int val){
  if(head==NULL){
    return;
  }
  if(head->next == NULL){
    deleteAtHead(head);
    return;
  }

  node* temp=head;
  while(temp->next->data!=val){
    temp=temp->next;
  }

  node* todelete = temp->next;
  temp->next = temp->next->next;
  delete todelete;
}

node* reverse(node* &head){
  node* prevptr=NULL;
  node* currptr=head;
  node* nextptr;
  while(currptr!=NULL){
    nextptr=currptr->next;
    currptr->next=prevptr;
    prevptr=currptr;
    currptr=nextptr;
  }

  return prevptr;
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
    insertAtHead(head,d);
    //  insertAtTail(head,d);
    // cin>>d;
  }
  
  return head;
}

int main(){

  node* head=take_Input();

  node* head2=take_Input();
  
  display(head);
  display(head2);




  // reverse(head);
  // display(head);
 /* insertAtTail(head,1);
    insertAtTail(head,2);
      insertAtTail(head,3);
      display(head);
      insertAtHead(head,4);
      display(head);

      cout<<search(head,3)<<endl;

      deletion(head,4);
      display(head);

      insertMiddle(head,5,2);
      display(head); */

   return 0;
}
