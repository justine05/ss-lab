#include<bits/stdc++.h>
using namespace std;

#define max 3

int pfch[] = {0, 0};

void lfu(int n, vector<int> r){
    vector<int> cache;
    map<int, int> freq, age;
    vector<int> pno;
    for(auto i: r){
        if(cache.size() < max){
            transform(age.begin(), age.end(), age.begin(), [](pair<int, int> x){return make_pair(x.first, x.second+1);});
            cache.push_back(i);
        }
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
    lfu(n,r);
    pf = pfch[0];
    ch = pfch[1];
    cout << "The number of page faults is: " << pf << "\n";
    cout << "The number of cache hits is: " << ch << "\n";
    return 0;
}

//7 2 3 1 2 5 3 4 6 7 7 1 0 5 4 6 2 3 0 1