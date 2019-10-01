#include<bits/stdc++.h>
#include<unistd.h>
#include<semaphore.h>
using namespace std;

#define N 5 
#define THINKING 2 
#define HUNGRY 1 
#define EATING 0 
#define LEFT (pno + 4) % N 
#define RIGHT (pno + 1) % N 

sem_t mutex;
sem_t S[N];

int state[N];
int p[] = {0, 1, 2 , 3, 4};

void test(int pno){
    if(state[pno] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != HUNGRY){
        state[pno] = EATING;
    }
}
int main(){
    
    return 0;
}