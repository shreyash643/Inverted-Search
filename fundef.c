#include"head.h"


int fv(char*str,Flist**head,Flist**temp)
{
    
            if(strstr(str,".txt")==NULL)
            {
                printf(RED"Wrong file extension ❌\n"RESET);
                return 0;
            }

            FILE*fptr=fopen(str,"r");
            if(fptr==NULL)
            {

                printf(RED"%s is not present in the directory ⛔\n"RESET,str);
                return 0;
            }
            fseek(fptr,0,SEEK_END);
            if(ftell(fptr)==0)
            {
                printf(RED"%s is empty ⛔\n"RESET,str);
                return 0;
            }
            rewind(fptr);
            fclose(fptr);

            int res=insert_last(head,str);
            if(res!=SUCCESS)
            {
                if(res==FULL)
                {
                   
                    return 0;
                }
                else if(res==DUPLICATE)
                {
                  printf(RED"%s this file is already added in directory this one is Duplicate of that ❌\n"RESET,str);
                }
                return 0;

            }
            insert_last(temp,str);
            return 1;
}


void valid(int argc,char** argv,Flist**head)
{

    for(int i=1;i<argc;i++)
    {

            if(strstr(argv[i],".txt")==NULL)
            {
                printf(RED"Wrong file extension ❌\n"RESET);
                continue;
            }

            FILE*fptr=fopen(argv[i],"r");
            if(fptr==NULL)
            {

                printf(RED"%s is not present in the directory ⛔\n"RESET,argv[i]);
                continue;
            }
            fseek(fptr,0,SEEK_END);
            if(ftell(fptr)==0)
            {
                printf(RED"%s is empty ⛔\n"RESET,argv[i]);
                continue;
            }
            rewind(fptr);
            fclose(fptr);

            int res=insert_last(head,argv[i]);
            if(res!=SUCCESS)
            {
                if(res==FULL)
                {
                    return;
                }
                else if(res==DUPLICATE)
                {
                  printf(RED"%s this file is already added in directory this one is Duplicate of that ❌\n"RESET,argv[i]);
                }
                continue;

            }
    }

}

/******************************************************************************************************************************************** */

int insert_last(Flist**head,const char*str)
{

    Flist*new=malloc(sizeof(Flist));
     if(new==NULL) 
    {
        printf(RED"Heap memory is full ⛔\n"RESET);
       return FULL;
    }
    new->link=NULL;
    strcpy(new->file,str);

        if(*head==NULL)
        {
           
            *head=new;
            return SUCCESS;
        }

        Flist*temp=*head;

        while(temp->link!=NULL)
        {
            if(strcmp(temp->file, str) == 0)
            {
                free(new);
                return DUPLICATE;
            }
            else
            {
              temp=temp->link;
            }
        }
        
           if(strcmp(temp->file, str) == 0)
            {      
                 free(new);
                return DUPLICATE;
            }
            else // sending that string to the function for 
            {
              temp->link=new;
                return SUCCESS;
            }

        
}

/******************************************************************************************************************************************** */

void print(Flist *head)
{
	if (head == NULL)
	{
		printf(RED"INFO : List is empty ⛔\n"RESET);
	}
    else
    {
	    while (head)		
	    {
		    printf("%s -> ", head->file);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
}

/*********************************************************************************************************************************************/

int create_database(Flist*head,Hlist*arr)
{

    if(head==NULL)                   // if the files linked list is empty than return
    {
        printf(RED"File not found ⛔\n"RESET);   
        return FAILURE;
    }
    
    char str[200];
    Flist*temp=head;
    
   

    while (temp!=NULL)                                  // runing linked list till null  
    {
        FILE*fptr=fopen(temp->file,"r");            // taking nodes file name and opening that in reading mode

        while(fscanf(fptr,"%199s",str)!=EOF)        // taking single single word and storing that inside a string 
        {
          
          if(insert_word(arr,str,temp->file)==FAILURE)  
          {
            return FAILURE;
          }

            
        }

        fclose(fptr);
        temp=temp->link;
    }
     return SUCCESS;
    
}

/******************************************************************************************************************************************************************/

int get_index(char ch)     // this function gives the index number as per character if that is not in range between a to z that time it will returns the 26
{
    if(ch>='a'&& ch<='z')
     {
        return ch-'a';   
     }
     else
     {
       return 26;
     }
}

/******************************************************************************************************************************************************************/

int insert_word(Hlist*arr,char *str,char *filen)
{
    
    char ch=str[0];
    int index = get_index(tolower(ch));         //before passing the character we are converting that charecter to small letter


    if(arr[index].link==NULL)                   // if index -> link is null than we are going create the mnode and snode and add in that link with mnode 
    {
        Slist*sub=malloc(sizeof(Slist));
        if(sub==NULL)
        {
            return FAILURE;
        }
        sub->count=1;
        strcpy(sub->fname,filen);
        sub->snext=NULL;


        Mlist*newn=malloc(sizeof(Mlist));
        if(newn==NULL)
        {
            return FAILURE;
        }
        newn->fcount=1;
        newn->next=NULL;
        newn->slink=sub;
        strcpy(newn->word,str);

        arr[index].link=newn;

        return SUCCESS;                     // after adding node to link part we are just going to return 
    }

        Mlist*temp=arr[index].link;   // taking temp variable to to traverse in Mlist cheacking for given string 

        while(temp->next!=NULL)    //this loop runs till last node when it reaches at last this loop get exited   
        {
            
            if(strcasecmp(temp->word,str)==0)  //cheacking the mlist word with given string if founded than we are going next
            {
                findsub(&temp,filen);    //here we are going to SList 
               
                return SUCCESS;
            }

            temp=temp->next;
        }

          if(strcasecmp(temp->word,str)==0)  //we checking mannual if last node have given string or not if found than we are going to add word in file
            {
                findsub(&temp,filen);  // if node->word matches with string that time we are ging to check the Slist 
                 
                return SUCCESS;  
            }

       
             
             Slist*sub=malloc(sizeof(Slist));
            if(sub==NULL)
            {
                return FAILURE;
            }
            sub->count=1;
            strcpy(sub->fname,filen);
            sub->snext=NULL;


            Mlist*newn=malloc(sizeof(Mlist));
            if(newn==NULL)
            {
                return FAILURE;
            }
            newn->fcount=1;
            newn->next=NULL;
            newn->slink=sub;
            strcpy(newn->word,str);

            temp->next=newn;
            
            return SUCCESS; 
}

/*********************************************************************************************************************************************************************************/

  int findsub(Mlist**head,char*str)  // in this function we are going to cheack for filename in Slist 
  {

    
    Slist *temp = (*head)->slink;

    
    while (temp != NULL)
    {
      
        if (strcasecmp(temp->fname, str) == 0)
        {
            temp->count++;          
            return SUCCESS;
        }

       
        if (temp->snext == NULL)
        {
            break;
        }

        temp = temp->snext;
    }

    
    Slist *newsub = malloc(sizeof(Slist));
    if (newsub == NULL)
    {
        return FAILURE;
    }
    newsub->count = 1;
    strcpy(newsub->fname, str);
    newsub->snext = NULL;

   
    temp->snext = newsub;
    (*head)->fcount=(*head)->fcount+1;

    return SUCCESS;
}
/*********************************************************************************************************************************************************************************/  
 void Display(Hlist *arr)
{
    int ci = 1;
    int emp=1;


    for(int i=0;i<27;i++)
    {
             if (arr[i].link != NULL)
             {
                emp=0;
                 break;
             }
    }

    if(emp==1)
    {
        printf(RED"\n\t\tDATA BASE is empty ⛔\n\n"RESET);
        return;
    }

    printf(BLUE"\n**************** INVERTED INDEX ******************\n"RESET);
    printf(MAGENTA"Index | Word | File Count\n"RESET);
    printf(BLUE"-------------------------------------------------\n"RESET);


    for (int i = 0; i < 27; i++)
    {
        if (arr[i].link != NULL)
        {
           Mlist *mtemp = arr[i].link;


            while (mtemp != NULL)
            {
                printf("%d | %s | %d\n\n", ci, mtemp->word, mtemp->fcount);
                ci++;


                Slist *stemp = mtemp->slink;
                while (stemp != NULL)
                {
                    printf(MAGENTA"  | File Name: %s Word Count: %d\n"RESET, stemp->fname, stemp->count);
                    stemp = stemp->snext;
                }


                printf(BLUE"-------------------------------------------------\n"RESET);
                mtemp = mtemp->next;
            }
        }
    }
}

/*********************************************************************************************************************************************************************************/

void Save(Hlist*arr,char*str)
{

    int ci = 1;
    int emp=1;


    for(int i=0;i<27;i++)
    {
             if (arr[i].link != NULL)
             {
                emp=0;
                 break;
             }
    }

    if(emp==1)
    {
        printf(RED"\n\t\tDATA BASE is empty ⛔\n\n"RESET);
        return;
    }

     FILE *fptr = fopen(str, "w");

        fprintf(fptr, "**************** INVERTED INDEX ******************\n");
        fprintf(fptr, "Index | Word | File Count\n");
        fprintf(fptr, "-------------------------------------------------\n");
    

     for (int i = 0; i < 27; i++)
    {
        if (arr[i].link != NULL)
        {
           Mlist *mtemp = arr[i].link;


            while (mtemp != NULL)
            {
                
                fprintf(fptr, "# %d | %s | %d\n\n",ci, mtemp->word, mtemp->fcount);
                ci++;


                Slist *stemp = mtemp->slink;
                while (stemp != NULL)
                {
                     fprintf(fptr,"  | File Name: %s Word Count: %d\n", stemp->fname, stemp->count);
                    stemp = stemp->snext;
                }


               fprintf(fptr, "-------------------------------------------------#\n");
                mtemp = mtemp->next;
            }
        }
          
    }
     fclose(fptr);
  
}

/*********************************************************************************************************************************************************************************/

void search(char*name,Hlist*arr)
{
    char ch=name[0];
    int index = get_index(tolower(ch)); 

    if(arr[index].link==NULL)
    {
        printf(RED"\nEntered word is not found in the DATA BASE \n"RESET);
        return;
    }



           Mlist *mtemp = arr[index].link;


            while (mtemp != NULL)
            {
                if(strcasecmp(mtemp->word,name)==0)
                {
                        Slist *stemp = mtemp->slink;
                        printf(MAGENTA"\t%s found in\n"RESET,name);
                    while (stemp != NULL)
                    {
                        printf(MAGENTA"  | File Name: %s Word Count: %d\n"RESET, stemp->fname, stemp->count);
                        stemp = stemp->snext;
                    }

                    printf(BLUE"-------------------------------------------------\n"RESET);
                   
               }
                mtemp = mtemp->next;
            }

}


