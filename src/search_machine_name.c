#include "main.h"
void search_machine_by_name(void)
{
	if (!plant_head)
	{
		printf("No plants available\n");
		return;
	}

	char name[30];
	printf("Enter Machine Name to search: ");
	scanf("%s", name);

	struct plant *p = plant_head;
	while (p)
	{
		struct eagle *m = p->machine_head;
		while (m)
		{
			if (strcmp(m->machine_name, name) == 0)
			{
				printf("\n--- Machine Found ---\n");
				printf("Machine ID: %d\n", m->machine_id);
				printf("Machine Name: %s\n", m->machine_name);
				printf("Production: %d\n", m->production);
				printf("Belongs to Plant: %s (%d)\n", p->plant_name, p->plant_id);
				return;
			}
			m = m->link;
		}
		p = p->link;
	}

	printf("Machine with Name '%s' not found\n", name);
}

