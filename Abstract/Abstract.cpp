// Abstract.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>


class AbstractProductA {
public:
    virtual ~AbstractProductA() = default;
    virtual std::string getDescription() const = 0;
};


class AbstractProductB {
public:
    virtual ~AbstractProductB() = default;
    virtual std::string getDescription() const = 0;
};


class ConcreteProductA1 : public AbstractProductA {
public:
    std::string getDescription() const override {
        return "Concrete Product A1";
    }
};


class ConcreteProductA2 : public AbstractProductA {
public:
    std::string getDescription() const override {
        return "Concrete Product A2";
    }
};


class ConcreteProductB1 : public AbstractProductB {
public:
    std::string getDescription() const override {
        return "Concrete Product B1";
    }
};


class ConcreteProductB2 : public AbstractProductB {
public:
    std::string getDescription() const override {
        return "Concrete Product B2";
    }
};

class AbstractFactory {
public:
    virtual ~AbstractFactory() = default;
    virtual AbstractProductA* createProductA() const = 0;
    virtual AbstractProductB* createProductB() const = 0;
};

// Конкретна фабрика 1
class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA* createProductA() const override {
        return new ConcreteProductA1();
    }

    AbstractProductB* createProductB() const override {
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA* createProductA() const override {
        return new ConcreteProductA2();
    }

    AbstractProductB* createProductB() const override {
        return new ConcreteProductB2();
    }
};

int main() {
    
    AbstractFactory* factory1 = new ConcreteFactory1();
    AbstractProductA* productA1 = factory1->createProductA();
    AbstractProductB* productB1 = factory1->createProductB();

    AbstractFactory* factory2 = new ConcreteFactory2();
    AbstractProductA* productA2 = factory2->createProductA();
    AbstractProductB* productB2 = factory2->createProductB();

    std::cout << "Product A1: " << productA1->getDescription() << std::endl;
    std::cout << "Product B1: " << productB1->getDescription() << std::endl;
    std::cout << "Product A2: " << productA2->getDescription() << std::endl;
    std::cout << "Product B2: " << productB2->getDescription() << std::endl;

    delete factory1;
    delete productA1;
    delete productB1;

    delete factory2;
    delete productA2;
    delete productB2;

    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
