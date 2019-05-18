# nowcower 个人刷题笔记

### 二维数组的查找

**思路一**

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;此问题的关键点在于把握二维数组由上到下，由左至右递增的特性，
那么选取右上角元素或者左下角元素 array[row][col] 与 target 进行比较，

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;当 target 小于元素 array[row][col] 时，那么 target 必定在元素 array 所在行的左边，
即 row++;

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;当 target 大于元素 array 时，那么 target 必定在元素 array 所在列的下边，
即 row++

**思路二**

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;把二维数组的每一行看成有序递增数组，利用二分查找，通过遍历每一行得到答案

时间复杂度 nlogn
