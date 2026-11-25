class Solution {
public:
    void dfs(vector<vector<int>>&image,vector<vector<bool>>&vis,int n,int m,int sr,int sc,int newcolor,int oldcolor){
        vis[sr][sc]=true;
        image[sr][sc]=newcolor;
        if(sr-1>=0 && !vis[sr-1][sc] && image[sr-1][sc]==oldcolor){
            dfs(image,vis,n,m,sr-1,sc,newcolor,oldcolor);
        }
        if(sr+1<n && !vis[sr+1][sc] && image[sr+1][sc]==oldcolor){
            dfs(image,vis,n,m,sr+1,sc,newcolor,oldcolor);
        }
        if(sc-1>=0 && !vis[sr][sc-1] && image[sr][sc-1]==oldcolor){
            dfs(image,vis,n,m,sr,sc-1,newcolor,oldcolor);
        }
        if(sc+1<m && !vis[sr][sc+1] && image[sr][sc+1]==oldcolor){
            dfs(image,vis,n,m,sr,sc+1,newcolor,oldcolor);
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        dfs(image,vis,n,m,sr,sc,color,image[sr][sc]);
        return image;

    }
};