#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

//MAIN MODULES
void admin();
void train_details();
void reservation();
void cancellation();
void extra_services();
void billing();


//SUB MODULES
void menu();
void append(int serial, char train_name[100], char source[30], char stop1[30], char stop2[30], char dest[30], int seats, float cost );
void append(int sno, char item[50], float rate);
void insert_elements();
void display_train_details();
void add_train();
int scanint(const char *const message);
void update_seats();
void update_cancelled_seats(int id);
void display_food_menu();
void get_trains(char from[14], char to[14]);
void details(int num_train, int num_seats);
struct person *hash_table_lookup(int pnr);
struct person *hash_table_cancel(int pnr);
float total(int choice, int quantity);
void add_total(int pnr, float subtotal);
void get_details(int train_num, char from[14], char to[14]);
void print_table();
void  main_exit();
int hash(int p);


int main()
{
system("color 6");
insert_elements();// update data of all modules
printf("\n\t\t\t\t\t\t\t---------- TRAINX - RAILWAY RESERVATION SYSTEM -------\n\n");
printf("\n\t\t\t\t\t\t\t\t\tBROUGHT TO YOU BY :\n\n");
printf("\n\t\t\t\t\t\t\t||              SILVI TANEJA                   ||\n");
printf("\n\t\t\t\t\t\t\t||              SHREYA RASTOGI                 ||\n");
printf("\n\t\t\t\t\t\t\t||              Y ABDUL SALIQ                  ||\n");
printf("\n\n\n\t\t\t\t\t\t\t                PRESS ENTER TO CONTINUE                   \n");
getch();
menu();
return 0;
}

void menu()
{

    int choice;
    system("cls");
    system("color 9");

    printf("\n\n\t    RAILWAY RESERVATION MANAGEMENT SYSTEM");
    printf("\n\n\n\t********* WELCOME TO THE MAIN MENU **********\n\n");
    printf("\n\t1. Admin\t\t\n");
    printf("\n\t2. Train Details\n\t\t");
    printf("\n\t3. Reservation\n\t\t");
    printf("\n\t4. Cancellation\n\t\t");
    printf("\n\t5. Extra Services\n\t\t");
    printf("\n\t6. Billing\n\t\t");
    printf("\n\t7. Exit\n\t\t");

    choice = scanint("\n\tSELECT YOUR CHOICE: ");
    switch(choice)
    {
        case 1:system("cls");
        admin();
        break;
        case 2:system("cls");
        train_details();
        break;
        case 3:system("cls");
        reservation();
        break;
        case 4:system("cls");
        cancellation();
        break;
        case 5:system("cls");
        extra_services();
        break;
        case 6:system("cls");
        billing();
        break;
        case 7:system("cls");
        printf("\n\nTHANK YOU!!\n\n");
               exit(0);
        break;
        default:printf("\nINVALID INPUT");
                getch();
                menu();

    }
}

//INSERT DATA INTO LINKED LISTS
void insert_elements()
{
    append(13456,"GOA EXPRESS            ","MAO","NULL","NULL","DEC", 350, 164.00);
    append(14356,"DELHI DURANTO EXPRESS  ","PUNE","NULL","NULL","DEC", 400, 2198.00);
    append(13256,"MANDOVI EXPRESS        ","MAO","NULL","NULL","CSMT", 600, 1272.00);
    append(14597,"GOLDEN CHARIOT         ","BNC","NULL","NULL","MAO", 500,  600.00);
    append(19984,"DEE GARIBRATH          ","CSMT","NULL","NULL","JP", 340,  800.00);
    append(12296,"PUNE ADI DURANTO       ","PUNE","CSMT","NULL","ADI", 456,  900.00);
    append(17018,"SURYA NAGARI EXPRESS   ","CSMT","ADI","NULL","JP", 100,  700.00);
    append(19784,"UDYAN EXPRESS          ","CSMT","PUNE","NULL","BNC", 450,  750.00);
    append(13981,"SBC EXPRESS            ","ADI","CSMT","PUNE","BNC", 650,  860.00);
    append(14584,"GITANJALI EXPRESS      ","CSMT","NULL","NULL","JP", 500,  890.00);
    append(15674,"CSMT CHENNAI EXPRESS   ","CSMT","PUNE","NULL","MAS", 120,  900.00);
    append(13767,"CHENNAI MAIL           ","CSMT","PUNE","BNC","MAS", 600,  1000.00);
    append(10935,"HUMSAFAR EXPRESS       ","JP","ADI","BNC","CHTS", 760,  800.00);
    append(16439,"MUMBAI DURANTO EXPRESS ","DEC","JP","ADI","CSMT", 400,  800.00);
    append(14577,"MANDOR EXPRESS         ","JP","NULL","NULL","DEC", 540,  340.00);
    append(13652,"JP PUNE EXPRESS        ","JP","PUNE","NULL","CSMT", 340,  670.00);
    append(12335,"JP CHENNAI EXPRESS     ","JP","BNC","NULL","MAS", 230,  450.00);
    append(10259,"MARU SAGAR EXPRESS     ","JP","BNC","NULL","CHTS", 650,  660.00);
    append(15677,"ADI PUNE EXPRESS       ","ADI","CSMT","NULL","PUNE", 750,  230.00);
    append(13782,"ADI MADGAON EXPRESS    ","ADI","CSMT","NULL","MAO", 560,  1120.00);
    append(16094,"NAVJEEVAN EXPRESS      ","ADI","NULL","NULL","MAS", 550,  860.00);
    append(18930,"RAJDHANI EXPRESS       ","ADI","CSMT","MAO","CHTS", 700,  900.00);
    append(12041,"MUMBAI RAJDHANI        ","DEC","NULL","NULL","CSMT", 500,  700.00);
    append(13844,"MMCT DURANTO           ","DEC","NULL","NULL","CSMT", 100,  860.00);
    append(11043,"SAINIK EXPRESS         ","DEC","NULL","NULL","JP", 700,  890.00);
    append(12584,"MAO SUP EXPRESS        ","MAO","NULL","NULL","ADI", 450,  880.00);



    append(1,"Tea                100 ml",10.00);
    append(2,"Coffee             100 ml",15.00);
    append(3,"Soup               150 ml",30.00);
    append(4,"Water Bottle           1L",20.00);
    append(5,"Idli-Vada                ",40.00);
    append(6,"Upma                     ",40.00);
    append(7,"Pongal                   ",40.00);
    append(8,"Egg-Omlet                ",50.00);
    append(9,"Standard Veg Meal        ",100.00);
    append(10,"Standard Non-Veg Meal   ",120.00);
    append(11,"Veg Biriyani     (350gm)",70.00);
    append(12,"Egg Biriyani     (350gm)",80.00);
    append(13,"Chicken Biriyani (350gm)",80.00);
}

void  main_exit()
{
    int main_exit;
    start: printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    if(main_exit==1)
    {
        system("cls");
        menu();
    }
    if(main_exit==0)
    {
        printf("\n\nTHANK YOU!!");
        exit(0);
    }

    else
    {
    printf("\n\nINVALID CHOICE");
    goto start;
    }

}

/*MODULE 1. ADMIN*/
void admin()
{
start: system("cls");
int ch;
printf("\n\n\n\t\t----------ADMIN MODULE---------");
printf("\n\n\n\t\t1. Passenger List\n\n\n");
printf("\t\t2. Remaining Seats\n\n\n");
printf("\t\t3. Add a New Train\n\n\n");
printf("\t\t4. Return to Main Menu\n\n\n");
ch= scanint("\n\t\tPlease Enter Your Choice: ");


switch(ch)
{
    case 1: system("cls");
            print_table();
            main_exit();
    break;

    case 2: system("cls");
            display_train_details();
            main_exit();
    break;

    case 3: add_train();
            main_exit();
    break;

    case 4: menu();
    break;

    default: printf("\n\n\t\tINVALID CHOICE\n\n");
             getch();
             goto start;

}
}

/*MODULE 2. TRAIN DETAILS*/

struct node
{
    int train_id;
    char train_name[100];
    char source[30];
    char stop1[30];
    char stop2[30];
    char dest[30];
    int seats;
    float cost;
    struct node *link;

};

struct node *root=NULL;

void train_details()
{
    display_train_details();
    main_exit();
}

//INSERTION OF TRAIN DETAILS INTO A SINGLE LINKED LIST
void append(int train_id, char *train_name, char source[30], char stop1[30], char stop2[30], char dest[30], int seats, float cost)
{

	struct node *temp;

	temp=(struct node *)malloc(sizeof(struct node));
	temp->train_id = train_id;
	temp->cost   = cost;
	temp->seats  = seats;
    strcpy(temp->train_name,train_name);
    strcpy(temp->source,source);
    strcpy(temp->stop1,stop1);
    strcpy(temp->stop2,stop2);
    strcpy(temp->dest,dest);

	temp->link = NULL;


	if(root==NULL)
    {
		root = temp;
	}

	else
	{
	    struct node *p;
        p=root;
		while(p->link != NULL)
		{
			p = p->link;
		}

		p->link = temp;
	}

}


void add_train()
{
    system("cls");
    int train_id;
    char name[100];
    char source[30];
    char stop1[30];
    char stop2[30];
    char destination[30];
    int seats;
    float price;
    char temp;


    printf("---------------------STATIONS--------------------\n\n");
    printf("SNO  CODE     STATION NAME\n\n");
    printf("1. CSMT     Chhatrapati Shivaji Maharaj Terminus(Mumbai,MAHARASHTRA)\n\n");
    printf("2. JP       Jaipur Junction railway station (Jaipur,RAJASTHAN)\n\n");
    printf("3. MAO      Madgaon Junction railway station(Madgaon,GOA)\n\n");
    printf("4. ADI      Ahmedabad Junction (Ahmedabad,GUJARAT)\n\n");
    printf("5. PUNE     Pune Junction railway station (Pune, MAHARSHTRA)\n\n");
    printf("6. CHTS     Cochin Harbour Terminus(Cochin, KERALA)\n\n");
    printf("7. BNC      Bengaluru Cantonment (Bengaluru, KARNATAKA)\n\n");
    printf("8. MAS      Puratchi Thalaivar Dr. M.G. Ramachandran Central Railway Station(Chennai, TAMIL NADU)\n\n");
    printf("9. DEC      Delhi Cantonment railway station(Delhi)\n\n\n");

    train_id: train_id = scanint("\nPlease Enter Train ID: ");

    if(train_id<0)
    {
        printf("\nTRAIN ID CANNOT BE NEGATIVE\n");
        goto train_id;
    }

    if(train_id>99999)
    {
        printf("\nTRAIN ID CANNOT EXCEED FIVE DIGITS\n");
        goto train_id;
    }

    struct node *p;
    p=root;

    while(p!=NULL)
    {
        if(train_id==p->train_id)
        {
            printf("\nTRAIN ID ALREADY EXISTS\n");
            getch();
            goto train_id;
        }
        p=p->link;
    }

    scanf("%c",&temp);


    train_name: printf("\nEnter Train Name: ");
    scanf("%[^\n]", name);

    int i,c;
    char temp2;

      for (i=0; i<strlen(name); i++)
        {
                if(isdigit(name[i]) != 0)
                {
                    printf("\nINVALID INPUT\n");
                    scanf("%c",&temp2);
                    goto train_name;
                }

        }

    source: printf("\nEnter source station code: ");
    scanf("%s",&source);


    if(!(strcmp(source,"CSMT")==0||strcmp(source,"JP")==0|| strcmp(source,"MAO")==0||strcmp(source,"ADI")==0||strcmp(source,"PUNE")==0||strcmp(source,"CHTS")==0||strcmp(source,"BNC")==0||strcmp(source,"MAS")==0 ||strcmp(source,"DEC")==0))
    {
            printf("\nINVALID CHOICE\n");
            getch();
            goto source;
    }

    stop1: printf("\nEnter stop1 station code: ");
    scanf("%s",&stop1);

    if(!(strcmp(stop1,"CSMT")==0||strcmp(stop1,"JP")==0|| strcmp(stop1,"MAO")==0||strcmp(stop1,"ADI")==0||strcmp(stop1,"PUNE")==0||strcmp(stop1,"CHTS")==0||strcmp(stop1,"BNC")==0||strcmp(stop1,"MAS")==0 ||strcmp(stop1,"DEC")==0||strcmp(stop1,"NULL")==0))
    {
            printf("\nINVALID CHOICE\n");
            getch();
            goto stop1;
    }

    if(strcmp(stop1,source)==0)
    {
        printf("\nSTATION ALREADY ENTERED\n");
        getch();
        goto stop1;
    }

    stop2: printf("\nEnter stop2 station code: ");
    scanf("%s",&stop2);

    if(!(strcmp(stop2,"CSMT")==0||strcmp(stop2,"JP")==0|| strcmp(stop2,"MAO")==0||strcmp(stop2,"ADI")==0||strcmp(stop2,"PUNE")==0||strcmp(stop2,"CHTS")==0||strcmp(stop2,"BNC")==0||strcmp(stop2,"MAS")==0 ||strcmp(stop2,"DEC")==0||strcmp(stop2,"NULL")==0))
    {
            printf("\nINVALID CHOICE\n");
            getch();
            goto stop2;
    }

    if(strcmp(stop2,source)==0||strcmp(stop2,stop1)==0)
    {
        printf("\nSTATION ALREADY ENTERED\n");
        getch();
        goto stop2;
    }

    destination: printf("\nEnter destination station code: ");
    scanf("%s",&destination);

    if(!(strcmp(destination,"CSMT")==0||strcmp(destination,"JP")==0|| strcmp(destination,"MAO")==0||strcmp(destination,"ADI")==0||strcmp(destination,"PUNE")==0||strcmp(destination,"CHTS")==0||strcmp(destination,"BNC")==0||strcmp(destination,"MAS")==0 ||strcmp(destination,"DEC")==0))
    {
            printf("\nINVALID CHOICE\n");
            getch();
            goto destination;
    }

    if(strcmp(destination,source)==0||strcmp(destination,stop1)==0||strcmp(destination,stop2)==0)
    {
        printf("\nSTATION ALREADY ENTERED\n");
        getch();
        goto destination;
    }

    seats: seats = scanint("\nPlease Enter Seats: ");

    if(seats<=0)
    {
        printf("\nENTER A POSITIVE INTEGER\n");
        getch();
        goto seats;
    }

     if(seats>2000)
    {
        printf("\nSEATS CANNOT EXCEED 2000\n");
        getch();
        goto seats;
    }

    price: price = scanint("\nPlease Enter Ticket Price: ");


    if(price<0)
    {
        printf("\nPRICE CANNOT BE NEGATIVE\n");
        getch();
        goto price;
    }


    if(price==0)
    {
        printf("\nPRICE CANNOT BE ZERO\n");
        getch();
        goto price;
    }

     if(price>3000)
    {
        printf("\nPRICE CANNOT EXCEED 3000\n");
        getch();
        goto price;
    }


    append(train_id,name,source,stop1,stop2,destination, seats, price);

    printf("\n\nTRAIN SUCCESSFULLY ADDED!\n\n");

}

int scanint(const char *const message)
{
    int value;

    printf("%s", message);
    while (scanf("%d", &value) != 1)
    {
        int chr;
        printf("\nINVALID INPUT\n");
        do {
            chr = getchar();
        } while ((chr != EOF) && (chr != '\n'));
        printf("%s", message);
    }
    return value;
}

void update_seats(int id, int seats)
{
        struct node *p;
        p=root;
		while(p!= NULL)
		{
		    if(id==p->train_id)
		    {
                 p->seats=p->seats-seats;
		    }
			p = p->link;
		}

}

void display_train_details()
{
    printf("\n--------------------------------------------------TRAIN DETAILS-------------------------------------------------------\n\n");
    printf("ID      TRAIN NAME                      SOURCE  DEST   SEATS    PRICE\n\n");
    struct node *p;
    p=root;

    while(p!=NULL)
    {
        printf("%d\t",p->train_id);
        printf("%s\t\t",p->train_name);
        printf("%s\t",p->source);
        printf("%s\t",p->dest);
        printf("%d\t",p->seats);
        printf("%.2f\t",p->cost);
        printf("\n");
        p=p->link;
    }
}


/*MODULE 3. RESERVATION*/
void reservation()
{
    int num_train, num_seats;

    start1: system("cls");

    printf("---------------------STATIONS--------------------\n\n");
    printf("SNO  CODE     STATION NAME\n\n");
    printf("1. CSMT     Chhatrapati Shivaji Maharaj Terminus(Mumbai,MAHARASHTRA)\n\n");
    printf("2. JP       Jaipur Junction railway station (Jaipur,RAJASTHAN)\n\n");
    printf("3. MAO      Madgaon Junction railway station(Madgaon,GOA)\n\n");
    printf("4. ADI      Ahmedabad Junction (Ahmedabad,GUJARAT)\n\n");
    printf("5. PUNE     Pune Junction railway station (Pune, MAHARSHTRA)\n\n");
    printf("6. CHTS     Cochin Harbour Terminus(Cochin, KERALA)\n\n");
    printf("7. BNC      Bengaluru Cantonment (Bengaluru, KARNATAKA)\n\n");
    printf("8. MAS      Puratchi Thalaivar Dr. M.G. Ramachandran Central Railway Station(Chennai, TAMIL NADU)\n\n");
    printf("9. DEC      Delhi Cantonment railway station(Delhi)\n\n\n");

    char from[14], to[14];
    char b1,b2,b3;
    int train_num;

    scanf("%c",&b1);
    printf("Enter From Station Code: ");
    scanf("%[^\n]", from);

    if(!(strcmp(from,"CSMT")==0 || strcmp(from,"JP")==0 || strcmp(from,"MAO")==0 || strcmp(from,"ADI")==0 || strcmp(from,"PUNE")==0 || strcmp(from,"CHTS")==0||strcmp(from,"BNC")==0 || strcmp(from,"MAS")==0 ||strcmp(from,"DEC")==0))
    {
    printf("\n\nINVALID CHOICE\n\n");
    getch();
    goto start1;
    }

    else
    {
    scanf("%c",&b2);
    printf("\nEnter To Station Code: ");
    scanf("%[^\n]", to);
       if(!(strcmp(to,"CSMT")==0||strcmp(to,"JP")==0|| strcmp(to,"MAO")==0||strcmp(to,"ADI")==0||strcmp(to,"PUNE")==0||strcmp(to,"CHTS")==0||strcmp(to,"BNC")==0||strcmp(to,"MAS")==0 ||strcmp(to,"DEC")==0))
       {
            printf("\n\nINVALID CHOICE\n\n");
            getch();
            goto start1;
       }
       else
        {
            if(strcmp(from,to)==0)
            {
                printf("\n\nSOURCE AND DESTINATION CANNOT BE SAME\n\n");
                getch();
                goto start1;
            }

            else
            {
            printf("\n---------------------TRAINS AVAILABLE---------------------\n\n");
            get_trains(from, to);

            scanf("%c",&b3);
            train: train_num= scanint("\nEnter Train Number: ");

            //check if train id exists
            struct node *p;
            p=root;

            bool valid=false;

                while(p!=NULL)
                {
                    if(train_num==p->train_id)
                    {
                        valid=true;
                    }
                    p=p->link;
                }

            if (valid==true)
            {
            get_details(train_num,from,to);
            }

            else
            {
                printf("\nINVALID TRAIN ID\n");
                getch();
                goto train;
            }

          }
       }
    }
}

void get_trains(char from[14], char to[14])
{
  int count=0;
  struct node *p;
  p=root;

      while(p!=NULL)
      {
        if((strcmp(from,p->source)==0 || strcmp(from,p->stop1)==0 ||strcmp(from,p->stop2)==0 ||strcmp(from,p->dest)==0)&&(strcmp(to,p->source)==0 || strcmp(to,p->stop1)==0 ||strcmp(to,p->stop2)==0 ||strcmp(to,p->dest)==0&&p->seats!=0))
            {
                printf("%d\t",p->train_id);
                printf("%s\t",p->train_name);
                printf("%s\t",p->source);
                printf("%s\t",p->dest);
                printf("%d\t",p->seats);
                printf("%.2f\t",p->cost);
                printf("\n");
                count++;
            }
        p=p->link;
      }

      if (count==0)
      {
          printf("\nNO TRAINS AVAILABLE\n");
          main_exit();
      }
}


//HASH TABLE TO STORE PASSENGER'S DETAILS
#define TABLE_SIZE 100

struct person
{
    int pnr;
    int age;
    char name[20];
    char sex[1];
    long long int phone_num;
    float bill;
    char train_name[30];
    int train_id;
    char source[20];
    char destination[20];

};


struct person *hash_table[TABLE_SIZE];//array of pointers
int pnr=3302;

//Quadratic probing in case of collision.
int hash(int p)
{
    int hash_value=p%TABLE_SIZE;
    return hash_value;
}

void get_details(int train_num, char from[14],char to[14])
{
    int seats,i;
    int index;

      struct node *ptr,*q;
      ptr=root;

      while(ptr!=NULL)
      {
        if(train_num==ptr->train_id)
        {
            q=ptr;
        }
        ptr=ptr->link;
      }

    seats: seats = scanint("\nEnter number of seats: ");

    if(seats<0)
    {
        printf("\nNUMBER OF SEATS CANNOT BE NEGATIVE \n");
        getch();
        goto seats;
    }

    if(seats==0)
    {
        printf("\nNUMBER OF SEATS CANNOT BE ZERO \n");
        getch();
        goto seats;
    }


    if(seats>6)
    {
        printf("\nNUMBER OF SEATS CANNOT EXCEED 6\n");
        getch();
        goto seats;
    }

    update_seats(train_num,seats);



    struct person *p;

    for(i=0; i<seats;i++)
    {
        system("cls");
        printf("\n------------RESERVATION DETAILS---------------\n\n");
        printf("\nDetails of passenger %d\n\n", i+1);
        p=(struct person*)malloc(sizeof(struct person));
        index=hash(pnr);

        hash_table[index]=p;
        p->pnr=pnr;

        char temp; char temp1; char temp2; //buffer , null character is stored at the start of string when integer value is entered
        int i;
        scanf("%c",&temp);

        name: printf("\nEnter Full Name: ");
        scanf("%[^\n]", p->name);


           for (i=0; i<strlen(p->name); i++)
            {
                if(isdigit(p->name[i]) != 0)
                {
                    printf("\nINVALID INPUT\n");
                    scanf("%c",&temp);
                    goto name;
                }

            }

        gender: printf("Enter Gender M, F or O: ");
        scanf("%s",&p->sex);

        if(!(strcmp(p->sex,"F")==0||strcmp(p->sex,"M")==0||strcmp(p->sex,"O")==0))
        {
            printf("\nINVALID ENTRY\n");
            goto gender;
        }




        age: p->age= scanint("\nEnter Age: ");


        if(p->age<0)
        {
        printf("\nAGE CANNOT BE NEGATIVE\n");
        getch();
        goto age;
        }

        if(p->age==0)
        {
        printf("\nAGE CANNOT BE ZERO\n");
        getch();
        goto age;
        }

        else if(p->age>120)
        {
        printf("\nINVALID AGE\n");
        getch();
        goto age;
        }

        phone_num: printf("ENTER 10 DIGIT PHONE NUMBER: ");
        scanf("%lld",&p->phone_num);


        if(p->phone_num<1000000000)
        {
            printf("\nINVALID PHONE NUMBER\n");
            goto phone_num;
        }

        if(p->phone_num>9999999999)
        {
            printf("\nINVALID PHONE NUMBER\n");
            goto phone_num;
        }

        strcpy(p->source,from);
        strcpy(p->destination,to);
        strcpy(p->train_name,q->train_name);
        p->train_id=q->train_id;
        p->bill=q->cost;
        pnr++;
        printf("\nYOUR PNR NUMBER IS:%d", p->pnr);
        getch();
    }

    printf("\n\n\nRESERVATION SUCCESSFUL!");

    main_exit();
}


void print_table()
{
system("cls");
int i;
int count=0;
for(i=0; i<TABLE_SIZE; i++)
{
        if(hash_table[i] != NULL)
        {
        printf("%d\t",hash_table[i]->pnr);
        printf("%s\t",hash_table[i]->name);
        printf("%d\t",hash_table[i]->age);
        printf("%s\t",hash_table[i]->sex);
        printf("%d\t",hash_table[i]->phone_num);
        printf("\n");
        }
        else
        {
        count++;
        printf("");
        }
}

if(count==TABLE_SIZE)
{
    printf("\n\n\t\tNO PASSENGERS AS YET!!\n\n");
    main_exit();
}
}

/*CANCELLATION MODULE*/

void cancellation()
{
int pnr;
system("cls");
pnr = scanint("\nENTER PNR NUMBER: ");

struct person *temp=hash_table_lookup(pnr);

if(temp==NULL)
{
printf("\nPNR NUMBER DOES NOT EXIST\n");
main_exit();
}


else
{
printf("---------PASSENGER DETAILS-----\n\n");

printf("\t%s\n",temp->train_name);
printf("Source       :%s\t",temp->source);
printf("Destination  :%s\n",temp->destination);
printf("--------------------------------\n");
printf("PNR Number   :%d\n",temp->pnr);
printf("Name         :%s\n",temp->name);
printf("Age          :%d\n",temp->age);
printf("Sex          :%s\n",temp->sex);
printf("Phone Number :%lld\n",temp->phone_num);
printf("Ticket Cost  :%.2f\n",temp->bill);// Cost upto 2 decimal places
printf("--------------------------------");
update_cancelled_seats(temp->train_id);
hash_table_cancel(pnr);
printf("\n\nTICKET SUCCESSFULLY CANCELLED");
main_exit();
}
}

struct person *hash_table_cancel(int pnr)
{
    int index=hash(pnr);
    struct person *p=hash_table[index];
    hash_table[index]=NULL;

}

void update_cancelled_seats(int id)
{
        struct node *p;
        p=root;
		while(p!= NULL)
		{
		    if(id==p->train_id)
		    {
                 p->seats=p->seats+1;
		    }
			p = p->link;
		}

}
struct person *hash_table_lookup(int pnr)
{
    int index=hash(pnr);
    if(hash_table[index]!=NULL && hash_table[index]->pnr==pnr)
    {
           struct person *p=hash_table[index];
           return p;
    }

    else
    {
        return NULL;
    }

}


/*MODULE 5 EXTRA SERVICES*/


int choice, quantity;

struct food
{
    int serial_no;
    char name[50];
    float price;
    struct food *link;

};

struct food *root_food=NULL;

void extra_services()
{
    char ch[1];
    int pnr;


    new_order: printf("\n----------------Today's Menu-----------------\n\n");

    printf("SNO     ITEM                            PRICE\n\n");

    display_food_menu();

    pnr = scanint("\nENTER PNR NUMBER: ");

    struct person *p=hash_table_lookup(pnr);

    if(p==NULL)
    {
        printf("\nINVALID PNR NUMBER");
        getch();
        main_exit();
    }

    else
    {
        choice: choice = scanint("\nSelect your choice: ");

        struct food *p;
        p=root_food;
        int count;

        while(p!=NULL)
        {
            if(p->serial_no==choice)
            {
                count=1;
            }
            p=p->link;
        }

        if(count!=1)
        {
            printf("\nINVALID CHOICE\n");
            goto choice;
        }

        quantity: quantity = scanint("\nEnter Quantity: ");

        if(quantity<=0)
        {
            printf("\nINVALID QUANTITY\n");
            goto quantity;
        }

        if(quantity>3)
        {
            printf("\nQUANTITY CANNOT EXCEED 3\n");
            goto quantity;
        }

        printf("\nOrder Placed Successfully!!\n");


        printf("\nCurrent Subtotal: %.2f",total(choice, quantity));

        add_total(pnr,total(choice, quantity)); // Add cost to final bill

        printf("\nWant Anything else? 'Y'/'N'\n");
        scanf("%s",&ch);

        if(strcmp(ch,"Y")==0)
        {
        system("cls");
        goto new_order;
        }

        else
        {
        main_exit();
        }
    }
}

//DISPLAY FOOD MENU
void display_food_menu()
{
    struct food *q;
    q=root_food;

    while(q!=NULL)
    {
        printf("%d\t",q->serial_no);
        printf("%s\t",q->name);
        printf("%.2f\t",q->price);
        printf("\n");
        q=q->link;
    }
}

//INSERTION OF FOOD ITEMS INTO A SINGLE LINKED LIST
void append(int sno, char item[50], float rate)
{

	struct food *temp;

	temp=(struct food *)malloc(sizeof(struct food));
	temp->serial_no = sno;
	temp->price = rate;
    strcpy(temp->name,item);

	temp->link = NULL;


	if(root_food==NULL)
    {
		root_food= temp;
	}

	else
	{
	    struct food *p;
        p=root_food;
		while(p->link != NULL)
		{
			p = p->link;
		}

		p->link = temp;
	}

}

//CALCULATE COST OF FOOD ITEMS
float total(int choice , int quantity)
{
    float bill=0;
    struct food *p;
    p=root_food;
    int ch=choice;
    int qty=quantity;

    while(p!=NULL)
    {
        if(ch==p->serial_no)
        {
            bill=bill+p->price*qty;
        }
        p=p->link;
    }
    return bill;
}

//ADD COST OF FOOD ITEMS TO BILL
void add_total(int pnr, float subtotal)
{

    printf("\n\nSUBTOTAL ADDED TO MAIN BILL\n\n");
    struct person *temp=hash_table_lookup(pnr);
    temp->bill=temp->bill+subtotal;
}

/*BILLING MODULE*/
void billing()
{
int pnr;

pnr = scanint("\nENTER PNR NUMBER: ");

struct person *temp=hash_table_lookup(pnr);

if(temp==NULL)
{
    printf("\nINVALID PNR NUMBER\n");
    main_exit();

}

else
{
printf("---------------PASSENGER DETAILS-----------\n\n");
printf("\t%s\n\n",temp->train_name);
printf("Source       :%s\t",temp->source);
printf("Destination  :%s\n",temp->destination);
printf("-------------------------------------------\n");
printf("PNR Number   :%d\n",temp->pnr);
printf("Name         :%s\n",temp->name);
printf("Age          :%d\n",temp->age);
printf("Sex          :%s\n",temp->sex);
printf("Phone Number :%lld\n",temp->phone_num);
printf("Ticket Cost  :%.2f\n",temp->bill);
printf("--------------------------------------------");
main_exit();
}
}
