#include<bits/stdc++.h>
using namespace std;

#define buffer_size 3

int state = 0;

void prod(){
    if(state <= buffer_size-1){
        state++;
        cout << "\nProducer produces the item " << state << "\n";
    }
    else {
        cout << "\nBuffer full!\n";
    }
}

void cons(){
    if(state == 0){
        cout << "\nBuffer empty!\n";
    }
    else {
        cout << "\nProducer consumes the item " << state << "\n";
        state--;
    }
}

int main(){
    int ch=0;
    while(ch != 3){
        cout << "1.Producer\n2.Consumer\n3.Exit\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            prod();
            break;
        case 2:
            cons();
            break;
        }
    }
    return 0;
}