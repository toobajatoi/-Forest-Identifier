#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct forest
{
    char name[50];
    char area[10][150];
    char description[10][150];
    char importance[10][150];
};
void driver();
void Header();
int readline(FILE *f, char *buffer, size_t len);

int main()
{
    driver();
    // FILE *fp;
    // fp = fopen("for.txt","r");
    // struct forest arr[100];
    
    // int j = 0;
    // int area_length[2]={1,4};
    // int imp_length[2]={1,6};
    // int des_length[2]={3,5};
    // while(j<2)
    // {
    //     struct forest alpine;
    //     char str[100]="";
    //     int i = 0;
    //     char ch=' ';
    //     char *pt;
    //     pt = &ch;
    //     char *empty="";
    //     alpine.name[0] = '\0';
    //     strcpy(alpine.name,empty);

    //     while (ch!='\n')
    //     {
    //         ch = fgetc(fp);
    //         strcat(&ch,alpine.name);
    //         //printf("printing after cat: %s", alpine.name);
    //     }
    //     // printf("FULL STRING: %s",alpine.name);
    //     // printf("HELLO");
    //     ch = 't';
    //     while (strcmp(alpine.area[i],"END\n")!=0)
    //     {
    //         strcpy(alpine.area[i],"");
    //         while (ch!='\n')
    //         {
    //             ch = fgetc(fp);
    //             strcat(alpine.area[i],pt);
    //             printf("%c",ch);
    //         }
    //         printf("%s",alpine.area[i]);
    //         if(strcmp(alpine.area[i],"END\n")==0)
    //         {
    //             break;
    //         }
    //         i++;
    //         // area_length[j]++;
    //         ch='t';
    //     }
    //     // if(j==1)
    //     //     printf("MEOW");
    //     i=0;
    //     ch = 't';
        
    //     while (strcmp(alpine.description[i],"END")!=0)
    //     {
    //         strcpy(alpine.description[i],"");
    //         while (ch!='\n')
    //         {
    //             ch = fgetc(fp);
    //             strcat(alpine.description[i],pt);
    //         }
    //         if(strcmp(alpine.description[i],"END\n")==0)
    //         {
    //             break;
    //         }
    //         // des_length[j]++;
    //         ch='t';
    //         i++;
    //     }
    //     i=0;
    //     ch = 't';
    //     while (strcmp(alpine.importance[i],"END")!=0)
    //     {
    //         strcpy(alpine.importance[i],"");
    //         while (ch!='\n')
    //         {
    //             ch = fgetc(fp);
    //             strcat(alpine.importance[i],pt);
    //         }
    //         if(strcmp(alpine.importance[i],"END\n")==0)
    //         {
    //             break;
    //         }
    //         ch='t';
    //         i++;
    //         // imp_length[j]++;
    //     }
    //     arr[j] = alpine;
    //     j++;
    // }
    // fclose(fp);
    // char fname[10][20] = {
    //     "Alpine Forests",
    //     "Coniferous Forests",
    // };
    // for (int i = 0; i < j; i++)
    // {
    //     printf("Forest Name: %s\n",fname[i]);
    //     printf("Forest Areas: \n");
    //     for (int k = 0; k < area_length[i]; k++)
    //     {
    //         printf("%d. %s",k+1,arr[i].area[k]);
    //     }
    //     printf("\n");
    //     printf("Forest Description: \n");
    //     for (int k = 0; k < des_length[i]; k++)
    //     {
    //         printf("%d. %s",k+1,arr[i].description[k]);
    //     }
    //     printf("\n");
    //     printf("Forest Importance: \n");
    //     for (int k = 0; k < imp_length[i]; k++)
    //     {
    //         printf("%d. %s",k+1,arr[i].importance[k]);
    //     }
    //     printf("\n");
    // }
    return 0;
}

void driver()
{
    FILE *fp = fopen("Forest.txt","r");
    struct forest arr[20];
    int const total_forest = 3;
    int area_length[3]={1,4,3};
    int des_length[3]={3,5,4};
    int imp_length[3]={1,6,1};
    for(int i = 0; i < total_forest; i++)
    {
        readline(fp,arr[i].name,sizeof(arr[i].name));
        for (int k = 0; k < area_length[i]; k++)
        {
            readline(fp,arr[i].area[k],sizeof(arr[i].area[k]));
        }
        for (int k = 0; k < des_length[i]; k++)
        {
            readline(fp,arr[i].description[k],sizeof(arr[i].description[k]));
        }
        for (int k = 0; k < imp_length[i]; k++)
        {
            readline(fp,arr[i].importance[k],sizeof(arr[i].importance[k]));
        }
    }
    fclose(fp);
    for(int i = 0; i < total_forest; i++)
    {
        printf("%s\n",arr[i].name);
        for (int k = 0; k < area_length[i]; k++)
        {
            printf("%s\n",arr[i].area[k]);
        }
        for (int k = 0; k < des_length[i]; k++)
        {
            printf("%s\n",arr[i].description[k]);
        }
        for (int k = 0; k < imp_length[i]; k++)
        {
            printf("%s\n",arr[i].importance[k]);
        }
    }
    char area[150],imp[150],des[150];
    int i = 0;
    int ans = 0;    
    while (ans == 0 || ans == -1)
    {
        Header();
        printf("Select an area from the list: \n");
        for (int k = 0; k < area_length[i]; k++)
        {
            printf("%d. %s\n",k+1,arr[i].area[k]);
        }
        printf("Select your option or Press 0 to see more options: ");
        fflush(stdin);
        scanf("%d",&ans);
        fflush(stdin);
        if(ans == 0)
        {
            if(i == total_forest-1 && ans == 0)
            {
                printf("End of options, Press -1 to Go Back");
                getch();
            }
            else
            {
                i++;
            }
        }
        if (ans == -1)
        {
            if(i==0 && ans == -1)
            {
                printf("Start of options, Press 0 to see next page");
                getch();
            }
            else
            {
                i--;
            }
        }
    }
    ans--;
    strcpy(area,arr[i].area[ans]);
    printf("Selected Area: %s",arr[i].area[ans]);
    //Description
    i = 0;
    ans = 0;    
    while (ans == 0 || ans == -1)
    {
        Header();
        printf("Select a Description from the list: \n");
        for (int k = 0; k < des_length[i]; k++)
        {
            printf("%d. %s\n",k+1,arr[i].description[k]);
        }
        printf("Select your option or Press 0 to see more options: ");
        fflush(stdin);
        scanf("%d",&ans);
        fflush(stdin);
        if(ans == 0)
        {
            if(i== total_forest-1 && ans == 0)
            {
                printf("End of options, Press -1 to Go Back");
                getch();
            }
            else
            {
                i++;
            }
        }
        if (ans == -1)
        {
            if(i==0 && ans == -1)
            {
                printf("Start of options, Press 0 to see next page");
                getch();
            }
            else
            {
                i--;
            }
        }
    }
    ans--;
    printf("Selected Description: %s",arr[i].description[ans]);
    strcpy(des,arr[i].description[ans]);
    //Importance
    
    i = 0;
    ans = 0;
    while (ans == 0 || ans == -1)
    {
        Header();
        printf("Select the Importance of the Forest from the list: \n");
        for (int k = 0; k < imp_length[i]; k++)
        {
            printf("%d. %s\n",k+1,arr[i].importance[k]);
        }
        printf("Select your option or Press 0 to see more options: ");
        fflush(stdin);
        scanf("%d",&ans);
        fflush(stdin);
        if(ans == 0)
        {
            if(i == total_forest-1 && ans == 0)
            {
                printf("End of options, Press -1 to Go Back");
                getch();
            }
            else
            {
                i++;
            }
        }
        if (ans == -1)
        {
            if(i==0 && ans == -1)
            {
                printf("Start of options, Press 0 to see next page");
                getch();
            }
            else
            {
                i--;
            }
        }
    }
    ans--;
    strcpy(imp,arr[i].importance[ans]);
    system("cls");
    printf("Selected Area: %s\n",area);
    printf("Selected Description: %s\n",des);
    printf("Selected Importance: %s\n",imp);
    printf("Based on the selections you made, Your Forest Name is: ");
    int aflag = 0;
    int dflag = 0;
    int iflag = 0;
    for(int i = 0; i < total_forest; i++)
    {
        for (int k = 0; k < area_length[i]; k++)
        {
            if (strcmp(area , arr[i].area[k])==0)
            {
                aflag = 1;
                break;
            }
        }
        for (int k = 0; k < des_length[i]; k++)
        {
            if (strcmp(des , arr[i].description[k])==0)
            {
                dflag = 1;
                break;
            }
        }
        for (int k = 0; k < imp_length[i]; k++)
        {
            if (strcmp(imp , arr[i].importance[k])==0)
            {
                iflag = 1;
                break;
            }
        }
        if(aflag == 1 && iflag == 1 && dflag == 1)
        {
            printf("%s",arr[i].name);
            exit(0);
        }
    }
    printf("Could not predict the forest");
}
void Header()
{
    system("cls");
    printf("-----------------------------------------------\n");
    printf("               FOREST IDENTIFIER            \n");
    printf("-----------------------------------------------\n");
}
int readline(FILE *f, char *buffer, size_t len)
{
    char c; 
    int i;
    memset(buffer, 0, len);
    for (i = 0; i < len; i++)
    {   
        int c = fgetc(f);
        if (!feof(f)) 
        {   
            if (c == '\r')
                buffer[i] = 0;
            else if (c == '\n')
            {   
                buffer[i] = 0;
                return i+1;
            }   
            else
                buffer[i] = c; 
        }   
        else
        {   
            return -1; 
        }   
    }
   return -1; 
}