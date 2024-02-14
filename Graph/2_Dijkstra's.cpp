vector <int> dijkstra(int V, vector<pair<int,int>> adj[], int S)
    {
        // Code here
        
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; 
        vector<int>dist(V,1e9);
        
        dist[S]=0;

        pq.push({0,S});
        while(!pq.empty()){
            auto it=pq.top();
            int distance=it.first;
            int node=it.second;
            pq.pop();
            for(auto it:adj[node]){
                int edgeWeight=it.second;
                int adjNode=it.first;
                if(distance+edgeWeight<dist[adjNode]){
                    dist[adjNode]=distance+edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
        
        
    }