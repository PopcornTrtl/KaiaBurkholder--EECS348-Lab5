#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_report(char file_name[50], double monthly_sales[12])
{
    FILE *report_ptr;
    char line[50];
    //opens given file on read mode
    report_ptr = fopen(file_name, "r");
    //for each line of the file, converts it to a double + adds it to the monthly_sales array
    int index = 0;
    while(fgets(line, 50, report_ptr))
    {
        monthly_sales[index] = strtod(line, NULL);
        index++;
    }
}
//given an index, returns the corresponding month
char* sales_month(int index)
{
    switch(index)
    {
        case 0:
            return "January";
            break;
        case 1:
            return "February";
            break;
        case 2:
            return "March";
            break;
        case 3:
            return  "April";
            break;
        case 4:
            return "May";
            break;
        case 5:
            return "June";
            break;
        case 6:
            return "July";
            break;
        case 7:
            return "August";
            break;
        case 8:
            return "September";
            break;
        case 9:
            return "October";
            break;
        case 10:
            return "November";
            break;
        case 11:
            return "December";
            break;
    }
}

//finds average sales over 6 months, starting from a given month point
double six_month_average(double monthly_report[12], int index)
{
    double average = monthly_report[index] + monthly_report[index+1] + monthly_report[index + 2] + monthly_report[index + 3] + monthly_report[index + 4] + monthly_report[index + 5];
    average /= 6;

    return average;
}
//Finds the average of all the sales
double average_sales(double monthly_report[12])
{
    double average = 0;
    for(int index = 0; index < 12; index++)
    {
        average += monthly_report[index];
    }
    average /= 12;

    return average;
}
//finds the largest sales
double max_sales(double monthly_report[12], int* max_index)
{
    double max = 0.0;
    for (int index = 0; index < 12; index++)
    {
        if (monthly_report[index] > max)
        {
            max = monthly_report[index];
            *max_index = index;
        }
    }

    return max;
}
//finds the smallest sales
double min_sales(double monthly_report[12], int* min_index)
{
    double min;
    for (int index = 0; index < 12; index++)
    {
        if (index == 0)
        {
            min = monthly_report[index];
        }
        else if (monthly_report[index] < min)
        {
            min = monthly_report[index];
            *min_index = index;
        }
    }

    return min;
}
//sorts the report from largest to smallest + prints them
void sort_report(double monthly_report[12])
{
    double sorted_report[12];
    int index_array[12];
    int sorted_size = 0;
    //for every sales num in monthly_report, iterates through until it finds a larger number or reaches index 0, then shifts everything after it to the right + inserts it
    for (int index = 0; index < 12; index++)
    {
        if(sorted_size == 0)
        {
            sorted_report[0] = monthly_report[index];
            index_array[0] = index;
            sorted_size++;
        }
        else
        {
            int sorted_index = sorted_size;
            while (sorted_index > 0 && monthly_report[index] > sorted_report[sorted_index - 1])
            {
                sorted_index--;
            }

            for(int inter_index = sorted_size - 1; inter_index >= sorted_index; inter_index--)
            {
                sorted_report[inter_index + 1] = sorted_report[inter_index];
                index_array[inter_index + 1] = index_array[inter_index];
            }

            sorted_report[sorted_index] = monthly_report[index];
            index_array[sorted_index] = index;
            sorted_size++;
        }
    }
    //prints sales numbers in order w/ corresponding month
    printf("\nSales report (highest to lowest):\n\n");
    printf("Month      Sales\n");

    for (int index = 0; index < 12; index++)
    {
        printf("%s:  %.2f\n", sales_month(index_array[index]), sorted_report[index]);
    }
}
//prints all necessary stats
void print_full_report(double monthly_report[12])
{
    int max_index, min_index;
    double max = max_sales(monthly_report, &max_index);
    double min = min_sales(monthly_report, &min_index);
    printf("Monthly sales report for 2024\n\n");
    printf("Month      Sales\n");
    //prints sales for every month
    for(int index = 0; index < 12; index++)
    {
        printf("%s:   %.2f\n", sales_month(index), monthly_report[index]);
    }
    //prints the max, min, and average sales
    printf("\nSales Summary Report:\n\n");
    printf("Minimum Sales: %.2f (%s)\n", min, sales_month(min_index));
    printf("Maximum Sales: %.2f (%s)\n", max, sales_month(max_index));
    printf("Average Sales: %.2f\n", average_sales(monthly_report));
    //prints the average over multiple 6-month periods
    printf("\nSix Month Moving Average Report:\n\n");
    for(int index = 0; index + 5 < 12; index++)
    {
        printf("%s-%s:   %.2f\n", sales_month(index), sales_month(index + 5), six_month_average(monthly_report, index));
    }
    //prints sales ordered largest ot smallest
    sort_report(monthly_report);


}


int main()
{
    //asks user for the file being used
    char file_name[50];
    printf("Enter the file name of the report: ");
    scanf("%s", &file_name);

    double monthly_report[12];
    //reads report + saves sales numbers to be used
    read_report(file_name, monthly_report);
    //prints out all of the data to the user
    print_full_report(monthly_report);
    return 0;
}