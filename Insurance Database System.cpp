/*
RIZA MERT YAÐCI B1705.010045 COM 117

This program is a simple database for a insurance to register their customers and car information
to login the program user have to know password
user can add customer and information and store them in a txt file
user can search a specific customer in program
user also can edit information of customer and  delete user.



*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

struct customer_car{
    char name[20];
    char lastName[20];
    char address[100];
    char telNumber[50];
    char car_model[100];
    int carAge;
    char carKm[50];
    char end_date[20];

};
struct customer_car a;

char lname[50],name[20],choice;


FILE *fp, *ft;


COORD coord = {0,0};

void menu();
void got();
void window();
void newCustomer();
void editCustomer();
void customerList();
void search();
void deleteCustomer();
void gotoxy(int x, int y);
void close();
void login();

int main(){
	login();
	system("color F");
        return 0;
}

void close(){
    printf("\n\n\n\nYou have logged out");
    exit(0);
    }

void gotoxy(int x, int y){
    coord.X = x;
	coord.Y = y; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menu(){
	system("cls");
    gotoxy(34,2);
    printf("INSURANCE DATABASE SYSTEM");
    gotoxy(40,4);
    printf("COMPANY NAME");
    gotoxy(31,26);
    while(1){
    	
        gotoxy(34,8);printf("1. Add New Customer");
        gotoxy(34,10);printf("2. Customer List");
        gotoxy(34,12);printf("3. Search Customer");
        gotoxy(34,14);printf("4. Edit Customer's information");
        gotoxy(34,16);printf("5. Delete Customer");
        gotoxy(34,18);printf("6. Exit");
        gotoxy(34,20);printf("Please enter your choice: ");
        
      	choice=getche();
        switch(choice){
            case '1':
            	newCustomer();
                break;
            case '2':
            	customerList();
            	break;
            case '3':
            	search();
            	break;
            case '4':
                editCustomer();
                break;
            case '5':
            	deleteCustomer();
                break;
            case '6':
               close();
                break;
            default:
                break;
        }

    }

}
void login(){
	int i,check;
char pass[10]="admin",password[10]="admin";
	gotoxy(36,1);
	printf("*password is admin");
	gotoxy(28,7);
	printf("Please enter the password to login:");
    scanf("%s",pass);
	if (strcmp(pass,password)==0){
		gotoxy(45,9);
			menu();
            
            
        }
    else{   
    		gotoxy(28,9);
			printf("Wrong password!!\a");
			gotoxy(28,10);
            printf("Enter 1 to try again and 0 to exit:");
            scanf("%d",&check);
            if (check==1){

                        system("cls");
                        main();
                    }

            else if (check==0){
                    system("cls");
                    close();
					}
            else{
                    system("cls");
					printf("\nInvalid!\a");
					close();
					}

        }
}
void newCustomer(){
	fp=fopen("Customer_information.txt","a");
	system("cls");
	gotoxy(22,2);
    printf("\xB2\xB2\xB2\xB2 NEW COSTUMER \xB2\xB2\xB2\xB2");
	fflush(stdin);
    printf("\n\n");
    printf("Name: ");
    scanf("%[^\n]",a.name);
    if(stricmp(a.name,"")==0 || stricmp(a.name," ")==0){ // if name input is empty then it won't be accepted as a customer
			menu();
		}
 	fflush(stdin);				//fflush() was used to avoid space error
 	printf("Last name: ");
    scanf("%[^\n]",a.lastName); //%[^\n] was used to use space in input
 	fflush(stdin);
    printf("Address: ");
    scanf("%[^\n]",a.address);
    fflush(stdin);
    printf("Phone number: ");
    scanf("%[^\n]",a.telNumber);    
    fflush(stdin);
    printf("Car model: ");
    scanf("%[^\n]",a.car_model);
	fflush(stdin);
    printf("Car age: ");
    scanf("%d",&a.carAge);
	fflush(stdin);
    printf("Car km: ");
    scanf("%[^\n]",a.carKm);    
 	fflush(stdin);
    printf("End of insurance date: ");
    scanf("%[^\n]",a.end_date);
		 
   	fwrite(&a,sizeof(a),1,fp);
   
    fclose(fp);
    printf("Customer have registered succesfully\n\n\nEnter the Choice:\n\n\t[1] Add Another Customer\t[2] Main Menu\t\t[0] Exit\n");
	choice = getche();
    switch(choice){
    	case '1':
    		newCustomer();
			break;
		case '2':
			menu();
			break;
		case '0':
			close();
			break;
		default:
			menu();
			break;
	
	}
}

void search(){			// total_hours_wasted_here = 48
system("cls");
int i,n,ch=1,l,found;
        while(ch==1)
		
        {
            found=0;
            printf("\n\n\t SEARCH\n\t-------------------------\n\tCostumer name to search: ");
            fflush(stdin);
            scanf("%[^\n]",&lname);
            l=strlen(lname);
            fp=fopen("Customer_information.txt","r");
            printf("\n\nSearch results for '%s' \n--------------------------------------\n",lname);
            while(fread(&a,sizeof(a),1,fp)==1){

                for(i=0; i<=l; i++){
                name[i]=a.name[i];
            }
            
				name[l]='\0';
				
                if(stricmp(name,lname)==0)

                {

                    printf("\nName: %s\nlast Name: %s\nAddress: %s\nPhone Number: %s\nCar Model: %s\nCar Age: %d\nCar Km: %s\nEnd Date: %s\n",a.name,a.lastName,a.address,a.telNumber,a.car_model,a.carAge,a.carKm,a.end_date);

                    found++;

                }

            }

            if(found==0)

                printf("\nNo match found!");

            else

                printf("\n%d match(s) found!",found);
                       	 fclose(fp);
    printf("\n\n\nEnter the Choice:\n\n\t[1] Search again\t[2] Main Menu\t\t[0] Exit\n");
	choice = getche();
    switch(choice){
    	case '1':
    		search();
			break;
		case '2':
			menu();
			break;
		case '0':
			close();
			break;
		default:
			menu();
			break;
	
	}
        }

}
void customerList(){
	int found;

	fflush(stdin);
	fp=fopen("Customer_information.txt","r");
	system("cls");
	if(fp==NULL){
			printf("\nFile couldn't found :");
	printf("\n\n\nEnter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
	choice = getche();
	if(choice=='1'){
		menu;
	}
	else{
		close();
	}
	}
	printf("\n\nCustomer List \n--------------------------------------\n\n");
	while(fread(&a,sizeof(a),1,fp)==1)
	{
    	
        printf("\nName: %s\nlast Name: %s\nAddress: %s\nPhone Number: %s\nCar Model: %s\nCar Age: %d\nCar Km: %s\nEnd Date: %s\n",a.name,a.lastName,a.address,a.telNumber,a.car_model,a.carAge,a.carKm,a.end_date);
		found++;
	}
	printf("\nNumber of Customers: %d",found);
	printf("\n\n\nEnter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
	choice = getche();
	if(choice=='1'){
		menu();//unless there is a call to menu, menu function don't close
	}
	else{
		close();
	}
}
void deleteCustomer(){
	    system("cls");
	 	printf("\n\n\tDELETE A CONTACT\n\t--------------------\n\tEnter the name of contact to delete:");
                scanf("%[^\n]",name);
                ft = fopen("temp.txt","w");   
                rewind(fp);
                while(fread(&a,sizeof(a),1,fp) == 1)  
                {
                    if(strcmp(a.name,name) != 0) 
                    {
                        fwrite(&a,sizeof(a),1,ft);
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("Customer_information.txt"); 
                rename("Temp.txt","Customer_information.txt"); 
    printf("\n\n\nEnter the Choice:\n\n\t[1] Delete again\t[2] Main Menu\t\t[0] Exit\n");
	choice = getche();
    switch(choice){
    	case '1':
    		deleteCustomer();
			break;
		case '2':
			menu();
			break;
		case '0':
			close();
			break;
		default:
			menu();
			break;
	
	}
}

void editCustomer(){
        system("cls");
        fp=fopen("Customer_information.txt","r");
        ft=fopen("temp.txt","w");
        fflush(stdin);
        gotoxy(8,1);
        printf("Edit contact\n--------------------------\n\n\tEnter the name of contact to edit:");
        scanf("%[^\n]",name);
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(stricmp(name,a.name)!=0)
                fwrite(&a,sizeof(a),1,ft);
        }
        	printf("\nEnter new information of customer: \n");
        	fflush(stdin);
            printf("Name: ");
    		scanf("%[^\n]",a.name);
    		fflush(stdin);
         	printf("Last name: ");
   			scanf("%[^\n]",a.lastName); 
 			fflush(stdin);
    		printf("Address: ");
    		scanf("%[^\n]",a.address);
    		fflush(stdin);
    		printf("Phone number: ");
    		scanf("%[^\n]",a.telNumber);    
    		fflush(stdin);
    		printf("Car model: ");
    		scanf("%[^\n]",a.car_model);
			fflush(stdin);
    		printf("Car age: ");
    		scanf("%d",&a.carAge);
			fflush(stdin);
    		printf("Car km: ");
    		scanf("%[^\n]",a.carKm);    
 			fflush(stdin);
    		printf("End of insurance date: ");
    		scanf("%[^\n]",a.end_date);
                fwrite(&a,sizeof(a),1,ft);

        fclose(fp);
        fclose(ft);

        remove("Customer_information.txt");

        rename("temp.txt","Customer_information.txt");

    printf("\n\n\nEnter the Choice:\n\n\t[1] Edit again\t[2] Main Menu\t\t[0] Exit\n");
	choice = getche();
    switch(choice){
    	case '1':
    		editCustomer();
			break;
		case '2':
			menu();
			break;
		case '0':
			close();
			break;
		default:
			menu();
			break;
	
	}
}
