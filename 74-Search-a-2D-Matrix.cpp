class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, m = matrix.size() - 1;
        
        while (row <= m) {
            int midRow = row + (m - row) / 2;
            
            if (matrix[midRow][0] > target) {
                m = midRow - 1;
            } else if (matrix[midRow][matrix[midRow].size() - 1] >= target && matrix[midRow][0] <= target) {
                int left = 0, right = matrix[midRow].size() - 1;
                
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    
                    if (matrix[midRow][mid] == target) {
                        return true;
                    } else if (matrix[midRow][mid] > target) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                
                return false; 
            } else {
                row = midRow + 1;
            }
        }
        
        return false;  
    }
};
