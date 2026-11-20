#include <iostream>
#include <string>
using namespace std;

class ExceptieSalariu : public exception
{
public:
	ExceptieSalariu(const char* mesaj) : exception(mesaj){}
};

class Angajat
{
protected:
	const int marca;
	string nume;
	float salariuBaza;

public:
	static const float salariu_minim;

	Angajat() : marca(0), nume("Anonim"), salariuBaza(3000)
	{

	}

	Angajat(int marcaA, string numeA, float salariuA) : marca(marcaA), nume(numeA), salariuBaza(salariuA)
	{
		if (salariuBaza < salariu_minim)
		{
			throw ExceptieSalariu(" Salariul este sub minimul pe economie");
		}
	}

	virtual void afisare()
	{
		cout << endl << "Marca: " << this->marca;
		cout << endl << "Nume: " << this->nume;
		cout << endl << "Salariu baza: " << this->salariuBaza << " RON";

	}

	virtual ~Angajat(){}

	virtual float getProcentBonus() = 0;


};

const float Angajat::salariu_minim = 2500;

class Programator : public Angajat
{

private: 
	float procentBonus;

public:

	Programator() :Angajat()
	{
		this->procentBonus = 0;
	}

	Programator(int marcaA, string numeA, float salariuA, float procentBonusP) :Angajat(marcaA, numeA, salariuA)
	{
		this->procentBonus = procentBonusP;
	}

	void afisare() override
	{
		this->Angajat::afisare();
		cout << endl << "Procent bonus de performanta: " << this->procentBonus << "%";
	}

	float getProcentBonus() override
	{
		return this->procentBonus;
	}
};

class CalculFinanciar
{
public:
	virtual float calculImpozit(float sumaBruta) = 0;
	virtual float calculNet(float sunaBruta) = 0;
	virtual ~CalculFinanciar(){}
};


class CalculatorTaxe :public CalculFinanciar
{
public:

	CalculatorTaxe(){}

	float calculImpozit(float sumaBruta)override
	{
		return sumaBruta * 0.10;

	}

	float calculNet(float sumaBruta)override
	{
		return sumaBruta - calculImpozit(sumaBruta);
	}
};

int main()
{
	try
	{
		Programator stagiar(100, "Radu Ion", 1500, 5);
		
	}
	catch (exception& e)
	{
		cout << "Eroare prinsa: " << e.what() << endl;
	}

	Angajat* echipa[3];
	echipa[0] = new Programator(101, " Pop Ioana", 8000, 15);
	echipa[1] = new Programator(102, " Iordache Iulian", 9000, 20);
	echipa[2] = new Programator(103, " Stoian Mihaela", 6500, 10);

	cout << "\n Componenta echipei: ";
	for (int i = 0; i < 3; i++)
	{
		echipa[i]->afisare();
		cout << endl;
		delete echipa[i];
	}

	Angajat* pAngajat = new Programator();
	pAngajat->afisare();
	cout << endl;
	delete pAngajat;

	CalculFinanciar* calcul = new CalculatorTaxe();
	cout << endl << "Salariu net pt 8000 RON brut: " << calcul->calculNet(8000) << " RON"<<endl;
	delete calcul;


	return 0;

}