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
	if (rand() % 2 == 0) { // 짝수일때는 ad 를 쓴다고 합시다.
		enemy.str();
		enemy.health -= ad;
		cout << this->name << "이 " << enemy.name << "에게 " << ad << "만큼의 피해를 입혔습니다.\n";
		enemy.str();
	}
	else { // 홀수일땐 ap
		enemy.str();
		enemy.health -= ap;
		cout << this->name << "이 " << enemy.name << "에게 " << ap << "만큼의 피해를 입혔습니다.\n";
		enemy.str();
	}
}

void Champion::str() {
	cout << "이름:" << name << " 체력:" << health << " 마나:" << mana << " AD:" << ad << " AP:" << ap << endl;
}

class ADChampion : public Champion {
public:
	ADChampion(string name, int health, int mana, int ad, int ap) : Champion(name, health, mana, ad + 20, ap - 10) {};
	void attack(Champion& enemy);
};

void ADChampion::attack(Champion& enemy) {
	enemy.str();
	enemy.health -= ad;
	cout << this->name << "이 " << enemy.name << "에게 " << ad << "만큼의 물리피해를 입혔습니다.\n";
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
	cout << this->name << "이 " << enemy.name << "에게 " << ap << "만큼의 마법피해를 입혔습니다.\n";
	enemy.str();
}

int main() {
	Champion singed("신지드", 100, 50, 5, 30);
	ADChampion yasuo("야스오", 80, 0, 20, 10);
	APChampion lux("럭스", 60, 100, 10, 50);
	singed.attack(yasuo);
	lux.attack(singed);
}