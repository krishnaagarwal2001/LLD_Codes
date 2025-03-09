#include<bits/stdc++.h>
using namespace std;

class Product {
    private: 
        string name;
        double price;
    
    public:
        Product(const string& name, const double& price):name(name),price(price){}

        const string& getName() const {
            return name;
        }

        double getPrice() const {
            return price;
        }
};

class Iterator {
    public:
        virtual Product* first()=0;
        virtual Product* next()=0;
        virtual bool hasNext()=0;
};

class ProductIterator: public Iterator{
    private:
        vector<Product*> &products;
        size_t current;
    
    public:
        ProductIterator(vector<Product*>& products): products(products), current(0){}

        Product* first(){
            if(products.empty()){
                return nullptr;
            }

            current = 0;
            return products[current];
        }

        Product* next(){
            if(hasNext()){
                return products[++current];
            }

            return nullptr;
        }

        bool hasNext(){
            return current<products.size();
        }
};

class Inventory{
    private:
        vector<Product*> products;

    public:
        void addProduct(Product* product){
            products.push_back(product);
        }

        Iterator* createIterator(){
            return new ProductIterator(products);
        }
};

int main(){
    Product product1("Laptop",2000);
    Product product2("SmartPhone",800);
    Product product3("HeadPhone",100);

    Inventory inventory;
    inventory.addProduct(&product1);
    inventory.addProduct(&product2);
    inventory.addProduct(&product3);

    Iterator* iterator = inventory.createIterator();
    Product* currentProduct = iterator->first();

    while(currentProduct){
        cout << "Product: " << currentProduct->getName() << 
                        ", Price: $" << currentProduct->getPrice() << std::endl;
        currentProduct = iterator->next();
    }

    delete iterator;
    
    return 0;
}