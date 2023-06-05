#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Character;
class physicalCharacter;
class magicalCharacter;

class Character {
private:
    string name;
public:
    int health;
    int damage;
    Character(string name, int damage, int health);
    int attack();
    void stat();
    static void plusItem(int physicitemNumber, int magicalitemNumber, physicalCharacter& A, magicalCharacter& B);
    friend void healCharacter(Character& character, int amount);
    int special_attack();
};

Character::Character(string name, int damage, int health) {
    this->name = name;
    this->damage = damage;
    this->health = health;
}

class physicalCharacter : public Character {
public:
    int physical_damage;
    physicalCharacter(string name, int physical_damage, int health) : Character(name, physical_damage, health) {
        this->physical_damage = physical_damage;
    }
};

class magicalCharacter : public Character {
public:
    int magical_damage;
    magicalCharacter(string name, int magical_damage, int health) : Character(name, magical_damage, health) {
        this->magical_damage = magical_damage;
    }
};

void Character::plusItem(int physicitemNumber, int magicalitemNumber, physicalCharacter& A, magicalCharacter& B) {
    if (physicitemNumber == 1) {
        A.damage += 100; // A의 physical_damage 값을 변경
    }
    else if (physicitemNumber == 2) {
        A.damage += 50;
    }
    else {
        cout << "잘못된 아이템 번호" << endl;
    }
    if (magicalitemNumber == 2) {
        B.damage += 50;
    }
    else if (magicalitemNumber == 3) {
        B.damage += 100;
    }
    else {
        cout << "잘못된 아이템 번호" << endl;
    }
}

void Character::stat() {
    cout << "이름: " << name << ", 체력: " << health << ", 공격력: " << damage << endl;
}

int Character::attack() {
    return damage;
}

int Character::special_attack() {
    return damage * 2;
}

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
    Character::plusItem(physicitemNumber, magicalitemNumber, A, B);
    A.stat();
    B.stat();
    cout << "─────────────────" << endl;
    cout << "character 1이 character 2를 공격" << endl;
    int attackPower = A.attack();
    B.health -= attackPower;
    A.stat();
    B.stat();
    cout << "\n";
    cout << "character 2가 character 1를 공격" << endl;
    int attackPower2 = B.attack();
    A.health -= attackPower2;
    A.stat();
    B.stat();

    cout << "─────────────────" << endl;
    cout << "A를 얼마만큼 치유할까요? : ";
    int amount;
    cin >> amount;
    healCharacter(A, amount);
    A.stat();

    Character* character1Ptr = &A;
    Character* character2Ptr = &B;

    A.special_attack();

    return 0;
}
