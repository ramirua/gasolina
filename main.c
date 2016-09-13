//ejercicio de la gasolina
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	char resp, placa[5], placa_mayor[5];
	int tipo, cont_vehiculo, i;
	float litros, mayor, precio_95, precio_91, monto_pagar, promedio_bs, total_monto;
	
	// inicializacion de mayor en un valor negativo
	mayor=-1;
	printf("ingrese el precio de la gasolina en bs de 95 octanos: ");
	scanf("%f",&precio_95);
	printf("ingrese el precio de la gasolina en bs de 91 octanos: ");
	scanf("%f",&precio_91);
	//ciclo for de los dias
	for(i=1; i<=7; i++)
	{
		total_monto=0;
		cont_vehiculo=0;
		printf("hay vehiculos en la estacion de servicio para el dia: %d",i);
		scanf(" %c",&resp);
		
		while(resp=='s' || resp=='S')
		{
			printf("ingrese la placa: ");
			scanf("%s",placa);
			printf("ingrese el tipo de la gasolina: ");
			scanf("%d",&tipo);
			printf("ingrese los litros de la gasolina: ");
			scanf("%f",&litros);
			
			if(tipo==95)
			{
				monto_pagar=litros*precio_95;
				if(litros>mayor)
				{
					mayor=litros;
					strcpy(placa_mayor, placa);
				}
			}
			
			if(tipo==91)
			{
				monto_pagar=litros*precio_91;
			}
			
			
		  printf("el monto a pagar por el vehiculo con la placa %s es %.2f", placa,monto_pagar);
		  total_monto=total_monto+monto_pagar;
		  cont_vehiculo++;
		  printf("\n hay mas vehiculos en la estacion de servicio para el dia: %d",i);	
		  scanf(" %c",&resp);
		}
		
	  if(cont_vehiculo>0)
	  {
			promedio_bs=total_monto/cont_vehiculo;
			printf("\n el promedio pagado por el vehiculo el dia %d es %.2f \n",i, promedio_bs);
	  }
	}
	
	printf("\n el vehiculo que solicito la mayor cantidad de litros del tipo de 95 es: %s quien solicito %.2f litros", placa_mayor, mayor);
	fflush(stdin);
	return 0;
}
