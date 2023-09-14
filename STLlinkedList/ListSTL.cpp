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


int main(){

  list<int> l;

  list<int> l1{1,2,3,10,8,5};

  // different Datatype
  list<string> l2{"apple","guave","mango","banana"};
  l2.push_back("Pineapple");
  l2.push_back("jkdsjksk");
  l2.push_back("djjkdks");

  for(auto s:l2){
    cout<<s<<" ";
  }
  cout<<endl;

  // sort
  l2.sort();


  for(auto s:l2){
    cout<<s<<" ";
  }
  cout<<endl;

  // front element
  // cout<<l2.front()<<endl;
  // cout<<l2.back()<<endl;
  // l2.pop_front();

  // l2.push_front("Kiwi");
  // l2.pop_back();



  l2.reverse();

  for(auto s:l2){
    cout<<s<<" ";
  }

  // some more functions in the list

  // remove a fruit
  string s;cin>>s;
  l2.remove(s);
  // all the occurences of that fruit remove by "remove" function

  // we can also remove some perticular index and one or more elements at ones

  auto it= l2.begin();
  it++;it++;
  // we need to increase the value of 
  l2.erase(it);

  // insert the element in the list
  it= l2.begin();it++;
  l2.insert(it,"Fruitjuice"); // remember parameters

   return 0;
}

