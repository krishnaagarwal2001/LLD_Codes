#include <iostream>
#include <vector>

using namespace std;

// Memento class - Stores the state
class Memento {
private:
    string state;
public:
    Memento(const string& s) : state(s) {}

    string getState() const {
        return state;
    }
};

// Originator class - Creates and restores state
class Originator {
private:
    string state;
public:
    void setState(const string& s) {
        state = s;
        cout << "Originator: Setting state to " << state << endl;
    }

    Memento* saveStateToMemento() {
        cout << "Originator: Saving state to Memento." << endl;
        return new Memento(state);
    }

    void restoreStateFromMemento(Memento* memento) {
        if (memento) {
            state = memento->getState();
            cout << "Originator: Restored state to " << state << endl;
        }
    }
};

// Caretaker class - Manages the history of states
class Caretaker {
private:
    vector<Memento*> mementoList;
public:
    ~Caretaker() { // Cleanup allocated memory
        for (Memento* m : mementoList) {
            delete m;
        }
    }

    void add(Memento* memento) {
        mementoList.push_back(memento);
    }

    Memento* get(int index) {
        if (index < 0 || index >= mementoList.size()) {
            throw out_of_range("Index out of range");
        }
        return mementoList[index];
    }
};

// Usage Example
int main() {
    Originator originator;
    Caretaker caretaker;

    originator.setState("State 1");
    caretaker.add(originator.saveStateToMemento());

    originator.setState("State 2");
    caretaker.add(originator.saveStateToMemento());

    originator.setState("State 3");

    // Undo operation - restoring first saved state
    originator.restoreStateFromMemento(caretaker.get(0)); // Restores "State 1"

    return 0;
}
