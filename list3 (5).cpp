#include<cstdio>
#include<cstdlib>
class list
{
    private:
    int arr[5];
    int size=0;
    
    public:
    void insertion_at_beggining(int key);
    void insertion_at_end(int key);
    void insertion_at_position(int pos,int key);
    int deletion_at_beggining();
    int deletion_at_end();
    int deletion_at_position(int pos);
    int search(int val);
    void display();
    void reverse(int arr[],int start,int end);
    void rotate_reverse(int k);
    void rotate_by_temp(int k);
    void rotate_by_loops(int k);
};

int main()
{
    list obj;
    int choice;
    do
    {
        printf("\nchoose any operation from the below to perform on the array:");
        printf("\n1. insertion at beginning\n2. insertion at end\n3. insertion at a given position\n"
            "4. deletion at beginning\n5. deletion at end\n6. deletion at a given position\n"
            "7. search a given element\n8. display the array\n9. rotate the array\n10. exit\n");
        printf("enter your choice of operation please:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                int key;
                printf("enter the value that you want to insert in the list:");
                scanf("%d",&key);
                obj.insertion_at_beggining(key);
                break;
            }
            case 2:
            {
                int key;
                printf("enter the element you want to insert:");
                scanf("%d",&key);
                obj.insertion_at_end(key);
                break;
            }
            case 3:
            {
                int key;
                printf("enter the element you want to insert:");
                scanf("%d",&key);
                int pos;
                printf("enter the position where you want to insert the elemwnt:");
                scanf("%d",&pos);
                obj.insertion_at_position(pos,key);
                break;
            }
            case 4:
            {
                int result;
                result=obj.deletion_at_beggining();
                if(result!=-1)
                {
                    printf("the deleted value is:%d\n",result);
                }
                break;
            }
            case 5:
            {
                int result;
                result=obj.deletion_at_end();
                if(result!=-1)
                {
                    printf("the deleted value is:%d\n",result);
                }
                break;
            }
            case 6:
            {
                int pos;
                printf("enter the position where you want to delete the element:");
                scanf("%d",&pos);
                int result;
                result=obj.deletion_at_position(pos);
                if(result!=-1)
                {
                    printf("the deleted value is:%d\n",result);
                }
                break;
            }
            case 7:
            {
                int key;
                printf("enter the element that you want to get searched:");
                scanf("%d",&key);
                int result=obj.search(key);
                if(result==-1)
                {
                    printf("the element not found in the list\n");
                }
                else
                {
                    printf("the element was found at index:%d\n",result);

                }
                break;
            }
            case 8:
            {
                obj.display();
                break;
            }
            case 9:
            {
                int val;
                printf("enter the number of times you want to rotate the array:");
                scanf("%d",&val);
                //obj.rotate_reverse(val);
                //obj.rotate_by_temp(val);
                obj.rotate_by_loops(val);
                break;
            }
            case 10:
            {
                printf("Exiting....");
                return 0;
            }
            default:
            {
                printf("invalid choice.\nplease enter valid choice value:\n");
                break;
            }
        }
    }while(choice!=10);
}

    void list::insertion_at_beggining(int key)
    {
        if(size==5)
        {
            printf("the list is full\ninsertion unsuccesfull!!\n");
            return;
        }
        for(int i=size;i>0;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[0]=key;
        size++;
    }

    void list::insertion_at_end(int key)
    {
        if(size==5)
        {
            printf("the list is full\ninsertion unsuccesfull!!\n");
            return;
        }
        size=size+1;
        ///////////////////////////
        arr[size-1]=key;

    }

    void list:: insertion_at_position(int pos,int key)
    {
        if(size==5)
        {
            printf("the list is full\ninsertion unsuccesfull!!\n");
            return;
        }
        if (pos < 0 || pos > size)
        {
            printf("Invalid position!\n");
            return;
        }
        for(int i=size;i>pos;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[pos]=key;
        size++;
    }

    int list:: deletion_at_beggining()
    {
        if(size==0)
        {
            printf("the list is empty so cant print any values\ndeletion unsuccesfull!!\n");
            return -1;
        }
        int val=arr[0];
        for(int i=0;i<size-1;i++)
        {
            arr[i]=arr[i+1];
        }
        size--;
        return val;
    }

    int list:: deletion_at_end()
    {
        if(size==0)
        {
            printf("the list is empty so cant print any values\ndeletion unsuccesfull!!\n");
            return -1;
        }
        int var=arr[size-1];
        size--;
        return var;
    }
    int list:: deletion_at_position(int pos)
    {
        if(size==0)
        {
            printf("the list is empty so cant print any values\ndeletion unsuccesfull!!\n");
            return -1;
        }
        if (pos < 0 || pos > size)
        {
            printf("Invalid position!\n");
            return -1;
        }
        int var=arr[pos];
        for(int i=pos;i<size-1;i++)
        {
            arr[i]=arr[i+1];
        }
        size--;
        return var;
    }

    int list:: search(int val)
    {
        if(size==0)
        {
            printf("the list is empty so cant search for any value\n");
            return -1;
        }
        for(int i=0;i<size;i++)
        {
            if(arr[i]==val)
            {
                return i;
            }
        }
        return -1;
    }

    void list::display()
    {
        if(size==0)
        {
            printf("the list is empty so cant display any value\n");
            return;
        }
        for(int i=0;i<size;i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
    }


    void list:: reverse(int arr[],int start,int end)
    {
        for(int i=start,j=end;i<j;i++,j--)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        
    }

    //1)
    void list:: rotate_reverse(int k)
    {
        if(size==0)
        {
            printf("the list is empty so cant rotate\n");
            return;
        }
        k=k%size;
        reverse(arr,0,size-1);
        reverse(arr,0,k-1);
        reverse(arr,k,size-1);
    }

    //2))
    void list:: rotate_by_temp(int k)
    {
        if(size==0)
        {
            printf("the list is empty so cant rotate\n");
            return;
        }
        k=k%size;
        int temp[5];
        for(int i=0;i<size;i++)
        {
            temp[(i+k)%size]=arr[i];
        }
        for(int i=0;i<size;i++)
        {
            arr[i]=temp[i];
        }
    }

    //3)
    void list:: rotate_by_loops(int k)
    {
        if(size==0)
        {
            printf("the list is empty so cant rotate\n");
            return;
        }
        k=k%size;
        for(int i=0;i<k;i++)
        {
            int last=arr[size-1];
            for(int j=size-1;j>0;j--)
            {
                arr[j]=arr[j-1];
            }
            arr[0]=last;
        }
    }