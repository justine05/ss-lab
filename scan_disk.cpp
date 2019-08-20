#include<bits/stdc++.h>
using namespace std;
int seek(int n, int head, vector<int> q){
    int total = 0;
    vector<int> l,r;
    for(int i=0;i<n;i++){
        if(q[i]>=head){
            r.push_back(q[i]);
        }
        else {
            l.push_back(q[i]);
        }
    }
    l.push_back(0);
    sort(l.begin(),l.end(),greater<int>());
    sort(r.begin(),r.end());    
    for(int i=0;i<l.size();i++){
        int next_val = l[i];
        cout << "Move from " << head << " to " << next_val << " with seek "<< abs(head-next_val) << "\n";
        total += abs(head-next_val);
        head = next_val;
    }
    for(int i=0;i<r.size();i++){
        int next_val = r[i];
        cout << "Move from " << head << " to " << next_val << " with seek "<< abs(head-next_val) << "\n";
        total += abs(head-next_val);
        head = next_val;
    }
    return total;
}
int main(){
    int n,head,val,s;
    vector<int> q;
    cout << "Enter the size of queue: ";
    cin >> n;
    cout << "Enter the Queue: ";
    for(int i=0;i<n;i++){
        cin >> val;
        q.push_back(val);
    }
    cout << "Enter the initial head position: ";
    cin >> head;
    s = seek(n,head,q);
    cout << "The total seek time is: " << s <<"\n";
    cout << "The total seek time is: " << float(s)/n <<"\n";
    return 0;
}