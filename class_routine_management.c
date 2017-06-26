#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <string.h>



int j,s;
char pass[20]="routine123";
char *days[]= {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday"};
char *teacher[]= {"MI","AR","SC","NS","SH","RPDN","FIA","FJ","RK","MAA","MKI","OR","MSH","MDA","MM","MNU","MIM","RK","JUA","RS","QI"};
char *ddays[]= {"Day 1","Day 2","Day 3"};
float times[]= {9.00,9.50,10.35,11.25,12.15,12.20,1.05,2.00,2.45,2.50,3.35,3.40,4.25};
char *sem1[]= {"CSE111","CSE112","CSE113","EEE121","EEE122","MATH131","PHY141","PHY142","CHEM161"};
char *sem2[]= {"CSE211","CSE212","EEE221","EEE222","PHY241","PHY242","MATH231","STAT251","STAT252","ENG271"};
char *sem3[]= {"CSE300","CSE311","CSE312","CSE313","CSE314","EEE321","EEE322","MATH331"};
char *sem4[]= {"CSE400","CSE411","CSE412","CSE413","CSE414","CSE415","CSE416","MATH 431","STAT 451"};
char *sem5[]= {"CSE500","CSE511","CSE512","CSE513","CSE514","CSE515","CSE516","CSE517","ECON 581","ACC0 591"};
char *sem6[]= {"CSE600","CSE611","CSE612","CSE613","CSE614","CSE615","CSE616","CSE617","EEE621","EEE622"};
char *sem7[]= {"CSE700","CSE711","CSE712","CSE713","CSE714","CSE715","CSE716","CSE717","CSE718"};
char *sem8[]= {"CSE800","CSE811","CSE812",
               "CSE813","CSE814","CSE815","CSE816","CSE817"
              };

char *filename;

struct data
{
    char *day;
    char *course;
    int day_no;
    float start;
    float finish;
    char year[20];
    char teacher[20];
    int teach_index;
    float time1;
    float time2;
    float time3;
    float time4;
    float time5;
    float time6;
    float time7;
    float time8;
    float time9;
    float time10;
    float time11;
    float time12;
    float time13;

};
struct data a,temp;

void cover();
void user();
void password();
void mainmenu();
void student_mainmenu();
void select_semester(int n);
int getdata(FILE *x,int y_axis);
int check_assign(FILE *x);
void viewroutine(FILE *x,int n);
void department_teacher(FILE *x);
void department(FILE *x);
void day_list(int y_axis);
void erase_day(int y_axis);
void course_1st(int x_axis,int y_axis);
void course_2nd(int x_axis,int y_axis);
void course_3rd(int x_axis,int y_axis);
void course_4th(int x_axis,int y_axis);
void course_5th(int x_axis,int y_axis);
void course_6th(int x_axis,int y_axis);
void course_7th(int x_axis,int y_axis);
void course_8th(int x_axis,int y_axis);
void del_routine(FILE *x);
void returnfunc(int n);
void list_view(FILE *x);
void grid_view(FILE *x);
void time_list(int y_axis);
void teacher_dept();
void teacher_list(int n);
void course_select(int n);
void save_file(FILE *x);
void guest_teacher();
void day_select(FILE *x);

COORD coord = {0, 0};
void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int main()
{
    cover();
    user();
}

void cover()
{
    int i;
    char* title,*name1,*name2,*name3,*name4;
    system("cls");

    for(i=0; i<16; i++)
    {
        gotoxy(10,6+i);
        printf("\xB2");
    }
    for(i=0; i<65; i++)
    {
        gotoxy(10+i,21);
        printf("\xDB");
    }
    for(i=0; i<16; i++)
    {
        gotoxy(74,21-i);
        printf("\xB2");
    }
    for(i=0; i<65; i++)
    {
        gotoxy(74-i,6);
        printf("\xDB");
    }
    gotoxy(20,9);
    for(i=0; i<43; i++)
    {
        if(i%2) printf("*");
        else printf("~");
    }
    title="A Program For Class Routine Management System";
    name1="Prepared By - 1.Shreya Khisa (ID:13701066)";
    name2= "           2.Shuva Dey (ID:13701063)";
    name3= "           3.Joyeta Sharma(ID:13701089)";
    name4= "           4.Sunanda Guha(ID:13701052)";

    gotoxy(26,11);
    i=0;
    while(title[i]!='\0')
    {
        printf("%c",*(title+i));
        i++;
    }

    gotoxy(29,13);
    i=0;
    while(name1[i]!='\0')
    {
        printf("%c",name1[i]);
        i++;
    }

    gotoxy(32,14);
    i=0;
    while(name2[i]!='\0')
    {
        printf("%c",name2[i]);
        i++;
    }

    gotoxy(32,15);
    i=0;
    while(name3[i]!='\0')
    {
        printf("%c",name3[i]);
        i++;
    }

    gotoxy(32,16);
    i=0;
    while(name4[i]!='\0')
    {
        printf("%c",name4[i]);
        i++;
    }
    gotoxy(20,18);
    for(i=0; i<43; i++)
    {
        if(i%2) printf("*");
        else printf("~");
    }

    delay(2000);

}

void user()
{
    char *name,*i1,*i3,*i5,*i6,*j2,*j4,*j6,*user1,*user2,*option;
    int n,i;

    i1=   "|---------------------------------------------------------------|\n ";
    name= "|                     Select A User                             |\n ";
    j2=   "|---------------------------------------------------------------|\n";

    i3=   "|---------------------------------------------------------------|\n ";
    user1="|                  1. ADMINISTRATOR                             |\n ";
    j4=  "|---------------------------------------------------------------|\n";

    i5   ="|---------------------------------------------------------------|\n ";
    user2="|                  2. STUDENT                                   |\n ";
    j6 =  "|---------------------------------------------------------------|\n";

    system("cls");
    gotoxy(20,2);
    i=0;
    while(i1[i]!='\0')
    {
        printf("%c",*(i1+i));
        i++;
    }

    gotoxy(20,4);
    i=0;
    while(name[i]!='\0')
    {
        printf("%c",*(name+i));
        i++;
    }

    gotoxy(20,6);
    i=0;
    while(j2[i]!='\0')
    {
        printf("%c",*(j2+i));
        i++;
    }

    gotoxy(20,8);
    i=0;
    while(i3[i]!='\0')
    {
        printf("%c",*(i3+i));
        i++;
    }

    gotoxy(20,10);
    i=0;
    while(user1[i]!='\0')
    {
        printf("%c",*(user1+i));
        i++;
    }

    gotoxy(20,12);
    i=0;
    while(j4[i]!='\0')
    {
        printf("%c",*(j4+i));
        i++;
    }

    gotoxy(20,14);
    i=0;
    while(i5[i]!='\0')
    {
        printf("%c",*(i5+i));
        i++;
    }

    gotoxy(20,16);
    i=0;
    while(user2[i]!='\0')
    {
        printf("%c",*(user2+i));
        i++;
    }

    gotoxy(20,18);
    i=0;
    while(i5[i]!='\0')
    {
        printf("%c",*(i5+i));
        i++;
    }

    printf("\n\n");
    printf("Enter your choice: ");
    scanf("%d",&s);
    switch(s)
    {
    case 1:
        password();
        break;
    case 2:
        student_mainmenu();
        break;
    case 3:
    {
        system("cls");
        gotoxy(10,17);
        printf("Exiting in 3 second...........>");
        delay(3000);
        exit(0);
    }
    break;
    default:
    {
        gotoxy(10,23);
        printf("\aWrong Entry!!Please re-enter correct option.Press any key...then enter your choice.");
        if(getch())
            user();
    }
    }
}

void password()
{
    system("cls");
    char d[25]="Password Protected";
    char ch,pass_1[10];
    int i=0,j;
    gotoxy(15,7);
    printf("Enter Password:");

    while(ch!=13)
    {
        ch=getch();
        if(ch!=13 && ch!=8)
        {
            putch('*');
            pass_1[i] = ch;
            i++;
        }
    }
    pass_1[i] = '\0';
    if(strcmp(pass_1,pass)==0)
    {
        gotoxy(15,9);
        printf("Password match");
        gotoxy(17,10);
        printf("Press any key to countinue.....");
        getch();
        mainmenu();
    }
    else
    {
        gotoxy(15,16);
        printf("\aWarning!! Incorrect Password");
        getch();
        password();
    }
}

void student_mainmenu()
{
    int i;
    char *menu,*view,*course,*teacher,*close,*user_select;

    menu=" MAIN MENU ";
    view="1.VIEW ROUTINE";
    teacher="2.VIEW TEACHERS NAME & DESIGNATION";
    course="3.SYLLABUS FOR ALL SEMESTER ";
    user_select="4.GO TO USER SELECTION";
    close="5.CLOSE APPLICATION";

    system("cls");
    for(i=0; i<29; i++)
    {
        gotoxy(13+i,5);
        printf("\xB2");
    }

    gotoxy(23,5);
    i=0;
    while(menu[i]!='\0')
    {
        printf("%c",menu[i]);
        i++;
    }

    for(i=0; i<9; i++)
    {
        gotoxy(13+i,7);
        printf("\xB2");
    }
    gotoxy(22,7);
    printf("\xDB");

    gotoxy(25,7);
    i=0;
    while(view[i]!='\0')
    {
        printf("%c",view[i]);
        i++;
    }

    for(i=0; i<9; i++)
    {
        gotoxy(13+i,9);
        printf("\xB2");
    }

    gotoxy(22,9);
    printf("\xDB");
    gotoxy(25,9);
    i=0;
    while(teacher[i]!='\0')
    {
        printf("%c",teacher[i]);
        i++;
    }
    for(i=0; i<9; i++)
    {
        gotoxy(13+i,11);
        printf("\xB2");
    }
    gotoxy(22,11);
    printf("\xDB");
    gotoxy(25,11);
    i=0;
    while(course[i]!='\0')
    {
        printf("%c",course[i]);
        i++;
    }
    for(i=0; i<9; i++)
    {
        gotoxy(13+i,13);
        printf("\xB2");
    }
    gotoxy(22,13);
    printf("\xDB");
    gotoxy(25,13);
    i=0;
    while(user_select[i]!='\0')
    {
        printf("%c",user_select[i]);
        i++;
    }

    for(i=0; i<9; i++)
    {
        gotoxy(13+i,15);
        printf("\xB2");
    }
    gotoxy(22,15);
    printf("\xDB");
    gotoxy(25,15);
    i=0;
    while(close[i]!='\0')
    {
        printf("%c",close[i]);
        i++;
    }

    printf("\n\n\n");
    printf("Enter your choice:");
    switch(getch())
    {
    case '1':
        select_semester(4);
        break;
    case '2':
        teacher_list(2);
        break;
    case '3':
        course_select(2);
        break;
    case '4':
        user();
        break;
    case '5':
    {
        system("cls");
        gotoxy(10,17);
        printf("Exiting in 3 second...........>");
        delay(3000);
        exit(0);
    }
    break;
    default:
    {
        gotoxy(30,23);
        printf("\aWrong Entry!!Please re-enter correct option.Press any key...then enter your choice.");
        if(getch())
            mainmenu();
    }
    }
}

void mainmenu()
{
    int i;
    char *menu,*add,*week,*sub,*close,*teacher,*syllabus,*user_select;

    menu="MAIN MENU";
    add="1.ADD ROUTINE";
    week="2.VIEW ROUTINE";
    sub="3.DELETE ROUTINE";
    teacher="4.VIEW TEACHERS NAME & DESIGNATION";
    syllabus="5.SYLLABUS FOR ALL SEMESTER ";
    user_select="6.GO TO USER SELECTION";
    close="7.CLOSE APPLICATION";

    system("cls");
    for(i=0; i<29; i++)
    {
        gotoxy(13+i,5);
        printf("\xB2");
    }

    gotoxy(23,5);
    i=0;
    while(menu[i]!='\0')
    {
        printf("%c",menu[i]);
        i++;
    }

    for(i=0; i<9; i++)
    {
        gotoxy(13+i,7);
        printf("\xB2");
    }
    gotoxy(22,7);
    printf("\xDB");
    gotoxy(25,7);
    i=0;
    while(add[i]!='\0')
    {
        printf("%c",add[i]);
        i++;
    }

    for(i=0; i<9; i++)
    {
        gotoxy(13+i,9);
        printf("\xB2");
    }
    gotoxy(22,9);
    printf("\xDB");
    gotoxy(25,9);
    i=0;
    while(week[i]!='\0')
    {
        printf("%c",week[i]);
        i++;
    }

    for(i=0; i<9; i++)
    {
        gotoxy(13+i,11);
        printf("\xB2");
    }
    gotoxy(22,11);
    printf("\xDB");
    gotoxy(25,11);
    i=0;
    while(sub[i]!='\0')
    {
        printf("%c",sub[i]);
        i++;
    }
    for(i=0; i<9; i++)
    {
        gotoxy(13+i,13);
        printf("\xB2");
    }
    gotoxy(22,13);
    printf("\xDB");
    gotoxy(25,13);
    i=0;
    while(teacher[i]!='\0')
    {
        printf("%c",teacher[i]);
        i++;
    }
    for(i=0; i<9; i++)
    {
        gotoxy(13+i,15);
        printf("\xB2");
    }
    gotoxy(22,15);
    printf("\xDB");
    gotoxy(25,15);
    i=0;
    while(syllabus[i]!='\0')
    {
        printf("%c",syllabus[i]);
        i++;
    }

    for(i=0; i<9; i++)
    {

        gotoxy(13+i,17);
        printf("\xB2");
    }
    gotoxy(22,17);
    printf("\xDB");
    gotoxy(25,17);
    i=0;
    while(user_select[i]!='\0')
    {
        printf("%c",user_select[i]);
        i++;
    }

    for(i=0; i<9; i++)
    {

        gotoxy(13+i,19);
        printf("\xB2");
    }
    gotoxy(22,19);
    printf("\xDB");
    gotoxy(25,19);
    i=0;
    while(close[i]!='\0')
    {
        printf("%c",close[i]);
        i++;
    }
    printf("\n\n\n");
    printf("Enter your choice:");
    scanf("%d",&s);
    switch(s)
    {
    case 1:
        select_semester(s);
        break;
    case 2:
        select_semester(s);
        break;
    case 3:
        select_semester(s);
        break;
    case 4:
        teacher_list(1);
        break;
    case 5:
        course_select(1);
        break;
    case 6:
        user();
        break;
    case 7:
    {
        system("cls");
        gotoxy(10,17);
        printf("Exiting in 3 second...........>");

        delay(3000);
        exit(0);
    }
    break;
    default:
    {
        gotoxy(30,23);
        printf("\aWrong Entry!!Please re-enter correct option.Press any key...then enter your choice.");
        if(getch())
            mainmenu();
    }
    }
}

void day_select(FILE *x)
{
    FILE *fp;
    system("cls");
    gotoxy(15,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2 GIVE TIME FOR EACH DAY");
    gotoxy(15,7);
    printf("\xB2\xB2\xB2\xB2 1.Day 1");
    gotoxy(15,9);
    printf("\xB2\xB2\xB2\xB2 2.Day 2");
    gotoxy(15,11);
    printf("\xB2\xb2\xB2\xB2 3.Day 3");
    gotoxy(15,13);
    printf("\xB2\xb2\xB2\xB2 4.Main menu");
    printf("\n\n\n\t\tEnter your selection:");
    scanf("%d",&s);
    temp.day_no=s-1;

    if(s==4)
        mainmenu();
    system("cls");
    if((getdata(x,3)==1&&check_assign(x)==1))
    {
        fp=fopen(filename,"ab+");
        fseek(fp,0,SEEK_END);
        fwrite(&a,1,sizeof(a),fp);
        fclose(fp);
        if(getch())
        {
            system("cls");
            gotoxy(15,8);
            printf("The day and time is sucessfully saved");
        }
        gotoxy(15,9);
        printf("Save another time for another day for same course?(y/ n):");
        if(getch()=='n')
            mainmenu();
        else
            day_select(x);
        fclose(x);

    }

}


void department_teacher(FILE *x)
{
    system("cls");
    gotoxy(15,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 For Whom Do you want to set your routine?");
    gotoxy(20,5);
    printf("GUEST TEACHERS");
    gotoxy(10,7);
    printf( "\xDB\xDB\xDB\xDB\xDB\xB2  14.Mohammad Didarul Alam (MDA)");
    gotoxy(10,9);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2   15.Mohammad Mohsin (MM)");
    gotoxy(10,11);
    printf( "\xDB\xDB\xDB\xDB\xDB\xB2 16.Mohammad Nasir Uddin (MNU)");
    gotoxy(10,13);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 17.Mohammad Idris Mia(MIM)");
    gotoxy(10,15);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2  18.Rejaul Karim(RK)");
    gotoxy(10,17);
    printf( "\xDB\xDB\xDB\xDB\xDB\xB2  19.Jamal Uddin Ahmed(JUA)");
    gotoxy(10,19);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2  20.Rabindranath Shil(RS)");
    gotoxy(10,21);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2  21.Quamrul Islam(QI)");
    gotoxy(70,5);
    printf("CSE DEPARTMENT TEACHERS");
    gotoxy(65,7);
    printf( "\xDB\xDB\xDB\xDB\xDB\xB2 1.Mr.Mahbubul Islam(MI)");
    gotoxy(65,9);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 2.Mr.Atiqur Rahman(AR)");
    gotoxy(65,11);
    printf( "\xDB\xDB\xDB\xDB\xDB\xB2 3.Ms.Shima Chakraborty(SC)");
    gotoxy(65,13);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 4.Ms.Nasrin Sultana(NS)");
    gotoxy(65,15);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 5.Mr.Sajedul Hoque(SH)");
    gotoxy(65,17);
    printf( "\xDB\xDB\xDB\xDB\xDB\xB2 6.Mr.Rudra Pratap Deb nath(RPDN)");
    gotoxy(65,19);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 7.Mr.Fahim Irfan Alam(FIA)");
    gotoxy(65,21);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 8.Mrs.Farah Jahan(FJ)");
    gotoxy(65,23);
    printf( "\xDB\xDB\xDB\xDB\xDB\xB2 9.Mr.MD.Rezaul Karim(RK)");
    gotoxy(65,25);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 10.Mr.Mohammad Anowarul Azim(MAA)");
    gotoxy(65,27);
    printf( "\xDB\xDB\xDB\xDB\xDB\xB2 11.Mr.Dr.Mohammad Khairul Islam(MKI)");
    gotoxy(65,29);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 12.Mr.Dr.Osiur Rahman(OR)");
    gotoxy(65,31);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 13.Mr.Dr.Mohammad Sahadat Hossain(MSH)");
    gotoxy(65,33);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 22.Main menu");
    gotoxy(25,36);
    printf("Enter your choice: ");
    scanf("%d",&s);
    temp.teach_index=s-1;
    switch(s)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
        day_select(x);
        fclose(x);
        break;
    case 22:
        mainmenu();
        break;
    }
}

int getdata(FILE *x,int y_axis)
{
    int i;
    gotoxy(10,y_axis);
    printf("Enter the information as number");
    gotoxy(10,y_axis+1);
    printf("Like:if you want to select Saturday then enter 1");
    gotoxy(10,y_axis+2);
    printf("This instruction is for entering all info");
    gotoxy(10,y_axis+3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    for(i=3; i<16; i++)
    {
        gotoxy(10,y_axis+i);
        printf("\xB2");
        gotoxy(48,y_axis+i);
        printf("\xB2");
    }
    gotoxy(10,y_axis+15);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(12,y_axis+6);
    printf("Semester: %s",temp.year);
    gotoxy(12,y_axis+8);
    printf("Course title & no:");
    if(filename=="1st semester.dat")
    {
        course_1st(60,y_axis);
        gotoxy(30,y_axis+8);
        scanf("%d",&s);
        temp.course=sem1[s-1];
        gotoxy(30,y_axis+8);
        printf("%s",temp.course);
        erase_day(y_axis);
    }
    else if(filename=="2nd semester.dat")
    {
        course_2nd(60,y_axis);
        gotoxy(30,y_axis+8);
        scanf("%d",&s);
        temp.course=sem2[s-1];
        gotoxy(30,y_axis+8);
        printf("%s",temp.course);
        erase_day(y_axis);
    }
    else if(filename=="3rd semester.dat")
    {
        course_3rd(60,y_axis);
        gotoxy(30,y_axis+8);
        scanf("%d",&s);
        temp.course=sem3[s-1];
        gotoxy(30,y_axis+8);
        printf("%s",temp.course);
        erase_day(y_axis);
    }

    else if(filename=="4th semester.dat")
    {
        course_4th(60,y_axis);
        gotoxy(30,y_axis+8);
        scanf("%d",&s);
        temp.course=sem4[s-1];
        gotoxy(30,y_axis+8);
        printf("%s",temp.course);
        erase_day(y_axis);
    }

    else if(filename=="5th semester.dat")
    {
        course_5th(60,y_axis);
        gotoxy(30,y_axis+8);
        scanf("%d",&s);
        temp.course=sem5[s-1];
        gotoxy(30,y_axis+8);
        printf("%s",temp.course);
        erase_day(y_axis);
    }
    else if(filename=="6th semester.dat")
    {
        course_6th(60,y_axis);
        gotoxy(30,y_axis+8);
        scanf("%d",&s);
        temp.course=sem6[s-1];
        gotoxy(30,y_axis+8);
        printf("%s",temp.course);
        erase_day(y_axis);
    }
    else if(filename=="7th semester.dat")
    {
        course_7th(60,y_axis);
        gotoxy(30,y_axis+8);
        scanf("%d",&s);
        temp.course=sem7[s-1];
        gotoxy(30,y_axis+8);
        printf("%s",temp.course);
        erase_day(y_axis);
    }

    else if(filename=="8th semester.dat")
    {
        course_8th(60,y_axis);
        gotoxy(30,y_axis+8);
        scanf("%d",&s);
        temp.course=sem8[s-1];
        gotoxy(30,y_axis+8);
        printf("%s",temp.course);
        erase_day(y_axis);
    }
    gotoxy(12,y_axis+10);
    printf("Day:");
    day_list(y_axis);
    gotoxy(17,y_axis+10);
    scanf("%d",&s);
    temp.day=days[s-1];
    gotoxy(17,y_axis+10);
    printf("%s",temp.day);
    erase_day(y_axis);
    gotoxy(12,y_axis+12);
    printf("Start Time: ");
    time_list(y_axis);
    gotoxy(23,y_axis+12);
    scanf("%d",&s);
    temp.start=times[s-1];
    gotoxy(23,y_axis+12);
    printf("%.2f",temp.start);
    gotoxy(12,y_axis+14);
    printf("End Time: ");
    gotoxy(23,y_axis+14);
    scanf("%d",&s);
    temp.finish=times[s-1];
    gotoxy(23,y_axis+14);
    printf("%.2f",temp.finish);
    erase_day(y_axis);
    return 1;

}



int check_assign(FILE *x)
{
    rewind(x);
    while(fread(&a,sizeof(a),1,x)==1)
    {
        if((a.day==temp.day)&& (((a.start<=temp.start)&&(a.finish>temp.start))||((a.start<=temp.finish)&&(a.finish>=temp.finish))))
        {
            gotoxy(15,21);
            printf("Sorry!This time is occupied by %s taking %s class.",teacher[a.teach_index],a.course);
            getch();
            if(temp.teach_index>a.teach_index)
            {
                a.day=temp.day;
                a.start=temp.start;
                a.finish=temp.finish;
                a.course=temp.course;
                strcpy(a.teacher,temp.teacher);
                a.teach_index=temp.teach_index;
                fseek(x,ftell(x)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,x);
                fclose(x);
                gotoxy(15,23);
                printf("But you will get that time because of your senoirity.");
                gotoxy(20,25);
                printf("Do you want to save another time & day for same course(y/n)?");
                if(getch()=='y')
                    day_select(x);
                if(getch()=='n');
                mainmenu();

            }
            else if(temp.teach_index==a.teach_index)
            {
                a.day=temp.day;
                a.course=temp.course;
                a.start=temp.start;
                a.finish=temp.finish;
                strcpy(a.teacher,temp.teacher);
                a.teach_index=temp.teach_index;
                fseek(x,ftell(x)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,x);
                fclose(x);
                gotoxy(15,23);
                printf("That is,you have already taken %s course on this time.",a.course);
                gotoxy(15,25);
                printf("Do you want to save another day for this course?(y/n)");
                if(getch()=='y')
                    day_select(x);                     //select_semester(1);
                if(getch()=='n')
                    mainmenu();
                else
                    gotoxy(20,27);
                printf("Wrong entry!!");
            }

            else
            {
                gotoxy(16,25);
                printf("You can not take that class.");
                gotoxy(16,27);
                printf("You want to add class in another time?(y/n)");
                if(getch()=='n')
                    mainmenu();
                else
                {
                    system("cls");
                    day_select(x);
                }
            }
        }
    }


    a.day=temp.day;
    a.start=temp.start;
    a.finish=temp.finish;
    a.course=temp.course;
    strcpy(a.teacher,temp.teacher);
    a.teach_index=temp.teach_index;
    fclose(x);

    return 1;
}

void day_list( int y_axis)
{
    char *title,*select,*sat,*sun,*mon,*tue,*wed,*thu;
    title="ENTER THE NUMBER BESIDE THE DAY";
    select="\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT A DAY\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    sat="\xDB\xDB\xDB\xDB\xDB\xB2 1.Saturday";
    sun="\xDB\xDB\xDB\xDB\xDB\xB2 2.Sunday";
    mon="\xDB\xDB\xDB\xDB\xDB\xB2 3.Monday";
    tue="\xDB\xDB\xDB\xDB\xDB\xB2 4.Tuesday";
    wed="\xDB\xDB\xDB\xDB\xDB\xB2 5.Wednesday";
    thu="\xDB\xDB\xDB\xDB\xDB\xB2 6.Thursday";
    int i=0;
    gotoxy(58,y_axis);
    while(title[i]!='\0')
    {
        printf("%c",title[i]);
        i++;
    }
    i=0;
    gotoxy(58,y_axis+2);
    while(select[i]!='\0')
    {
        printf("%c",select[i]);
        i++;
    }
    i=0;
    gotoxy(58,y_axis+4);
    while(sat[i]!='\0')
    {
        printf("%c",sat[i]);
        i++;
    }
    i=0;
    gotoxy(58,y_axis+6);
    while(sun[i]!='\0')
    {
        printf("%c",sun[i]);
        i++;
    }
    i=0;
    gotoxy(58,y_axis+8);
    while(mon[i]!='\0')
    {
        printf("%c",mon[i]);
        i++;
    }
    i=0;
    gotoxy(58,y_axis+10);
    while(tue[i]!='\0')
    {
        printf("%c",tue[i]);
        i++;
    }
    i=0;
    gotoxy(58,y_axis+12);
    while(wed[i]!='\0')
    {
        printf("%c",wed[i]);
        i++;
    }
    i=0;
    gotoxy(58,y_axis+14);
    while(thu[i]!='\0')
    {
        printf("%c",thu [i]);
        i++;
    }
    i=0;

}

void erase_day(int y_axis)
{
    int j,k;

    for( j=y_axis; j<(y_axis+30); j++)
    {
        for(k=58; k<=150; k++)
        {
            gotoxy(k,j);
            printf(" ");
        }
    }

}

void course_1st(int x_axis,int y_axis)
{
    char *title,*compu,*compulab,*dm,*eee,*eeel,*math,*phy,*phyl,*ch;
    int i;
    title="1ST SEMESTER COURSE TITLE & COURSE NO:";
    compu="\xDB\xDB\xDB\xDB\xDB\xB2 1.CSE 111:INTRODUCTION TO COMPUTER SYSTEMS";
    compulab="\xDB\xDB\xDB\xDB\xDB\xB2 2.CSE 112:INTRODUCTION TO COMPUTER SYSTEMS LAB";
    dm="\xDB\xDB\xDB\xDB\xDB\xB2 3.CSE 113:DISCRETE MATHEMATICS";
    eee="\xDB\xDB\xDB\xDB\xDB\xB2 4.EEE 121:INTRODUCTION TO ELECTRICAL ENGINEERING";
    eeel="\xDB\xDB\xDB\xDB\xDB\xB2 5.EEE 122:INTRODUCTION TO ELECTRICAL ENGINEERING LAB";
    math="\xDB\xDB\xDB\xDB\xDB\xB2 6.MATH 131:MATRICES,VECTOR ANALYSES AND GEOMETRY";
    phy="\xDB\xDB\xDB\xDB\xDB\xB2 7.PHY 141:HEAT AND THERMODYNAMICS,STRUCTURE OF MATTER,WAVES AND OSCILLATIONS";
    phyl="\xDB\xDB\xDB\xDB\xDB\xB2 8.PHY 142:HEAT AND THERMODYNAMICS,STRUCTURE OF MATTER,WAVES AND OSCILLATIONS LAB";
    ch="\xDB\xDB\xDB\xDB\xDB\xB2 9.CHEM 161:CHEMISTRY";

    gotoxy(x_axis,y_axis);
    i=0;
    while(title[i]!='\0')
    {
        printf("%c",title[i]);
        i++;
    }

    gotoxy(x_axis,y_axis+1);
    printf("------------------------------------------------------");

    gotoxy(x_axis,y_axis+3);
    i=0;
    while(compu[i]!='\0')
    {
        printf("%c",compu[i]);
        i++;
    }

    gotoxy(x_axis,y_axis+5);
    i=0;
    while(compulab[i]!='\0')
    {
        printf("%c",compulab[i]);
        i++;
    }

    gotoxy(x_axis,y_axis+7);
    i=0;
    while(dm[i]!='\0')
    {
        printf("%c",dm[i]);
        i++;
    }

    gotoxy(x_axis,y_axis+9);
    i=0;
    while(eee[i]!='\0')
    {
        printf("%c",eee[i]);
        i++;
    }

    gotoxy(x_axis,y_axis+11);
    i=0;
    while(eeel[i]!='\0')
    {
        printf("%c",eeel[i]);
        i++;
    }

    gotoxy(x_axis,y_axis+13);
    i=0;
    while(math[i]!='\0')
    {
        printf("%c",math[i]);
        i++;
    }

    gotoxy(x_axis,y_axis+15);
    i=0;
    while(phy[i]!='\0')
    {
        printf("%c",phy[i]);
        i++;
    }

    gotoxy(x_axis,y_axis+17);
    i=0;
    while(phyl[i]!='\0')
    {
        printf("%c",phyl[i]);
        i++;
    }

    gotoxy(x_axis,y_axis+19);
    i=0;
    while(ch[i]!='\0')
    {
        printf("%c",ch[i]);
        i++;
    }
    i=0;
}

void course_2nd(int x_axis,int y_axis)
{
    char *title,*sp,*splab,*elec,*eleclab,*phy,*phylab,*math,*stat,*statlab,*eng;
    int i;
    title="2ND SEMESTER COURSE TITLE & COURSE NO:";
    sp="\xDB\xDB\xDB\xDB\xDB\xB2 1.CSE 211:STRUCTURED PROGRAMMING LANGUAGE ";
    splab="\xDB\xDB\xDB\xDB\xDB\xB2 2.CSE 212:STRUCTURED PROGRAMMING LANGUAGE LAB";
    elec="\xDB\xDB\xDB\xDB\xDB\xB2 3.EEE 221:BASIC ELECTRONICS DEVICES & CIRCUITS";
    eleclab="\xDB\xDB\xDB\xDB\xDB\xB2 4.EEE 222:BASIC ELECTRONICS DEVICES & CIRCUITS LAB";
    phy="\xDB\xDB\xDB\xDB\xDB\xB2 5.PHY 241:ELECTROMAGNETISM,OPTICS & MODERN PHYSICS";
    phylab="\xDB\xDB\xDB\xDB\xDB\xB2 6.PHY 242:ELECTROMAGNETISM,OPTICS & MODERN PHYSICS LAB";
    math="\xDB\xDB\xDB\xDB\xDB\xB2 7.MATH 231:CALCULAS & DIFFERENTIAL EQUATIONS";
    stat="\xDB\xDB\xDB\xDB\xDB\xB2 8.STAT 251:BASIC STATISTICS";
    statlab="\xDB\xDB\xDB\xDB\xDB\xB2 9.STAT 251:BASIC STATISTICS LAB";
    eng="\xDB\xDB\xDB\xDB\xDB\xB2 10.ENG 271:ENGLISH";

    gotoxy(x_axis,y_axis);
    i=0;
    while(title[i]!='\0')
    {
        printf("%c",title[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+1);
    printf("------------------------------------------------------");
    gotoxy(x_axis,y_axis+3);
    i=0;
    while(sp[i]!='\0')
    {
        printf("%c",sp[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+5);
    i=0;
    while(splab[i]!='\0')
    {
        printf("%c",splab[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+7);
    i=0;
    while(elec[i]!='\0')
    {
        printf("%c",elec[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+9);
    i=0;
    while(eleclab[i]!='\0')
    {
        printf("%c",eleclab[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+11);
    i=0;
    while(phy[i]!='\0')
    {
        printf("%c",phy[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+13);
    i=0;
    while(phylab[i]!='\0')
    {
        printf("%c",phylab[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+15);
    i=0;
    while(math[i]!='\0')
    {
        printf("%c",math[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+17);
    i=0;
    while(stat[i]!='\0')
    {
        printf("%c",stat[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+19);
    i=0;
    while(statlab[i]!='\0')
    {
        printf("%c",statlab[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+21);
    i=0;
    while(eng[i]!='\0')
    {
        printf("%c",eng[i]);
        i++;
    }
    i=0;
}

void course_3rd(int x_axis,int y_axis)
{
    char *title,*pro,*ds,*dslab,*oop,*ooplab,*dld,*dldlab,*math;
    int i;
    title="3RD SEMESTER COURSE TITLE & COURSE NO:";
    pro="\xDB\xDB\xDB\xDB\xDB\xB2 1.CSE 300:PROJECT BASED ON C LANGUAGE";
    ds="\xDB\xDB\xDB\xDB\xDB\xB2 2.CSE 311:DATA STRUCTURE";
    dslab="\xDB\xDB\xDB\xDB\xDB\xB2 3.CSE 312:DATA STRUCTURE LAB";
    oop="\xDB\xDB\xDB\xDB\xDB\xB2 4.CSE 313:OBJECT-ORIENTED PROGRAMMING LANGUAGE";
    ooplab="\xDB\xDB\xDB\xDB\xDB\xB2 5.CSE 314:OBJECT-ORIENTED PROGRAMMING LANGUAGE LAB";
    dld="\xDB\xDB\xDB\xDB\xDB\xB2 6.EEE 321:DIGITAL LOGIC DESIGN";
    dldlab="\xDB\xDB\xDB\xDB\xDB\xB2 7.EEE 322:DIGITAL LOGIC DESIGN LAB";
    math="\xDB\xDB\xDB\xDB\xDB\xB2 8.MATH 331:COMPLEX VARIABLE,LAPLACE AND FOURIER TRANSFORMATION";

    gotoxy(x_axis,y_axis);
    i=0;
    while(title[i]!='\0')
    {
        printf("%c",title[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+1);
    printf("------------------------------------------------------");

    gotoxy(x_axis,y_axis+2);
    i=0;
    while(pro[i]!='\0')
    {
        printf("%c",pro[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+4);
    i=0;
    while(ds[i]!='\0')
    {
        printf("%c",ds[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+6);
    i=0;
    while(dslab[i]!='\0')
    {
        printf("%c",dslab[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+8);
    i=0;
    while(oop[i]!='\0')
    {
        printf("%c",oop[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+10);
    i=0;
    while(ooplab[i]!='\0')
    {
        printf("%c",ooplab[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+12);
    i=0;
    while(dld[i]!='\0')
    {
        printf("%c",dld[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+14);
    i=0;
    while(dldlab[i]!='\0')
    {
        printf("%c",dldlab[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+16);
    i=0;
    while(math[i]!='\0')
    {
        printf("%c",math[i]);
        i++;
    }
    i=0;
}

void returnfunc(int n)
{
    if(n==1)
    {
        {
            gotoxy(70,01);
            printf("Press ENTER to return to mainmenu");
        }
a:
        if(getch()==13)
            mainmenu();
        else
            goto a;
    }

    else if(n==2)
    {
        gotoxy(70,01);
        printf("Press ENTER to return to mainmenu");

b:
        if(getch()==13)
            student_mainmenu();
        else
            goto b;
    }
}

void viewroutine(FILE *x,int n)
{
    system("cls");
    gotoxy(15,5);
    printf("\xB2\xB2\xB2\xB2 HOW DO YOU WANT TO SEE YOUR ROUTINE?\xB2\xB2\xB2\xB2");
    gotoxy(15,7);
    printf("\xB2\xB2\xB2\xB2\xB2 1.LIST VIEW");
    gotoxy(15,9);
    printf("\xB2\xB2\xB2\xB2\xB2 2.GRID VIEW");
    gotoxy(15,11);
    printf("\xB2\xB2\xB2\xB2\xB2 3.MAIN MENU");
    if(n==1)
    {
        gotoxy(15,15);
        printf("\xB2\xB2\xB2\xB2\xB2 YOUR CHOICE: ");
        scanf("%d",&s);
        switch(s)
        {
        case 1:
            list_view(x);
            fclose(x);
            returnfunc(1);
            break;
        case 2:
            grid_view(x);
            fclose(x);
            returnfunc(1);
            break;
        case 3:
            mainmenu();
            break;
        default:
        {
            gotoxy(30,23);
            printf("\aWrong Entry!!Please re-enter correct option.Press any key...then enter your choice.");
            if(getch())
                viewroutine(x,1);
            fclose(x);
        }

        }
        fclose(x);
    }
    if(n==2)
    {
        gotoxy(15,15);
        printf("\xB2\xB2\xB2\xB2\xB2 YOUR CHOICE: ");
        scanf("%d",&s);
        switch(s)
        {
        case 1:
            list_view(x);
            fclose(x);
            returnfunc(2);
            break;
        case 2:
            grid_view(x);
            fclose(x);
            returnfunc(2);

            break;
        case 3:
            student_mainmenu();
            break;
        default:
        {
            gotoxy(30,23);
            printf("\aWrong Entry!!Please re-enter correct option.Press any key...then enter your choice.");
            if(getch())
                viewroutine(x,2);
            fclose(x);
        }

        }
        fclose(x);
    }

}

void list_view(FILE *x)
{
    system("cls");
    gotoxy(1,1);
    printf("******************************** ROUTINE ************************************");
    gotoxy(2,2);
    printf("SEMESTER     DAY    START TIME    END TIME      COURSE CODE      TEACHER ");
    j=4;


    while(fread(&a,sizeof(a),1,x)==1)
    {
        strcpy(a.year,temp.year);
        gotoxy(2,j);
        printf("%s",a.year);
        gotoxy(11,j);
        printf("%s",a.day);
        gotoxy(23,j);
        printf("%.2f",a.start);
        gotoxy(36,j);
        printf("%.2f",a.finish);
        gotoxy(52,j);
        printf("%s",a.course);
        gotoxy(70,j);
        printf("%s",teacher[a.teach_index]);
        printf("\n\n");
        j++;

    }

}

void grid_view(FILE *x)
{
    int i;
    struct data c;
    c.time1=9.00;
    c.time2=9.50;
    c.time3=10.35;
    c.time4=11.25;
    c.time5=12.15;
    c.time6=12.20;
    c.time7=1.05;
    c.time8=2.00;
    c.time9=2.45;
    c.time10=2.50;
    c.time11=3.35;
    c.time12=3.40;
    c.time13=4.25;

    system("cls");
    printf("                          **************************ROUTINE*************************");

    for(i=0; i<30; i++)
    {
        gotoxy(2,3+i);
        printf("\xB2");
    }


    for(i=0; i<119; i++)
    {
        gotoxy(3+i,32);
        printf("\xB2");
    }


    for(i=0; i<30; i++)
    {

        gotoxy(121,32-i);
        printf("\xB2");
    }



    for(i=0; i<119; i++)
    {

        gotoxy(120-i,3);
        printf("\xB2");
    }




    gotoxy(4,4);
    printf("TIME    |           |           |           |           |           |           |           |           |           |");
    gotoxy(4,5);
    printf("DAY     |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,6);

    printf("---------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|");
    gotoxy(4,7);
    printf("        |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,8);
    printf("         |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,9);
    printf("         |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,10);
    printf("---------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|");
    gotoxy(3,11);
    printf("         |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,12);
    printf("         |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,13);
    printf("         |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,14);
    printf("---------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|");
    gotoxy(3,15);
    printf("         |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,16);
    printf("         |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,17);
    printf("         |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,18);
    printf("---------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|");
    gotoxy(3,19);
    printf("         |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,20);
    printf("         |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,21);
    printf("         |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,22);
    printf("---------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|");
    gotoxy(3,23);
    printf("         |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,24);
    printf("         |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,25);
    printf("         |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,26);
    printf("---------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|");
    gotoxy(3,27);
    printf("         |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,28);
    printf("         |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,29);
    printf("         |           |           |           |           |           |           |           |           |           |");
    gotoxy(3,30);
    printf("---------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|-----------|");
    gotoxy(13,4);
    printf("9.00-9.50");

    gotoxy(25,4);
    printf("9.50-10.35");

    gotoxy(37,4);
    printf("10.35-11.25");
    gotoxy(49,4);
    printf("11.25-12.15");
    gotoxy(61,4);
    printf("12.20-1.05");
    gotoxy(85,4);
    printf("2.00-2.45");
    gotoxy(97,4);
    printf("2.50-3.35");
    gotoxy(109,4);
    printf("3.40-4.25");
    gotoxy(4,8);
    printf("%s",days[0]);
    gotoxy(4,12);
    printf("%s",days[1]);
    gotoxy(4,16);
    printf("%s",days[2]);
    gotoxy(4,20);
    printf("%s",days[3]);
    gotoxy(3,24);
    printf("%s",days[4]);
    gotoxy(4,28);
    printf("%s",days[5]);
    gotoxy(78,8);
    printf("B");
    gotoxy(78,12);
    printf("R");
    gotoxy(78,15);
    printf("E");
    gotoxy(78,20);
    printf("A");
    gotoxy(78,24);
    printf("K");



    rewind(x);
    while(fread(&a,sizeof(a),1,x)==1)
    {

        if(a.day==days[0])
        {

            if((a.start==c.time1)&&(a.finish==c.time2))
            {
                gotoxy(13,8);
                printf("%s",a.course);
                gotoxy(13,9);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time2)&&(a.finish==c.time3))
            {
                gotoxy(26,8);
                printf("%s",a.course);
                gotoxy(26,9);
                printf("%s",teacher[a.teach_index]);

            }


            else if((a.start==c.time3)&&(a.finish==c.time4))
            {

                gotoxy(37,8);
                printf("%s",a.course);
                gotoxy(37,9);
                printf("%s",teacher[a.teach_index]);

            }



            else if((a.start==c.time4)&&(a.finish==c.time5))
            {

                gotoxy(50,8);
                printf("%s",a.course);
                gotoxy(50,9);
                printf("%s",teacher[a.teach_index]);

            }



            else if((a.start==c.time6)&&(a.finish==c.time7))
            {

                gotoxy(62,8);
                printf("%s",a.course);
                gotoxy(62,9);
                printf("%s",teacher[a.teach_index]);

            }


            else if((a.start==c.time8)&&(a.finish==c.time9))
            {
                gotoxy(86,8);
                printf("%s",a.course);
                gotoxy(86,9);
                printf("%s",teacher[a.teach_index]);

            }



            else if((a.start==c.time10)&&(a.finish==c.time11))
            {
                gotoxy(98,8);
                printf("%s",a.course);
                gotoxy(98,9);
                printf("%s",teacher[a.teach_index]);

            }



            else if((a.start==c.time12)&&(a.finish==c.time13))
            {
                gotoxy(110,8);
                printf("%s",a.course);
                gotoxy(110,9);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time1)&&(a.finish==c.time3))
            {
                gotoxy(24,6);
                printf(" ");
                gotoxy(24,7);
                printf(" ");


                gotoxy(24,10);
                printf(" ");

                gotoxy(21,8);
                printf("%s",a.course);
                gotoxy(24,9);
                printf("%s",teacher[a.teach_index]);
            }

            else if((a.start==c.time2)&&(a.finish==c.time4))
            {
                gotoxy(36,6);
                printf(" ");
                gotoxy(36,7);
                printf(" ");
                gotoxy(36,10);
                printf(" ");

                gotoxy(34,8);
                printf("%s",a.course);
                gotoxy(35,9);
                printf("%s",teacher[a.teach_index]);
            }

            else if((a.start==c.time3)&&(a.finish==c.time5))
            {
                gotoxy(48,6);
                printf(" ");
                gotoxy(48,7);
                printf(" ");
                gotoxy(48,9);
                printf(" ");
                gotoxy(48,10);
                printf(" ");

                gotoxy(44,8);
                printf("%s",a.course);
                gotoxy(44,9);
                printf("%s",teacher[a.teach_index]);
            }

            else if((a.start==c.time4)&&(a.finish==c.time7))
            {
                gotoxy(60,6);
                printf(" ");
                gotoxy(60,7);
                printf(" ");
                gotoxy(60,9);
                printf(" ");
                gotoxy(60,10);
                printf(" ");

                gotoxy(56,8);
                printf("%s",a.course);
                gotoxy(56,9);
                printf("%s",teacher[a.teach_index]);
            }
            else if((a.start==c.time6)&&(a.finish==c.time9))
            {
                gotoxy(62,8);
                printf("%s",a.course);
                gotoxy(62,9);
                printf("%s",teacher[a.teach_index]);

                gotoxy(86,8);
                printf("%s",a.course);
                gotoxy(86,9);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time8)&&(a.finish==c.time11))
            {
                gotoxy(96,6);
                printf(" ");
                gotoxy(96,7);
                printf(" ");

                gotoxy(94,8);
                printf("%s",a.course);
                gotoxy(96,9);
                printf("%s",teacher[a.teach_index]);
                gotoxy(96,10);
                printf(" ");
            }
            else if((a.start==c.time10)&&(a.finish==c.time13))
            {
                gotoxy(108,6);
                printf(" ");
                gotoxy(108,7);
                printf(" ");
                gotoxy(107,8);
                printf("%s",a.course);
                gotoxy(108,9);
                printf("%s",teacher[a.teach_index]);
                gotoxy(108,10);
                printf(" ");

            }

            else if((a.start==c.time1)&&(a.finish==c.time4))
            {
                gotoxy(24,6);
                printf(" ");
                gotoxy(24,7);
                printf(" ");
                gotoxy(24,8);
                printf(" ");
                gotoxy(24,9);
                printf(" ");
                gotoxy(24,10);
                printf(" ");
                gotoxy(26,8);
                printf("%s",a.course);
                gotoxy(29,9);
                printf("%s",teacher[a.teach_index]);
                gotoxy(36,6);
                printf(" ");
                gotoxy(36,7);
                printf(" ");
                gotoxy(36,8);
                printf(" ");
                gotoxy(36,9);
                printf(" ");
                gotoxy(36,10);
                printf(" ");
            }

            else if((a.start==c.time2)&&(a.finish==c.time5))
            {
                gotoxy(36,6);
                printf(" ");
                gotoxy(36,7);
                printf(" ");
                gotoxy(36,8);
                printf(" ");
                gotoxy(36,9);
                printf(" ");
                gotoxy(36,10);
                printf(" ");

                gotoxy(37,8);
                printf("%s",a.course);
                gotoxy(37,9);
                printf("%s",teacher[a.teach_index]);

                gotoxy(48,6);
                printf(" ");
                gotoxy(48,7);
                printf(" ");
                gotoxy(48,8);
                printf(" ");
                gotoxy(48,9);
                printf(" ");
                gotoxy(48,10);
                printf(" ");

            }

            else if((a.start==c.time3)&&(a.finish==c.time7))
            {
                gotoxy(48,6);
                printf(" ");
                gotoxy(48,7);
                printf(" ");
                gotoxy(48,8);
                printf(" ");
                gotoxy(48,9);
                printf(" ");
                gotoxy(48,10);
                printf(" ");


                gotoxy(50,8);
                printf("%s",a.course);
                gotoxy(50,9);
                printf("%s",teacher[a.teach_index]);

                gotoxy(60,6);
                printf(" ");
                gotoxy(60,7);
                printf(" ");
                gotoxy(60,8);
                printf(" ");
                gotoxy(60,9);
                printf(" ");
                gotoxy(60,10);
                printf(" ");
            }


            else if((a.start==c.time4)&&(a.finish==c.time9))
            {
                gotoxy(60,6);
                printf(" ");
                gotoxy(60,7);
                printf(" ");

                gotoxy(60,10);
                printf(" ");
                gotoxy(56,8);
                printf("%s",a.course);
                gotoxy(59,9);
                printf("%s",teacher[a.teach_index]);

                gotoxy(85,8);
                printf("%s",a.course);
                gotoxy(85,9);
                printf("%s",teacher[a.teach_index]);


            }
            else if((a.start==c.time6)&&(a.finish==c.time11))
            {
                gotoxy(61,8);
                printf("%s",a.course);

                gotoxy(62,9);
                printf("%s",teacher[a.teach_index]);

                gotoxy(90,8);
                printf("%s",a.course);
                gotoxy(93,9);
                printf("%s",teacher[a.teach_index]);

                gotoxy(96,6);
                printf(" ");
                gotoxy(96,7);
                printf(" ");
                gotoxy(96,9);
                printf(" ");
                gotoxy(96,10);
                printf(" ");

            }


            else if((a.start==c.time8)&&(a.finish==c.time13))
            {
                gotoxy(96,6);
                printf(" ");
                gotoxy(96,7);
                printf(" ");
                gotoxy(96,8);
                printf(" ");
                gotoxy(96,9);
                printf(" ");
                gotoxy(96,10);
                printf(" ");

                gotoxy(98,8);
                printf("%s",a.course);
                gotoxy(98,9);
                printf("%s",teacher[a.teach_index]);
                gotoxy(108,6);
                printf(" ");
                gotoxy(108,7);
                printf(" ");

                gotoxy(108,8);
                printf(" ");
                gotoxy(108,9);
                printf(" ");
                gotoxy(108,10);
                printf(" ");
            }
        }

        else if(a.day==days[1])
        {
            if((a.start==c.time1)&&(a.finish==c.time2))
            {

                gotoxy(13,12);
                printf("%s",a.course);
                gotoxy(13,13);
                printf("%s",teacher[a.teach_index]);

            }

            else if((a.start==c.time2)&&(a.finish==c.time3))
            {
                gotoxy(27,12);
                printf("%s",a.course);
                gotoxy(27,13);
                printf("%s",teacher[a.teach_index]);
            }

            else if((a.start==c.time3)&&(a.finish==c.time4))
            {
                gotoxy(37,12);
                printf("%s",a.course);
                gotoxy(37,13);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time4)&&(a.finish==c.time5))
            {

                gotoxy(50,12);
                printf("%s",a.course);
                gotoxy(50,13);
                printf("%s",teacher[a.teach_index]);

            }


            else if((a.start==c.time6)&&(a.finish==c.time7))
            {

                gotoxy(62,12);
                printf("%s",a.course);
                gotoxy(62,13);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time8)&&(a.finish==c.time9))
            {

                gotoxy(86,12);
                printf("%s",a.course);
                gotoxy(86,13);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time10)&&(a.finish==c.time11))
            {

                gotoxy(98,12);
                printf("%s",a.course);
                gotoxy(98,13);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time12)&&(a.finish==c.time13))
            {

                gotoxy(110,12);
                printf("%s",a.course);
                gotoxy(110,13);
                printf("%s",teacher[a.teach_index]);

            }


            else if((a.start==c.time1)&&(a.finish==c.time3))
            {
                gotoxy(24,10);
                printf(" ");
                gotoxy(24,11);
                printf(" ");


                gotoxy(24,14);
                printf(" ");

                gotoxy(21,12);
                printf("%s",a.course);
                gotoxy(24,13);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time2)&&(a.finish==c.time4))
            {
                gotoxy(36,10);
                printf(" ");
                gotoxy(36,11);
                printf(" ");
                gotoxy(36,14);
                printf(" ");

                gotoxy(34,12);
                printf("%s",a.course);
                gotoxy(35,13);
                printf("%s",teacher[a.teach_index]);
            }

            else if((a.start==c.time3)&&(a.finish==c.time5))
            {
                gotoxy(48,10);
                printf(" ");
                gotoxy(48,11);
                printf(" ");
                gotoxy(48,14);
                printf(" ");
                gotoxy(48,12);
                printf(" ");

                gotoxy(44,12);
                printf("%s",a.course);
                gotoxy(48,13);
                printf("%s",teacher[a.teach_index]);
            }

            else if((a.start==c.time4)&&(a.finish==c.time7))
            {

                gotoxy(60,10);
                printf(" ");
                gotoxy(60,11);
                printf(" ");
                gotoxy(60,13);
                printf(" ");
                gotoxy(60,14);
                printf(" ");

                gotoxy(56,12);
                printf("%s",a.course);
                gotoxy(56,13);
                printf("%s",teacher[a.teach_index]);
            }

            else if((a.start==c.time6)&&(a.finish==c.time9))
            {
                gotoxy(62,12);
                printf("%s",a.course);
                gotoxy(62,13);
                printf("%s",teacher[a.teach_index]);

                gotoxy(86,12);
                printf("%s",a.course);
                gotoxy(86,13);
                printf("%s",teacher[a.teach_index]);
            }

            else if((a.start==c.time8)&&(a.finish==c.time11))
            {

                gotoxy(96,10);
                printf(" ");
                gotoxy(96,11);
                printf(" ");

                gotoxy(94,12);
                printf("%s",a.course);
                gotoxy(94,13);
                printf("%s",teacher[a.teach_index]);
                gotoxy(96,14);
                printf(" ");

            }

            else if((a.start==c.time10)&&(a.finish==c.time13))
            {

                gotoxy(108,10);
                printf(" ");
                gotoxy(108,11);
                printf(" ");
                gotoxy(107,12);
                printf("%s",a.course);
                gotoxy(108,13);
                printf("%s",teacher[a.teach_index]);
                gotoxy(108,14);
                printf(" ");
            }
            else if((a.start==c.time1)&&(a.finish==c.time4))
            {
                gotoxy(24,10);
                printf(" ");
                gotoxy(24,11);
                printf(" ");
                gotoxy(24,12);
                printf(" ");
                gotoxy(24,13);
                printf(" ");
                gotoxy(24,14);
                printf(" ");
                gotoxy(26,12);
                printf("%s",a.course);
                gotoxy(29,13);
                printf("%s",teacher[a.teach_index]);
                gotoxy(36,10);
                printf(" ");
                gotoxy(36,11);
                printf(" ");
                gotoxy(36,12);
                printf(" ");
                gotoxy(36,13);
                printf(" ");
                gotoxy(36,14);
                printf(" ");
            }
            else if((a.start==c.time2)&&(a.finish==c.time5))
            {
                gotoxy(36,10);
                printf(" ");
                gotoxy(36,11);
                printf(" ");
                gotoxy(36,12);
                printf(" ");
                gotoxy(36,13);
                printf(" ");
                gotoxy(36,14);
                printf(" ");

                gotoxy(37,12);
                printf("%s",a.course);
                gotoxy(37,13);
                printf("%s",teacher[a.teach_index]);

                gotoxy(48,10);
                printf(" ");
                gotoxy(48,11);
                printf(" ");
                gotoxy(48,12);
                printf(" ");
                gotoxy(48,13);
                printf(" ");
                gotoxy(48,14);
                printf(" ");

            }

            else if((a.start==c.time3)&&(a.finish==c.time7))
            {
                gotoxy(48,10);
                printf(" ");
                gotoxy(48,11);
                printf(" ");
                gotoxy(48,12);
                printf(" ");
                gotoxy(48,13);
                printf(" ");
                gotoxy(48,14);
                printf(" ");


                gotoxy(50,12);
                printf("%s",a.course);
                gotoxy(50,13);
                printf("%s",teacher[a.teach_index]);

                gotoxy(60,10);
                printf(" ");
                gotoxy(60,11);
                printf(" ");
                gotoxy(60,12);
                printf(" ");
                gotoxy(60,13);
                printf(" ");
                gotoxy(60,14);
                printf(" ");
            }
            else if((a.start==c.time4)&&(a.finish==c.time9))
            {
                gotoxy(60,10);
                printf(" ");
                gotoxy(60,11);
                printf(" ");

                gotoxy(60,14);
                printf(" ");
                gotoxy(56,12);
                printf("%s",a.course);
                gotoxy(59,13);
                printf("%s",teacher[a.teach_index]);

                gotoxy(85,12);
                printf("%s",a.course);
                gotoxy(85,13);
                printf("%s",teacher[a.teach_index]);


            }
            else if((a.start==c.time6)&&(a.finish==c.time11))
            {
                gotoxy(61,12);
                printf("%s",a.course);

                gotoxy(62,13);
                printf("%s",teacher[a.teach_index]);

                gotoxy(90,12);
                printf("%s",a.course);
                gotoxy(93,13);
                printf("%s",teacher[a.teach_index]);

                gotoxy(96,10);
                printf(" ");
                gotoxy(96,11);
                printf(" ");
                gotoxy(96,12);
                printf(" ");
                gotoxy(96,13);
                printf(" ");

            }
            else if((a.start==c.time8)&&(a.finish==c.time13))
            {
                gotoxy(96,10);
                printf(" ");
                gotoxy(96,11);
                printf(" ");
                gotoxy(96,12);
                printf(" ");
                gotoxy(96,13);
                printf(" ");
                gotoxy(96,14);
                printf(" ");

                gotoxy(98,12);
                printf("%s",a.course);
                gotoxy(98,13);
                printf("%s",teacher[a.teach_index]);
                gotoxy(108,10);
                printf(" ");
                gotoxy(108,11);
                printf(" ");
                gotoxy(108,13);
                printf(" ");
                gotoxy(108,14);
                printf(" ");
            }
        }
        else if(a.day==days[2])
        {

            if((a.start==c.time1)&&(a.finish==c.time2))
            {

                gotoxy(13,16);
                printf("%s",a.course);
                gotoxy(13,17);
                printf("%s",teacher[a.teach_index]);

            }

            else if((a.start==c.time2)&&(a.finish==c.time3))
            {

                gotoxy(26,16);
                printf("%s",a.course);
                gotoxy(26,17);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time3)&&(a.finish==c.time4))
            {

                gotoxy(37,16);
                printf("%s",a.course);
                gotoxy(37,17);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time4)&&(a.finish==c.time5))
            {

                gotoxy(50,16);
                printf("%s",a.course);
                gotoxy(50,17);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time6)&&(a.finish==c.time7))
            {

                gotoxy(62,16);
                printf("%s",a.course);
                gotoxy(62,17);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time8)&&(a.finish==c.time9))
            {

                gotoxy(86,16);
                printf("%s",a.course);
                gotoxy(86,17);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time10)&&(a.finish==c.time11))
            {

                gotoxy(98,16);
                printf("%s",a.course);
                gotoxy(98,17);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time12)&&(a.finish==c.time13))
            {

                gotoxy(110,16);
                printf("%s",a.course);
                gotoxy(110,17);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time1)&&(a.finish==c.time3))
            {

                gotoxy(24,14);
                printf(" ");
                gotoxy(24,15);
                printf(" ");


                gotoxy(24,18);
                printf(" ");

                gotoxy(21,16);
                printf("%s",a.course);
                gotoxy(24,17);
                printf("%s",teacher[a.teach_index]);
            }
            else if((a.start==c.time2)&&(a.finish==c.time4))
            {

                gotoxy(36,14);
                printf(" ");
                gotoxy(36,15);
                printf(" ");
                gotoxy(36,18);
                printf(" ");

                gotoxy(34,16);
                printf("%s",a.course);
                gotoxy(35,17);
                printf("%s",teacher[a.teach_index]);
            }

            else if((a.start==c.time3)&&(a.finish==c.time5))
            {

                gotoxy(48,14);
                printf(" ");
                gotoxy(48,15);
                printf(" ");
                gotoxy(48,18);
                printf(" ");
                gotoxy(48,16);
                printf(" ");

                gotoxy(44,16);
                printf("%s",a.course);
                gotoxy(48,17);
                printf("%s",teacher[a.teach_index]);

            }

            else if((a.start==c.time4)&&(a.finish==c.time7))
            {


                gotoxy(60,14);
                printf(" ");
                gotoxy(60,15);
                printf(" ");
                gotoxy(60,17);
                printf(" ");
                gotoxy(60,18);
                printf(" ");

                gotoxy(56,16);
                printf("%s",a.course);
                gotoxy(56,17);
                printf("%s",teacher[a.teach_index]);


            }

            else if((a.start==c.time6)&&(a.finish==c.time9))
            {

                gotoxy(62,16);
                printf("%s",a.course);
                gotoxy(62,17);
                printf("%s",teacher[a.teach_index]);

                gotoxy(86,16);
                printf("%s",a.course);
                gotoxy(86,17);
                printf("%s",teacher[a.teach_index]);
            }

            else if((a.start==c.time8)&&(a.finish==c.time11))
            {
                gotoxy(96,14);
                printf(" ");
                gotoxy(96,15);
                printf(" ");

                gotoxy(90,16);
                printf("%s",a.course);
                gotoxy(94,17);
                printf("%s",teacher[a.teach_index]);
                gotoxy(96,18);
                printf(" ");

            }

            else if((a.start==c.time10)&&(a.finish==c.time13))
            {
                gotoxy(108,14);
                printf(" ");
                gotoxy(108,15);
                printf(" ");
                gotoxy(105,16);
                printf("%s",a.course);
                gotoxy(108,17);
                printf("%s",teacher[a.teach_index]);
                gotoxy(108,18);
                printf(" ");

            }

            else if((a.start==c.time1)&&(a.finish==c.time4))
            {
                gotoxy(24,14);
                printf(" ");
                gotoxy(24,15);
                printf(" ");
                gotoxy(24,16);
                printf(" ");
                gotoxy(24,17);
                printf(" ");
                gotoxy(24,18);
                printf(" ");
                gotoxy(26,16);
                printf("%s",a.course);
                gotoxy(29,17);
                printf("%s",teacher[a.teach_index]);
                gotoxy(36,14);
                printf(" ");
                gotoxy(36,15);
                printf(" ");
                gotoxy(36,16);
                printf(" ");
                gotoxy(36,17);
                printf(" ");
                gotoxy(36,18);
                printf(" ");

            }

            else if((a.start==c.time2)&&(a.finish==c.time5))
            {
                gotoxy(24,14);
                printf(" ");
                gotoxy(24,15);
                printf(" ");
                gotoxy(24,16);
                printf(" ");
                gotoxy(24,17);
                printf(" ");
                gotoxy(24,18);
                printf(" ");
                gotoxy(26,16);
                printf("%s",a.course);
                gotoxy(29,17);
                printf("%s",teacher[a.teach_index]);
                gotoxy(36,14);
                printf(" ");
                gotoxy(36,15);
                printf(" ");
                gotoxy(36,16);
                printf(" ");
                gotoxy(36,17);
                printf(" ");
                gotoxy(36,18);
                printf(" ");
            }

            else if((a.start==c.time3)&&(a.finish==c.time7))
            {
                gotoxy(48,14);
                printf(" ");
                gotoxy(48,15);
                printf(" ");
                gotoxy(48,16);
                printf(" ");
                gotoxy(48,17);
                printf(" ");
                gotoxy(48,18);
                printf(" ");


                gotoxy(50,16);
                printf("%s",a.course);
                gotoxy(50,17);
                printf("%s",teacher[a.teach_index]);

                gotoxy(60,14);
                printf(" ");
                gotoxy(60,15);
                printf(" ");
                gotoxy(60,16);
                printf(" ");
                gotoxy(60,17);
                printf(" ");
                gotoxy(60,18);
                printf(" ");
            }
            else if((a.start==c.time4)&&(a.finish==c.time9))
            {

                gotoxy(60,14);
                printf(" ");
                gotoxy(60,15);
                printf(" ");

                gotoxy(60,18);
                printf(" ");
                gotoxy(56,16);
                printf("%s",a.course);
                gotoxy(59,17);
                printf("%s",teacher[a.teach_index]);

                gotoxy(85,16);
                printf("%s",a.course);
                gotoxy(85,17);
                printf("%s",teacher[a.teach_index]);


            }
            else if((a.start==c.time6)&&(a.finish==c.time11))
            {
                gotoxy(61,16);
                printf("%s",a.course);

                gotoxy(62,17);
                printf("%s",teacher[a.teach_index]);

                gotoxy(90,16);
                printf("%s",a.course);
                gotoxy(93,17);
                printf("%s",teacher[a.teach_index]);

                gotoxy(96,14);
                printf(" ");
                gotoxy(96,15);
                printf(" ");
                gotoxy(96,16);
                printf(" ");
                gotoxy(96,17);
                printf(" ");
            }
            else if((a.start==c.time8)&&(a.finish==c.time13))
            {
                gotoxy(96,14);
                printf(" ");
                gotoxy(96,15);
                printf(" ");
                gotoxy(96,16);
                printf(" ");
                gotoxy(96,17);
                printf(" ");
                gotoxy(96,18);
                printf(" ");

                gotoxy(98,16);
                printf("%s",a.course);
                gotoxy(98,17);
                printf("%s",teacher[a.teach_index]);
                gotoxy(108,14);
                printf(" ");
                gotoxy(108,15);
                printf(" ");

                gotoxy(108,16);
                printf(" ");
                gotoxy(108,17);
                printf(" ");
                gotoxy(108,18);
                printf(" ");
            }
        }
        else if(a.day==days[3])
        {
            if((a.start==c.time1)&&(a.finish==c.time2))
            {
                gotoxy(13,20);
                printf("%s",a.course);
                gotoxy(13,21);
                printf("%s",teacher[a.teach_index]);
            }
            else if((a.start==c.time2)&&(a.finish==c.time3))
            {
                gotoxy(26,20);
                printf("%s",a.course);
                gotoxy(26,21);
                printf("%s",teacher[a.teach_index]);
            }
            else if((a.start==c.time3)&&(a.finish==c.time4))
            {
                gotoxy(37,20);
                printf("%s",a.course);
                gotoxy(37,21);
                printf("%s",teacher[a.teach_index]);
            }
            else if((a.start==c.time4)&&(a.finish==c.time5))
            {
                gotoxy(50,20);
                printf("%s",a.course);
                gotoxy(50,21);
                printf("%s",teacher[a.teach_index]);
            }
            else if((a.start==c.time6)&&(a.finish==c.time7))
            {
                gotoxy(62,20);
                printf("%s",a.course);
                gotoxy(62,21);
                printf("%s",teacher[a.teach_index]);
            }
            else if((a.start==c.time8)&&(a.finish==c.time9))
            {
                gotoxy(86,20);
                printf("%s",a.course);
                gotoxy(86,21);
                printf("%s",teacher[a.teach_index]);
            }
            else if((a.start==c.time10)&&(a.finish==c.time11))
            {
                gotoxy(98,20);
                printf("%s",a.course);
                gotoxy(98,21);
                printf("%s",teacher[a.teach_index]);
            }
            else if((a.start==c.time12)&&(a.finish==c.time13))
            {
                gotoxy(110,20);
                printf("%s",a.course);
                gotoxy(110,21);
                printf("%s",teacher[a.teach_index]);
            }
            else if((a.start==c.time1)&&(a.finish==c.time3))
            {
                gotoxy(24,18);
                printf(" ");
                gotoxy(24,19);
                printf(" ");


                gotoxy(24,22);
                printf(" ");

                gotoxy(21,20);
                printf("%s",a.course);
                gotoxy(24,21);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time2)&&(a.finish==c.time4))
            {
                gotoxy(36,18);
                printf(" ");
                gotoxy(36,19);
                printf(" ");
                gotoxy(36,22);
                printf(" ");

                gotoxy(34,20);
                printf("%s",a.course);
                gotoxy(35,21);
                printf("%s",teacher[a.teach_index]);
            }

            else if((a.start==c.time3)&&(a.finish==c.time5))
            {

                gotoxy(48,18);
                printf(" ");
                gotoxy(48,19);
                printf(" ");
                gotoxy(48,22);
                printf(" ");
                gotoxy(48,20);
                printf(" ");

                gotoxy(44,20);
                printf("%s",a.course);
                gotoxy(48,21);
                printf("%s",teacher[a.teach_index]);
            }

            else if((a.start==c.time4)&&(a.finish==c.time7))
            {

                gotoxy(60,18);
                printf(" ");
                gotoxy(60,19);
                printf(" ");
                gotoxy(60,20);
                printf(" ");
                gotoxy(60,21);
                printf(" ");
                gotoxy(60,22);
                printf(" ");

                gotoxy(56,20);
                printf("%s",a.course);
                gotoxy(56,21);
                printf("%s",teacher[a.teach_index]);



            }

            else if((a.start==c.time6)&&(a.finish==c.time9))
            {
                gotoxy(62,20);
                printf("%s",a.course);
                gotoxy(62,21);
                printf("%s",teacher[a.teach_index]);

                gotoxy(86,20);
                printf("%s",a.course);
                gotoxy(86,21);
                printf("%s",teacher[a.teach_index]);
            }

            else if((a.start==c.time8)&&(a.finish==c.time11))
            {

                gotoxy(96,18);
                printf(" ");
                gotoxy(96,19);
                printf(" ");

                gotoxy(94,20);
                printf("%s",a.course);
                gotoxy(94,21);
                printf("%s",teacher[a.teach_index]);
                gotoxy(96,22);
                printf(" ");

            }

            else if((a.start==c.time10)&&(a.finish==c.time13))
            {

                gotoxy(108,18);
                printf(" ");
                gotoxy(108,19);
                printf(" ");
                gotoxy(107,20);
                printf("%s",a.course);
                gotoxy(108,21);
                printf("%s",teacher[a.teach_index]);
                gotoxy(108,22);
                printf(" ");

            }

            else if((a.start==c.time1)&&(a.finish==c.time4))
            {

                gotoxy(24,19);
                printf(" ");
                gotoxy(24,18);
                printf(" ");
                gotoxy(24,20);
                printf(" ");
                gotoxy(24,21);
                printf(" ");
                gotoxy(24,22);
                printf(" ");
                gotoxy(26,20);
                printf("%s",a.course);
                gotoxy(29,21);
                printf("%s",teacher[a.teach_index]);
                gotoxy(36,18);
                printf(" ");
                gotoxy(36,19);
                printf(" ");
                gotoxy(36,20);
                printf(" ");
                gotoxy(36,21);
                printf(" ");
                gotoxy(36,22);
                printf(" ");

            }

            else if((a.start==c.time2)&&(a.finish==c.time5))
            {

                gotoxy(24,18);
                printf(" ");
                gotoxy(24,19);
                printf(" ");
                gotoxy(24,20);
                printf(" ");
                gotoxy(24,21);
                printf(" ");
                gotoxy(24,22);
                printf(" ");
                gotoxy(26,20);
                printf("%s",a.course);
                gotoxy(29,21);
                printf("%s",teacher[a.teach_index]);
                gotoxy(36,18);
                printf(" ");
                gotoxy(36,19);
                printf(" ");
                gotoxy(36,20);
                printf(" ");
                gotoxy(36,21);
                printf(" ");
                gotoxy(36,22);
                printf(" ");
            }

            else if((a.start==c.time3)&&(a.finish==c.time7))
            {
                gotoxy(48,18);
                printf(" ");
                gotoxy(48,19);
                printf(" ");
                gotoxy(48,20);
                printf(" ");
                gotoxy(48,21);
                printf(" ");
                gotoxy(48,22);
                printf(" ");


                gotoxy(50,20);
                printf("%s",a.course);
                gotoxy(50,21);
                printf("%s",teacher[a.teach_index]);

                gotoxy(60,18);
                printf(" ");
                gotoxy(60,19);
                printf(" ");
                gotoxy(60,20);
                printf(" ");
                gotoxy(60,21);
                printf(" ");
                gotoxy(60,22);
                printf(" ");
            }
            else if((a.start==c.time4)&&(a.finish==c.time9))
            {

                gotoxy(60,18);
                printf(" ");
                gotoxy(60,19);
                printf(" ");

                gotoxy(60,22);
                printf(" ");
                gotoxy(56,20);
                printf("%s",a.course);
                gotoxy(59,21);
                printf("%s",teacher[a.teach_index]);

                gotoxy(85,20);
                printf("%s",a.course);
                gotoxy(85,21);
                printf("%s",teacher[a.teach_index]);
            }
            else if((a.start==c.time6)&&(a.finish==c.time11))
            {

                gotoxy(61,20);
                printf("%s",a.course);

                gotoxy(62,21);
                printf("%s",teacher[a.teach_index]);

                gotoxy(90,20);
                printf("%s",a.course);
                gotoxy(93,21);
                printf("%s",teacher[a.teach_index]);

                gotoxy(96,18);
                printf(" ");
                gotoxy(96,19);
                printf(" ");
                gotoxy(96,20);
                printf(" ");
                gotoxy(96,21);
                printf(" ");
                gotoxy(96,22);
                printf(" ");

            }
            else if((a.start==c.time8)&&(a.finish==c.time13))
            {

                gotoxy(96,18);
                printf(" ");
                gotoxy(96,19);
                printf(" ");
                gotoxy(96,20);
                printf(" ");
                gotoxy(96,21);
                printf(" ");
                gotoxy(96,22);
                printf(" ");

                gotoxy(98,20);
                printf("%s",a.course);
                gotoxy(98,21);
                printf("%s",teacher[a.teach_index]);
                gotoxy(108,18);
                printf(" ");
                gotoxy(108,19);
                printf(" ");

                gotoxy(108,20);
                printf(" ");
                gotoxy(108,21);
                printf(" ");
                gotoxy(108,22);
                printf(" ");
            }
        }
        else if(a.day==days[4])
        {
            if((a.start==c.time1)&&(a.finish==c.time2))
            {

                gotoxy(13,24);
                printf("%s",a.course);
                gotoxy(13,25);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time2)&&(a.finish==c.time3))
            {

                gotoxy(26,24);
                printf("%s",a.course);
                gotoxy(26,25);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time3)&&(a.finish==c.time4))
            {

                gotoxy(37,24);
                printf("%s",a.course);
                gotoxy(37,25);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time4)&&(a.finish==c.time5))
            {

                gotoxy(50,24);
                printf("%s",a.course);
                gotoxy(50,25);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time6)&&(a.finish==c.time7))
            {

                gotoxy(62,24);
                printf("%s",a.course);
                gotoxy(62,25);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time8)&&(a.finish==c.time9))
            {

                gotoxy(86,24);
                printf("%s",a.course);
                gotoxy(86,25);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time10)&&(a.finish==c.time11))
            {

                gotoxy(98,24);
                printf("%s",a.course);
                gotoxy(98,25);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time12)&&(a.finish==c.time13))
            {

                gotoxy(110,24);
                printf("%s",a.course);
                gotoxy(110,25);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time1)&&(a.finish==c.time3))
            {
                gotoxy(24,22);
                printf(" ");
                gotoxy(24,23);
                printf(" ");

                gotoxy(24,26);
                printf(" ");

                gotoxy(21,24);
                printf("%s",a.course);
                gotoxy(24,25);
                printf("%s",teacher[a.teach_index]);


            }
            else if((a.start==c.time2)&&(a.finish==c.time4))
            {

                gotoxy(36,22);
                printf(" ");
                gotoxy(36,23);
                printf(" ");
                gotoxy(36,26);
                printf(" ");

                gotoxy(34,24);
                printf("%s",a.course);
                gotoxy(35,25);
                printf("%s",teacher[a.teach_index]);
            }

            else if((a.start==c.time3)&&(a.finish==c.time5))
            {
                gotoxy(48,22);
                printf(" ");
                gotoxy(48,23);
                printf(" ");
                gotoxy(48,26);
                printf(" ");
                gotoxy(48,24);
                printf(" ");

                gotoxy(44,24);
                printf("%s",a.course);
                gotoxy(48,25);
                printf("%s",teacher[a.teach_index]);
            }

            else if((a.start==c.time4)&&(a.finish==c.time7))
            {
                gotoxy(60,22);
                printf(" ");
                gotoxy(60,23);
                printf(" ");
                gotoxy(60,24);
                printf(" ");
                gotoxy(60,25);
                printf(" ");
                gotoxy(60,26);
                printf(" ");

                gotoxy(56,24);
                printf("%s",a.course);
                gotoxy(56,25);
                printf("%s",teacher[a.teach_index]);

            }

            else if((a.start==c.time6)&&(a.finish==c.time9))
            {

                gotoxy(62,24);
                printf("%s",a.course);
                gotoxy(62,25);
                printf("%s",teacher[a.teach_index]);

                gotoxy(86,24);
                printf("%s",a.course);
                gotoxy(86,25);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time8)&&(a.finish==c.time11))
            {
                gotoxy(96,22);
                printf(" ");
                gotoxy(96,23);
                printf(" ");

                gotoxy(94,24);
                printf("%s",a.course);
                gotoxy(94,25);
                printf("%s",teacher[a.teach_index]);
                gotoxy(96,26);
                printf(" ");

            }
            else if((a.start==c.time10)&&(a.finish==c.time13))
            {
                gotoxy(108,22);
                printf(" ");
                gotoxy(108,23);
                printf(" ");
                gotoxy(107,24);
                printf("%s",a.course);
                gotoxy(108,25);
                printf("%s",teacher[a.teach_index]);
                gotoxy(108,26);
                printf(" ");

            }

            else if((a.start==c.time1)&&(a.finish==c.time4))
            {

                gotoxy(24,22);
                printf(" ");
                gotoxy(24,23);
                printf(" ");
                gotoxy(24,24);
                printf(" ");
                gotoxy(24,25);
                printf(" ");
                gotoxy(24,26);
                printf(" ");
                gotoxy(26,24);
                printf("%s",a.course);
                gotoxy(29,25);
                printf("%s",teacher[a.teach_index]);
                gotoxy(36,22);
                printf(" ");
                gotoxy(36,23);
                printf(" ");
                gotoxy(36,24);
                printf(" ");
                gotoxy(36,25);
                printf(" ");
                gotoxy(36,26);
                printf(" ");

            }

            else if((a.start==c.time2)&&(a.finish==c.time5))
            {
                gotoxy(24,22);
                printf(" ");
                gotoxy(24,23);
                printf(" ");
                gotoxy(24,24);
                printf(" ");
                gotoxy(24,25);
                printf(" ");
                gotoxy(24,26);
                printf(" ");
                gotoxy(26,24);
                printf("%s",a.course);
                gotoxy(29,25);
                printf("%s",teacher[a.teach_index]);
                gotoxy(36,22);
                printf(" ");
                gotoxy(36,23);
                printf(" ");
                gotoxy(36,24);
                printf(" ");
                gotoxy(36,25);
                printf(" ");
                gotoxy(36,26);
                printf(" ");

            }

            else if((a.start==c.time3)&&(a.finish==c.time7))
            {
                gotoxy(48,22);
                printf(" ");
                gotoxy(48,23);
                printf(" ");
                gotoxy(48,24);
                printf(" ");
                gotoxy(48,25);
                printf(" ");
                gotoxy(48,26);
                printf(" ");

                gotoxy(50,24);
                printf("%s",a.course);
                gotoxy(50,25);
                printf("%s",teacher[a.teach_index]);

                gotoxy(60,22);
                printf(" ");
                gotoxy(60,23);
                printf(" ");
                gotoxy(60,24);
                printf(" ");
                gotoxy(60,25);
                printf(" ");
                gotoxy(60,26);
                printf(" ");
            }
            else if((a.start==c.time4)&&(a.finish==c.time9))
            {
                gotoxy(60,22);
                printf(" ");
                gotoxy(60,23);
                printf(" ");

                gotoxy(60,26);
                printf(" ");
                gotoxy(56,24);
                printf("%s",a.course);
                gotoxy(59,25);
                printf("%s",teacher[a.teach_index]);

                gotoxy(85,24);
                printf("%s",a.course);
                gotoxy(85,25);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time6)&&(a.finish==c.time11))
            {

                gotoxy(61,24);
                printf("%s",a.course);

                gotoxy(62,25);
                printf("%s",teacher[a.teach_index]);

                gotoxy(90,24);
                printf("%s",a.course);
                gotoxy(93,25);
                printf("%s",teacher[a.teach_index]);

                gotoxy(96,22);
                printf(" ");
                gotoxy(96,23);
                printf(" ");
                gotoxy(96,24);
                printf(" ");
                gotoxy(96,25);
                printf(" ");
                gotoxy(96,26);
                printf(" ");
            }
            else if((a.start==c.time8)&&(a.finish==c.time13))
            {
                gotoxy(96,22);
                printf(" ");
                gotoxy(96,23);
                printf(" ");
                gotoxy(96,24);
                printf(" ");
                gotoxy(96,25);
                printf(" ");
                gotoxy(96,26);
                printf(" ");

                gotoxy(98,24);
                printf("%s",a.course);
                gotoxy(98,25);
                printf("%s",teacher[a.teach_index]);
                gotoxy(108,22);
                printf(" ");
                gotoxy(108,23);
                printf(" ");

                gotoxy(108,24);
                printf(" ");
                gotoxy(108,25);
                printf(" ");
                gotoxy(108,26);
                printf(" ");

            }
        }
        else if(a.day==days[5])
        {
            if((a.start==c.time1)&&(a.finish==c.time2))
            {
                gotoxy(16,28);
                printf("%s",a.course);
                gotoxy(16,29);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time2)&&(a.finish==c.time3))
            {
                gotoxy(26,28);
                printf("%s",a.course);
                gotoxy(26,29);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time3)&&(a.finish==c.time4))
            {

                gotoxy(37,28);
                printf("%s",a.course);
                gotoxy(37,29);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time4)&&(a.finish==c.time5))
            {

                gotoxy(50,28);
                printf("%s",a.course);
                gotoxy(50,29);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time6)&&(a.finish==c.time7))
            {
                gotoxy(62,28);
                printf("%s",a.course);
                gotoxy(62,29);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time8)&&(a.finish==c.time9))
            {
                gotoxy(86,28);
                printf("%s",a.course);
                gotoxy(86,29);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time10)&&(a.finish==c.time11))
            {
                gotoxy(98,28);
                printf("%s",a.course);
                gotoxy(98,29);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time12)&&(a.finish==c.time13))
            {
                gotoxy(110,28);
                printf("%s",a.course);
                gotoxy(110,29);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time1)&&(a.finish==c.time3))
            {
                gotoxy(24,26);
                printf(" ");
                gotoxy(24,27);
                printf(" ");

                gotoxy(24,30);
                printf(" ");

                gotoxy(21,28);
                printf("%s",a.course);
                gotoxy(24,29);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time2)&&(a.finish==c.time4))
            {
                gotoxy(36,26);
                printf(" ");
                gotoxy(36,27);
                printf(" ");
                gotoxy(36,30);
                printf(" ");

                gotoxy(34,28);
                printf("%s",a.course);
                gotoxy(35,29);
                printf("%s",teacher[a.teach_index]);
            }

            else if((a.start==c.time3)&&(a.finish==c.time5))
            {

                gotoxy(48,26);
                printf(" ");
                gotoxy(48,27);
                printf(" ");
                gotoxy(48,30);
                printf(" ");
                gotoxy(48,28);
                printf(" ");

                gotoxy(44,28);
                printf("%s",a.course);
                gotoxy(48,29);
                printf("%s",teacher[a.teach_index]);

            }

            else if((a.start==c.time4)&&(a.finish==c.time7))
            {

                gotoxy(60,26);
                printf(" ");
                gotoxy(60,27);
                printf(" ");
                gotoxy(60,28);
                printf(" ");
                gotoxy(60,29);
                printf(" ");
                gotoxy(60,30);
                printf(" ");

                gotoxy(56,28);
                printf("%s",a.course);
                gotoxy(56,29);
                printf("%s",teacher[a.teach_index]);



            }

            else if((a.start==c.time6)&&(a.finish==c.time9))
            {

                gotoxy(62,28);
                printf("%s",a.course);
                gotoxy(62,29);
                printf("%s",teacher[a.teach_index]);

                gotoxy(86,28);
                printf("%s",a.course);
                gotoxy(86,29);
                printf("%s",teacher[a.teach_index]);


            }

            else if((a.start==c.time8)&&(a.finish==c.time11))
            {

                gotoxy(96,26);
                printf(" ");
                gotoxy(96,27);
                printf(" ");

                gotoxy(90,28);
                printf("%s",a.course);
                gotoxy(94,29);
                printf("%s",teacher[a.teach_index]);
                gotoxy(96,30);
                printf(" ");
            }

            else if((a.start==c.time10)&&(a.finish==c.time13))
            {

                gotoxy(108,26);
                printf(" ");
                gotoxy(108,27);
                printf(" ");
                gotoxy(105,28);
                printf("%s",a.course);
                gotoxy(108,29);
                printf("%s",teacher[a.teach_index]);
                gotoxy(108,30);
                printf(" ");

            }

            else if((a.start==c.time1)&&(a.finish==c.time4))
            {

                gotoxy(24,26);
                printf(" ");
                gotoxy(24,27);
                printf(" ");
                gotoxy(24,28);
                printf(" ");
                gotoxy(24,29);
                printf(" ");
                gotoxy(24,30);
                printf(" ");
                gotoxy(26,28);
                printf("%s",a.course);
                gotoxy(29,29);
                printf("%s",teacher[a.teach_index]);
                gotoxy(36,26);
                printf(" ");
                gotoxy(36,27);
                printf(" ");
                gotoxy(36,28);
                printf(" ");
                gotoxy(36,29);
                printf(" ");
                gotoxy(36,30);
                printf(" ");
            }

            else if((a.start==c.time2)&&(a.finish==c.time5))
            {

                gotoxy(24,26);
                printf(" ");
                gotoxy(24,27);
                printf(" ");
                gotoxy(24,28);
                printf(" ");
                gotoxy(24,29);
                printf(" ");
                gotoxy(24,30);
                printf(" ");
                gotoxy(26,28);
                printf("%s",a.course);
                gotoxy(29,29);
                printf("%s",teacher[a.teach_index]);
                gotoxy(36,26);
                printf(" ");
                gotoxy(36,27);
                printf(" ");
                gotoxy(36,28);
                printf(" ");
                gotoxy(36,29);
                printf(" ");
                gotoxy(36,30);
                printf(" ");
            }

            else if((a.start==c.time3)&&(a.finish==c.time7))
            {
                gotoxy(48,26);
                printf(" ");
                gotoxy(48,27);
                printf(" ");
                gotoxy(48,28);
                printf(" ");
                gotoxy(48,29);
                printf(" ");
                gotoxy(48,30);
                printf(" ");

                gotoxy(50,28);
                printf("%s",a.course);
                gotoxy(50,29);
                printf("%s",teacher[a.teach_index]);

                gotoxy(60,26);
                printf(" ");
                gotoxy(60,27);
                printf(" ");
                gotoxy(60,28);
                printf(" ");
                gotoxy(60,29);
                printf(" ");
                gotoxy(60,30);
                printf(" ");
            }
            else if((a.start==c.time4)&&(a.finish==c.time9))
            {
                gotoxy(60,26);
                printf(" ");
                gotoxy(60,27);
                printf(" ");

                gotoxy(60,30);
                printf(" ");
                gotoxy(56,28);
                printf("%s",a.course);
                gotoxy(59,29);
                printf("%s",teacher[a.teach_index]);

                gotoxy(85,28);
                printf("%s",a.course);
                gotoxy(85,29);
                printf("%s",teacher[a.teach_index]);

            }
            else if((a.start==c.time6)&&(a.finish==c.time11))
            {
                gotoxy(61,28);
                printf("%s",a.course);

                gotoxy(62,29);
                printf("%s",teacher[a.teach_index]);

                gotoxy(90,28);
                printf("%s",a.course);
                gotoxy(93,29);
                printf("%s",teacher[a.teach_index]);

                gotoxy(96,26);
                printf(" ");
                gotoxy(96,27);
                printf(" ");
                gotoxy(96,28);
                printf(" ");
                gotoxy(96,29);
                printf(" ");
                gotoxy(96,30);
                printf(" ");
            }
            else if((a.start==c.time8)&&(a.finish==c.time13))
            {
                gotoxy(96,26);
                printf(" ");
                gotoxy(96,27);
                printf(" ");
                gotoxy(96,28);
                printf(" ");
                gotoxy(96,29);
                printf(" ");
                gotoxy(96,30);
                printf(" ");

                gotoxy(98,28);
                printf("%s",a.course);
                gotoxy(98,29);
                printf("%s",teacher[a.teach_index]);
                gotoxy(108,26);
                printf(" ");
                gotoxy(108,27);
                printf(" ");

                gotoxy(108,28);
                printf(" ");
                gotoxy(108,29);
                printf(" ");
                gotoxy(108,30);
                printf(" ");

            }
        }

    }

}

void time_list(int y_axis)
{
    char *t,*t1,*t2,*t3,*t4,*t5,*t6,*t7,*t8,*t9,*t10,*t11,*t12,*t13,*t14,*t15,*t16;
    int i;
    t="SELECT YOUR TIME FROM HERE";
    t1="(a)(1) 9.00 A.M";
    t2="(2) 9.50 A.M";
    t3="(b)(2)9.50 A.M";
    t4="(3)10.35 A.M";
    t5="(c)(3)10.35 A.M";
    t6="(4)11.25 A.M";
    t7="(d)(4)11.25 A.M";
    t8="(5)12.15 P.M";
    t9="(e)(6)12.20 P.M";
    t10="(7)1.05 P.M";
    t11="(f)(8)2.00 P.M";
    t12="(9)2.45 P.M";
    t13="(g)(10)2.50 P.M";
    t14="(11)3.35 P.M";
    t15="(h)(12)3.40 P.M";
    t16="(13) 4.25 P.M";
    gotoxy(58,y_axis);
    i=0;
    while(t[i]!='\0')
    {
        printf("%c",t[i]);
        i++;
    }
    gotoxy(58,y_axis+2);
    printf("---------------------------------");

    gotoxy(58,y_axis+4);
    i=0;
    while(t1[i]!='\0')
    {
        printf("%c",t1[i]);
        i++;
    }

    gotoxy(71,y_axis+4);
    i=0;
    while(t2[i]!='\0')
    {
        printf("%c",t2[i]);
        i++;
    }
    gotoxy(58,y_axis+6);
    i=0;
    while(t3[i]!='\0')
    {
        printf("%c",t3[i]);
        i++;
    }
    gotoxy(71,y_axis+6);
    i=0;
    while(t4[i]!='\0')
    {
        printf("%c",t4[i]);
        i++;
    }
    gotoxy(58,y_axis+8);
    i=0;
    while(t5[i]!='\0')
    {
        printf("%c",t5[i]);
        i++;
    }
    gotoxy(71,y_axis+8);
    i=0;
    while(t6[i]!='\0')
    {
        printf("%c",t6[i]);
        i++;
    }
    gotoxy(58,y_axis+10);
    i=0;
    while(t7[i]!='\0')
    {
        printf("%c",t7[i]);
        i++;
    }
    gotoxy(71,y_axis+10);
    i=0;
    while(t8[i]!='\0')
    {
        printf("%c",t8[i]);
        i++;
    }
    gotoxy(58,y_axis+12);
    i=0;
    while(t9[i]!='\0')
    {
        printf("%c",t9[i]);
        i++;
    }
    gotoxy(71,y_axis+12);
    i=0;
    while(t10[i]!='\0')
    {
        printf("%c",t10[i]);
        i++;
    }
    gotoxy(58,y_axis+14);
    i=0;
    while(t11[i]!='\0')
    {
        printf("%c",t11[i]);
        i++;
    }
    gotoxy(71,y_axis+14);
    i=0;
    while(t12[i]!='\0')
    {
        printf("%c",t12[i]);
        i++;
    }
    gotoxy(58,y_axis+16);
    i=0;
    while(t13[i]!='\0')
    {
        printf("%c",t13[i]);
        i++;
    }

    gotoxy(71,y_axis+16);
    i=0;
    while(t14[i]!='\0')
    {
        printf("%c",t14[i]);
        i++;
    }

    gotoxy(58,y_axis+18);
    i=0;
    while(t15[i]!='\0')
    {
        printf("%c",t15[i]);
        i++;
    }
    gotoxy(71,y_axis+18);
    i=0;
    while(t16[i]!='\0')
    {
        printf("%c",t16[i]);
        i++;
    }
    i=0;
}

void del_routine(FILE *x)
{
    FILE* fptemp;
    list_view(x);
    j=j+2;
    getdata(x,j);
    rewind(x);

    while(fread(&a,sizeof(a),1,x)==1)
    {
        if(a.course==temp.course)
        {
            if((a.day==temp.day)&&(a.start==temp.start)&&(a.finish==temp.finish)&&(strcmp(a.teacher,temp.teacher)==0))
            {
                gotoxy(10,j+17);
                printf("Record available, You want to delete?(y/n)");
                if(getch()=='y')
                {
                    fptemp=fopen("test.dat","wb+");
                    rewind(x);
                    while(fread(&a,sizeof(a),1,x)==1)
                    {
                        if(!((a.day==temp.day)&& (a.start==temp.start)&&(a.finish==temp.finish)&&(a.course==temp.course)&&(strcmp(a.teacher,temp.teacher)==0)))
                        {
                            fseek(fptemp,0,SEEK_CUR);
                            fwrite(&a,sizeof(a),1,fptemp);
                        }
                    }
                    fclose(fptemp);
                    fclose(x);
                    int a= remove(filename);
                    int b=rename("test.dat",filename);
                    if(a==0&&b==0)
                    {
                        printf("\n\nsuccessful");
                    }
                    else
                    {
                        gotoxy(10,j+20);
                        printf("RECORD DELETED!!!!");
                    }
                    gotoxy(10,j+22);
                    printf("Press Any Key to go to mainmenu");
                    if(getch()) mainmenu();

                }

            }
        }
    }

}

void course_4th(int x_axis,int y_axis)
{
    int i;
    char *title,*CSE400,*CSE411,*CSE412,*CSE413,*CSE414,*CSE415,*CSE416,*MATH431,*STAT451;
    title="4TH SEMESTER COURSE TITLE & NO";
    CSE400="\xDB\xDB\xDB\xDB\xDB\xB2 1.CSE 400:Project on OOP language";
    CSE411="\xDB\xDB\xDB\xDB\xDB\xB2 2.CSE 411:Computer Algorithms";
    CSE412="\xDB\xDB\xDB\xDB\xDB\xB2 3.CSE 412:Computer Algorithms Lab";
    CSE413="\xDB\xDB\xDB\xDB\xDB\xB2 4.CSE 413:Database system";
    CSE414="\xDB\xDB\xDB\xDB\xDB\xB2 5.CSE 414:Database system Lab";
    CSE415="\xDB\xDB\xDB\xDB\xDB\xB2 6.CSE 415:Microprocessor & Micro Controller";
    CSE416="\xDB\xDB\xDB\xDB\xDB\xB2 7.CSE 416:Microprocessor & Micro Controller Lab";
    MATH431="\xDB\xDB\xDB\xDB\xDB\xB2 8.MATH 431: Numerical Analysis" ;
    STAT451="\xDB\xDB\xDB\xDB\xDB\xB2 6.STAT 451:Applied statistics" ;

    gotoxy(x_axis,y_axis);
    i=0;
    while(title[i]!='\0')
    {
        printf("%c",title[i]);
        i++;
    }

    gotoxy(x_axis,y_axis+4);
    i=0;
    while(CSE400[i]!='\0')
    {
        printf("%c",CSE400[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+6);
    i=0;
    while(CSE411[i]!='\0')
    {
        printf("%c",CSE411[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+8);
    i=0;
    while(CSE412[i]!='\0')
    {
        printf("%c",CSE412[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+10);
    i=0;
    while(CSE413[i]!='\0')
    {
        printf("%c",CSE413[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+12);
    i=0;
    while(CSE414[i]!='\0')
    {
        printf("%c",CSE414[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+14);
    i=0;
    while(CSE415[i]!='\0')
    {
        printf("%c",CSE415 [i]);
        i++;
    }
    gotoxy(x_axis,y_axis+16);
    i=0;
    while(CSE416[i]!='\0')
    {
        printf("%c",CSE416[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+18);
    i=0;
    while(MATH431[i]!='\0')
    {
        printf("%c",MATH431[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+20);
    i=0;
    while(STAT451[i]!='\0')
    {
        printf("%c",STAT451[i]);
        i++;
    }
    i=0;
}
void course_6th( int x_axis,int y_axis)
{
    char *title,*CSE600,*CSE611,*CSE612,*CSE613,*CSE614,*CSE615,*CSE616,*CSE617,*EEE621,*EEE622;
    int i;
    title="6TH SEMESTER COURSE CODE & TITLE";
    CSE600="\xDB\xDB\xDB\xDB\xDB\xB2 1.CSE 600:Project on Software Engineering & Information System Design";
    CSE611="\xDB\xDB\xDB\xDB\xDB\xB2 2.CSE 611:Computer Interfacting and Peripherals";
    CSE612="\xDB\xDB\xDB\xDB\xDB\xB2 3.CSE 612:Computer Interfacting and Peripherals Lab";
    CSE613="\xDB\xDB\xDB\xDB\xDB\xB2 4.CSE 613:Computer Networking";
    CSE614="\xDB\xDB\xDB\xDB\xDB\xB2 5.CSE 614:Computer Networking Lab";
    CSE615="\xDB\xDB\xDB\xDB\xDB\xB2 6.CSE 615:Web Engineering ";
    CSE616="\xDB\xDB\xDB\xDB\xDB\xB2 7.CSE 616:Web Engineering Lab";
    CSE617="\xDB\xDB\xDB\xDB\xDB\xB2 8.CSE 617:Theory of Computation" ;
    EEE621="\xDB\xDB\xDB\xDB\xDB\xB2 9.CSE 621:Communication engineering" ;
    EEE622="\xDB\xDB\xDB\xDB\xDB\xB2 10.EEE 622:Communication engineering Lab" ;

    gotoxy(x_axis,y_axis);
    i=0;
    while(title[i]!='\0')
    {
        printf("%c",title[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+4);
    i=0;
    while(CSE600[i]!='\0')
    {
        printf("%c",CSE600[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+6);
    i=0;
    while(CSE611[i]!='\0')
    {
        printf("%c",CSE611[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+8);
    i=0;
    while(CSE612[i]!='\0')
    {
        printf("%c",CSE612[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+10);
    i=0;
    while(CSE613[i]!='\0')
    {
        printf("%c",CSE613[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+12);
    i=0;
    while(CSE614[i]!='\0')
    {
        printf("%c",CSE614[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+14);
    i=0;
    while(CSE615[i]!='\0')
    {
        printf("%c",CSE615 [i]);
        i++;
    }
    gotoxy(x_axis,y_axis+16);
    i=0;
    while(CSE616[i]!='\0')
    {
        printf("%c",CSE616[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+18);
    i=0;
    while(CSE617[i]!='\0')
    {
        printf("%c",CSE617[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+20);
    i=0;
    while(EEE621[i]!='\0')
    {
        printf("%c",EEE621[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+22);
    i=0;
    while(EEE622[i]!='\0')
    {
        printf("%c",EEE622[i]);
        i++;
    }
    i=0;
}

void course_7th( int x_axis,int y_axis)
{
    char *title,*CSE700,*CSE711,*CSE712,*CSE713,*CSE714,*CSE715,*CSE716,*CSE717,*CSE718;
    int i;
    title="7TH SEMSTER COURSE TITLE & NO";
    CSE700="\xDB\xDB\xDB\xDB\xDB\xB2 1.CSE 700:Project/ Thesis";
    CSE711="\xDB\xDB\xDB\xDB\xDB\xB2 2.CSE 711:Compilers";
    CSE712="\xDB\xDB\xDB\xDB\xDB\xB2 3.CSE 712:Compilers Lab";
    CSE713="\xDB\xDB\xDB\xDB\xDB\xB2 4.CSE 713:Artificial Intelligence";
    CSE714="\xDB\xDB\xDB\xDB\xDB\xB2 5.CSE 714:Artificial Intelligence Lab";
    CSE715="\xDB\xDB\xDB\xDB\xDB\xB2 6.CSE 715:Machine learning ";
    CSE716="\xDB\xDB\xDB\xDB\xDB\xB2 7.CSE 716:Machine learning Lab";
    CSE717="\xDB\xDB\xDB\xDB\xDB\xB2 8.CSE 717:Option-1" ;
    CSE718="\xDB\xDB\xDB\xDB\xDB\xB2 9.CSE 718:Industrial Tour" ;

    gotoxy(x_axis,y_axis);
    i=0;
    while(title[i]!='\0')
    {
        printf("%c",title[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+4);
    i=0;
    while(CSE700[i]!='\0')
    {
        printf("%c",CSE700[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+6);
    i=0;
    while(CSE711[i]!='\0')
    {
        printf("%c",CSE711[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+8);
    i=0;
    while(CSE712[i]!='\0')
    {
        printf("%c",CSE712[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+10);
    i=0;
    while(CSE713[i]!='\0')
    {
        printf("%c",CSE713[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+12);
    i=0;
    while(CSE714[i]!='\0')
    {
        printf("%c",CSE714[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+14);
    i=0;
    while(CSE715[i]!='\0')
    {
        printf("%c",CSE715 [i]);
        i++;
    }
    gotoxy(x_axis,y_axis+16);
    i=0;
    while(CSE716[i]!='\0')
    {
        printf("%c",CSE716[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+18);
    i=0;
    while(CSE717[i]!='\0')
    {
        printf("%c",CSE717[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+20);
    i=0;
    while(CSE718[i]!='\0')
    {
        printf("%c",CSE718[i]);
        i++;
    }
    i=0;

}

void course_8th( int x_axis,int y_axis)
{
    char *title,*CSE800,*CSE811,*CSE812,*CSE813,*CSE814,*CSE815,*CSE816,*CSE817;
    int i;
    title="8TH SEMESTER COURSE TITLE & NO";
    CSE800="\xDB\xDB\xDB\xDB\xDB\xB2 1.CSE 800:Project/ Thesis";
    CSE811="\xDB\xDB\xDB\xDB\xDB\xB2 2.CSE 811:Digital Image Processing";
    CSE812="\xDB\xDB\xDB\xDB\xDB\xB2 3.CSE 812:Digital Image Processing Lab";
    CSE813="\xDB\xDB\xDB\xDB\xDB\xB2 4.CSE 813:Computer Graphics";
    CSE814="\xDB\xDB\xDB\xDB\xDB\xB2 5.CSE 814:Computer Graphics Lab";
    CSE815="\xDB\xDB\xDB\xDB\xDB\xB2 6.CSE 815:Optical Fiber Communication ";
    CSE816="\xDB\xDB\xDB\xDB\xDB\xB2 7.CSE 816:Optical Fiber Communication Lab";
    CSE817="\xDB\xDB\xDB\xDB\xDB\xB2 8.CSE 817:Option-2" ;

    gotoxy( x_axis,y_axis);
    i=0;
    while(title[i]!='\0')
    {
        printf("%c",title[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+4);
    i=0;
    while(CSE800[i]!='\0')
    {
        printf("%c",CSE800[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+6);
    i=0;
    while(CSE811[i]!='\0')
    {
        printf("%c",CSE811[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+8);
    i=0;
    while(CSE812[i]!='\0')
    {
        printf("%c",CSE812[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+10);
    i=0;
    while(CSE813[i]!='\0')
    {
        printf("%c",CSE813[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+12);
    i=0;
    while(CSE814[i]!='\0')
    {
        printf("%c",CSE814[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+14);
    i=0;
    while(CSE815[i]!='\0')
    {
        printf("%c",CSE815 [i]);
        i++;
    }
    gotoxy(x_axis,y_axis+16);
    i=0;
    while(CSE816[i]!='\0')
    {
        printf("%c",CSE816[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+18);
    i=0;
    while(CSE817[i]!='\0')
    {
        printf("%c",CSE817[i]);
        i++;
    }
    i=0;
}

void course_5th( int x_axis,int y_axis)
{
    char *title,*CSE500,*CSE511,*CSE512,*CSE513,*CSE514,*CSE515,*CSE516,*CSE517,*ECCON581,*ACCO591;
    int i;
    title="5TH SEMESTER COURSE TITLE & NO";
    CSE500="\xDB\xDB\xDB\xDB\xDB\xB2 1.CSE 500:Project on Database System";
    CSE511="\xDB\xDB\xDB\xDB\xDB\xB2 2.CSE 511:Operating System";
    CSE512="\xDB\xDB\xDB\xDB\xDB\xB2 3.CSE 512:Operating System Lab";
    CSE513="\xDB\xDB\xDB\xDB\xDB\xB2 4.CSE 513:Data Communication";
    CSE514="\xDB\xDB\xDB\xDB\xDB\xB2 5.CSE 514:Data communication Lab";
    CSE515="\xDB\xDB\xDB\xDB\xDB\xB2 6.CSE 515:Software Engineering & Information System Design";
    CSE516="\xDB\xDB\xDB\xDB\xDB\xB2 7.CSE 516:Software Engineering & Information System Design Lab";
    CSE517="\xDB\xDB\xDB\xDB\xDB\xB2 8.CSE 517: Computer Architecture" ;
    ECCON581="\xDB\xDB\xDB\xDB\xDB\xB2 9.ECON 581:Ecconomics" ;
    ACCO591="\xDB\xDB\xDB\xDB\xDB\xB2 10.ACCO:Principal of Accounting & Management" ;

    gotoxy(x_axis,y_axis);
    i=0;
    while(title[i]!='\0')
    {
        printf("%c",title[i]);
        i++;
    }

    gotoxy(x_axis,y_axis+4);
    i=0;
    while(CSE500[i]!='\0')
    {
        printf("%c",CSE500[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+6);
    i=0;
    while(CSE511[i]!='\0')
    {
        printf("%c",CSE511[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+8);
    i=0;
    while(CSE512[i]!='\0')
    {
        printf("%c",CSE512[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+10);
    i=0;
    while(CSE513[i]!='\0')
    {
        printf("%c",CSE513[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+12);
    i=0;
    while(CSE514[i]!='\0')
    {
        printf("%c",CSE514[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+14);
    i=0;
    while(CSE515[i]!='\0')
    {
        printf("%c",CSE515 [i]);
        i++;
    }
    gotoxy(x_axis,y_axis+16);
    i=0;
    while(CSE516[i]!='\0')
    {
        printf("%c",CSE516[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+18);
    i=0;
    while(CSE517[i]!='\0')
    {
        printf("%c",CSE517[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+20);
    i=0;
    while(ECCON581[i]!='\0')
    {
        printf("%c",ECCON581[i]);
        i++;
    }
    gotoxy(x_axis,y_axis+22);
    i=0;
    while(ACCO591[i]!='\0')
    {
        printf("%c",ACCO591[i]);
        i++;
    }
    i=0;
}

void teacher_list(int n)
{
    system("cls");
    gotoxy(20,4);
    printf("\xDB\xDB\xDB\xDB\xB2\xB2 1.Teachers of the CSE Department");
    gotoxy(20,6);
    printf("\xDB\xDB\xDB\xDB\xB2\xB2 2.Guest Teachers");
    gotoxy(20,8);
    printf("\xDB\xDB\xDB\xDB\xB2\xB2 3.Main Menu");
    gotoxy(15,10);
    printf("Enter your choice:");
    scanf("%d",&s);
    if(n==1)
    {
        switch(s)
        {
        case 1:
            teacher_dept();
            returnfunc(1);
            break;
        case 2:
            guest_teacher();
            returnfunc(1);
            break;
        case 3:
            mainmenu();
            break;
        default:
            gotoxy(10,23);
            printf("\aWrong Entry!!Please re-enter correct option.Press any key...then enter your choice.");
            if(getch())
                teacher_list(1);
        }
    }
    if(n==2)
    {
        switch(s)
        {
        case 1:
            teacher_dept();
            returnfunc(2);
            break;
        case 2:
            guest_teacher();
            returnfunc(2);
            break;
        case 3:
            student_mainmenu();
            break;
        default:
            gotoxy(10,23);
            printf("\aWrong Entry!!Please re-enter correct option.Press any key...then enter your choice.");
            if(getch())
                teacher_list(2);
        }
    }
}

void teacher_dept()
{
    int i;
    char *name, *teacher1,*teacher2,*teacher3,*teacher4,*teacher5,*teacher6,*teacher7,*teacher8,*teacher9,*teacher10,*teacher11,*teacher12,*teacher13;

    name=    "|----------------------------------------------------|\n                    |     Name                    |    Designation       |";
    teacher1="|----------------------------------------------------|\n                    |Mr.Dr.Md. Shahadat Hossain   |Professor             |";
    teacher2="|----------------------------------------------------|\n                    |Mr.Dr.Mohammad Khairul Islam |Associate Professor   |";
    teacher3="|----------------------------------------------------|\n                    |Mr.Dr. Mohammad Osiur Rahman |Associate Professor   |";
    teacher4="|----------------------------------------------------|\n                    |Mr.Dr. Muhammad Anowarul Azim|Associate Professor   |";
    teacher5="|----------------------------------------------------|\n                    | Mr.Rezaul Karim             |Assistant Professor   |";
    teacher6="|----------------------------------------------------|\n                    | Mr.Fahim Irfan Alam         |Assistant Professor   |";
    teacher7="|----------------------------------------------------|\n                    | Mrs. Farah Jahan            |Assistant Professor   |";
    teacher8="|----------------------------------------------------|\n                    | Mr.Rudra Pratap Debnath     |Lecturer              |";
    teacher9="|----------------------------------------------------|\n                    | Mrs. Nasrin Sultana         |Lecturer              |";
    teacher10="|----------------------------------------------------|\n                    |Ms. Shima Chakrabarty        |Lecturer              |";
    teacher11="|----------------------------------------------------|\n                    |Mr. A.H.M. Sajedul Hoque     |Lecturer              |";
    teacher12="|----------------------------------------------------|\n                    |Mr. Atiqur Rahman            |Lecturer              |";
    teacher13="|----------------------------------------------------|\n                    |Mr. Md.Mahbubul Islam        |Lecturer              |\n                    |----------------------------------------------------|";

    system("cls");
    gotoxy(25,2);
    printf("TEACHERS NAME WITH DESIGNATION OF CSE DEPARTMENT");
    gotoxy(15,3);
    printf("----------------------------------------------------------------------");
    gotoxy(20,5);
    i=0;
    while(name[i]!='\0')
    {
        printf("%c",*(name+i));
        i++;
    }
    gotoxy(20,7);
    i=0;
    while(teacher1[i]!='\0')
    {
        printf("%c",*(teacher1+i));
        i++;
    }
    gotoxy(20,9);
    i=0;
    while(teacher2[i]!='\0')
    {
        printf("%c",*(teacher2+i));
        i++;
    }
    gotoxy(20,11);
    i=0;
    while(teacher3[i]!='\0')
    {
        printf("%c",*(teacher3+i));
        i++;
    }
    gotoxy(20,13);
    i=0;
    while(teacher4[i]!='\0')
    {
        printf("%c",*(teacher4+i));
        i++;
    }
    gotoxy(20,15);
    i=0;
    while(teacher5[i]!='\0')
    {
        printf("%c",*(teacher5+i));
        i++;
    }
    gotoxy(20,17);
    i=0;
    while(teacher6[i]!='\0')
    {
        printf("%c",*(teacher6+i));
        i++;
    }
    gotoxy(20,19);
    i=0;
    while(teacher7[i]!='\0')
    {
        printf("%c",*(teacher7+i));
        i++;
    }
    gotoxy(20,21);
    i=0;
    while(teacher8[i]!='\0')
    {
        printf("%c",*(teacher8+i));
        i++;
    }
    gotoxy(20,23);
    i=0;
    while(teacher9[i]!='\0')
    {
        printf("%c",*(teacher9+i));
        i++;
    }
    gotoxy(20,25);
    i=0;
    while(teacher10[i]!='\0')
    {
        printf("%c",*(teacher10+i));
        i++;
    }
    gotoxy(20,27);
    i=0;
    while(teacher11[i]!='\0')
    {
        printf("%c",*(teacher11+i));
        i++;
    }
    gotoxy(20,29);
    i=0;
    while(teacher12[i]!='\0')
    {
        printf("%c",*(teacher12+i));
        i++;
    }
    gotoxy(20,31);
    i=0;
    while(teacher13[i]!='\0')
    {
        printf("%c",*(teacher13+i));
        i++;
    }


}

void course_select(int n)
{
    system("cls");
    gotoxy(25,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT A SEMESTER\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,5);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 1.1st Semester");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 2.2nd Semester");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 3.3rd Semester");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 4.4th Semester");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 5.5th Semester");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 6:6th Semester");
    gotoxy(20,17);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 7.7th Semester");
    gotoxy(20,19);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 8.8th Semester");
    gotoxy(20,21);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 9.Main menu");
    gotoxy(20,23);
    printf("Enter your choice: ");
    if(n==1)
    {
        switch(getch())
        {
        case '1':
            system("cls");
            course_1st(20,3);
            returnfunc(1);
            break;
        case '2':
            system("cls");
            course_2nd(20,3);
            returnfunc(1);
            break;
        case '3':
            system("cls");
            course_3rd(20,3);
            returnfunc(1);
            break;
        case '4':
            system("cls");
            course_4th(20,3);
            returnfunc(1);
            break;
        case '5':
            system("cls");
            course_5th(20,3);
            returnfunc(1);
            break;
        case '6':
            system("cls");
            course_6th(20,3);
            returnfunc(1);
            break;
        case '7':
            system("cls");
            course_7th(20,3);
            returnfunc(1);
            break;
        case '8':
            system("cls");
            course_8th(20,3);
            returnfunc(1);
            break;
        case '9':
            mainmenu();
            break;
        }
    }
    if(n==2)
    {
        switch(getch())
        {
        case '1':
            system("cls");
            course_1st(20,3);
            returnfunc(2);
            break;
        case '2':
            system("cls");
            course_2nd(20,3);
            returnfunc(2);
            break;
        case '3':
            system("cls");
            course_3rd(20,3);
            returnfunc(2);
            break;
        case '4':
            system("cls");
            course_4th(20,3);
            returnfunc(2);
            break;
        case '5':
            system("cls");
            course_5th(20,3);
            returnfunc(2);
            break;
        case '6':
            system("cls");
            course_6th(20,3);
            returnfunc(2);
            break;
        case '7':
            system("cls");
            course_7th(20,3);
            returnfunc(2);
            break;
        case '8':
            system("cls");
            course_8th(20,3);
            returnfunc(2);
            break;
        case '9':
            student_mainmenu();
            break;
        }
    }

}

void guest_teacher()
{
    int i;
    char *name, *teacher1,*teacher2,*teacher3,*teacher4,*teacher5,*teacher6,*teacher7,*teacher8,*teacher9,*teacher10,*teacher11,*teacher12,*teacher13;

    name=    "|-------------------------------------------------------------------------|\n        |     Name                 |    Designation     |      Department         |";
    teacher1="|-------------------------------------------------------------------------|\n        |Mr.Mohammad Didarul Alam  |     Lecturer       |      APECE              |";
    teacher2="|-------------------------------------------------------------------------|\n        |Mr. Mohammad Mohsin       |     Lecturer       |      Physics            |";
    teacher3="|-------------------------------------------------------------------------|\n        |Mr.Dr.Mohammad Nasir Uddin     | Associate Professor|      Chemistry     |";
    teacher4="|-------------------------------------------------------------------------|\n        |Mr. Rejaul Karim          | Assistant Professor|      Physics            |";
    teacher5="|-------------------------------------------------------------------------|\n        | Mr. Md. Idris Mia         |    Professor       |      Physics           |";
    teacher6="|-------------------------------------------------------------------------|\n        |Mr. Jamal Uddin Ahmad      |    Professor       |      APECE             |";
    teacher7="|-------------------------------------------------------------------------|\n        |Mr.Dr.Rabindrnath Shil       |    Professor       |      Statistics      |";
    teacher8="|-------------------------------------------------------------------------|\n        | Mr.Dr.Qamrul Islam         |    Professor       |      Mathmatics       | \n        |----------------------------------------------------------------|";
    teacher9="|-------------------------------------------------------------------------|\n        ";

    system("cls");
    gotoxy(35,3);
    printf("GUEST TEACHERS");
    gotoxy(26,4);
    printf("------------------------------------");

    gotoxy(8,8);
    i=0;
    while(name[i]!='\0')
    {
        printf("%c",*(name+i));
        i++;
    }
    gotoxy(8,10);
    i=0;
    while(teacher1[i]!='\0')
    {
        printf("%c",*(teacher1+i));
        i++;
    }
    gotoxy(8,12);
    i=0;
    while(teacher2[i]!='\0')
    {
        printf("%c",*(teacher2+i));
        i++;
    }
    gotoxy(8,14);
    i=0;
    while(teacher3[i]!='\0')
    {
        printf("%c",*(teacher3+i));
        i++;
    }
    gotoxy(8,16);
    i=0;
    while(teacher4[i]!='\0')
    {
        printf("%c",*(teacher4+i));
        i++;
    }
    gotoxy(8,18);
    i=0;
    while(teacher5[i]!='\0')
    {
        printf("%c",*(teacher5+i));
        i++;
    }
    gotoxy(8,20);
    i=0;
    while(teacher6[i]!='\0')
    {
        printf("%c",*(teacher6+i));
        i++;
    }
    gotoxy(8,22);
    i=0;
    while(teacher7[i]!='\0')
    {
        printf("%c",*(teacher7+i));
        i++;
    }
    gotoxy(8,24);
    i=0;
    while(teacher8[i]!='\0')
    {
        printf("%c",*(teacher8+i));
        i++;
    }
    gotoxy(8,26);
    i=0;
    while(teacher9[i]!='\0')
    {
        printf("%c",*(teacher9+i));
        i++;
    }
}

void select_semester(int n)
{
    FILE *fp;
    system("cls");
    gotoxy(15,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT A SEMESTER\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(15,5);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 1.1st Semester");
    gotoxy(15,7);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 2.2nd Semester");
    gotoxy(15,9);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 3.3rd Semester");
    gotoxy(15,11);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 4.4th Semester");
    gotoxy(15,13);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 5.5th Semester");
    gotoxy(15,15);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 6:6th Semester");
    gotoxy(15,17);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 7.7th Semester");
    gotoxy(15,19);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 8.8th Semester");
    gotoxy(15,21);
    printf("\xDB\xDB\xDB\xDB\xDB\xB2 9.Main menu");
    gotoxy(15,23);
    printf("Enter your choice: ");
    scanf("%d",&s);
    switch(s)
    {
    case 1:
        fp=fopen("1st semester.dat","rb+");
        filename="1st semester.dat";
        strcpy(temp.year,"1st");
        break;
    case 2:
        fp=fopen("2nd semester.dat","rb+");
        filename="2nd semester.dat";
        strcpy(temp.year,"2nd");
        break;
    case 3:
        fp=fopen("3rd semester.dat","rb+");
        filename="3rd semester.dat";
        strcpy(temp.year,"3rd");
        break;
    case 4:
        fp=fopen("4th semester.dat","rb+");
        filename="4th semester.dat";
        strcpy(temp.year,"4th");
        break;
    case 5:
        fp=fopen("5th semester.dat","rb+");
        filename="5th semester.dat";
        strcpy(temp.year,"5th");
        break;
    case 6:
        fp=fopen("6th semester.dat","rb+");
        filename="6th semester.dat";
        strcpy(temp.year,"6th");
        break;
    case 7:
        fp=fopen("7th semester.dat","rb+");
        filename="7th semester.dat";
        strcpy(temp.year,"7th");
        break;
    case 8:
        fp=fopen("8th semester.dat","rb+");
        filename="8th semester.dat";
        strcpy(temp.year,"8th");
        break;
    case 9:
    {
        if(n==1||n==2||n==3)
            mainmenu();
        else if(n==4)
            student_mainmenu();
    }
    break;
    }
    if(n==1)
    {
        department_teacher(fp);
        fclose(fp);
    }
    else if(n==2)
    {
        viewroutine(fp,1);
        fclose(fp);
    }
    else if(n==3)
    {
        del_routine(fp);
        fclose(fp);
    }
    else if(n==4)
    {
        viewroutine(fp,2);
        fclose(fp);
    }
}


