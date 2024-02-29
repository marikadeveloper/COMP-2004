/**
 * You are given two integer arrays nums1 and nums2 of lengths m and n respectively. nums1 and nums2
represent the digits of two numbers. You are also given an integer k. Create the maximum number of
length k <= m + n from digits of the two numbers. The relative order of the digits from the same array
must be preserved. Return an array of the k digits representing the answer.

Example 1:
Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
Output: [9,8,6,5,3

  TODO:

  If H is from num1, make sure (n - H_pos - 1) + (m – num2_pos) >= k_pos - i
  If H is from num2, make sure (n – num1_pos) + (m -H_pos - 1) + >= k_pos - i
 */

const arr1 = [3, 4, 6, 5];
const arr2 = [9, 1, 2, 5, 8, 3];
// 9 8 6 5 3

const k = 5;
let result = '';

let num1_pos = 0;
let num2_pos = 0;

for (let k_pos = 0; k_pos < k; k_pos++) {
  let h = 0;
  let hIsFromArray = 1;
  let h_pos = 0;
  for (let i = num1_pos; i < arr1.length; i++) {
    if (arr1[i] > h) {
      h = arr1[i];
      hIsFromArray = 1;
      h_pos = i;
    }
  }
  for (let i = num2_pos; i < arr2.length; i++) {
    if (arr2[i] > h) {
      h = arr2[i];
      hIsFromArray = 2;
      h_pos = i;
    }
  }

  if (hIsFromArray === 1) {
    num1_pos = h_pos + 1;
  } else {
    num2_pos = h_pos + 1;
  }

  result += h;
}
