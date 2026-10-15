#include<iostream>
#include<string>
using namespace std;
class GameCharacter
{
public:
	string name;
	int hp;
	int level;
	// Constructor
	GameCharacter(string n, int h, int l)
	{
		name=n;
		hp=h;
		level=l;
		// 將 h 存入 hp
		// 將 l 存入 level
	}
	// 受到傷害
		void damage(int value)
		{
			// 1. hp 扣掉 value
			hp -= value;
			// 2. 如果 hp 小於 0 ，將 hp 設為 0
			if (hp < 0) {
				hp = 0;
			}
		}

		// 回復生命值
		void heal(int value)
		{
			hp += value;
			// 1. hp 加上 value
			if (hp > 100) {
				hp = 100;
			}
			// 2. 如果 hp 大於 100 ，將 hp 設為 100
		}

		// 升級
		void levelUp(int value)
		{
			if (level += 1) {
				hp = 100;
			}
			// 1. level 加 1
			// 2. hp 回復成 100
		}
		// 顯示角色資料
		void show()
		{
			cout<< "名稱:" << name << endl;
			cout << "血量:" << hp << endl;
			cout << "等級:" << level << endl;
			cout << "" << endl;
			// 顯示 name 、 hp 、 level
		}
	};
int main()
{
	int y,z,b,c;
	string a;
	cin >> a >> b >> c;
	GameCharacter p1(a, b, c);
	cout << "=====角色" << 1 << "=====" << endl;
	p1.show();
	cout << "" << endl;
	while (true) {
		cout << "=====選單" << "=====" << endl;
		cout << "1.扣血" << endl;
		cout << "2.回血" << endl;
		cout << "3.升級" << endl;
		cout << "4.Show角色資料" << endl;
		cout << "請選擇:";
		cin >> y;
		if (y == 1) {
			cout << "扣血:";
			cin >> z;
			p1.damage(z);
			cout << "" << endl;
			p1.show();
		}
		else if (y == 2) {
			cout << "回血:";
			cin >> z;
			p1.heal(z);
			cout << "" << endl;
			p1.show();

		}
		else if (y == 3) {
			cout << "升級:";
			cin >> z;
			p1.levelUp(z);
			cout << "" << endl;
			p1.show();
		}
		else if (y == 4) {
			cout << "Show角色資料:"<<endl;
			cout << "" << endl;
			p1.show();
		}
	}
		return 0;
}
