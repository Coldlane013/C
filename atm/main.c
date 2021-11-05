#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include<ctype.h>
#include <string.h>
// if input is valid
void loader(void);
void design(void);
void design2(void);
void exitdesign(void);
void transaction_panel(void);
int transact(){
float balance = 0;
int anotherTransaction = 1;
while(anotherTransaction == 1){
    int option;
    system("cls");
    design();
    printf("\t\tWhat transaction will you do?\n");
    printf("\t\t[1] : Check Balance");
    printf("\t[2] : Deposit");
    printf("\t[3] : Withdrawal");
    printf("  [4] : Exit \n");
    printf("\t\tChoice:");
    scanf("%d",&option);
    if(option == 1)//balance check
    {   transaction_panel();
        printf("\t\tYour balance is: PHP%f\n", balance);
    }
    // deposit
    else if (option == 2){
        int amountDeposit;
        printf("\t\tHow much money do you want to deposit? PHP:");
        scanf("%d",&amountDeposit);
        if(amountDeposit>0){
        balance += amountDeposit;
        transaction_panel();
        printf("\t\tYou have deposited %d into your account.\n",amountDeposit);
        printf("\t\tYour current balance is : %f\n",balance);
        }
        else{
            transaction_panel();
            printf("\t\tInvalid deposit amount\n");
        }
    }
    //withdrawal
    else if(option == 3)
    {
       int amountWithdraw;
       printf("\t\tHow much money do you want to withdraw? PHP:");
       scanf("%d",&amountWithdraw);

       if(amountWithdraw <= balance && amountWithdraw <=20000)
       {
        balance -=amountWithdraw;
        transaction_panel();
        printf("\t\tYou have withdrawn %d from your account.\n",amountWithdraw);
        printf("\t\tThe current balance from your account is %f.\n",balance);
       }
       else
       {
            if(amountWithdraw > 20000)
           {
            transaction_panel();
               printf("\t\tMaximum withdrawal reached. Transaction denied.\n");
           }
           else if (amountWithdraw > balance)
           {
               transaction_panel();
               printf("\t\tInsufficient balance.Transaction denied.\n");
           }

       }
    }
    //exit
     else if(option==4){
        system("cls");
        exitdesign();
printf("\n\t\t\t\t\t   THANK YOU FOR USING OUR SEVICE.\n\n\n");
 exit(0);
    }
    //error
    else{
        printf("\t\tInvalid Transaction\n");
    }
    anotherTransaction = 0;

    while(anotherTransaction !=1 && anotherTransaction !=2)
        {
    printf("\t\tDo you want to do another transaction?\n");
    printf("\t\t[1]YES\t\t\t[2]NO\n");
    printf("\t\tChoice: ");
      scanf("%d",&anotherTransaction);
      system("cls");
    }

}// exit.sucess
exitdesign();
printf("\n\t\t\t\t\t   THANK YOU FOR USING OUR SEVICE.\n\n\n");
 exit(0);
}
int choice(){
  int choiceYN;
  printf("\n\n\t\t  INVALID INPUT.\n");
    printf("\t\t  Do you still want to continue?\n");
    printf("\t\t  [1]YES\t\t\t[2]NO\n");
    printf("\t\t  Choice: ");

    scanf("%d",&choiceYN);
     if(choiceYN == 1){
      system("cls");
      return (main());
     }
    else{
            system("cls");
            exitdesign();
            printf("\n\t\t\t\t\t   THANK YOU FOR USING OUR SEVICE.\n");
        return 0 ;
    }
}
// if input is not valid

int main(){
  const int maxPasswordLength = 4;
  char password[maxPasswordLength+1];
  char ch;
  //store character 0 = position value in array
  int characterPosition = 0;
  loader();
  system("cls");
  design();
  design2();
  printf("\t\t\t\tEnter PIN:",maxPasswordLength);
  // 1= true 13= ASCII enter button 8=ASCII for backspace
  // read input
  while(1){
    ch = _getch();
    // if user enter button loop stop
    if(ch == 13){
      if(strlen(password)== 0 || strlen(password)<4){
      choice();
    }
    else{
            system("cls");
            design();
            transact();
    }
    }
    else if (ch==8){
        if( characterPosition > 0){
        characterPosition--;
        password[characterPosition]='\0';
        printf("\b \b");
        }// \b = cursor to go back
    }else if (ch==32 || ch == 9){
      continue; //when user hits space or tab
    }else{
      if(characterPosition < maxPasswordLength){
        password[characterPosition] = ch;
        characterPosition++;
        printf("*");
      }else{
          choice();
      }
    }
  }
  password[characterPosition] ='\0';
  printf("\n");

    return 0 ;
}
void loader(){
int i;
system("cls");
printf("\n\n\n\n\t\t\t Please wait Loading:");
for(i=0;i<50;i++){
    Sleep(30);
    printf("%c",219);
}
}
void design(){
 printf("\t\t\t ===============================================\n");
  printf("\t\t\t -----------------------------------------------\n");
  printf("\t\t\t  =============================================\n");
  printf("\t\t\t\t\t    --------\n");
  printf("\t\t\t\t\t    | 0000 |\n");
  printf("\t\t\t\t\t   | 000000 |\n");
  printf("\t\t\t\t\t   | 000    |\n");
  printf("\t\t\t\t\t   |  0     |\n");
  printf("\t\t\t\t\t    | 0    | \n");
  printf("\t\t\t\t\t    --------\n");
  printf("\t\t\t            PHIL-FIRST SIMPLE ATM SYSTEM\n");
   printf("\t\t\t      Prepared by: Nicole Alvarez\n");
    printf("\t\t\t                   Lalaine Costales\n");
    printf("\t\t\t                   Joan Dela Austria\n");
    printf("\t\t\t                   Marjorie Ilano\n");
    printf("\t\t\t                    BSIS-1B\n");
  printf("\t\t\t    ===========================================\n");
  printf("\t\t\t   ---------------------------------------------\n");
  printf("\t\t\t   =============================================\n\n");
}
void design2(){
  printf("\tNOTE: To are valued users, please rememeber that pin is consist of 4 integers.Thankyou.\n\n");
}
void exitdesign(){
printf("\t\t\t           ===============================================\n");
 printf("\t\t  __     __       =================================================\n");
 printf("\t\t /  %c   /  %c       ---    ---    ---  -----  -----  --  --  -----|\n",92,92);
 printf("\t\t/    %c_/    %c     /      /   %c  /   %c |    %c |    %c  %c  /  |  \n",92,92,92,92,92,92,92);
 printf("\t        |  ==   ==  |    /  ___ /     %c/     %c|     %c|____/   %c/   |---|\n",92,92,92,92,92,92);
 printf("\t        %c     0     /    %c     /%c     /%c     /|     /|    %c   /    |\n",92,92,92,92,92);
 printf("\t        +++++++++++++     %c__ /  %c___/  %c___/ |____/ |____/  /     |_____|\n",92,92,92,92,92);
 printf("\t\t  +       +       =================================================\n");
 printf("\t\t    +++++          ===============================================\n");
}
void transaction_panel(){
 printf("\t\t=====================================================\n");
    printf("\t\t ****************Transaction Summary****************\n");
    printf("\t\t=====================================================\n");
}





