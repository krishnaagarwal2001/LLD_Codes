#include<bits/stdc++.h>
using namespace std;

class FoodItem
{
    public:
        virtual string getDescription()=0;
        virtual double getPrice() = 0;
        virtual ~FoodItem() {}
};

class Pizza: public FoodItem{
    public:
        string getDescription(){
            return "Pizza";
        }
        double getPrice(){
            return 200.0;
        }
};

class Burger: public FoodItem{
    public:
        string getDescription(){
            return "Burger";
        }
        double getPrice(){
            return 100.0;
        }
};

class Decorator: public FoodItem{
    protected:
        FoodItem* foodItem;
    public:
        Decorator(FoodItem *item): foodItem(item){}
};

class ExtraCheeseDecorator: public Decorator{
    private:
        double extraCheesePrice;
    
    public: 
        ExtraCheeseDecorator(FoodItem* item, double price): Decorator(item),extraCheesePrice(price){}

        string getDescription(){
            return foodItem->getDescription()+ " with Extra Cheese";
        }

        double getPrice(){
            return foodItem->getPrice()+ extraCheesePrice;
        }
        
};

class ExtraSauceDecorator: public Decorator{
    private:
        double extraSaucePrice;
    
    public: 
        ExtraSauceDecorator(FoodItem* item, double price): Decorator(item),extraSaucePrice(price){}

        string getDescription(){
            return foodItem->getDescription()+ " with Extra Sauce";
        }

        double getPrice(){
            return foodItem->getPrice()+ extraSaucePrice;
        }
        
};

class ExtraToppingsDecorator: public Decorator{
    private:
        double extraToppingsPrice;
    
    public: 
        ExtraToppingsDecorator(FoodItem* item, double price): Decorator(item),extraToppingsPrice(price){}

        string getDescription(){
            return foodItem->getDescription()+ " with Extra Toppings";
        }

        double getPrice(){
            return foodItem->getPrice()+ extraToppingsPrice;
        }
        
};

int main(){
    FoodItem* pizzaOrder = new Pizza();
    FoodItem* burgerOrder = new Burger();

    pizzaOrder = new ExtraCheeseDecorator(pizzaOrder,10.0);
    pizzaOrder = new ExtraSauceDecorator(pizzaOrder, 5.0);

    burgerOrder = new ExtraCheeseDecorator(burgerOrder, 20.0);
    burgerOrder = new ExtraToppingsDecorator(burgerOrder, 15.0);

    cout << "Description of pizza order is " << pizzaOrder->getDescription() << endl;
    cout << "Price of pizza order is : " << pizzaOrder->getPrice() << endl;

    cout << "Description of burger order is " << burgerOrder->getDescription() << endl;
    cout << "Price of burger order is : " << burgerOrder->getPrice() << endl;

    // Clean up allocated memory
    delete burgerOrder;
    delete pizzaOrder;

    return 0;
}