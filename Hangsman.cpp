#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// FUNCTION INITIALIZE LIST OF WORDS
void initialize_list(vector <string> &lst)
{
	fstream ifile;
	ifile.open("Lists/countries.txt", ios::in);
	if(! ifile)
	{
		cerr << "An error has been encountered";
		exit(0);
	}
	else
	{
		string word;
		while(!ifile.eof())
		{
			getline(ifile, word);
			lst.push_back(word);
		}

	}
	ifile.close();
}

// FUNCTION TO GET A RANDOM WORD OUT OF LIST

string get_word(vector <string> &lst, int random)
{
	return lst.at(random);
}

// LIVES SELECTOR
void lives_selector(unsigned short int &lives)
{
	bool check = true;
	cout << "How many lives (Chances) you want to Play with?" << endl;
	while(check == true)
	{
		cout << "Life Should be selected in Range (1-10)" << endl;
		cin >> lives;
		if(lives <= 10 && lives > 0)
		{
			check = false;
		}
	}
}

// GUESS MESSAGE
void guess_msg()
{
	srand(time(0));
	unsigned short int r = rand()% 5;
	if (r == 0 )
	{
		cout << "Guess a Character." << endl << endl;
	}
	else if (r == 1 )
	{
		cout << "Make a wild Guess" << endl<< endl;
	}
	else if (r == 2 )
	{
		cout << "Let See can you guess the right character" << endl<< endl;
	}
	else if (r == 3 )
	{
		cout << "Try a Character My Friend" << endl<< endl;
	}
	else
	{
		cout << "Can you Guess it?" << endl<< endl;
	}	
}

// SUCCESS MESSAGE
void success_msg()
{
	srand(time(0));
	unsigned short int r = rand()% 5;
	if (r == 0 )
	{
		cout << "Thats Correct, MR Perfect" << endl<< endl;
	}
	else if (r == 1 )
	{
		cout << "I know you are a Saviour" << endl<< endl;
	}
	else if (r == 2 )
	{
		cout << "I knew I can count on it" << endl<< endl;
	}
	else if (r == 3 )
	{
		cout << "You are one step closer to save me" << endl<< endl;
	}
	else
	{
		cout << "Thats right, You are Master" << endl<< endl;
	}	
}

// Failure MESSAGE
void failure_msg()
{
	srand(time(0));
	unsigned short int r = rand()% 5;
	if (r == 0 )
	{
		cout << "Oh No I am Doomed" << endl<< endl;
	}
	else if (r == 1 )
	{
		cout << "You are a Muderer" << endl<< endl;
	}
	else if (r == 2 )
	{
		cout << "You are a Killer" << endl<< endl;
	}
	else if (r == 3 )
	{
		cout << "Wrong Answer Mr" << endl<< endl;
	}
	else
	{
		cout << "I knew you will get me into trouble" << endl<< endl;
	}	
}


// HANGSMAN MAIN
void HangsMan(string & rand_word, unsigned short int& life)
{
	unsigned short int size = rand_word.length();		//STORING SIZE
	char correct_word[size];							//CREATING A HIDDEN WORD
	
	for(int i = 0; i < size; i++)
	{
		correct_word[i] = '_';
	}
	
	// LOOP TO HANDLE SPACES
	for(int i = 0 ; i < rand_word.length(); i++)
	{
		if(rand_word[i] == ' ' )
		{
			correct_word[i] = rand_word[i];
			size = size - 1;
		}
	}
////////////////////////////////////////////////////////////////
	cout <<"The total lenght of Word is :" <<size << endl;
	for(int i = 0; i < size; i++)
	{
		cout <<correct_word[i] << " ";
	}
	cout << endl<<"--------------------------------------------------------------------------" << endl << endl;
////////////////////////////////////////////////////////////////////
char character;
bool check_life;
bool victory = false;
vector <char> tried;
unsigned short int correct_no = 0;
	// MAIN LOOP
	while(life != 0 && correct_no != rand_word.length())
	{
		check_life = false;
		victory = false;
		guess_msg();								//PRINTING GUESS MESSAGE
		cin >> character;
		character = tolower(character);
		tried.push_back(character);
		
		// LOOP FOR REPLACING CORRECT CHARACTERS IN HIDDEN WORD
		for(int i = 0; i < size; i++)
		{
			if(character == rand_word[i])
			{
				if(correct_word[i] != character)
				{
					correct_no ++;
					victory = true;
				}
				correct_word[i] = character;
				check_life = true;
				
			}
		}
		cout << endl << "--------------------------------------------------------------------------" << endl;

		if(check_life == true)
		{
			success_msg();
		}
		if(check_life == false)
		{
			life --;
			failure_msg();
		}
		for(int i = 0; i < size; i++)
		{
			cout << correct_word[i] << " ";
		}
		cout << endl << endl;
		cout << "Correct Alphabets: " << correct_no << endl; 
		cout <<"Remaining Life: " << life << endl;
		cout << "Tried Aplhabets: ";
		for(int i = 0; i < tried.size(); i++)
		{

			cout <<tried.at(i) << " ";
		}
		cout << endl << endl << endl;
		cout << "--------------------------------------------------------------------------" << endl << endl;	
	}
	
	if (victory == false)
	{
		cout << "You Lose" << endl;
	}
	else
	{
		cout << "You Win" << endl;
	}
	cout << "Country Name: " << rand_word << endl;
}



int main()
{
	cout << "----------------------------(HANGSMAN GAME)------------------------------" << endl << endl;
	
	vector <string> lst;
	initialize_list(lst);								//INITIALIZE LIST
	
	srand(time(0));
	unsigned short int random = rand()% lst.size();		//GETTING RANDOM NUMBER
	
	string rand_word = get_word(lst, random);			//GETTING RANDOM WORD
	
	unsigned short int life;							// DECLARING LIFE
	lives_selector(life);								// SETTING LIFE
	cout << endl <<"--------------------------------------------------------------------------" << endl << endl; 
	HangsMan(rand_word, life);
	cout << "--------------------------------------------------------------------------" << endl;
	return 0;
}
