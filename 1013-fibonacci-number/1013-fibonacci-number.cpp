class Solution {
public:
    int Recursion(int n){
        if(n<=1){
            return n;
        }

        return Recursion(n-1)+Recursion(n-2);
    }
    int fib(int n) {
        return Recursion(n);
    }
};