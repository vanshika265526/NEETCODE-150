class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //calculate number of rows and coloumns
        int n=matrix.size();
        int m=matrix[0].size();
       //first step is to transpose the matrix
        for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
      
        //then reverse the rows
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};
