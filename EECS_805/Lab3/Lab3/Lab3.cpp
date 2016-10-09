// Lab3
// Aymeric

//ASSIGNEMENT 1

#include "stdafx.h"

#define MAX 10  /* Size of the array */

void init_array(int *array, int value);
void copy_array(int *array1, int *array2);

#if 0
int main() {
	int  array_1[MAX];				// array of a size of MAX
	int *array_ptr = array_1;		// pointer to the address &array_1[0]

	int init_value = 0x5A;
	int i;

	init_array(array_1, init_value);

	for (i = 0; i < MAX; i++, array_ptr++) {		// show what is inside the array
		printf("i = %d, value in array = %x \n", i, *array_ptr);
	}

	return 0;
}

#endif

#if 1

int main()
{
	int  array_1[MAX];
	int  array_2[MAX];

	int *array_ptr1 = array_1;			// pointer to the address &array_1[0]
	int *array_ptr2 = array_2;			// pointer to the address &array_2[0]

	int init_value = 0x5A;
	int i;

	printf("Initializing the array1 to init_value \n")

	/* Initializing the array */
	init_array(array_1, init_value);

	printf("copy array_1 to array_2 \n")

	/* copy array_1 to array_2 */
	copy_array(array_1, array_2);

	for (i = 0; i < MAX; i++, array_ptr2++) {		// show what is inside the array
		printf("i = %d, value in array2 = %x \n", i, *array_ptr2);
	}

	return 0;
}

#endif

// Functions

void init_array(int *array, int value) {
	int i;

	for (i = 0; i < MAX; i++, array++)
		*array = value;
}

void copy_array(int *array1, int *array2) {
	int i;

	while (*array1) {
		*(array2++) = *(array1++);
	}
}
