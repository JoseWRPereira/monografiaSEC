#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
  FILE * fp;
  int   cont 	   = 0;
  int   nciclos    = 10;
  float sensor_min = 0.0;
  float sensor_max = 0.0;
  float setpoint   = 0.0;
  float usp        = 1.0;	// mu set point
  float lsp        = 0.0;	// lambda set point
  float us         = 0.0;	// mu sensor
  float ls         = 1.0;	// lambda sensor
  float sensor     = 0.0; 	// sensor 
  float Gc         = 0.0; 	// grau de certeza
  float Gct        = 0.0;	// grau de contradicao
  float D          = 0.0;	// distancia
  float Gcr        = 0.0;	// grau de certeza real
  float uer        = 0.0;	// mu ?evidencia real?

  printf("\t\tSimulacao de LPA2v\n\n");
  printf("Entre com os dados do sensor |\n");
  printf("Valor minimo de leitura = ");
  scanf("%f", &sensor_min );
  printf("\nValor maximo de leitura = ");
  scanf("%f", &sensor_max );
  do
  {
    printf("\nEntre com o valor do SetPoint[%2.3f .. %2.3f] = ", 
	  sensor_min, sensor_max);
    scanf("%f", &setpoint );
  }
  while( setpoint < sensor_min || setpoint > sensor_max );
  do
  {
    printf("\nEntre com o valor inicial do Sensor[%2.3f .. %2.3f] = ", 
	  sensor_min, sensor_max);
    scanf("%f", &sensor );
  }
  while( sensor < sensor_min || sensor > sensor_max );


  printf("\n\n\t\tParametros Iniciais\n");
  printf("Sensor[%2.3f .. %2.3f] = ", sensor_min, sensor_max );
  printf("%2.3f  ->  %2.3f\n\n", sensor, setpoint );
  printf("ciclos|sensor| us  | ls  | Gc  | Gct |  D  | Gcr | uer \n");
  printf("%6u %3.3f %1.3f %1.3f %1.3f %1.3f %1.3f %1.3f %1.3f\n", 
	cont, sensor, us,ls, Gc, Gct, D, Gcr, uer );
 
  fp = fopen("grafparacontrol.txt", "w+");
    fprintf( fp, "%6u %3.3f %3.3f %1.3f %1.3f %1.3f %1.3f %1.3f %1.3f %1.3f\n", 
	    cont, sensor, setpoint, us,ls, Gc, Gct, D, Gcr, uer );

  while( setpoint-sensor > 0.0005 )
  {
    cont++;

    us =  (sensor - sensor_min)/(setpoint-sensor_min);
    ls = 1.0 - us;

    Gc  = usp - ls;
    Gct = usp + ls - 1.0;

    D = sqrtf((Gct*Gct)+((1.0-Gc)*(1.0-Gc)));
    Gcr = 1.0 - D;
    uer = (1.0 + Gcr)/2.0;

    sensor = uer*(setpoint-sensor_min)+sensor_min;

    printf("%6u %3.3f %1.3f %1.3f %1.3f %1.3f %1.3f %1.3f %1.3f\n", 
	    cont, sensor, us,ls, Gc, Gct, D, Gcr, uer );
    fprintf( fp, "%6u %3.3f %3.3f %1.3f %1.3f %1.3f %1.3f %1.3f %1.3f %1.3f\n", 
	    cont, sensor, setpoint, us,ls, Gc, Gct, D, Gcr, uer );
    
  }
  fclose(fp);
  return(0);
}
