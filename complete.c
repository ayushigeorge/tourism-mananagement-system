#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <conio.h> 

enum state{main_menu,login_system};
enum state currentwindow=main_menu;

typedef struct userprofile
{
    char user_fname[100];
    char user_password[100];
    char user_place[100];
    float ticket_price;
    int user_numtick;
    char user_feedback[1000];
    struct userprofile *next;

}userprofile;

void ShowBrochure();
userprofile* InitializeListing(userprofile*);
userprofile* Adding_Client(userprofile*);
void login_client(userprofile*);
void booking_ticket(userprofile*);
void printing_ticket(userprofile*);
void cancelling_ticket(userprofile*);
void changing_pass(userprofile*);
void logout_client();
void checking_ticket(userprofile*);
void displaying_all_bookings(userprofile*);
void WriteToFile(userprofile*);
void exit_system();
void add_user_feedback(userprofile*);
void set_password(userprofile*);
char* enter_password();

char current_client[100];

  
void set_password(userprofile *user)
{
    char c;
	//password[10];
int i = 0;
    while( 1 )
		{
			c=getch();
			if ((c == '\n') ||
    	       (c == 13))
           {
		        printf(" \ndone!");   
        		break;
		   }
        
		user->user_password[i] = c;
        printf("*");
       i++;
    }
    return;
}

char* enter_password()
{
    char c; 
	char *password = (char*)malloc(sizeof(10));
	int i = 0;
    while( 1 )
		{
			c=getch();
			if ((c == '\n') ||
           (c == 13) || i >= 9)
           {
		        printf(" \n \n done!");   
        		break;
		   }
        
		password[i] = c;
        printf("*");
        i++;
    }
    return password;
}


int main()
{
	printf("===================================================================\n");
    printf("\t\t PROJECT MANAGEMENT SYSTEM \n");
    printf("===================================================================\n");
    userprofile *hello=NULL;
    int choice1,choice2;
    hello=InitializeListing(hello);
    while (1)
    {

        if(currentwindow==main_menu)
        {

            printf("\n\t\tAdd User\t\t\t1\n\t\tLogin User\t\t\t2\n\t\tBrochure\t\t\t3\n\t\tExit\t\t\t\t4\n\t\tEnter:\t\t\t\t");
            scanf("%d",&choice1);
            switch(choice1)
            {
                case 1:
                    hello=Adding_Client(hello);
                    break;
                case 2:
                    login_client(hello);
                    break;
                case 3:
                    ShowBrochure();
                    break;
                case 4:
                    exit_system();
                    exit(0);
                    break;
                default:
                    printf("Not a valid input at this stage\n");
            }
        }
        else if(currentwindow==login_system)
        {
            system("CLS");
            printf("\n====================================================================================================");
            printf("\n\t\t\t\tTOURISM MANAGEMENT SYSTEM");
            printf("\n====================================================================================================\n");
            printf("\n\t\t\t\tBook Package\t\t\t1\n\t\t\t\tCheck Ticket\t\t\t2\n\t\t\t\tPrint Ticket\t\t\t3\n\t\t\t\tCancel Ticket\t\t\t4\n\t\t\t\tChange Password\t\t\t5\n\t\t\t\tLogout User\t\t\t6\n\t\t\t\tBrochure\t\t\t7\n\t\t\t\tFeed Back\t\t\t8\n\t\t\t\tExit\t\t\t\t9\n\t\t\t\tEnter\t\t\t\t");
            scanf("%d",&choice2);
            switch(choice2)
            {
                case 1:
                    booking_ticket(hello);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 2:
                    checking_ticket(hello);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 3:
                    printing_ticket(hello);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 4:
                    cancelling_ticket(hello);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 5:
                    changing_pass(hello);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 6:
                    logout_client(hello);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 7:
                    ShowBrochure();
                    system("PAUSE");
                    system("CLS");
                    break;
                case 8:
                    add_user_feedback(hello);
                    system("PAUSE");
                    system("CLS");
                    break;
                case 9:
                    exit_system();
                    exit(0);
                    break;

                default:
                    printf("Not a valid input at this stage\n");
            }
        }
    }
}
void add_user_feedback(userprofile *hello)
{
	fflush(stdin);
	userprofile *trans=hello;
    while(hello!=NULL)
    {
        if(!strcmp(hello->user_fname,current_client))
            break;
        hello=hello->next;
    }
    if(hello==NULL)
        return;    
#if 1
	int n ;
     printf("\t\tFEED BACK Please \n\t\tEnter your FEED BACK :  ");
        //scanf("%s",hello->user_feedback);
        //scanf("%[^\n]%*c",hello->user_feedback);
		scanf("%[^\n]s", hello->user_feedback);
fflush(stdin);
	   // n=fwrite(hello,sizeof(userprofile),1,p);
   //     if(n>0)
     //   {
            printf("thank you for feed back\n");
       // }
        //else
        //{
          //  printf("feed back is not saved");
        //}
    //}
    //fclose(p);

#endif
    WriteToFile(trans);
    return ;
}

userprofile* InitializeListing(userprofile *hello)
{
    userprofile* text,*petrol,temporary;
    FILE *fileopen;
    int counting_cooridantes=0,z;
    float following;
    fileopen=fopen("users.txt","r");

    if(fileopen==NULL)
        return NULL;

    if(fgetc(fileopen)==EOF)
        return NULL;

    rewind(fileopen);
    while(fscanf(fileopen,"%s %s %s %f %d",temporary.user_fname,temporary.user_password,temporary.user_place,&temporary.ticket_price,&temporary.user_numtick)!=EOF)
    {
        petrol=(userprofile*)malloc(sizeof(userprofile));
        strcpy(petrol->user_fname,temporary.user_fname);
        strcpy(petrol->user_password,temporary.user_password);
        strcpy(petrol->user_place,temporary.user_place);
        petrol->ticket_price=temporary.ticket_price;
        petrol->user_numtick=temporary.user_numtick;
        petrol->next=NULL;

        if(hello==NULL)
            hello=text=petrol;
        else
        {
            hello->next=petrol;
            hello=petrol;
        }
    }
    fclose(fileopen);
    return text;
}

void WriteToFile(userprofile *hello)
{
    FILE *fileopen;
    fileopen=fopen("users.txt","w");
    while(hello!=NULL)
    {
        fprintf(fileopen,"%s %s %s %f %d \n",hello->user_fname,hello->user_password,
							hello->user_place,hello->ticket_price,hello->user_numtick); //hello->user_feedback);
		fprintf(fileopen,"feedback : %s\n",hello->user_feedback);					
        hello=hello->next;
    }
    fclose(fileopen);
}

void ShowBrochure()
{
    system("CLS");
    printf("=============================================================================\n\t\t\t\tBROCHURE\n=============================================================================\n  CODE\t\tPLACE\t\t\t\t\t\tAMOUNT\n\n  1  - Isla Gigantis Tours  \t\t\t\t\tRs  3,000/-\n  2  - Mag-Aso Falls Tours \t\t\t\t\tRs  5,000/-\n  3  - Mambukal Resort Tours \t\t\t\t\tRs  2,000/-\n  4  - Boracay Beach Resort \t\t\t\t\tRs  10,000/-\n  5  - Whispering Palms Island Resort \t\t\t\tRs  12,000/-\n  6  - La Vista Highlands \t\t\t\t\tRs  5,000/-\n  7  - Punta Bulata Resort & Spa \t\t\t\tRs  7,000/-\n  8  - Big BamBoo Beach Resort \t\t\t\t\tRs  8,000/-\n  9  - Nature's Village Resort \t\t\t\t\tRs  12,000/-\n  10 - Artistic Diving & Beach Resort \t\t\t\tRs  14,000/-\n");
}

void checking_ticket(userprofile *hello)
{
    while(hello!=NULL)
    {
        if(!strcmp(hello->user_fname,current_client))
            break;
        hello=hello->next;
    }
    if(!strcmp(hello->user_place,"\0") || hello->ticket_price==0.0 || hello->user_numtick==0)
    {
        printf("You do not have a ticket booked yet\n");
        return;
    }
    float tot=0.0;
    tot=(hello->ticket_price)*(hello->user_numtick);
    printf("\tYou have booked %d tickets\n\tTotal Amount %0.2f \n\ttour code    %s\n",hello->user_numtick,tot,hello->user_place);
}

userprofile* Adding_Client(userprofile* hello)
{
    userprofile *trans;
    trans=hello;
    userprofile *newwonderers;
    newwonderers=(userprofile*)malloc(sizeof(userprofile));
    fflush(stdin);
    printf("\n\n\t\tEnter Username or Email : ");
    scanf("%s",newwonderers->user_fname);
    while(hello!=NULL)
    {
        if(!strcmp(hello->user_fname,newwonderers->user_fname))
        {
            printf("\t\tThat email already exists\n");
            return trans;
        }
        hello=hello->next;
    }
    hello=trans;
    fflush(stdin);
    printf("\t\tEnter password \t\t: ");
    set_password(newwonderers);
    //newwonderers->user_password = enter_password();
	printf("\n User Created! \n");
	//scanf(" %[^\n]s",&newwonderers->user_password);
    newwonderers->next=NULL;
    strcpy(newwonderers->user_place,"N/A");
    newwonderers->ticket_price=0.0;
    newwonderers->user_numtick=0;

    if(hello==NULL)
    {
        hello=trans=newwonderers;
    }
    else
    {
        while(hello->next!=NULL)
        {
            hello=hello->next;
        }
        hello->next=newwonderers;
    }
    WriteToFile(trans);
    return trans;
}

void login_client(userprofile* hello)
{
    char client_username[100];
    //char client_password[100];
    char *client_password = NULL;
    fflush(stdin);
    printf("\n\n");
    printf("\t\tEnter Email/Username    : ");
    scanf("%s",client_username);
    fflush(stdin);
    printf("\t\tEnter Password\t\t: ");
    //scanf(" %[^\n]s",client_password);
    client_password = enter_password();
      //printf("\n\t\ Password:%s\n\t\t",client_password);
    while(hello!=NULL)
    {
        if((!strcmp(hello->user_fname,client_username)) && (!strcmp(hello->user_password,client_password)))
        {
            currentwindow=login_system;
            strcpy(current_client,client_username);

            printf("\n\t\tLogin successful!\n");
            system("PAUSE");
            return;
        }
        else if((!strcmp(hello->user_fname,client_username)) && (strcmp(hello->user_password,client_password)))
        {
            printf("Password mismatch\n");
            return;
        }
        hello=hello->next;
    }
    printf("\nSorry, no such user record was found\n");
}

void booking_ticket(userprofile *hello)
{
    userprofile *trans=hello;
    char place[100];
    while(hello!=NULL)
    {
        if(!strcmp(hello->user_fname,current_client))
            break;
        hello=hello->next;
    }
    if(hello==NULL)
        return;
    if(hello->ticket_price!=0.0)
    {
        printf("You must cancel your previous ticket before buying a new one\n");
        return;
    }
    ShowBrochure();
    float pricelist[]={3000.0,5000.0,2000.0,10000.0,12000.0,5000.0,7000.0,8000.0,12000.0,14000.0};
    fflush(stdin);
    printf("\nEnter place code NUMBER\n");
    scanf(" %[^\n]s",place);
    char choice;
    fflush(stdin);
    printf("\nWould You Like to Confirm Booking?\nPRESS 1 to Confirm booking\nPRESS 2 to GO BACK\n");
    scanf("%c",&choice);
    float price;
    if(choice!='1')
        return;
    if(strcmp(place,"1")==0)
        price=pricelist[0];
    else if(strcmp(place,"2")==0)
        price=pricelist[1];
    else if(strcmp(place,"3")==0)
        price=pricelist[2];
    else if(strcmp(place,"4")==0)
        price=pricelist[3];
    else if(strcmp(place,"5")==0)
        price=pricelist[4];
    else if(strcmp(place,"6")==0)
        price=pricelist[5];
    else if(strcmp(place,"7")==0)
        price=pricelist[6];
    else if(strcmp(place,"8")==0)
        price=pricelist[7];
    else if(strcmp(place,"9")==0)
        price=pricelist[8];
    else if(strcmp(place,"10")==0)
        price=pricelist[9];
    else
    {
        printf("That tour code doesn't exist\n");
        return;
    }
    printf("Enter the number of tickets you want to book?\n");
    scanf("%d",&hello->user_numtick);
    if(hello->user_numtick==0)
        return;
    strcpy(hello->user_place,place);
    hello->ticket_price=price;
    WriteToFile(trans);
    printf("Bookings Done!!\n");
    system("PAUSE");

}

void printing_ticket(userprofile *hello)
{
    while(hello!=NULL)
    {
        if(!strcmp(hello->user_fname,current_client))
            break;
        hello=hello->next;
    }
    if(!strcmp(hello->user_place,"\0") || hello->ticket_price==0.0 || hello->user_numtick==0)
    {
        printf("You do not have a ticket booked yet\n");
        return;
    }
    float tot=0.0;
    tot=(hello->ticket_price)*(hello->user_numtick);
    FILE *fileopen;
    char filename[50];
    strcpy(filename,hello->user_fname);
    strcat(filename,"_ticket.txt");
    fileopen=fopen(filename,"w");
    if(fileopen==NULL)
    {
        printf("Problem opening the file\n");
        return;
    }
    if(fgetc(fileopen)==EOF)
    {
        fprintf(fileopen,"TOURISM TICKET\n===============\n\n");
    }
    fprintf(fileopen,"Email ID: %s\nTour Code: %s\nTicket Cost: P %f\nNumber of tickets: %d\nTotal Cost: P %f\n",hello->user_fname,hello->user_place,hello->ticket_price,hello->user_numtick,tot);
    fclose(fileopen);
}

void cancelling_ticket(userprofile *hello)
{
    userprofile *trans=hello;
    while(hello!=NULL)
    {
        if(!strcmp(hello->user_fname,current_client))
            break;
        hello=hello->next;
    }

    int flag=-1;

    if(hello==NULL)
        printf("No such user\n");

    if(strcmp(hello->user_place,"1")==0)
        flag++;
    else if(strcmp(hello->user_place,"2")==0)
        flag++;
    else if(strcmp(hello->user_place,"3")==0)
        flag++;
    else if(strcmp(hello->user_place,"4")==0)
        flag++;
    else if(strcmp(hello->user_place,"5")==0)
        flag++;
    else if(strcmp(hello->user_place,"6")==0)
        flag++;
    else if(strcmp(hello->user_place,"7")==0)
        flag++;
    else if(strcmp(hello->user_place,"8")==0)
        flag++;
    else if(strcmp(hello->user_place,"9")==0)
        flag++;
    else if(strcmp(hello->user_place,"10")==0)
        flag++;
    else
    {
        printf("You haven't booked a tour yet\n");
        return;
    }
    if(flag==0)
    {
        printf("Your ticket has been successfully cancelled\nA refund of P %f for Tour Code %s for %d tickets will soon be made to your original source of purchase\n",hello->ticket_price,hello->user_place,hello->user_numtick);
        strcpy(hello->user_place,"N/A");
        hello->ticket_price=0.0;
        hello->user_numtick=0;
        WriteToFile(trans);
    }
}

void changing_pass(userprofile *hello)
{
    userprofile *trans=hello;
    char *passcurr;//[100];
    fflush(stdin);
    printf("Enter your current password to continue:\n");
    //scanf(" %[^\n]s",passcurr);
    passcurr = enter_password();
    
	while(hello!=NULL)
    {
        if(!strcmp(hello->user_fname,current_client))
            break;
        hello=hello->next;
    }
    if(hello==NULL)
        return;
    if(!strcmp(passcurr,hello->user_password))
    {
        printf("Enter new password:\n");
        set_password(hello);
		//hello->user_password = enter_password();        
        //scanf(" %[^\n]s",hello->user_password);
    }
    WriteToFile(trans);
}

void logout_client()
{
    if(currentwindow==main_menu || strcmp(current_client,"\0")==0)
    {
        printf("You must be logged in to logout\n");
        return;
    }
    strcpy(current_client,"\0");
    currentwindow=main_menu;
    printf("You have been successfully logged out\n");
}

void exit_system()
{
    printf("Exiting...\nBrought You By \nTEK_kraft\n\nPress \"Enter/Return\" to exit");
    char exitprog;
    fflush(stdin);
    scanf("%c",&exitprog);
}


