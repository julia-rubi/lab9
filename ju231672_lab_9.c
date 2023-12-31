// Julianna Diaz
// COP 3502 
// Professor Torosdagli
// 30 July 2023

#include <stdio.h>

// RecordType
struct RecordType
{
	int		id;
	char	name;
	int		order; 
};

// Struct called HashType that holds the records and the next
struct HashType
{
	struct RecordType record;
  	struct HashType *next;

};

// Hash function that returns the remainder after it is divided by 31
int hash(int x)
{
	return x % 31;
}

// parses input file to an integer array
int parseData(char* inputFileName, struct RecordType** ppData)
{
	FILE* inFile = fopen(inputFileName, "r");
	int dataSz = 0;
	int i, n;
	char c;
	struct RecordType *pRecord;
	*ppData = NULL;

	if (inFile)
	{
		fscanf(inFile, "%d\n", &dataSz);
		*ppData = (struct RecordType*) malloc(sizeof(struct RecordType) * dataSz);
		// Implement parse data block
		if (*ppData == NULL)
		{
			printf("Cannot allocate memory\n");
		}
		for (i = 0; i < dataSz; ++i)
		{
			pRecord = *ppData + i;
			fscanf(inFile, "%d ", &n);
			pRecord->id = n;
			fscanf(inFile, "%c ", &c);
			pRecord->name = c;
			fscanf(inFile, "%d ", &n);
			pRecord->order = n;
		}

		fclose(inFile);
	}

	return dataSz;
}

// prints the records
void printRecords(struct RecordType pData[], int dataSz)
{
	int i;
	printf("\nRecords:\n");
	for (i = 0; i < dataSz; ++i)
	{
		printf("\t%d %c %d\n", pData[i].id, pData[i].name, pData[i].order);
	}
	printf("\n\n");
}

// Function that displays the records in a certain hash format
void displayRecordsInHash(struct HashType *pHashArray, int hashSz)
{

    // Counter variable
	int i;

    // For loop that runs until it reaches the max hash size
	for (i=0; i < hashSz; i++)
	{
        // While loop that runs until the last id 
		while(pHashArray[i].record.id != NULL){
            // Prints the index number, id, record name, and record order
			printf("Index %d -> %d, %c, %d\n", i, pHashArray[i].record.id, pHashArray[i].record.name, pHashArray[i].record.order);
		}
	}
}


int main(void)
{
	struct RecordType *pRecords;
	int recordSz = 0;


	recordSz = parseData("input.txt", &pRecords);
	printRecords(pRecords, recordSz);
    // Displays the records in hash format
	displayRecordsInHash(pRecords, recordSz);
}