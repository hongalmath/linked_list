#include "main.h"
void search_plant_by_name(void)
{
	if (plant_head == NULL)
	{
		printf("No plants available\n");
		return;
	}

	char name[30];
	printf("Enter Plant Name to search: ");
	scanf(" %29[^\n]", name);

	struct plant *temp = plant_head;
	while (temp)
	{
		if (strcmp(temp->plant_name, name) == 0)
		{
			printf("\n--- Plant Found ---\n");
			printf("Plant ID: %d\n", temp->plant_id);
			printf("Plant Name: %s\n", temp->plant_name);
			printf("Location: %s\n", temp->location);
			printf("Total Production: %d\n", temp->total_production);
			printf("Total Machines: %d\n", temp->total_machines);
			return;
		}
		temp = temp->link;
	}

	printf("Plant with Name '%s' not found\n", name);
}
