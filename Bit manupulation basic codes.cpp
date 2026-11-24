
#include<bits/stdc++.h>
#define int long long int
using namespace std;

/*
==================================================
             BIT MANIPULATION NOTES
==================================================

Bit indexing: Right to Left (0-based)

Index :  3 2 1 0
Bits  :  0 1 0 1  = 5

Remember:
AND (&)  -> Check / Clear bits
OR  (|)  -> Set bits
XOR (^)  -> Toggle bits
NOT (~)  -> Flip bits

Use 1LL instead of 1 for 64-bit operations.

Assume non-negative numbers and bit indices 0..62.
==================================================
*/


// 01. ODD OR EVEN
/*
    Intuition:
    Last bit = 1 -> Odd
    Last bit = 0 -> Even

    5 = 0101 -> Odd
    6 = 0110 -> Even

    TC: O(1) | SC: O(1)
*/
void oddEven(int n){
    if(n & 1){
        cout<<"Odd"<<endl;
    }else{
        cout<<"Even"<<endl;
    }
}


// 02. GET ITH BIT
/*
    Goal: Check whether ith bit is 0 or 1.

    n = 5, i = 2

    n    = 0101
    mask = 0100
    ------------
    AND  = 0100 -> Non-zero -> 1

    Trick: AND with 1 at target position.
*/
int getIthBit(int n,int i){
    int mask = (1LL<<i);
    return (n & mask) != 0;
}


// 03. SET ITH BIT
/*
    Goal: Make ith bit 1.

    n = 5, i = 1

    n    = 0101
    mask = 0010
    ------------
    OR   = 0111 -> 7

    Trick: x | 1 = 1
*/
void setIthBit(int &n,int i){
    int mask = (1LL<<i);
    n = n | mask;
}


// 04. CLEAR ITH BIT
/*
    Goal: Make ith bit 0.

    n = 5, i = 2

    n    = 0101
    mask = 1011  (~0100)
    ------------
    AND  = 0001 -> 1

    Trick: x & 0 = 0
*/
void clearIthBit(int &n,int i){
    int mask = ~(1LL<<i);
    n = n & mask;
}


// 05. TOGGLE ITH BIT
/*
    Goal: Flip ith bit.
    0 -> 1
    1 -> 0

    n = 5, i = 2

    n    = 0101
    mask = 0100
    ------------
    XOR  = 0001 -> 1

    Trick: x ^ 1 flips the bit.
*/
void toggleIthBit(int &n,int i){
    n = n ^ (1LL<<i);
}


// 06. UPDATE ITH BIT
/*
    Goal: Set ith bit to given value v (0 or 1).

    Steps:
    1. Clear ith bit.
    2. Put value v at ith position.

    n = 5, i = 1, v = 1

    Original = 0101
    Clear    = 0101
    OR mask  = 0010
    Result   = 0111 -> 7
*/
void updateIthBit(int &n,int i,int v){
    clearIthBit(n,i);
    int mask = (v<<i);
    n = n | mask;
}


// 07. CLEAR LAST I BITS
/*
    Goal: Clear rightmost i bits.

    n = 15, i = 2

    n    = 1111
    mask = 1100
    ------------
    AND  = 1100 -> 12

    Trick: Shift an all-ones unsigned mask.
*/
void clearLastIBits(int &n,int i){
    auto mask = (~0ULL)<<i;
    n = n & mask;
}


// 08. CLEAR BITS IN RANGE [i,j]
/*
    Goal: Clear all bits from i to j (inclusive).

    n = 31, i = 1, j = 3

    n    = 11111

    a    = 10000  (keep left bits)
    b    = 00001  (keep right bits)

    mask = 10001  (a | b)

    n & mask = 10001 -> 17
*/
void clearBitsInRange(int &n,int i,int j){
    auto a = (~0ULL)<<(j+1);
    auto b = (1ULL<<i)-1;

    auto mask = a | b;
    n = n & mask;
}


// 09. CHECK POWER OF TWO
/*
    Every power of 2 has exactly one set bit.

    n   = 8 = 1000
    n-1 = 7 = 0111
    ----------------
    AND     = 0000

    Examples: 1, 2, 4, 8, 16, 32...
*/
bool isPowerOfTwo(int n){
    return n>0 && (n & (n-1))==0;
}


// 10. CLEAR RIGHTMOST SET BIT
/*
    n   = 12 = 1100
    n-1 = 11 = 1011
    -----------------
    AND      = 1000 -> 8

    Useful for counting set bits.
*/
void clearRightmostSetBit(int &n){
    n = n & (n-1);
}


// 11. COUNT SET BITS
/*
    Brian Kernighan's Algorithm

    n = 13 = 1101

    1101 -> 1100
    1100 -> 1000
    1000 -> 0000

    Answer = 3

    TC: O(number of set bits)
    SC: O(1)
*/
int countSetBits(int n){
    int cnt = 0;

    while(n){
        n = n & (n-1);
        cnt++;
    }

    return cnt;

    // Built-in: __builtin_popcountll(n);
}


// ================= DRIVER CODE =================

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    int n = 5;
    int i = 1;

    updateIthBit(n,i,1);

    cout<<n;  // Output: 7

    return 0;
}
