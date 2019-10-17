/* A program that simulates a paging system using the ageing algorithm.
*  The number of page frames is a parameter. */

#include <stdio.h>
#include <stdlib.h>

#define BUFF 555

/* A struct for a table entry */
typedef struct table_entry
{
	unsigned int counter;
	int pg_num;
}frame;

/* mask to be used later on for recently referencd pages */
int mask = 1<<(sizeof(int)*8-1);


int main()
{
	int page_frame_num;
	int hit = 0;
	int miss = 0;
	int current_index = 0;
	scanf("%d", &page_frame_num);

	/* create the table of page frames */
	frame table[page_frame_num];

	/* initialize everything to zero */
	for (int i = 0; i < page_frame_num; ++i)
	{
		table[i].pg_num = 0;
		table[i].counter = 0;
	}

	/* open the input file and read */
	FILE *fp = fopen("Lab 09 input.txt", "r");

	int current_frame;

	while(fscanf(fp, "%d", &current_frame) != EOF)
	{
		int flag = 0;	/* flag to keep track of if new page has been found or added yet */
		for (int i = 0; i < page_frame_num; ++i)
		{
			/* check if the page number we just read is already in our table */
			if (current_frame == table[i].pg_num)
			{
				hit++;
				current_index = i;
				flag = 1;
				break;
			}
		}

		/* If it's not in the table, we check if there's an empty place */
		if (flag == 0)
		{
			for (int i = 0; i < page_frame_num; ++i)
			{
				if (table[i].pg_num == 0)
				{
					table[i].pg_num = current_frame;
					current_index = i;
					flag = 1;
					miss++;
					break;
				}
			}
		}

		/* if there is no empty place, we check for the one with the least counter and replace it */
		if (flag == 0)
		{
			miss++;
			int youngest_age = 1<<30;
			int page_to_remove = 0;
			int index_to_remove = 0;

			for (int i = 0; i < page_frame_num; ++i)
			{
				if (table[i].counter < youngest_age)
				 {
				 	youngest_age = table[i].counter;
				 	page_to_remove = table[i].pg_num;
				 	index_to_remove = i;
				 	current_index = i;
				 }
			}
			table[index_to_remove].pg_num = current_frame;
		}

		for (int i = 0; i < page_frame_num; ++i)
		{
			table[i].counter = table[i].counter >> 1;
		}

		table[current_index].counter = table[current_index].counter | mask;

	}

	double ratio = (double)hit/miss;
	printf("Hit = %d, Miss = %d, Hit/Miss ratio = %f\n", hit, miss, ratio);

	fclose(fp);
	return 0;
}
