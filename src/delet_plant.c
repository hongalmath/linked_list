#include "main.h"
void delete_plant(void)
{
	if (plant_head == NULL)
	{
		printf("No plant is present\n");
		return;
	}

	struct plant *current = plant_head;
	struct plant *previous = NULL;
	char buffer[20];
	int plant_id;

	
	while (1)
	{
		printf("Enter plant id to delete: ");
		scanf("%s", buffer);

		int valid = 1;
		for (int i = 0; buffer[i]; i++)
		{
			if (!isdigit(buffer[i]))
			{
				valid = 0;
				break;
			}
		}

		if (!valid)
		{
			printf("Invalid plant id! Only digits allowed.\n");
			continue;
		}

		plant_id = atoi(buffer);
		break;
	}


	while (current)
	{
		if (current->plant_id == plant_id)
		{
			if (previous == NULL)
				plant_head = current->link;
			else
				previous->link = current->link;

			
			struct eagle *m = current->machine_head;
			while (m)
			{
				struct eagle *temp = m;
				m = m->link;
				free(temp);
			}

			free(current);
			plant_count--;

			printf("Plant with ID %d deleted successfully\n", plant_id);
			return;
		}

		previous = current;
		current = current->link;
	}

	printf("Plant ID does not exist\n");
}
