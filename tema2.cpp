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

	int getId() { return this->id; }
	string getMarca() { return this->marca; }
	string getProcesor() { return this->procesor; }
	int getRam() { return this->ram; }
	float getPret() { return this->pret; }

	void setMarca(string marcaNoua)
	{
		if (marcaNoua != "")
		{
			this->marca = marcaNoua;
		}
	}


	void setProcesor(string procesorNou)
	{
		if (procesorNou != "")
		{
			this->procesor = procesorNou;
		}
	}

	void setRam(int ramNou)
	{
		if (ramNou > 0)
		{
			this->ram = ramNou;
		}
		else {
			throw "RAM-ul trebuie sa fie nr pozitiv!";
		}
	}

	void setPret(float pretNou)
	{
		if (pretNou >= 0)
		{
			this->pret = pretNou;
		}
		else {
			throw "Pretul nu poate fi negativ!";
		}
	}

	~Calculator()
	{ }

};

int Calculator::nrCalculatoare = 0;

int main()
{
	Calculator C1;
	cout << " Calculatorul 1 ( surpriza )" << endl;
	C1.afisareCalculator();

	try 
	{
		C1.setMarca("Dell");
		C1.setRam(16);
	}

	catch (const char* mesaj)
	{
		cout << endl << " EXCEPTIE: " << mesaj << endl;
	}

	cout << "\n Calculatorul 1 ( dupa setMarca si setRam )" << endl;
	C1.afisareCalculator();

	cout << "\n Citire cu getter Ram-ul C1 este : " << C1.getRam() << "GB" << endl;

	Calculator C2(" Intel i9 ", " Lenovo ", 32, 8900.5);
	cout << "\n Calculatorul 2 ( totul cunoscut )" << endl;

	C2.afisareCalculator();

	cout << "\n In total s-au comandat " << Calculator::nrCalculatoare << " calculatoare!" << endl;


	return 0;
}