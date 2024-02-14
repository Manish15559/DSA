vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        set<pair<int,int>>st; 
        vector<int>dist(V,1e9);
        
        dist[S]=0;
        st.insert({0,S});
        while(!st.empty()){
            auto it=*(st.begin());
            st.erase(it);
            int distance=it.first;
            int node=it.second;
          
            for(auto it:adj[node]){
                int edgeWeight=it[1];
                int adjNode=it[0];
                if(distance+edgeWeight<dist[adjNode]){
                    if(dist[adjNode]!=1e9){
                        st.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode]=distance+edgeWeight;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
        
        
    }