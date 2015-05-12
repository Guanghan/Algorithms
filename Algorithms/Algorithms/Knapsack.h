/* This Knapsack problem is an optimization problem from Linear Programming */
class Knapsack
{
public:
	static const int weight[5];
	static const int value[5];

	Knapsack();
	Knapsack(int maxWeight);
	int operator()(int maxWeight);
	void dispSolution();  
	int getMaxValue(int kth, int maxWeight);  //The maximum value the knapsack could convey, if we only put the 1st to kth items in it.
	int getMaxIndex(int kth, int maxWeight);  //The maximum index of the item used in the knapsack.

private:
	int Index[5];
	const int itemNum = 5;
	int solved = 0;
	int maxWeight;
};