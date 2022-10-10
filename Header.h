#pragma once
//#include <string>
using namespace std;
class Component {

protected:
    Component* parent;


public:
    Component();
    virtual ~Component() {}
    void SetParent(Component* parentP);
    Component* GetParent();

    virtual void Add(Component* component) {}
    virtual void Remove(Component* component) {}

    virtual bool IsComposite()const {
        return false;
    }
    virtual string Operation() = 0;
};

class Leaf : public Component {
public:
    string Operation()  override;
};


class Composite : public Component {

protected:
    std::list<Component*> children;

public:

    void Add(Component* component) override;

    void Remove(Component* component);
    bool IsComposite() const override;

    string Operation() override;
};


