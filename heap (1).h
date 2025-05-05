#include <iostream>

struct node{
    int weight;
    int vertex;
    int parent;
};

class heap{
    private:
        int curr;
        node arr[100];
        int size;
    public:
        heap(int vertex){
            curr=0;
            size=vertex;
        }
        void heapify(int,int);
        int insert(node);
        void display();
        node delete1();
        int getCurr() {
            return curr;
        }

        node getNode(int i) {
            return arr[i];
        }
};

void heap::display(){
    std::cout<<"\n";
    for (int i=1;i<=curr;i++){
        std::cout<<" "<<arr[i].weight;
    }
}

int heap::insert(node data){
    if (curr+1==size){
        return 1;
    }else{
        curr=curr+1;
        arr[curr]=data;
        heapify(curr,0);
        return 0;
    }
}

node heap::delete1(){
    // if (curr == 0)
    // {
    //     return -1;
    // }
    if (curr == 1)
    {
        curr = 0;
        return (arr[1]);
    }
    else{
        node returnElem = arr[1];

        arr[1] = arr[curr];
        curr -= 1;

        heapify(1, 1);

        return (returnElem);
    }
}

void heap::heapify(int start,int mode){
    if (mode==0){       
        int parent=start/2;                        //heapify up
        if (start!=0 && start!=1 && arr[start/2].weight>arr[start].weight){
            node temp=arr[start/2];
            arr[start/2]=arr[start];
            arr[start]=temp;
            heapify(parent,mode);
        }
    }
    else{
        
        if ((start*2<=curr && arr[start].weight>arr[start*2].weight) || (start*2+1<=curr && arr[start].weight>arr[start*2+1].weight)){
            node temp=arr[start*2].weight>arr[start*2+1].weight?arr[start*2+1]:arr[start*2];
            int tempind=arr[start*2].weight>arr[start*2+1].weight?start*2+1:start*2;
            arr[tempind]=arr[start];
            arr[start]=temp;
            heapify(tempind,mode);
        }
    }
}
