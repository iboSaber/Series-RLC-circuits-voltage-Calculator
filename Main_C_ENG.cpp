#include <stdio.h>
#include <math.h>

int main() {
	
	double R, L, C, V_infinity, V0, Ic, A1, A2, Alfa, W, root, S1, S2, t, dt, dvdt, Wd;
	int i, n;
	printf("\n Hello User! This program calculates the voltage across the capacitor (C) in the Series RLC circuits\n\n Please enter the required values\n");
	printf("\n Enter value of R..:");  scanf("%lf", &R);
	printf("\n Enter value of L..:");  scanf("%lf", &L);
	printf("\n Enter value of C..:");  scanf("%lf", &C);
	printf("\n Enter value of V(0)..:");  scanf("%lf", &V0);
	printf("\n Enter value of V(∞)..:");  scanf("%lf", &V_infinity);
	printf("\n Enter value of Ic(0)..:");  scanf("%lf", &Ic);
	printf("\n Enter code runtime..:");  scanf("%lf", &t);
	printf("\n Enter the value of the time step d(t)..:");  scanf("%lf", &dt);

	Alfa = R / (2 * L);
	W = 1 / sqrt(L * C); 
	dvdt = (Ic / C);
	n = (t / dt); // to declare how mant times the program will itrarate itself
	double Vt[n+1]; 

	for (i = 0; i < n+1 ; i++) //	i here acts as mulitpulier 
	{	
		if(Alfa > W)
			{	
				root = pow(Alfa, 2) - pow(W, 2);
				S1 = -Alfa + sqrt(root);
				S2 = -Alfa - sqrt(root);
				A1 = (dvdt + S2 * (V_infinity - V0)) / (S1 - S2);
				A2 = (dvdt + S1 * (V_infinity - V0)) / (S2 - S1);
				Vt[i] = V_infinity + (A1 * exp(S1 * (i*dt))) + (A2 * exp(S2 * (i*dt)));
				
			//	V = V_infinity + A1 * exp(S1 * t) + A2 * exp(S2 * t);
				printf("\n\n at t = %lf\t\t V   =   %lf\n", i*dt , Vt[i]);
			}
		else if(Alfa == W)
			{
				printf("\n\n Critical dapmed");
				A1 = V0 - V_infinity;
				A2 = dvdt + Alfa * A1;
				Vt[i] = V_infinity + (A1 + A2 * (i*dt)) * exp(-Alfa * (i*dt));
				printf("at t = %lf\t\t V   =   %lf\n", i*dt , Vt[i]);
			}
		else
			{
				printf("\n\n Dapmed");
				root = pow(W, 2) - pow(Alfa, 2);
				Wd = sqrt(root);
				A1 = V0 - V_infinity;
				A2 = (dvdt + Alfa * A1) / Wd;
				Vt[i] = V_infinity + (exp(-Alfa * (i*dt)) * ((A1 * cos(Wd * (i*dt))) + (A2 * sin(Wd * (i*dt)))));
				printf(" at t = %lf\t\t V   =   %lf\n", i*dt , Vt[i]);
			}
	}
	
	printf(" \n\nA1 = %.4lf \t\t A2 = %.4lf \t\t S1 = %.2lf \t\t S2 = %.2lf", A1, A2, S1, S2);
	
	FILE *file;
	file = fopen("Values_found.csv", "w");
	
	if (file == NULL)
	{
		printf("Error opneing the file.\n");
		return 1;
	}
	
	fprintf(file,",,,,,,The characteristic roots:\n,,,,,,Alpha=%.3lf ,,,W=%.3lf\n ,,,,,,S1=%.2lf ,,,S2=%.2lf\n ,,,,,,A1=%.4lf ,,,A2=%.4lf\n ,,,,,,dvdt=%.2lf\n", Alfa, W, S1, S2, A1, A2, dvdt);
    
	if  (Alfa<W)
	{
        fprintf(file,",,,,,,Wd=j%.4lf\n\n\n", Wd);
    }
	
	fprintf(file, "Time values,V values\n");
	
	for(i =  0; i <= n; i++)
	{
		fprintf(file,"%lf,%lf\n", i*dt , Vt[i]);
	}

	fclose(file);
	
	return 0;
}

