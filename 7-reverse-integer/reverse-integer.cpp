class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int ld = x % 10;

            // overflow check
            if (rev > INT_MAX / 10 || rev < INT_MIN / 10)
                return 0;

            rev = rev * 10 + ld;
            x /= 10;
        }
        return rev;
    }
};
