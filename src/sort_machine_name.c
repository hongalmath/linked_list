#include "main.h"
void sort_machine_by_name(void)
{
	int plant_id;
	printf("Enter plant id: ");
	scanf("%d", &plant_id);

	struct plant *plant_node = plant_head;
	while (plant_node && plant_node->plant_id != plant_id)
		plant_node = plant_node->link;

	if (!plant_node)
	{
		printf("Plant not found\n");
		return;
	}

	if (!plant_node->machine_head)
	{
		printf("No machines present in this plant\n");
		return;
	}

	if (plant_node->machine_head->link == NULL)
	{
		printf("Only one machine present, sorting not required\n");
		struct eagle *m = plant_node->machine_head;
		printf("\nMachine: %s (%d)\n", m->machine_name, m->machine_id);
		printf("Production: %d\n", m->production);
		return;
	}

	struct eagle *p, *q;

	for (p = plant_node->machine_head; p->link != NULL; p = p->link)
	{
		for (q = p->link; q != NULL; q = q->link)
		{
			if (strcmp(p->machine_name, q->machine_name) > 0)
			{
				int temp_id = p->machine_id;
				p->machine_id = q->machine_id;
				q->machine_id = temp_id;

				int temp_prod = p->production;
				p->production = q->production;
				q->production = temp_prod;

				int temp_cycle = p->cycle;
				p->cycle = q->cycle;
				q->cycle = temp_cycle;

				char temp_name[30];
				strcpy(temp_name, p->machine_name);
				strcpy(p->machine_name, q->machine_name);
				strcpy(q->machine_name, temp_name);
			}
		}
	}

	printf("\n--- Machines Sorted by Name (A → Z) ---\n");
	for (p = plant_node->machine_head; p; p = p->link)
	{
		printf("\nMachine: %s (%d)\n", p->machine_name, p->machine_id);
		printf("Production: %d\n", p->production);
	}
}

