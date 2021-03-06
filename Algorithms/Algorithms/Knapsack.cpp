/* This Knapsack problem is an optimization problem from Linear Programming */
#include "Knapsack.h"
#include <math.h>
#include <algorithm>
#include <iostream>

//The arrays of weights and values
const int Knapsack::weight[5] = { 12, 2, 1, 1, 4 };
const int Knapsack::value[5] = { 4, 2, 2, 1, 10 };


//Display the results
void Knapsack::dispSolution()
{
	if (solved == 1)
	{
		getMaxIndex(itemNum, maxWeight);
	}
	else
	{
		std::cout << "Please Solve the Problem first!\n";
		for (int i = 1; i <= itemNum; i++)
		{
			getMaxIndex(i, maxWeight);
		}
	}
}

//Constructor
Knapsack::Knapsack(){}

//Overload Constructor
Knapsack::Knapsack(int maxWeight)
{
	this->maxWeight = maxWeight;
}

//The default call returns the solution
int Knapsack::operator()(int maxWeight)
{
	this->maxWeight = maxWeight;
	std::cout << "item number is:" << itemNum << std::endl;

	return getMaxValue(itemNum, maxWeight);
}

//The maximum value the knapsack could convey, if we only put the 1st to kth items in it.
int Knapsack::getMaxValue(int kth, int maxWeight)
{
	//std::cout << "(kth, maxWeight) = (" << kth << ", " << maxWeight << ")" << std::endl;

	if (kth == 0) return 0;
	if (maxWeight == 0) return 0;

	if (kth == 1)
	{
		//std::cout << "kth = 1      " << (float)maxWeight<<"  " << (float)weight[0] << " "<< value[0]<<" "<< floor((float)maxWeight / (float)weight[0])*value[0] << "\n";
		return floor((float)maxWeight/(float)weight[0])*value[0];
	}

	if (maxWeight - weight[kth - 1] < 0)  //This was ignored and was the bug
	{
		return getMaxValue(kth - 1, maxWeight);
	}
	else
	{
		return std::max(getMaxValue(kth -1, maxWeight), getMaxValue(kth, maxWeight - weight[kth - 1]) + value[kth-1]);  //Another bug here: need to add " + value[kth-1]"
	}
}

//The maximum index of the item used in the knapsack.
int Knapsack::getMaxIndex(int kth, int maxWeight)
{
	if (maxWeight - weight[kth - 1] < 0)  //This was ignored and was the bug
	{
		std::cout << kth << "th maxIndex: " << kth-1 << std::endl;
		return getMaxIndex(kth-1, maxWeight);
	}
	else if (getMaxValue(kth - 1, maxWeight) > getMaxValue(kth, maxWeight - weight[kth - 1]) + value[kth -1] ) //Another bug here: need to add " + value[kth-1]"
	{
		int temp= getMaxIndex(kth - 1, maxWeight);
		std::cout << kth << "th maxIndex: " << temp << std::endl;

		return temp;
	}
	else
	{
		std::cout << kth << "th maxIndex: " << kth << std::endl;
		return kth;
	}
}
