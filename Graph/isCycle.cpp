
bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&parent,int &cycleStart,int &cycleEnd){
	vis[node]=1;
	for(auto adjNode:adj[node]){
		if(adjNode==parent[node]) continue; //skipped parent node
		if(vis[adjNode]==0){
			parent[adjNode]=node;
			if(dfs(adjNode,adj,vis,parent,cycleStart,cycleEnd)) return true;

		}
		else if(vis[adjNode]==1){
			cycleStart=adjNode;
			cycleEnd=node;
			return true;
		}
		

	}
	// vis[node]=2;
	return false;
}

vector<int> isCyclic(int n,vector<int>adj[]){
	vector<int>vis(n,0);
	vector<int>parent(n,-1);
	int cycleStart=-1;
	int cycleEnd=-1;
	for(int node=0;node<n;node++){
		if(vis[node]==0&&dfs(node,adj,vis,parent,cycleStart,cycleEnd)){
			break;

		}
	}
	vector<int>vert(n,0); //mark the vertices which are part of cycle
	if(cycleStart==-1){
		return vert; //no cycle exist
	}
	vert[cycleStart]=1;
	for(int node=cycleEnd;node!=cycleStart;node=parent[node]){
		vert[node]=1;
	}

	return vert;
}
