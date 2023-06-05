#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Champion {
public:
	string name;
	int health;
	int mana;
	int ad;
	int ap;
	Champion(string n, int h, int m, int ad, int ap);
	void attack(Champion& enemy);
	void str();

};

Champion::Champion(string n, int h, int m, int ad, int ap) {
	name = n;
	health = h;
	mana = m;
	this->ad = ad;
	this->ap = ap;
	str();
};

void Champion::attack(Champion& enemy) {
	srand(time(NULL));
	if (rand() % 2 == 0) { // ¦���϶��� ad �� ���ٰ� �սô�.
		enemy.str();
		enemy.health -= ad;
		cout << this->name << "�� " << enemy.name << "���� " << ad << "��ŭ�� ���ظ� �������ϴ�.\n";
		enemy.str();
	}
	else { // Ȧ���϶� ap
		enemy.str();
		enemy.health -= ap;
		cout << this->name << "�� " << enemy.name << "���� " << ap << "��ŭ�� ���ظ� �������ϴ�.\n";
		enemy.str();
	}
}

void Champion::str() {
	cout << "�̸�:" << name << " ü��:" << health << " ����:" << mana << " AD:" << ad << " AP:" << ap << endl;
}

class ADChampion : public Champion {
public:
	ADChampion(string name, int health, int mana, int ad, int ap) : Champion(name, health, mana, ad + 20, ap - 10) {};
	void attack(Champion& enemy);
};

void ADChampion::attack(Champion& enemy) {
	enemy.str();
	enemy.health -= ad;
	cout << this->name << "�� " << enemy.name << "���� " << ad << "��ŭ�� �������ظ� �������ϴ�.\n";
	enemy.str();
}

class APChampion : public Champion {
public:
	APChampion(string name, int health, int mana, int ad, int ap) : Champion(name, health, mana, ad - 10, ap + 20) {};
	void attack(Champion& enemy);
};

void APChampion::attack(Champion& enemy) {
	enemy.str();
	enemy.health -= ap;
	cout << this->name << "�� " << enemy.name << "���� " << ap << "��ŭ�� �������ظ� �������ϴ�.\n";
	enemy.str();
}

int main() {
	Champion singed("������", 100, 50, 5, 30);
	ADChampion yasuo("�߽���", 80, 0, 20, 10);
	APChampion lux("����", 60, 100, 10, 50);
	singed.attack(yasuo);
	lux.attack(singed);
}