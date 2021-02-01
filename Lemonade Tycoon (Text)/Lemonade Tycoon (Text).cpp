#include <iostream>
#include <string>
#include <vector>

void welcomeUser();
void gameSetup();
void gameLoop();
void displayInventory();
void displayBalance();
void displayPrices();
void updateInventory();
void buyIngredients();
void sellIngredients();


using namespace std;



class Ingredient 
{
    public:
        string name;
        float price;
        int quantity;
        int recipeQuantity;
        Ingredient(string ingName, float ingPrice) {
            name = ingName;
            price = ingPrice;
            recipeQuantity = 0;
        }
};

bool gameActive;
string playerName;

float balance;
Ingredient lemon("Lemon", 0.50f);
Ingredient sugar("Sugar", 0.20f);
Ingredient ice("Ice", 0.02f);
Ingredient water("Water", 0.10f);
vector<Ingredient> ingredientList;


string strBalance;
string gameInstruction;
int x;
string y;
int days;


int main()
{
    gameSetup();
    welcomeUser();
    gameLoop();
}

string printCurrency(float num)
{
    strBalance = to_string(num);
    strBalance = strBalance.substr(0, strBalance.find(".") + 3);

    return "$" + strBalance;
}

void gameSetup()
{
    balance = 10.00f;
    updateInventory();


}

void updateInventory()
{
    ingredientList.clear();
    ingredientList.push_back(lemon);
    ingredientList.push_back(sugar);
    ingredientList.push_back(ice);
    ingredientList.push_back(water);
}

void welcomeUser()
{
    cout << "Welcome to Lemonade Tycoon(Text)!\n\nWhat is your name? : ";
    getline(cin, playerName);
    
    system("CLS");
    cout << "Balance:" + printCurrency(balance) + "\t\t\t\t\t\t\t\t"; displayInventory(); cout << "\n\n";

    cout << "Hi " + playerName + ", you have : " + printCurrency(balance) + ", if you need help type 'help'\n";

}

void displayBalance()

{

}

void displayPrices()
{

    updateInventory();

    for (auto& i : ingredientList) {
        cout << i.name + " price : " + printCurrency(i.price);
        if (&i != &ingredientList.back()) {
            cout << ", ";
        }
        else {
            cout << "\n";
        }
    }

    gameInstruction = "";

}

void displayInventory()
{
    updateInventory();

    for (auto& i : ingredientList) {
        cout << to_string(i.quantity) + " " + i.name;
        if (&i != &ingredientList.back()) {
            cout << ", ";
        }
        else {
            cout << "";
        }
    }
}

void buyIngredients()
{
    system("CLS");
    cout << "Balance:" + printCurrency(balance) + "\t\t\t\t\t\t\t\t"; displayInventory(); cout << "\n\n";;

    cin >> x >> y;

    
    while (cin.fail()){
        
        cout << "The buy format is as follows '[Buy] [Quantity (integer)] [Item Name]'\n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << ">";
        cin >> gameInstruction;
        if (gameInstruction == "buy") {
            cin >> x >> y;
            cin.clear();
            cin.ignore(256, '\n');
        }
        else {
            
            return;

        }
    }

    if (x < 0) {
        cout << "Nice try, use sell in order to sell back stock (you will get back 75% of the purchase price).\n";
    }

    else {


        if (y == "lemon") {

            if (balance >= lemon.price * x) {
                balance -= (lemon.price * x);
                lemon.quantity += x;

                system("CLS");
                cout << "Balance:" + printCurrency(balance) + "\t\t\t\t\t\t\t\t"; displayInventory(); cout << "\n\n";

                cout << "You buy " + to_string(x) + " Lemon.\n";
            }
            else {
                cout << "You don't have enough money to buy that! \n";
            }




        }

        else if (y == "sugar") {

            if (balance >= sugar.price * x) {
                balance -= (sugar.price * x);
                sugar.quantity += x;

                system("CLS");
                cout << "Balance:" + printCurrency(balance) + "\t\t\t\t\t\t\t\t"; displayInventory(); cout << "\n\n";

                cout << "You buy " + to_string(x) + " Sugar.\n";
            }
            else {
                cout << "You don't have enough money to buy that! \n";
            }
        }

        else if (y == "water") {

            if (balance >= water.price * x) {
                balance -= (water.price * x);
                water.quantity += x;

                system("CLS");
                cout << "Balance:" + printCurrency(balance) + "\t\t\t\t\t\t\t\t"; displayInventory(); cout << "\n\n";

                cout << "You buy " + to_string(x) + " water.\n";
            }
            else {
                cout << "You don't have enough money to buy that! \n";
            }
        }

        else if (y == "ice") {

            if (balance >= ice.price * x) {
                balance -= (ice.price * x);
                ice.quantity += x;

                system("CLS");
                cout << "Balance:" + printCurrency(balance) + "\t\t\t\t\t\t\t\t"; displayInventory(); cout << "\n\n";

                cout << "You buy " + to_string(x) + " ice cubes.\n";
            }
            else {
                cout << "You don't have enough money to buy that! \n";
            }
        }
    }
    gameInstruction = "";
}

void sellIngredients()
{
    system("CLS");
    cout << "Balance:" + printCurrency(balance) + "\t\t\t\t\t\t\t\t"; displayInventory(); cout << "\n\n";

    cin >> x >> y;

    while (cin.fail()) {

        cout << "sell format is as follows '[Sell] [Quantity (integer)] [Item Name]'\n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << ">";
        cin >> gameInstruction;

        if (gameInstruction == "sell") {
            cin >> x >> y;
            cin.clear();
            cin.ignore(256, '\n');
        }
        else {

            return;

        }
    }

    if (x < 0) {
        cout << "Nice try, use buy in order to buy stock.\n";
    }
    else

    {

        if (y == "lemon") {

            if (lemon.quantity >= x) {
                balance += ((lemon.price * x) * 0.75);
                lemon.quantity -= x;

                system("CLS");
                cout << "Balance:" + printCurrency(balance) + "\t\t\t\t\t\t\t\t"; displayInventory(); cout << "\n\n";

                cout << "You sell " + to_string(x) + " Lemon.\n";

            }
            else {
                cout << "You don't have enough lemons to sell that many! \n";
            }

        }

        else if (y == "sugar") {

            if (sugar.quantity >= x) {
                balance += (sugar.price * x * 0.75);
                sugar.quantity -= x;

                system("CLS");
                cout << "Balance:" + printCurrency(balance) + "\t\t\t\t\t\t\t\t"; displayInventory(); cout << "\n\n";

                cout << "You sell " + to_string(x) + " Sugar.\n";
            }
            else {
                cout << "You don't have enough sugar to sell that many! \n";
            }
        }

        else if (y == "water") {

            if (water.quantity >= x) {
                balance += (water.price * x * 0.75);
                water.quantity -= x;

                system("CLS");
                cout << "Balance:" + printCurrency(balance) + "\t\t\t\t\t\t\t\t"; displayInventory(); cout << "\n\n";

                cout << "You sell " + to_string(x) + " water.\n";
            }
            else {
                cout << "You don't have enough litres of water to sell that many! \n";
            }
        }

        else if (y == "ice") {

            if (ice.quantity >= x) {
                balance += (ice.price * x * 0.75);
                ice.quantity -= x;

                system("CLS");
                cout << "Balance:" + printCurrency(balance) + "\t\t\t\t\t\t\t\t"; displayInventory(); cout << "\n\n";

                cout << "You sell " + to_string(x) + " ice cubes.\n";
            }
            else {
                cout << "You don't have enough ice cubes to sell that many! \n";
            }
        }
    }

    gameInstruction = "";
}

void setRecipe() {
    system("CLS");
    cout << "Balance:" + printCurrency(balance) + "\t\t\t\t\t\t\t\t"; displayInventory(); cout << "\n\n";

    cout << "What would you like the recipe per jug to be? (Each jug uses 1 litre of water) \n";
    cout << "\nLemon Quantity:";
    cin >> lemon.recipeQuantity;
    cout << "\nSugar Quantity:";
    cin >> sugar.recipeQuantity;
    cout << "\nIce Quantity:";
    cin >> ice.recipeQuantity;

    gameInstruction = "";
}

void simulateDay() {

}

void gameHelp() {

    system("CLS");
    cout << "Balance:" + printCurrency(balance) + "\t\t\t\t\t\t\t\t"; displayInventory(); cout << "\n\n";

    cout << "Help Menu\n\n";
    cout << "When you see the > symbol, the game is waiting for your instruction.\n";
    cout << "\nPossible Instructions\n\n";
    cout << ">prices (Displays price of ingredients)\n\n";
    cout << ">recipe (Set the lemonade recipe)\n\n";
    cout << ">location (Rent an area to set up the stand)\n\n";
    cout << ">buy 1 lemon (Buy ingredients using this format)\n\n";
    cout << ">sell 1 lemon (Sell ingredients using this format)\n\n";
    cout << " Available Ingredients\n";
    cout << "\tlemon\n";
    cout << "\tsugar\n";
    cout << "\twater\n";
    cout << "\tice\n\n";
    cout << ">help (This menu)\n\n";
    cout << ">quit & >exit (Exit the game)\n\n";
    cout << "Enjoy the game!\n\n";

    gameInstruction = "";
}

void displayHUD() {
    system("CLS");
    cout << "Balance:" + printCurrency(balance) + "\t\t\t\t\t\t\t\t"; displayInventory(); cout << "\n\n";
}
void location() {
    displayHUD();

    cout << "Locations available\n\n";
    cout << " - Bronx\n";
    cout << " - Corner\n";

}

void gameLoop() 
{
    gameActive = true;
    

    while (gameActive) {
        cout << ">";
        if (gameInstruction == "") {
            cin >> gameInstruction;
        }

        if (gameInstruction == "prices") {
            displayPrices();
            continue;
        }
        else if (gameInstruction == "recipe") {
            setRecipe();
            continue;
        }
        else if (gameInstruction == "buy") {
            buyIngredients();
            continue;
            
        }
        else if (gameInstruction == "sell") {
            sellIngredients();
            continue;
        }
        else if (gameInstruction == "location") {
            location();
            continue;
        }
        else if (gameInstruction == "help") {
            gameHelp();
            continue;
        }
        else if (gameInstruction == "quit" || gameInstruction == "exit") {
            gameActive = false;
            continue;
            
        }
        else {
            gameInstruction = "";
        }
        
    }

}