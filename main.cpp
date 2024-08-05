#include<time.h>
#include<iostream>
#include<conio.h>
#include"help.h"
using namespace std;

void draw(float x, float y, float r)
{
	for (int k = 0; k < 20; k++)
	{
		myEllipse((x - r), (y - r), (x + r), (y + r), 255, 250, 67);
		Sleep(70);
	}
}

bool intersects(int x, int y, int r, int x1, int y1, int r1)
{
	float distance = 0, rad = 0;
	distance = sqrt(((x1 - x) * (x1 - x)) + ((y1 - y) * (y1 - y)));
	rad = r + r1;

	if (distance <= rad)
		return true;
	else
		return false;
}


void mostIntersecting(float X[], float Y[], float R[], int n)
{
	int x1 = 0, y1 = 0, r1 = 0;
	int  max_index = 0, max = 0;
	bool res = 0;


	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			res = intersects(X[i], Y[i], R[i], X[j], Y[j], R[j]);
			if (res == 1)
				count++;
		}
		if (max < count)
		{
			max = count;
			max_index = i;
		}
	}
	cout << "The center of the cirle which intersects the most is:  (" << X[max_index] << "," << Y[max_index] << ")" << endl;
	cout << "It's radius is: " << R[max_index];
	for (int t = 0; t < 20; t++)
	{
		x1 = X[t];
		y1 = Y[t];
		r1 = R[t];
		draw(x1, y1, r1);
	}
	myEllipse((X[max_index] - R[max_index]), (Y[max_index] - R[max_index]), (X[max_index] + R[max_index]), (Y[max_index] + R[max_index]), 210, 100, 150);
	Sleep(12000);
}




int main()
{
	float  X[20] = { 590,590,768,670,976,320,378,800,890,190,300,400,800,949,700,455,260,290,400,700 };
	float  Y[20] = { 140, 170, 170, 220, 290, 224, 244,200,297,130,259,309,350,230,530,234,450,500,500,267 };
	float  R[20] = { 50,30,40,70,50,60,60,50,80,45,55,45,70,59,70,58,60,39,70,30 };
	int n = 20;

	mostIntersecting(X, Y, R, n);

	system("pause");
	return 0;
}