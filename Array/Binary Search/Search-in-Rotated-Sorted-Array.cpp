class Solution {
public:

    int findPivot(vector<int>& nums, int n){
        int low = 0;
        int high = n -1;

        while(low < high){
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[high]){
                low = mid + 1; 
            }else{
                high = mid;
            }
        }

        return high;
    }

    int binarySearch(int low, int high , int target, vector<int>& nums){
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return -1;
    }
    int search(vector<int>& nums, int target) {
      int n = nums.size();
      int pivot_index = findPivot(nums , n);

      int rightSide = binarySearch(0, pivot_index -1 , target, nums);
      int leftSide = binarySearch(pivot_index, n - 1, target, nums);

      if(rightSide != -1){
        return rightSide;
      }

      if(leftSide != -1){
        return leftSide;
      }

      return -1;

    }
};
