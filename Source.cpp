#include <iostream>

using namespace std;

class Animal {
public:
	virtual void voice() {
	}

	void DoSmth1() {//�����, ������� ����� �������������
		printf("Animal::DoSmth1\n");
	}

	void DoSmth2() {//�����, ������� ����� ������������� � Lion
		printf("Animal::DoSmth2\n");
	}

	virtual void DoSmth3() {//����������� �����
		printf("Animal::DoSmth3\n");
	}
	virtual string classname() {
		return "Animal";
	}
	virtual bool isA(string classname) {
		return(classname == "Animal");
	}


	virtual~Animal() {
		//printf("~Animal\n");
	}

};

class Lion : public Animal{
public:
	Lion() {

	}
	void sit() {
		printf("Lion::sit\n");
	}
	void voice() {
		printf("rrrrrr");
	}
	void DoSmth1() {
		printf("Lion::DoSmth1\n");
	}

	void DoSmth3() {
		printf("Lion::DoSmth3\n");
	}
	string classname() {
		return "Lion";
	}
	bool isA(string classname) {
		return(classname == "Lion");
	}


	~Lion() {
		//printf("~Lion\n");
	}
};

class Tiger : public Animal {
public:
	Tiger() {

	}

	void run() {
		printf("Tiger::run\n");
	}

	void voice() {
		printf("wwwww");
	}

	string classname() {
		return "Tiger";
	}

	bool isA(string classname) {
		return(classname=="Tiger");
	}
};




class Base {
public:
	Base() {
		printf("Base()\n");
	}

	Base(Base* obj) {
		printf("Base(Base* obj)\n");
	}

	Base(Base& obj) {
		printf("Base(Base& obj)\n");
	}

	virtual~Base() {
		printf("~Base()\n");
	}
};

class Desc : public Base {
public:
	Desc() {
		printf("Desc()\n");
	}

	Desc(Base* obj) {
		printf("Desc(Desc* obj)\n");
	}

	Desc(Base& obj) {
		printf("Desc(Desc& obj)\n");
	}

	~Desc() {
		printf("~Desc()\n");
	}
};


void func1(Base obj) {
	printf("void func1(Base obj)\n");
}

void func2(Base *obj) {
	printf("void func2(Base *obj)\n");
}

void func3(Base& obj) {
	printf("void func3(Base& obj)\n");
}

Base func11(Base obj) {
	//printf("Base func1()\n");
	return obj;
}

Base* func22(Base* obj) {
	//printf("Base* func1()\n");
	return obj;
}

Base& func33(Base& obj) {
	//printf("Base& func1()\n");
	return obj;
}



int main()
{
	srand(time(NULL));
	Lion* a = new Lion();//�������� ������� ����������, ����������� � ���������� ����������  
	a->DoSmth1();//����� ����������������� ������ 
	a->DoSmth2();//����� ������������ ������
	delete a;


	Animal* b = new Animal();;//�������� ������� �������� ������, ����������� � ���������� �������� ������  
	b->DoSmth3();//����� ������������ ������ �������� ������
	delete b;


	Animal* c = new Lion();//�������� ������� ����������, ����������� � ���������� �������� ������  
	c->DoSmth3();//����� ������������ ������������ ������
	delete c;


	printf("\n\n\n");


	Animal* d;
	if (rand() % 2 == 0) {
		d = new Lion();
	}
	else{
		d = new Tiger();
	}

	if (d->classname() == "Lion") { //�������� �� �������������� ���������� ������ 
		((Lion*)d)->sit();          //c ������� ������ classname
	}
	else {
		((Tiger*)d)->run();
	}
	delete d;




	Animal* e;
	if (rand() % 2 == 0) {
		e = new Lion();
	}
	else {
		e = new Tiger();
	}

	if (e->isA("Lion")) { //�������� �� �������������� ���������� ������ 
		((Lion*)e)->sit();//c ������� ������ isA
	}
	else {
		((Tiger*)e)->run();
	}
	delete e;




	Animal* f;
	if (rand() % 2 == 0) {
		f = new Lion();
	}
	else {
		f = new Tiger();
	}
	((Lion*)f)->sit(); //������� ���������� �����
	delete f;



	
	Animal* g;
	if (rand() % 2 == 0) {
		g = new Lion();
	}
	else {
		g = new Tiger();
	}
	if (dynamic_cast<Lion*>(g)) {//���������� ���������� ����� 
		((Lion*)g)->sit();       //� ������� dynamic_cast
	}
	else {
		((Tiger*)g)->run();
	}
	delete g;
	printf("\n\n\n\n\n\n\n");


	Base* h = new Base();
	func1(h);
	func2(h);
	func3(*h);
	printf("\n\n");
	

	Desc* i = new Desc();
	func1(*i);
	func2(i);
	func3(*i);
	delete i;
	printf("\n\n");

	func11(*h);
	func22(h);
	func33(*h);
	delete h;


	
	printf("\n\n");
	{
		unique_ptr<Base> unq(new Desc());
	}

	printf("\n\n");

	Base* j = new Desc();
	shared_ptr<Base> p1(j);
	{
		shared_ptr<Base> p2(p1);
	}




}