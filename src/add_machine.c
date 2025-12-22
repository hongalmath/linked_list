#include "main.h"
#define MAX_MACHINES 10
void add_machine(void)
{
	char buffer[50];
	int plant_id;
	char plant_name[30];

	if (plant_head == NULL)
	{
		printf("No plant is present\n");
		return;
	}

	struct plant *plant_node = NULL;
	display_all_plants();

	while (1)
	{
		printf("\nEnter plant id: ");
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

		if (plant_node->total_machines >= MAX_MACHINES)
		{
			printf("Machine limit reached! Maximum 10 machines allowed per plant.\n");
			return;
		}

		break;
	}

	struct eagle *new_machine = malloc(sizeof(struct eagle));
	if (!new_machine)
	{
		printf("Memory allocation failed\n");
		return;
	}

	do
	{
		printf("Enter machine id (4 digits only): ");
		scanf("%s", buffer);

		if (!valid_machine_id(buffer))
		{
			printf("Invalid machine id. Must be 4 digits.\n");
			continue;
		}

		new_machine->machine_id = atoi(buffer);
		break;

	} while (1);

	while (1)
	{
		printf("Enter machine name (1G): ");
		scanf("%s", new_machine->machine_name);

		if (!valid_machine_name(new_machine->machine_name))
		{
			printf("Invalid machine name\n");
			continue;
		}

		if (machine_exists_in_plant(plant_node,
					new_machine->machine_id,
					new_machine->machine_name))
		{
			printf("Machine ID or name already exists in this plant\n");
			continue;
		}

		break;
	}

	new_machine->cycle = 0;
	new_machine->production = 0;
	new_machine->link = plant_node->machine_head;
	plant_node->machine_head = new_machine;
	plant_node->total_machines++;

	printf("Machine added successfully under Plant %s (ID: %d)\n",
			plant_node->plant_name,
			plant_node->plant_id);
}

