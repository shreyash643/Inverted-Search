#include"head.h"

int x=0;

int main(int argc,char*argv[])
{

    Flist *head=NULL;
    Hlist arr[27];
    for(int i=0;i<27;i++)
    {
        arr[i].index=i;
        arr[i].link=NULL;
    }
    valid(argc,argv,&head);


    int option;

    while (1)
    {
       
        printf(BLUE"-----------------------------------------------------\n"RESET);
        printf(MAGENTA"                        Menu \n"RESET);
        printf(BLUE"-----------------------------------------------------\n"RESET);
        printf(CYAN" 1. Create DATABASE📖\n"RESET);
        printf(CYAN" 2. Display Database🖥️\n"RESET);
        printf(CYAN" 3. Update DATABASE🆙\n"RESET);
        printf(CYAN" 4. Search🔎\n"RESET);
        printf(CYAN" 5. Save Database🔃\n"RESET);
        printf(CYAN" 6. Exit\n"RESET);
        printf(BLUE"-----------------------------------------------------\n"RESET);
        printf(YELLOW"Enter your choice: "RESET);

       
        
        while(scanf("%d",&option)!=1)
        {

            printf(RED"Invalid Inpunt ! Enter the number :\n"RESET);
            while(getchar()!='\n');
        
            continue;
        }
        
        printf(BLUE"-----------------------------------------------------\n"RESET);

        switch (option)
        {
            case 1:
            {
                if(x==1)
                {
                    printf(RED"DATA BASE already created\n"RESET);
                    break;
                }
                for(int i=0;i<27;i++)
                {
                    arr[i].index=i;
                    arr[i].link=NULL;
                }
                if(create_database(head,arr)==FAILURE)
                {
                    printf(RED"DATA BASE creation failed ⛔\n"RESET);
                }
                else
                {
                    printf(GREEN"DATA BASE created successfull ✅\n"RESET);
                    x=1;
                }

                break;
            }
            case 2:
            {
                Display(arr);
                break;
            }
            case 3:
            {

                if(x==0)
                {
                    printf(RED"DATA BASE not created ⛔\n"RESET);
                    break;
                }
                char str[50];

                printf(YELLOW"Enter the File Name:"RESET);
                scanf(" %[^\n]",str);

                Flist*temp=NULL;
                
                if(fv(str,&head,&temp))
                {
                        if(create_database(temp,arr)==FAILURE)
                    {
                        printf(RED"\nDATA BASE update failed ⛔\n"RESET);
                    }
                    else
                    {
                        printf(GREEN"\nDATA BASE updated successfull ✅\n"RESET);
                    }

                }
                
                break;
            }
            case 4:
            {
                char name[100];
                printf(YELLOW"Enter the word:"RESET);
                scanf(" %s",name);
               

                 search(name,arr);
                break;
            }
            case 5:
            {
                char str[50];
                printf(YELLOW"Enter the File name:"RESET);
                scanf(" %s",str);
                Save(arr,str);
                printf(GREEN"\nDATA BASE saved to File ✅\n"RESET);
                break;
            }
            case 6:
            {
                return 0;
                break;
            }
            default:
            {
                printf(RED"\n\t\tEnter valid option ⛔\n\n"RESET);
                break;
            }
        }
    }
    
}



