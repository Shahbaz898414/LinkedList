#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[100], n, i, num, loc;
    cin>>n;   
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin>>num;   
    cin>>loc;

    for (i = n; i >= loc; i--) {
        arr[i] = arr[i - 1];
    }
    // n++;
    arr[loc - 1] = num;
   
    for (i = 0; i <=n; i++) {
        cout << arr[i] << " ";
    }
    sort(arr,arr+n);
    cout<<endl;

    for (i = 0; i <=n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}