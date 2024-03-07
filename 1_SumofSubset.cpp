const int N=1e5+10;
 vector<int>adj[N];
 int dp1[N];
 int dp2[N];

 void dfs(int node,int parent,vector<int>&coins){
 	int sum1=0;
 	int sum2=0;
 	for(auto it:adj[node]){
 		if(it!=parent){
 			dfs(it,node,coins);
 			sum1+=dp2[it];
 			sum2+=max(dp1[it],dp2[it]);
 		}
 	}
 	dp1[node]=coins[node]+sum1;
 	dp2[node]=sum2;
 }
 
void solve(){
	int n;
	cin>>n;
	vector<int>coins(n);
	for(int i=0;i<n;i++){
		cin>>coins[i];
	}
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(0,-1,coins);
	
  
 
 
	
}