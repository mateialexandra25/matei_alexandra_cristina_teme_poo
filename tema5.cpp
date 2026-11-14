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

	Companie(const Companie& c) : idCompanie(++Contor_ID)
	{
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

	~Companie()
	{
		if (this->numeCompanie != nullptr)
		{
			delete[] this->numeCompanie;
			this->numeCompanie = nullptr;
		}
	}

	bool operator<(const Companie& c)
	{
		return this->cifraAfaceri < c.cifraAfaceri;
	}

	void operator+=(double sumaDeAdunat)
	{
		this->cifraAfaceri += sumaDeAdunat;
	}

	bool operator!()
	{
		return this->cifraAfaceri > 0;
	}

	double operator()(double valoareDeAdaugat)
	{
		return this->cifraAfaceri + valoareDeAdaugat;
	}

	char& operator[](int index)
	{
		if (this->numeCompanie != nullptr and index >= 0 and index < (int)strlen(this->numeCompanie))
		{
			return this->numeCompanie[index];
		} 
		else
		{
			throw exception();
		}
	}

	friend ostream& operator<<(ostream& out, const Companie& c)
	{
		out << "\nOperator de afisare:";
		out << "\nID Companie: " << c.idCompanie;
		out << "\nNume Companie: " << (c.numeCompanie != nullptr ? c.numeCompanie : "Necunoscut");
		out << "\nCifra de afaceri: " << c.cifraAfaceri << " RON\n";
		return out;
	}


	friend istream& operator>>(istream& in, Companie& c);

	Companie operator++(int)
	{
		Companie copie = *this;
		this->cifraAfaceri++;
		return copie;
	}

	Companie operator++()
	{
		this->cifraAfaceri++;
		return *this;
	}

};

int Companie::Contor_ID = 100;

istream& operator>>(istream& in, Companie& c)
{
	cout << "Introduceti numele companiei: ";
	char v[100];
	in >> ws;
	in.getline(v, 100);
	if (c.numeCompanie != nullptr)
	{
		delete[] c.numeCompanie;
	}
	c.numeCompanie = new char[strlen(v) + 1];
	strcpy(c.numeCompanie, v);

	
	cout << "Introduceti cifra de afaceri: ";
	in >> c.cifraAfaceri;

	return in;

}

int main()
{
	Companie C1;
	Companie C2("Lenovo");

	
	C2 += 370000.78;

	
	cout << C2;


	if (C1 < C2)
		cout << "C1 are cifra de afaceri mai mica decat C2.\n";

	
	if (!C2)
		cout << "C2 are cifra de afaceri mai mare ca 0.\n";

	
	cout << "Cifra de afaceri + bonus (operator()): " << C2(50000) << " RON\n";

	
	try
	{
		cout << "Prima litera din nume: " << C2[0] << endl;
		C2[0] = 'l';
		cout << "Prima litera modificata prin []: " << C2[0] << endl;
	}
	catch (exception&)
	{
		cout << "Index invalid!\n";
	}

	
	Companie C3 = ++C2;
	Companie C4 = C2++;
	cout << "C3 (dupa ++C2): " << C3;
	cout << "C4 (dupa C2++): " << C4;

	
	Companie C5;
	cin >> C5;
	cout << C5;

	return 0;
}