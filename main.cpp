#include <iostream>
#include <windows.h>
#include <time.h>
#include <vector>
#include <conio.h>

using namespace std;
const int height=20;
const int width=30;
int divide;

int x,y,fruitX,fruitY;
int score=0;
int ntail=0;
int tailX[100],tailY[100];
int maxscore=0;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos = {0, 0}; 
    
void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = false;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
} 

bool gameOver;


enum eDirection{ stop=0, UP , DOWN , LEFT , RIGHT };
eDirection dir;


void setColor(int color) { 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}



void fruit(){
    fruitX= 1 + rand() % (width-2);
    fruitY= 1 + rand() % (height-2);
    
    bool b=true;

    if(fruitX==x && fruitY==y)
        b=false;
    for(int i=0;i<ntail;i++){
        if(fruitX==tailX[i] && fruitY==tailY[i])
        {
            b=false;
            break;
        }
    }
    if(b==false)
        fruit();
}


void setup(){
    gameOver=false;
    dir=stop;
    x=width/2;
    y=height/2;
    score=0;
    ntail=0;
    fruit();
}



void starting_interface(){
    system("CLS");
    setColor(9);
    cout<< "WELCOME TO SNAKE GAME BY TECH SQUAD"<<endl<<endl;
    setColor(3);
    cout<<"      Choose Difficulty :"<<endl;
    cout<<"         for Easy Press 1"<<endl;
    cout<<"         for Medium Press 2"<<endl;
    cout<<"         for Hard Press 3"<<endl;
    int c;
    cin>>c;
    if(c==1)
        divide=1;
    else if(c==2)
        divide=2;
    else if(c==3)
        divide=3;
    else{
        divide=1;
    }
    }



void draw(){

    SetConsoleCursorPosition(hConsole, pos);

    setColor(7);


    for(int i=0;i<width;i++){
        cout<<(char)219;
    }
    cout<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(j==0 || j==width-1){
                cout<<(char)219;
            }
            else if(i==y && j==x){
                cout<<"O";
            }
            else if(i==fruitY && j==fruitX){
                cout<<"@";
            }
            else  {

                bool print=false;
                for(int k=0;k<ntail;k++){
                    if(i==tailX[k] && j==tailY[k]){
                    cout<<"o";
                    print=true;
                    }
                }if(!print){
                cout<<" ";
            }
            }

            }
        cout<<endl;
    }
    for(int i=0;i<width;i++){
        cout<<(char)219;
    }
    cout<<endl<<endl;
    cout<<"Score : "<<score<<endl;
    return;
}


void input(){
    if(_kbhit()){
        switch(_getch()){
            case 'w':
            if(dir!=DOWN)
                dir=UP;
            break;
    
            case 's' :
            if(dir!=UP)
                dir=DOWN;
            break;
            
            case 'a' :
            if(dir!=RIGHT)
                dir=LEFT;
            break;

            case 'd' :
            if(dir!=LEFT)
                dir=RIGHT;
            break;

            case 'x' :
            gameOver=true;
            break;
            
            default :
            break;
        }
    }
}




void logic(){

    int prevX=tailX[0];
    int prevY=tailY[0];
    tailX[0]=y;
    tailY[0]=x;
    int prev2X,prev2Y;

    for(int i=1;i<ntail;i++){
        prev2X=tailX[i];
        prev2Y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2X;
        prevY=prev2Y;
    }

    switch(dir){
        case UP :
            y--;
            break;
        case DOWN :
            y++;
            break;
        case LEFT :
            x--;
            break;
        case RIGHT :
            x++;
            break;
        default :
            break;
    }
    if(x<0 || y<0 || x>=width-1 || y>=height){
            gameOver=true;
        }

    for(int i=0;i<ntail;i++){
        if(y==tailX[i] && x==tailY[i]){
            gameOver=true;
    }
    }
    

    if(x==fruitX && y==fruitY){
            score++;
            ntail++;
            fruit();
        }
}

void GameOver(){
        system("CLS");
    setColor(4);    
    cout<<"GAME OVER"<<endl;
    setColor(7);
    cout<<"Score : "<<score<<"    Highest score : "<<maxscore<<endl;
    setColor(9);
    cout<<"TO PLAY AGAIN PRESS 'Y' OR TO EXIT GAME PRESS 'N' "<<endl;
    
}

void start_game(){
    system("CLS");
    hideCursor();
    setup();
    while(!gameOver){
    draw();
    input();
    logic();
    Sleep(200/divide);
    }
}

int main(){
    starting_interface();
    start_game();
    while(1)
        if(gameOver){
            if(score>maxscore)
                maxscore=score;
            GameOver();
            char c;
            if(score>maxscore)
                maxscore=score;
            cin>>c;
            cin.ignore();
            if(c=='y' || c=='Y')
                start_game();
            else
                break;
        }
return 0;
}
