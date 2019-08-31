#include<bits/stdc++.h>
using namespace std;

int pfch[] = {0, 0};

#define max 3

void print(deque<int> q){
    for(auto i : q){
        cout << i << " ";
    }
    cout << endl;
}

void lru(int n, vector<int> r){
    deque<int> q;
    int temp;
    deque<int>::iterator f;
    for(int i=0;i<max;i++){
        q.push_back(r[i]);
        print(q);
        pfch[0]++;
    }
    for(int i=max;i<n;i++){
        if(find(q.begin(),q.end(),r[i]) == q.end()){
            q.pop_front();
            q.push_back(r[i]);
            pfch[0]++;
        }
        else if (find(q.begin(), q.end(), r[i]) != q.end() && find(q.begin(), q.end(), r[i]) != q.end()-1 )
        {
            f = find(q.begin(), q.end(), r[i]);
            temp = *f;
            *f = *(f+1);
            *(f+1) = temp;
            pfch[1]++;
        }
        else {
            pfch[1]++;
        }
        
        print(q);
    }
}

int main(){
    vector<int> r;
    int temp,n,ch, pf;
    cout << "Enter number of requests: ";
    cin >> n;
    cout << "Enter the request string: ";
    for(int i=0;i<n;i++){
        cin >> temp;
        r.push_back(temp);
    }
    lru(n,r);
    pf = pfch[0];
    ch = pfch[1];
    cout << "The number of page faults is: " << pf << "\n";
    cout << "The number of cache hits is: " << ch << "\n";
    return 0;
}

//7 2 3 1 2 5 3 4 6 7 7 1 0 5 4 6 2 3 0 1