#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Companie
{
private:
	char* numeCompanie;
	const int idCompanie;
	double cifraAfaceri;

	static int Contor_ID;

public:

	Companie() : idCompanie(++Contor_ID)

	{
		this->numeCompanie = new char[strlen("Anonim") + 1];
		strcpy(this->numeCompanie, "Anonim");
		this->cifraAfaceri = 0.0;

	}

	Companie(const char* nume) : idCompanie(++Contor_ID)
	{
		if (nume != nullptr and strlen(nume) > 0)
		{
			this->numeCompanie = new char[strlen(nume) + 1];
			strcpy(this->numeCompanie, nume);

		}
		else
		{
			this->numeCompanie = new char[strlen("Anonim") + 1];
			strcpy(this->numeCompanie, "Anonim");
		}

		this->cifraAfaceri = 0.0;
	}

	~Companie()
	{
		if (this->numeCompanie != nullptr)
		{
			delete[] this->numeCompanie;
			this->numeCompanie = nullptr;
		}
	}

	int getIdCompanie() const
	{
		return this->idCompanie;
	}

	void setNumeCompanie(const char* nouNume)
	{
		if (nouNume != nullptr and strlen(nouNume) > 0)
		{
			if (this->numeCompanie != nullptr)
			{
				delete[] this->numeCompanie;
			}

			this->numeCompanie = new char[strlen(nouNume) + 1];
			strcpy(this->numeCompanie, nouNume);
		}
	}

	void setCifraDeAfaceri(double nouaCifra)
	{
		if (nouaCifra >= 0)
		{
			this->cifraAfaceri = nouaCifra;
		}
	}

	Companie& operator=(const Companie& c)
	{
		if (this != &c)
		{
			if (this->numeCompanie != nullptr)
			{
				delete[] this->numeCompanie;

			}

			if (c.numeCompanie != nullptr)
			{
				this->numeCompanie = new char[strlen(c.numeCompanie) + 1];
				strcpy(this->numeCompanie, c.numeCompanie);
			}
			else
			{
				this->numeCompanie = nullptr;
			}

			this->cifraAfaceri = c.cifraAfaceri;
		}

		return *this;
	}

	void afisare() const
	{
		cout << " \nID Companie: " << this->idCompanie << endl;
		cout << " Nume Companie: " << (this->numeCompanie != nullptr ? this->numeCompanie : "Necunoscut") << endl;
		cout << " Cifra de afaceri: " << this->cifraAfaceri << " RON\n" << endl;
	}

};

int Companie::Contor_ID = 100;

int main()
{
	Companie C1;
	C1.afisare();

	Companie C2("Tech Solutions");
	cout << " Compania C2 " << endl;

	C2.setNumeCompanie("Lenovo");
	C2.setCifraDeAfaceri(370000.78);
	C2.afisare();
	cout << " Compania C2 dupa metodele set " << endl;

	Companie C3;
	C3 = C2;
	cout << " Compania C3 identica C2" << endl;
	C3.afisare();

	return 0;
}