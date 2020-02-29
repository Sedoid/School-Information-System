#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>


int Admission(void)
{

    FILE *now,*then,*first,*sub;

    sub = fopen("now.dat","r");
    if(!sub)
    {
        first = fopen("now.dat","w");
        if(!first)
        {
            printf("Failed to open file");
            exit(1);
        }
        int f=1;
        fwrite(&f,sizeof(int),1,first);
        fclose(first);
    }
    then = fopen("now.dat","r");
    if(!then)
    {
        printf("Failed to create the file");
        exit(1);
    }
    int v;
    fread(&v,sizeof(int),1,then);
  //  printf("This is the %d time youre running this program",v);

    now = fopen("now.dat","w");
    if(!now)
    {
        printf("Failed to create the file");
        exit(1);

    }
    int x = v+1;
    fwrite(&x,sizeof(int),1,now);
    fclose(now);

   // system("Pause");
    return v;

}


void Loader(void)
{
    FILE *now,*then,*first,*sub;

    char subjects[9][45] = {"Buffaloe Rider","Advanced Physics","Advanced Chemistry","Biological Science","Youngest King of hunters",
                            "After Earth","Julius Caeser","Aping the Apes","Animal Farm"};
    sub = fopen("Books.txt","r");

    if(!sub)
    {
        // Initializes the checker
        then = fopen("checker.dat","r");
    if(!then)
    {printf("Failed to read the file");
        exit(1);
    }
    int v;
    fread(&v,sizeof(int),1,then);
    fclose(then);
    //reads the value of the checker
    if(v == 1)
    {
   //     printf("Heyy...i got this far..reading from checkers\n");
        now= fopen("checker.dat","w");
        if(!now)
        {
            printf("An Error Occurred..");
            exit(1);
        }
        fprintf(now,"0");
        fclose(now);

        int z;
      //  printf("Heyy...i got this far\n");
        first = fopen("Books.txt","w");
     //   printf("Heyy...i got this far...Books has been created\n\n");
        if(!first)
        {
            printf("Failed to open file");
            exit(1);
        }
        for(z=0;z<8;z++)
            fprintf(first,"%s\n",subjects[z]);
        fclose(first);
//printf("Heyy...i got this far...Books has been filled\n\n");
    }

    }
    fclose(sub);


}


void Re_Born(void);
void Registeration_software(void);
void Library_Management_software(void);
int main()
{


          struct Reg
    {
        char name[30];
        int age;
        int level;
        char gender;         //class
        time_t date;   // time of registration
        int admission_number;

    }student;

    int activity,c;
    c = 0;
    do
    {
First:
    system("color 0B");
        printf("\n\n\t\t\t\t\tSCHOOL INFORMATION SYSTEM\n\n");
        printf("Select an activity Numbers\n\n");
    printf("\t1-REGISTERATION SOFTWARE\n\n");
    printf("\t2-LIBRARY MANAGEMENT SOFTWARE\n\n");
    printf("\t3-REPORT CARD SOFTWARE\n\n");
    printf("\t4-EXIT\n\n");
    if(c>0)
    printf("\n\t****************Enter a Valid a Number ******************\n");
    printf("Choose an activity: ");
    scanf("%d",&activity);
    }while(activity<1 || activity> 4);

    switch(activity)
    {
    case 1:
        {
            system("cls");
            system("color 0F");
          Registeration_software();
          system("cls");
            goto First;
          break;
        }
    case 2:
        {
            system("cls");
            system("color 0B");
            Library_Management_software();
            system("cls");
            goto First;
            break;
        }
    case 3:
        {

            system("cls");
            system("color f2");
          Re_Born();
          system("cls");
          goto First;
          break;
        }
    case 4:
        {
            printf("\n\n\t\t********************************** See U Next Time **************************************\n\n");
        system("exit");
        }
    }

    return 0;
}

void Registeration_software(void)
{
    int choice;
    FILE *data_base;

    data_base = fopen("Registration.db","a");

    if(!data_base)
    {
        printf("failed to create the failed");
        exit(1);
    }

    int num_to_reg,c,i;
    c=0;
here:
    do
    {
        if(c>0)
        {
            system("cls");
            printf("Note: Enter an appropriate activity Number\a\a ");
        }
    printf("\n\n\n\t\t\t\tREGISTERATION SOFTWARE\n\n");
    printf("\tWelcome to the registration software \n");
    printf("Select the number which corresponds to the activity you want to perform:\n");
    printf("Activities: \n\n");
    printf("\t1- REGISTER NEW STUDENTS\n\n");
    printf("\t2- VIEW REGISTERED STUDENTS\n\n");
    printf("\t3- EXIT\n");
    printf("\nChoose Activity : ");
    scanf("%d",&choice);
    c = 1;
    }while(choice<0 || choice > 3);
    c = 0;

    switch(choice)
    {

    case 1:
    {
printf("\n\n\t\t\t REGISTER NEW STUDENTS\n");

        printf("\nWelcome to the school registration software. Here, you are allowed to register new students\n"
           "NOTE: only students who have paid their fees are registered in the software\n\n");
    do
    {
        if(c > 0)
            printf("\n\t\tINVALID INPUT!!!...enter a correct input\a\a\a\n");

        printf("\nEnter the number of students to register: ");
    scanf("%d",&num_to_reg);
    c++;
    }while((int)num_to_reg <=0 );


    struct Register
    {
        char name[30];
        int age;
        int level;
        char gender;         //class
        time_t date;   // time of registration
        int admission_number;

    }student[num_to_reg];


    printf("\nEnter the students information as required below \n");
char name[30];
    for(i=0;i<num_to_reg;i++)
    {
        char name[30];
        printf("\nStudent Name : ");
        fgets(name,30,stdin);
        fgets(name,30,stdin);

  strcpy(student[i].name,name);
    printf("\nstudent Age  : ");
    scanf("%d",&student[i].age);

    printf("\nStudents Gender(M/F): ");
    scanf("%s", &student[i].gender );

    time(&student[i].date);
    student[i].admission_number = Admission();

    fwrite(&student[i],sizeof(struct Register),1,data_base);

    printf("\n\t******************** Next Student *********************\n");
    }
    fclose(data_base);

    printf("\n\t\t************** Your record has been saved *******************\n");

        system("pause");
        system("cls");
        goto here;
    }
    case 2:

     {

         FILE *proof;
    struct book
    {
        char name[30];
         int age;
        int level;
        char gender;         //class
        time_t date;   // time of registration
        int admission_number;
    };
    struct book person;
    proof = fopen("Registration.db","r");

    if(!proof)
    {
        printf("Failed the create the file");
        exit(1);
    }
    while(fread(&person,sizeof(struct book),1,proof))
      {
          printf("Name   :%s\nage     : %-8d\nGender  : %c\nDate    : %-20s\nAdmission Number: %d\n\n "
               ,person.name,person.age,person.gender,ctime(&person.date),person.admission_number);
        printf("\n\t******************** Next Student **********************\n");

      }

    fclose(proof);

        system("pause");
        system("cls");
        goto here;
        break;
     }

    case 3:
            return 0;
        break;

    }

}

Library_Management_software()
{

int activity;
        char response[3];
    char password[20];

    FILE *word, *first;
    word = fopen("Password.dat","r");
    if(!word)
    {
   // strcpy(password,"teacher");

        first = fopen("Password.dat","w");
        if(!first)
            {

            printf("Failed to create the files...Aborting.\n");
            exit(1);
            }
    strcpy(password,"teacher");
        fprintf(first,"%s",password);
    fclose(first);
        }



   // fclose(word);

int m,c;
c=0;
    printf("\n\t\t\t\tLIBRARY MANAGEMENT SOFTWARE\n\n  ");
    printf("Please identify yourself\n");
    printf("\n\tAre you the Library Attendant : ");
    scanf("%s",&response);

    if(toupper(response[0]) == 'Y')
    {
        char test[20];
        do
        {
            if(c>0)
                printf("\n\t************Password Incorrect..try again****************\n");
                if(c == 3)
                    goto here;
            printf("\nKindly enter your password: ");
        scanf("%s",&test);
      //  fgets(test,10,stdin);
     //   fgets(test,10,stdin);
        char answer[20];
        fgets(answer,20,word);
        m = strcmp(answer,test);
        c++;

        }while(m != 0);

      //  printf("\t\t%s\t%d",answer,m);

    if(m == 0)
{
         do{
home:
        printf("Correct Password\n");
        system("cls");
        printf("\n\t\t\t\tLIBRARY MANAGEMENT SOFTWARE\n\n  ");
        printf("\tWelcome Sir\Madame \n");
        printf("select the activity to perform\n");
        printf("\t1-View Books Available\n");
        printf("\t2-Add New Books\n");
        printf("\t3-View Burrow Requests\n");
        printf("\t4-View Book Suggestions\n");
        printf("\t5-Change Your Password\n");
        printf("\t6-Exit\n");

        printf("Choose Activity : ");
        scanf("%d",&activity);
    }while(activity < 1 || activity >6);

        switch(activity)
        {
        case 1:
            {

    FILE *define;
   define= fopen("checker.dat","w");
    if(!define)
    {
        printf("Fail to create the file");
        exit(1);
    }
    int p = 1;
    fwrite(&p,sizeof(int),1,define);
    fclose(define);
    Loader();
                char books[45];
                FILE *viewer;
            viewer = fopen("Books.txt","r");
            if(!viewer)
            {
                printf("Failed to open the file...Books");
                goto home;
            }
printf("\nThese are the current books in the library \n\n");
            while(fgets(books,45,viewer))
                    printf("\t%s\n ",books);
                putchar('\n');
                system("pause");
                system("cls");
                goto home;
                break;
            }
        case 2:
            {
                int i;
                FILE  *viewer;
                viewer=fopen("Books.txt","a");
                if(!viewer)
                {
                    printf("Failed to read the file\n");
                    exit(1);
                }
                int n;
                printf("\t\tAdd New Books\n");
                printf("How many books will you like to add: ");
                scanf("%d",&n);
                printf("\nEnter the Book titles %d\n",n);
                printf("\tTitles\n");

                for(i=0;i<n;i++)
                {
                    char names[45];
                    printf("%d_ ",i+1);
                    //fgets(char names,45,stdin);
                    //fgets(names,45,stdin);
                    scanf("%s",&names);
                    fprintf(viewer,"\n%s",names);
                }
                fclose(viewer);
                printf("\n\tBooks have been added Successfully\t\t");

                 putchar('\n');
                system("pause");
                system("cls");
                goto home;
                break;
            }
        case 3:
            {
                char permission[3];
                char permissionn[20];
                int ch;
                printf("\n\t\tBorrow Requests\n\n ");
                printf("\tHere, you will find the names of students and the books they want to burrow\n"
                       "And you are to decide whether or not he can borrow it\n\n");

                FILE *next;
                next = fopen("Burrow.dat","a+");
                if(!next)
                {
                    printf("**************** No Student Requests to Burrow a Book ************************\n\n");

                     putchar('\n');
                system("pause");
                system("cls");
                goto home;
                }

                while((ch = fgetc(next))!= EOF)
                    putchar(ch);
                    c = 0;
                 // do
                   // {
                    if(c>0)
                    printf("\t*************** Enter a Valid Response*****************");

                    printf("\n\nWhat is your decision (permission yes \ no) :");
                    scanf("%s",&permission);
                    c++;
                  //  }while(toupper(permission)!='Y' || toupper(permission) !='N');

                    if(toupper(permission[0]) =='Y')
                        strcpy(permissionn,"Permission Granted");
                    else
                        strcpy(permissionn,"Permission Denied");

                    fprintf(next,"\n\nLibrary Attendant's Decision : %s",permissionn);
                    fclose(next);
                    printf("\n\t\tYour Message has been Conveyed to Recipient Successfully\n");

                    putchar('\n');
                    system("pause");
                    system("cls");
                    goto home;



            }
     //           break;

        case 4:
            {
                printf("\n\t\t\tSuggested Books\n\n");
                printf("\tHere, you will see the Books that some students would like to add to the Library\n");
                char books[45];
                FILE *viewer;
            viewer = fopen("Suggested_Books.txt","r");
            printf("\nThese are the current suggested by the students \n\n");
            if(!viewer)
            {
                printf("\t\t******************No Book Suggestion for  now*******************\n\n");
                system("pause");
                system("cls");
                goto home;
            }
            while(fgets(books,45,viewer))
                    printf("\t%s\n ",books);

                system("pause");
                system("cls");
                goto here;
                break;
            }
        case 5:
            {
                FILE *viewer;
                viewer = fopen("Password.dat","w");
                if(!viewer)
                {
                    printf("Fail to open the password file\n");
                    exit(1);
                }
                printf("\n\t\tChange Your password\n");
                printf("\tHere, you can change your password to be anything you want: \n\n");
                printf("Enter your new password : ");
                scanf("%s",password);
                fprintf(viewer,"%s",password);
                fclose(viewer);
                printf("\t\tPassword Updated Successfully");
                 putchar('\n');
                system("pause");
                system("cls");
                goto home;
                break;
            }
        case 6:
            {

            }
        }
        }  // Ends the library attendants mode
    }

   else
    {
        char stud_name[40];
       c=0;
          struct Reg
    {
        char name[30];
        int age;
        int level;
        char gender;         //class
        time_t date;   // time of registration
        int admission_number;

    }student;



        printf("\nWhat is your name : ");
        fgets(stud_name,40,stdin);
        fgets(stud_name,40,stdin);

             FILE *viewer,*next;
            viewer = fopen("Registration.db","r");
            if(!viewer)
            {
                printf("Sorry, No student has been registered Yet ");
                exit(1);
            }
                while(fread(&student,sizeof(struct Reg),1,viewer))
                            if(!strcmp(student.name,stud_name))

                               goto here;


                               printf("\nThere is no record of you.  Your name is not found in the database\n"
                                   "\n\t\tRegister before you can use this software\n");

                                   system("Pause");

                                   exit(1);




here:

        do{
        system("cls");
        printf("\n\n\t\t\tLIBRARY MANAGEMENT SOFTWARE\n\n");
        printf("\t\tWelcome to Students Mode: \n\n");
        printf("select the activity to perform\n");
        printf("\t1-View Books Available\n");
        printf("\t2-Borrow a book\n");
        printf("\t3-Updates \n");
        printf("\t4-Make a book Suggestions\n");
        printf("\t5-Open a Book\n");
        printf("\t6-Exit\n");
        if(c>0)
            printf("\n\t\tEnter a valid activity Number\n");
        printf("Choose Activity : ");
        scanf("%d",&activity);
        c++;
    }while(activity < 1 || activity >6);


      switch(activity)
        {
        case 1:
            {

    FILE *define;
   define= fopen("checker.dat","w");
    if(!define)
    {
        printf("Fail to create the file");
        exit(1);
    }
    int p = 1;
    fwrite(&p,sizeof(int),1,define);
    fclose(define);
    Loader();
                char books[45];
                FILE *viewer;
            viewer = fopen("Books.txt","r");
            if(!viewer)
            {
                printf("Failed to open the file...Books");
                exit(1);
            }
printf("\nThese are the current books in the library \n\n");
            while(fgets(books,45,viewer))
                    printf("\t%s ",books);

                 putchar('\n');
                system("pause");
                system("cls");
                goto here;
                break;
            }
        case 2:
            {
                char books[45];
                int n,i;
                printf("\t\t\tBorrow A Book\n\n");
                printf("\nHere, students are permitted to borrow Books from the Library\n\n");
                do
                {
                    c = 0;
                    if(c>0)
                    printf("\n\t************** Don't Exceed the limit*****************\n");
                    printf("How many Books will you like to Borrow (Max is 3) :");
                    scanf("%d",&n);
                    c++;
                }while(n<1 || n >3);
c=0;
                printf("\n\nEnter their respective Titles\n");
                char burrow[n][45];

                for(i=0;i<=n;i++)
                {
                    //fgets(burrow[i],45,stdin);
                      printf("\t- ");
                    //  scanf("%s",&burrow[i]);
                  fgets(burrow[i],45,stdin);

                }
                putchar('\n');
                for(i=0;i<n;i++)
                    printf("\n******** %s", burrow[i]);
                putchar('\n');

                 FILE *viewer,*next;
                 next = fopen("Burrow.dat","w");
            viewer = fopen("Books.txt","r");
            if(!viewer || !next)
            {
                printf("Failed to open the file...Books");
                exit(1);
            }

            fprintf(next,"%s                Wants to Borrow the following Books\n",stud_name);
                while(fgets(books,45,viewer))
                        for(i=0;i<n;i++)
                    {
         //               printf(" \n%s Comparing %s",books,burrow[i]);
                          if(!strcmp(books,burrow[i]) )
                          {
               //               printf("\nA Match is found %s\tand %s",books,burrow[i]);
                              fprintf(next,"%s",burrow[i]);
                            c++;
                          }

                    }
                    fclose(next);

                            printf("\n\n%d of the books were found in the library\n\n",c);
                            printf("\t\tYour Borrowing request has been sent to the Library attendant\n\n");
                printf("\n\t*********** Check your updates regularly to see the library attendants decision*************\n");


                putchar('\n');
                system("pause");
                system("cls");
                goto here;

                break;
            }
        case 3:
            {
                system("cls");
                printf(" \t\t\tBorrow Request \n");
                int ch;
                 FILE *next;
                next = fopen("Burrow.dat","r");
                if(!next)
                {
                    printf("**************** No Student Requests to Burrow a Book ************************\n\n");

                     putchar('\n');
                system("pause");
                system("cls");
                goto home;
                }

                while((ch = fgetc(next))!= EOF)
                    putchar(ch);

                printf("\n\n\n");
                system("pause");
                break;
            }
        case 4:
            {
                 int i;
                FILE  *viewer;
                viewer=fopen("Suggested_Books.txt","a");
                if(!viewer)
                {
                    printf("Failed to read the file\n");
                    exit(1);
                }
                int n;
                printf("\t\tSuggested  Books\n");
                printf("\tHere,You can write the titles of the book you will like the library attendant to add to the "
                       "current books in the Library\n\n");
                printf("How many books will you like to suggest: ");
                scanf("%d",&n);
                printf("\nEnter the Book titles %d\n",n);
                printf("\n\t\tNOTE: SEPERATE THE NAMES WITH UNDERCORES e.g Book_Title\n");
                printf("\tBook Titles\n");

                for(i=0;i<n;i++)
                {
                    char names[45];
                    printf("%d_ ",i+1);
                    //fgets(char names,45,stdin);
                    //fgets(names,45,stdin);
                    scanf("%s",&names);
                    fprintf(viewer,"\n%s",names);
                }
                fclose(viewer);
                printf("\n\tYour list has Successfully been sent to the library attendant\t\t\n");
                system("pause");
                system("cls");
                goto here;

                break;
            }
        case 5:
            {
              char name[255];
    DIR *handle;
    struct dirent *file;
    char book[45];

   /* printf("Enter the book to search for: ");
    scanf("%s",&book);

    handle = opendir(".");
    if(!handle)
    {
        printf("Failed to open the directory");
        exit(1);
    }
   while(file = readdir(handle))
   if(file->d_name,book)
         {
            printf(" \n\nThe book is found in the library");
            break;
         }
   // printf("Found folder '%s'\n",file->d_name );*/
   getcwd(name,255);
   //printf("\n\nThis is your Current working directory:\n\n %s\n\n\n",name);

   //chdir("css_tutorial.pdf");

   handle = opendir("css_tutorial.pdf");
   system("start css_tutorial.pdf");

    closedir(handle);


            }
        case 6:
            {
                return 0;
            }
        }


    }

    }


Re_Born()
{
    int class_name;
    int students,subjects,x,i,c;
    char teachers_name[20];
    char subject_Name[10][15];
    float constant;
    char swapper;
    c=0;

printf("\n\n\t\t\t**-THIS PROGRAM COMPUTES THE REPORT CARD OF ALL THE STUDENTS IN CLASS-**\n\n");
    printf("Enter the Class Masters name: ");
   fgets(teachers_name,20,stdin);
   fgets(teachers_name,20,stdin);
    printf("Enter the (class) Form(1,2,3,4,5) : " );
    scanf("%d",&class_name);
   printf("Enter the number of students in Class: ");
   scanf("%d",&students);

   printf("Enter the Number of subjets to register for: ");
   scanf("%d",&subjects);


    int coef[subjects];
     float Total_sum = 0;
     float sum_total[subjects];
     float average[students];

   struct Students_Record
   {
       char stud_name[20];
       float First_marks[subjects];
       float Second_marks[subjects];
       char gender;
       float stud_average;
       int positon;
   } stud[students];

   printf("\nEnter the Students Names and Gender  below ");

     struct Reg
     {
        char name[30];
        int age;
        int level;
        char gender;         //class
        time_t date;   // time of registration
        int admission_number;

    }student;
   printf(" \n\tNAMES\t\t\t\tGENDER(M/F)\n");

   for( x=0; x < students; x++)
   {
       printf("  :-  ");
  //   scanf("%s",stud[x].stud_name);
     fgets(stud[x].stud_name,20,stdin);
     fgets(stud[x].stud_name,20,stdin);
       printf("\t\t\t\t\t:-  ");
      scanf("%s",&stud[x].gender);

       FILE *viewer;
            viewer = fopen("Registration.db","r");
            if(!viewer )
            {
                printf("Sorry, No student has been registered Yet ");
                exit(1);
            }
            c=0;
            for(i=0;i<students;i++)
                while(fread(&student,sizeof(struct Reg),1,viewer))
                       {


                //         printf("\ncomparing %s and %s",stud[x].stud_name,student.name);


                       if(!strcmp(stud[i].stud_name,student.name))
                             {
                        //         printf("\t\tThere is a match here\n\n");


                                 c=1;
                                 break;
                             }
                             }
                             if(c == 0)
                             {
                                 c=2;
                                 printf("\nThere is no record of you.  Your name is not found in the database\n"
                                   "\n\t\tRegister before you can use this software\n");
                                 printf("Do you wish register this student(1/0): ");
                                 scanf("%d",&c);
                             }
                                }


here:


   printf("\nPlease Enter Every Subjects and their respective coefficients \n");

   printf("\n\tSUBJECTS\t\t\tCoeff\n");

   for(x=0 ;x<subjects ; x++)
   {
        printf(" :- ");
      scanf("%s",subject_Name[x]);
       printf("\t\t\t\t\t:- ");
      scanf("%d",&coef[x]);
   }

   printf("\nPlease follow up attentively, for every student name, Enter his/her"
          " corresponding marks\n\n");

    for(x=0 ;x<students ; x++)
    {
        printf("Student Name: \t\tSubjects\t\tFirst SeQ\t\tSecond SeQ \n");

        printf("\n%-15s ", stud[x].stud_name);
        for(i=0 ; i < subjects ; i++)
        {
            printf("\t\t\t%-25s-: ",subject_Name[i]);
            scanf("%f", &stud[x].First_marks[i]);
            printf("\t\t\t\t\t\t\t\t\t -:");
            scanf("%f", &stud[x].Second_marks[i]);
          //  putchar('\n');
      //      printf("\t\t");

        }
        printf("\n\t\t**********-Next Student-**********\n\n");

    }

     for(x=0 ; x<subjects ; x++)
    {
         c  = 20 * coef[x];
         Total_sum = Total_sum + c;

    }


//printf("\n\nThe total marks is %d\n\n ", Total_sum);
//******************* How to Calculate the Average **********************
// Multiply each students mark with the subjects coefficient and get the sum total

for(x=0 ; x< students ; x++)
{

    int s = 0;
     sum_total[x]=0;
        for(i=0 ; i<subjects ;i++)
       {
           s = stud[x].Second_marks[i]* coef[i];
           c=  stud[x].First_marks[i] * coef[i];
       // sum_total[x] = sum_total[x] + s + c;
            c = (s + c)*0.5;
        sum_total[x] =  sum_total[x] + c;
       }


}

for(x=0 ; x< students ; x++)
        for(i=0 ; i<subjects ;i++)
        {
            average[x]= (float)sum_total[x]/(float)Total_sum;
            average[x] = average[x]*20.0;

        }

    // Transfers the averages back to the Corresponding students
        for(x=0 ; x<students ; x++)
            stud[x].stud_average = average[x];


//************************* BUBBLE SORTING *************************************
int m;
for(x=0; x<students-1; x++)

    for(i=x+1 ; i < students ;i++)

    if(stud[i].stud_average > stud[x].stud_average)
    {
   // ******************* Swaps Position *****************************************
                        constant = stud[x].stud_average;
            stud[x].stud_average = stud[i].stud_average;
                 stud[i].stud_average = constant;

    //********************* Swaps Names *******************************************
                 for(m = 0 ; m<20 ; m++)
                 {
                                  swapper = stud[x].stud_name[m];
                     stud[x].stud_name[m] = stud[i].stud_name[m];
                     stud[i].stud_name[m] = swapper;
                     }
    //********************** Swaps Genders *****************************************

                       swapper = stud[x].gender;
                stud[i].gender = stud[x].gender;
                stud[i].gender = swapper;
    //************************* Swap Scores **************************************
    float score,score2;
    for(m=0;m<subjects;m++)
    {
                         score2= stud[x].Second_marks[m];
                         score = stud[x].First_marks[m];
        stud[x].First_marks[m] = stud[i].First_marks[m];
       stud[x].Second_marks[m]= stud[i].Second_marks[m];
         stud[i].First_marks[m]= score;
       stud[i].Second_marks[m] = score2;
        }

}

// Presents the report cards

printf(" \n\t\t\t Report Card\n\n ");
system("color f2");
for(i=0 ; i<students ; i++)
{
printf("+-----------------------------------------------------------------------------------------------------+");
printf("\t\t\t\t\t              GOVERNMENT   BILINGUAL   HIGH   SCHOOL\n\t\t\t\t\t                  BAMENDA");
printf("\n+-----------------------------------------------------------------------------------------------------+\n\n\n");

printf("Student's Name: %s\n",stud[i].stud_name);
printf("Class : form %d\n",class_name);
printf("Gender : %c \nClass masters name: %s",stud[i].gender,teachers_name);
printf("\n\t+----------------+-----------------------+-----------------------+---------------------+------------------+\n");
printf("\t| Subjects\t |\t1st Sequence\t  \b|\t2nd Sequence\t\b  |\tCoefficients\t\b|\tRemark\t  |");
printf("\n\t+----------------+-----------------------+-----------------------+---------------------+------------------+\n");
for(x=0 ; x<subjects ; x++)
   {
    printf("\t|%-15s |\t%-17.2f|\t%-17.2f|\t%-15d|\t",subject_Name[x],stud[i].First_marks[x],stud[i].Second_marks[x],coef[x]);

    if((stud[i].First_marks[x]+ stud[i].Second_marks[x])/2 < 5.0)
        printf("Very Poor     |");
    if((stud[i].First_marks[x]+ stud[i].Second_marks[x])/2>=5 && (stud[i].First_marks[x]+ stud[i].Second_marks[x])/2<10.0)
        printf("Weak          |");
    if((stud[i].First_marks[x]+ stud[i].Second_marks[x])/2>=10.0 && (stud[i].First_marks[x]+ stud[i].Second_marks[x])/2<15.0)
        printf("Fairly Good   |");
    if((stud[i].First_marks[x]+ stud[i].Second_marks[x])/2 >= 15.0 && (stud[i].First_marks[x]+ stud[i].Second_marks[x])/2<17.0)
        printf("Very Good     |");
    if((stud[i].First_marks[x]+ stud[i].Second_marks[x])/2>=17.0 && (stud[i].First_marks[x]+ stud[i].Second_marks[x])/2<=20)
        printf("Excellent     |");
    printf("\n\t+----------------+-----------------------+-----------------------+---------------------+------------------+\n");

   }

printf("\n____________________________________________________________\n");
printf("Average: %.2f\t\t\tRANK: %d/%d\n\n",stud[i].stud_average,i+1,students );

printf("\t\t\t********************** NEXT STUDENT***************************\n\n");
}
system("Pause");
getchar();
}



