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
    int total =0;
    vector<int> rem_time = burst_time;
    vector<int> order;
    while(accumulate(rem_time.begin(),rem_time.end(),0) != 0){
        for(int i=0;i<n;i++){
            if(arrival_time[i] <= total){
                if(rem_time[i] >= q){
                    rem_time[i] -= q;
                    total += q;
                    order.push_back(process[i]);
                }
                else if(rem_time[i] < q && rem_time[i] != 0)
                {
                    total += rem_time[i];
                    rem_time[i] = 0;
                    order.push_back(process[i]);
                }
            }
        }
    }
    return order;
}
vector<int> cal_cmplt(int n, vector<int> order, vector<int> burst_time, vector<int> arrival_time, int q){
    int count = 0;
    int total =0;
    vector<int> rem_time = burst_time;
    vector<int> cmplt_time(n,0), time;
    for(int i=0;i<order.size();i++){
        if(rem_time[order[i]-1] >= q){
            rem_time[order[i]-1] -= q;
            total += q;
            cmplt_time[order[i]-1] = total;
        }
        else if (rem_time[order[i]-1] < q && rem_time[order[i]-1] != 0)
        {
            total += rem_time[order[i]-1];
            rem_time[order[i]-1] -= rem_time[order[i]-1];
            cmplt_time[order[i]-1] = total;
        }
        
    }
    return cmplt_time;
}
vector<int> cal_cmplt(int n, vector<int> order, vector<int> burst_time){
    vector<int> cmplt_time;
    int total_time = 0;
    for(int i=0;i<n;i++){
        total_time += burst_time.at(order[i]-1);
        cmplt_time.push_back(total_time);
    }
    return cmplt_time;
}
float cal_avg(int n, vector<int> cmplt_time){
    float sum = 0.0f;
    for(int i=0;i<n;i++){
        sum += cmplt_time.at(i);
    }
    return sum/n;
}
void gantt(int n, vector<int> process, vector<int> cmplt_time, vector<int> burst_time, int q){
    int count = 0;
    int scale = 1;
    int total = 0;
    cout << "\n|";
    while(count < process.size()){
        if(burst_time[process[count]-1] >= q){
            burst_time[process[count]-1] -= q;
            total += q;
        }
        else if (burst_time[process[count]-1] < q && burst_time[process[count]-1] != 0)
        {
            total += burst_time[process[count]-1];
            burst_time[process[count]-1] -= burst_time[process[count]-1];
        }
        for(int i=0;i<2*scale;i++)
            cout << "  ";
        cout << "P" << process[count] << "(" << total << ")";
        for(int i=0;i<2*scale;i++)
            cout << "  ";
        cout << "|";
        count++;
    }
    cout << "\n\n";
}
int main(){
    int p, a, b, q;
    vector<int> cmplt_time;
    vector<int> burst_time, arrival_time, process, wait_time, o;
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
    o = order(p, process, burst_time, arrival_time, q);
    cmplt_time = cal_cmplt(p,o,burst_time,arrival_time,q);
    cout << "The given processes:\t";
    print(p,process);
    cout << "The arrival time:\t";
    print(p,arrival_time);
    cout << "The burst time:\t\t";
    print(p,burst_time);
    cout << "The turnaround time:\t";
    print(p,cmplt_time);
    cout << "The waiting time is:\t";
    for(int i=0;i<p;i++){
        wait_time.push_back(cmplt_time[i]-burst_time[o[i]-1] - arrival_time[o[i]-1]); 
    }
    print(p,wait_time);
    cout << "The average waiting time:\t" << cal_avg(p,wait_time) << "\n";
    cout << "The average turnaround time:\t" << cal_avg(p,cmplt_time) << "\n";
    gantt(p,o,cmplt_time,burst_time,q);
    return 0;
}