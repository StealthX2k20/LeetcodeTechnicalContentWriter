# Editorial for LeetCode Problem 390 Elimination Game

*Lemma* : After performing the given operation for **M** number of times the remaining segment will be an ArithmeticcProgression with a common difference of **2^M** where **^**
represents power function.

*Proof of Lemma* : Obviously, initially **0** operations are performed so the given sequence is an Arithmetic Progression with a common difference of 1 i.e. 2^0. Now by induction
we can say that since the **(M-1)th** operation resulted in a common difference of **2^(M-1)** and since we are removing alternating elements in the **Mth** operation, thereby
doubling the common difference between the new adjacent elements.

Now, I will try to explain my recursive approach by dividing my solution into 2 cases:

1) If the length of the segment is odd : Suppose the segment is of **5** elements **{a, b, c, d, e}**,then it's easy to see that the second element of this segment will be the
first element of the new segment and the second last element of this segment will be the last element of the new segment which will be formed after doing the given operation on
this segment, irrespective of the direction in which you apply the given operation and hence the new segment will be **{b, d}**.

2) If the length of the segment is even : Suppose the segment is of **4** elements **{a, b, c, d}**, then the first and last element of the new segment will depend on the
direction in which we are applying our operation, i.e. the new segment will be **{b, d}** if we operate from left to right and **{a, c}** if we operate from right to left. It's
easy to see that if we operate from left to right then the second element of the segment becomes the first element of the new segment and the last element remains the same, we can
make a similar assertion for the **“right to left”** operation.

Keeping these observations in mind, we can easily make a recursive solution for the given problem.

**Space Complexity : O(log N)**
**Time Complexity : O(log N)**

*Reason for Time Complexity being O(log N)* : The key note here is that the common difference is increasing in terms of ‘powers of 2’ and since this difference can go as high as
O(N) therefore it will take O(log N) function calls in the worst case, hence the time complexity of the given code will be **O(log N)**.

*Reason for Space Complexity being O(log N)* : As mentioned above the number of function calls will be O(log N) and in each function call we are occupying O(1) space therefore the overall space complexity will be **O(log N)**.
