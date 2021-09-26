#include<stdio.h>
#include<string.h>
#include<conio.h>

//Fetches password from book text & cipher and copies it into password[]
void fetchps(int cp[10][2], char password[]);

//Takes user's input for current cipher and copies it into ps[10][2] and currentcipher.txt file
void inputcipher(int cp[10][2]);

//Checks password from user input against ps[], returns flag value 0 for correct password
int securelogin();

//Asks for password confirmation, changes password
void changepassword(char ps[]);

void main()
{
    int menu = 0;
    while(menu==0)
    {   
        char password[10]; 
        int cp[10][2];
        int count, flag=0;
        for(count=0; count<3; count++)
            {
                flag=securelogin();
                if(flag==0)
                    {
                        printf("Correct password!!!");
                        getch();
                        break;
                    }
                printf("Incorrect password!\n%d more tries\n", 2-count);
                if(count>=2)
                    return;
            }
        //printf("All good");
        
    }
}

void fetchps(int cp[10][2], char password[])
{
    FILE *fp;
    fp = fopen("book1.txt", "r");
    char temp, bookline[1000];
    for(int j=0; j<10; j++)
    {
        for(int i=0; i<cp[j][0]; i++)
        {
            fgets(bookline, 1000, fp);
            password[i] = bookline[cp[j][1]];
        }       
    }
    //printf("%s", &bookline);
    fclose(fp);
}

void inputcipher(int cp[10][2])
{
    FILE *fp;
    fp = fopen("currentcipher.txt", "w");
    printf("Input the cipher:\n");
    for(int i=0; i<10; i++)
    {
        scanf("%d%d", &cp[i][0], &cp[i][1]);
        fputc(cp[i][0], fp);
        fputc(cp[i][1], fp);
    }
    fclose(fp);
}

int securelogin()
{   
    int flag;
    char ips[11], fps[11];
    printf("Enter your password: ");
    scanf("%s", &ips);
    FILE *fp;
    fp=fopen("currentpassword.txt", "r");
    fgets(fps, 11, fp);
    fclose(fp);
    //printf("\nfile input: %s\n", fps);
    //printf("\nuser input: %s\n", ips);
    if(strcmp(ips, fps)==0)
        flag=0;
    else
        flag=1;
    return flag;   
}

void changepassword(char ps[])
{
    char userpass[10];
    printf("Confirm current password: ");
    scanf("%s", &userpass);
    if(strcmp(userpass, ps))
    {   
        printf("Enter new password: ");
        scanf("%s", &userpass);
        strcpy(ps, userpass);
        FILE *fp;
        fp=fopen("currentpassword.txt", "w");
        fputs(ps, fp);
        fclose(fp);
    }
    else
    {
        printf("Wrong password!");
    }

}