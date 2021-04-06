/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:22:41 by jpizarro          #+#    #+#             */
/*   Updated: 2021/04/06 09:20:10 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Allocates (with malloc(3)) and returns an array of strings obtained
**	by splitting ’s’ using the character ’c’ as a delimiter. The array
**	must be ended by a NULL pointer.
*/

#include "libft.h"

char	**ft_split(const char *s, char c)
{
	char	**mem;
	size_t	cnt[3];

	mem = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!s || !mem)
		return (NULL);
	cnt[0] = 0;
	cnt[2] = 0;
	while (cnt[0] < ft_wordcount(s, c))
	{
		while (s[cnt[2]] == c)
			cnt[2]++;
		cnt[1] = 0;
		while (s[cnt[2] + cnt[1]] != c && s[cnt[2] + cnt[1]])
			cnt[1]++;
		mem[cnt[0]] = malloc(sizeof(char) * (cnt[1] + 1));
		if (!mem[cnt[0]])
			return (NULL);
		ft_memcpy(mem[cnt[0]], s + cnt[2], cnt[1]);
		mem[cnt[0]++][cnt[1]] = 0;
		cnt[2] += cnt[1];
	}
	mem[cnt[0]] = NULL;
	return (mem);
}
