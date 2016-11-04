#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d",&n);

	float a[n+1][n+1];

	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){

			printf("a[%d][%d] = ",i,j);
			scanf("%f",&a[i][j]);

		}

	}

	float b[n+1][n+1];
	float d[n+1][n+1];
	float c[n+2];

	for (int i=1; i<=n; i++){

		for (int j=1; j<=n; j++){

			if (i==j){

				b[i][j] = 1;

			} else {

				b[i][j] = 0;

			}

		}

	}

	for (int k=1; k<=n-1; k++){

		for (int i=1; i<=n; i++){

			for (int j=1; j<=n; j++){

				d[i][j] = 0;

				for (int h=1; h<=n; h++){
					d[i][j] = d[i][j] + a[i][h] * b[h][j];
				}

 			}

		}

		c[k] = 0;

		for (int i=1; i<=n; i++){

			c[k] = c[k] + d[i][i];

		}

		c[k] = -c[k]/k;

		for (int i=1; i<=n; i++){

			for (int j=1; j<=n; j++){

				if (i==j){

					b[i][j] = d[i][j] +c[k];

				} else {

					b[i][j] = d[i][j];

				}

			}

		}

	}

	for (int i=1; i<=n; i++){

		for (int j=1; j<=n; j++){

			d[i][j] = 0;

			for (int h=1; h<=n; h++){

				d[i][j] = d[i][j] + a[i][h]*b[h][j];

			}

		}

	}

	c[n] = 0;

	for (int i=1; i<=n; i++){

		c[n] = c[n] + d[i][i];

	}

	c[n] = -c[n]/n;

	if (c[n] == 0){

		printf("nu e inversabila \n");

	} else {

		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){

				printf(" %f ",-b[i][j]/c[n]);

			}
			printf("\n");
		}

	}

	printf("\n coef pol caract:  ");

	for (int i=1; i<=n; i++){
		printf(" %f ",c[i]);
	}
	printf("\n");

	// bairstrow

	float a2[n+1];

	a2[0] = 1;

	for (int i=1; i<=n; i++){

		a2[i] = c[i];

	}

	float b2[n+1], c2[n+1], delta, R, S, x1, x2;

	while (n>2){

		float p,q,eps;

		printf("p = ");
		scanf("%f",&p);

		printf("q = ");
		scanf("%f",&q);

		printf("eps = ");
		scanf("%f",&eps);

		do {

			b2[0] = a2[0];
			b2[1] = a2[1] - p*b2[0];

			for (int k=2; k<=n; k++){

				b2[k] = a2[k] - p * b2[k-1] - q * b2[k-2];

			}

			c2[0] = b2[0];
			c2[1] = b2[1] - p * c2[0];

			for (int k=2; k<=n; k++){

				c2[k] = b2[k] - p * c2[k-1] - q * c2[k-2];

			}

			delta = c2[n-2]*c2[n-2] - c2[n-1] * c2[n-3] + b2[n-1] * c2[n-3];
			R = b2[n] * c2[n-3] - b2[n-1] * c2[n-2];
			S = b2[n-1] * c2[n-1] - b2[n-1] * b2[n-1] - b2[n] * c2[n-2];
			p = p - R/delta;
			q = q - S/delta;

		} while (fabs((R+S)/delta) > eps );

		printf("p = %f  q = %f ",p,q);

		if (p*p - 4*q >= 0){

			x1 = (-p-sqrt(p*p-4*q)) / 2;
			x2 = (-p+sqrt(p*p-4*q)) / 2;
			printf("x1 = %f x2 = %f reale",x1,x2);
			printf("\n");

		} else {

			printf("x1 = %f - i * %f",-p/2,sqrt(4*q-(p*p)));
			printf("x2 = %f + i * %f",-p/2,sqrt(4*q-(p*p)));
			printf("\n");
		}

		n = n-2;
		for (int k=0; k<=n; k++){

			a2[k] = b2[k];

		}
	}

	if (n==1){

		printf(" se obtine un factor liniar cu solutia x1 = %f \n", -b2[1]/b2[0]);

	} else {

		printf("se obtine un factor patratic \n");
		if (b2[1]*b2[1] - 4*b2[0]*b2[2] >= 0 ) {

			x1 = (-b2[1] - sqrt(b2[1]*b2[1]-4*b2[0]*b2[2]))/(2*b2[0]);
			x2 = (-b2[1] + sqrt(b2[1]*b2[1]-4*b2[0]*b2[2]))/(2*b2[0]);
			printf("x1 = %f x2 = %f reale \n",x1,x2);

		} else {

			printf("x1 = %f - i %f",-b2[1]/(2*b2[0]),sqrt(4*b2[0]*b2[2]-b2[1]*b2[1]));
			printf("x2 = %f + i %f",-b2[1]/(2*b2[0]),sqrt(4*b2[0]*b2[2]-b2[1]*b2[1]));

		}

	}



}
