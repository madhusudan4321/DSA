class Solution {
public:
    void dfs(int n,int m,vector<vector<int>>&image,vector<vector<bool>>&vis,int sr,int sc,int oldcolor,int newcolor){
        image[sr][sc]=newcolor;
        vis[sr][sc] = true;
        if(sr-1>=0 && !vis[sr-1][sc] && image[sr-1][sc]==oldcolor){
            dfs(n,m,image,vis,sr-1,sc,oldcolor,newcolor);
        }
        if(sr+1<n && !vis[sr+1][sc] && image[sr+1][sc]==oldcolor){
            dfs(n,m,image,vis,sr+1,sc,oldcolor,newcolor);
        }
        if(sc-1>=0 && !vis[sr][sc-1] && image[sr][sc-1]==oldcolor){
            dfs(n,m,image,vis,sr,sc-1,oldcolor,newcolor);
        }
        if(sc+1<m && !vis[sr][sc+1] && image[sr][sc+1]==oldcolor){
            dfs(n,m,image,vis,sr,sc+1,oldcolor,newcolor);
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int oldcolor = image[sr][sc]; 
        vector<vector<bool>>vis(n,vector<bool>(m,false));  
        dfs(n,m,image,vis,sr,sc,image[sr][sc],color);
        return image;
    }
};