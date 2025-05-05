#include <iostream>
using namespace std;
#include "header.h"


int main(){
    cll l1;
    int shatime;
    cout<<"Enter Share time:";
    cin>>shatime;
    int num,loop=1;
    while (loop==1){
        int ch;
        cout<<"1.Insert process\n2.Execute\n3.Display\n4.Exit\n";
        cout<<"Enter your choice:";
        cin>>ch;
        switch (ch){
            case 1:
                cout<<"Enter the number:";
                cin>>num;
                l1.insertprocess(num);
                break;
            case 2:
                l1.execute(shatime);
                break;
            case 3:
                l1.display();
                break;
            case 4:
                loop=0;
                break;
            default:
                cout<<"\nInvalid Entry\n\n";
        }
    }
}


