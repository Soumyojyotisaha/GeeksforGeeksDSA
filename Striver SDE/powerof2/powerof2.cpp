class Solution {
public:
    bool isPowerOfTwo(int n) {//log2 variant
        return n>0 && log2(n)==31-__builtin_clz(n);
    }
};
