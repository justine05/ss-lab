#include<bits/stdc++.h>
using namespace std;
int seek(int n, int head, queue<int> q){
    int total = 0;
    for(int i=0;i<n;i++){
        int next_val = q.front();
        q.pop();
        cout << "Move from " << head << " to " << next_val << " with seek "<< abs(head-next_val) << "\n";
        total += abs(head-next_val);
        head = next_val;
    }
    return total;
}
int main(){
    int n,head,val,s;
    queue<int> q;
    cout << "Enter the size of queue: ";
    cin >> n;
    cout << "Enter the Queue: ";
    for(int i=0;i<n;i++){
        cin >> val;
        q.push(val);
    }
    cout << "Enter the initial head position: ";
    cin >> head;
    s = seek(n,head,q);
    cout << "The total seek time is: " << s <<"\n";
    cout << "The total seek time is: " << float(s)/n <<"\n";
    return 0;
}