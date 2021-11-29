#include<iostream>
using namespace std;

//function decleration
void shop();
void monster();
void battle(int monsterhealth, char type);

// global variables (BAD)
string items[10] = { "bottle cap" };
int money = 10;
int turns = 0;
int health = 100;

int main() {

	//local variables
	int room = 1;
	string input;



	cout << "you wake up to find yourself in a dark and scary basement. Try to escape, go ahead. Good Luck" << endl;

	do { // beginning of game loop
		cout << "iventory; " << endl;
		for (int i = 0; i < 10; i++)
			cout << items[i] << " | ";
		cout << endl;

		cout << "you have had " << turns << " turns." << endl;
		turns++;
		cout << "your health is " << health << endl;
		switch (room) {
		case 1:
			monster();
			cout << "you are in a room. You can go North" << endl;
			cout << "press p for shop" << endl;
			cin >> input;
			if (input == "n")
				room = 2;
			else if (input == "p")
				shop();
			else
				cout << "Nope not an option. There's a wall there" << endl;

			break;
		case 2:
			if (items[4] != "shank") {
				cout << "you got a shiv!" << endl;
				items[4] = "Shiv";

			}
			cout << "you are in room 2. you can go North, or go back South ." << endl;
			cin >> input;
			if (input == "n")
				room = 3;
			else if (input == "s")
				room = 1;
			else
				cout << "Nope not an option. There's a wall there" << endl;
			if (input.compare("pick up") == 3)
				items[3] = "empty";
			break;
		case 3:
			cout << "you are in room 3. you can go East or West, or go back south" << endl;
			cin >> input;
			if (input == "w")
				room = 4;
			else if (input == "e")
				room = 5;
			else if (input == "s")
				room = 2;
			else
				cout << "Nope not an option. There's a wall there" << endl;
			if (input.compare("pick up") == 0)
				items[0] = "key";
			break;
		case 4:
			cout << "you are in room 4. you can go East." << endl;
			cin >> input;
			if (input == "e")
				room = 3;
			else
				cout << "Nope not an option. There's a wall there" << endl;
			break;
		case 5:
			cout << "you are in room 5. you can go North, or back West" << endl;
			cin >> input;
			if (input == "n")
				room = 6;
			else if (input == "w")
				room = 3;
		case 6:
			cout << "you are in room 6. you can go North or East, or back South" << endl;
			cin >> input;
			if (input == "n")
				room = 8;
			else if (input == "e")
				room = 7;
			else if (input == "s")
				room = 5;
		case 7:
			cout << "you are in room 7. you can only go back West" << endl;
			cin >> input;
			if (input == "w")
				room = 6;
		case 8:
			cout << "you are in room 8. you can go West or back South" << endl;
			cin >> input;
			if (input == "w")
				room = 9;
			else if (input == "s")
				room = 6;
			else
				cout << "Nope not an option. There's a wall there" << endl;
			break;
		case 9:
			cout << "you are in room 9. you can go East or back West" << endl;
			cin >> input;
			if (input == "w")
				room = 10;
			else if (input == "s")
				room = 8;
			else
				cout << "Nope not an option. There's a wall there" << endl;
			break;
		case 10:
			cout << "you are in room 10. you can go back East" << endl;
			cin >> input;
			if (input == "w")
				room = 9;
			else
				cout << "Nope not an option. There's a wall there" << endl;
			break;

		}// end switch
	} while (input != "q"); // end game loop

}

void monster() {
	int num = rand() % 100 + 1;
	if (num < 20) {
		cout << "a giant spider jumps on you!" << endl;
		battle(30, 's');
	}


	else if (num < 50) {
		cout << "a giang centipede crawls up your leg!" << endl;

		battle(10, 'c');
	}
	else if (num < 75) {
		cout << "a big dark creature slahes at you!" << endl;
		battle(50, 'p');
	}
	else
		cout << " nothing appears" << endl;
}
//battle system defenition 
void battle(int monsterhealth, char type) {
	int damage;
	while (monsterhealth > 0 && health > 0) {
		//monsetr attack first
		if (type == 'c')
			damage = rand() % 20;
		else if (type == 's')
			damage = rand() % 30;
		else if (type == 'p')
			damage = 40;
		cout << "the spider bites you for " << damage << " damage" << endl;
		health -= damage;
		cout << " you have " << health << " health left" << endl;
		//human atack
		if (items[4] == "Shiv") {
			damage = rand() % 60 + 20;
			cout << "you used your shiv on the monter" << endl;
		}
		else {
			damage = rand() % 50 + 10;
			cout << "you kicked the bug away" << endl;
		}
	
		
		cout << "you hit the monster for " << damage << " damage" << endl;
		monsterhealth -= damage;
		cout << "the spider has " << monsterhealth << " health left" << endl;
	}
	if (monsterhealth <= 0) {
		cout << "you have defeted the monster" << endl;
	}
}

//funtion defenitions go here
void shop() {
	string input;
	do {
		cout << "Hello... welcome to my shop" << endl;
		cout << "you have " << money << " coins." << endl;
		cout << "press 'f' for flashlight $3, 'b' for bandaid $1, and 's' for shank $5." << endl;
		cout << "press 'q' to quit." << endl;
		cin >> input;
		if (input == "p") {
			if (money >= 3) {
				items[1] = "flashlight";
				cout << "you got a flashlight" << endl;
				money -= 3;
			}

		}
		else if (input == "b") {
			if (money >= 1) {
				items[2] = "bandaid";
				cout << "you got a bandaid" << endl;
				money -= 1;
			}
			else if (input == "s") {
				if (money >= 3) {
					items[3] = "shank";
					cout << "you got a shank" << endl;
					money -= 5;
				}

			}
		} 

	} while (input != "q");
}
