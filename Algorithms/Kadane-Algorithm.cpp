#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n){
    
    int maxsum = arr[0];
    int prev = arr[0];
    for(int i=1;i<n;i++)
    {
        
        prev = max(arr[i],arr[i]+prev);
        if(prev>maxsum)
        maxsum = prev;
    }
    return maxsum;
    
}


int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
