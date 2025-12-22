#include "main.h"
struct plant *find_plant(int plant_id, char *plant_name)
{
	struct plant *temp = plant_head;
	while (temp)
	{
		if (temp->plant_id == plant_id && strcmp(temp->plant_name, plant_name) == 0)
			return temp;
		temp = temp->link;
	}
	return NULL;
}

