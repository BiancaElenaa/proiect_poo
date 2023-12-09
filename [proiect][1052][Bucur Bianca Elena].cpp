// [proiect][1052][Bucur Bianca Elena].cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
//prima clasa
class ingredient
{
	const string* denumireIngredient;
	float* cantitatea_disponibila;

public:
	
	//destructorul clasei
	~ingredient()
	{
		delete denumireIngredient;
		delete cantitatea_disponibila;
	}
	
	//constructor
	ingredient(const string &nume, float cantitate) : denumireIngredient(new string (nume)), cantitatea_disponibila(new float (cantitate)){}
	ingredient(): denumireIngredient(nullptr),cantitatea_disponibila(nullptr)
	{}
};

//a doua clasa
class preparat
{
	string* denumire_preparat;
	static int numar_total_preparate;
	ingredient* lista_ingrediente;
	float* cantitatile_necesare;
public:
	//destructorul clasei
	~preparat()
	{
		delete denumire_preparat;
		delete[] lista_ingrediente;
		delete cantitatile_necesare;
	}

	//constructor 
	preparat(const string& denumire,const string& lista,float cantitate,int nr) : denumire_preparat(new string (denumire)), lista_ingrediente(new ingredient[nr]), cantitatile_necesare(new float (cantitate))
	{
		
			cout << "numele preparatului :" << *denumire_preparat << "\n ingredientele sale:";
			if (lista_ingrediente != nullptr)
			cout << (lista_ingrediente[1].denumireIngredient) << " ";


		
	}
	preparat():denumire_preparat(nullptr),lista_ingrediente(nullptr),cantitatile_necesare(nullptr){}
	
};
int preparat::numar_total_preparate = 0;

//a treia clasa
class meniu
{
	preparat* denumirile_preparatelor;
	 int numar_preparate_disponibile;
public:
	//destructorul clasei
	~meniu()
	{
		delete[] denumirile_preparatelor;
	}
	//constructor
	meniu(const string& denum, int nr) :denumirile_preparatelor(new preparat[nr]), numar_preparate_disponibile(nr) {}
	
};

//a patra clasa
class comanda
{
	string* lista_produse_comandate;
	int numar_preparate_comandate;
public:
	//destructorul clasei
	~comanda()
	{
		delete[] lista_produse_comandate;
	}
	comanda(const string& list, int nr) :lista_produse_comandate(new string (list)), numar_preparate_comandate(nr)
	{}

};

//a cincea clasa
class ospatar
{
	string* nume_ospatar;
	bool* comanda_a_fost_preluata;
public:
	//destructorul clasei
	~ospatar()
	{
		delete nume_ospatar;
		delete comanda_a_fost_preluata;
	}
	ospatar(const string& nume, bool preluare):nume_ospatar(new string(nume)), comanda_a_fost_preluata(new bool(preluare))
	{}
};


int main()
{
	ingredient clatiteing(("oua","lapte","faina"), (30.0,100.0,25.0));
	preparat clatite("clatitee", ("oua", "lapte", "faina"), (12, 23, 10),3);
	//clatite.afis();
	return 0;
}