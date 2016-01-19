// Programa que calcula el área bajo la curva (1/(σ sqrt(2π)))e^((-1/2)((x-µ)/σ)))² dx
// ESCUELA SUPERIOR DE CÓMPUTO 
// Cálculo Aplicado
//Prof. Montiel
//Autor: Javier Mejía Pérez

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define pi 3.141592
#define eulerC 2.7182

double evalInt(double , double , double );
int getConst(double *, int *);
void inits(char [], int ); //Inicializa una cadena de caracteres en \0
int main(void){
  system("clear");
  printf("Programa que calcula el área bajo la curva (1/(σ sqrt(2π)))e^((-1/2)((x-µ)/σ)))² por el método rectangular.\n\n");
    int sh=0;
    char opc='\0';
	double sigma=-1; // σ
	double mu=0.0; //µ
	double c1;// constante que acompaña a la integral
	double auxa=0,auxb=0,a=0,b=0; //límites de integración
	double areaBajoCurva=0.0;
	long int iteraciones=300;//Númerod e iteraciones por defecto
	double x,iteracionesaux=0;
	do{
		    
fflush( stdin );fflush( stdin );fflush( stdin );
	puts ("Constantes: \nIngrese el valor de σ:");
	while(sigma<=0){
	getConst(&sigma,&sh);
	  if(sigma==0)printf("No puedo hacer eso, ya que haré el cálculo:\n (1/(σ sqrt(2π))) y si σ=0 eso se indetermina.  Intenta con otro número: \n ");
	  if(sigma<0.0)printf("Sigma debe ser estrictamente mayor que 0 \n ");
	}
	puts("Ingrese el valor de µ:");
	 getConst(&mu,&sh);
	while(auxa==auxb){
	 puts("Límites de integración:\nCalcular área desde (ingrese  el valor de a):");
	
	getConst(&auxa,&sh);
	
	printf("Hasta (ingrese el valor de b):");
	getConst(&auxb,&sh);
	if(auxb>auxa)
	{
	  a=auxa;
	  b=auxb;
	}else if(auxa>auxb){
	  printf("Parece que tus límites están en el orden incorrecto, a debe ser menor a b por definición, pero puedo manejarlo, invirtiendo..\n");
	  b=auxa;
	  a=auxb;

	}
	else{
	    printf("Eh!, ahí no hay área!, escribe límites de integración que no sean iguales...Va de nuevo:\n");
	  }
	}
	
	
	x=a;  
	printf("Calculando área con σ=%2.2f,µ=%2.2f,a=%2.2f,b=%2.2f\n ",sigma,mu,a,b);
	double base=(b-a)/iteraciones;
	c1=1/(sigma*(sqrt(2*pi))); 
	double ev;
	for(int i=1;i<=iteraciones;i++){
		ev=evalInt(x,mu,sigma);
		
		areaBajoCurva=areaBajoCurva+((c1)*(ev)*(base));
		//printf("[%f] x=%f",ev,x);
		x=x+base;
	}
	printf("Area bajo (1/(σ sqrt(2π)))e^((-1/2)((x-µ)/σ)))²:[%f]\n\n\n ",areaBajoCurva);
	printf("Detalles:\n Calculé el área desde: %2.2f hasta %2.2f\n ",a,b,iteraciones);
	
	    printf("Otro Cálculo? S para si.\n");
	    //getchar();
	    scanf("%c",&opc);
	  a=0;
	  b=0;
	  auxa=0;
	  auxb=0;
	  sigma=-1;
	  getchar();
	  system("clear"); 
	  }while(opc=='S'||opc=='s');


}



double evalInt(double x, double mu, double sigma){

	double eint =(pow(((x-mu)/(sigma)),2))*(-0.5);
	double eval=(pow(eulerC,eint )) ;

	return eval;
}
int getConst(double * constante, int * sh ){
   int flag=0,mas=0,menos=0,pto=0,num=0;
    char aux[50];
   int lenght=0;
    inits(aux,lenght); // inciando cadena 

  while(flag==0){



 gets(aux); //obteniendo cadena
 lenght= strlen(aux);

 int x=0;
 while(aux[x]!='\0'){
   
     
 
   if((aux[x]-'0'>=0 &&aux[x]-'0'<=9)||aux[x]=='-'||aux[x]=='.'||aux[x]=='+'){
     flag=1;
if(aux[x]=='.')
pto++;
if(aux[x]=='-')
menos++;
if(aux[x]=='+')
mas++;
if((aux[x]-'0'>=0 &&aux[x]-'0'<=9))
num++;
if((aux[x]=='-'||aux[x]=='+')&&(num>0))
menos=2;
if((aux[x]=='-'||aux[x]=='+')&&(pto>0))
menos=2;


}
else{
flag=0;
x= lenght-1;
}
     
     
   x++;
 }

 if(flag==1){

   *constante=atof(aux);
 if(pto>1||menos>1||mas>1)
printf("Eso no es un número pero pienso que puedo tratar con %f \n\n",*constante);
}

    else{
     printf("Es en serio?, intenta de nuevo... Ingrese el valor requerido:\n");
       *sh=1;
  }
  }
 

 return flag;

}


void inits(char cad[],int w)//Inicializa una cadena de caracteres en \0
{
  int n;
  for(n=0;n<w;n++)
  {
    cad[n]='\0'; //inicializando cadena	
  }
}
