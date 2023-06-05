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
        A.damage += 100; // A�� physical_damage ���� ����
    }
    else if (physicitemNumber == 2) {
        A.damage += 50;
    }
    else {
        cout << "�߸��� ������ ��ȣ" << endl;
    }
    if (magicalitemNumber == 2) {
        B.damage += 50;
    }
    else if (magicalitemNumber == 3) {
        B.damage += 100;
    }
    else {
        cout << "�߸��� ������ ��ȣ" << endl;
    }
}

void Character::stat() {
    cout << "�̸�: " << name << ", ü��: " << health << ", ���ݷ�: " << damage << endl;
}

int Character::attack() {
    return damage;
}

int Character::special_attack() {
    return damage * 2;
}

void healCharacter(Character& character, int amount) {
    character.health += amount;
    cout << character.name << "�� ü���� " << amount << "��ŭ ȸ���Ǿ����ϴ�." << endl;
}

int main() {
    int physicitemNumber;
    int magicalitemNumber;
    physicalCharacter A("A", 100, 1000); 
    cout << "character 1: ���� ���� ����" << endl;
    A.stat();
    magicalCharacter B("B", 100, 1000);
    cout << "character 2: ���� ���� ����" << endl;
    B.stat();

   
    
    cout << "������" << endl;
    cout << "����������������������������������" << endl;
    cout << "item 1: ���� ���� +100, ���� ���� +0" << endl;
    cout << "item 2: ���� ���� +50, ���� ���� +50" << endl;
    cout << "item 3: ���� ���� +0, ���� ���� +100" << endl;
    cout << "����������������������������������" << endl;

    cout << "character 1���� ������ �ϳ� �߰�(������ ��ȣ 1, 2 �� �Է�) : ";
    cin >> physicitemNumber;
    cout << "character 2���� ������ �ϳ� �߰�(������ ��ȣ 2, 3 �� �Է�) : ";
    cin >> magicalitemNumber;
    Character::plusItem(physicitemNumber, magicalitemNumber, A, B);
    A.stat();
    B.stat();
    cout << "����������������������������������" << endl;
    cout << "character 1�� character 2�� ����" << endl;
    int attackPower = A.attack();
    B.health -= attackPower;
    A.stat();
    B.stat();
    cout << "\n";
    cout << "character 2�� character 1�� ����" << endl;
    int attackPower2 = B.attack();
    A.health -= attackPower2;
    A.stat();
    B.stat();

    cout << "����������������������������������" << endl;
    cout << "A�� �󸶸�ŭ ġ���ұ��? : ";
    int amount;
    cin >> amount;
    healCharacter(A, amount);
    A.stat();

    Character* character1Ptr = &A;
    Character* character2Ptr = &B;

    A.special_attack();

    return 0;
}
