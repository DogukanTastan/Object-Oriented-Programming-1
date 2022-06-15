// Dogukan TASTAN 1901042627
#include <iostream>
#include <cstdlib>  // Libraries required for random operations
#include <time.h>
using namespace std;

string number_maker(int digit){  // This function generates a random number according to the desired number of digits and returns it as a string.
	
	char secret_number[digit];
	string number;
	
	secret_number[0]=rand() % 9 + 49; // Since the first digit will not be 0, the operation is performed separately.
	
	for(int i=1;i<digit;i++){							
		secret_number[i]=rand() % 10 + 48;  // other steps are selected.

		for(int j=0;j<i;j++){
			if(secret_number[j]==secret_number[i]){  // if it is the same, exit here and the process is done again
				i--;
				break;
			}
		}  
	}
	

	number=secret_number;
	return number;  // When the number generation is complete, the number is returned as a string.
}

int game_play(string secret_number,int digit,int& testing){  // this funtion plays the game

	int counter1,counter2; // counters
	string user_guess;
	int counter3;		// compare counter

	while(true){
		counter1=0,counter2=0;
		cin>>user_guess;		// user input
		testing++;			// total test counter
		
		if(testing>100){
			return 0;   //If the user cannot find in 100 iterations, print the following message and exit the program:
		}
		
		counter3=0;
		for(int i=0;i<digit;i++){
			if(user_guess[i]==secret_number[i])
				counter3++;
		}

		if(counter3==digit && user_guess.size()==digit)  // 3 is returned when there is a match
			return 3;

		if(user_guess.size()!=digit)  // size check in progress
			return 1;

		if(user_guess[0]=='0')  // If the first value entered by the user is 0, an error is thrown.
				return 1;

		for(int i=0;i<digit;i++){
			if(user_guess[i]<48 || user_guess[i]>57){  // Checks whether characters are int or not based on ascii values
				return 2;
			}
		}

		for(int i=0;i<user_guess.size();i++){
			if(user_guess[i]==secret_number[i])  //match in place
				counter1++;
			else{
				for(int j=0;j<digit;j++){
					if(user_guess[i]==secret_number[j])  // out of place matches
						counter2++;
				}
			}
		}
		cout<<counter1<<" "<<counter2<<endl;  // print the counters
	}
}

int main(int argc, char *argv[]){
	
	srand(time(NULL));

	int n_digit=0;   // hold digit number
	int copy_number;  // variable created so that the original number is not affected
	string secret_number;   // secret number
	int result,testing=0;   // control variables
	string argv1,argv2;		// String variables created for more comfortable operations on char**
	if(argv[1]!=NULL)
		argv1=argv[1];		// If the program is started incorrectly, I check to avoid Segmentation faults.
	if(argv[2]!=NULL)
		argv2=argv[2];

	if(argv1=="-r"){  // console argument control
	

		if(argv[2][0]<49 || argv[2][0]>57){  // Checking for int over ascii value

			cout<<"E0\n";
			return 0;
		}
		
		n_digit=argv2[0]-48;  // Converting the number entered after -r to an int value

		secret_number=number_maker(n_digit);

		result=game_play(secret_number,n_digit,testing);
		if(result==1){
			cout<<"E1";  // Entering missing digits
			return 0;
		}
		else if(result==2){
			cout<<"E2";
			return 0;  // not integer
		}
		else if(result==3){
			cout<<"FOUND "<< testing<<endl;
			return 0;  
		}
		else if(result==0){
			cout<<"FAILED";
			return 0;  
		}
	}
	else if(argv1=="-u"){

		argv2=argv[2];
		n_digit=argv2.size(); // Finding the size of the number entered with the string size function
		
		for(int i=0;i<n_digit;i++){
			for(int j=i+1;j<n_digit;j++){
				
				if(argv[2][i]==argv[2][j]){  
					cout<<"E0";
					return 0;
				}
			}
		}

		if(argv[2][0]<49 || argv[2][0]>57){  //Since the first digit cannot be 0, it is analyzed separately.
				cout<<"E0"; 
				return 0;
			}
		for(int i=1;i<n_digit;i++){
			if(argv[2][i]<48 || argv[2][i]>57){
				cout<<"E0";
				return 0;
			}
		}

		result=game_play(argv2,n_digit,testing);

		if(result==1){
			cout<<"E1";  // Entering missing digits
			return 0;
		}
		else if(result==2){
			cout<<"E2";
			return 0;  // not integer
		}
		else if(result==3){
			cout<<"FOUND "<< testing<<endl;
			return 0;  
		}
		else if(result==0){
			cout<<"FAILED";
			return 0;  
		}
	}
	else{
		cout<<"E0"; // consol errors
	}
}