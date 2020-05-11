#include <cstdlib>
#include <iostream> 
using namespace std; 

//Reference: https://www.geeksforgeeks.org/place-k-knights-such-that-they-do-not-attack-each-other/

int m, n, k; 
int countl = 0; 
//creating empty bord
void makeBoard(char** board) 
{ 
	for (int i = 0; i < m; i++) { 
		for (int j = 0; j < n; j++) { 
			board[i][j] = '_'; 
		} 
	} 
} 

//showing the board
void displayBoard(char** board) 
{ 
	cout << endl 
		<< endl; 
	for (int i = 0; i < m; i++) { 
		for (int j = 0; j < n; j++) { 
			cout << " " << board[i][j] << " "; 
		} 
		cout << endl; 
	} 
} 

//marks all the attacking position at that position
void attack(int i, int j, char a, 
			char** board) 
{ 
	if ((i + 2) < m && (j - 1) >= 0) { 
		board[i + 2][j - 1] = a; 
	} 
	if ((i - 2) >= 0 && (j - 1) >= 0) { 
		board[i - 2][j - 1] = a; 
	} 
	if ((i + 2) < m && (j + 1) < n) { 
		board[i + 2][j + 1] = a; 
	} 
	if ((i - 2) >= 0 && (j + 1) < n) { 
		board[i - 2][j + 1] = a; 
	} 
	if ((i + 1) < m && (j + 2) < n) { 
		board[i + 1][j + 2] = a; 
	} 
	if ((i - 1) >= 0 && (j + 2) < n) { 
		board[i - 1][j + 2] = a; 
	} 
	if ((i + 1) < m && (j - 2) >= 0) { 
		board[i + 1][j - 2] = a; 
	} 
	if ((i - 1) >= 0 && (j - 2) >= 0) { 
		board[i - 1][j - 2] = a; 
	} 
} 

// If the position is empty, place the knight 
bool canPlace(int i, int j, char** board) 
{ 
	if (board[i][j] == '_') 
		return true; 
	else
		return false; 
} 

// Place the knight at [i][j] position on board 
void place(int i, int j, char k, char a, 
		char** board, char** new_board) 
{ 

	// Copy the configurations of old board to new board 
	for (int y = 0; y < m; y++) { 
		for (int z = 0; z < n; z++) { 
			new_board[y][z] = board[y][z]; 
		} 

	new_board[i][j] = k; 

	attack(i, j, a, new_board); 
} 

// Function for placing knights on board such that they don't attack each other 
void kkn(int k, int sti, int stj, char** board) 
{ 

	/* If there are no knights left to be placed, 
	display the board and increment the count */
	if (k == 0) { 
		displayBoard(board); 
		countl++; 
	} 
	else { 
		for (int i = sti; i < m; i++) { 
			for (int j = stj; j < n; j++) { 

				// Is it possible to place knight at [i][j] position on board? 
				if (canPlace(i, j, board)) { 

					/* Create a a new board and place the 
					new knight on it */
					char** new_board = new char*[m]; 
					for (int x = 0; x < m; x++) { 
						new_board[x] = new char[m]; 
					} 
					place(i, j, 'K', '-', board, new_board); 

					kkn(k - 1, i, j, new_board); 

					//free memory
					for (int x = 0; x < m; x++) { 
						delete[] new_board[x]; 
					} 
					delete[] new_board; 
				} 
			} 
			stj = 0; 
		} 
	} 
} 


int main() 
{ 
    cout<<"Enter the size of the matrix"<<endl;
    cin>>m;
    n=m;
    k=n;
	//create board
	char** board = new char*[m]; 
	for (int i = 0; i < m; i++) { 
		board[i] = new char[n]; 
	} 
	//initialiazation
	makeBoard(board); 
	kkn(k, 0, 0, board); 
	cout<< "Total number of solutions : "<< countl; 
	return 0; 
} 
