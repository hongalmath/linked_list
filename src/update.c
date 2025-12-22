#include"main.h"
void update(void)
{
	char plant_id_buffer[10], machine_id_buffer[10];
	char plant_name[30];
	char start_hour_str[5], start_minute_str[5], end_hour_str[5], end_minute_str[5];
	int plant_id, machine_id;
	int start_hour, start_minute, end_hour, end_minute;

	if (plant_head == NULL)
	{
		printf("No plant is present\n");
		return;
	}

	struct plant *plant_node = NULL;

	while (1)
	{
		printf("Enter plant id: ");
		scanf("%s", plant_id_buffer);

		int valid = 1;
		for (int i = 0; plant_id_buffer[i]; i++)
		{
			if (!isdigit(plant_id_buffer[i]))
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

		plant_id = atoi(plant_id_buffer);

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
		printf("No machine is present to update\n");
		return;
	}

	struct eagle *machine_node = NULL;

	while (1)
	{
		printf("Enter machine id: ");
		scanf("%s", machine_id_buffer);

		int valid = 1;
		for (int i = 0; machine_id_buffer[i]; i++)
		{
			if (!isdigit(machine_id_buffer[i]))
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

		machine_id = atoi(machine_id_buffer);

		machine_node = plant_node->machine_head;
		while (machine_node && machine_node->machine_id != machine_id)
			machine_node = machine_node->link;

		if (machine_node == NULL)
		{
			printf("Machine not found in this plant. Try again.\n");
			continue;
		}

		break;
	}

	while (1)
	{
		printf("Enter start hour (0-23): ");
		scanf("%s", start_hour_str);
		int valid = 1;
		for (int i = 0; start_hour_str[i]; i++)
			if (!isdigit(start_hour_str[i]))
				valid = 0;

		if (!valid)
		{
			printf("Invalid start hour\n");
			continue;
		}

		start_hour = atoi(start_hour_str);
		if (start_hour < 0 || start_hour > 23)
		{
			printf("Start hour must be 0-23\n");
			continue;
		}
		break;
	}

	while (1)
	{
		printf("Enter start minute (0-59): ");
		scanf("%s", start_minute_str);
		int valid = 1;
		for (int i = 0; start_minute_str[i]; i++)
			if (!isdigit(start_minute_str[i]))
				valid = 0;

		if (!valid)
		{
			printf("Invalid start minute\n");
			continue;
		}

		start_minute = atoi(start_minute_str);
		if (start_minute < 0 || start_minute > 59)
		{
			printf("Start minute must be 0-59\n");
			continue;
		}
		break;
	}

	while (1)
	{
		printf("Enter end hour (0-23): ");
		scanf("%s", end_hour_str);
		int valid = 1;
		for (int i = 0; end_hour_str[i]; i++)
			if (!isdigit(end_hour_str[i]))
				valid = 0;

		if (!valid)
		{
			printf("Invalid end hour\n");
			continue;
		}

		end_hour = atoi(end_hour_str);
		if (end_hour < 0 || end_hour > 23)
		{
			printf("End hour must be 0-23\n");
			continue;
		}
		break;
	}

	while (1)
	{
		printf("Enter end minute (0-59): ");
		scanf("%s", end_minute_str);
		int valid = 1;
		for (int i = 0; end_minute_str[i]; i++)
			if (!isdigit(end_minute_str[i]))
				valid = 0;

		if (!valid)
		{
			printf("Invalid end minute\n");
			continue;
		}

		end_minute = atoi(end_minute_str);
		if (end_minute < 0 || end_minute > 59)
		{
			printf("End minute must be 0-59\n");
			continue;
		}
		break;
	}

	int total_minutes = (end_hour * 60 + end_minute) - (start_hour * 60 + start_minute);
	if (total_minutes <= 0)
	{
		printf("Invalid time range\n");
		return;
	}

	machine_node->cycle += total_minutes;
	machine_node->production += total_minutes;
	plant_node->total_production += total_minutes;

	printf("Machine updated successfully\n");
}
