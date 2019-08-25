#include<bits/stdc++.h>
using namespace std;
void print(int n, vector<int> v){
    for(int i=0;i<n;i++){
        cout << v.at(i) << "\t";
    }
    cout << "\n";
}
void gantt(int n, vector<int> process, vector<int> cmplt_time, vector<int> burst_time){
    int count = 0;
    int scale = 1;
        cout << "\n|";
    while(count < 5){
        for(int i=0;i<(burst_time[count]*scale)/2+1;i++)
            cout << "  ";
        cout << "P" << process[count] << "(" << cmplt_time[count] << ")";
        for(int i=0;i<(burst_time[count]*scale)/2+1;i++)
            cout << "  ";
        cout << "|";
        count++;
    }
    cout << "\n\n";
}
vector<int> cal_cmplt(int n, vector<int> process, vector<int> burst_time, vector<int> arrival_time){
    vector<int> cmplt_time;
    int total_time = 0;
    for(int i=0;i<n;i++){
        if(arrival_time[i]<=total_time){
            total_time += burst_time.at(i);
            cmplt_time.push_back(total_time);
        }   
    }
    return cmplt_time;
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
float cal_avg_wait(int n, vector<int> burst_time, vector<int> cmplt_time, vector<int> arrival_time){
    float sum = 0.0;
    for(int i=0;i<n;i++){
        sum += cmplt_time.at(i) - burst_time.at(i) - arrival_time[i];
    }
    return sum/n;
}
float cal_avg_turn(int n, vector<int> burst_time, vector<int> cmplt_time, vector<int> arrival_time){
    float sum = 0.0f;
    for(int i=0;i<n;i++){
        sum += cmplt_time.at(i) - arrival_time[i];
    }
    return sum/n;
}
int main(){
    int p, a, b;
    vector<int> cmplt_time;
    vector<int> burst_time, arrival_time, process, wait_time;
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
    cmplt_time = cal_cmplt(p,process,burst_time,arrival_time);
    cout << "The process order:\t";
    print(p,process);
    cout << "The arrival time:\t";
    print(p,arrival_time);
    cout << "The burst time:\t\t";
    print(p,burst_time);
    cout << "The turnaround time:\t";
    print(p,cmplt_time);
    cout << "The waiting time is:\t";
    for(int i=0;i<p;i++){
        wait_time.push_back(cmplt_time[i]-burst_time[i] - arrival_time[i]); 
    }
    print(p,wait_time);
    cout << "The average waiting time:\t" << cal_avg_wait(p,burst_time,cmplt_time,arrival_time) << "\n";
    cout << "The average turnaround time:\t" << cal_avg_turn(p,burst_time,cmplt_time,arrival_time) << "\n";
    gantt(p,process,cmplt_time,burst_time);
    return 0;
}