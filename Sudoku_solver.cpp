#include<bits/stdc++.h>
using namespace std;
void print_board(vector<vector<int>>&board,int n)
{
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<"  ";
        }
        cout<<"\n";
        cout<<"\n";
    }
}
bool is_valid(vector<vector<int>>&board,int i,int j,int num,int n)
{
    for(int k=0;k<n;k++)
    {
        if(board[i][k] == num)
        {
            return false;
        }
    }
    for(int k=0;k<n;k++)
    {
        if(board[k][j] == num)
        {
            return false;
        }
    }
    int sq = sqrt(n);
    int si = i-i%sq;
    int sj = j-j%sq;
    for(int x=si;x<si+sq;x++)
    {
        for(int y=sj;y<sj+sq;y++)
        {
            if(board[x][y] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool Sudoku_Solver(vector<vector<int>>&board,int i,int j,int n)
{
    if(i == n)
    {
        print_board(board,n);
        return true;
    }
    if(j == n)
    {
        return Sudoku_Solver(board,i+1,0,n);
    }
    if(board[i][j] != 0)
    {
        return Sudoku_Solver(board,i,j+1,n);
    }
    for(int num=1;num<=9;num++)
    {
        if(is_valid(board,i,j,num,n))
        {
            board[i][j] = num;
            bool subans = Sudoku_Solver(board,i,j+1,n);
            if(subans)
            {
                return true;
            }
            board[i][j] = 0;
        }
    }
}
signed main()
{
    int x = 9,y = 9;
    vector<vector<int>>board(x,vector<int>(y));
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            cin>>board[i][j];
        }
    }
    Sudoku_Solver(board,0,0,x);
}
