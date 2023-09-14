//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printlist(Node *head)
{
	if (head==NULL)return;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void append(struct Node** headRef, char data)
{
	struct Node* new_node = new Node(data);
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

// task is to complete this function
struct Node* arrange(Node *head);

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        char tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        head = arrange(head);
        printlist(head);
    }
	return 0;
}


// } Driver Code Ends




struct Node* arrange(Node *head) {
   
   vector<char> a;
   Node *pre=head;
   int len=0;

   while(pre!=NULL){
    a.push_back(pre->data);
    pre=pre->next;
   }



   vector<char>  v;
   vector<char>  co;


   for(int i=0;i<a.size();i++){
      if(a[i]=='a' || a[i]=='e' || a[i]=='u' || a[i]=='i' || a[i]=='o'){
        v.push_back(a[i]);
      }else{
        co.push_back(a[i]);
      }
   }



   pre=head;

   int temp=0;
   int gem=0;


   while(pre!=NULL) {
    if(temp<v.size()) pre->data=v[temp++];
    else pre->data=co[gem++];

    pre=pre->next;
   }


   return head;
}
