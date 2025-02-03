//lab5 ex8
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LENGTH 50

// Structure to hold employee information
typedef struct {
    int id;
    char name[NAME_LENGTH];
    char surname[NAME_LENGTH];
    float monthly_salary;
} Employee;

// Function prototypes
void add_employee(Employee *employees, int *count, int id, const char *name, const char *surname, float salary);
void print_employees_by_index(Employee *employees, int *index, int count);
void generate_id_index(int *index, Employee *employees, int count);
void generate_surname_index(int *index, Employee *employees, int count);
int compare_by_id(const void *a, const void *b, void *employees);
int compare_by_surname(const void *a, const void *b, void *employees);

// Main function
int main() {
    Employee employees[MAX_EMPLOYEES];
    int id_index[MAX_EMPLOYEES];
    int surname_index[MAX_EMPLOYEES];
    int employee_count = 0;

    // Adding some employees to the database
    add_employee(employees, &employee_count, 102, "Alice", "Smith", 3000.0);
    add_employee(employees, &employee_count, 101, "Bob", "Johnson", 2800.0);
    add_employee(employees, &employee_count, 104, "Charlie", "Brown", 3200.0);
    add_employee(employees, &employee_count, 103, "Diana", "Miller", 2900.0);

    // Generate indexes
    generate_id_index(id_index, employees, employee_count);
    generate_surname_index(surname_index, employees, employee_count);

    // Print employees sorted by ID
    printf("Employees sorted by ID:\n");
    print_employees_by_index(employees, id_index, employee_count);

    // Print employees sorted by Surname
    printf("\nEmployees sorted by Surname:\n");
    print_employees_by_index(employees, surname_index, employee_count);

    return 0;
}

// Function to add an employee to the database
void add_employee(Employee *employees, int *count, int id, const char *name, const char *surname, float salary) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Database is full!\n");
        return;
    }
    employees[*count].id = id;
    strncpy(employees[*count].name, name, NAME_LENGTH);
    strncpy(employees[*count].surname, surname, NAME_LENGTH);
    employees[*count].monthly_salary = salary;
    (*count)++;
}

// Function to print employees based on a given index array
void print_employees_by_index(Employee *employees, int *index, int count) {
    for (int i = 0; i < count; i++) {
        int idx = index[i];
        printf("ID: %d, Name: %s %s, Monthly Salary: %.2f\n",
               employees[idx].id, employees[idx].name, employees[idx].surname, employees[idx].monthly_salary);
    }
}

// Function to generate index sorted by ID
void generate_id_index(int *index, Employee *employees, int count) {
    for (int i = 0; i < count; i++) {
        index[i] = i;
    }
    qsort_r(index, count, sizeof(int), compare_by_id, employees);
}

// Function to generate index sorted by Surname
void generate_surname_index(int *index, Employee *employees, int count) {
    for (int i = 0; i < count; i++) {
        index[i] = i;
    }
    qsort_r(index, count, sizeof(int), compare_by_surname, employees);
}

// Comparison function for sorting by ID
int compare_by_id(const void *a, const void *b, void *employees) {
    int idx_a = *(int *)a;
    int idx_b = *(int *)b;
    Employee *emp = (Employee *)employees;

    return (emp[idx_a].id - emp[idx_b].id);
}

// Comparison function for sorting by Surname
int compare_by_surname(const void *a, const void *b, void *employees) {
    int idx_a = *(int *)a;
    int idx_b = *(int *)b;
    Employee *emp = (Employee *)employees;

    return strcmp(emp[idx_a].surname, emp[idx_b].surname);
}
