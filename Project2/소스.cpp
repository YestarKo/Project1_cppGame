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
    cout << "�Ϲ� ����!" << endl;
}

void Character::stat() {
    cout << "�̸�: " << name << ", ü��: " << health << ", ���ݷ�: " << damage << endl;
}

class physicalCharacter : public Character {
public:
    void specialAttack() {
        cout << "���� Ư�� ����!" << endl;
    }
};

class magicalCharacter : public Character {
public:
    void specialAttack() {
        cout << "���� Ư�� ����!" << endl;
    }
};

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
        cout << "�߸��� ������ ��ȣ" << endl;
    }

    magicalCharacter* magicalPtr = &B;
    if (magicalitemNumber == 2) {
        magicalPtr->damage += 50;
    }
    else if (magicalitemNumber == 3) {
        magicalPtr->damage += 100;
    }
    else {
        cout << "�߸��� ������ ��ȣ" << endl;
    }

    A.stat();
    B.stat();
    cout << "����������������������������������" << endl;
    cout << "character 1�� character 2�� ����" << endl;
    character1Ptr->specialAttack();
    int attackPower = character1Ptr->damage;
    character2Ptr->health -= attackPower;
    A.stat();
    B.stat();
    cout << "\n";
    cout << "character 2�� character 1�� ����" << endl;
    character2Ptr->specialAttack();
    int attackPower2 = character2Ptr->damage;
    character1Ptr->health -= attackPower2;
    A.stat();
    B.stat();

    cout << "����������������������������������" << endl;
    cout << "A�� �󸶸�ŭ ġ���ұ��? : ";
    int amount;
    cin >> amount;
    healCharacter(A, amount);
    A.stat();

    return 0;
}
