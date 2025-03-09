#include<bits/stdc++.h>
using namespace std;

class IButton {
    public:
        virtual void press()=0;
};

class ITextBox {
    public:
        virtual void setText()=0;
};

class MacButton: public IButton{
    public:
        void press(){
            cout<<"Mac Button is pressed"<<endl;
        }
};

class WinButton: public IButton{
    public:
        void press(){
            cout<<"Windows Button is pressed"<<endl;
        }
};

class MacTextBox: public ITextBox{
    public:
        void setText(){
            cout<<"Setting Text in Mac"<<endl;
        }
};

class WinTextBox: public ITextBox{
    public:
        void setText(){
            cout<<"Setting Text in Windows"<<endl;
        }
};

class IFactory{
    public:
        virtual IButton* createButton()=0;
        virtual ITextBox* createTextBox()=0;
};

class WinFactory : public IFactory{
    public:
        IButton* createButton(){
            return new WinButton();
        }

        ITextBox* createTextBox(){
            return new WinTextBox();
        }
};

class MacFactory: public IFactory{
    public:
        IButton* createButton(){
            return new MacButton();
        }

        ITextBox* createTextBox(){
            return new MacTextBox();
        }
};

class GUIAbstractFactory{
    public:
        static IFactory* createFactory(string osType){
            if(osType == "WINDOWS"){
                return new WinFactory();
            }
            else if(osType == "MAC"){
                return new MacFactory();
            }

            return nullptr;
        }
};

int main(){
    cout<<"Enter machine OS"<<endl;
    string osType;
    cin>>osType;

    IFactory* factory = GUIAbstractFactory::createFactory(osType);

    IButton* button = factory->createButton();
    button->press();

    ITextBox* textBox =factory->createTextBox();
    textBox->setText();

    return 0;
}