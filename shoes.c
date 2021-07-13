#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
    char company[30];
    char model[30];
    char size[3];
    char color[10];
    char price[10];
    char condition[5];
    char age[3];   
};

void delete_line(int line) //buy pair
{
    FILE *file;
    FILE *draft;
    char c[100];
    int i=1;
    file=fopen("C:/Andrei/C/Practice Stage Project/data.txt","r");
    draft=fopen("C:/Andrei/C/Practice Stage Project/draft.txt","a");
    while(fgets(c,sizeof(c),file)!=NULL)  
    {
        if(i!=line)
            fprintf(draft,"%s",c);
        i++;
    }
    fclose(file);
    fclose(draft);
    delete_all();
    file=fopen("C:/Andrei/C/Practice Stage Project/data.txt","a");
    draft=fopen("C:/Andrei/C/Practice Stage Project/draft.txt","r");
    while(fgets(c,sizeof(c),draft)!=NULL)  
    {
        fprintf(file,"%s",c);
    }
    fclose(file);
    fclose(draft);
    draft=fopen("C:/Andrei/C/Practice Stage Project/draft.txt","w");
    fclose(draft);
}

void delete_all()
{
    FILE *file;
    file=fopen("C:/Andrei/C/Practice Stage Project/data.txt","w");
    fclose(file);
}

void read()
{
    char c[100];
    FILE *file;
    file=fopen("C:/Andrei/C/Practice Stage Project/data.txt","r");
    printf("Data from the file: \n");
    while(fgets(c,sizeof(c),file)!=NULL)  
    {
        printf("\n%s",c);
    }
    fclose(file);
}

void add()
{
    FILE *file;
    char *i=(char *)malloc(sizeof(struct data));
    i[0]='\0';
    struct data shoe;
    file=fopen("C:/Andrei/C/Practice Stage Project/data.txt","a");
    printf("\nEnter the brand of the shoes: ");
    scanf(" %s",shoe.company);
    strcat(i,shoe.company);
    strcat(i," ");
    printf("\nEnter the model of the shoes: ");
    scanf(" %s",shoe.model);
    strcat(i,shoe.model);
    strcat(i," ");
    printf("\nEnter the size of the shoes:");
    scanf(" %s",shoe.size);
    strcat(i,shoe.size);
    strcat(i," ");
    printf("\nEnter the color of the shoes: ");
    scanf(" %s",shoe.color);
    strcat(i,shoe.color);
    strcat(i," ");
    printf("\nEnter the price of the shoes:");
    scanf(" %s",shoe.price);
    strcat(i,shoe.price);
    strcat(i," ");
    printf("\nEnter the conditon of the shoes (good/ok/bad):");
    scanf(" %s",shoe.condition);
    strcat(i,shoe.condition);
    strcat(i," ");
    printf("\nHow old are the shoes? (years) ");
    scanf(" %s",shoe.age);
    strcat(i,shoe.age);
    fprintf(file,"%s \n",i);
    fclose(file);
}

void modify()
{  
    int line;
    printf("Type the number of the line you want to modify (begins from 1): ");
    scanf("%d",&line);
    FILE *file;
    FILE *draft;
    char c[100], *input=(char *)malloc(sizeof(struct data));
    int i=1;
    input[0]='\0';
    file=fopen("C:/Andrei/C/Practice Stage Project/data.txt","r");
    draft=fopen("C:/Andrei/C/Practice Stage Project/draft.txt","a");
    while(fgets(c,sizeof(c),file)!=NULL)  
    {
        if(i!=line)
            fprintf(draft,"%s",c);
        else
        {
            struct data shoe;
            printf("\nEnter the brand of the shoes: ");
            scanf(" %s",shoe.company);
            strcat(input,shoe.company);
            strcat(input," ");
            printf("\nEnter the model of the shoes: ");
            scanf(" %s",shoe.model);
            strcat(input,shoe.model);
            strcat(input," ");
            printf("\nEnter the size of the shoes:");
            scanf(" %s",shoe.size);
            strcat(input,shoe.size);
            strcat(input," ");
            printf("\nEnter the color of the shoes: ");
            scanf(" %s",shoe.color);
            strcat(input,shoe.color);
            strcat(input," ");
            printf("\nEnter the price of the shoes:");
            scanf(" %s",shoe.price);
            strcat(input,shoe.price);
            strcat(input," ");
            printf("\nEnter the conditon of the shoes (good/ok/bad):");
            scanf(" %s",shoe.condition);
            strcat(input,shoe.condition);
            strcat(input," ");
            printf("\nHow old are the shoes? (years) ");
            scanf(" %s",shoe.age);
            strcat(input,shoe.age);
            fprintf(draft,"%s \n",input);
        }
        i++;
    }
    fclose(file);
    fclose(draft);
    delete_all();
    file=fopen("C:/Andrei/C/Practice Stage Project/data.txt","a");
    draft=fopen("C:/Andrei/C/Practice Stage Project/draft.txt","r");
    while(fgets(c,sizeof(c),draft)!=NULL)  
    {
        fprintf(file,"%s",c);
    }
    fclose(file);
    fclose(draft);
    draft=fopen("C:/Andrei/C/Practice Stage Project/draft.txt","w");
    fclose(draft);
}

void estimatedprice(float price1, int age1,char condition1[])
{
    if(strcmp(strupr(condition1),"GOOD")==0)
    {
        price1=price1-3*price1*age1/100;
    }
    if(strcmp(strupr(condition1),"OK")==0)
    {
        price1=price1-10*price1/100;
        price1=price1-4*price1*age1/100;
    }
    if(strcmp(strupr(condition1),"BAD")==0)
    {
        price1=price1-25*price1/100;
        price1=price1-5*price1*age1/100;
    }
    if(price1<0)
    {
        price1=10;
    }
    printf("\nEstimated price: %.2f dollars\n", price1);
}

void estimate()
{
    char company1[30], model1[30], color1[10], condition1[5];
    int size1,age1;
    float price1=0;
    printf("\nEnter the brand of the shoes: ");
    scanf(" %s",company1);
    printf("\nEnter the model of the shoes: ");
    scanf(" %s",model1);
    printf("\nEnter the size of the shoes:");
    scanf(" %d",&size1);
    printf("\nEnter the color of the shoes: ");
    scanf(" %s",color1);
    printf("\nEnter a reference price to make better estimates (you can enter 0 if you don't know): ");
    scanf(" %f",&price1);
    printf("\nEnter the conditon of the shoes (good/ok/bad): ");
    scanf(" %s",condition1);
    printf("\nHow old are the shoes? (years) ");
    scanf(" %d",&age1);
    if(strcmp(strupr(company1),"NIKE")==0)
    {
        if(price1==0)
        {
            price1=80;
            estimatedprice(price1,age1,condition1);
        }
        else
        {
            estimatedprice(price1,age1,condition1);
        }
    }
    if(strcmp(strupr(company1),"ADIDAS")==0)
    {
        if(price1==0)
        {
            price1=70;
            estimatedprice(price1,age1,condition1);
        }
        else
        {
            estimatedprice(price1,age1,condition1);
        }
    }
    if(strcmp(strupr(company1),"REEBOK")==0)
    {
        if(price1==0)
        {
            price1=50;
            estimatedprice(price1,age1,condition1);
        }
        else
        {
            estimatedprice(price1,age1,condition1);
        }
    }
    if(strcmp(strupr(company1),"ASICS")==0)
    {
        if(price1==0)
        {
            price1=70;
            estimatedprice(price1,age1,condition1);
        }
        else
        {
            estimatedprice(price1,age1,condition1);
        }
    }
    if(strcmp(strupr(company1),"NEWBALANCE")==0)
    {
        if(price1==0)
        {
            price1=60;
            estimatedprice(price1,age1,condition1);
        }
        else
        {
            estimatedprice(price1,age1,condition1);
        }
    }  
}

void show_data()
{
    read();
}

void buy_pair()
{
    int line;
    printf("Type the number of the line for the shoe (begins from 1): ");
    scanf("%d",&line);
    delete_line(line);
}

void sell_pair()
{
    add();
}

int main()
{
    int input, run=1;
    while(run==1)
    {
        printf("\nPress 1 to delete all of the data\n");
        printf("\nPress 2 to show all of the data\n");
        printf("\nPress 3 to buy a pair of shoes (delete a line)\n");
        printf("\nPress 4 to sell a pair of shoes (add a new line)\n");
        printf("\nPress 5 to modify data\n");
        printf("\nPress 6 to get an estimated price\n");
        printf("\nPress 7 to exit\n");
        scanf("%d",&input);

        switch(input)
        {
            case 1:
                delete_all();
                break;
            case 2:
                show_data();
                break;
            case 3:
                buy_pair();
                break;
            case 4:
                sell_pair();
                break;
            case 5:
                modify();
                break;
            case 6:
                estimate();
                break;
            case 7:
                printf("Thank you for coming to us! We hope you come back.");
                run=0;
                break;
            default:
                printf("Error! invalid input");
        }
    }


    return 0;
}