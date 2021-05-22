#include <iostream>
using namespace std;
int place[8][8];

void insert(int i, int j)
{
	for (int l = 0; l < 8; l++)
	{
		place[l][j]++;
		place[i][l]++;
		int d;
		d = j - i + l;
		if (d >= 0 && d < 8)
			place[l][d]++;
		d = j + i - l;
		if (d >= 0 && d < 8)
			place[l][d]++;
		place[i][j] = -1;
	}
}


void zeroing(int i, int j)
{
	for (int l = 0; l < 8; l++)
	{
		place[l][j]--;  
		place[i][l]--; 
		int d; 
		d = j - i + l;
		if (d >= 0 && d < 8)
			place[l][d]--;
		d = j + i - l;
		if (d >= 0 && d < 8)
			place[l][d]--;
		place[i][j] = 0; 
	}
}

int queen(int i)
{
	int key = 0;
	for (int j = 0; j < 8; j++)
	{
		if (place[i][j] == 0)
		{
			insert(i, j);

			if (i == 7)
				key = 1;
			else 
				if (!(key = queen(i + 1))) 
					zeroing(i, j);
		}
		if (key) break;
	}
	return key;
}

int main()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			place[i][j] = 0;
		}
	}
	queen(0); 
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (place[i][j] == -1) 
				cout << "F"; 
			else 
				cout << "."; 
		}
		cout << endl;
	}
	return 0;
}
