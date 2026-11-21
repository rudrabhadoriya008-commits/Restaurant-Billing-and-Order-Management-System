#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

int main()
{
    string customerName;

    int choice, quantity;
    int itemCount = 0;
    const int MAX_ORDERS = 20;
    const int MENU_SIZE = 8;

    // Restaurant menu
    string items[MENU_SIZE] = {
        "Burger",
        "Pizza",
        "Sandwich",
        "Coffee",
        "Cold Drink",
        "French Fries",
        "Pasta",
        "Ice Cream"
    };

    int prices[MENU_SIZE] = {80, 150, 60, 40, 30, 70, 120, 50};

    // Arrays to store ordered items
    string orderedItems[MAX_ORDERS];
    int orderedQty[MAX_ORDERS];
    int orderedPrice[MAX_ORDERS];

    double subtotal = 0;
    double gst = 0;
    double finalAmount = 0;

    cout << "========================================\n";
    cout << "       WELCOME TO OUR RESTAURANT\n";
    cout << "========================================\n";

    cout << "Enter Customer Name: ";
    getline(cin, customerName);

    // Check empty customer name
    if (customerName.empty())
    {
        customerName = "Guest";
    }

    int running = 1;

    while (running == 1)
    {
        cout << "\n------------- RESTAURANT MENU -------------\n";

        for (int i = 0; i < MENU_SIZE; i++)
        {
            cout << i + 1 << ". "
                 << left << setw(15) << items[i]
                 << "Rs. " << prices[i] << endl;
        }

        cout << "0. Generate Bill\n";
        cout << "\nEnter your choice: ";

        // Validate menu choice
        if (!(cin >> choice))
        {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (choice == 0)
        {
            if (itemCount == 0)
            {
                cout << "Your order is empty. Please select at least one item.\n";
                continue;
            }

            running = 0;
        }
        else if (choice >= 1 && choice <= MENU_SIZE)
        {
            if (itemCount >= MAX_ORDERS)
            {
                cout << "Order limit reached! You cannot add more items.\n";
                continue;
            }

            cout << "Enter quantity: ";

            // Validate quantity input
            if (!(cin >> quantity))
            {
                cout << "Invalid input! Please enter quantity in numbers.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (quantity > 0)
            {
                orderedItems[itemCount] = items[choice - 1];
                orderedQty[itemCount] = quantity;
                orderedPrice[itemCount] = prices[choice - 1];

                subtotal = subtotal + prices[choice - 1] * quantity;
                itemCount++;

                cout << "Item added successfully!\n";
            }
            else
            {
                cout << "Invalid quantity! Quantity must be greater than zero.\n";
            }
        }
        else
        {
            cout << "Invalid choice! Please select a number from 0 to "
                 << MENU_SIZE << ".\n";
        }
    }

    // GST calculation
    gst = subtotal * 0.05;
    finalAmount = subtotal + gst;

    // Display final bill
    cout << "\n\n==============================================\n";
    cout << "                 CUSTOMER BILL\n";
    cout << "==============================================\n";
    cout << "Customer Name: " << customerName << endl;
    cout << "----------------------------------------------\n";

    cout << left << setw(16) << "Item"
         << setw(8) << "Qty"
         << setw(10) << "Price"
         << "Total\n";

    cout << "----------------------------------------------\n";

    for (int i = 0; i < itemCount; i++)
    {
        int itemTotal = orderedQty[i] * orderedPrice[i];

        cout << left << setw(16) << orderedItems[i]
             << setw(8) << orderedQty[i]
             << setw(10) << orderedPrice[i]
             << itemTotal << endl;
    }

    cout << "----------------------------------------------\n";

    cout << fixed << setprecision(2);
    cout << "Subtotal:       Rs. " << subtotal << endl;
    cout << "GST (5%):       Rs. " << gst << endl;
    cout << "----------------------------------------------\n";
    cout << "FINAL AMOUNT:   Rs. " << finalAmount << endl;
    cout << "==============================================\n";
    cout << "          THANK YOU! VISIT AGAIN\n";
    cout << "==============================================\n";

    return 0;
}
