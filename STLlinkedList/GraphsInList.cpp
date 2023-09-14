#include<bits/stdc++.h>
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


int main() {

  // List of create a Graph Data Structure
  list<pair<int,int>> *l;
  int n;cin>>n;

  l =new list<pair<int,int>> [n];

  int e;cin>>e;
  for (int i = 0; i <e; i++)
  {
    int x,y,z;
    cin>>x>>y>>z;
    l[x].push_back(make_pair(y,z));
    l[y].push_back(make_pair(x,z));

  }
  

  for (int i = 0; i < n; i++)
  {
    cout<<"Linked List"<<i<<"->";
   for(auto xp:l[i]){
     cout<<"("<<xp.first<<","<<xp.second<<"),";
   }
   cout<<endl;
  }
  



  

    return 0;
}