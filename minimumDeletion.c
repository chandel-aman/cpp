#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int freq[n], distinct = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
            }
        }
        freq[distinct] = count;
        distinct++;

        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                i = j;
            }
        }
    }
    int distinctFreq[distinct];

    for (int i = 0; i < distinct; i++)
    {
        distinctFreq[i] = freq[i];
    }

    // for (int i = 0; i < distinct; i++)
    // {
    //     printf("%d ", distinctFreq[i]);
    // }

    int common_divisor = freq[0];
    for (int i = 1; i < distinct; i++)
    {
        common_divisor = gcd(common_divisor, freq[i]);
    }

    if (common_divisor > 1)
    {
        printf("%d\n", n);
    }
    else
    {
        int max_freq = distinctFreq[0];
        for (int i = 1; i < distinct; i++)
        {
            if (distinctFreq[i] > max_freq)
            {
                max_freq = distinctFreq[i];
            }
        }
        int num_deletions = n - max_freq-1;
        printf("%d\n", num_deletions);
    }

    return 0;
}
