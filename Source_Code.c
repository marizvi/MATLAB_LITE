#include<stdio.h> 
#include<math.h>
void nularr(float arr[], int q);//1

float sprod(float u[],float v[], int q);//2

void proj(float arr[],float y[],float u[],int q);//3

void final(float arr[],float y[], int q);//4 

void orthonorm(int q, int w, float a[][w]);//5  q= rows, w= columns

void orthog(int q, int w, float a[][w]);//6   q= rows, w= columns

void multip(int rows1, int columns1, int columns2, float matrix1[][columns1], float matrix2[][columns2],float r[rows1][columns2]);//7

void prntmatrix(int rows,int columns,float matrix[][columns]);//8

void inputmat(int rows,int columns,float a[][columns],float b[][columns]);//9

void QRfactorisation(int rows, int columns,float a[][columns], float b[][columns],float btranspose[][rows],float r[][columns]);//10

void rexchange(float arr1[],float arr2[],int n);//11

void ref(int g, int h, float a[][h]);//12

int linear_dependency(int rows,int columns, float a[][columns]);//13

void determinant(int rows, float a[][rows]);//14

void dimensions(int rows, int columns, float a[][columns]);//15


int main()
{
int rows,columns,options;
int test;
do
{
printf("\n\t\t\t\t   ///////////******|||||||||||||||||||******\\\\\\\\\\\\\\\\\\\\\n\n");
printf("\n\t\t\t\t ||||||||||******** WELCOME TO MATLAB LITE ******|||||||||||\n");
printf("\nEnter the options Accordingly: \n\n");
printf("\n\n*****|||||****\t\t\t # Press 1 for finding QR factorization: \n");
printf("\n*****|||||****\t\t\t # Press 2 for finding least square solution using QR factorization: \n");
printf("\n*****|||||****\t\t\t # Press 3 for finding orthogonal basis: \n");
printf("\n*****|||||****\t\t\t # Press 4 for finding orthonormal basis: \n");
printf("\n*****|||||****\t\t\t # Press 5 for finding REF form: \n");
printf("\n*****|||||****\t\t\t # Press 6 to check linear dependency of given vectors: \n");
printf("\n*****|||||****\t\t\t # Press 7 to find determinant of a matrix: \n");
printf("\n*****|||||****\t\t\t # Press 8 to find product of two matrices: \n");
printf("\n*****|||||****\t\t\t # Press 9 to find rank of a Matrix: \n");
printf("\n*****|||||****\t\t\t # Press CTRL + C to close this applictaion anytime \n\n");
scanf("%d",&options);
if(options>=10 || options<=0)
printf("\n Sorry we cannot execute your request\n\n Kindly read instructions properly \n");
if(options>0 && options <10)// program will only run if appropriate options are chosen.
{
printf("\n*****|||||****\tEnter number of rows: ");
scanf("%d",&rows);

printf("\n*****|||||****\tEnter number of columns: ");
scanf("%d",&columns);

int new_column=columns+1;

float a[rows][columns];
float b[rows][columns];//orthonormal matrix
float d[rows];
float r[columns][columns];

if(options==1)// to get QR factorization
 {          
            float btranspose[columns][rows];
             inputmat(rows,columns,a,b);
             int chk=0;
            float temp_chek[rows][columns];
            for(int i=0;i<rows;i++)
            {
                for(int j=0;j<columns;j++)
                {
                  temp_chek[i][j]=a[i][j];
                }
            }
            ref(rows, columns,temp_chek);
            chk=linear_dependency(rows,columns,temp_chek);
            if(chk==1)
            {
            QRfactorisation(rows,columns,a,b,btranspose,r);
            printf("\n\nFinal Upper Triangular Matrix R = ");
            prntmatrix(columns,columns,r);
            }
            else
            printf("Sorry for the inconvenience,\n the columns you entered are lineraly dependent, \n And QR factorisation only works with linearly independent columns");

           
}
if(options == 2) // least square solution using  QR factorisation
 { 
            float A[columns][new_column],temp[columns][1];//temp = Q(transpose)*b
            float btranspose[columns][rows];// btranpose refers to Q transpose in QR factorisation
            float d[rows][1]; // here d refers to a vector in AX=d
            inputmat(rows,columns,a,b); // here b matrix refers to Q in QR factorisation
            
            int chk=0;
            float temp_chek[rows][columns];
            for(int i=0;i<rows;i++)
            {
                for(int j=0;j<columns;j++)
                {
                  temp_chek[i][j]=a[i][j];
                }
            }
            ref(rows, columns,temp_chek);
            chk=linear_dependency(rows,columns,temp_chek);


            if(chk==1)
       {    
           printf(" hence QR factorisation exists ");
            QRfactorisation(rows,columns,a,b,btranspose,r); //b = Q, a = original matrix
             
             printf("\n\nFinal Upper Triangular Matrix R = ");
            prntmatrix(columns,columns,r);

            printf("\n\nEnter d vector\n"); //AX=d
            for(int i=0;i<rows;i++)
            scanf("%f",&d[i][0]);

            multip(columns,rows,1,btranspose,d,temp); //executing temp = Q (transpose) * d

            for(int i=0;i<columns;i++)
            for(int j=0;j<columns;j++)
                A[i][j]=r[i][j];

            for(int i=0;i<rows;i++)
            A[i][columns]=temp[i][0];

            float sum,x[20];
            int n=columns;

            //this loop is for backward substitution
            for(int i=n-1; i>=0; i--)
            {
                sum=0;
                for(int j=i+1; j<n; j++)
                {
                    sum=sum+A[i][j]*x[j];
                }
                x[i]=(A[i][n]-sum)/A[i][i];
            }
            printf("\n\nThe solution is: \n");
            for(int i=0; i<n; i++)
            {
                printf("\nx%d=%f\t",i,x[i]); /* x1, x2, x3 are the required solutions*/
            }              
       }

            else
            printf("Sorry for the inconvenience,\n the columns you entered are lineraly dependent, \n And QR factorisation only works with linearly independent columns");
 }
 if(options == 3)// to find orthogonal basis.
 {   
             inputmat(rows,columns,a,b);
                orthog(rows,columns,a);
                prntmatrix(rows,columns,a);
 }
 if(options == 4)// to find orthonormal basis.
 {   
             inputmat(rows,columns,a,b);
                orthog(rows,columns,a);
                orthonorm(rows,columns,a);
                prntmatrix(rows,columns,a);
 }  
 if(options == 5) //to find ref form
 {
      inputmat(rows,columns,a,b);
      ref(rows,columns,a);
      prntmatrix(rows,columns,a);

 }
 if(options == 6)// to check linear dependency
 {
      inputmat(rows,columns,a,b);
      ref(rows,columns,a);
      prntmatrix(rows,columns,a);
      linear_dependency(rows,columns,a);
 }

 if(options == 7) // to find determinant
 {  
     if(rows==columns)
     {
    inputmat(rows,rows,a,b);
    ref(rows,columns,a);
     determinant(rows,a);
     }
     else
     printf("\n\n:-( :-( \nPlease check once again. \nFor determinant you have to insert a square matrix");    
 }

 if(options == 8)// to multiply two matrices
 {
    inputmat(rows,columns,a,b);
     int rows2, columns2;
     printf("\nEnter the number of rows of 2nd Matrix: ");
     scanf("%d",&rows2);
     printf("\nEnter the number of columns of 2nd Matrix: ");
     scanf("%d",&columns2);
     if(rows2==columns)
     {
     float c[rows2][columns2],prod[rows][columns2];
    inputmat(rows2,columns2,c,b);
     multip(rows,columns,columns2,a,c,prod);
     prntmatrix(rows,columns2,prod);
     }
     else
     printf("\n Sorry we cannot execute your request as, \nRows of second Matrix must be equal to Columns of 1st\n");
 }
 if(options == 9)//rank of matrix..
 {
            inputmat(rows,columns,a,b);
            ref(rows,columns,a);
            dimensions(rows,columns,a);
 }
 printf("\n\n Do you want to Calculate again ? \n(press 1 for yes and 0 for no): ");
 scanf("%d",&test);
} 
}while(test==1);
 printf("\n\n Aborting.......");
 printf("\n\n\t\t\t********||||||||||||||||*********\n");
 printf("\n THANKS FOR VISITING US,\n\n HAVE A NICE DAY.\n\n :-) :-) :-)");
 printf("\n");
 system("pause");
return 0;
}

void nularr(float arr[], int q)
{
    for(int i=0;i<q;i++)
    arr[i]=0;
}

float sprod(float u[],float v[], int rows)
{
    float sum = 0.0;
    for(int i=0;i<rows;i++)
    {
        sum+=u[i]*v[i];
    }
    return sum;
}

void proj(float arr[],float y[],float u[],int rows)
{
    float m=sprod(y,u,rows);
    float n=sprod(u,u,rows);
for(int i=0;i<rows;i++)
    arr[i]+=(m/n)*u[i];
}

void final(float arr[],float y[], int rows)
{
for(int i=0;i<rows;i++)
{
    y[i]-=arr[i];
}
}

void orthonorm(int rows, int columns, float a[][columns])
{
    float v[columns][rows];
    for(int j=0;j<columns;j++)
{
    for(int i=0;i<rows;i++)
    {
        v[j][i]=a[i][j]; //storing columns of matrix into vectors v1, v2, v3.
    }
}   
float m;
    for(int i=0;i<columns;i++)
  {
       m=sprod(v[i],v[i],rows);
       for(int j=0;j<rows;j++)
       v[i][j]/=sqrt(m);
  }

   for(int j=0;j<columns;j++)
{
    for(int i=0;i<rows;i++)
    {
        a[i][j]=v[j][i];
    }
}
}

void orthog(int rows, int columns, float a[][columns])
{

float v[columns][rows]; //vectors
float arr[rows];
nularr(arr,rows);
for(int j=0;j<columns;j++)
{
    for(int i=0;i<rows;i++)
    {
        v[j][i]=a[i][j];  //storing columns of matrix into vectors v1, v2, v3.
    }
}
int d=1;
while(d<columns)
{
for(int i=0;i<d;i++)
{
    proj(arr,v[d],v[i],rows);
}
final(arr,v[d],rows);  // v1 = x1 - (x1*x0/x0*x0 ) * x1 // Gram Schimdt
nularr(arr,rows);
d++;
}
// this part is just to organise basis into matrix form
for(int j=0;j<columns;j++)
{
    for(int i=0;i<rows;i++)
    {
        a[i][j]=v[j][i];
    }
}
}


void multip(int rows1, int columns1, int columns2, float matrix1[][columns1], float matrix2[][columns2],float r[rows1][columns2])
{   
    for(int i=0;i<rows1;i++)
    {
    for(int j=0;j<columns2;j++)
    {
    r[i][j]=0;
    for(int k=0;k<columns1;k++)
    {
        r[i][j]+=matrix1[i][k]*matrix2[k][j];
    }
    }
    }

}

void prntmatrix(int rows,int columns,float matrix[][columns])
{
    printf("\n");
    for(int i=0;i<rows;i++)
{   
    printf("\n");
    for(int j=0;j<columns;j++)
    printf("%0.3f ",matrix[i][j]);
}
}

void inputmat(int rows,int columns,float a[][columns],float b[][columns])
{
printf("\nNow enter the matrix A row wise (Each element seperated by a space): \n");
     
for(int i=0;i<rows;i++)
{
    for(int j=0;j<columns;j++)
    {
        scanf("%f",&a[i][j]);
        b[i][j]=a[i][j];
    }
}
}

void QRfactorisation(int rows, int columns,float a[][columns], float b[][columns],float btranspose[][rows],float r[][columns])
{
            
            orthog(rows,columns,b);
            orthonorm(rows,columns,b);
            printf("\n\nOrthonormal Matrix Q: ");
            prntmatrix(rows,columns,b);

            for(int i=0;i<rows;i++)
            for(int j=0;j<columns;j++)
            btranspose[j][i]=b[i][j];

            multip(columns,rows,columns,btranspose,a,r);//three parameters (rows of 1st mat,columns of 1st, column of last mat)
            
}


void rexchange(float arr1[],float arr2[],int columns)
{   float temp;
    for(int i=0;i<columns;i++)
    {
        temp=arr1[i];
        arr1[i]=arr2[i];
        arr2[i]=temp;
    }
}

void ref(int rows, int columns, float a[][columns])
{   
int c=rows-1,u;
if(rows<=columns)
u=rows;
else if(columns<rows)
    u=columns;
for(int i=0;i<u;i++)// this loop is to check diagonal entries 
{      
            if(a[i][i]==0) 
           {    
               for(int y=i+1;y<rows;y++)   //try to convert it into a function
               {
                   if(a[y][i]!=0)
            rexchange(a[i],a[y],columns);  // to swap rows..
               }
           }
            if(a[i][i]==0) // even  if after row exchange if diagonal entry is zero then skip rest row operation
                continue;

    for(int m=i+1;m<rows;m++)  //'To move on next columns
    {       
            float x = a[c][i]/a[i][i];  
            for(int j=0;j<columns;j++)    // applying row operation
            {
                a[c][j]-=x*a[i][j]; //R3= R3-x*R1(For 1st iteration)
                if(a[c][j]<0.00001 && a[c][j]>-0.00001)
                a[c][j]=0;
            }
            c--;
    }
    
    c=rows-1;

}
}

int linear_dependency(int rows,int columns, float a[][columns])
{
int count=0,termination;
if(rows<=columns)
termination=rows;
if(columns<rows)
termination=columns;
for(int i=0;i<termination;i++)
{
    if(a[i][i]==0)
    count++;
}
printf("\n");
if(count!=0&&columns<=rows)
{
printf("\nColumns are lineraly dependent\n");
return 0;
}
else
if(count==0&&columns<=rows)
{
printf("\nColumns are lineraly independent\n");
return 1;
}
else if(columns>rows)
{
printf("\nColumns linearly dependent\n");
return 0;
}
}

void determinant(int rows, float a[][rows])
{   
    float det=1;
    for(int i=0;i<rows;i++)
    {
        det*=a[i][i];
    }
    if(det==-0)
    det=0;
    printf("\n\nDeterminant of a given matrix is: %0.3f",det);
}

void dimensions(int rows, int columns, float a[][columns])
{
     int i, j, k,count = 0;
  if (rows <= columns)
  {
      k = rows;
      
  }
  else 
  k = columns;
 
  for (i = 0; i <k; i++)
  {
       if (a[i][i] != 0)
       {
            count++;
       }
  }
            printf ("\n Rank of Matrix %d \n", count);
}