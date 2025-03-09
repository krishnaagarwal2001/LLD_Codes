#include<bits/stdc++.h>
using namespace std;

class PaymentStrategy {
    public:
        virtual void processPayment(double amount)=0;
        virtual ~PaymentStrategy() {}
};

class CreditCardPayment: public PaymentStrategy{
    public:
        void processPayment (double amount) override {
            cout << "Processing credit card payment of $" << amount << endl;
        }
};

class PayPalPayment: public PaymentStrategy{
    public:
        void processPayment (double amount) override {
            cout << "Processing PayPal payment of $" << amount << endl;
        }
};

class CryptocurrencyPayment : public PaymentStrategy {
    public:
        void processPayment(double amount) override {
            cout << "Processing cryptocurrency payment of $" << amount << endl;
        }
};
    
class PaymentProcessor {
    private:
        PaymentStrategy* paymentStrategy;

    public:
        void setPaymentStrategy(PaymentStrategy* strategy){
            paymentStrategy=strategy;
        }

        void processPayment(double amount){
            if(paymentStrategy){
                paymentStrategy->processPayment(amount);
            } else {
                cerr << "Payment strategy not set." << endl;
            }
        }

        ~PaymentProcessor() {
            if (paymentStrategy) {
                delete paymentStrategy; // Clean up the strategy instance
            }
        }    
};

int main(){
    PaymentProcessor processor;

    PaymentStrategy* creditCardStrategy = new CreditCardPayment();
    processor.setPaymentStrategy(creditCardStrategy);
    processor.processPayment(100.0);

    PaymentStrategy* payPalStrategy = new PayPalPayment();
    processor.setPaymentStrategy(payPalStrategy);
    processor.processPayment(100.0);

    return 0;
}