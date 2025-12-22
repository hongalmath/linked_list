#include "main.h"
struct plant *plant_head = NULL;
int plant_count = 0;

int main()
{
	int choice;

	while (1)
	{
		printf("\n+==============================================+\n");
		printf("|               E A G L E PLANT                |\n");
		printf("+==============================================+\n");
		printf("| No  | Operation                              |\n");
		printf("+-----+----------------------------------------+\n");

		printf("|  1  | Add Plant                              |\n");
		printf("|  2  | Add Machine                            |\n");
		printf("|  3  | Delete Plant                           |\n");
		printf("|  4  | Delete Machine                         |\n");
		printf("|  5  | View Status                            |\n");
		printf("|  6  | Update Machine                         |\n");

		printf("+-----+----------------------------------------+\n");
		printf("|           SORT PLANT OPERATIONS              |\n");
		printf("+-----+----------------------------------------+\n");
		printf("|  7  | Sort Plant by Production               |\n");
		printf("|  8  | Sort Plant by Name                     |\n");
		printf("|  9  | Sort Plant by ID                       |\n");

		printf("+-----+----------------------------------------+\n");
		printf("|          SORT MACHINE OPERATIONS             |\n");
		printf("+-----+----------------------------------------+\n");
		printf("| 10  | Sort Machine by Production             |\n");
		printf("| 11  | Sort Machine by Name                   |\n");
		printf("| 12  | Sort Machine by ID                     |\n");

		printf("+-----+----------------------------------------+\n");
		printf("|          SEARCH PLANT OPERATIONS             |\n");
		printf("+-----+----------------------------------------+\n");
		printf("| 13  | Search Plant by Name                   |\n");
		printf("| 14  | Search Plant by ID                     |\n");

		printf("+-----+----------------------------------------+\n");
		printf("|         SEARCH MACHINE OPERATIONS            |\n");
		printf("+-----+----------------------------------------+\n");
		printf("| 15  | Search Machine by ID                   |\n");
		printf("| 16  | Search Machine by Name                 |\n");

		printf("+==============================================+\n");
		printf("| 17  | Exit                                   |\n");
		printf("+==============================================+\n");



		printf("Enter choice: ");

		choice = validation();

		switch (choice)
		{
			case 1: 
				add_plant(); 
				break;
			case 2: 
				add_machine(); 
				break;
			case 3: 
				delete_plant(); 
				break;
			case 4: 
				delete_machine(); 
				break;
			case 5: 
				view_status(); 
				break;
			case 6: 
				update(); 
				break;
			case 7: 
				sort_plant_by_production(); 
				break;
			case 8: 
				sort_plant_by_name(); 
				break;
			case 9: 
				sort_plant_by_id(); 
				break;
			case 10: 
				sort_machine_by_production(); 
				break;
			case 11: 
				sort_machine_by_name(); 
				break;
			case 12: 
				sort_machine_by_id(); 
				break;
			case 13: 
				search_plant_by_id(); 
				break;
			case 14:
				search_plant_by_id();
				break;
			case 15:
				search_machine_by_id();
				break;
			case 16:
				search_machine_by_name();
				break;
			case 17: 
				exit(0);
			default: 
				printf("Invalid choice\n");
		}
	}
}

