#include <iostream>

class Marine
{
public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, int default_damage);
    ~Marine ();
    Marine(int x, int y, const char* marine_name);

    int attack() const;
    Marine& be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
    static void show_total_marine();

private:
    static int total_marine_sum;
    const static int i = 0;
    int hp;
    int coord_x, coord_y;
    // int damage;
    bool is_dead;

    const int default_damage;

    // char* name;
};
int Marine::total_marine_sum = 0;
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
          total_marine_sum++;
      }

// Marine::Marine() {
//     hp = 50;
//     coord_x = coord_y = 0;
//     damage = 5;
//     is_dead = false;
//     name = NULL;
// }

Marine::Marine(int x, int y) :
    coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
          total_marine_sum++;
      }

// Marine::Marine(int x, int y)
// {
//     coord_x = x;
//     coord_y = y;
//     hp = 50;
//     damage = 5;
//     is_dead = false;
//     name = NULL;
// }

Marine::Marine(int x, int y, int default_damage) 
    : coord_x(x), 
      coord_y(y), 
      hp(50), 
      default_damage(default_damage), 
      is_dead(false) {
          total_marine_sum++;
      }

void Marine::move(int x, int y)
{
    coord_x = x;
    coord_y = y;
}

// Marine::Marine(int x, int y, const char* marine_name)
// {
//     name = new char[strlen(marine_name) + 1];
//     strcpy(name, marine_name);
//
//     coord_x = x;
//     coord_y = y;
//     hp = 50;
//     damage = 5;
//     is_dead = false;
// }
Marine::~Marine()
{
    total_marine_sum--;
}
// Marine::~Marine()
// {
//     std::cout << name << "의 소멸자 호출!" << std::endl;
//     if (name) {
//        delete [] name;
//     }
// }
int Marine::attack() const { return default_damage; }

Marine& Marine::be_attacked(int damage_earn)
{
    hp -= damage_earn;
    if (hp <= 0) {
        is_dead = true;
    }

    return *this;
}
void Marine::show_status()
{
    // std::cout << "*** Marine : " << name << "***" << std::endl;
    std::cout << " Location : ( " << coord_x << ", " << coord_y << " )" << std::endl;
    std::cout << " HP : " << hp << std::endl;
    std::cout << "   현재 총 마린 수 : " << total_marine_sum << std::endl;
}

void Marine::show_total_marine() {
    std::cout << " 전체 마린 수 : " << total_marine_sum << std::endl;
}
void create_marine() {
    Marine marine3(10, 10, 4);
}

int main(int argc, char *argv[])
{
    Marine marine1(2, 3, 5);
    marine1.show_status();
    
    Marine marine2(3, 5, 19);
    marine2.show_status();

    create_marine(); // marine3은 이 함수의 종료와 함께 소멸된다.

    std::cout << std::endl << "마린 1이 마린 2를 공격!" << std::endl;
    marine2.be_attacked(marine1.attack()).be_attacked(marine1.attack());

    marine1.show_status();
    marine2.show_status();
}
