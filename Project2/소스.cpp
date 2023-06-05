#include <iostream>
#include <string>
using namespace std;

class Character;
class physicalCharacter;
class magicalCharacter;

class Character {
protected:
    string name;
public:
    int health;
    int damage;
    Character(string name, int damage, int health);
    virtual void specialAttack();
    void stat();
};

Character::Character(string name, int damage, int health) {
    this->name = name;
    this->damage = damage;
    this->health = health;
}

void Character::specialAttack() {
    cout << "일반 공격!" << endl;
}

void Character::stat() {
    cout << "이름: " << name << ", 체력: " << health << ", 공격력: " << damage << endl;
}

class physicalCharacter : public Character {
public:
    void specialAttack() {
        cout << "물리 특수 공격!" << endl;
    }
};

class magicalCharacter : public Character {
public:
    void specialAttack() {
        cout << "마법 특수 공격!" << endl;
    }
};

void healCharacter(Character& character, int amount) {
    character.health += amount;
    cout << character.name << "의 체력이 " << amount << "만큼 회복되었습니다." << endl;
}

int main() {
    int physicitemNumber;
    int magicalitemNumber;
    physicalCharacter A("A", 100, 1000);
    cout << "character 1: 물리 피해 입힘" << endl;
    A.stat();
    magicalCharacter B("B", 100, 1000);
    cout << "character 2: 마법 피해 입힘" << endl;
    B.stat();

    cout << "아이템" << endl;
    cout << "─────────────────" << endl;
    cout << "item 1: 물리 피해 +100, 마법 피해 +0" << endl;
    cout << "item 2: 물리 피해 +50, 마법 피해 +50" << endl;
    cout << "item 3: 물리 피해 +0, 마법 피해 +100" << endl;
    cout << "─────────────────" << endl;

    cout << "character 1에게 아이템 하나 추가(아이템 번호 1, 2 중 입력) : ";
    cin >> physicitemNumber;
    cout << "character 2에게 아이템 하나 추가(아이템 번호 2, 3 중 입력) : ";
    cin >> magicalitemNumber;

    Character* character1Ptr = &A;
    Character* character2Ptr = &B;

    physicalCharacter* physicalPtr = &A;
    if (physicitemNumber == 1) {
        physicalPtr->damage += 100;
    }
    else if (physicitemNumber == 2) {
        physicalPtr->damage += 50;
    }
    else {
        cout << "잘못된 아이템 번호" << endl;
    }

    magicalCharacter* magicalPtr = &B;
    if (magicalitemNumber == 2) {
        magicalPtr->damage += 50;
    }
    else if (magicalitemNumber == 3) {
        magicalPtr->damage += 100;
    }
    else {
        cout << "잘못된 아이템 번호" << endl;
    }

    A.stat();
    B.stat();
    cout << "─────────────────" << endl;
    cout << "character 1이 character 2를 공격" << endl;
    character1Ptr->specialAttack();
    int attackPower = character1Ptr->damage;
    character2Ptr->health -= attackPower;
    A.stat();
    B.stat();
    cout << "\n";
    cout << "character 2가 character 1를 공격" << endl;
    character2Ptr->specialAttack();
    int attackPower2 = character2Ptr->damage;
    character1Ptr->health -= attackPower2;
    A.stat();
    B.stat();

    cout << "─────────────────" << endl;
    cout << "A를 얼마만큼 치유할까요? : ";
    int amount;
    cin >> amount;
    healCharacter(A, amount);
    A.stat();

    return 0;
}
