#include <iostream>
#include <string>
#include <vector>

using namespace std;


//prima clasa
class Ingredient
{
    string* nume;
    float* cantitate;

public:
    //constructor de copiere
    Ingredient(const Ingredient& other)
        : nume(new string(*other.nume)), cantitate(new float(*other.cantitate)) {}

    //constructor cu toti param
    Ingredient(const  string& nume, float cantitate)
        : nume(new  string(nume)), cantitate(new float(cantitate)) {}

    //destructor
    ~Ingredient()
    {
        delete nume;
        delete cantitate;
    }
    //supraincarcare >>
    friend istream& operator >> (istream& in, Ingredient& ingredient)
    {
        cout << "Nume ingredient: ";
        in >> *ingredient.nume;
        cout << "Cantitate: ";
        in >> *ingredient.cantitate;
        return in;
    }
    //supraincarcare <<
    friend  ostream& operator << (ostream& out, Ingredient& ingredient) {
        out << "Nume ingredient: " << *ingredient.nume << endl;
        out << "Cantitate: " << *ingredient.cantitate << endl;
        return out;
    }
    //accesor set + get
    void setAdaugCantitate( float cantitate)
    {
        if (this->cantitate != 0)
            this->cantitate = cantitate;
    }
    float * getCantitateNoua()
    {
        return cantitate;
    }
};
//a doua clasa
class Preparat
{
    string denumire;
    int numar_ordine;
    vector<Ingredient> ingredients;
public:
    //constructor de copiere
    Preparat(const Preparat& other)
    {
        this->denumire = other.denumire;
        this->numar_ordine = other.numar_ordine;
        this->ingredients = other.ingredients;
    }
    //destructor
    ~Preparat() {}
    //constructor cu toti param
    Preparat(string denumire, int numar_ordine, vector<Ingredient>ingredients)
    {
        this->denumire = denumire;
        this->numar_ordine = numar_ordine;
        this->ingredients = ingredients;
    }
    //supraincarcare cu >>
    friend istream& operator >>(istream& in, Preparat& preparat)
    {
        cout << "Denumirea preparatului: ";
        in >> preparat.denumire;
        cout << "Numarul de ordine al preparatului: ";
        in >> preparat.numar_ordine;
        return in;
        

    }
    //supraincarcare<<
    friend  ostream& operator << (ostream& out, Preparat& preparat) {
        out << "Denumire Preparat: " << preparat.denumire << endl;
        out << "Numar de ordine Preparat: " << preparat.numar_ordine << endl;
        return out;
    }
   
};
int main()
{
    Ingredient ingredient("Faina", 100);
     vector<Ingredient> ingredients;
    ingredients = {
            Ingredient("Faina", 100),
            Ingredient("Zahar", 200),
            Ingredient("Sare", 50),
            Ingredient("Ulei", 150),
            Ingredient("Lapte", 300)
    };
    vector<Ingredient> Ingrediente_oua;
    Ingrediente_oua = 
    {
        Ingredient("oua",3) ,
        Ingredient("ulei",5),
        Ingredient("sare",0.2)
    };
    for (Ingredient i : ingredients) {
        cout << i;
        cout << endl;
    }
    Preparat preparat("Clatite", 12, ingredients);
    vector<Preparat>preparate;
    preparate =
    {
        Preparat("clatite",12,ingredients),
        Preparat("oua",2,Ingrediente_oua)
    };
    for (Preparat i : preparate)
    {
        cout << i << endl;
    }
    float a = 250;
    ingredient.setAdaugCantitate(&a);
    ingredient.getCantitateNoua();
    return 0;
}
