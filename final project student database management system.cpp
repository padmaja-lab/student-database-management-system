#include<iostream>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<direct.h>
#include<windows.h>
using namespace std;


void add();// add a record
void search();// search a record
void list(); //display the record
void del(); // delete the record
void modify();// mpdify the record
void rec(); //scan the new record
void mainpage(); //starting page
int logscreen();// login screen
void callExit();// exit function
void menu();// Main Menu
void date();// to get current date
void empty();// used in deleting the record
void title();// title bar


/*declaring structure*/

struct information
{
  char ID[15]; //Student ID
  char name[30];  //Student name
  char cls[10];  //Class of Student
  char Branch[35];  //Branch of class
  char address[50];  //Address of Student
  char email[30];  //Email of Student
  char rollno[15];  //Roll No Of a Student
  char phoneno[15];  //Phone No Of a Student
};
struct information c;
FILE *fpt;

void title()
{
  
  cout<<"\n\n\n\t\t\t\t\t    ||  STUDENT MANAGEMENT SYSTEM  || \n\n\n\t\t\t\t";


}

void mainpage()
{
  int process=0;
  system("cls");
  cout<<"\n";
  cout<<"\n\n\n\t\t\t\t\t    ||  STUDENT MANAGEMENT SYSTEM  ||\n\n\n\n\t\t\t\t";
  cout<<"Prepared By    :";
  cout<<"    Padmaja Kolukulapalli";
  cout<<"\n\n";
  cout<<"\t\t\t\t";
  cout<<"Mini Project    :";
  cout<<"   Student Management System";
  cout<<"\n\n\n\n\n\n\n\n";
  cout<<"\t\t\t\t    Press Enter to continue...... \n\n";
  getchar();
}

int logscreen()
{
  char username[30];
  char password[30];
  int tries = 0;
  int yes = 1;
  do
  {
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t";
    cout<<"Username: ";
    cin>>username;
    cout<<"\t\t\t\t\t";
    cout<<"\n";
    cout<<"\t\t\t\t\t";
    cout<<"Password: ";
    cin>>password;
    if(strcmp(username,"admin")==0 && strcmp(password,"pass")==0)
      {
        cout<<"\n\n\n\n";
        cout<<"\t\t\t\t";
        cout<<"You are accessed to the system!\n\n\n\n\n";
        cout<<"\t\t\t\t   Press Enter to continue...";
        fflush(stdin);
        getchar();
        menu();//calling function within a function
        system("cls");
        getchar();
        yes=0;
      }
      else
      {
        system("cls");
        tries = tries+1;
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t";
        cout<<"No. of attempts remain: "<<(3-tries);
        fflush(stdin);
        getchar();
        if(tries>=3)
        {

          cout<<"\t\t\t\t\t\t";
          cout<<"\n";
          cout<<"\t\t\t\t";
          cout<<"   No permission to enter the system!" ;
          getchar();
          callExit();
          getchar();
      ;
      }
  } 
 }
 while(yes==1);
}


void menu()
{
  int input;
  system("cls");
  title();
  cout<<" 1. Enter new Records\n\n";
  cout<<"\t\t\t\t";
  cout<<" 2. Modify Records\n\n";
  cout<<"\t\t\t\t";
  cout<<" 3. Delete Records\n\n";
  cout<<"\t\t\t\t";
  cout<<" 4. Search and view Records\n\n";
  cout<<"\t\t\t\t";
  cout<<" 5. Exit\n\n";
  cout<<"\t\t\t\t";
  cout<<"Choose options:[1/2/3/4/5]:";
  fflush(stdin);
  cin>>input;
  switch(input)
  {
    case 1:
    {
      system("cls");
      add();
    }
    break;

    case 2:
    {
      system("cls");
      modify();
      getchar();
    }
    break;

    case 3:
    {
      system("cls");
      del();
    }
    break;

    case 4:
    {
      system("cls");
      search();
    }break;

    case 5:
    {
      system("cls");
      fflush(stdin);
      exit(0);
    }
    break;

    default:
    {
      fflush(stdin);
      cout<<"\n\n\n";
      cout<<"\t\t\t\t";
      cout<<"      Invalid input!   \n\n";
      cout<<"\t\t\t\tPress Enter to choose again...";
      getchar();
      menu();
    }
  }
  }
  void add()
  {
    char input;
    system("cls");
    cout<<" ";
    cout<<"\n";
    cout<<"\t\t\t\t\n\t\t\t\t\n\t\t\t\t\n\n\n\n\n\t\t\t\t";
    cout<<"Enter The Information Below: ";
    cout<<"\n\t\t\t\tEnter ID        :  ";
    fflush(stdin);
    cin>>c.ID;
    
    cout<<"\n\t\t\t\tFull Name       :  ";
    fflush(stdin);
    cin>>c.name;
    
    cout<<"\n\t\t\t\tClass           :  ";
    fflush(stdin);
    cin>>c.cls;
    
    cout<<"\n\t\t\t\tBranch          :  ";
    fflush(stdin);
    cin>>c.Branch;
    
    cout<<"\n\t\t\t\tAddress         :  ";
    fflush(stdin);
    cin>>c.address;
    
    cout<<"\n\t\t\t\tEmail Address   :  ";
    fflush(stdin);
    cin>>c.email;
    
    cout<<"\n\t\t\t\tRoll No.        :  ";
    fflush(stdin);
    cin>>c.rollno;
    
    cout<<"\n\t\t\t\tPhone No.       :  ";
    fflush(stdin);
    cin>>c.phoneno;
    fflush(stdin);
    fpt=fopen("data.txt","a");
    fwrite(&c,sizeof(c),1,fpt);
    fclose(fpt);
    cout<<"\n\n\t\t\t\tRecord added successfully";

    cout<<"\n\n\t\t\t\tDo you want to add more?(Y/N)";
    cin>>input;
    if(input=='Y' || input=='y')
    {
      add();
    }
    else
    menu();
    getchar();
    }

      void callExit()
      {
       system("cls");
       fflush(stdin);
       cout<<"\n\n\n\n\t\t\t\tYou are out of the System.";
       cout<<"\n\n\t\t\t\t Press Enter to Continue Exit Program...";
       getchar();
       exit(0);
      }

      void search()
      {
        int ch;
        char sid[30];
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";

        fflush(stdin);
        cout<<"Enter Full Name: ";
        cin>>sid;

        fpt=fopen("data.txt","r");
        while (fread(&c, sizeof(c), 1, fpt)==1)
        {
          if(strcmp(sid,c.name)==0)
          {
            ch=1;
            break;
          }
        }
        if(ch==1)
        {
          system("cls");
          cout<<"\n\n\n\n\n\n\n";
          cout<<"\t\t\t\t\t";

          cout<<"<<==Search Succesfull==>>";
          fflush(stdin);
          getchar();
          list(); //display the record
          cout<<"\n\n\n\t\t\t\tPress Enter For Main Menu...";
          getchar();
          menu();
        }
        else
        {
          system("cls");
          getchar();
          cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
          cout<<"<<--Record Not Found-->>";
          cout<<"\n\n\t\t\t\tPress Enter For Main Menu...";
          getchar();
          menu();
        }

        fclose(fpt);
      }


      void list()
{
      cout<<"\n\n\t\t\t\t ID             :   "<<c.ID;
      cout<<"\n\t\t\t\t Full Name       :   "<<c.name;
      cout<<"\n\t\t\t\t Class           :   "<<c.cls;
      cout<<"\n\t\t\t\t Branch          :   "<<c.Branch;
      cout<<"\n\t\t\t\t Address         :   "<<c.address;
      cout<<"\n\t\t\t\t Email Address   :   "<<c.email;
      cout<<"\n\t\t\t\t Roll No.        :   "<<c.rollno;
      cout<<"\n\t\t\t\t Phone No.       :   "<<c.phoneno;

}

       void del()
       {
         FILE *fpt,*temp;
         int ch;
         char sid[30];

         system("cls");
         cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t";
         cout<<"Enter Full Name:";
         fflush(stdin);
         cin>>sid;
         fflush(stdin);
         cout<<"\n\n\t\t\t\t Record Deleted Successfully.";
         cout<<"\n\n\t\t\t\t Press Enter For Main Menu...";
         getchar();
         menu();
         fpt=fopen("data.txt","r");
         temp = fopen("temp.txt", "w");
         while (fread(&c, sizeof(c), 1, fpt)==1)
         {
           if(strcmp(sid,c.name)!=0)
           {
             {
                 fwrite(&c,sizeof(c),1,temp);
           }
         }
         fclose(fpt);
         fclose(temp);
         remove("data.txt");
         rename("temp.txt","data.txt");
         }
       }

      void empty()
      {
        strcpy(c.ID," ");
        strcpy(c.name," ");
        strcpy(c.cls," ");
        strcpy(c.Branch," ");
        strcpy(c.address," ");
        strcpy(c.email," ");
        strcpy(c.rollno," ");
        strcpy(c.phoneno," ");
      }

void modify()
{
  char mid[30];

  int found=0;
  cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
  fflush(stdin);
  cout<<"Enter Full Name: ";
  cin>>mid;
  fflush(stdin);
  FILE *fpt, *temp;
  temp =fopen("temp.txt","w");
  fpt = fopen("data.txt","r+");
  while(fread(&c, sizeof(c),1,fpt) == 1)
  {
      if(strcmp(mid, c.name) == 0)
      {
          fflush(stdin);
          system("cls");
          cout<<"\n\n\n\n\n\n\n\n\n\n\n";
          cout<<"\t\t\t\t\t";
          cout<<"<<<==Old Record==>>>";
          cout<<"\n";
          cout<<"\t\t\t\t\t";
          list();

          cout<<"\n\n\t\t\t\t\t Press Enter to modify the record...";


          getchar();
          system("cls");
          rec(); // this will ask to enter new record
          fseek(fpt, ftell(fpt) - sizeof(c),0);
          fwrite(&c, sizeof(c), 1, fpt); //The new name will be added to the record.
          found = 1;
          cout<<"\n\n\t\t\t\t\t Record Saved !!!";
          getchar();
        }
        fclose(fpt);
        menu();
      }

      if(!found)
      {
        {
          system("cls");
          fflush(stdin);

          cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
          fflush(stdin);

          cout<<"<<--Record Not Found-->>";
          getchar();
          menu();
        }
      }
      fclose(fpt);
}
       void rec()
       {
    
         cout<<"\n\n\n\n\t\t\t\t";

         cout<<"Enter The Information Below: ";
         cout<<"\n\n\t\t\t\t ID             :  "<<c.ID;
         cout<<"\n\t\t\t\t Full Name       :  ";
         fflush(stdin);
         cin>c.name;
         cout<<"\n\t\t\t\t Class           :  ";
         fflush(stdin);
         cin>>c.cls;
         cout<<"\n\t\t\t\t Branch          :  ";
         fflush(stdin);
         cin>>c.Branch;
         cout<<"\n\t\t\t\t Address         :  ";
         fflush(stdin);
         cin>>c.address;
         cout<<"\n\t\t\t\t Email Address   :  ";
         fflush(stdin);
         cin>>c.email;
         cout<<"\n\t\t\t\t Roll No.        :  ";
         fflush(stdin);
         cin>>c.rollno;
         cout<<"\n\t\t\t\t Phone No.       :  ";
         fflush(stdin);
         cin>>c.phoneno;
         fflush(stdin);
}

int main()
{
  system("cls");
  mainpage();
  logscreen();
}
