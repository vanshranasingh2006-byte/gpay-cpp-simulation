#include <bits/stdc++.h>
using namespace std;

//---------------------------- ENUMS ----------------------------------------//

enum Category
{
    ELECTRONICS,
    CLOTHING,
    FOOD,
    BOOKS
};

enum OrderStatus
{
    PENDING,
    CONFIRMED,
    CANCELLED,
    DELIVERED
};

enum PaymentStatus
{
    PAYMENT_PENDING,
    PAYMENT_SUCCESS,
    PAYMENT_FAILED
};

enum PaymentMethod
{
    CREDIT_CARD,
    UPI,
    CASH
};

//---------------------------- UNION ----------------------------------------//

union PaymentInfo
{
    char card_last4[5];
    char upi_id[50];

    PaymentInfo()
    {
        card_last4[0] = '\0';
    }
};

//---------------------------- PRODUCT CLASS --------------------------------//

class Product
{
private:
    int product_id;
    string name;
    float price;
    int stock;
    Category category;

public:

    // Default constructor
    Product()
    {
        product_id = 0;
        name = "";
        price = 0.0;
        stock = 0;
        category = FOOD;
    }

    // Parameterized constructor
    Product(int id, string n, float p, int s, Category c)
    {
        product_id = id;
        name = n;
        price = p;
        stock = s;
        category = c;
    }

    int get_product_id()
    {
        return product_id;
    }

    float get_price()
    {
        return price;
    }

    int get_stock()
    {
        return stock;
    }

    string get_name()
    {
        return name;
    }

    bool checkAvailability(int quantity)
    {
        return quantity > 0 && quantity <= stock;
    }

    void updateStock(int quantity)
    {
        stock += quantity;
    }

    void reduceStock(int quantity)
    {
        if(quantity <= stock)
        {
            stock -= quantity;
        }
    }

    void displayProduct()
    {
        cout << "\nProduct ID: " << product_id
             << "\nName: " << name
             << "\nPrice: Rs. " << price
             << "\nStock: " << stock
             << "\nCategory: ";

        switch(category)
        {
            case ELECTRONICS:
                cout << "Electronics";
                break;

            case CLOTHING:
                cout << "Clothing";
                break;

            case FOOD:
                cout << "Food";
                break;

            case BOOKS:
                cout << "Books";
                break;
        }

        cout << "\n";
    }
};

//---------------------------- CUSTOMER CLASS -------------------------------//

class Customer
{
private:
    int customer_id;
    string name;
    string email;
    long long phone;
    string address;

public:

    Customer()
    {
        customer_id = 0;
        name = "";
        email = "";
        phone = 0;
        address = "";
    }

    Customer(int id, string n, string e, long long p, string a)
    {
        customer_id = id;
        name = n;
        email = e;
        phone = p;
        address = a;
    }

    int get_customer_id()
    {
        return customer_id;
    }

    string get_name()
    {
        return name;
    }

    void updateCustomerDetails()
    {
        cout << "\nEnter new name: ";
        cin >> name;

        cout << "Enter new email: ";
        cin >> email;

        cout << "Enter new phone: ";
        cin >> phone;

        cout << "Enter new address: ";
        cin >> address;

        cout << "\nCustomer details updated successfully.\n";
    }

    void displayCustomer()
    {
        cout << "\nCustomer ID: " << customer_id
             << "\nName: " << name
             << "\nEmail: " << email
             << "\nPhone: " << phone
             << "\nAddress: " << address
             << "\n";
    }
};

//---------------------------- ORDER STRUCT ---------------------------------//

struct Order
{
    int order_id;
    int customer_id;
    float total_amount;

    OrderStatus order_status;
    PaymentStatus payment_status;

    PaymentMethod payment_method;
    PaymentInfo payment_info;

    Order()
    {
        order_id = 0;
        customer_id = 0;
        total_amount = 0.0;

        order_status = PENDING;
        payment_status = PAYMENT_PENDING;

        payment_method = CASH;
    }

    void displayOrder()
    {
        cout << "\nOrder ID: " << order_id
             << "\nCustomer ID: " << customer_id
             << "\nTotal Amount: Rs. " << total_amount;

        cout << "\nOrder Status: ";

        switch(order_status)
        {
            case PENDING:
                cout << "Pending";
                break;

            case CONFIRMED:
                cout << "Confirmed";
                break;

            case CANCELLED:
                cout << "Cancelled";
                break;

            case DELIVERED:
                cout << "Delivered";
                break;
        }

        cout << "\nPayment Status: ";

        switch(payment_status)
        {
            case PAYMENT_PENDING:
                cout << "Pending";
                break;

            case PAYMENT_SUCCESS:
                cout << "Successful";
                break;

            case PAYMENT_FAILED:
                cout << "Failed";
                break;
        }

        cout << "\nPayment Method: ";

        switch(payment_method)
        {
            case CREDIT_CARD:
                cout << "Credit Card";
                break;

            case UPI:
                cout << "UPI";
                break;

            case CASH:
                cout << "Cash";
                break;
        }

        cout << "\n";
    }
};

//---------------------------- FUNCTION DECLARATIONS ------------------------//

int find_product(Product[], int, int);
int find_customer(Customer[], int, int);
int find_order(Order[], int, int);

void add_product(Product[], int&);
void display_products(Product[], int);

void add_customer(Customer[], int&);
void display_customers(Customer[], int);

void create_order(Product[], int, Customer[], int, Order[], int&);
void update_order(Order[], int);
void confirm_order(Order[], int);
void cancel_order(Order[], int);
void display_orders(Order[], int);

void make_payment(Order[], int);

//---------------------------- MAIN -----------------------------------------//

int main()
{
    Product products[10];
    Customer customers[10];
    Order orders[20];

    int product_count = 0;
    int customer_count = 0;
    int order_count = 0;

    int choice;

    while(true)
    {
        cout << "\n\n==========================================";
        cout << "\n     E-COMMERCE ORDER MANAGEMENT SYSTEM";
        cout << "\n==========================================";

        cout << "\n1. Add Product";
        cout << "\n2. Display Products";
        cout << "\n3. Add Customer";
        cout << "\n4. Display Customers";
        cout << "\n5. Create Order";
        cout << "\n6. Make Payment";
        cout << "\n7. Update Order";
        cout << "\n8. Confirm Order";
        cout << "\n9. Cancel Order";
        cout << "\n10. Display Orders";
        cout << "\n11. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                add_product(products, product_count);
                break;

            case 2:
                display_products(products, product_count);
                break;

            case 3:
                add_customer(customers, customer_count);
                break;

            case 4:
                display_customers(customers, customer_count);
                break;

            case 5:
                create_order(products, product_count,
                             customers, customer_count,
                             orders, order_count);
                break;

            case 6:
                make_payment(orders, order_count);
                break;

            case 7:
                update_order(orders, order_count);
                break;

            case 8:
                confirm_order(orders, order_count);
                break;

            case 9:
                cancel_order(orders, order_count);
                break;

            case 10:
                display_orders(orders, order_count);
                break;

            case 11:
                cout << "\nThank you for using the system.\n";
                return 0;

            default:
                cout << "\nInvalid menu choice!";
        }
    }
}

//---------------------------- FIND FUNCTIONS -------------------------------//

int find_product(Product products[], int size, int id)
{
    for(int i = 0; i < size; i++)
    {
        if(products[i].get_product_id() == id)
        {
            return i;
        }
    }

    return -1;
}

int find_customer(Customer customers[], int size, int id)
{
    for(int i = 0; i < size; i++)
    {
        if(customers[i].get_customer_id() == id)
        {
            return i;
        }
    }

    return -1;
}

int find_order(Order orders[], int size, int id)
{
    for(int i = 0; i < size; i++)
    {
        if(orders[i].order_id == id)
        {
            return i;
        }
    }

    return -1;
}

//---------------------------- PRODUCT FUNCTIONS ----------------------------//

void add_product(Product products[], int& count)
{
    if(count >= 10)
    {
        cout << "\nProduct storage is full!";
        return;
    }

    int id;
    string name;
    float price;
    int stock;
    int category;

    cout << "\nEnter Product ID: ";
    cin >> id;

    if(find_product(products, count, id) != -1)
    {
        cout << "\nProduct ID already exists!";
        return;
    }

    cout << "Enter Product Name: ";
    cin >> name;

    cout << "Enter Price: ";
    cin >> price;

    if(price <= 0)
    {
        cout << "\nInvalid price!";
        return;
    }

    cout << "Enter Stock: ";
    cin >> stock;

    if(stock < 0)
    {
        cout << "\nInvalid stock!";
        return;
    }

    cout << "\nCategory:";
    cout << "\n0. Electronics";
    cout << "\n1. Clothing";
    cout << "\n2. Food";
    cout << "\n3. Books";

    cout << "\nEnter Category: ";
    cin >> category;

    if(category < 0 || category > 3)
    {
        cout << "\nInvalid category!";
        return;
    }

    products[count] = Product(
        id,
        name,
        price,
        stock,
        static_cast<Category>(category)
    );

    count++;

    cout << "\nProduct added successfully!";
}

void display_products(Product products[], int count)
{
    if(count == 0)
    {
        cout << "\nNo products available.";
        return;
    }

    for(int i = 0; i < count; i++)
    {
        cout << "\n--------------------------------";
        products[i].displayProduct();
    }
}

//---------------------------- CUSTOMER FUNCTIONS ---------------------------//

void add_customer(Customer customers[], int& count)
{
    if(count >= 10)
    {
        cout << "\nCustomer storage is full!";
        return;
    }

    int id;
    string name;
    string email;
    long long phone;
    string address;

    cout << "\nEnter Customer ID: ";
    cin >> id;

    if(find_customer(customers, count, id) != -1)
    {
        cout << "\nCustomer ID already exists!";
        return;
    }

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Email: ";
    cin >> email;

    cout << "Enter Phone: ";
    cin >> phone;

    cout << "Enter Address: ";
    cin >> address;

    customers[count] = Customer(
        id,
        name,
        email,
        phone,
        address
    );

    count++;

    cout << "\nCustomer added successfully!";
}

void display_customers(Customer customers[], int count)
{
    if(count == 0)
    {
        cout << "\nNo customers available.";
        return;
    }

    for(int i = 0; i < count; i++)
    {
        cout << "\n--------------------------------";
        customers[i].displayCustomer();
    }
}

//---------------------------- CREATE ORDER ---------------------------------//

void create_order(Product products[],
                  int product_count,
                  Customer customers[],
                  int customer_count,
                  Order orders[],
                  int& order_count)
{
    if(order_count >= 20)
    {
        cout << "\nOrder storage is full!";
        return;
    }

    int customer_id;

    cout << "\nEnter Customer ID: ";
    cin >> customer_id;

    int customer_index =
        find_customer(customers, customer_count, customer_id);

    // Validation 1: Invalid Customer ID
    if(customer_index == -1)
    {
        cout << "\nInvalid Customer ID!";
        return;
    }

    int product_id;
    int quantity;

    cout << "Enter Product ID: ";
    cin >> product_id;

    int product_index =
        find_product(products, product_count, product_id);

    // Validation 2: Invalid Product ID
    if(product_index == -1)
    {
        cout << "\nInvalid Product ID!";
        return;
    }

    cout << "Enter Quantity: ";
    cin >> quantity;

    // Validation 3: Product out of stock
    if(!products[product_index].checkAvailability(quantity))
    {
        cout << "\nProduct is out of stock or insufficient quantity!";
        return;
    }

    float total =
        products[product_index].get_price() * quantity;

    Order new_order;

    new_order.order_id = 1000 + order_count + 1;
    new_order.customer_id = customer_id;
    new_order.total_amount = total;

    orders[order_count] = new_order;

    products[product_index].reduceStock(quantity);

    order_count++;

    cout << "\nOrder created successfully!";
    cout << "\nOrder ID: " << new_order.order_id;
    cout << "\nTotal Amount: Rs. " << total;
}

//---------------------------- PAYMENT --------------------------------------//

void make_payment(Order orders[], int count)
{
    int id;

    cout << "\nEnter Order ID: ";
    cin >> id;

    int index = find_order(orders, count, id);

    // Validation 4: Invalid Order ID
    if(index == -1)
    {
        cout << "\nInvalid Order ID!";
        return;
    }

    // Validation 5: Payment for cancelled order
    if(orders[index].order_status == CANCELLED)
    {
        cout << "\nCannot make payment for a cancelled order!";
        return;
    }

    cout << "\nPayment Methods:";
    cout << "\n0. Credit Card";
    cout << "\n1. UPI";
    cout << "\n2. Cash";

    int method;

    cout << "\nEnter Payment Method: ";
    cin >> method;

    if(method < 0 || method > 2)
    {
        cout << "\nInvalid payment method!";
        return;
    }

    orders[index].payment_method =
        static_cast<PaymentMethod>(method);

    if(method == CREDIT_CARD)
    {
        cout << "\nEnter last 4 digits of card: ";
        cin >> orders[index].payment_info.card_last4;

        orders[index].payment_status = PAYMENT_SUCCESS;
    }

    else if(method == UPI)
    {
        cout << "\nEnter UPI ID: ";
        cin >> orders[index].payment_info.upi_id;

        orders[index].payment_status = PAYMENT_SUCCESS;
    }

    else
    {
        cout << "\nCash payment selected.";
        orders[index].payment_status = PAYMENT_SUCCESS;
    }

    cout << "\nPayment successful!";
}

//---------------------------- UPDATE ORDER ---------------------------------//

void update_order(Order orders[], int count)
{
    int id;

    cout << "\nEnter Order ID: ";
    cin >> id;

    int index = find_order(orders, count, id);

    if(index == -1)
    {
        cout << "\nInvalid Order ID!";
        return;
    }

    if(orders[index].order_status == CANCELLED)
    {
        cout << "\nCannot update a cancelled order!";
        return;
    }

    if(orders[index].order_status == DELIVERED)
    {
        cout << "\nCannot update a delivered order!";
        return;
    }

    cout << "\nCurrent Order:";
    orders[index].displayOrder();

    cout << "\nOrder update completed.";
}

//---------------------------- CONFIRM ORDER ---------------------------------//

void confirm_order(Order orders[], int count)
{
    int id;

    cout << "\nEnter Order ID: ";
    cin >> id;

    int index = find_order(orders, count, id);

    if(index == -1)
    {
        cout << "\nInvalid Order ID!";
        return;
    }

    if(orders[index].order_status == CANCELLED)
    {
        cout << "\nCannot confirm a cancelled order!";
        return;
    }

    // Validation 6: Confirming with failed/pending payment
    if(orders[index].payment_status != PAYMENT_SUCCESS)
    {
        cout << "\nCannot confirm order.";
        cout << "\nPayment has not been completed successfully.";
        return;
    }

    orders[index].order_status = CONFIRMED;

    cout << "\nOrder confirmed successfully!";
}

//---------------------------- CANCEL ORDER ---------------------------------//

void cancel_order(Order orders[], int count)
{
    int id;

    cout << "\nEnter Order ID: ";
    cin >> id;

    int index = find_order(orders, count, id);

    if(index == -1)
    {
        cout << "\nInvalid Order ID!";
        return;
    }

    // Validation 7: Cancelling delivered order
    if(orders[index].order_status == DELIVERED)
    {
        cout << "\nCannot cancel a delivered order!";
        return;
    }

    if(orders[index].order_status == CANCELLED)
    {
        cout << "\nOrder is already cancelled!";
        return;
    }

    orders[index].order_status = CANCELLED;

    cout << "\nOrder cancelled successfully!";
}

//---------------------------- DISPLAY ORDERS -------------------------------//

void display_orders(Order orders[], int count)
{
    if(count == 0)
    {
        cout << "\nNo orders available.";
        return;
    }

    for(int i = 0; i < count; i++)
    {
        cout << "\n================================";
        orders[i].displayOrder();
    }
}

//---------------------------- END OF PROGRAM -------------------------------//