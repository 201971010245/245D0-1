#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define maxn 10000
/*测试用例
8 100
30 40 20 5 15 60 25 10
47 30 9 8 15 66 12 11
*/
/*
5 10
2 2 6 5 4
6 3 5 4 6
*/
typedef struct
{
    int w;//物品重量
    int v;//物品价值
    int x;//物品解向量
    double dw_v;//物品单位价值
} WP;
WP wp[maxn];

int n;//物品数量
int W;//最大容量
int cw,cv;//当前背包重量和价值
int best_v;//最优价值
int best_w;//最优重量
int best_x[maxn];//最优解

int Bound(int i)//上界函数
{
    int cleft=W-cw;//剩余背包容量
    int b=cv;//当前背包价值
    while(i<=n&&wp[i].w<=cleft)
    {
        cleft-=wp[i].w;//以单位重量价值为序递减装入物品
        b+=wp[i].v;
        i++;
    }
    if(i<=n)//能装多少装多少
        b+=wp[i].v*cleft/wp[i].w;
    return b;
}
void Backtrack(int i)//回溯递归
{
    if(i>n)//到达叶子节点记录最优解
    {
        best_v=cv;
        best_w=cw;
        for(int j=1; j<=n; j++)
        {
            best_x[j]=wp[j].x;
        }
        return;
    }
    //output();//记录当前叶子节点的一个解
    else
    {
        if(cw+wp[i].w<=W)//进入左子树，装入该层物品
        {
            cw+=wp[i].w;
            cv+=wp[i].v;
            wp[i].x=1;
            Backtrack(i+1);
            cw-=wp[i].w;//返回上一层
            cv-=wp[i].v;
            wp[i].x=0;//进入右子树
        }
        if(Bound(i+1)>best_v)//满足上界函数则继续递归下一层
        {
            Backtrack(i+1);
        }
    }
}
bool cmp(WP a,WP b)
{
    return a.dw_v>b.dw_v;
}
int main()
{

    cout<<"输入物品数量和背包最大容量："<<endl;
    cin>>n>>W;
    cout<<"输入各物品重量："<<endl;
    for(int i=1; i<=n; i++)
        cin>>wp[i].w;
    cout<<"输入各物品价值："<<endl;
    for(int i=1; i<=n; i++)
        cin>>wp[i].v;
    for(int i=1; i<=n; i++)
    {
        wp[i].dw_v=wp[i].v/wp[i].w;
    }
    sort(wp+1,wp+n+1,cmp);

    cout<<endl<<"当前物品重量及价值："<<endl;

    cout<<"序号：";
    for(int i=1; i<=n; i++)
        printf("%3d ",i);
    cout<<endl;

    cout<<"重量：";
    for(int i=1; i<=n; i++)
        printf("%3d ",wp[i].w);
    cout<<endl;

    cout<<"价值：";
    for(int i=1; i<=n; i++)
        printf("%3d ",wp[i].v);
    cout<<endl;

    Backtrack(1);

    cout<<endl<<"最大价值："<<endl;
    cout<<best_v<<endl;
    cout<<"占用背包大小："<<endl;
    cout<<best_w<<endl;
    cout<<"选用物品序号："<<endl;
    for(int i=1; i<=n; i++)
    {
        if(best_x[i]==1)
            cout<<i<<" ";
        //cout<<best_x[i]<<" ";
    }
    cout<<endl;
}


