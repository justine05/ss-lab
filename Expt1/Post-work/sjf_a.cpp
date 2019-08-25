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
vector<int> comp_order(int n, vector<int> process, vector<int> burst_time, vector<int> arrival_time){
    int total_time = 0;
    vector<int> order(n,0);
    int pos = 0;
    int small, count = 0;
    while (count < n)
    {
        int small = INT_MAX;
        for (int i = 0; i < n; i++)
        {   if(find(order.begin(), order.end(), i+1) != order.end())
                continue;
            if(burst_time[i] < small && arrival_time[i] <= total_time){
                small = burst_time[i];
                pos = i;
            }
        }
        total_time += burst_time[pos];
        order[count] = process[pos];
        count++;
    }
    return order;
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
void gantt(int n, vector<int> process, vector<int> cmplt_time, vector<int> burst_time){
    int count = 0;
    int scale = 1;
        cout << "\n|";
    while(count < 5){
        for(int i=0;i<(burst_time[process[count]-1]*scale)/2+1;i++)
            cout << "  ";
        cout << "P" << process[count] << "(" << cmplt_time[count] << ")";
        for(int i=0;i<(burst_time[process[count]-1]*scale)/2+1;i++)
            cout << "  ";
        cout << "|";
        count++;
    }
    cout << "\n\n";
}
int main() {
    int p, a, b;
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
    srt(p,process,burst_time,arrival_time);
    order = comp_order(p,process,burst_time,arrival_time);
    cmplt_time = cal_cmplt(p,order,burst_time);
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
    cout << "The average waiting time:\t" << cal_avg(p,wait_time) << "\n";
    cout << "The average turnaround time:\t" << cal_avg(p,cmplt_time) << "\n";
    gantt(p,order,cmplt_time,burst_time);
    return 0;
}