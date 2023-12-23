//Player vs Computer
#include<bits/stdc++.h>
#define print(n) cout<<n<<endl
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void printBoard(){
    cout<<"\t\t "<<board[0][0]<<" | "<< board[0][1]<<" | "<<board[0][2]<<endl;
    print("\t\t---|---|---");
    cout<<"\t\t "<<board[1][0]<<" | "<< board[1][1]<<" | "<<board[1][2]<<endl;
    print("\t\t---|---|---");
    cout<<"\t\t "<<board[2][0]<<" | "<< board[2][1]<<" | "<<board[2][2]<<endl;
}


bool isOver(){
    if(board[0][0] == board[0][1] && board[0][0] == board[0][2]){
        return true;
    }
    else if(board[1][0] == board[1][1] && board[1][0] == board[1][2]){
        return true;
    }
    else if(board[2][0] == board[2][1] && board[2][0] == board[2][2]){
        return true;
    }
    else if(board[0][0] == board[1][0] && board[0][0] == board[2][0]){
        return true;
    }
    else if(board[0][1] == board[1][1] && board[0][1] == board[2][1]){
        return true;
    }
    else if(board[0][2] == board[1][2] && board[0][2] == board[2][2]){
        return true;
    }
    else if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        return true;
    }
    else if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        return true;
    }
    else{
        return false;
    }
}

int findMove(char turn){
    //Sequential search for position
    /*for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] != 'O' && board[i][j] != 'X'){
                return (board[i][j]-'0');
            }
        }
    }*/

    //Check for win
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] == 'X' || board[i][j] == 'O'){
                continue;
            }
            char temp = board[i][j];
            board[i][j] = turn;
            if(isOver()){
                print(1);
                board[i][j] = temp;
                return temp-'0';
            }
            board[i][j] = temp;
        }
    }

    char opponent;
    if(turn == 'O'){
        opponent = 'X';
    }
    else{
        opponent = 'O';
    }

    //Block opponent move
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] == 'X' || board[i][j] == 'O'){
                continue;
            }

            char temp = board[i][j];
            board[i][j] = opponent;

            if(isOver()){
                print(2);
                board[i][j] = temp;
                return temp-'0';
            }
            board[i][j] = temp;
        }
    }

    //Acquire centre position
    if(board[1][1] == '5'){
        print(3);
        return 5;
    }

    //Random move
    while(true){
        int temp = (rand()%9 + 1);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]-'0' == temp){
                    print(4);
                    return temp;
                }
            }
        }
    }
}
char placeMove(char turn, bool &comp){
    int temp;
    if(!comp){
        cout<<"Enter place: ";
        cin>>temp;
    }
    else{
        temp = findMove(turn);
    }

    bool move = false;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]-'0' == temp){
                board[i][j] = turn;
                move = true;
                break;
            }
        }
        if(move){
            break;
        }
    }
    if(!move){
        cout<<"###Invalid move..."<<endl;
        return placeMove(turn,comp);
    }
    else{
        comp = !comp;
        if(turn == 'O'){
            return 'X';
        }
        else{
            return 'O';
        }
    }
}

void whoseTurn(char turn){
        print("--------------");
        cout<<"###It's "<<turn<<"'s turn..."<<endl;
        print("--------------");
}

void printWinner(char n){
    printBoard();
    cout<<"\t Winner: "<<endl;
    if(n == 'O'){
        cout<<" 000 "<<endl;
        cout<<"0   0"<<endl;
        cout<<"0   0"<<endl;
        cout<<"0   0"<<endl;
        cout<<" 000 "<<endl;
    }
    else{
        cout<<"X   X"<<endl;
        cout<<" X X "<<endl;
        cout<<"  X  "<<endl;
        cout<<" X X "<<endl;
        cout<<"X   X"<<endl;
    }
}
int main(void){
    cout<<"#Enter your mark (O | X): ";
    char a, b;
    cin>>a;

    if(a == 'O'){
        b = 'X';
    }
    else{
        b = 'O';
        a = 'X';
    }

    bool comp = false;
    char turn;
    int count = 0;

    while(!isOver() && count < 9){
        printBoard();
        if(comp){
            turn = b;
        }
        else{
            turn = a;
        }
        whoseTurn(turn);
        placeMove(turn, comp);
        count++;
    }
    if(count != 9){
        printWinner(turn);
    }
    else{
        cout<<"\t\t#Match Draw..."<<endl;
    }

    return 0;
}
