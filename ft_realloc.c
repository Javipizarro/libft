/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpizarro <jpizarro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:32:02 by jpizarro          #+#    #+#             */
/*   Updated: 2022/07/12 17:50:00 by jpizarro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Creates a new allocation, copies as much of the old data pointed to by
**	ptr as will fit to the new allocation, frees the old allocation, and
**	returns a pointer to the allocated memory.
**	If ptr is NULL, it is identical to a call to malloc() for size bytes.
**	If size is zero and ptr is not NULL, a new, minimum sized object
**	is allocated and the original object is freed.
**	It does not zero-fill the additional memory.
*/

void	*realloc(void *ptr, size_t size)
{
	void *temp;

	if (!size && ptr)
		size = 1;
	temp = malloc(size);
	if (ptr)
	{
		ft_memccpy(temp, ptr, '\0', size);
		free (ptr);
	}
	return (temp);
}