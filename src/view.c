#include "main.h"
void view_status(void)
{
    struct plant *plant_node = plant_head;

    if (plant_node == NULL)
    {
        printf("No plant is present\n");
        return;
    }

    while (plant_node)
    {
        printf("\nPlant: %s (%d)\n", plant_node->plant_name, plant_node->plant_id);
        printf("Location: %s\n", plant_node->location);

        if (plant_node->machine_head == NULL)
        {
            printf("  No machine is present\n");
        }
        else
        {
            struct eagle *machine_node = plant_node->machine_head;
            while (machine_node)
            {
                printf("  Machine: %s (%d) Production: %d\n",machine_node->machine_name,machine_node->machine_id,machine_node->production);
                machine_node = machine_node->link;
            }
        }

        plant_node = plant_node->link;
    }
}

