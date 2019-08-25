#include<bits/stdc++.h>
using namespace std;
void print(int n, vector<int> v){
    for(int i=0;i<n;i++){
        cout << v.at(i) << "\t";
    }
    cout << "\n";
}
void srt(int n, vector<int> &process, vector<int> &burst_time, vector<int> &arrival_time){
    int temp,pos;
    for(int i=0;i<n-1;i++){
        pos = i;
        for(int j=i;j<n;j++){
            if(arrival_time.at(j)<arrival_time.at(pos)){
                pos = j;
            }
        }
        temp = arrival_time.at(pos);
        arrival_time.at(pos) = arrival_time.at(i);
        arrival_time.at(i) = temp;
        temp = process.at(pos);
        process.at(pos) = process.at(i);
        process.at(i) = temp;
        temp = burst_time.at(pos);
        burst_time.at(pos) = burst_time.at(i);
        burst_time.at(i) = temp;
    }
}
vector<int> order(int n, vector<int> process, vector<int> burst_time, vector<int> arrival_time, int q){
    int count = 0;
    vector<int> rem_time = burst_time;
    vector<int> order;
    while(accumulate(rem_time.begin(),rem_time.end(),0) != 0){
        
    }
}
int main(){
    int p, a, b, q;
    vector<int> cmplt_time;
    vector<int> burst_time, arrival_time, process, wait_time, order;
    cout << "Enter the number of processes: ";
    cin >> p;
    for(int i=0;i<p;i++){
        cout << "Enter arrival time and burst time for process " << i + 1 << ":";
        cin >> a >> b;
        burst_time.push_back(b);
        arrival_time.push_back(a);
        process.push_back(i+1);
    }
    cout << "Enter the time quantum: ";
    cin >> q;
    srt(p,process,burst_time,arrival_time);
    //order = comp_order(p,process,burst_time,arrival_time);
    //cmplt_time = cal_cmplt(p,order,burst_time);
    cout << "The process order:\t";
    print(p,order);
    cout << "The arrival time:\t";
    print(p,arrival_time);
    cout << "The burst time:\t\t";
    print(p,burst_time);
    cout << "The turnaround time:\t";
    print(p,cmplt_time);
    cout << "The waiting time is:\t";
    for(int i=0;i<p;i++){
        wait_time.push_back(cmplt_time[i]-burst_time[order[i]-1] - arrival_time[order[i]-1]); 
    }
    print(p,wait_time);
    //cout << "The average waiting time:\t" << cal_avg(p,wait_time) << "\n";
    //cout << "The average turnaround time:\t" << cal_avg(p,cmplt_time) << "\n";
    //gantt(p,order,cmplt_time,burst_time);
    return 0;
}