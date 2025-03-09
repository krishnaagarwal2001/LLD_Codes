#include<bits/stdc++.h>
using namespace std;

class ProductPrototype {
    public:
        virtual ProductPrototype*  clone()=0;
        virtual void display()=0;
        virtual ~ProductPrototype(){}
        virtual void update(string updatedName, double updatedPrice)=0;
};

class Product: public ProductPrototype{
    private:
        string name;
        double price;
    
    public:
        Product(const string& name, double price)
            :name(name), price(price){}
        
        ProductPrototype* clone() override {
            return new Product(*this);
        }

        void display() override {
            cout<<"Product: "<<name<<endl;
            cout<<"Price: $"<<price<<endl;
        }

        void update(string updatedName, double updatedPrice) override{
            name = updatedName;
            price = updatedPrice;
        }
};


int main(){
    ProductPrototype* product1 = new Product("Dell Laptop", 1000);

    ProductPrototype* product2 = product1->clone();

    product2->update("Apple Laptop",2000);

    cout<<"Original Product"<<endl;
    product1->display();

    cout<<"Cloned Product"<<endl;
    product2->display();

    delete product1;
    delete product2;

    return 0;
}