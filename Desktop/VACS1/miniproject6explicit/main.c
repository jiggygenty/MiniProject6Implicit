#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double u0(double n,double x)
{
    return(sin(n*x));
}
double uexact(double n,double t,double x)
{
    return(exp(-pow(n,2)*t)*sin(n*x));
}

void main()
{
double n=1;
double D=1.0;
double F=0.0;
double dx=M_PI/20;
double xi=0.0;
double xf=M_PI;
double tMAX=2.0;
double lambda=0.4;
double dt=lambda*dx*dx/D;
int i,j;
int N=(int)ceil((xf-xi)/dx);

int M=(int)ceil(tMAX/dt);
double u[M+1][N+1];
double exact[M+1][N+1];
double error[M+1][N+1];

FILE *fptr;
FILE *fr;
fptr=fopen("explicitdata4.csv","w");
fr=fopen("experror4.csv","w");

for(i=0;i<=M;i++)
{
    for(j=0;j<=N;j++)
    {
    printf("%lf ",uexact(n,(i*dt),(j*dx)));
    exact[i][j]=uexact(n,(i*dt),(j*dx));
    }
    printf("\n");
}
printf("\n");
printf("\n");

for(j=1;j<=N-1;j++)
{
    u[0][j]=u0(n,j*dx);
}
for(i=0;i<=M;i++)
{
    u[i][0]=0;
    u[i][N]=0;
}

for(i=0;i<=M-1;i++)
{
    for(j=1;j<=N-1;j++)
    {
        u[i+1][j]=u[i][j]+lambda*(u[i][j-1]-2*u[i][j]+u[i][j+1]);
    }
}
for(i=0;i<=M;i++)
{
    for(j=1;j<=N-1;j++)
    {
      error[i][j]=100.0*(fabs(u[i][j]-exact[i][j]))/exact[i][j];
      fprintf(fr,"%lf,",error[i][j]);
    }
    fprintf(fr,"\n");
}

for(i=0;i<=M;i++)
{
for(j=0;j<=N;j++)
{
    printf("%lf ",u[i][j]);
}
printf("\n");
}
for(i=0;i<=M;i++)
{
    for(j=0;j<=N;j++)
    {
        fprintf(fptr,"%lf,",u[i][j]);
    }
    fprintf(fptr,"\n");
}
fclose(fptr);
fclose(fr);
}
