#include <iostream>
#include <string>

using namespace std;

enum TipCalculator { DESKTOP = 1, LAPTOP = 2};

class Calculator
{
private:

	const int id;
	string marca;
	string procesor;
	int ram;
	float pret;
	TipCalculator tip;
	int nrComponente;
	float* preturiComponente;

public:

	static int nrCalculatoare;
	Calculator() : id(++nrCalculatoare)
	{
		this->marca = " fara_nume ";
		this->procesor = " intel i5 ";
		this->ram = 8;
		this->pret = 2100.0;
		this->tip = LAPTOP;
		this->nrComponente = 0;
		this->preturiComponente = nullptr;
	}


	Calculator(string procesor) : id(++nrCalculatoare)
	{
		this->marca = " fara_nume ";
		this->procesor = procesor;
		this->ram = 16;
		this->pret = 3500.0;
		this->tip = LAPTOP;
		this->nrComponente = 0;
		this->preturiComponente = nullptr;
	}

	Calculator(string procesor, string marca) : id(++nrCalculatoare)
	{
		this->marca = marca;
		this->procesor = procesor;
		this->ram = 32;
		this->pret = 4000.0;
		this->tip = LAPTOP;
		this->nrComponente = 0;
		this->preturiComponente = nullptr;

	}

	Calculator(string procesor, string marca, int ram, float pret, TipCalculator tip=DESKTOP, int nrComponente = 0,float* preturiComponente=nullptr ) : id(++nrCalculatoare)
	{
		this->marca = marca;
		this->procesor = procesor;
		this->ram = ram;
		this->pret = pret;
		this->tip = tip;
		this->nrComponente = nrComponente;

		if (this->nrComponente > 0 and preturiComponente != nullptr)
		{
			this->preturiComponente = new float[this->nrComponente];
			for (int i = 0;i < this->nrComponente;i++)
			{
				this->preturiComponente[i] = preturiComponente[i];
			} 
		}
		else {
			this->preturiComponente = nullptr;
		}
	}

	Calculator(const Calculator& c) : id(++nrCalculatoare)
	{
		this->marca = c.marca;
		this->procesor = c.procesor;
		this->ram = c.ram;
		this->pret = c.pret;
		this->tip = c.tip;
		this->nrComponente = c.nrComponente;

		if (c.preturiComponente != nullptr and c.nrComponente > 0)

		{
			this->preturiComponente = new float[c.nrComponente];
			for (int i = 0;i < c.nrComponente;i++)
			{
				this->preturiComponente[i] = c.preturiComponente[i];

			}
		} else {
			this->preturiComponente = nullptr;
		}

	}


	void operator=(const Calculator& c)
	{
		if (this != &c)
		{
			if (this->preturiComponente != nullptr)
			{
				delete[] this->preturiComponente;
				this->preturiComponente = nullptr;

			}
			this->marca = c.marca;
			this->procesor = c.procesor;
			this->ram = c.ram;
			this->pret = c.pret;
			this->tip = c.tip;
			this->nrComponente = c.nrComponente;

			if (c.preturiComponente != nullptr and c.nrComponente > 0)
			{
				this->preturiComponente = new float[c.nrComponente];
				for (int i = 0; i < c.nrComponente;i++)
				{
					this->preturiComponente[i] = c.preturiComponente[i];

				}
			}
			else {
				this->preturiComponente = nullptr;
			}
		}
	}


	void afisareCalculator()
	{
		cout << endl;
		cout << " ID Calculator: " << this->id << endl;
		cout << " Marca: " << this->marca << endl;
		cout << " Procesor: " << this->procesor << endl;
		cout << " Memorie RAM: " << this->ram << "GB" << endl;
		cout << " Pret: " << this->pret << "LEI" << endl;
		cout << " Tip " << (this->tip == DESKTOP ? " DESKTOP" : "LAPTOP") << endl;

		if (this->nrComponente > 0 and this->preturiComponente != nullptr)
		{
			cout << " Preturi componente: ";
			for (int i = 0; i < this->nrComponente;i++)
			{
				cout << this->preturiComponente[i] << "LEI ";
			}
			cout << endl;
		}
	}

	~Calculator() 
	{
		if (this->preturiComponente != nullptr)
		{
			delete[] this->preturiComponente;
		}
	}



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

	Calculator C5 = C4;
	cout << " Calculatorul 5 ( creat prin copia lui C4 ) " << endl;
	C5.afisareCalculator();
	cout << endl;

	C1 = C4;
	cout << " Calculatorul 1 ( dupa atribuirea C1 = C4 ) " << endl;
	C1.afisareCalculator();
	cout << endl;

	cout << "In total s-au comandat " << Calculator::nrCalculatoare << " calculatoare!" << endl;

	return 0;
}