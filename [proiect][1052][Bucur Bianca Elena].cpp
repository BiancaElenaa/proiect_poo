// [proiect][1052][Bucur Bianca Elena].cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <string.h>

using namespace std;
//prima clasa
class ingredient
{
	const string* denumireIngrediente;
	float* cantitatea_disponibila;

public:

	//destructorul clasei
	~ingredient()
	{
		delete []denumireIngrediente;
		delete cantitatea_disponibila;
	}

	//constructor
	ingredient(const string* denumireIngrediente, float* cantitatea_disponibila,int nrIng) 
	{
		this->denumireIngrediente = new string[nrIng];
		this->denumireIngrediente = denumireIngrediente;
	this->cantitatea_disponibila = cantitatea_disponibila;

	
	}
	ingredient() : denumireIngrediente(nullptr), cantitatea_disponibila(nullptr)
	{}
	void afisare()
	{
		cout << "Denumire ingrediente";
		if(denumireIngrediente!=nullptr)
		{
			for (int i = 0;i<3;i++)
			{
				cout << denumireIngrediente[i] << ' ';
			}
		}

	}
};

//a doua clasa
class preparat
{
	string denumire_preparat;
	static int numar_ordine_preparat;
	//int numar_ingrediente;
	ingredient** lista_ingrediente;
	float* cantitatile_necesare;
public:
	//destructorul clasei
	~preparat()
	{
		//delete denumire_preparat;
		delete[] lista_ingrediente;
		delete cantitatile_necesare;
	}

	//constructor 
	preparat() :denumire_preparat(nullptr), lista_ingrediente(nullptr), cantitatile_necesare(nullptr) {}
	preparat(const string& denumire_preparat, ingredient** lista_ingrediente, float cantitatile_necesare, int numar_ingrediente) {
		this->denumire_preparat = denumire_preparat;
		if(numar_ingrediente>0 && lista_ingrediente!=nullptr)
		{
			this->lista_ingrediente = new ingredient*[numar_ingrediente];
			for (int i = 0; i < numar_ingrediente; i++)
				this->lista_ingrediente[i] = new ingredient(*lista_ingrediente[i]);
		}
		

		/*cout << "numele preparatului :" << *denumire_preparat << "\n ingredientele sale:";
		if (lista_ingrediente != nullptr)
			cout << (lista_ingrediente[1].denumireIngredient) << " ";
		*/
	}
};
int preparat::numar_ordine_preparat = 1;

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
	meniu(preparat*denumirile_preparatelor,int numar_preparate_disponibile)
	{
		this->denumirile_preparatelor = denumirile_preparatelor;
		this->numar_preparate_disponibile = numar_preparate_disponibile;
	}

};

//a patra clasa
class comanda
{
	char* lista_produse_comandate;
	int numar_preparate_comandate;
public:
	//destructorul clasei
	~comanda()
	{
		delete[] lista_produse_comandate;
	}
	comanda(char* lista_produse_comandate, int numar_preparate_comandate)
	{
		strcpy(this->lista_produse_comandate, lista_produse_comandate);
		this->numar_preparate_comandate = numar_preparate_comandate;
	}

};

//a cincea clasa
class ospatar
{
	char* nume_ospatar = nullptr;
	int* id_comenzi = { 0 };
public:
	//destructorul clasei
	~ospatar()
	{
		
		delete id_comenzi;
	}
	ospatar	(){}
	ospatar( char* nume_ospatar, int * id_comenzi)
	{
		strcpy(this->nume_ospatar, nume_ospatar);
		id_comenzi = nullptr;
	}
};


int main()
{
	 string denumireIngrediente[] = {"oua", "lapte", "faina"};
	 float cantitatea_disponibila[] = {30.00, 100, 25};
	ingredient clatiteing(denumireIngrediente, cantitatea_disponibila, 3);
	//preparat clatite("clatitee", ("oua", "lapte", "faina"), (12, 23, 10), 3);
	clatiteing.afis();
	return 0;
}
