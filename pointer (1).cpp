#include<stdio.h>
#include<stdlib.h>

int isPalindrome(int num){
int * rev = (int *)malloc(sizeof(int));
*rev = 0;
int temp = num;
while (temp > 0){
*rev = *rev * 10 + temp % 10;
temp /= 10;
}
return *rev == num;
}

int isArmstrong(int num){
int * sum = (int *)malloc(sizeof(int));
*sum = 0;
int temp = num, remainder;
while(temp > 0){
remainder = temp % 10;
*sum += remainder * remainder * remainder;
temp /= 10;
}
return *sum == num;
}

int isPerfect(int num){
int * sum = (int *)malloc(sizeof(int));
*sum = 0;
for (int i = 1; i < num; i++) {
if (num % i == 0)
*sum += i;
}
return *sum == num;
}

int main(){
int choice = 0;
int * num = (int *)malloc(sizeof(int));

do{
printf("\nMenu: \n");
printf("1.Palindrome\n2.Armstrong Number\n3.Perfect Number\n4.Exit\n");
printf("Enter your choice: ");
scanf("%d",&choice);

if(choice == 4) break;

printf("Enter a number: ");
scanf("%d",num);

switch (choice) {
case 1:
printf(isPalindrome(*num) ? "Palindrome\n" : "Not a Palindrome\n");
break;
case 2:
printf(isArmstrong(*num) ? "Armstrong\n" : "Not a Armstrong\n");
break;
case 3:
printf(isPerfect(*num) ? "Perfect\n" : "Not a Perfect\n");
break;
default:
printf("Invalid choice! Try again.\n");
}
} while (choice != 4);

free(num);
return 0;
}