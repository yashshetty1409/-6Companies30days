class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long int tempSum = 0;
        int count = 0;
        int min = INT_MAX;
        for(int i=0;i<matrix.size();i++){
            long long int sum = 0;
            for(int j=0;j<matrix[i].size();j++){                 
                if(matrix[i][j]<0){
                    matrix[i][j] *= (-1);
                    count++;
                }
                if(min>matrix[i][j]){
                    min=matrix[i][j];
                }
                sum += matrix[i][j];  
            }
            tempSum+=sum;
        }
        if(count%2==0){
            return tempSum;
        }
        else{
            return tempSum-(2*min);
        }
    }
};