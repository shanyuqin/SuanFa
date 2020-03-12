// 一个数 数为0 的话  0的0次方怎么定义 你要返回0还是1，0的负数次方 是不和规则的需要判断。

// 然后如果求一个数的32次方，那么其实就是两个 数的16次方相乘，那么16次方，又是两个8次方的相乘

double PowerWithExponent(double base,unsigned int exponent) {
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;
    
    double result = PowerWithExponent(base,exponent/2);
    result *= result;

    if (exponent % 2 == 1)
        result *= base;
    
    return result;
}