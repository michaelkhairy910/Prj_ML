// BlackJack1_ML.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main() {
	srand(time(0));
	int PlayerCardSum = 0;
	bool Playagain = true;
	int decision = 0;
	while (true) {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Black Jack Game" << endl;
		int Card1Dealer = 1 + rand() % 10;
		int Card2Dealer = 1 + rand() % 10;
		int PlayersCardGiven = Card1Dealer + Card2Dealer;
		int Card3Dealer = 1 + rand() % 10;
		int Card4Dealer = 1 + rand() % 10;
		int DealersCardGiven = Card3Dealer + Card4Dealer;
		bool PlayerBust = false;
		bool DealerBust = false;
		cout << "Player's Card Given: " << PlayersCardGiven << endl;
		cout << "Dealer's Card Given (One card shown only): " << Card3Dealer << " ,And two/ total Face Value Card : " << DealersCardGiven << endl;
		cout << " Press (1) to hit or Press (2) to stand: " << endl;
		int choices;
		cin >> choices;
		// Player's Loop
		if (choices == 1) { // Players cards
			while (true) {
				int CardHitPlayer = 1 + rand() % 10;
				PlayersCardGiven += CardHitPlayer;
				cout << "Player's Card Total: " << PlayersCardGiven << endl;
				if (PlayersCardGiven > 21) {
					PlayerBust = true;
					cout << "Player Busted!" << endl;
					break;
				}
				cout << " Press (1) to hit or Press (2) to stand: " << endl;
				int choices;
				cin >> choices;
				if (choices == 2) {
					cout << "Player Stands with a Value of: " << PlayersCardGiven <<
						endl;
					break;
				}
			}
		}
		//Dealer's Loop
		if (!PlayerBust) {
			for (int i = 0; DealersCardGiven <= 16; i++) {
				int CardHitDealer = 1 + rand() % 10;
				DealersCardGiven += CardHitDealer;
				cout << "sum count: " << i << endl;
				if (DealersCardGiven <= 16) {
					cout << "Dealer hit, dealer has a value of: " << DealersCardGiven
						<< endl;
					if (DealersCardGiven > 21) {
						DealerBust = true;
					}
				}
				else if (DealersCardGiven >= 17) {
					cout << "Dealer Stand, dealer has a value of: " <<
						DealersCardGiven << endl;
					if (DealersCardGiven > 21) {
						DealerBust = true;
					}
				}
				else if (DealersCardGiven > 21) {
					DealerBust = true;
				}
			}
		}
		//Winner determination 
		if (PlayerBust == true) {
			cout << "Player Lost..." << endl;
			cout << "Player lost, with a value of: " << PlayersCardGiven << endl;
			cout << "Dealer's Value: " << DealersCardGiven << endl;
		}
		else if (DealerBust == true) {
			cout << "Dealer Lost..." << endl;
			cout << "Dealer lost, with a value of: " << DealersCardGiven << endl;
			cout << "Player Value: " << PlayersCardGiven << endl;
		}
		if (DealerBust == false && PlayerBust == false) {
			if (DealersCardGiven > PlayersCardGiven) {
				cout << "Dealer wins, with a value of: " << DealersCardGiven << endl;
				cout << "Player Value: " << PlayersCardGiven << endl;
			}
			else if (DealersCardGiven < PlayersCardGiven) {
				cout << "Player wins, with a value of: " << PlayersCardGiven << endl;
				cout << "Dealer's Value: " << DealersCardGiven << endl;
			}
			else if (DealersCardGiven == PlayersCardGiven) {
				cout << "Draw..." << endl;
				cout << "Player Value: " << PlayersCardGiven << endl;
				cout << "Dealer's Value: " << DealersCardGiven << endl;
			}
		}
	}
	return 0;
}