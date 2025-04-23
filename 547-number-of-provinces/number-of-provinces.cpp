class Solution {
public:
    void cityCount(vector<vector<int>>& a, int i, int j){
        a[i][j] = -1;
        a[j][i] = -1;
        int n = a[0].size();
        for(int k=0;k<n;k++){
            if(a[j][k] == 1)
            cityCount(a, j, k);
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces= 0;
        int n = isConnected[0].size();
        for(int i =0;i<n;i++){
            if(isConnected[i][i] == 1){
                cityCount(isConnected, i, i);
                provinces++;
            }  
        }
        return provinces;
    }
};