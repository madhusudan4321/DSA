class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        HashSet<ArrayList<Integer>>set = new HashSet<>();
        List<List<Integer>>ans = new ArrayList<>();
        Arrays.sort(nums);
        for(int i=0;i<nums.length;i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            int left = i+1;
            int right = nums.length-1;

            while(left<right){
                int sum = nums[i]+nums[left]+nums[right];
                if(sum==0){
                    set.add(new ArrayList<>(Arrays.asList(nums[i],nums[left],nums[right])));
                    if(left<nums.length && nums[left]==nums[left+1]){
                        left++;
                    }
                    if(right>0 && nums[right]==nums[right-1]){
                        right--;
                    }
                }else if(sum<0){
                    left++;
                }else{
                    right--;
                }
                if(sum==0){
                    left++;
                    right--;
                }
            }
        }
        ans.addAll(set);
        return ans; 
    }
}