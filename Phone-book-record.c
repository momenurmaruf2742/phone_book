#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>

void addrecord();
void viewlist();
void editrecord();
void deleterecord();

COORD coord = {0, 0};
void gotoxy(int x, int y)
{
 COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char Namee[10]={"maruf"};
char password[10]={"123456"};

FILE *fp, *ft;

char name[20];

struct contact
{
	char cust_name[30];
	char mob_no[11];
	char email[50];
};
struct contact temp_c;
FILE *ptr1;

int main()
{
    system("cls");
   system("color 1F");
   char ch,name[10];
   int i=0;
    printf("PHONE BOOK RECORD SYSTEM");
   printf("\n********************************* Log In ***********************************\n");
   printf("User Name: ");

   while(ch!=13)
   {
	ch=getch();
	if(ch!=13 && ch!=8 ){
	putch(ch);
	name[i] = ch;
	i++;
	}
   }
   name[i] = '\0';
   if(strcmp(name,Namee)==0)

   {
   char ch,pass[10];
   int i=0;
   printf("\nPassword: ");

   while(ch!=13)
   {
	ch=getch();
	if(ch!=13 && ch!=8)
    {
	putch('*');
	pass[i] = ch;
	i++;
	}
   }
   pass[i] = '\0';
   if(strcmp(pass,password)==0)
   {
	printf("\npassword successfully matched!!!\n");
    mainmenu();
   }
   else
   {
    //system("cls");
    system("COLOR 1C");
    printf("\nIncorrect Password!!!\n");
    printf("\nPlease re-enter Correct Password\n ");
    getch();
   }
}
   else
   {
	 {
	     system("COLOR 1C");
	 printf("\nIncorrect User Name!!!!\n");
	 printf("Please Re-enter Correct User Name");
	 }
	 getch();
   }
    return 0;
}

void mainmenu()
{

     system("cls");
    int c;

    gotoxy(2,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf(" MAIN MENU ");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,6);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Add Record");
    gotoxy(20,8);
    printf("\xDB\xDB\xDB\xDB\xB2 2. View All Record");
    gotoxy(20,10);
    printf("\xDB\xDB\xDB\xDB\xB2 3.Edit Record");
    gotoxy(20,12);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Delete Record");
    gotoxy(20,14);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Exit");
    gotoxy(20,16);

    printf("Enter Your Choice.");
    switch(getch())
    {
        case '1': addrecord();
        break;
        case '2': viewlist();
        break;
        case '3':editrecord();
        break;
        case '4':deleterecord();
        break;
        default:
         printf("You are wrong choice try in later.");
         system("cls");
            system("color 5");
            printf("\n\n\t\t<<<<***>>>> Thnak You I Will Try My Best To Help you <<<<***>>>>\n\n\t\t<<<<***>>>> BY: MD.Momenur Islam <<<<***>>>>\n\n\t\t<<<<***>>>> Bsc In Software Engineering <<<<***>>>>");

            getch();

            exit(0);
    }
}


void addrecord()
{
    char ch;

 FILE *fptr;
 system("cls");
	  fptr = fopen("Contact.txt", "a");

    if (fptr == NULL)
    {
        printf("File does not exists \n");
        return;
    }
	   system("cls");
	   ch='y';
	   while(ch=='y')
	   {
		system("cls");
		printf(" \t\t\tRCORD ENTRY\t\t\t ");
		printf("\n\tNAME : ");
		scanf("%s",&temp_c.cust_name);
		printf("\n\tCONTACT NO.   : ");
		scanf("%s",&temp_c.mob_no);
		printf("\n\tEMAIL ID    : ");
		scanf("%s",&temp_c.email);

		printf("\n\tSave");

		printf("\tCancel");

		printf("\n\nPress First charecter for the operation : ");
		ch=getche();
		if(ch=='s' || ch=='S')
		{
			fprintf(fptr," %s %s %s\n",temp_c.cust_name,temp_c.mob_no,temp_c.email);
			fprintf(fptr,"\n");
			system("cls");

			printf("\nRecord Added Successfully!!!!!");

			printf("\nMore entries  [y/n] ");
			ch=getche();

		}
	   }
	   fclose(fptr);

printf("Press enter any key and go to main menu>> ");
getche();
mainmenu();
}


void viewlist()
{
    char ch;
 int id,i;
 system("cls");
	   ptr1=fopen("Contact.txt","r");
	   if(ptr1==NULL)
	   {
		printf("\n\t Can not open File! ");
		exit(0);
	   }
	   system("cls");
	   gotoxy(8,48);
	   printf("Press Anykey to go to Rcord MENU!!!");
	   gotoxy(30,8);
	   printf(" NUMBER LIST ");
	   i=14;
	   gotoxy(5,10);
	   printf("          NAME.     MOBILE.NO.      EMAIL");
	   gotoxy(4,12);
	   printf("   ====================================================");
	   while(fscanf(ptr1,"%s %s     %s", temp_c.cust_name,   temp_c.mob_no,  temp_c.email)!=EOF)
	   {

		gotoxy(4,i);
		gotoxy(13,i);
		printf(" %s",temp_c.cust_name);
		gotoxy(25,i);
		printf(" %s",temp_c.mob_no);
		gotoxy(37,i);
		printf(" %s",temp_c.email);
		i=i+2;
	   }
    printf("\n\n\n\tPress enter any key and go to main menu>> ");
    getche();
    mainmenu();

}

void editrecord()
{
       system("cls");
fp=fopen("contact.txt","r");
ft=fopen("temp.txt","w");
fflush(stdin);
printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to edit:");
scanf("%s",&name);
while(fread(&temp_c,sizeof(temp_c),1,fp)==1)
{
if(stricmp(name,temp_c.cust_name)!=0)
fwrite(&temp_c,sizeof(temp_c),1,ft);
}
fflush(stdin);
printf("\n\n..::Editing '%s'\n\n",name);
printf("..::Name(Use identical):");
scanf("%s",&temp_c.cust_name);
fflush(stdin);
printf("..::Phone:");
scanf("%ld",&temp_c.mob_no);
fflush(stdin);
printf("..::email address:");
gets(temp_c.email);
printf("\n");
fwrite(&temp_c,sizeof(temp_c),1,ft);
fclose(fp);
fclose(ft);
remove("contact.txt");
rename("temp.txt","contact.txt");
printf("Update your new information. ");
printf("\nPress enter any key and go to main menu>> ");
getche();
mainmenu();
}

void deleterecord()
{
    system("cls");
fflush(stdin);
printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enterthe name of contact to delete:");
scanf("%s",&name);
fp=fopen("contact.txt","r");
ft=fopen("temp.txt","w");
while(fread(&temp_c,sizeof(temp_c),1,fp)!=0)
if (stricmp(name,temp_c.cust_name)!=0)
fwrite(&temp_c,sizeof(temp_c),1,ft);
fclose(fp);
fclose(ft);
remove("contact.txt");
rename("temp.txt","contact.txt");
printf("Successfully Delete all record.");
printf("\nPress enter any key and go to main menu>> ");
getche();
mainmenu();
}

