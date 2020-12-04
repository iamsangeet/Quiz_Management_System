#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
///declaration of structure
struct Quizplay{
char questions[1000];
int qno;
char a[150];
char b[150];
char c[150];
char d[150];
char answer;
}ques;
//function declaration
//FUNCTION DECLARATION
void admin();
void add();
void display();
void search();
void update();
void deleterec();
int comp(int qn);
int count();
int empty();
void play(int N);
///main implementation
int main(){
//structure variable
int choice,c;
char playername[50];


///main homr
 mainhome:
     system("cls");
     printf("\t\t\tC PROGRAM QUIZ GAME\n");
     printf("\n\t\t________________________________________");

     printf("\n\t\t\t   WELCOME ");
     printf("\n\t\t\t      to ");
     printf("\n\t\t\t   THE GAME ");
     printf("\n\t\t________________________________________");
     printf("\n\t\t________________________________________");
     printf("\n\t\t   TEST YOUR GK!!!!!!!!!!!    ") ;
     printf("\n\t\t________________________________________");
     printf("\n\t\t________________________________________");
     printf("\n\t\t > Press 1 for Admin control");
     printf("\n\t\t > Press 2 to start game  ");
     printf("\n\t\t > Press 3 to quit");
     printf("\n\t\t________________________________________\n\n");
     scanf("%d",&choice);
      if (choice==1)
	{
	admin();
	goto mainhome;
	}


	else if (choice==3){
	exit(1);
	}
    else if(choice==2)
    {
     system("cls");

    printf("\n\n\n\n\n\n\n\n\n\n\t\t\tResister your name:");
     gets(playername);

    system("cls");
    printf("\n ------------------  Welcome %s to C Program Quiz Game --------------------------",playername);
    printf("\n\n Here are some tips you might wanna know before playing:");
    printf("\n\n\n Press Y  to start the game!\n");
    printf("\n Press any other key to return to the main menu!");
    if (tolower(getch())=='y')
		{
		    c=count();
		    play(c);
		    goto mainhome;
        }
	else
		{
        goto mainhome;
        system("cls");
       }
}
getch();
return 0;

}//main ends
//dunction definition
//admin menu
void admin()
{
    system("cls");
   int choice;
   printf("Enter a choice \n1)Add \t\t2)display \n3)search \n4)update \t5)delete \n6)Goto main menu");
   scanf("%d",&choice);
   switch(choice)
   {
   case 1:
   add();
   break;
   case 2:
    display();
    break;
   case 3:
    search();
    break;
   case 4:
    update();
    break;
    case 5:
    deleterec();
    case 6:
    break;
    default:
    printf("\nInvalid choice");
   }
}
//    FUNCTION TO INSERT RECORDS TO THE FILE
void add()
{
    system("cls");
 FILE *fp;
 fp = fopen("questions.dat", "a");
 printf("Enter the Question no  : ");
 scanf("%d", &ques.qno);
 printf("Enter the Question    : ");
 fflush(stdin);
 gets(ques.questions);
 printf("Enter the option 'a' : ");
 fflush(stdin);
 gets(ques.a);
 printf("Enter the option 'b': ");
 fflush(stdin);
 gets(ques.b);
 printf("Enter the option 'c': ");
 fflush(stdin);
 gets(ques.c);
 printf("Enter the option 'd': ");
 fflush(stdin);
 gets(ques.d);
 printf("Enter the answer: ");
 fflush(stdin);
 scanf("%c",&ques.answer);
 fwrite(&ques, sizeof(ques), 1, fp);
 fclose(fp);
 printf("\n the question has been added");
 getch();
}
//    FUNCTION TO DISPLAY RECORDS
void display()
{
    system("cls");
 FILE *fp1;
 fp1 = fopen("questions.dat", "r");
 while (fread(&ques, sizeof(ques), 1, fp1))
 printf(" \nQ.%d  %s \na)%s \tb)%s \nc)%s \td)%s \nAnswer: %c", ques.qno, ques.questions, ques.a, ques.b, ques.c, ques.d ,ques.answer);
 fclose(fp1);
 getch();
}
//function definition to search a question according to the number
void search()
{
    system("cls");
 FILE *fp2;
 int r, s, avl;
 printf("\nEnter the Question no. you want to search  :");
 scanf("%d", &r);
 avl = comp(r);
 if (avl == 0)
  printf("Question no.%d is not available in the file\n",r);
 else
 {
  fp2 = fopen("questions.dat", "r");
  while (fread(&ques, sizeof(ques), 1, fp2))
  {
   s = ques.qno;
   if (s == r)
   {
    printf("\n %s", ques.questions);
    printf("\n a.%s", ques.a);
    printf("\n b.%s", ques.b);
    printf("\n c.%s", ques.c);
    printf("\n d.%s", ques.d);
    printf("\n the correct answer is %c",ques.answer);
   }//if ends
  }//while ends
  fclose(fp2);
 }//if-else ends
 getch();
}
//    FUNCTION TO DELETE A RECORD
void deleterec()
{
    system("cls");
 FILE *fpo;
 FILE *fpt;
 int r, s;
 printf("Enter the Question no you want to delete :");
 scanf("%d", &r);
 if (comp(r) == 0)
  printf("Question no %d is not available in the file\n", r);
 else
 {
  fpo = fopen("questions.dat", "r");
  fpt = fopen("TempFile.dat", "w");
  while (fread(&ques, sizeof(ques), 1, fpo))
  {
   s = ques.qno;
   if (s != r)
    fwrite(&ques, sizeof(ques), 1, fpt);
  }//while ends
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("questions.dat", "w");
  fpt = fopen("TempFile.dat", "r");
  while (fread(&ques, sizeof(ques), 1, fpt))
   fwrite(&ques, sizeof(ques), 1, fpo);
  printf("\nQUESTION DELETED\n");
  fclose(fpo);
  fclose(fpt);
 }//if-else ends
getch();
}
//    FUNCTION TO UPDATE THE RECORD
void update()
{
    system("cls");
 int avl;
 FILE *fpt;
 FILE *fpo;
 int s, r, ch;
 printf("Enter Question no to update:");
 scanf("%d", &r);
 avl = comp(r);
 if (avl == 0)
 {
  printf("Question no %d is not Available in the file", r);
 }
 else
 {
  fpo = fopen("questions.dat", "r");
  fpt = fopen("TempFile.dat", "w");
  while (fread(&ques, sizeof(ques), 1, fpo))
  {
   s = ques.qno;
   if (s != r)
    fwrite(&ques, sizeof(ques), 1, fpt);
   else
   {
    printf("\n\t1. Update Question of Question no %d", r);
    printf("\n\t2. Update option 'a' of Question no %d", r);
    printf("\n\t3. Update option 'b' of Question no %d", r);
    printf("\n\t4. Update option 'c' of Question no %d", r);
    printf("\n\t5. Update option 'd' of Question no %d", r);
    printf("\n\t6. Update answer of Question no %d", r);
    printf("\n\t7. Update all Question, option and answer of question %d", r);
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    //MENU
    switch (ch)
    {
    case 1:
     printf("Enter Question:");
     fflush(stdin);
     gets(ques.questions);
     break;
    case 2:
     printf("Enter option 'a': ");
     fflush(stdin);
     gets(ques.a);
     break;
    case 3:
     printf("Enter option 'b': ");
     fflush(stdin);
     gets(ques.b);
     break;
    case 4:
     printf("Enter option 'c': ");
     fflush(stdin);
     gets(ques.c);
     break;
    case 5:
     printf("Enter option 'd': ");
     fflush(stdin);
     gets(ques.d);
     break;
    case 6:
     printf("Enter answer: ");
     fflush(stdin);
     scanf("%c",&ques.answer);
     break;
    case 7:
     printf("Enter Question:");
     fflush(stdin);
     gets(ques.questions);
     printf("Enter option 'a': ");
     fflush(stdin);
     gets(ques.a);
     printf("Enter option 'b': ");
     fflush(stdin);
     gets(ques.b);
     printf("Enter option 'c': ");
     fflush(stdin);
     gets(ques.c);
     printf("Enter option 'd': ");
     fflush(stdin);
     gets(ques.d);
     printf("Enter answer: ");
     fflush(stdin);
     scanf("%c",ques.answer);
     break;
    default:
     printf("Invalid Selection");
     break;
    }
    fwrite(&ques, sizeof(ques), 1, fpt);
   }//inner if-else ends
  }//while loop ends
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("questions.dat", "w");
  fpt = fopen("TempFile.dat", "r");
  while (fread(&ques, sizeof(ques), 1, fpt))
  {
   fwrite(&ques, sizeof(ques), 1, fpo);
  }//while loop ends
  fclose(fpo);
  fclose(fpt);
  printf("QUESTION UPDATED");
 }//if-else ends
 getch();
}
//    FUNCTION TO CHECK GIVEN QUESTION NUMBER IS AVAILABLE //
int comp(int qn)
{
 FILE *fp;
 int c = 0;
 fp = fopen("questions.dat", "r");
 while (!feof(fp))
 {
  fread(&ques, sizeof(ques), 1, fp);

  if (qn == ques.qno)
  {
   fclose(fp);
   return 1;
  }//if ends
 }//while loop ends
 fclose(fp);
 getch();
 return 0;
}
//FUNCTION TO CHECK THE FILE IS EMPTY OR NOT
int empty()
{
 int c = 0;
 FILE *fp;
 fp = fopen("questions.dat", "r");
 while (fread(&ques, sizeof(ques), 1, fp))
  c = 1;
 fclose(fp);
 return c;
}
//FUNCTION TO COUNT QUESTION
int count()
{
 int c = 0;
 FILE *fp;
 fp = fopen("questions.dat", "r");
 while(fread(&ques,sizeof(ques),1,fp))
    c++;
 return c;
}
//FUNCTION TO PLAY GAME
void play(int N)
{
    system("cls");
FILE *fp;
fp = fopen("questions.dat", "r");
int score=0,i;
char ans;
struct Quizplay q[N];
for(i=0;i<N;i++)
{
    fread(&q[i],sizeof(q[i]),1,fp);
    printf("\nQ.%d  %s \na)%s \tb)%s \nc)%s \td)%s \n", q[i].qno, q[i].questions, q[i].a, q[i].b, q[i].c, q[i].d);
    fflush(stdin);
    scanf("%c",&ans);
    if(tolower(ans)==tolower(q[i].answer))
    {
       score++;

    }else
    {
        printf("\nThe correct answer is %c",q[i].answer);


    }
}
printf("\nYour score is %d",score);
getch();
}

