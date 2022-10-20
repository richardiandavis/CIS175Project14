//Rich Davis
//October 18, 2022
//Project 14

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	srand(time(NULL));

	int correctAnswers = 0;
	int incorrectAnswers = 0;

	map<string, string>statesAndCapitals = { {"Alabama", "Montgomery"},
		{"Alaska", "Juneau"},
		{"Arizona", "Phoenix"},
		{"Nebraska", "Lincoln"},
		{"California", "Sacramento"},
		{"Colorado", "Denver"},
		{"Connecticut", "Hartford"},
		{"Delaware", "Dover"},
		{"Florida", "Tallahassee"},
		{"Georgia", "Atlanta"} };

	vector<string> stateNames{ "Alabama", "Alaska", "Arizona", "Nebraska", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia" };

	cout << "I'm going to ask you for the capitals of 5 states." << endl;

	for (int i = 10; i > 5; i--) {
		string answer;
		int x = rand() % i;
		cout << "What is the capital of " << stateNames[x] << "? ";
		cin >> answer;
		transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
		transform(answer.begin()+1, answer.end(), answer.begin()+1, ::tolower);
		if (answer == statesAndCapitals[stateNames[x]]) {
			cout << "Correct!\n" << endl;
			correctAnswers += 1;
		}
		else {
			cout << "Sorry, that's incorrect. The capital of " << stateNames[x] << " is " << statesAndCapitals[stateNames[x]] << ".\n" << endl;
			incorrectAnswers += 1;
		}
		stateNames.erase(remove(stateNames.begin(), stateNames.end(), stateNames[x]), stateNames.end());
	}

	cout << "End of the quiz." << endl;
	cout << "Correct answers: " << correctAnswers << endl;
	cout << "Incorrect answers: " << incorrectAnswers;

	return 0;
}