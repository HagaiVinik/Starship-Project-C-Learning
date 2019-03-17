#include "Starship.h"

//function print all aliens in system data.
//input: pointer of file. output: return 0.
int print_all(FILE *fp)
{
	alien alien_print ;
	int count = 0 ;

	fp = fopen("starship.dat", "rb");
	fread(&alien_print, sizeof(alien), 1, fp);
	while(!feof(fp))
	{
		printf("{ALIEN ID: %d , ALIEN NAME: %s , ALIEN STAR NAME: %s ,ALIEN AGE: %d }\n",alien_print.id,alien_print.name,alien_print.star_name,alien_print.age);
		count++;
		fread(&alien_print, sizeof(alien), 1, fp);		
		
	}
	printf("TOTAL ALIENS : %d\n" , count);
	fclose(fp);
	return 0;
}

//function add new alien to system data.
//input: pointer of file. output: return 0.
int add_alien(FILE *fp)
{
	// input alien details.
	alien alien_read;
	printf("please enter id:\n");
	scanf("%d",&alien_read.id);
	printf("please enter name:\n");
	scanf("%s",&alien_read.name);
	printf("please enter star name:\n");
	scanf("%s",&alien_read.star_name);
	printf("please enter age:\n");
	scanf("%d",&alien_read.age);
	
	fp = fopen("starship.dat", "ab");
	fwrite(&alien_read, sizeof(alien), 1, fp);
	fclose(fp);
	return 0;
}

//function update alien's details that exist in system data.
//input: pointer of file. output: return 0.
int update_alien(FILE *fp)
{
	int end = 0;
	alien alien_temp;
	int temp_id;
	printf("please enter alien's id you want to update:\n");
	scanf("%d", &temp_id);
	fp = fopen("starship.dat", "r+b");
	fread(&alien_temp, sizeof(alien), 1, fp);
	while(!feof(fp) && end == 0)
	{
		if(alien_temp.id == temp_id )
		{
			printf("please enter new name:\n");
			scanf("%s",&alien_temp.name);
			printf("please enter new star name:\n");
			scanf("%s",&alien_temp.star_name);
			printf("please enter new age:\n");
			scanf("%d",&alien_temp.age);
			fseek(fp,-1 * sizeof(alien),SEEK_CUR);
			fwrite(&alien_temp, sizeof(alien), 1, fp);
			end = 1;
		}
		else
		{
			fread(&alien_temp, sizeof(alien), 1, fp);
		}
	}
	fclose(fp);
	return 0;

}

//function start program, main func.
//input: none. output: none.
void main(void)
{
	FILE *fp;
	int i = 1;
	int user_choice;
	fp = fopen("starship.dat", "wb");
	fclose(fp);
	//user interface:
	printf("=================    ENTERPRIZE SOFTWARE VERSION 1.1.2    =================\n\n");
	printf("welcome to EnterPrize Starship! here is the option menu:\n\n");
	printf("1 - print all alien's data collected by starship.\n");
	printf("2 - add new alien to system data.\n");
	printf("3 - update alien's details that Exists in system data\n");
	printf("4 - exit software.\n");
	printf("please choose: ");
	scanf("%d" , &user_choice);
	
	while ( user_choice != 4)
	{
		//check what user chose, start func chosen. 
		(user_choice > 4 || user_choice < 1) ? printf("ERROR: choose a relevant number:\n\n"): 0 ;
		(user_choice == 1) ? i = print_all(fp) : 0;
		(user_choice == 2) ? i = add_alien(fp) : 0;
		(user_choice == 3) ? i = update_alien(fp) : 0;
		(i == 0 ) ? printf("\nsuccessfully done.\n\n") : printf("\nERROR: function failed.\n\n") ;
		i = 1;
		printf("OPTION MENU:\n\n");
		printf("1 - print all alien's data collected by starship.\n");
		printf("2 - add new alien to system data.\n");
		printf("3 - update alien's details that Exists in system data\n");
		printf("4 - exit software.\n");
		printf("\nplease choose: ");
		scanf("%d" , &user_choice);
	}
	printf("\ngoodbye!\n");
	// end program.
}