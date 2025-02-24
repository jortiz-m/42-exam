size_t	ft_strspn(const char *s, const char *accept)
{
    size_t  i;
    size_t  res;
    int     j;

    i = 0;
    res = 0;
    while (s[i])
    {
        j = 0;
        while (accept[j])
        {
            if (s[i] == accept[j])
            {
                res++;
                break;
            }
            j++;
        }
        if (!accept[j])
            break;
        i++;
    }
    return (res);
}
