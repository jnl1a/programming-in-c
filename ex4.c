#include <stdio.h>
#include <string.h>

//helped from chatgpt

#define max_name_length 10
#define max_employees 10

//structure holding info
typedef struct {
    char name[max_name_length + 1];  // +1 for null terminator
    char surname[max_name_length + 1];
    int age;
    double monthly_salary;
} Employee;

//input employee data
void input_employee(Employee *emp) { //emp is a pointer to employee struct
    printf("Enter name: ");
    scanf("%s", emp->name);
    if (strlen(emp->name) > max_name_length) {
        emp->name[max_name_length] = '\0';  // Truncate name
    }
// truncation: to cut off a string when too long to limit the length
    printf("Enter surname: ");
    scanf("%s", emp->surname);
    if (strlen(emp->surname) > max_name_length) {
        emp->surname[max_name_length] = '\0';  // Truncate surname
    }

    printf("Enter age: ");
    scanf("%d", &emp->age);

    printf("Enter monthly salary: ");
    scanf("%lf", &emp->monthly_salary);
}

//table format display
void display_employees(Employee employees[], int count, int precision) {
    printf("\n%-4s %-10s %-10s %-4s %*s\n", "No", "Name", "Surname", "Age", precision + 9, "Yearly Salary");
    printf("-------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        double yearly_salary = employees[i].monthly_salary * 13;
        printf("%-4d %-10s %-10s %-4d %*.2f\n", i + 1, employees[i].name, employees[i].surname, employees[i].age, precision + 9, yearly_salary);
    }
}

int main() {
    Employee employees[max_employees];
    int count = 0;
    int precision;

    printf("Enter the precision for salary columns (0 for no decimal places, up to 2): ");
    scanf("%d", &precision);
    if (precision < 0 || precision > 2) {
        printf("Invalid precision. Defaulting to 2.\n");
        precision = 2;
    }

    for (int i = 0; i < max_employees; i++) {
        printf("\nEntering details for employee %d:\n", i + 1);
        input_employee(&employees[i]);
        count++;

        if (count % 5 == 0) {
            display_employees(employees, count, precision);
        }
    }

    // Final display after all entries
    display_employees(employees, count, precision);

    // Calculate average salary
    double total_salary = 0.0;
    for (int i = 0; i < count; i++) {
        total_salary += employees[i].monthly_salary;
    }
    double average_salary = total_salary / count;

    printf("\nAverage monthly salary: %.2f\n", average_salary);
    return 0;
}