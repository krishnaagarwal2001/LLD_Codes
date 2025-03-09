#include<bits/stdc++.h>
using namespace std;

class OrderProcessingTemplate{
    public:
        void processOrder(){
            verifyOrder();
            assignDeliveryAgent();
            trackDelivery();
        }

        virtual void verifyOrder() = 0;
        virtual void assignDeliveryAgent() = 0;
        virtual void trackDelivery() = 0;
};

class LocalOrderProcessor: public OrderProcessingTemplate{
    public:
        void verifyOrder() {
            cout << "Verifying local order..." << endl;
        }

        void assignDeliveryAgent() {
            cout << "Assigning a local delivery agent..." << endl;
        }

        void trackDelivery() {
            cout << "Tracking local delivery..." << endl;
        }

};

class InternationalOrderProcessor: public OrderProcessingTemplate{
    public:
        void verifyOrder() {
            cout << "Verifying international order..." << endl;
        }

        void assignDeliveryAgent() {
            cout << "Assigning a international delivery agent..." << endl;
        }

        void trackDelivery() {
            cout << "Tracking international delivery..." << endl;
        }

};

int main(){
    OrderProcessingTemplate* localOrder = new LocalOrderProcessor();    
    OrderProcessingTemplate* internationalOrder = new InternationalOrderProcessor();

    cout << "Processing a local order:" << endl;
    localOrder->processOrder();
    cout << endl;

    cout << "Processing an international order:" << endl;
    internationalOrder->processOrder();

    delete localOrder;
    delete internationalOrder;

    return 0;
}