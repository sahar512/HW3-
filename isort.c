#include <stdio.h>
#define fifty 50
void shift_element(int *arr,int i)
{
    int temp=i; 
    while (temp>0){
        *(arr+temp)=*(arr+temp-1);
        temp--;
    }
}
void insertion_sort(int *arr,int len)
{
    for(int i=1; i<len; i++){
        int temp1=*(arr+i);
        int j =i-1;
        while(j>=0){
            if((*(arr+j)>temp1)){
                j--; 
            }
            else{
                break;
            }
        }
        shift_element(arr+j, i-j);
        *(arr+j+1)=temp1; 
        // while(j>=0 && temp1 < *(arr+j)){
        //     j--;
        //     shift_element((arr+i),(j-i));
        //     *(arr+i+1)=temp1;
        // }
    }
    // int i=1;
    // while (i<=len)
    // {
    //     int temp1=*(arr+i);
    //     int j=i-1;
    //     int temp2=*(arr+j);
    //     // while(temp1<temp2 && j>=0)
    //     //   j--;
    //     // shift_element(arr+j,i-j);
    //     // *(arr+j+1)=temp1;  
    // } 
}
int main()
{
    int arr[fifty]={0};
    for (int i = 0; i < fifty; i++)
    {
        scanf("%d",&(*(arr+i)));
    }
    insertion_sort(arr,fifty);
    for(int i=0; i<fifty;i++)
    {
        if(i==fifty-1){
            printf("%d",*(arr+i));
            break;
        }
        else{
            printf(",");
        }
        printf("%d",*(arr+i));
    }
    printf("\n");
    // int i = 0; 
    // while(i < fifty)
    // {
    //     printf("%d ",(*(arr+i)));
    //     i++;
    // }
    // return 0;
}
