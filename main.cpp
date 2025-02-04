#include <iostream>
#include <windows.h>
#include <time.h>
#include <vector>
#include <conio.h>

using namespace std;
const int height=20;
const int width=30;

int x,y,fruitX,fruitY;
int score=0;


bool gameOver;


enum eDirection{ stop=0, UP , DOWN , LEFT , RIGHT };
eDirection dir;


void setup(){
    gameOver=false;
    dir=stop;
    x=width/2;
    y=height/2;
    fruitX= 1 + rand() % (width-2);
    fruitY= 1 + rand() % (height-2);
}


void draw(){

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});

    for(int i=0;i<width;i++){
        cout<<"#";
    }
    cout<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(j==0 || j==width-1){
                cout<<"#";
            }
            else if(i==y && j==x){
                cout<<"O";
            }
            else if(i==fruitY && j==fruitX){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
            }
        cout<<endl;
    }
    for(int i=0;i<width;i++){
        cout<<"#";
    }
    cout<<endl<<endl;
    cout<<"Score : "<<score<<endl;
    return;
}


void input(){
    if(_kbhit()){
        switch(_getch()){
            case 'w':
            dir=UP;
            break;
            case 's' :
            dir=DOWN;
            break;
            case 'a' :
            dir=LEFT;
            break;
            case 'd' :
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
    if(x<0 || y<0 || x>=width-1 || y>=height-1){
            gameOver=true;
        }

    if(x==fruitX && y==fruitY){
            score++;
            fruitX= 1 + rand() % (width-2);
            fruitY= 1 + rand() % (height-2);
        }
}

void GameOver(){
        system("CLS");
    cout<<"GAME OVER"<<endl;
}

int main(){
    setup();
    while(!gameOver){
    draw();
    input();
    logic();
    Sleep(200);
    }
    while(gameOver){
        GameOver();
        break;
    }
    return 0;
}
