#include <iostream>
using namespace std;

class shape{
    private:
        int len,bre,hei,area;
    public:
        shape(){
            len=1;
            bre=1;
            hei=1;
        }
        void setlen(int);
        void setbre(int);
        void sethei(int);
        int square(){
            area=len*len;
            cout <<"\nArea of square:"<<area<<"\n\n";
            return 0;
        }
        int cube(){
            area=6*len*len;
            cout << "\nArea of cube:"<<area<<"\n\n";
            return 0;
        }
        int rectangle(){
            area=len*bre;
            cout << "\nArea of rectangle:"<<area<<"\n\n";
            return 0;
        }
        int cuboid(){
            area=2*((len*bre)+(bre*hei)+(hei*len));
            cout << "\nArea of cuboid:" << area<<"\n\n";
            return 0;
        }

};

int main(){
    shape sha;
    int loop=0;
    while (loop==0){
        int ch;
        cout << "Area of\n1.Square\n2.Cube\n3.Rectangle\n4.Cuboid\n5.Exit\n\n";
        cout <<"Enter your choice:";
        cin >> ch;
        switch (ch){
            case 1:
                int len1;
                cout <<"\nEnter the length of the square:";
                cin >>len1;
                sha.setlen(len1);
                sha.square();
                break;
            case 2:
                int len2;
                cout <<"\nEnter the length of the cube:";
                cin >>len2;
                sha.setlen(len2);
                sha.cube();
                break;
            case 3:
                int len3,bre1;
                cout<<"\nEnter the length of the rectangle:";
                cin >>len3;
                cout<<"Enter the breadth of the rectangle:";
                cin >>bre1;
                sha.setlen(len3);
                sha.setbre(bre1);
                sha.rectangle();
                break;
            case 4:
                int len,bre,hei;
                cout<<"\nEnter the length of the cuboid:";
                cin >>len;
                cout<<"Enter the breadth of the cuboid:";
                cin >>bre;
                cout<<"Enter the height of the cuboid:";
                cin>>hei;
                sha.setbre(bre);
                sha.setlen(len);
                sha.sethei(hei);
                sha.cuboid();
                break;
            case 5:
                loop=1;
                break;
            default:
                cout<<"\nInvalid Entry Try Again\n\n";
                break;
        }

    }

}


void shape::setlen(int l){
    len=l;
}
void shape::setbre(int b){
    bre=b;
}
void shape::sethei(int h){
    hei=h;
}