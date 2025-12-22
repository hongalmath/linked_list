#include"main.h"
void search_plant_by_id(void)
{
        if (plant_head == NULL)
        {
                printf("No plants available\n");
                return;
        }

        int plant_id;
        printf("Enter Plant ID to search: ");
        scanf("%d", &plant_id);

        struct plant *temp = plant_head;
        while (temp)
        {
                if (temp->plant_id == plant_id)
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

        printf("Plant with ID %d not found\n", plant_id);
}
