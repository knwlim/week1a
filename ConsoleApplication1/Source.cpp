#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <math.h>
#include <cstdlib>

double rand_from_min_to_max(double min, double max)
{
	double temp = (double)rand() / (double)RAND_MAX;

	return min + (max - min)*temp;
}

bool isInsideCircle(const double x, const double y)
{
	const double x_c = 0.2;
	const double y_c = 0.5;
	const double r = 0.2;

	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r * r;

	if (f > 0.0) return false;
	else return true;
}

bool isInsideCircle2(const double x, const double y)
{
	const double x_c = 0.8;
	const double y_c = 0.5;
	const double r = 0.2;

	const double f = (x - x_c)*(x - x_c) + (y - y_c)*(y - y_c) - r * r;

	if (f > 0.0) return false;
	else return true;
}

bool isInsiderec(const double x, const double y)
{
	if (y <0.55 && y>0.45) return true;
}

bool IsInsideEllipse(double XPoint,double YPoint)
{
	double XCenter = 0.5;
	double XRadius = 0.2;
	double YCenter = 0.5;
	double YRadius = 0.4;

	double scaledX = double(XPoint - XCenter) / double(XRadius);
	double scaledY = double(YPoint - YCenter) / double(YRadius);
	return scaledX * scaledX + scaledY * scaledY < 1.0f;
}

void main()
{
	srand((unsigned int)time(NULL));
	std::ofstream circletext("final2.txt");

	for (int i = 0; i < 90000; i++)
	{
		double x = rand_from_min_to_max(0.0, 1.0);
		double y = rand_from_min_to_max(0.0, 1.0);

		if (IsInsideEllipse(x, y) == true )
			circletext << std::fixed << std::setprecision(5)<< x << " " << y << std::endl;
	}
} 