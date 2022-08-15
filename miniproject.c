#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>   
//#include<limits.h>
struct node
{
    int money;
    struct node *next;
};

struct st1
{   
    char name[120];
    char ph_no[20];
    char email[30];
    char reference_id[30];
    char wifi_plan[10];
    int roomno;
    int floor;
    int no_of_people;
    char arrivaldate[25];
}room;


int top = -1;
int arr[199];
int space[4][7] = {{101,102,103,104,105,106,107},{201,202,203,204,205,206,207},{301,302,303,304,305,306,307},{401,402,403,404,405,406,407}};


int Top(){
    if(top == -1){return -1;}
    return arr[top];
}
void push(int x){
    if(top == 199){
        printf("The stack is full\n");
        return ;
    }
    top++;
    arr[top] = x;
}

  
void sum(){
    int i = 0;
    int Sum = 0;
    
    for(i=0;i<=top;i++){
        printf(" %d . %d\n",i+1,arr[i]);
        Sum = Sum + arr[i];
    }
    printf("\t\tYour Profit is %d \n",Sum);
    printf("\t\tPress Enter to continue\n");
    getch();
}

int  checkPhoneNum(char num[]){
    int count = 0;
    
    while(num[count]!='\0'){
      
       ++count;
    }
    if(count== 10){
        return 1;//valid phno.
    }
    else{
        printf("Not valid phone number!\n\n");
        Sleep(900);
        return 0;
    }
}
int tickroom(int);
void BUSINESSROOM();
void DELUXEROOM();
void TWOBHK();
void ONEBHK();
void BOOKROOM2(); // This function is present in BOOKROOM1.
void WIFI();
void CHECK_AVAILABLE_ROOMS();
void BOOKROOM1();
void DISPLAY();
// void SEARCH_CUSTOMER_ROOMS();
void ADD_FOOD_IN_MENU_LIST();
void ORDER_FOOD();
void MONEY_STATISTICS();

int  tickroom(int num){
   
    int found = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<7;j++){
            if(space[i][j] == num){
               found = 1;
              space[i][j] = 0;
              return found;
            }
        }
    }
    if(found == 0){printf("\t\tRoom is not vacant\n");return found;}
}

char *hidden_pass()
{
    char string[29];
    char *ptr;
    int i = 0;
    char ch;
    while ((ch = _getch()) != 13)
    {
        printf("*");
        string[i] = ch;
        i++;
    }
    string[i] = '\0';
    ptr = string;
    return ptr;
}

int main()
{   system("color 02");
    time_t wordclk;
    char Option1;
    char pword[25] = "password";
    char str2[25];
    char *type_pass;
    int n = 0;
    wordclk = time(NULL);
    
    printf("\t\tEnter any key to route to login window\n");
    Option1 = getch();
    system("cls");
    for (int i = 0; i < 80; i++)
        printf("-");
    printf("\nDATE\t:\t%s\n", ctime(&wordclk));
    for (int i = 0; i < 80; i++)
        printf("-");

    printf("\n\n\n");
    printf("\t\t*************************************************************************************\n");
    printf("\t\t**                                                                                 **\n");
    printf("\t\t**                  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                             **\n");
    printf("\t\t**                  @                                @                             **\n");
    printf("\t\t**                  @      WELCOME TO THE RESORT     @                             **\n");
    printf("\t\t**                  @       SUNRISE & SUNSHINE       @                             **\n");
    printf("\t\t**                  @                                @                             **\n");
    printf("\t\t**                  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                             **\n");
    printf("\t\t**                                                                                 **\n");
    printf("\t\t*************************************************************************************\n");
    printf("\n\n");
    // Sleep(4000);     later uncomment this line.
     printf("\n\t\t\t\t\t****WELCOME TO THE LOGIN WINDOW****\t\t\n");
    for (int i = 0; i < 6; i++)
    {
      
        fflush(stdin);
        printf("\n\n\t\tEnter your back up password :\n");
        type_pass = hidden_pass();
        int j;
        j = 0;
        while (*type_pass != '\0')
        {
            str2[j] = *type_pass;
            j++;
            type_pass++;
        }
        str2[j] = '\0';

        
        if (strcmp(pword, str2) == 0)
        {
            
            printf("\n\n\n\nAdmin verfied Successfully.\n\n");
            printf("\n\n\t\t\tLoading...");
            Sleep(3000);
            BOOKROOM1();
            break;
        }
        else
        {
            printf("\nPassword not matched.You have %d trials\n", 5 - i - 1);
         
            if (i == 4)
            {
                printf("No more Attempts are given to login \n");
                break;
            }
        }
    }
    printf("Initiating Termination Process!!\n");
    Sleep(2000);
    for(int i=0;i<5;i++){
        Beep(750,200);
    }
    Sleep(1000);
    printf("Program Terminated\n");
    Beep(750,2000);
    return 0;
}

void MONEY_STATISTICS()
{   system("cls");
    time_t clock1;
    clock1 = time(NULL);
    printf("\t\tDATE\t:\t%s\n", ctime(&clock1));
    for (int i = 0; i < 90; i++){
        printf("-");
    }
    printf("\n");
    printf("\t\tYour current profit is displayed below:\n");
    for (int i = 0;i<90; i++){
        printf("\t\t-");
    }
    printf("\n");
    printf("\t\tHit enter key to proceed\n");
    getch();
    sum();
    return ;
}

void DISPLAY()
{   system("cls");
    FILE *room_book;

    char buffer[256];
    if (room_book == NULL)
    {
        printf("Loading file ...\n");
        Sleep(2000);
    }
    room_book = fopen("ROOMBOOKINGS.txt", "r");
    while (!feof(room_book))
    {
        //fflush(stdin);
        fgets(buffer,256, room_book);
        printf("%s", buffer);
    }
    fclose(room_book);
    printf("\n\nEnter any key to continue\n");
    getch();
}

void ADD_FOOD_IN_MENU_LIST()
{
    FILE *fooditems;
    int num;int num1;
    char buff[256];
    system("cls");
    printf("Press any num-1 key to Route to the main Menu (Optional) (press num 1) : ");
    scanf("%d", &num1);
    if(num1 == 1){
        BOOKROOM1();
        
    }
    system("cls");
    printf("How many number of food items do you want to enter\n");
    scanf("%d",&num);
    if (fooditems == NULL)
    {
        printf("The file cannot be opened\n");
    }
    fooditems = fopen("FOOD_ITEMS.txt", "a+");

    for (int i = 0; i < num; i++)
    {
        fflush(stdin);
        printf("Enter your  %d food item\n", i + 1);
        gets(buff);
        fprintf(fooditems, "\n%s\n", buff);
    }
    fclose(fooditems);
    printf("The file contents are successfully written\n");
    printf("\n\nEnter any key to continue\n");
    getch();
}
void WIFI()
{   system("cls");
    int num;
    do{
    printf(" ------------- OUR WIFI PLANS ---------------\n");
    printf("1 - 1.5GB/day ===== $25\n");
    printf("2 - 3GB /day  ===== $70\n");
    printf("Enter the your choice as mentioned numbers\n");
    scanf("%d", &num);
    if (num == 1)
    {   push(25);
        strcpy(room.wifi_plan,"1.5GB");
        
    }
    else if (num == 2)
    {   push(70);
        strcpy(room.wifi_plan,"3GB");
        
    }

    else{
        printf("Enter valid input\n");
    }
    fflush(stdin);
  }while(num<1 || num>2);
    printf("Enter to continue\n");
   getch();
}

void ONEBHK()
{
    system("cls");
    fflush(stdin);
    time_t t1;
    char ch;
    int N;
    t1 = time(NULL);
    FILE *room_book;
    int floor1 = 1;
    int Roomno;
    int found = 1;
    int day;
     printf("\t\tDATE\t:\t%s\n\n",ctime(&t1));
    if (room_book == NULL)
    {
        printf("File Loading\n");
      
    }
    do{
        system("cls");
    printf("\n\tEnter the room number between 101 - 107 : ");
    scanf("%d",&Roomno);
    if(Roomno<101 || Roomno>107){printf("\n\tThe room number is not valid !\n");Sleep(1000);}
    }while(Roomno<101 || Roomno>107);
    fflush(stdin);
    found = tickroom(Roomno);
    if (found == 0)
    {
        printf("%d room is not vacant \n",Roomno);
        fclose(room_book);
        fflush(stdin);
        BOOKROOM2();
    }

    else if (found == 1)
    {
        room.roomno = Roomno;
        room.floor = floor1;
        printf("\n\t%d room is vacant ",Roomno);
        fflush(stdin);
        printf("\n\tEnter your name : ");
        
        gets(room.name);
        
        do{
            fflush(stdin);
        printf("\n\tEnter your phone number : ");
        scanf("\n%s", room.ph_no);}while(checkPhoneNum(room.ph_no)!=1);
        printf("\n\tEnter your email : ");
        scanf("\n%s", room.email);
        printf("\n\tEnter the no.of room accomadation members : ");
        scanf("%d", &room.no_of_people);
        printf("\n\tEnter how many days you want to stay : ");
        scanf("\n%d", &day);
        fflush(stdin);
        printf("\n\tEnter your arrival date [Day/Month/Year] : ");
        scanf("\n%s", room.arrivaldate);

        printf("\n\tEnter your reference ID - Adharcard,identity card....  : ");
        scanf("\n%s", room.reference_id);
        N = day*700;
        push(N);
       
        printf("\n\n\tAmount paid successfully\n");
        
        printf("\n\tPress enter key to get wifi service or else press any key\n");
        ch = getch();
        if (ch == 13)
        {
            WIFI();
            printf("\tWifi plan successfully accessed\n");
        }
        else
        {   strcpy(room.wifi_plan,"No");
            printf("\tWifi access denied\n");
        }
    }
    room_book = fopen("ROOMBOOKINGS.txt", "a+");
    fprintf(room_book, "Booking time - %s\n", ctime(&t1));
    fprintf(room_book, "Name : %s\n", room.name);
    fprintf(room_book, "Phone number : %s\n", room.ph_no);
    fprintf(room_book, "Email : %s\n", room.email);
    fprintf(room_book, "Wifi plan : %s\n",room.wifi_plan);
    fprintf(room_book, "Number days to stay : %d\n",day);
    fprintf(room_book, "Reference Id : %s\n", room.reference_id);
    fprintf(room_book, "Room number : %d\n", room.roomno);
    fprintf(room_book, "Floor number : %d\n", room.floor);
    fprintf(room_book, "Number of people : %d\n", room.no_of_people);
    fprintf(room_book, "Arrival date : %s\n", room.arrivaldate);
    
    fclose(room_book);
    printf("All contents are successfully recorded\n");Sleep(1000);
}

void TWOBHK()
{
    fflush(stdin);
    system("cls");
    time_t t2;
    int N;
    char ch;
    t2 = time(NULL);
    FILE *room_book;
    int found = 1;
    int day;
    if (room_book == NULL)
    {
        printf("The file is loading\n");
        
    }
    int floor2 = 2;
    int Roomno;
    do{
        system("cls");
        printf("\n\tEnter the room number of second floor 201 - 207 : ");
        scanf("%d",&Roomno);
        if(Roomno<201 || Roomno>207){
            printf("\n\tThe room number is not valid !");Sleep(1000);
        }
    }while(Roomno<201 || Roomno>207);
    found = tickroom(Roomno);
    fflush(stdin);
    
    if (found == 0)
    {
        printf("%d room is not vacant\n",Roomno);
        Sleep(1000);
        fclose(room_book);
        BOOKROOM2();
    }
    else if (found == 1)
    {
        room.floor = floor2;
        room.roomno = Roomno;
        printf("\n\t%d room is vacant \n",Roomno);
        fflush(stdin);
        printf("\n\tEnter your Name : ");
        gets(room.name);
        do{
        printf("\n\tEnter your phone number : ");
        scanf("\n%s",room.ph_no);}while(checkPhoneNum(room.ph_no)!=1);
        printf("\n\tEnter your email : ");
        scanf("\n%s",room.email);
        printf("\n\tEnter the no.of room accomadation members : ");
        scanf("%d",&room.no_of_people);
        printf("\n\tHow many number of days you want stay : ");
        scanf("\n%d",&day);

        printf("\n\tEnter your arrival date [Day/Month/Year] : ");
        scanf("\n%s",room.arrivaldate);
        printf("\n\tEnter your reference ID - Adharcard,identity card.... : ");
        scanf("\n%s",room.reference_id);
        N = day*900;
        push(N);
        
        printf("!!Payment done successfully\n");
        printf("\n\tPress enter key to get wifi service or else press any key\n");
        ch = getch();
        if (ch == 13)
        {
            WIFI();
            printf("\n\tWifi plan successfully accessed\n");
        }
        else
        {   strcpy(room.wifi_plan,"No");
            printf("\n\tWifi access denied\n");
        }
    }

    room_book = fopen("ROOMBOOKINGS.txt", "a+");
    fprintf(room_book, "Booking time : %s\n", ctime(&t2));
    fprintf(room_book, "Name : %s\n", room.name);
    fprintf(room_book, "Phone Number : %s\n", room.ph_no);
    fprintf(room_book, "Email : %s\n", room.email);
    fprintf(room_book, "Wifi plan : %s\n",room.wifi_plan);
    fprintf(room_book, "Room number : %d\n", room.roomno);
    fprintf(room_book, "Floor number : %d\n", room.floor);
    fprintf(room_book, "Number of days to stay is %d\n",day);
    fprintf(room_book, "Number of people in %d room is %d\n", room.roomno, room.no_of_people);
    fprintf(room_book, "Arrival date : %s\n", room.arrivaldate);
    fprintf(room_book, "Reference Id : %s\n", room.reference_id);
    fclose(room_book);
    printf("\n\n\tContents are successfull written in to the file\n");
    Sleep(1000);
}

void BUSINESSROOM()
{
    fflush(stdin);
    system("cls");
    FILE *room_book;
    time_t t3;
    char ch;
    t3 = time(NULL);
    int N;
    int floor3 = 3;
    int found = 1;
    int day;
    int Roomno;
    if (room_book == NULL)
    {
        printf("File is loading\n");
        
    }
    do{
        system("cls");
    printf("\n\tEnter room number between 301 - 307 : ");
    scanf("%d",&Roomno);
    if(Roomno<301||Roomno>307){printf("\n\tThe roomnumber is not valid !\n");Sleep(1000);}
    }while(Roomno<301 || Roomno>307);
    found = tickroom(Roomno);
    fflush(stdin);
    if (found == 0)
    {
        printf("%d room is not vacant\n",Roomno);
        // fclose(room_book);
        fflush(stdin);
        BOOKROOM2();
    }
    else if (found == 1)
    {
        room.roomno = Roomno;
        room.floor = floor3;
        printf("%d room is vacant \n",Roomno);
        fflush(stdin);
        printf("\n\tEnter your name \n");
        gets(room.name);
        fflush(stdin);
        do{printf("\n\tEnter your phone number : ");
        scanf("\n%s",room.ph_no);}while(checkPhoneNum(room.ph_no)!=1);
        printf("\n\tEnter your email ID : ");
        scanf("\n%s",room.email);
        printf("\n\tEnter the number of room accomadation members : ");
        scanf("\n%d",&room.no_of_people);
        // fflush();
        printf("\n\tHow many days you want to leave : ");
        scanf("\n%d",&day);
        printf("\n\tMention your Arrival date [Day/Month/year] : ");
        scanf("\n%s",room.arrivaldate);
        printf("\n\tEnter your reference ID - Adharcard,identity card... : ");
        scanf("\n%s",room.reference_id);
        N = day*1200;
        push(N);
        
        printf("!!Amount paid successfully\n");
        printf("\n\tPress enter key to get wifi service or else press any key\n");
        ch = getch();
        if (ch == 13)
        {
            WIFI();
            printf("\n\tWifi plan successfully accessed\n");
        }
        else
        {   strcpy(room.wifi_plan,"No");
            printf("\n\tWifi access denied\n");
        }
    }

    room_book = fopen("ROOMBOOKINGS.txt", "a+");
    fprintf(room_book, "Time booking : %s\n",ctime(&t3));
    fprintf(room_book, "Name : %s\n",room.name);
    fprintf(room_book, "Email : %s\n",room.email);
    fprintf(room_book, "Wifi plan : %s\n",room.wifi_plan);
    fprintf(room_book, "Phone Number : %s\n",room.ph_no);
    fprintf(room_book, "Reference ID : %s\n",room.reference_id);
    fprintf(room_book, "Room number : %d\n",room.roomno);
    fprintf(room_book, "Floor number : %d\n",room.floor);
    fprintf(room_book, "Number of days to stay : %d\n",day);
    fprintf(room_book, "Number of members in %d room is %d\n",room.roomno,room.no_of_people);
    fprintf(room_book, "Arrival date : %s\n",room.arrivaldate);
    fclose(room_book);
    printf("All the content are loaded into the file successfully\n");
    Sleep(1000);
}

void DELUXEROOM()
{
    system("cls");

    FILE *room_book;
    time_t t4;
    char ch;
    t4 = time(NULL);
    printf("\t\tDATE\t:\t%s\n",ctime(&t4));
    int N;
    int floor4 = 4;
    int found = 1;
    int day;
    int Roomno;
    if (room_book == NULL)
    {
        printf("File loading\n");
        
    }
    do{
    system("cls");
    printf("\n\tEnter room number between 401 - 407 : ");
    scanf("%d",&Roomno);
    if(Roomno<401 || Roomno>407){printf("\n\tThe room number is not valid !\n");Sleep(1000);}
    }while(Roomno<401 || Roomno>407);
    found = tickroom(Roomno);
    fflush(stdin);
    // printf("Payment done successfully\n");
    if (found == 0)
    {
        printf("%d room is not vacant\n",Roomno);
        BOOKROOM2();
    }
    else if (found == 1)
    {
        room.roomno = Roomno;
        room.floor = floor4;
        printf("%d room is vacant \n",Roomno);
        fflush(stdin);
        printf("\n\tE\n\tnter your name \n");
        gets(room.name);
        fflush(stdin);
        do{
        printf("\n\tEnter your phone number : ");
        scanf("\n%s",room.ph_no);}while(checkPhoneNum(room.ph_no)!=1);
        printf("\n\tEnter your email ID : ");
        scanf("\n%s",room.email);
        printf("\n\tEnter the number of room accomadation members : ");
        scanf("\n%d",&room.no_of_people);
        printf("\n\tHow many days you want to leave : ");
        scanf("\n%d",&day);
        printf("\n\tMention your Arrival date [Day/Month/year] : ");
        scanf("\n%s",room.arrivaldate);
        printf("\n\tEnter your reference ID - Adharcard,identity card... : ");
        scanf("\n%s",room.reference_id);
        N = day*1500;
        push(N);
        
        printf("!!Amount paid successfully\n");
        printf("\n\tPress enter key to get wifi service or else press any key\n");
        ch = getch();
        if (ch == 13)
        {
            WIFI();
            printf("\n\tWifi plan successfully accessed\n");
        }
        else
        {   strcpy(room.wifi_plan,"No");
            printf("\n\tWifi access denied\n");
        }
    }

    room_book = fopen("ROOMBOOKINGS.txt", "a+");
    fprintf(room_book, "Time booking : %s\n",ctime(&t4));
    fprintf(room_book, "Name : %s\n",room.name);
    fprintf(room_book, "Email : %s\n",room.email);
    fprintf(room_book, "Wifi plan : %s\n",room.wifi_plan);
    fprintf(room_book, "Phone Number : %s\n",room.ph_no);
    fprintf(room_book, "Reference ID : %s\n",room.reference_id);
    fprintf(room_book, "Room number : %d\n",room.roomno);
    fprintf(room_book, "Floor number : %d\n",room.floor);
    fprintf(room_book, "Number of days to stay : %d\n",day);
    fprintf(room_book, "Number of members in %d room is %d\n",room.roomno,room.no_of_people);
    fprintf(room_book, "Arrival date : %s\n",room.arrivaldate);
    // fflush(room_book);
    fclose(room_book);
    printf("\n\tAll the content are loaded into the file successfully\n");
    Sleep(1000);
}


void BOOKROOM2()
{   system("cls");
    int floor;
    fflush(stdin);
    do
    {   system("cls");
        for (int i = 0; i < 90; i++)
            printf("-");
            printf("\n");
        printf("\t\tTypes of rooms \n");
        for (int i = 0; i < 90; i++)
            printf("-");
            printf("\n");
        printf("1.ONE BHK   -----   $700/day\n");
        printf("2.TWO BHK   -----   $900/day\n");
        printf("3.BUSINESS ROOM --- $1200/day\n");
        printf("4.DELUXE ROOM   --- $1500/day\n");
        printf("5.Back to Main menu !");
        printf("\n\nEnter your choice \n");
        scanf("%d", &floor);  
        if (floor < 1 || floor > 5)
        {
            printf("Enter valid input\n");
        }
    } while (floor < 1 || floor >5);

    switch (floor)
    {
    case 1:
        ONEBHK();
        break;
    case 2:
        TWOBHK();
        break;
    case 3:
        BUSINESSROOM();
        break;
    case 4:
        DELUXEROOM();
        break;
 
    case 5:
        BOOKROOM1();
        break;
    }
}

void ORDER_FOOD()
{
    FILE *fooditems;
    FILE *bill;
    char food[256];
    char buff[3000];
    int count;
    int ch;
    system("cls");
    printf("Press num 1 to move to the main menu, if you need or Else type any number! : ");
    scanf("%d",&ch);
    if(ch == 1){
        BOOKROOM1();
    }
    if (bill == NULL)
    {
        printf("The file cannot be opened\n");
    }
    if (fooditems == NULL)
    {
        printf("The file is loading...\n");
        Sleep(2000);
    }
    fflush(stdin);
    bill = fopen("BILL.txt", "a+");
    fooditems = fopen("FOOD_ITEMS.txt", "r");
    system("cls");
    printf("\n\nHow many items the customer needs : ");
    scanf("%d", &count);
    system("cls");
    for (int i = 0; i < count; i++)
    {
        while (!feof(fooditems))
        {   
            fgets(buff,3000, fooditems);
            printf("\n%s", buff);
            fflush(stdin);
        }

        printf("\nAll the recipes are $500\n");
        printf("Enter the recipe along with its rate!\n\n");
        gets(food);
        push(500);
        
        printf("Amount paid successfully\n");
        Sleep(2000);
        fprintf(bill, "\n* - %s", food);
        fflush(stdin);
    }
    fclose(bill);
    fclose(fooditems);
    printf("The contents are loaded into the BILL.txt successfullly\n");
    
}

void CHECK_AVAILABLE_ROOMS()
{
    system("cls");
    printf("Available Rooms Is displayed\n\n");
   
    for(int i=0;i<4;i++){
        for(int j=0;j<7;j++){
            printf("%d\t\t",space[i][j]);
        }
        printf("\n\n");
    }
    printf("\n\n");
    printf("Press enter to move to main Menu continue\n");
    getch();
}

void BOOKROOM1()
{
    FILE *room_book;    time_t gk;
    gk = time(NULL);
    int choice;
    system("cls");
    if (room_book == NULL)
    {
        printf("Loading files \n");
        
    }
    
    while (1)
    {   system("cls");
        printf("\t\tDATE\t:\t%s\n\n",ctime(&gk));
        for (int i = 0; i < 90; i++)
        printf("=");
        printf("\n");
        printf("\t\t\t\t\tMAIN  MENU");
        printf("\n");
        for (int i = 0; i<90;i++)
        printf("=");
        printf("\n");
        printf("----------------------------------------------\n");
        printf(" 1 . Room Bookings - $\n");
        printf("----------------------------------------------\n");
        printf(" 2 . Order Food & Bill print - $\n");
        printf("----------------------------------------------\n");
        printf(" 3 . List all the customer details \n");
        printf("----------------------------------------------\n");
        printf(" 4 . Check Vacant rooms\n");
        printf("----------------------------------------------\n");
        printf(" 5 . Add New Food/Dish in food menu\n");
        printf("----------------------------------------------\n");
        printf(" 6 . View the current Money statistics - $\n");
        printf("----------------------------------------------\n");
        printf(" 7 . EXIT\n");
        printf("----------------------------------------------\n");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            BOOKROOM2();
            break;

        case 2:
            ORDER_FOOD();
            break;

        case 3:
            DISPLAY();
            break;

        case 4:
            CHECK_AVAILABLE_ROOMS();
            break;

        case 5:
            ADD_FOOD_IN_MENU_LIST();
            break;

        case 6:
            MONEY_STATISTICS();
            break;

        case 7:
            break;

        default:
            printf("Enter any valid choice\n");
            getch();
        }
        if (choice == 7)
        {
            break;
        }
       
    }

    return;
}
