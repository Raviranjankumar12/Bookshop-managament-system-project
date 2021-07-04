//*******Bookshop******
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct bookshop
{
	char date[40];
	char cname[40];
	double Number;
	char bname[40];
	char barcode[40];
	float cost;
};
struct bookshop s;			// object of bookshop class

void write();				//Function Diclaration // Function Store Data
void display();				//Function Display Data
void edit();
void delrecord();				//edit data


void write()				//Function Defination
{

	char ch='y';
	FILE *rec;
	rec=fopen("record.txt","ab+");
	while(ch=='y'||ch=='Y' )
	{
		printf("\n	ENTER DATE	::	>");
		scanf("%s",&s.date);
		fflush(stdin);
		printf("	CUSTOMER NAME	::	>");
		gets(s.cname);
		printf("	CUSTOMER MOBILE	::	>");
		scanf("%lf",&s.Number);
		fflush(stdin);
		printf("	BOOK NAME	::	>");
		gets(s.bname);
		fflush(stdin);
		printf("	BARCODE NUMBER	::	>");
		gets(s.barcode);
		printf("	BOOK Rs.	::	>");
		scanf("%f",&s.cost);

		fwrite(&s,sizeof(s),1,rec);

		printf("\n	IF YOU WANT TO CREATE MORE RECORD\n	Y/N 		::	>");
		ch=getche();
	}

	fclose(rec);
		printf("\n\n			ENTRY RECORD SUCCESS!!	\n");

}

void display()			//Function Defination
{
	char search[40];
	int found=0, choise;

	FILE *rec;
	rec=fopen("record.txt","rb");
	printf("	PRESS <1> SEARCH BY BARCODE\n	PRESS <2> SEARCH BY DATE\n	CHOISE		::	>");
	scanf("%d",&choise);
	if(choise==1)
	{
		printf("\n	ENTER BARCODE NUMBER	::	>");
		scanf("%s",&search);
	}
	else if(choise==2)
	{
		printf("\n	ENTER DATE	::	>");
		scanf("%s",&search);
	}

		if(rec==NULL)
		{
			printf("\nFILE ERROR");
			return;
		}
		else
		{
		while(fread(&s,sizeof(s),1,rec))
		{
			if(strcmp(s.barcode,search)==0||strcmp(s.date,search)==0)
			{
				found=1;
				printf("\n	DATE			:: %s ",s.date);
				printf("\n	CUSTOMER NAME		:: %s",strupr(s.cname));
				printf("\n	CUSTOMER MOBILE		:: %.lf",s.Number);
				printf("\n	BOOK NAME		:: %s",strupr(s.bname));
				printf("\n	BOOK BARCODE		:: %s",s.barcode);
				printf("\n	BOOK Rs.		:: %.2f\n",s.cost);

			}
		}
		}
		if(found==0)
		{
			printf("		RECORD NOT FOUND");
		}
		fclose(rec);
}

void edit()			//Function Defination
{
	char user[40];
	char password[40];
	int num;
	char lm[20];
	int size;
	int flag=0;
	FILE *rec;
	rec=fopen("record.txt","r+b");
	printf("\n	WHICH BARCODE RECORD DO YOU WANT\n 	TO MODIFY	::	>");
	scanf("%s",&lm);

		if(rec==NULL)
		{
			printf("\nFILE ERROR");
			return;
		}
	while(fread(&s,sizeof(s),1,rec))
	{
		if(strcmp(s.barcode,lm)==0)
		{
			flag=1;
			printf("\n	DATE			:: %s ",s.date);
			printf("\n	CUSTOMER NAME		:: %s",strupr(s.cname));
			printf("\n	CUSTOMER MOBILE		:: %.lf",s.Number);
			printf("\n	BOOK NAME		:: %s",strupr(s.bname));
			printf("\n	BOOK BARCODE		:: %s",s.barcode);
			printf("\n	BOOK Rs.		:: %.2f\n",s.cost);

		lable:

			printf("\n	IF YOU WANT TO MODIFY THIS RECORD");
			printf("\n	PLEASE ENTER USER NAME AND PASSWORD");

			fflush(stdin);
			printf("\t\n\n	USER NAME	::	>");
			gets(user);
			printf("	PASSWORD	::	>");
			gets(password);


			if((strcmp(user,"Ravi")==0) && (strcmp(password,"123456")==0))
			{
				printf("\n 	PRESS 	<1> 	FOR DATE");
				printf("\n 	PRESS 	<2> 	FOR CUSTOMER NAME");
				printf("\n 	PRESS 	<3> 	FOR BOOK NAME");
				printf("\n 	PRESS 	<4> 	FOR BOOK Rs.");
				printf("\n	*************************************\n");
				printf("	\n	PLEASE ENTER YOUR CHOISE::>");
				scanf("%d",&num);
				switch (num)
				{
					case 1:
						{
							printf("\n	ENTER DATE	::	>");
							scanf("%s",&s.date);
							break;
						}
					case 2:
						{
							fflush(stdin);
							printf("	CUSTOMER NAME	::	>");
							gets(s.cname);
							break;
						}
					case 3:
						{
							fflush(stdin);
							printf("	BOOK NAME	::	>");
							gets(s.bname);
							break;
						}
					case 4:
						{
							printf("	BOOK Rs.	::	>");
							scanf("%f",&s.cost);
							break;
						}
				}
				size=sizeof(s);
        		fseek(rec,-size,SEEK_CUR);
        		fwrite(&s,sizeof(s),1,rec);
				fclose(rec);

				printf("				\nRECORD UPDATE!!");
				return;
			}
			if((strcmp(user,"Ravi")!=0) || (strcmp(password,"123456")!=0))
			{
				printf("	WRONG PASSWORD PLEASE TRY AGAIN\n");
				goto lable;
			}

		}

	}
		if(flag==0)
		{
			printf("\n		RECORD NOT FOUND");
		}
}

void main()						//Function Calling Section
{
		char user[40];
		char password[40];
		int choise;
		printf("\n	*****************************************");

		printf("\n	*	WELCOME TO RAVIRANJAN BOOKSHOP	*");

		printf("\n	*****************************************");
		printf("\t\n\n 	PLEASE ENTER USER NAME AND PASSWORD");
		printf("\t\n\n	USER NAME	::	>");
		gets(user);
		printf("	PASSWORD	::	>");
		gets(password);
	if((strcmp(user,"Ravi")==0) && (strcmp(password,"123456")==0))
{
	do
	{
		printf("\t\n\n\n	*********WELCOME TO MY BOOKSHOP********\n");
		printf("\n 	PRESS 	<1> 	FOR CREAT RECORD");
		printf("\n 	PRESS 	<2> 	FOR SEARCH RECORD");
		printf("\n 	PRESS 	<3> 	FOR MODIFY RECORD");
		printf("\n 	PRESS 	<4> 	FOR DELETE RECORD");
		printf("\n 	PRESS 	<0> 	FOR EXIT PROGRAM");
		printf("\n\n	YOUR CHOISE 	::	> ");
		scanf("%d",&choise);
		printf("\n	***************************************\n");
			switch (choise)
			{
			case 1:
				{
					write();		//Function Calling
					break;
				}
			case 2:
				{
					display();	//Function Calling
					break;
				}
			case 3:
				{
					edit();	//Function Calling
					break;
				}
			case 4:
				{
					delrecord();	//Function Calling
					break;
				}

			case 0:
				{
					exit(0);
				}
			default:
				{
					printf("\nINVALID ENTRY");
				}
			}
	}
	while(choise!=0);
}
else
{
	printf("\n\n	WRONG PASSWORD PLEASE TRY AGAIN");
}
}

void delrecord()			//Function Defination
{
	char user[40];
	char password[40];
	char lm[20];
	FILE *rec,*del;
	printf("\n	WHICH BARCODE RECORD DO YOU \n	WANT TO DELETE	::	>");
	scanf("%s",&lm);
	printf("\n	IF YOU WANT TO DELETE THIS RECORD");
	printf("\n	PLEASE ENTER USER NAME AND PASSWORD");
	lable:
	fflush(stdin);
	printf("\t\n\n	USER NAME	::	>");
	gets(user);
	printf("	PASSWORD	::	>");
	gets(password);

	if((strcmp(user,"Ravi")==0) && (strcmp(password,"123456")==0))
	{
		rec=fopen("record.txt","r");
		del=fopen("delete.txt","w+");
		if(rec==NULL)
		{
			printf("\nFILE ERROR");
			return;
		}
		else
		while(fread(&s,sizeof(s),1,rec))
		{
			if(strcmp(s.barcode,lm)!=0)
			{
				fwrite(&s,sizeof(s),1,del);
			}
		}
			fclose(rec);
			fclose(del);
			remove("record.txt");
			rename("delete.txt","record.txt");
			printf("					\nRECORD DELETED!!");
	}
else
{
	printf("	WRONG PASSWORD PLEASE TRY AGAIN\n");
	goto lable;
}
}

//Thank you!!!!!
