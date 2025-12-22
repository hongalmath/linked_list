#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct eagle
{
	int machine_id;
	char machine_name[20];
	int cycle;
	int production;
	struct eagle *link;
};

struct plant
{
	int plant_id;
	char plant_name[30];
	char location[30];
	int total_machines;
	int total_production;
	struct eagle *machine_head;
	struct plant *link;
};

extern struct plant *plant_head;
extern int plant_count;

void add_plant(void);
void add_machine(void);

void delete_plant(void);
void delete_machine(void);

void update(void);
void view_status(void);

void search_plant_by_id(void);
void search_plant_by_name(void);
void search_machine_by_id(void);
void search_machine_by_name(void);

void sort_plant_by_id(void);
void sort_plant_by_name(void);
void sort_plant_by_production(void);

void sort_machine_by_id(void);
void sort_machine_by_name(void);
void sort_machine_by_production(void);

long long int validation();
struct plant *find_plant(int plant_id, char *plant_name);

int valid_plant_id(const char *s);
int valid_plant_name(const char *s);
int valid_location(const char *s);
int plant_id_exists(int plant_id);
int plant_name_exists(const char *name);

void display_all_plants(void);

int valid_machine_id(char *s);
int valid_machine_name(char *s);
int machine_exists_in_plant(struct plant *plant_node, int machine_id, const char *machine_name);
