// LeetCode Problem 1281
// Title: Subtract the Product and Sum of Digits of an Integer
// Difficulty: Easy

class Solution {
public:
int subtractProductAndSum(int n) {

    int product = 1;
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        product = product * digit;
        sum = sum + digit;
        n = n / 10;
    }
    return product - sum;
}

};