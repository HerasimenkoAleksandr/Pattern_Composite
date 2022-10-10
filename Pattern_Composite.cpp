#include <iostream>
#include <list>
#include <string>
#include "Header.h"
using namespace std;


void ClientCode(Component* component);




int main() {
  

    Component* A = new Composite;
   


    Component* A1 = new Composite;
    Component* A2 = new Composite;
    Component* a1 = new Leaf;
    Component* a2 = new Leaf;
    A->Add(a1);
    A2->Add(a1);
    A2->Add(a2);
    A->Add(A1);
    A->Add(A2);
    ClientCode(A);
    cout << endl;




    

    delete A;
    delete A1;
    delete A2;
    delete a1;
    delete a2;
    

    return 0;
}



Component::Component() : parent{ nullptr } {}

void Component::SetParent(Component* parentP) {
    parent = parentP;
}
Component* Component::GetParent() {
    return parent;
}

string Leaf::Operation() {
    return "Leaf";
}

void Composite::Add(Component* component) {
    children.push_back(component);
    component->SetParent(this);
}

void Composite::Remove(Component* component) {
    children.remove(component);
    component->SetParent(nullptr);
}
bool Composite::IsComposite() const {
    return true;
}

string Composite::Operation() {
    string result;
    for (Component* c : children) {
        if (c == children.back()) {
            result += c->Operation();
        }
        else {
            result += c->Operation() + "+";
        }
    }
    return "Branch(" + result + ")";
}

void ClientCode(Component* component) {

    std::cout << "RESULT: " << component->Operation();

}