#include"main.h"
void sort_plant_by_production(void)
{
	if (!plant_head)
	{
		printf("No plant is present to sort\n");
		return;
	}

	struct plant *p, *q;
	int count = 0;

	for (p = plant_head; p; p = p->link)
		if (p->total_production > 0)
			count++;

	if (count == 0)
	{
		printf("No production available\n");
		return;
	}

	if (count == 1)
	{
		printf("Only one plant has production, sorting not required\n");
		for (p = plant_head; p; p = p->link)
		{
			if (p->total_production > 0)
			{
				printf("\nPlant: %s (%d)\n", p->plant_name, p->plant_id);
				printf("  Total Production: %d\n", p->total_production);
				return;
			}
		}
	}

	for (p = plant_head; p->link != NULL; p = p->link)
	{
		for (q = p->link; q != NULL; q = q->link)
		{
			if (p->total_production > q->total_production && q->total_production > 0)
			{
				int temp_id = p->plant_id;
				p->plant_id = q->plant_id;
				q->plant_id = temp_id;

				int temp_prod = p->total_production;
				p->total_production = q->total_production;
				q->total_production = temp_prod;

				int temp_m = p->total_machines;
				p->total_machines = q->total_machines;
				q->total_machines = temp_m;

				char temp_name[30];
				strcpy(temp_name, p->plant_name);
				strcpy(p->plant_name, q->plant_name);
				strcpy(q->plant_name, temp_name);

				char temp_loc[30];
				strcpy(temp_loc, p->location);
				strcpy(p->location, q->location);
				strcpy(q->location, temp_loc);

				struct eagle *temp_mh = p->machine_head;
				p->machine_head = q->machine_head;
				q->machine_head = temp_mh;
			}
		}
	}

	printf("\n--- Plants Sorted by Production (Ascending) ---\n");
	for (p = plant_head; p; p = p->link)
	{
		if (p->total_production > 0)
		{
			printf("\nPlant: %s (%d)\n", p->plant_name, p->plant_id);
			printf("  Total Production: %d\n", p->total_production);
		}
	}
}
