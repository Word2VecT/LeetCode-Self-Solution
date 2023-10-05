int numSubarrayBoundedMax(int* nums, int numsSize, int left, int right){
    int i;
    int cnt = 0;
    int locIn = -1;
    int locOver = -1;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] >= left && nums[i] <= right)
            locIn = i;
        else if (nums[i] > right) {
            locOver = i;
            locIn = -1;
        }
        if (locIn != -1)
            cnt += locIn - locOver;
            /*固定右端，左端在 In 和 Over 之间移动*/
    }

    return cnt;
}