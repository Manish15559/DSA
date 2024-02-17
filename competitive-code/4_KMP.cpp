vector <int> search(string pat, string txt)
        {
            //code here
            
            int n=txt.size();
            int m=pat.size();
        pat=' '+pat;
        vector<int>lps(m+1,0);
        vector<int>ans;
        int l=0;
        int r=2;
        while(r<=m){
            if(pat[l+1]==pat[r]){
                lps[r]=++l;
                r++;
              
            }
            else{
                if(l!=0){
                    l=lps[l-1];
                }
                else{
                    lps[r]=l;
                    r++;
                }
            }
           
        }
        int idx=0;
        for(int i=0;i<n;i++){
           
              while(idx!=0&&pat[idx+1]!=txt[i]){
                idx=lps[idx];
            }
             if(pat[idx+1]==txt[i]){
                 idx++;
            
            }
            
           
                
            
          
            if(idx==m){
                ans.push_back(i-m+2);
                idx=lps[idx];
            }
            
        }
        
        if(ans.size()==0){
            return {-1};
        }
        return ans;
            
            
            
        
        }