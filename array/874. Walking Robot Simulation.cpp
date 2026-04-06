class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> ob;
        for(auto it:obstacles)
            ob.insert(to_string(it[0])+","+to_string(it[1]));
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        int x=0,y=0,pos=0,ans=0;
        for(int it:commands){
            if(it==-1) pos=(pos+1)%4;
            if(it==-2) pos=(pos+3)%4;
            for(int i=0;i<it;i++){
                int nx=x+dir[pos][0];
                int ny=y+dir[pos][1];
                if(ob.count(to_string(nx)+","+to_string(ny))) break;
                x=nx;
                y=ny;
                ans=max(ans,x*x+y*y);
            }
        }
        return ans;
    }
};
