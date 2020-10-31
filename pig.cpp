#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int simulateSingleTurn(int score);

int main(){

	//seed the random number generator
	srand((unsigned int)time(NULL));

	long int N, score, repetition;

	cout << "Enter value to hold at: ";

	cin >> N;

	cout << "Enter N-turn simulation: ";

	cin >> repetition;

	long int frequency[9];

	for(int i = 0; i < 9; i++){

		frequency[i] = 0;
	}
	for(long int i = 0; i < repetition; i++){

		score = simulateSingleTurn(N);

		if(score == 0){
			frequency[0]++;
		}else if(score == N){
			frequency[1]++;
		}else if(score == (N + 1)){
			frequency[2]++;
		}else if(score == (N + 2)){
			frequency[3]++;
		}else if(score == (N + 3)){
			frequency[4]++;
		}else if(score == (N + 4)){
			frequency[5]++;
		}else if(score == (N + 5)){
			frequency[6]++;
		}else if(score == (N + 6)){
			frequency[7]++;
		}else if(score == (N + 7)){
			frequency[8]++;
		}
	}
	double totalprint = 0;
	cout << "n " << left << setw(10) << "Score" << left << "Estimated Probability" << endl;

	cout << " " << left << setw(10) << "0" << left <<fixed << setprecision(5) << ((double) frequency[0]) / repetition << endl;
	totalprint += ((double)frequency[0]) / repetition;
	for(int i = 1; i < 9; i++){

		cout << " " << left << setw(10) << (N + i - 1) << left << fixed << setprecision(5) << ((double)frequency[i]) / repetition << endl;
		totalprint += ((double)frequency[i]) / repetition;
	}
	//cout << totalprint << endl;
	return 0;
}
int simulateSingleTurn(int score){

	long int turnScore = 0;
	int die;

	do{

		die = rand() % 8 + 1;

		if(die == 1)
			return 0;
		else
			turnScore += die;
	}while(turnScore < score);

	return turnScore;
}
