// Welcome to scientific calculator Cni_math_v1 made by ayaan
#include<stdio.h>
#include<math.h>

int
main ()
{
  char opr;
  int m,q;
  int a, b, c;
  int n, choice;
  int matrix1[n][n], matrix2[n][n], result[n][n];
  float x, y, z;
  int choie;
  double angle;
  
  printf ("Welcome to scientific calculator Calcumate_v1 \n");
  start:
  printf ("chose your mode\n 1.Simple calculatin \n2.Mtrix calculatins\n 3.Polynomial equations\n 4. Trigonometry calcutions\n");
  scanf ("%d", &m);
  switch (m)
	{
	case 1: ///simple
	  {
      printf("\nWelcome to simple mode\n");
		printf ("Enter 2 numbers for the operations\n");
		scanf ("%d\n%d", &a, &b);
		printf ("Enter any operator of the following\n'+'\n'-'\n'*'\n'/'\n");
		scanf ("%s", &opr);

		switch (opr)
		  {
		  case '+':
			c = a + b;
			printf ("adding 2 numbers is %d", c);
			break;
		  case '-':
			c = a - b;
			printf ("subtracting 2 numbers is %d", c);
			break;
		  case '*':
			c = a * b;
			printf ("multiplying2 numbers is %d", c);
			break;
		  case '/':
			c = a / b;
			printf ("dividing2 numbers is %d", c);
			break;
		  default:
			printf ("invalid operator");
		  }
      printf ("\ndo you countine press 1 and 2 to exit");
        scanf ("%d",&q);
        if(q<=1);
        goto start;
        
      break;
	  }
	case 2: //matrix
	  {
		printf ("\nWelcome to matrix mode\n");
		printf ("Enter the size of the matrices (nxn): ");
		scanf ("%d", &n);
// Input elements for matrix 1
		printf ("Enter elements of matrix 1:\n");
		for (int i = 0; i < n; i++)
		  {
			for (int j = 0; j < n; j++)
			  {
				scanf ("%d", &matrix1[i][j]);
			  }
		  }

		// Input elements for matrix 2
		printf ("Enter elements of matrix 2:\n");
		for (int i = 0; i < n; i++)
		  {
			for (int j = 0; j < n; j++)
			  {
				scanf ("%d", &matrix2[i][j]);
			  }
		  }

		{
		  printf ("\nSelect an operation:\n");
		  printf ("1. Addition\n");
		  printf ("2. Subtraction\n");
		  printf ("3. Multiplication\n");
		  printf ("4. Transpose of matrix 1\n");
		  printf ("5. Transpose of matrix 2\n");
		  printf ("6. Exit\n");
		  printf ("Enter your choice: ");
		  scanf ("%d", &choice);

		  switch (choice)
			{
			case 1:
			  // Add matrices
			  for (int i = 0; i < n; i++)
				{
				  for (int j = 0; j < n; j++)
					{
					  result[i][j] = matrix1[i][j] + matrix2[i][j];
					}
				}
			  printf ("The sum of the matrices:\n");
			  for (int i = 0; i < n; i++)
				{
				  for (int j = 0; j < n; j++)
					{
					  printf ("%d ", result[i][j]);
					}
				  printf ("\n");
				}
			  break;
			case 2:
			  // Subtract matrices
			  for (int i = 0; i < n; i++)
				{
				  for (int j = 0; j < n; j++)
					{
					  result[i][j] = matrix1[i][j] - matrix2[i][j];
					}
				}
			  printf ("The difference of the matrices:\n");
			  for (int i = 0; i < n; i++)
				{
				  for (int j = 0; j < n; j++)
					{
					  printf ("%d ", result[i][j]);
					}
				  printf ("\n");
				}
			  break;
			case 3:
			  // Multiply matrices
			  if (n != matrix2[0][0])
				{				// Check if compatible for multiplication
				  printf
					("Error: Matrix dimensions incompatible for multiplication.\n");
				}
			  else
				{
				  for (int i = 0; i < n; i++)
					{
					  for (int j = 0; j < n; j++)
						{
						  result[i][j] = 0;
						  for (int k = 0; k < n; k++)
							{
							  result[i][j] += matrix1[i][k] * matrix2[k][j];
							}
						}
					}
				  printf ("The product of the matrices:\n");
				  for (int i = 0; i < n; i++)
					{
					  for (int j = 0; j < n; j++)
						{
						  printf ("%d ", result[i][j]);
						}
					  printf ("\n");
					}
				}
			  break;
			case 4:
			  // Transpose of matrix 1
			  for (int i = 0; i < n; i++)
				{
				  for (int j = 0; j < n; j++)
					{
					  result[j][i] = matrix1[i][j];
					}
				}
			  printf ("The transpose of matrix 1:\n");
			  for (int i = 0; i < n; i++)
				{
				  for (int j = 0; j < n; j++)
					{
					  printf ("%d ", result[i][j]);
					}
				  printf ("\n");
				}
			  break;
			}

		
		}
      printf ("\ndo you countine press 1 and 2 to exit");
        scanf ("%d",&q);
        if(q<=1)
        goto start;
        
			break;
	  }
	case 3:  //poly
    {
    printf("\nPolynomial eqaution mode\n");
        printf("Enter coefficient a: ");
    scanf("%f", &x);
    
    printf("Enter coefficient b: ");
    scanf("%f", &y);

    printf("Enter coefficient c: ");
    scanf("%f", &z);

    // Calculate the discriminant
    float discriminant = y * y - 4 * x * z;

    // Calculate roots based on the discriminant
    if (discriminant > 0) {
        // Two real and distinct roots
        float root1 = (-y + sqrt(discriminant)) / (2 * x);
        float root2 = (-y - sqrt(discriminant)) / (2 * x);

        printf("Roots are real and distinct: %.2f and %.2f\n", root1, root2);
    } else if (discriminant == 0) {
        // Two real and equal roots
        float root = -y / (2 * x);

        printf("Roots are real and equal: %.2f\n", root);
    } else {
        // Complex roots
        float realPart = -y / (2 * x);
        float imaginaryPart = sqrt(fabs(discriminant)) / (2 * x);

        printf("Roots are complex: %.2f + %.2fi and %.2f - %.2fi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }
      printf ("\ndo you countine press 1 and 2 to exit");
        scanf ("%d",&q);
        if(q<=1)
        goto start;
        
			
        break;
    }
  case 4: //trigo
  { printf("\n Trigomenty mode\n");
    printf("\nEnter an angle in degrees:\n ");
    scanf("%lf", &angle);

    // Convert angle to radians
    double radians = angle * M_PI / 180.0;

    // Menu for trigonometric calculations
    printf("\nTrigonometric Calculations:\n");
    printf("1. Sine\n");
    printf("2. Cosine\n");
    printf("3. Tangent\n");
    printf("Enter your choice (1/2/3): \n");

    
    scanf("%d", &choie);

    // Perform trigonometric calculations based on user choice
    switch (choie) {
        case 1:
            printf("Sine(%lf) = %.4lf\n", angle, sin(radians));
            break;
        case 2:
            printf("Cosine(%lf) = %.4lf\n", angle, cos(radians));
            break;
        case 3:
            // Check if tangent is undefined for 90 and 270 degrees
            if (angle == 90 || angle == 270) {
                printf("Tangent(%lf) is undefined.\n", angle);
            } else {
                printf("Tangent(%lf) = %.4lf\n", angle, tan(radians));
            }
            break;
        default:
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
    }
    printf ("\ndo you countine press 1 and 2 to exit");
        scanf ("%d",&q);
        if(q<=1)
        goto start;
        else
			break;
  }
  case 5: 
  { printf("hello this ayaan");
   break;
  }  
  
  }
  printf("\nThanks for using scientific calculator Cni_math_v1");   
}
  
//this is scientific calculator made by ayaan.
