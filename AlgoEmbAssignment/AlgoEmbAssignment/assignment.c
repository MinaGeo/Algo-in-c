
#include <stdio.h>
typedef unsigned char uint8_t;
typedef signed char int8_t;
typedef signed int int32_t;


int8_t insertionSort(int32_t* array, uint8_t arraySize)
{
	if (sizeof(array) == 0 || array == NULL || arraySize == 0)//array is empty
	{
		return -1;
	}
	else if (arraySize == 0 || arraySize > 10)
	{
		return -2;
	}
	else
	{
		int temp, j;

		for (int i = 1; i < arraySize; i++) {

			temp = array[i];
			j = i - 1;

			while (array[j] > temp && j >= 0) {

				array[j + 1] = array[j];
				j = j - 1;
			}
			array[j + 1] = temp;
		}

		return 0;
	}
}
int8_t lcsGetSize(int32_t* array, uint8_t arraySize, uint8_t* sizeofLCS) {
	if (array == NULL || arraySize == 0) {
		return -1;
	}
	else if (arraySize > 10) {
		return -2;
	}

	// Sort the array using insertion sort
	int8_t result = insertionSort(array, arraySize);
	if (result != 0) {
		return result;
	}

	// Find the longest consecutive subsequence
	uint8_t currentLCS = 1;
	uint8_t maxLCS = 1;
	for (uint8_t i = 1; i < arraySize; i++) {
		if (array[i] - array[i - 1] == 1) {
			currentLCS++;
			if (currentLCS > maxLCS) {
				maxLCS = currentLCS;
			}
		}
		else {
			currentLCS = 1;
		}
	}

	if (maxLCS == 1) {
		return -3;
	}

	*sizeofLCS = maxLCS;
	return 0;


}
void printArray(int32_t* array, uint8_t arraySize)
{
	printf("The array is [");
	for (int8_t i = 0; i < arraySize; i++) {
		printf("%d, ", array[i]);
	}
	printf("]\n");
}
int main()
{
	int8_t printVal;
	uint8_t sizeofLCS;
	uint8_t input;
	uint8_t arraySize;
	int32_t array[12];


	while (1) {
		printf("Enter operation (i=insertion sort, l=LCS, q=quit): ");
		scanf_s("%c", &input);
		getchar(); // consume any remaining characters in the input stream
		switch (input) {
		case 'i':
			printf("Enter the size of the array (=<10): ");
			scanf_s("%d", &arraySize);
			getchar();

			printf("Enter elements that will undergo insertion sorting.\n*------------------------------------------------------------*\n");
			for (uint8_t i = 0; i < arraySize; i++) {
				printf("Enter element %d: ", i + 1);
				int result = scanf_s("%d", &array[i]);
				if (result == 0) {
					// User didn't enter any input, so break out of the loop
					break;
				}
				while (getchar() != '\n');

			}

			printVal = insertionSort(&array, arraySize);

			if (printVal == -1)
			{
				printf("*------------------------------------------------------------*\nArray is empty\n*------------------------------------------------------------*\n");

			}
			else if (printVal == -2)
			{
				printf("*------------------------------------------------------------*\narray has invalid size\n*------------------------------------------------------------*\n");

			}
			else
			{
				printf("*------------------------------------------------------------*\nSuccesfully printing array...\n");
				printArray(&array, arraySize);
				printf("*------------------------------------------------------------*\n");

			}
			break;
		case 'l':
			printf("Enter the size of the array (=<10): ");
			scanf_s("%d", &arraySize);
			getchar();

			printf("Enter elements that will undergo LCS\n*------------------------------------------------------------*\n");
			for (uint8_t i = 0; i < arraySize; i++) {
				printf("Enter element %d: ", i + 1);
				int result = scanf_s("%d", &array[i]);
				if (result == 0) {
					// User didn't enter any input, so break out of the loop
					break;
				}
				while (getchar() != '\n');

			}

			printVal = lcsGetSize(&array, arraySize, &sizeofLCS);
			if (printVal == -1)
			{
				printf("*------------------------------------------------------------*\nArray is empty\n*------------------------------------------------------------*\n");

			}
			else if (printVal == -2)
			{
				printf("*------------------------------------------------------------*\narray has invalid size\n*------------------------------------------------------------*\n");
			}
			else if (printVal == -3)
			{
				printf("*------------------------------------------------------------*\narray has no LCS\n*------------------------------------------------------------*\n");

			}
			else
			{
				printf("*------------------------------------------------------------*\nSuccesfully printing array...\n");
				printArray(&array, arraySize);
				printf("LCS Size is %d\n*------------------------------------------------------------*\n", sizeofLCS);

			}
			break;
		case 'q':
			exit(0);
		default:
			printf("Error: Invalid input\n");
			break;
		}
	}


	}
