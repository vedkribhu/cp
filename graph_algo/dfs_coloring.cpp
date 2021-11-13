void dfs(ll i, ll parent){
    // debug(i, parent);
    if(col[i]==1){
        flag = true;
        
        ll ori = i;
        // i = pre[i]; 
        tmp.clear();
        tmp.pb(ori);
        while(parent!=ori && parent!=-1){
            // debug(parent,ori);
            tmp.pb(parent);
            parent=pre[parent];
        }
        tmp.pb(ori);
        col[i]=2;
        return;
        
    }

    else if(col[i]==0){
        col[i]=1;
        pre[i]=parent;
        for(auto nb: adj[i]){
            if(nb==parent || col[nb]==2){continue;}
            // pre[nb]=i;
            dfs(nb, i);

        }
        col[i]=2;
        return;
    }
    else{
        return;
    }
}