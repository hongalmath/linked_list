#include "main.h"
#define MAX_PLANTS 20
void add_plant(void)
{
	if (plant_count >= MAX_PLANTS)
	{
		printf("Plant limit reached! Maximum 20 plants allowed.\n");
		return;
	}

	int choice;
	char buffer[50];
	struct plant *temp = plant_head;

	struct plant *new_plant = malloc(sizeof(struct plant));
	if (new_plant == NULL)
	{
		printf("Memory allocation failed\n");
		return;
	}

	while (1)
	{
		printf("\nEnter plant id (3 digits only): ");
		scanf("%s", buffer);

		if (!valid_plant_id(buffer))
		{
			printf("Invalid plant id! It should be 3 digits only.\n");
			continue;
		}

		new_plant->plant_id = atoi(buffer);

		if (plant_id_exists(new_plant->plant_id))
		{
			printf("Plant ID already exists! Enter a different ID.\n");
			continue;
		}

		break;
	}

	while (1)
	{
		printf("Enter plant name (eg: 1WE): ");
		scanf("%s", new_plant->plant_name);

		if (!valid_plant_name(new_plant->plant_name))
		{
			printf("Invalid plant name! Must be exactly 3 characters.\n");
			continue;
		}

		if (plant_name_exists(new_plant->plant_name))
		{
			printf("Plant name already exists! Enter a different name.\n");
			continue;
		}

		break;
	}

	while (1)
	{
		printf("\nSelect plant location:\n");
		printf("1. Pune\n");
		printf("2. Gujarat\n");
		printf("3. Belgaum\n");
		printf("4. Chennai\n");
		printf("Enter your choice (1-4): ");

		if (scanf("%d", &choice) != 1)
		{
			while (getchar() != '\n');
			printf("Invalid input! Please enter a number 1-4.\n");
			continue;
		}

		switch (choice)
		{
			case 1:
				strcpy(new_plant->location, "Pune");
				break;
			case 2:
				strcpy(new_plant->location, "Gujarat");
				break;
			case 3:
				strcpy(new_plant->location, "Belgaum");
				break;
			case 4:
				strcpy(new_plant->location, "Chennai");
				break;
			default:
				printf("Invalid choice! Please select 1-4.\n");
				continue;
		}
		break;
	}

	new_plant->total_machines = 0;
	new_plant->total_production = 0;
	new_plant->machine_head = NULL;
	new_plant->link = NULL;

	if (plant_head == NULL)
	{
		plant_head = new_plant;
	}
	else
	{
		while (temp->link)
			temp = temp->link;

		temp->link = new_plant;
	}

	plant_count++;
	printf("Plant added successfully! Location: %s\n", new_plant->location);
}

