#include "sum.h"
#include <assert.h>

int sum(int a[], int n)
{
    if(n > 0)
    {
        return(a[n-1]+sum(a,n-1));
    }
    else if(n == 0)
    {
        return 0;
    }
    else
        return -1;
}