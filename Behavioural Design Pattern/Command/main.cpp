#include<bits/stdc++.h>
using namespace std;

//Reciever
class Document{
    public:
        void open(){
            cout<<"Document Opened"<<endl;
        }

        void save(){
            cout<<"Document Saved"<<endl;
        }
};

//Command Interface
class ActionInterface {
    public:
        virtual void execute()=0;
        virtual ~ActionInterface() {}
};

class ActionOpen: public ActionInterface{
    private:
        Document* doc;
    
    public:
        ActionOpen(Document* doc):doc(doc){}

        void execute(){
            doc->open();
        }
};

class ActionSave: public ActionInterface{
    private:
        Document* doc;
    
    public:
        ActionSave(Document* doc):doc(doc){}

        void execute(){
            doc->save();
        }
};

// Invoker
class MenuOptions {
    private:
        vector<ActionInterface*> commands;
    
    public:
        void addCommand(ActionInterface* command) {
            commands.push_back(command);
        }
    
        void executeCommands() {
            for (ActionInterface* command : commands) {
                command->execute();
            }
        }
    };
    

int main(){
    Document doc;
    MenuOptions menu;

    ActionInterface* clickOpen = new ActionOpen(&doc);
    ActionInterface* clickSave = new ActionSave(&doc);

    menu.addCommand(clickOpen);
    menu.addCommand(clickSave);
    
    // Client code only adds commands to the menu
    // The invoker (menu) doesn't need to change when new commands are added
    menu.executeCommands();

    delete clickOpen;
    delete clickSave;

    return 0;
}