#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	ft_strfind(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return (1);
}
int main(void)
{
    printf("ft_strfind: %d", ft_strfind("0 : zero \n", '\n'));
    return (0);
}