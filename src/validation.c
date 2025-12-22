#include "main.h"

void display_all_plants(void)
{
	struct plant *temp = plant_head;
	int count = 0;

	printf("\n===============================\n");
	printf("Available Plants:\n");
	printf("===============================\n");

	        printf("\n________________________________________________\n");
	while (temp)
	{
		printf("Plant ID: %d | Plant Name: %s | Machines: %d\n",temp->plant_id,temp->plant_name,temp->total_machines);
		count++;
		temp = temp->link;
	}
	        printf("__________________________________________________\n");

	printf("Total Plants: %d\n", count);
}




long long int validation()
{
	long long int v;
	while (scanf("%lld", &v) != 1)
	{
		while (getchar() != '\n');
		printf("Enter valid number: ");
	}
	return v;
}


int valid_plant_id(const char *s)
{
	if (strlen(s) != 3)
		return 0;

	for (int i = 0; s[i]; i++)
	{
		if (!isdigit(s[i]))
			return 0;
	}

	return 1;
}

// Check if plant name is exactly 3 chars: 1 digit + 2 letters
int valid_plant_name(const char *s)
{
	if (strlen(s) != 3)
		return 0;
	if (!isdigit(s[0]))
		return 0;

	if (!isalpha(s[1]) || !isalpha(s[2]))
		return 0;

	return 1;
}

// Check if location contains only letters
int valid_location(const char *s)
{
	for (int i = 0; s[i]; i++)
	{
		if (!isalpha(s[i]))
			return 0;
	}
	return 1;
}

// Check if plant ID already exists in linked list
int plant_id_exists(int plant_id)
{
	struct plant *temp = plant_head;
	while (temp)
	{
		if (temp->plant_id == plant_id)
			return 1;
		temp = temp->link;
	}
	return 0;
}


// Check if plant name already exists in linked list
int plant_name_exists(const char *name)
{
	struct plant *temp = plant_head;
	while (temp)
	{
		if (strcmp(temp->plant_name, name) == 0)
			return 1;
		temp = temp->link;
	}
	return 0;
}


int valid_machine_id(char *s)
{
	if (strlen(s) != 4)
		return 0;

	for (int i = 0; s[i]; i++)
		if (!isdigit(s[i]))
			return 0;

	return 1;
}

int valid_machine_name(char *s)
{

	if (strlen(s) != 2)
		return 0;

	if(!isdigit(s[0]))
		return 0;
	if(!isalpha(s[1]))
		return 0;
	return 1;
}

int machine_exists_in_plant(struct plant *plant_node, int machine_id, const char *machine_name)
{
	struct eagle *temp = plant_node->machine_head;

	while (temp)
	{
		if (temp->machine_id == machine_id ||
				strcmp(temp->machine_name, machine_name) == 0)
		{
			return 1;
		}
		temp = temp->link;
	}
	return 0;
}
