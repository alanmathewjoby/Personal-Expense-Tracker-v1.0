#include <stdio.h>
#include <string.h>

// Structure definition
struct Expense {
    char date[12];
    char category[30];
    float amount;
};

// Global array and counter
struct Expense expenses[100];
int count = 0;

// Function prototypes
void add_expense(struct Expense expenses[], int *count);
void display_expense(struct Expense expenses[], int count);
void total_spending(struct Expense expenses[], int count);
void avg_spending(struct Expense expenses[], int count);
void sort_by_amount(struct Expense expenses[], int count);
void search_by_category(struct Expense expenses[], int count);
void menu(); // recursive menu

// Function implementations

void add_expense(struct Expense expenses[], int *count) {
    printf("\n--- Add New Expense ---\n");
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", expenses[*count].date);

    printf("Enter category: ");
    scanf("%s", expenses[*count].category);

    printf("Enter amount: ");
    scanf("%f", &expenses[*count].amount);

    (*count)++;
    printf("Expense added successfully!\n");
}

void display_expense(struct Expense expenses[], int count) {
    if (count == 0) {
        printf("\nNo expenses recorded yet.\n");
        return;
    }

    printf("\n--- Expense List ---\n");
    printf("%-12s %-15s %-10s\n", "Date", "Category", "Amount");
    printf("------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-12s %-15s %-10.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
    }
}

void total_spending(struct Expense expenses[], int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    printf("\nTotal spending: %.2f\n", total);
}

void avg_spending(struct Expense expenses[], int count) {
    if (count == 0) {
        printf("\nNo expenses to calculate average.\n");
        return;
    }
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    float avg = total / count;
    printf("\nAverage spending per entry: %.2f\n", avg);
}

void sort_by_amount(struct Expense expenses[], int count) {
    struct Expense temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (expenses[j].amount > expenses[j + 1].amount) {
                temp = expenses[j];
                expenses[j] = expenses[j + 1];
                expenses[j + 1] = temp;
            }
        }
    }
    printf("\nExpenses sorted by amount (ascending).\n");
}

void search_by_category(struct Expense expenses[], int count) {
    if (count == 0) {
        printf("\nNo expenses to search.\n");
        return;
    }

    char cat[30];
    printf("Enter category to search: ");
    scanf("%s", cat);
    int found = 0;

    printf("\nResults for category '%s':\n", cat);
    for (int i = 0; i < count; i++) {
        if (strcmp(expenses[i].category, cat) == 0) {
            printf("%-12s %-15s %.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
            found = 1;
        }
    }

    if (!found)
        printf("No expenses found for category: %s\n", cat);
}

// Recursive menu function
void menu() {
    int choice;
    printf("\n===== PERSONAL EXPENSE TRACKER v1.0 =====\n");
    printf("1. Add Expense\n");
    printf("2. Display All Expenses\n");
    printf("3. Total Spending\n");
    printf("4. Average Spending\n");
    printf("5. Sort by Amount\n");
    printf("6. Search by Category\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_expense(expenses, &count);
            break;
        case 2:
            display_expense(expenses, count);
            break;
        case 3:
            total_spending(expenses, count);
            break;
        case 4:
            avg_spending(expenses, count);
            break;
        case 5:
            sort_by_amount(expenses, count);
            break;
        case 6:
            search_by_category(expenses, count);
            break;
        case 7:
            printf("\nExiting program. Goodbye!\n");
            return;
        default:
            printf("Invalid choice! Please try again.\n");
    }

    menu(); // recursion to repeat menu
}

int main() {
    menu();
    return 0;
}
