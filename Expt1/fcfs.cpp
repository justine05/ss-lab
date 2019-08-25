#include<bits/stdc++.h>
using namespace std;
void print(int n, vector<int> v){
    for(int i=0;i<n;i++){
        cout << v.at(i) << "\t";
    }
    cout << "\n";
}
vector<int> cal_cmplt(int n, vector<int> process, vector<int> burst_time){
    vector<int> cmplt_time;
    int total_time = 0;
    for(int i=0;i<n;i++){
        total_time += burst_time.at(i);
        cmplt_time.push_back(total_time);
    }
    return cmplt_time;
}
float cal_avg_wait(int n, vector<int> burst_time, vector<int> cmplt_time){
    float sum = 0.0;
    for(int i=0;i<n;i++){
        sum += cmplt_time.at(i) - burst_time.at(i);
    }
    return sum/n;
}
float cal_avg_turn(int n, vector<int> burst_time, vector<int> cmplt_time){
    float sum = 0.0f;
    for(int i=0;i<n;i++){
        sum += cmplt_time.at(i);
    }
    return sum/n;
}
int main(){
    int n,p,b;
    vector<int> process, burst_time, cmplt_time,wait_time;
    cout << "Enter the number of processes: ";
    cin >> n;
    for(int i=0;i<n;i++){
        cout << "Enter process number and burst time: ";
        cin >> p >> b; 
        process.push_back(p);
        burst_time.push_back(b);
    }
    cmplt_time = cal_cmplt(n,process,burst_time);
    cout << "The process order:\t";
    print(n,process);
    cout << "The burst time:\t\t";
    print(n,burst_time);
    cout << "The turnaround time:\t";
    print(n,cmplt_time);
    cout << "The waiting time is:\t";
    for(int i=0;i<n;i++){
        wait_time.push_back(cmplt_time[i]-burst_time[i]); 
    }
    print(n,wait_time);
    cout << "The average waiting time:\t" << cal_avg_wait(n,burst_time,cmplt_time) << "\n";
    cout << "The average turnaround time:\t" << cal_avg_turn(n,burst_time,cmplt_time) << "\n";
    // draw_gantt(n,process,cmplt_time);
    return 0;
}