/* Temperature Converter
 *
 * Takes three arguments, a start
 * temperature (in C), an end temperature
 * (in C) and a step size in order to print out
 * a table that goes from the start temperature
 * to the end temperature, in steps of the step size.
 *
 * Performs input validation; does not accept start
 * temperature less than a lower limit or higher than
 * and upper limit. Step size cannot be larger than 
 * the difference in the high and low temp.
 */
# include <stdio.h>

# define LOWER_LIMIT 0
# define UPPER_LIMIT 50000 

/* provide prototypes */
double convert_temp_c_to_f(double temp_c);
void print_results(int limit_low, int limit_high, int step);

int main(void) { 
    
    double temp_c, temp_f;

    int limit_low = -1;
    int limit_high = -1;
    int step = -1;

    /* Read in lower, high limit and step */
    while (limit_low <= (int) LOWER_LIMIT) {
        printf("Please provide a lower limit, limit >= %d: ", (int) LOWER_LIMIT);
        scanf("%d", &limit_low);
    }

    while ((limit_high < limit_low) || (limit_high > (int) UPPER_LIMIT)) {
        printf("Please provide an upper limit, %d < limit <= %d: ", limit_low, (int) UPPER_LIMIT);
        scanf("%d", &limit_high); 
    }

    while (step <=  0 || step  > (limit_high - limit_low)) {
        printf("Please provide a step size, 0 < step_size < %d: ", limit_high - limit_low);
        scanf("%d", &step);
    }
    
    print_results(limit_low, limit_high, step);
    return 0; 
}

double convert_temp_c_to_f(double temp_c) {
    return (9.0 * temp_c) / 5 + 32;
}

void print_results(int limit_low, int limit_high, int step) {
    printf("\nCelcius\t\tFahrenheit\n---------\t----------\n");
    
    while(limit_low <= limit_high) {
        printf("%d\t\t%f\n", limit_low, convert_temp_c_to_f(limit_low));;
        limit_low += step;
    }
}


