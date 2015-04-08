#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include "ArrayQueue.h"
using namespace std;

string hotPotatoGame(string names[], int numNames, int iterations);
int main()
{
	string ChildNames[10]{"Tim", "Lisa", "Jack", "Bertha",
		"Adam", "Bert", "Madonna", "Ashley", "Krishna", "Jackson"};
	//Random number generation algorithm
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_int_distribution<int> distribution(0, 100);
	int iterations = distribution(generator);
	cout << "Random number generated: " << iterations << endl;
	string winner = hotPotatoGame(ChildNames, 10, iterations);
	cout << "The winner is: " << winner << endl;
	return 0;
}
string hotPotatoGame(string names[], int numNames, int iterations)
{
	//add names from array into queue data structure
	ArrayQueue gameQueue;

	for (int i = 0; i<numNames; i++){
		ItemType itm;
		itm.string_data = names[i];
		gameQueue.enqueue(itm);
	}
	string eliminated = "";

	while (gameQueue.getSize()>1){

		for (int i = 0; i<iterations; i++){
			gameQueue.enqueue(gameQueue.dequeue());
		}

		ItemType  eliminated = gameQueue.dequeue();

		cout << eliminated.string_data << " is eliminated from the game." << endl;
		cout << "size of queue = " << gameQueue.getSize() << endl;
	}

	return gameQueue.dequeue().string_data;
}
/*Examples of outputs
Random number generated: 86
Madonna is eliminated from the game.
size of queue = 9
Jack is eliminated from the game.
size of queue = 8
Tim is eliminated from the game.
size of queue = 7
Adam is eliminated from the game.
size of queue = 6
Krishna is eliminated from the game.
size of queue = 5
Lisa is eliminated from the game.
size of queue = 4
Ashley is eliminated from the game.
size of queue = 3
Bert is eliminated from the game.
size of queue = 2
Jackson is eliminated from the game.
size of queue = 1
The winner is: Bertha
-----------------------------------
Random number generated: 62
Jack is eliminated from the game.
size of queue = 9
Lisa is eliminated from the game.
size of queue = 8
Jackson is eliminated from the game.
size of queue = 7
Krishna is eliminated from the game.
size of queue = 6
Adam is eliminated from the game.
size of queue = 5
Ashley is eliminated from the game.
size of queue = 4
Bert is eliminated from the game.
size of queue = 3
Bertha is eliminated from the game.
size of queue = 2
Madonna is eliminated from the game.
size of queue = 1
The winner is: Tim
...............................................
Random number generated: 37
Ashley is eliminated from the game.
size of queue = 9
Jackson is eliminated from the game.
size of queue = 8
Bert is eliminated from the game.
size of queue = 7
Tim is eliminated from the game.
size of queue = 6
Jack is eliminated from the game.
size of queue = 5
Madonna is eliminated from the game.
size of queue = 4
Lisa is eliminated from the game.
size of queue = 3
Adam is eliminated from the game.
size of queue = 2
Bertha is eliminated from the game.
size of queue = 1
The winner is: Krishna
.................................................
Random number generated: 29
Jackson is eliminated from the game.
size of queue = 9
Jack is eliminated from the game.
size of queue = 8
Krishna is eliminated from the game.
size of queue = 7
Lisa is eliminated from the game.
size of queue = 6
Tim is eliminated from the game.
size of queue = 5
Ashley is eliminated from the game.
size of queue = 4
Adam is eliminated from the game.
size of queue = 3
Bertha is eliminated from the game.
size of queue = 2
Madonna is eliminated from the game.
size of queue = 1
The winner is: Bert
.......................................................
Random number generated: 84
Adam is eliminated from the game.
size of queue = 9
Krishna is eliminated from the game.
size of queue = 8
Bertha is eliminated from the game.
size of queue = 7
Bert is eliminated from the game.
size of queue = 6
Madonna is eliminated from the game.
size of queue = 5
Jack is eliminated from the game.
size of queue = 4
Ashley is eliminated from the game.
size of queue = 3
Jackson is eliminated from the game.
size of queue = 2
Tim is eliminated from the game.
size of queue = 1
The winner is: Lisa
..............................................
Random number generated: 52
Jack is eliminated from the game.
size of queue = 9
Tim is eliminated from the game.
size of queue = 8
Madonna is eliminated from the game.
size of queue = 7
Lisa is eliminated from the game.
size of queue = 6
Krishna is eliminated from the game.
size of queue = 5
Adam is eliminated from the game.
size of queue = 4
Bert is eliminated from the game.
size of queue = 3
Jackson is eliminated from the game.
size of queue = 2
Bertha is eliminated from the game.
size of queue = 1
The winner is: Ashley
*/
