#include<stdio.h>


int josephus(int n, int k){
    int res=0;
    for(int i=1;i<=n;i++) 
    res = (res + k) % i;
    return res+1; // 1-based result
}

int main(){
    int n, k;

    printf("Enter number of people:");
    scanf("%d",&n);

    printf("Enter step value k:");
    scanf("%d",&k);

    printf("Survivor= %d\n",josephus(n,k));
    return 0;
}
