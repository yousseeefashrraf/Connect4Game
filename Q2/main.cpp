

#include <iostream>
#include <stdio.h>
using namespace std;
void board (char brd[][50]){
    int r,c;
   
    for(r=3; r<14;r++){
        for(c=0;c<=45;c+=5){
            brd[r][c]='[';
            brd[r][c+1]=' ';
            brd[r][c+2]=' ';
            brd[r][c+3]=' ';
            brd[r][c+4]=']';
        }
    }
    int i=1;
    for(c=0;c<=45;c+=5){
        brd[1][c]='|';
        brd[1][c+1]=' ';
        brd[1][c+2]=' ';
        brd[1][c+3]=' ';
        brd[1][c+4]=' ';
        
        if(i<10){
            brd[1][c+2]='0'+i;
        }
        
        else{
            if(i<100){
                brd[1][c+2]='0'+i/10;
                brd[1][c+3]='0'+i%10;
            }
        }
        i++;
    }
    brd[1][0]=' ';
    
    for(c=0;c<50;c++){
        brd[0][c]='.';
        brd[13][c]='.';
    }
    
    for(c=0;c<50;c++){
        brd[2][c]='.';
        brd[3][c]=' ';
    }
}

void Cout(char x[][50]){
    cout<<"\n\n\n";
    for( int r=0;r<14;r++){
        cout<<"      ";
        for( int c=0;c<50;c++){
            cout<<x[r][c];
        }
        cout<<"\n";
        if(r>3&&r<12){
            cout<<"\n";

        }
    }
    cout<<"\n";

}


//            //
//check if win//
//check if win//
//check if win//
//check if win//
//check if win//
//check if win//
//            //


void vertical(char x[][50], int & ifwin,int c, int r,char character){
    int ru,rd,ct=1;
    for(rd=r-1;rd>3;rd--){
        if(x[rd][c]==character){
            ct++;
        }
        else{
            break;
        }
    }
    
    for(ru=r+1;ru<=13;ru++){
        if(x[ru][c]==character){
            ct++;
        }
        else{
            break;
        }
    }
    
    if(ct>3){
        ifwin=1;
    }
    
}

void horizontal(char x[][50], int & ifwin,int c, int r,char character){
    int cl,cr,ct=1,cu;
    for(cl=c-1;cl>=0;cl--){
        cu=cl*5+2;
        if(x[r][cu]==character){
            ct++;
        }
        else{
            break;
        }
    }
    
    
    for(cr=c+1;cr<10;cr++){
        cu=cr*5+2;
        if(x[r][cu]==character){
            ct++;
        }
        else{
            break;
        }
    }
    
    if(ct>3){
        ifwin=1;
    }
    
}


void diagonal_left(char x[][50], int & ifwin,int c, int r,char character){
    int cl,rd,cr,ct=1,cu;
    for(cl=c-1,rd=r-1;cl>=0&&rd>3;cl--,rd--){
        cu=cl*5+2;
        if(x[rd][cu]==character){
            ct++;
        }
        else{
            break;
        }
        
    }
    
    
    for(cr=c+1,rd=r+1;cr<=9&&rd<14;cr++,rd++){
        cu=cr*5+2;
        if(x[rd][cu]==character){
            ct++;
        }
        else{
            break;
        }
    }
    
    if(ct>3){
        ifwin=1;
    }
    
}

void diagonal_right(char x[][50], int & ifwin,int c, int r,char character){
    int cl,rd,cr,ct=1,cu;
    for(cl=c+1,rd=r-1;cl<9&&rd>4;cl++,rd--){
        cu=cl*5+2;
        if(x[rd][cu]==character){
            ct++;
        }
        else{
            break;
        }
        
    }
    
    
    for(cr=c-1,rd=r+1;cr>=0&&rd<14;cr--,rd++){
        cu=cr*5+2;
        if(x[rd][cu]==character){
            ct++;
        }
        else{
            break;
        }
    }
    
    if(ct>3){
        ifwin=1;
    }
    
    
}

void play(char x[][50], char character, int c2,int &ifwin, int &notfair){
    int r;
    notfair=0;
    int c=c2*5+2;
    for(r=13;r>3;r--){
        if(x[r][c]==' ' && c2>=0 && c2<10){
            notfair=1;
            x[r][c]=character;
            break;
        }
    }
    
     ifwin=0;
    vertical(x, ifwin, c,  r, character);
    horizontal(x, ifwin, c2,  r, character);
    diagonal_left(x, ifwin, c2,  r,character);
    diagonal_right(x, ifwin, c2,  r,character);
    
}


int main() {
    char brd[15][50];
   
    
    char nameofgame[365]={95,95,95,95,95,95,95,95,95,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,95,95,32,32,32,32,32,95,95,95,95,95,32,32,10,92,95,32,32,32,95,95,95,32,92,32,32,95,95,95,95,32,32,32,95,95,95,95,32,32,32,95,95,95,95,32,32,32,95,95,95,95,32,32,32,95,95,95,95,95,47,32,32,124,95,32,32,47,32,32,124,32,32,124,32,10,47,32,32,32,32,92,32,32,92,47,32,47,32,32,95,32,92,32,47,32,32,32,32,92,32,47,32,32,32,32,92,95,47,32,95,95,32,92,95,47,32,95,95,95,92,32,32,32,95,95,92,47,32,32,32,124,32,32,124,95,10,92,32,32,32,32,32,92,95,95,95,40,32,32,60,95,62,32,41,32,32,32,124,32,32,92,32,32,32,124,32,32,92,32,32,95,95,95,47,92,32,32,92,95,95,95,124,32,32,124,32,47,32,32,32,32,94,32,32,32,47,10,32,92,95,95,95,95,95,95,32,32,47,92,95,95,95,95,47,124,95,95,95,124,32,32,47,95,95,95,124,32,32,47,92,95,95,95,32,32,62,92,95,95,95,32,32,62,95,95,124,32,92,95,95,95,95,32,32,32,124,32,10,32,32,32,32,32,32,32,32,92,47,32,32,32,32,32,32,32,32,32,32,32,32,92,47,32,32,32,32,32,92,47,32,32,32,32,32,92,47,32,32,32,32,32,92,47,32,32,32,32,32,32,32,32,32,32,124,95,95,32};
    
    

    int notfair=0;
    int ifwin=0;
    int f=1;
    int sc;
    int i=0;
    
    
    while(f){
        
        cout<<nameofgame<<"\n";
        board(brd);
        Cout(brd);
        for(;i<99;i++){
           cout<<"First player (O): ";
           cin>>sc;
           play(brd,'O', sc-1, ifwin,notfair);
            while(notfair==0){
                cout<<"Wrong cell for player 1, Enter Again: \n";
                cin>>sc;
                play(brd,'O', sc-1, ifwin,notfair);
            }

            cout<<"\n\n\n"<<nameofgame<<"\n";
           Cout(brd);
            cout<<"\n\n";
           if(ifwin==1){
               cout<<"Player 1 won!\n";
               cout<<"\n\nwanna play again? (<1> for yes <0> for no) \n";
               cin>>f;
               while(f!=0 && f!=1){
                   cout<<"Invalid operation, Enter again: ";
                   cin>>f;
               }
               break;
           }
           cout<<"Second player (0): ";
           cin>>sc;
           play(brd,'0', sc-1, ifwin,notfair);
            while(notfair==0){
                cout<<"Wrong cell for player 2, Enter Again: \n";
                cin>>sc;
                play(brd,'0', sc-1, ifwin,notfair);
            }
           
            cout<<"\n\n\n"<<nameofgame<<"\n";
           Cout(brd);
            cout<<"\n\n";
           if(ifwin==1){
               cout<<"Player 2 won!\n";
               cout<<"\n\nwanna play again? (<1> for yes <0> for no) \n";
               cin>>f;
               while(f!=0 && f!=1){
                   cout<<"Invalid operation, Enter again: ";
                   cin>>f;
               }
            
           }
        }
        
        if(i==100){
            cout<<"Draw.";
            cout<<"\n\nwanna play again? (1 for yes 0 for no) \n";
            cin>>f;
            while(f!=0 && f!=1){
                cout<<"Invalid operation, Enter again: ";
                cin>>f;
            }
        }
        
    }
    
}
