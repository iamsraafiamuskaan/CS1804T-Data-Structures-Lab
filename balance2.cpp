#include<cstdio>
#include<cstdlib>
#include"st.sll2.h"

//Function to check whether the string is balanced.
bool checkbalance(char *str)
        {
            stack st;
            for(int i=0;str[i]!='\0';i++)
            {
                if(str[i]=='(')
                {
                    st.push(str[i]);
                }
                else if(str[i]==')')
                {
                        if(st.isempty()){return false;}
                        else
                        {
                            st.pop();
                        }
                }
                else {return false;}
            }
            return st.isempty();
        }
//To check whether string is balanced or not using just count method.
bool checkbalance_counter(char* str)
    {
        int count=0;
        for(int i=0;str[i]!='\0';i++)
        {
            if(str[i]=='(')
            {
                count++;
            }
            else if(str[i]==')')
            {
                count--;
            }
            else
            {
                return false;
            }    
        }
        if(count==0){return true;}
        else{return false;}
    }


int main()
{
    char str[100];
    int choose;
    do
    {
        printf("\nChoose the operation to be performed from the following menu: \n");
    printf("1 To Check Balance\n2 To Exit\n");
    scanf("%d",&choose);
    switch(choose)
    {
        case 1:
        printf("Enter the string which has only paranthesis: ");
        scanf("%s",str);
        if(checkbalance(str))
        {
            printf("The string %s is balanced with paranthesis stack.\n",str);
        }
        else
        {
            printf("The string %s is not balanced with paranthesis stack.\n",str);
        }

        if(checkbalance_counter(str))
        {
            printf("The string %s is balanced with paranthesis count.\n",str);
        }
        else
        {
            printf("The string %s is not balanced with paranthesis count.\n",str);
        }
        break;

        case 2:
        printf("Exiting...\n");
        break;
        
        default:
        printf("Invalid Number.Please Try Again.\n");
    }
    }while(choose!=2);

    return 0;
}