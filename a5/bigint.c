/*
 * your program signature
 Name: Ashish Sharma
 Email: shar4454@mylaurier.ca
 ID: 169044454
 Date: 02/17/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

BIGINT bigint(char *p)
{
    BIGINT bn = {0};
    if (p == NULL)
        return bn;
    else if (!(*p >= '0' && *p <= '9'))
    { // not begin with digits
        return bn;
    }
    else if (*p == '0' && *(p + 1) == '\0')
    { // just "0"
        dll_insert_end(&bn, new_node(*p - '0'));
        return bn;
    }
    else
    {
        while (*p)
        {
            if (*p >= '0' && *p <= '9')
            {
                dll_insert_end(&bn, new_node(*p - '0'));
            }
            else
            {
                dll_clean(&bn);
                break;
            }
            p++;
        }
        return bn;
    }
}

BIGINT bigint_add(BIGINT oprand1, BIGINT oprand2)
{
    // your code
    BIGINT result = { 0, NULL, NULL };
	int carry = 0;

	NODE *ptr1 = oprand1.end;
	NODE *ptr2 = oprand2.end;

	while (ptr1 != NULL || ptr2 != NULL || carry != 0) {
		int sum = carry;
		if (ptr1 != NULL) {
			sum += ptr1->data;
			ptr1 = ptr1->prev;
		}
		if (ptr2 != NULL) {
			sum += ptr2->data;
			ptr2 = ptr2->prev;
		}

		carry = sum / 10;
		dll_insert_start(&result, new_node(sum % 10));

	}
	return result;
}

BIGINT bigint_fibonacci(int n)
{
    // your code
    if (n <= 0) {
		return bigint("0");
	} else if (n == 1) {
		return bigint("1");
	}

	BIGINT a = bigint("0");
	BIGINT b = bigint("1");
	BIGINT c = { 0, NULL, NULL };

	for (int i = 2; i <= n; ++i) {
		c = bigint_add(a, b);
		dll_clean(&a);
		a = b;
		b = c;
	}

	dll_clean(&a);
	return b;
}
