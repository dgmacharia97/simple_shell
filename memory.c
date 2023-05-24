#include "alx.h"

/**
 * bfree -  frees a Ptr and Null the address
 * @ptr: Ptr to free
 *
 * Return: If freed return 1,else 0.
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
