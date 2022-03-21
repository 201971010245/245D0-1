#include<iostream>
using namespace std;
int main()
{
	int n, C, i, j;
	cout << "请输入背包容量：";
	cin >> C;
	cout << "请输入物品数：";
	cin >> n;
	int *w = new int[n+1];
	int *v = new int[n+1];
	int *x = new int[n+1];
	int **V = new int*[n+1];//设立动态数组，节省空间
	for (i = 0; i < n + 1; i++)
	{
		V[i] = new int[C + 1];
	}
	cout << "请输入这些物品的重量：";
	w[0] = 0;
	for (i = 1; i < n + 1; i++)//重量和价值都从下标1开始存，这样方便后面计算
		cin >> w[i];
	cout << "请输入这些物品的价值：";
	v[0] = 0;
	for (i = 1; i < n + 1; i++)
		cin >> v[i];
	for (i = 0; i < n + 1; i++)//初始化第0列
		V[i][0] = 0;
	for (j = 0; j < C + 1; j++)//初始化第0行
		V[0][j] = 0;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= C; j++)
		{
			if (j < w[i])
				V[i][j] = V[i - 1][j];
			else
				V[i][j] = V[i - 1][j] > (V[i - 1][j - w[i]] + v[i]) ? V[i - 1][j] : (V[i - 1][j - w[i]] + v[i]);
		}
	for (j = C, i = n; i > 0; i--)
	{
		if (V[i][j] > V[i - 1][j])
		{
			x[i] = 1;
			j = j - w[i];
		}
		else
			x[i] = 0;
	}
	/*控制X的输出格式*/
	cout << "此题最优解为：X={";
	for (i = 1; i < n; i++)
		cout << x[i] << ",";
	cout << x[i] << "}" << endl;
	/*输出表*/
	/*控制表头的输出格式*/
	cout << '\t';
	for (j = 0; j < C+1; j++)
		cout << j << '\t';
	cout << endl;
	/*输出表最左边一列和表的内容*/
	for (i = 0; i < n + 1; i++)
	{
		cout << i << '\t';//输出表最左边
		for (j = 0; j < C + 1; j++)//输出表的内容
			cout << V[i][j] << '\t';
		cout << endl;
	}
	delete[] w;
	delete[] v;
	delete[] x;
	delete[] V;
	return 0;
}
