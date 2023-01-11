#include <stdio.h>
#include <math.h>
#include <time.h>
int main() {
	
	double R, L, C, V_infinity, V0, Ic, A1, A2, Alfa, W, root, S1, S2, t, dt, dvdt, Wd;
	int i, n;
	printf("\n Merhaba, Kullanici! Bu program Seri RLC devrelerindeki kapasitor (C) üzerindeki gerilim değişimini degerini hesaplar\n\n Lutfen istenen degerleri giriniz");
	printf("\n\n R degeri giriniz..:");  scanf("%lf", &R);
	printf("\n L degeri giriniz..:");  scanf("%lf", &L);
	printf("\n C degeri giriniz..:");  scanf("%lf", &C);
	printf("\n V(0) degeri giriniz..:");  scanf("%lf", &V0);
	printf("\n V_infinity degeri giriniz..:");  scanf("%lf", &V_infinity);
	printf("\n Ic(0) degeri giriniz..:");  scanf("%lf", &Ic);
	printf("\n Kod calisma suresi giriniz..:");  scanf("%lf", &t);
	printf("\n Zaman adimin degeri giriniz..:");  scanf("%lf", &dt);

	Alfa = R / (2 * L);
	W = 1 / sqrt(L * C); 
	dvdt = (Ic / C);
	n = (t / dt); // programın kendisini kaç kez tekrarlayacağını bildirmek için
	double Vt[n+1]; 

	for (i = 0; i < n+1 ; i++) //	i burada çarpan görevi görür, i arttıkça t degeri de artar 
	{	
		if(Alfa > W) // Aşırı Sönümlü
			{	
			
				root = pow(Alfa, 2) - pow(W, 2);
				S1 = -Alfa + sqrt(root);
				S2 = -Alfa - sqrt(root);
				A1 = (dvdt + S2 * (V_infinity - V0)) / (S1 - S2);
				A2 = (dvdt + S1 * (V_infinity - V0)) / (S2 - S1);
				Vt[i] = V_infinity + (A1 * exp(S1 * (i*dt))) + (A2 * exp(S2 * (i*dt)));
				
			
				printf("\n\n at t = %lf\t\t V   =   %lf\n", i*dt , Vt[i]);
			}
		else if(Alfa == W) // Kritik Sönümlü
			{
				A1 = V0 - V_infinity;
				A2 = dvdt + Alfa * A1;
				Vt[i] = V_infinity + (A1 + A2 * (i*dt)) * exp(-Alfa * (i*dt));
				printf("at t = %lf\t\t V   =   %lf\n", i*dt , Vt[i]);
			}
		else  // Sönümlü
			{
				root = pow(W, 2) - pow(Alfa, 2);
				Wd = sqrt(root);
				A1 = V0 - V_infinity;
				A2 = (dvdt + Alfa * A1) / Wd;
				Vt[i] = V_infinity + (exp(-Alfa * (i*dt)) * ((A1 * cos(Wd * (i*dt))) + (A2 * sin(Wd * (i*dt)))));
				printf(" at t = %lf\t\t V   =   %lf\n", i*dt , Vt[i]);
			}
	}
		
	FILE *file; 
	file = fopen("Bulunan_degerler.csv", "w");  //Dosya oluşturmak icin
	
	if (file == NULL) // Eğer dosya açılımında arıza varsa 1 iade eder 
	{
		printf("Dosya acilirken hata olustu.\n");
		return 1;
	}
	
	fprintf(file,",,,,,,Karakteristik kokler:\n,,,,,,Alpha= %.3lf ,,,W= %.3lf\n ,,,,,,A1= %.4lf ,,,A2= %.4lf\n ,,,,,,dvdt= %.2lf\n", Alfa, W, A1, A2, dvdt);
    	
		if  (Alfa > W) // Wd degeri yazdırmak icin
	{
        fprintf(file,",,,,,,S1= %.2lf ,,,S2= %.2lf\n", S1, S2);
    }
    
	if  (Alfa < W) // Wd degeri yazdırmak icin
	{
        fprintf(file,",,,,,,Wd= j%.4lf\n\n\n", Wd);
    }
	
	fprintf(file, "Zaman degerleri,V degerleri\n");
	
	for(i =  0; i <= n; i++) // Bulunan değerleri dosyada yazdırmak için
	{
		fprintf(file,"%lf,%lf\n", i*dt , Vt[i]);
	}

		fclose(file); // Dosya kaptmak icin
	
		printf("\n\nIsleminiz basarili bir sekilde gerceklesmistir. V(t) degerleri Excel dosyasinda bulacaksiniz.");
	
	return 0;
}

