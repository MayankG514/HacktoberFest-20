using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int v;
	    cin>>v;
	    int temp;
	    int arr[v][v];
	    int dist[v][v];
	    for(int i=0;i<v;i++)
	    {
	        for(int j=0;j<v;j++)
	        {
	            cin>>arr[i][j];
	            dist[i][j] = arr[i][j];
	        }
	    }
	    for(int i=0;i<v;i++)
	    {
	        for(int j=0;j<v;j++)
	        {
	            for(int k=0;k<v;k++)
	            {
	                if(dist[j][k]>dist[j][i]+dist[i][k])
	                {
	                    dist[j][k] = dist[j][i]+dist[i][k];
	                }
	            }
	        }
	    }
	    for(int i=0;i<v;i++)
	    {
	        for(int j=0;j<v;j++)
	        {
	            if(dist[i][j]!=10000000)
	            cout<<dist[i][j]<<" ";
	            else
	            cout<<"INF ";
	        }
	        cout<<endl;
	    }
	}
	return 0;
}
