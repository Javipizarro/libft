#include "libft.h"
#include <stdio.h>

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (dst == src || !n)
		return (dst);
	if (dst || src)
	{
		s = src;
		d = dst;
		while (n-- > 0)
			*(d++) = *(s++);
		return (dst);
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char *s;

	if (!(s = malloc(ft_strlen(s1) + 1)))
		return (NULL);
	ft_memcpy(s, s1, ft_strlen(s1) + 1);
	return (s);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*j;

	j = s;
	while (n-- > 0)
		*(j++) = 0;
}

char	*ft_litoa_base(long int n, char *base)
{
	char		ret[66];
	short int	i;
	int			bsize;

	bsize = ft_strlen(base);
	if (!base || bsize < 2)
		return ("Error, no valid base to transform 'n'");
	i = 65;
	ft_bzero(ret, 66 * sizeof(char));
	if (n < 0)
	{
		ret[0] = '-';
		ret[--i] = base[-(n % bsize)];
		n = -(n / bsize);
	}
	while (n % bsize || n / bsize)
	{
		ret[--i] = base[n % bsize];
		n /= bsize;
	}
	if (ret[0] == '-')
		ret[--i] = '-';
	else if (i == 65)
		ret[--i] = '0';
	return (ft_strdup(&ret[i]));
}

char	*ft_litoa_base_old(long int n, char *base)
{
	char		ret[66];
	short int	i;
	short int	neg;
	int			bsize;

	if (!base || (bsize = ft_strlen(base)) < 2)
		return ("Error, no valid base to transform 'n'");
	i = 65;
	ret[i] = 0;
	if (n < 0)
	{
		neg = 1;
		ret[--i] = base[-(n % bsize)];
		n = -(n / bsize);
	}
	while (n % bsize || n / bsize)
	{
		ret[--i] = base[n % bsize];
		n /= bsize;
	}
	if (neg == 1)
		ret[--i] = '-';
	else if (i == 65)
		ret[--i] = '0';
	return (ft_strdup(&ret[i]));
}

#include "libft.h"

char	*ft_itoa_base(int n, char *base)
{
	char		ret[34];
	short int	i;
	short int	neg;
	int			bsize;

	if (!base || (bsize = ft_strlen(base)) < 2)
		return ("Error, no valid base to transform 'n'");
	i = 33;
	ret[i] = 0;
	if (n < 0)
	{
		neg = 1;
		ret[--i] = base[-(n % bsize)];
		n = -(n / bsize);
	}
	while (n % bsize || n / bsize)
	{
		ret[--i] = base[n % bsize];
		n /= bsize;
	}
	if (neg == 1)
		ret[--i] = '-';
	else if (i == 33)
		ret[--i] = '0';
	return (ft_strdup(&ret[i]));
}

int	main()
{
	//long c = -2147483648;
	int c = -2147483648;
	char *b = "0123456789abcdef";
	while (c += 2147483  < 2147483647)
	{
	//	printf("'%s' '%s' '%s'\n", ft_itoa_base(c, b), ft_litoa_base(c, b),ft_litoa_base(c, b));
		printf("'%s' '%s'\n", ft_litoa_base(c, b), ft_litoa_base_old(c, b));
	}
	return (0);
}