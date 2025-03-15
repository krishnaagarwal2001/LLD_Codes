#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Flyweight class - Stores shared state (tree type, color)
class TreeType {
public:
    string name;
    string color;

    TreeType(const string& name, const string& color) : name(name), color(color) {}

    void display(int x, int y) const {
        cout << "Drawing " << name << " tree at (" << x << ", " << y << ") with color " << color << endl;
    }
};

// Flyweight Factory - Manages shared TreeType objects
class TreeFactory {
private:
    static unordered_map<string, TreeType*> treeTypes;
public:
    static TreeType* getTreeType(const string& name, const string& color) {
        string key = name + "_" + color;
        if (treeTypes.find(key) == treeTypes.end()) {
            treeTypes[key] = new TreeType(name, color);
        }
        return treeTypes[key];
    }

    // Cleanup function to free allocated memory
    static void cleanup() {
        for (auto& pair : treeTypes) {
            delete pair.second;
        }
        treeTypes.clear();
    }
};

// Define the static map
unordered_map<string, TreeType*> TreeFactory::treeTypes;

// Context class - Stores unique state (x, y coordinates)
class Tree {
private:
    int x, y;
    TreeType* type;
public:
    Tree(int x, int y, TreeType* type) : x(x), y(y), type(type) {}

    void display() const {
        type->display(x, y);
    }
};

// Forest class - Stores trees with shared flyweight objects
class Forest {
private:
    vector<Tree> trees;
public:
    void plantTree(int x, int y, const string& name, const string& color) {
        TreeType* type = TreeFactory::getTreeType(name, color);
        trees.emplace_back(x, y, type);
    }

    void displayTrees() const {
        for (const auto& tree : trees) {
            tree.display();
        }
    }
};

// Usage Example
int main() {
    Forest forest;

    // Planting trees with shared flyweight objects
    forest.plantTree(1, 2, "Oak", "Green");
    forest.plantTree(3, 4, "Pine", "Dark Green");
    forest.plantTree(5, 6, "Oak", "Green"); // Reuses existing "Oak, Green" flyweight

    forest.displayTrees();

    // Clean up memory allocated by TreeFactory
    TreeFactory::cleanup();

    return 0;
}
