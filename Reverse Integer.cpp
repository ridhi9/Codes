class Solution {
public:
    int reverse(int x) {
        // int prod=1;
        // while(x!=0){
        //   int digit=x%10;
      
        //     prod=prod*digit;
        //     prod=prod*10;
        //     x/10;
        //     x%10;
        // prod=prod+x;
        // }
      
        // return prod  
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
          //as 2^31-1= 2147483647 
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
          //as -2^31= -2147483648
            rev = rev * 10 + pop;
        }
        return rev;
    }
}; 
