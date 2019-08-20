#include<bits/stdc++.h>
using namespace std;
void print(int n, vector<int> v){
    for(int i=0;i<n;i++){
        cout << v.at(i) << "\t";
    }
    cout << "\n";
}
vector<int> cal_cmplt(int n, vector<int> process, vector<int> burst_time, int q){
    vector<int> cmplt_time(n,0);
    vector<int> done(n,0);
    int time = 0;
    int total_time = 0;
    int max_time = accumulate(burst_time.begin(),burst_time.end(),0);
    while(total_time != max_time){
        for(int i=0;i<q;i++){
            if(done.at(i) != burst_time.at(i)){
                if(cmplt_time.at(i) != 0){
                    continue;
                }
                done.at(i) += 3;
                total_time += 3;
                if(done.at(i) == burst_time.at(i)){
                    cmplt_time.at(i) = total_time;
                }
            }
        }
    }
    return cmplt_time;
}
// void draw_gantt(int n, vector<int> process, vector<int> cmplt_time){
//     float scale = 0.75;
//     int nu = 0;
//     for(int i=0;i<cmplt_time.back()/scale;i++)
//         cout << "- ";
//     cout << "\n";
//     for(int i=0;i<cmplt_time.back()/scale;i++){
//         if(i==0){
//             cout << "|";
//         }
//         else if(i==(cmplt_time.at(nu)/(scale*2))){
//             cout << "P" << process.at(nu) << "(" << cmplt_time.at(nu) << ")";
//             continue;
//         }
//         else if(i==cmplt_time.at(nu)/scale){
//             cout << "|";
//             nu++;
//         }
//         else {
//             cout << "  ";
//         }
//     } 
//     cout << "|\n";      
//     for(int i=0;i<cmplt_time.back()/scale;i++)
//         cout << "- ";
//     cout << "\n";    
// }
float cal_avg_wait(int n, vector<int> burst_time, vector<int> cmplt_time){
    float sum = 0;
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
    int n,p,b,q;
    vector<int> process, burst_time, cmplt_time;
    cout << "Enter the number of processes: ";
    cin >> n;
    for(int i=0;i<n;i++){
        cout << "Enter process number and burst time: ";
        cin >> p >> b; 
        process.push_back(p);
        burst_time.push_back(b);
    }
    cout << "Enter time quantum: ";
    cin >> q;
    cmplt_time = cal_cmplt(n,process,burst_time,q);
    cout << "The process order:\t";
    print(n,process);
    cout << "The burst time:\t\t";
    print(n,burst_time);
    cout << "The complete time:\t";
    print(n,cmplt_time);
    cout << "The average waiting time:\t" << cal_avg_wait(n,burst_time,cmplt_time) << "\n";
    cout << "The average turnaround time:\t" << cal_avg_turn(n,burst_time,cmplt_time) << "\n";
    // draw_gantt(n,process,cmplt_time);
    return 0;
}