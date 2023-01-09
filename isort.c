#include <stdio.h>
#define FIFTY 50
void shift_element(int *arr,int i)
{
    int temp=i;
    while (temp>0)
    {
    *(arr+temp)=*(arr+temp-1);
    temp--;
    }
}
void insertion_sort(int *arr,int len)
{
    int temp1,temp2,i=1;
    for ( i = 1; i < len; i++)
    {
        temp1=*(arr+i);
        temp2=i-1;
        while(temp2>=0 && *(arr+temp2)>temp1)
        {
         *(arr+temp2+1)=*(arr+temp2);   
         temp2--;
        }
        *(arr+temp2+1)=temp1;  
    } 
}
int main()
{
    int arr[FIFTY]={0};
    for (int i = 0; i < FIFTY; i++)
    {
        scanf("%d",&(*(arr+i)));
    }
    insertion_sort(arr,FIFTY);
    int i = 0; 
    for ( i = 0; i < FIFTY; ++i)
    {
        if (i!=FIFTY-1)
        {
            printf("%d%c",*(arr+i),',');
        }
        else 
        printf("%d%c",*(arr+i),'\n');
    }
}
