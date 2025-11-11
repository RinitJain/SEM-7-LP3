#include<iostream>
#include<vector>
using namespace std;

//Function to check if placing queen at (row, col) is safe
bool isSafe(int row, int col, vector<string>&board, int n){
    //Check the left row
    for(int j=col-1; j>=0; j--)
        if(board[row][j]=='Q') return false;

    //Check for upper left diagonal
    for(int i=row-1, j=col-1; i>=0, j>=0; i--, j--)
        if(board[i][j]=='Q') return false;

    //Check for lower left diagonal
    for(int i=row+1, j=col-1; i<n, j>=0; i++, j--)
        if(board[i][j]=='Q') return false;

    return true;
}

void solve(int col, vector<string>&board, vector<vector<string>>&ans, int n){
    //Base case: If all queens are placed, add the board configuration to answers
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row=0; row<n; row++){
        //Check if placing queen at (row, col) is safe
        if(isSafe(row, col, board, n)){
            board[row][col] = 'Q'; //Place queen
            solve(col+1, board, ans, n); //Recur to place rest of the queens
            board[row][col] = '.'; //Backtrack VERY IMPORTANT
        }
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>>ans;
    vector<string>board(n, string(n, '.'));
    solve(0, board, ans, n);
    return ans;
}
int main(){
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    vector<vector<string>>solutions = solveNQueens(n);

    cout<<"Total solution for "<<n<<"-Queens: "<<solutions.size()<<endl;
    for(auto board : solutions){
        for(auto row : board){
            cout<<row<<endl;
        }
        cout<<endl;
    }

    return 0;
}