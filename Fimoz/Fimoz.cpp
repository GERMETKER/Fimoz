#include <iostream>
//Полиморфизм - технолог измен повед прог при сохран линейн структуры кода

//При полиморф вызовах прог рассчтывая на код описанн в род классе фактич будет\
выполнять код методов описанн в классах наследниках
class Yaderka
{
public:
    //ключ слово virtual созд визуал табл типов в прог
    Yaderka()
    {
        std::cout << "Base Constructor\n";
    }
    virtual ~Yaderka()
    {
        std::cout << "Base Destructor\n";
    }
    virtual void Print()const
    {
        std::cout << "Hello World!\n";
    }
};

class Neytronka:public Yaderka
{
public:
    Neytronka()
    {
        std::cout << "Derived Constructor\n";
    }
    
    ~Neytronka()
    {
        std::cout << "Derived Destructor\n";
    }
    //override - замена род метода , если у род есть virtual
    void Print()const override
    {
        std::cout << "Hello\n";
    }
};
//Полиморфные вызовы возможны когда объекты в прог перед по ссылкам и указателям
void F00(Yaderka &a)
{
    a.Print();
}

//Если передача ведётся по параметру то происх опер upcast котор отсек все св-ва наслед классов и созд новый объект\
базового на их осове
int main()
{
    Yaderka* one = new Yaderka;
    one->Print();//==(*three).Print();
    Neytronka* two = new Neytronka;
    two->Print();



    delete one;
    delete two;
}
