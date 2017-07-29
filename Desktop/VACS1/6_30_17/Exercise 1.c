#include<stdio.h>

void main()
{
    FILE *fp;

    fp=fopen("test.txt","w+");
    fprintf(fp,"The file test.txt created successfully...!!\n");
    fclose(fp);
}
