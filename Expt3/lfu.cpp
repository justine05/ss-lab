#include<bits/stdc++.h>
using namespace std;

int pfch[] = {3, 0};

#define max 3

void print(deque<tuple<int, int, int>> q){
    for(auto i : q){
        cout << get<2>(i) << " ";
    }
    cout << endl;
}
bool comp(tuple<int, int, int> t1, tuple<int, int, int> t2){
    if(get<0>(t1) == get<0>(t2))
        return get<1>(t1) > get<1>(t2);
    else
        return get<0>(t1) <= get<0>(t2);
}
void lfu(int n, vector<tuple<int, int>> r){
    deque<tuple<int, int, int>> q;
    deque<int>::iterator f;
    deque<tuple<int, int, int>>::iterator g;
    map<int,int> freq;
    deque<int> req;
    deque<int> pno;
    deque<int> use;
    int val, pos;
    
    for(int i=0;i<max;i++){
        q.push_back(make_tuple(get<0>(r[i]), max-i, get<1>(r[i])));
        req.push_back(get<1>(r[i]));
        freq.insert(pair<int, int>(get<1>(r[i]),1));
        sort(q.begin(), q.end(), comp);
        print(q);
    }
    for(int i=max;i<n;i++){
        if(freq[get<1>(r[i])]){
            freq[get<1>(r[i])]++;
        }
        else {
            freq.insert(pair<int, int>(get<1>(r[i]), 1));
        }
        for(int j=0;j<max;j++){
            use.push_back(get<0>(q[j]));
            pno.push_back(get<1>(q[j]));
            req.push_back(get<2>(q[j]));
        }
        f = find(req.begin(), req.end(), get<1>(r[i]));
        pos = f - req.begin();
        if(f == req.end()){
            q.pop_front();
            for(auto j : q){
                get<1>(j)++;
            }
            q.push_front(make_tuple(freq[get<1>(r[i])], 1, get<1>(r[i])));
            pfch[0]++;
        }
        else {
            g = find(q.begin(), q.end(), make_tuple(use[pos], pno[pos], req[pos]));
            get<0>(*g)++;
            for(auto j : q){
                get<1>(j)++;
            }
            pfch[1]++;
        }
        sort(q.begin(), q.end(), comp);
        req.clear();
        pno.clear();
        use.clear();
        print(q);
    }
}

int main(){
    vector<tuple<int, int>> r;
    int temp,n,ch, pf;
    cout << "Enter number of requests: ";
    cin >> n;
    cout << "Enter the request string: ";
    for(int i=0;i<n;i++){
        cin >> temp;
        r.push_back(make_tuple(1, temp));
    }
    lfu(n,r);
    pf = pfch[0];
    ch = pfch[1];
    cout << "The number of page faults is: " << pf << "\n";
    cout << "The number of cache hits is: " << ch << "\n";
    return 0;
}

//7 2 3 1 2 5 3 4 6 7 7 1 0 5 4 6 2 3 0 1