#include <iostream>
using namespace std;

class GameCharacter {
public:
    int health;
    int strength;

    GameCharacter(int h, int s) {
        health = h;
        strength = s;
    }

    void attack(GameCharacter& target) {
        target.health -= strength;
        cout << "Attacked! Target health is now " << target.health << endl;
    }
};
class Wizard : public GameCharacter {
public:
    int mana;

    Wizard(int h, int s, int m) : GameCharacter(h, s) {
        energy = m;
    }

    void castSpell(GameCharacter& target) {
        if (mana > 0) {
            target.health -= strength;
            mana -= 10;
            cout << "Spell cast! Target health is now " << target.health << ". mana left: " << mana << endl;
        } else {
            cout << "Not enough mana to cast a spell!" << endl;
        }
    }
};

int main() {
    GameCharacter enemy(300, 18);
    Wizard player(180, 220, 50);

    cout << "Enemy health: " << enemy.health << ", strength: " << enemy.strength << endl;
    cout << "Player health: " << player.health << ", strength: " << player.strength << ", mana: " << player.mana << endl;

    cout << "\nPlayer attacks enemy!" << endl;
    player.attack(enemy);

    cout << "\nPlayer casts a spell on enemy!" << endl;
    player.castSpell(enemy);

    cout << "\nEnemy health after attacks: " << enemy.health << endl;
    cout << "Player mana after casting: " << player.mana << endl;
    return 0;
