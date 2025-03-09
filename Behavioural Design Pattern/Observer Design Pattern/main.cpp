#include<bits/stdc++.h>
using namespace std;

class Order;

class Observer {
    public:
        virtual void update(Order *order)=0;
};

class Order {
    private:
        int id;
        string status;
        vector<Observer *> observers;
    
    public:
        Order(int id):id(id), status("Order Placed"){}

        int getId(){
            return id;
        }

        string getStatus(){
            return status;
        }

        void setStatus(string updatedStatus){
            status=updatedStatus;
            notifyObservers();
        }

        void attach(Observer *observer){
            observers.push_back(observer);
        }

        void detach(Observer *observer)
        {
            for (auto it = observers.begin(); it != observers.end(); ++it)
            {
                if (*it == observer)
                {
                    observers.erase(it);
                    break; // Assuming each observer can be attached only once
                }
            }
        }

        void notifyObservers(){
            for(Observer *observer: observers){
                observer->update(this);
            }
        }
};

class Customer : public Observer {
    private:
        string name;
    
    public:
        Customer(string name) : name(name) {}
    
        void update(Order *order) override {
            cout << "Hello, " << name << "! Order #" << order->getId() << " is now " << order->getStatus() << endl;
        }
};
    
class Restaurant : public Observer {
    private:
        string restaurantName;

    public:
        Restaurant(string name) : restaurantName(name) {}

        void update(Order *order) override {
            cout << "Restaurant " << restaurantName << ": Order #" << order->getId() << " is now " << order->getStatus() << endl;
        }
};

class DeliveryPartner : public Observer {
    private:
        string driverName;

    public:
        DeliveryPartner(string name) : driverName(name) {}

        void update(Order *order) override {
            cout << "Driver " << driverName << ": Order #" << order->getId() << " is now " << order->getStatus() << endl;
        }
};

class CallCenter : public Observer {
    public:
        void update(Order *order) override {
            cout << "Call center: Order #" << order->getId() << " is now " << order->getStatus() << endl;
        }
};

int main(){
    Order *order = new Order(123);

    Customer *customer1 = new Customer("Customer 1");
    Restaurant *restaurant1 = new Restaurant("Rest 1");
    DeliveryPartner *deliveryPartner = new DeliveryPartner("Driver 1");
    CallCenter *callCenter = new CallCenter();

    order->attach(customer1);
    order->attach(restaurant1);
    order->attach(deliveryPartner);
    order->attach(callCenter);

    order->setStatus("Out for Delivery");

    order->detach(callCenter);

    order->setStatus("Delivered");

    delete order;
    delete customer1;
    delete restaurant1;
    delete deliveryPartner;
    delete callCenter;

    return 0;
}