#include"maze.h"

// Edit the code here to change maze file.
#define MAZE_FILE "mazeWithCycle.txt"

bool solver(Maze M, char trackmaze[100][100], int x, int y);

int main(){
	Maze M;
	
	M.ReadMaze(MAZE_FILE);
	
	cout<<"This is the maze."<<endl;
	cout << M;
	char trackmaze[100][100];
	M.getStart();
	int x, y;
	M.getCurrentLocation(x,y);
	cout<<"Get started! Now you are @ ("<<x<<","<<y<<")"<<endl;
	//the correct path will be shown by the coordinates of 'O' in trackmaze
	trackmaze[y][x] = 'O';
	cout << M;

	solver(M, trackmaze, x, y);
	return 0;
}

bool solver(Maze M, char trackmaze[100][100], int x, int y)
{
	if (M.isFinish())
	{
		cout << "Congrats - Desination reached!" << endl;
		return true;
	}
	M.getCurrentLocation(x, y);
	//north
	if (trackmaze[y - 1][x] != 'O' && trackmaze[y - 1][x] != 'B')
	{
		trackmaze[y][x] = 'O';
		if (M.north())
		{
			M.getCurrentLocation(x, y);
			
			cout << "March north! Now you are @ (" << x << "," << y << ")" << endl;
			cout << M;
			return solver(M, trackmaze, x, y);
		}
	}
	//east
	if (trackmaze[y][x + 1] != 'O' && trackmaze[y][x + 1] != 'B')
	{
		trackmaze[y][x] = 'O';
		if (M.east())
		{
			M.getCurrentLocation(x, y);

			cout << "March east! Now you are @ (" << x << "," << y << ")" << endl;
			cout << M;
			return solver(M, trackmaze, x, y);
		}
	}
	//west
	if (trackmaze[y][x - 1] != 'O' && trackmaze[y][x - 1] != 'B')
	{
		trackmaze[y][x] = 'O';
		if (M.west())
		{
			M.getCurrentLocation(x, y);

			cout << "March west! Now you are @ (" << x << "," << y << ")" << endl;
			cout << M;
			return solver(M, trackmaze, x, y);
		}
	}
	//south
	if (trackmaze[y + 1][x] != 'O' && trackmaze[y + 1][x] != 'B')
	{
		trackmaze[y][x] = 'O';
		if (M.south())
		{
			M.getCurrentLocation(x, y);

			cout << "March south! Now you are @ (" << x << "," << y << ")" << endl;
			cout << M;
			return solver(M, trackmaze, x, y);
		}
	}

	//backtrack 
	trackmaze[y][x] = 'B';
	if (trackmaze[y - 1][x] == 'O')
	{
		trackmaze[y][x] = 'B';
		if (M.north())
		{
			M.getCurrentLocation(x, y);
			
			cout << "March back north! Now you are @ (" << x << "," << y << ")" << endl;
			cout << M;
			return solver(M, trackmaze, x, y);
		}
	}

	if (trackmaze[y][x + 1] == 'O')
	{
		trackmaze[y][x] = 'B';
		if (M.east())
		{
			M.getCurrentLocation(x, y);

			cout << "March back east! Now you are @ (" << x << "," << y << ")" << endl;
			cout << M;
			return solver(M, trackmaze, x, y);
		}
	}

	if (trackmaze[y][x - 1] == 'O')
	{
		trackmaze[y][x] = 'B';
		if (M.west())
		{
			M.getCurrentLocation(x, y);
			cout << "March back west! Now you are @ (" << x << "," << y << ")" << endl;
			cout << M;
			return solver(M, trackmaze, x, y);
		}
	}

	if (trackmaze[y + 1][x] == 'O')
	{
		trackmaze[y][x] = 'B';
		if (M.south())
		{
			M.getCurrentLocation(x, y);

			cout << "March back south! Now you are @ (" << x << "," << y << ")" << endl;
			cout << M;
			return solver(M, trackmaze, x, y);
		}
	}
}
