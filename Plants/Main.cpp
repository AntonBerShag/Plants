#include <iostream>
#include <string>

using namespace std;

class Plants {
public:
	static int fruits;
	static int berries;

	Plants() {
		count++;
	}
	Plants(string name, int count) :Plants() {
		name = name;
		fruits += count;
	}

	virtual ~Plants() {
		count--;
	}

	void setName(string name) {
		name = name;
	}

	string getName() {
		return name;
	}
	static int getCounter() {
		return count;
	}
	static int getFruits() {
		return fruits;
	}

private:
	string name;
	static int count;
};

class Trees : Plants {
public:
	Trees() {}
	Trees(string name, int count) {
		Plants::setName(name);
		berries += count;
	}
	virtual ~Trees() {}
	void setName(string& name) {
		name = name;
	}
	string getName() {
		return name;
	}

	int getFetus(int fetus) {
		fetus -= fetus;
		return fetus;
	}
private:
	string name;
	int fetus;
};

class Bushes : Plants {
public:
	Bushes() {}
	Bushes(string name, int count) {
		Plants::setName(name);
		berries += count;
	}
	virtual ~Bushes() {}
};

class FruitOfTree {
public:
	FruitOfTree() {}
	virtual ~FruitOfTree() {}
	static int getFetus() {
		return Plants::fruits + Plants::berries;
	}
};

class Fruits : FruitOfTree {
public:
	Fruits() {}

	virtual ~Fruits() {}
	static int getFetus(int fetus) {
		Plants::fruits -= fetus;
		return Plants::fruits;
	}
};

class Berries : FruitOfTree {
public:
	Berries() {}

	virtual ~Berries() {}
	static int getFetus(int fetus) {
		Plants::berries -= fetus;
		return Plants::berries;
	}
};
int Plants::fruits = 0;
int Plants::berries = 0;
int Plants::count = 0;

int main() {

	Trees Grusha("Grusha", 4);
	Trees Vishna("Vishna", 6);

	Bushes Shipovnik("Shipovnik", 40);
	Bushes Bouaroshnik("Bouaroshnik", 20);

	std::cout << "Common quantity of plants: " << Plants::getCounter() << endl;
	std::cout << "Common quantity of fruits: " << Plants::fruits << endl;
	std::cout << "Common quantity of berries: " << Plants::berries << endl;

	int n = 5;

	std::cout << "getting Fetus: " << n << " " << Fruits::getFetus(n) << endl;
	std::cout << "getting Berries: " << n << " " << Berries::getFetus(n) << endl;
	std::cout << "Commont quantity of getted Fetus: " << FruitOfTree::getFetus() << endl;

	return 0;
}
