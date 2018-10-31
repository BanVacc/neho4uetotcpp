#include<cmath>
#include<iostream>
#include<vector>
#include<list>

const double NA = 6.022140857 * pow(10, 23);
const double Vm = 22.414;
class Element
{
private:
	int Amount;
	int _neutron;
	int _proton;
	int _electron;
	int ID = 0;
	double Ar = 0;
public:
	double Get_Ar() { return this->Ar; }
	int Get_Amount() { return this->Amount; }
	int OxidationState = 0;
	Element(int ID, int Ar, int OxidationState, int Amount = 1)
	{
		this->Ar = Ar;
		this->OxidationState = OxidationState;
		this->ID = ID;
		_proton = _electron = ID;
		_neutron = Ar - _electron;
		this->Amount = Amount;
	}
};

class Compound {
private:
	std::vector<Element> components;
	double n = 1;
	double m = 0;
	double Mr = 0;
	int OxidationState = 0;
public:
	///////////////////////////////////////////
	int Get_OxidationState() { return this->OxidationState; }
	double Get_n() { return this->n; }
	double Get_m() { return this->m; }
	double Get_N() { return(NA * this->n); }
	double Get_V() { return (this->n * Vm); }
	double Get_Mr() { return this->Mr; }
	///////////////////////////////////////////
	void Set_n(int n) { this->n = n; this->m = this->Mr*this->n; }
	void Set_m(int m) { this->m = m; this->n = this->m / this->Mr; }
	///////////////////////////////////////////
private:
	/*void calculate_DO_NOT_TOUCH(std::vector<Element> &elements) {
		for (int i = 0; i < elements.size(); i++)
		{
			this->Mr += elements[i].Get_Ar() * elements[i].Get_Amount();
			this->OxidationState += elements[i].OxidationState * elements[i].Get_Amount();
			this->m += elements[i].Get_Ar() * elements[i].Get_Amount();

		}	this->n = this->m / this->Mr;
	}*/

	void calculate_DO_NOT_TOUCH(std::initializer_list<Element> &elements) {
		for (auto element : elements) {
			this->Mr += element.Get_Ar()*element.Get_Amount();
			this->OxidationState += element.OxidationState*element.Get_Amount();
			this->m += element.Get_Ar()*element.Get_Amount();
		}
	}
public:
	///////////////////////////////////////////

	Compound(std::initializer_list<Element>elements) {
		this->calculate_DO_NOT_TOUCH(elements);
		for (auto element : elements) { this->components.push_back(element); }
	}
	void Add(std::initializer_list<Element>elements_to_add) {
		this->calculate_DO_NOT_TOUCH(elements_to_add);
		for (auto element : elements_to_add) { this->components.push_back(element); }
	}

};




int main() {
	Element C(6, 12, -4);
	Element H(1, 1, +1, 3);

	system("pause");
	return 0;
}




