//lab4 ex1

// Iterative function
long fact(int n) {
    long ans;
    for (ans = 1; n > 1; n--)
        ans *= n;
    return ans;
}

// Recursive function
long rfact(int n) {
    long ans;
    if (n > 0)
        ans = n * rfact(n - 1);
    else
        ans = 1;
    return ans;
}

/* 
ans: the iterative function uses only one stack frame, the memory usage is consistant.
the recursive function creates a stack frame each time it is called, the memory usage is multiplied by the amount of recursive calls.
 */