#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

double f(double x)
{
    return 8 - pow(x, 2);
}
double f1(double x)
{
    return -2*x; // похідна першого порядку
}
double f2(double x)
{
    return -2;  // похідна другого порядку
}

int main()
{
   double a, b, e, x, start1, start2, start3, start, end1, end2, end3, end, time1 = 0, time2 = 0,time3 = 0, time, time_general;
   int k, var, var1, var2, numb_of_iterations;
   a = 1; b = 9; e = 0.0001;
   printf("First limit\t Second limit\t Error\n");
   printf("%.lf\t\t %.lf\t\t %.4lf\n", a, b, e);
   printf("Enter number \"1\" if you want to solve the equation by the method of Half Division\n");
   printf("Enter number \"2\" if you want to solve the equation by the method of Newton\n");
   printf("Enter number 3");
   printf("Choose your method: ");
   scanf("%d", &var);
   printf("Enter the number of iterations before pause: ");
   scanf("%d", &numb_of_iterations);
   printf("The number of iterations before pause: %d\n", numb_of_iterations);
   if(var == 1){
   if(f(a)*f(b) < 0){
    printf("The convergence condition is satisfied\n");
    k = 1;
    while(true){
        if(var2 == 1)
            {
                start1 = clock();
                x = (a + b)/2;
                k++;
                if(fabs(f(x)) < e)
                    break;
                if(f(a)*f(x) < 0){
                    a = a; b = x;
                }
                else{
                    a = x; b = b;

                }
                end1 = clock();
                time1 = time1 + (end1 - start1);
            }
        else if(k%numb_of_iterations == 0){
            printf("Number of iterations: %d\n", k);
            printf("Enter the number \"1\" if you want to change the number of iterations\n");
            printf("Enter the number \"2\" if you want to continue\n");
            printf("Enter the number \"3\" if you want to finish with this number of iterations\n");
            printf("Your choise: \n");
            scanf("%d", &var1);
            if(var1 == 2){
                start2 = clock();
                x = (a + b)/2;
                k++;
                if(fabs(f(x)) < e)
                    break;
                if(f(a)*f(x) < 0){
                    a = a; b = x;
                }
                else{
                    a = x; b = b;
                }
            }
            else if(var1 == 1){
                k++;
                var2 =1;
            }
            else if(var1 == 3){break;}
            end2 = clock();
            time2 = time2 + (end2 - start2);
        }

        else{
            start3 = clock();
            x = (a + b)/2;
                k++;
                if(fabs(f(x)) < e)
                    break;
                if(f(a)*f(x) < 0){
                    a = a; b = x;
                }
                else{
                    a = x; b = b;
                }
                end3 = clock();
                time3 = time3 + (end3 - start3);
        }
    }
    printf("x = %lf\n", x);
    printf("Number of iterations k = %d\n", k);

   }
   else{
    printf("The convergence condition is not satisfied\n");
   }
   time_general = (time1+time2+time3)/ (CLOCKS_PER_SEC);
   printf("Time for calculating the quantity of x = %lf seconds\n", time_general);
   }

   if(var == 2){
   start = clock();
   if(f(a)*f2(a) > 0){
    printf("The convergence condition is satisfied x = a = %.lf\n", a);
    x = a;
   }
   else{
        if(f(b)*f2(b) > 0){
    printf("The convergence condition is satisfied x = b = %.lf\n", b);
    x = b;
   }
   else{
    printf("The convergence condition is not satisfied\n");
    x = -10E10;
   }
   }
   end = clock();
   time = end - start;
   if(x > -10E10){
    int k1 = 1;
    while(true){
            if(var2 == 1){
        start1 = clock();
        x = x - f(x)/f1(x);
        k1++;
        if(fabs(f(x)) < e)
            break;
            end1 =clock();
            time1 = time1 + (end1 - start1);
    }

    else if(k1%numb_of_iterations == 0){
            printf("Number of iterations: %d\n", k1);
            printf("Enter the number \"1\" if you want to change the number of iterations\n");
            printf("Enter the number \"2\" if you want to continue\n");
            printf("Enter the number \"3\" if you want to finish with this number of iterations\n");
            printf("Your choise: \n");
            scanf("%d", &var1);
        start2 = clock();
        if(var1 == 1){
            var2 = 1;
            k1++;
        }
        if(var1 == 2){
        x = x - f(x)/f1(x);
        k1++;
        if(fabs(f(x)) < e)break;
        }
        if(var1 == 3)break;
        end2 = clock();
        time2 = end2 - start2;
    }
    else{
        start3 = clock();
      x = x - f(x)/f1(x);
        k1++;
        if(fabs(f(x)) < e)break;
        }
        end3 = clock();
        time3 = end3 - start3;
    }


    printf("x = %lf\n", x);
    printf("Number of iterations k = %d\n", k1);
    }
    time_general = (time + time1 + time2 + time3)/(CLOCKS_PER_SEC);
    printf("Time for calculating the quantity of x = %lf seconds\n", time_general);
   }
   if(var == 3){
    printf("You chose method 3");
   }




    return 0;
}
