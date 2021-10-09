#include <bits/stdc++.h>
using namespace std;
#define m 1000000007
typedef long long int lli;
void prod(lli f[2][2], lli v[2][2]);                       //helper function to calculate product
int power(lli f[2][2],int n,int a,int b)
{
    lli v[2][2]={{1,0},{0,1}};
    while(n>0)
        if(n&1)
              prod(v,f),n--;
        else 
           prod(f,f),n/=2;
           
    return((a*v[0][0]+b*v[1][0])%m);
}
void prod(lli f[2][2],lli v[2][2])
{
    int x =((f[0][0] * v[0][0])%m + (f[0][1] * v[1][0]) %m) % m;
    int y =((f[0][0] * v[0][1])%m + (f[0][1] * v[1][1]) %m) % m;
    int z =((f[1][0] * v[0][0])%m + (f[1][1] * v[1][0]) %m) % m;
    int w =((f[1][0] * v[0][1])%m + (f[1][1] * v[1][1]) %m) % m;
    f[0][0] = x,f[0][1] = y,f[1][0] = z,f[1][1] = w;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,a,b,n;
    cin >> t;
    while(t--) 
    {
        cin >> a >> b >> n;                             //Enter first two values of the sequence and n, where n is the nth term.
                                                        // This code return the nth term of the customised fibonacci sequence modulo 1e9 + 7, just in case the number is too big
        if(n == 1)
          cout << b << "\n";
        else 
        {
            lli f[2][2]={ {0,1} , {1,1} };
            cout << power(f,n,a,b) << "\n";
        }
    }
    return 0;
}
