#include"main.h"
void delete_machine(void)
{
	if (plant_head == NULL)
	{
		printf("No plant is present\n");
		return;
	}

	char buffer[50];
	int plant_id, machine_id;
	char plant_name[30];
	struct plant *plant_node = NULL;

	
	while (1)
	{
		printf("Enter plant id: ");
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

		printf("Enter plant name: ");
		scanf("%s", plant_name);

		plant_node = find_plant(plant_id, plant_name);
		if (plant_node == NULL)
		{
			printf("Wrong plant id or name. Try again.\n");
			continue;
		}

		break;
	}

	if (plant_node->machine_head == NULL)
	{
		printf("No machines in this plant\n");
		return;
	}

	
	while (1)
	{
		printf("Enter machine id to delete: ");
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
			printf("Invalid machine id! Only digits allowed.\n");
			continue;
		}

		machine_id = atoi(buffer);
		break;
	}

	
	struct eagle *current = plant_node->machine_head;
	struct eagle *previous = NULL;

	while (current)
	{
		if (current->machine_id == machine_id)
		{
			if (previous == NULL)
				plant_node->machine_head = current->link;
			else
				previous->link = current->link;

			free(current);
			plant_node->total_machines--;

			printf("Machine with ID %d deleted successfully from Plant %s\n", machine_id, plant_node->plant_name);
			return;
		}

		previous = current;
		current = current->link;
	}

	printf("Machine ID does not exist in this plant\n");
}
