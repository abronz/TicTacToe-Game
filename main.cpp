#include <iostream>
#include <gl/glut.h>
#include <math.h>

using namespace std;

char matrix[3][3] =	{	'1', '2',  '3',
						'4', '5',  '6',
						'7', '8',  '9'	};

char currentPlayer = 'X';		// X is player 1, O is player  2
int currentTurn = 1;
char result = 'N';

void clsBoard() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int input() {
	int input;
	cout << "Enter a number Player " << currentPlayer << "(1-9) >> ";
	cin >> input;

	if (input == 1) {
		if (matrix[0][0] == '1') {
			matrix[0][0] = currentPlayer;
			currentTurn++;
		}
		else {
			cout << "Input cannot be inserted into populated field." << endl;
			return -1;
		}
		return 0;
	}
	else if (input == 2) {
		if (matrix[0][1] == '2') {
			matrix[0][1] = currentPlayer;
			currentTurn++;
		}
		else {
			cout << "Input cannot be inserted into populated field." << endl;
			return -1;
		}
		return 0;
	}
	else if (input == 3) {
		if (matrix[0][2] == '3') {
			matrix[0][2] = currentPlayer;
			currentTurn++;
		}
		else {
			cout << "Input cannot be inserted into populated field." << endl;
			return -1;
		}
		return 0;
	}
	else if (input == 4) {
		if (matrix[1][0] == '4') {
			matrix[1][0] = currentPlayer;
			currentTurn++;
		}
		else {
			cout << "Input cannot be inserted into populated field." << endl;
			return -1;
		}
		return 0;
	}
	else if (input == 5) {
		if (matrix[1][1] == '5') {
			matrix[1][1] = currentPlayer;
			currentTurn++;
		}
		else {
			cout << "Input cannot be inserted into populated field." << endl;
			return -1;
		}
		return 0;
	}
	else if (input == 6) {
		if (matrix[1][2] == '6') {
			matrix[1][2] = currentPlayer;
			currentTurn++;
		}
		else {
			cout << "Input cannot be inserted into populated field." << endl;
			return -1;
		}
		return 0;
	}
	else if (input == 7) {
		if (matrix[2][0] == '7') {
			matrix[2][0] = currentPlayer;
			currentTurn++;
		}
		else {
			cout << "Input cannot be inserted into populated field." << endl;
			return -1;
		}
		return 0;
	}
	else if (input ==  8) {
		if (matrix[2][1] == '8') {
			matrix[2][1] = currentPlayer;
			currentTurn++;
		}
		else {
			cout << "Input cannot be inserted into populated field." << endl;
			return -1;
		}
		return 0;
	}
	else if (input == 9) {
		if (matrix[2][2] == '9') {
			matrix[2][2] = currentPlayer;
			currentTurn++;
		}
		else {
			cout << "Input cannot be inserted into populated field." << endl;
			return -1;
		}
		return 0;
	}
}

void togglePlayer() {
	if (currentPlayer == 'X')
		currentPlayer = 'O';
	else
		currentPlayer = 'X';
}

char checkBoard(char player) {		// checks every turn if a player won until one wins or ties - returns winning player

	// Check horizontally
	if (matrix[0][0] == player && matrix[0][1] == player && matrix[0][2] == player)	
		return player;
	if (matrix[1][0] == player && matrix[1][1] == player && matrix[1][2] == player)
		return player;
	if (matrix[2][0] == player && matrix[2][1] == player && matrix[2][2] == player)
		return player;

	// Check vertically
	if (matrix[0][0] == player && matrix[1][0] == player && matrix[2][0] == player)
		return player;
	if (matrix[0][1] == player && matrix[1][1] == player && matrix[2][1] == player)
		return player;
	if (matrix[0][2] == player && matrix[1][2] == player && matrix[2][2] == player)
		return player;

	// Check diagonally
	if (matrix[0][0] == player && matrix[1][1] == player && matrix[2][2] == player)
		return player;
	if (matrix[0][2] == player && matrix[1][1] == player && matrix[2][0] == player)
		return player;

	return 'N';
}

// Rendering
void drawGrid() {
	glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    //2 vertical lines
    glVertex2f(100, 50);
    glVertex2f(100, 340);
    glVertex2f(200, 340);
    glVertex2f(200, 50);
    //2 horizontal lines
    glVertex2f(0, 150);
    glVertex2f(300, 150);
    glVertex2f(0, 250);
    glVertex2f(300, 250);
	glEnd();
}

void drawXO() {
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (matrix[i][j] == 'X') 
			{
				glBegin(GL_LINES);
				glVertex2f(50 + j * 100 - 25, 100 + i * 100 - 25);
				glVertex2f(50 + j * 100 + 25, 100 + i * 100 + 25);
				glVertex2f(50 + j * 100 - 25, 100 + i * 100 + 25);
				glVertex2f(50 + j * 100 + 25, 100 + i * 100 - 25);
				glEnd();
			}
			else if (matrix[i][j] == 'O') 
			{
				glBegin(GL_LINE_LOOP);
				glVertex2f(50 + j * 100 - 25, 100 + i * 100 - 25);
				glVertex2f(50 + j * 100 - 25, 100 + i * 100 + 25);
				glVertex2f(50 + j * 100 + 25, 100 + i * 100 + 25);
				glVertex2f(50 + j * 100 + 25, 100 + i * 100 - 25);
				glEnd();
			}
		}
	}
}

void reshape(int x, int y)
{
	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, x, y, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
	glColor3f(1, 1, 1);
	drawGrid();
	drawXO();

	glutPostRedisplay();
	glutSwapBuffers();

	// Game Logic
	clsBoard();
	if (input() != -1) {
		system("CLS");
		char turnResult = checkBoard(currentPlayer);
		cout << "Turn: " << currentTurn << endl;
		if (turnResult == currentPlayer) {
			cout << endl << currentPlayer << " has won the game." << endl;
			result = currentPlayer;
		}
		else if (turnResult == 'N' && currentTurn == 10) {
			cout << endl << "The game ends in a tie." << endl;
			result = 'T';
		}
		togglePlayer();
	}
}

void main(int argc, char** argv) {
	// Render
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(720, 480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("TicTacToe");
	glutReshapeFunc(reshape);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(display);
	glutMainLoop();
}