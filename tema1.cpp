#include <iostream>
#include <string>

using namespace std;

class Calculator
{
private:

	const int id;
	string marca;
	string procesor;
	int ram;
	float pret;

public:

	static int nrCalculatoare;
	Calculator() : id(++nrCalculatoare)
	{
		this->marca = " fara_nume ";
		this->procesor = " intel i5 ";
		this->ram = 8;
		this->pret = 2100.0;
	}


	Calculator(string procesor) : id(++nrCalculatoare)
	{
		this->marca = " fara_nume ";
		this->procesor = procesor;
		this->ram = 16;
		this->pret = 3500.0;
	}

	Calculator(string procesor, string marca) : id(++nrCalculatoare)
	{
		this->marca = marca;
		this->procesor = procesor;
		this->ram = 32;
		this->pret = 4000.0;
	}

	Calculator(string procesor, string marca, int ram, float pret) : id(++nrCalculatoare)
	{
		this->marca = marca;
		this->procesor = procesor;
		this->ram = ram;
		this->pret = pret;
	}

	void afisareCalculator()
	{
		cout << endl;
		cout << " ID Calculator: " << this->id << endl;
		cout << " Marca: " << this->marca << endl;
		cout << " Procesor: " << this->procesor << endl;
		cout << " Memorie RAM: " << this->ram << "GB" << endl;
		cout << " Pret: " << this->pret << "LEI" << endl;
	}

	~Calculator() {}



};


int Calculator::nrCalculatoare = 0;


int main()
{
	Calculator C1;
	cout << " Calculatorul 1 ( surpriza ) " << endl;
	C1.afisareCalculator();
	cout << endl;

	Calculator C2("AMD Ryzen 9");
	cout << " Calculatorul 2 (procesor cunoscut) " << endl;
	C2.afisareCalculator();
	cout << endl;

	Calculator C3("Intel i7", "HP");
	cout << " Calculatorul 3 ( procesor si marca cunoscute )" << endl;
	C3.afisareCalculator();
	cout << endl;

	Calculator C4("Intel i9", "Lenovo", 32, 8900.5);
	cout << " Calculatorul 4 ( total cunoscut ) " << endl;
	C4.afisareCalculator();
	cout << endl;

	cout << "In total s-au comandat " << Calculator::nrCalculatoare << " calculatoare!" << endl;

	return 0;
}
