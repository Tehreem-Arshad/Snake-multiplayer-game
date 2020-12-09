#include <iostream>
#include <windows.h> //because we need system functions
#include <conio.h> //Because we need kbhit function
#include <fstream> // for files
#include<stdlib.h> // for cls command
#include<time.h> //time seeding
#include <vector> // for vectors
#include <mmsystem.h> // for background music
using namespace std;

int main_a();
int main_v();

bool end ;
enum movement {STOP=0,RIGHT, LEFT, UP, DOWN}; // RIGHT at first means snake will move to the right in start, Stop =0 means initially snake will not move
movement direction ;
int lev = 1;
int tail1 [50], tail2 [50] ;
void level_no () ; // after hitting specific score, level will change
void loading () ; // loading screen
void board (int &scr, int &tail_length, int &h_x, int &h_y, int &t_x, int &t_y, int &height, int &width) ; // For the main frame of game
void system(int &h_x, int &h_y, int &t_x, int &t_y, int &height, int &width) ; // For generating food randomly and snake head
void feed () ;  // For changing directions
int process (int &scr, int &tail_length, int &h_x, int &h_y, int &t_x, int &t_y, int &height, int &width) ; // For implementing the given change in direction
int menu (int &scr, int &tail_length, int &h_x, int &h_y, int &t_x, int &t_y, int &height, int &width) ;  // Main screen
int options () ; // to move up,down,right,left


////////////////////////////////////////////////////////////////////////////////////////////////////////

int main_v();

int game_play(vector<int> snake_r,vector<int> snake_c,char arr[][60],int height,int width,int seed_r,int seed_c,int stage); // game processing
void display(char arr[][60],int height,vector<int>snake_r);  //display
vector<int> seed(char arr[][60],int height,int width,vector<int>snake_c,vector<int>snake_r); //seed
void snake_growth(vector<int>&snake_r,vector<int>&snake_c,int seed_r,int seed_c); //snake growth
int death(char arr[][60],int height,vector<int>snake_r,vector<int>snake_c,int width); //snake death
void level_1(char arr[][60],int height,int width, vector<int> snake_r,vector<int> snake_c, int seed_r, int seed_c); //levels
void level_2(char arr[][60],int height,int width, vector<int> snake_r,vector<int> snake_c, int seed_r, int seed_c);
void level_3(char arr[][60],int height,int width, vector<int> snake_r,vector<int> snake_c, int seed_r, int seed_c);
void level_4(char arr[][60],int height,int width, vector<int> snake_r,vector<int> snake_c, int seed_r, int seed_c);
// two player game
int two_player_main();
vector<int> seed_2p (char arr [][70],int height ,int width ,vector<int>snake_c,vector<int>snake_r,vector<int>snake_c2,vector<int>snake_r2);
void level_2p (char arr [][70],int height ,int width , vector<int> snake_r,vector<int> snake_c,vector<int> snake_r2,vector<int> snake_c2, int seed_r , int seed_c );
void display_2p (char arr [][70],int height ,vector<int>snake_r,vector<int>snake_r2);
int game_play_2p (vector<int> snake_r,vector<int> snake_c,char arr [][70],int height ,int width ,int seed_r ,int seed_c ,vector<int> snake_r2,vector<int> snake_c2);
int death_2p (char arr [][70],int height ,vector<int>snake_r,vector<int>snake_c,int width ,vector<int>snake_r2,vector<int>snake_c2);
bool snake_growth_2p (vector<int>&snake_r,vector<int>&snake_c,vector<int>&snake_r2,vector<int>&snake_c2,int seed_r ,int seed_c );


int main ()
{
   PlaySound("PIRATES.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC) ;

    int game_mode;
  cout<<"1: Tehreem mode"<<endl;
  cout<<"2: Imtisal mode"<<endl;
  cin>>game_mode;
  if(game_mode == 1)
    {
       main_a();
    }
  else if(game_mode == 2)
    {
      main_v();
    }

}
int main_a()
{
   int height = 22 ;
   int width  = 22 ;
   int score=0 ;
   int tail=0 ;
   int h_x,h_y,t_x,t_y ; // for snake head (h_x,h_y) and food (t_x, t_y) position
   system ("Color F0") ; // color change
   // loading () ;

    menu (score, tail, h_x, h_y, t_x, t_y, height, width) ;

}
int main_v()
{

   system("color 4F");

    while(true) //loop keeping campaign mode continuous
    {
    system("cls");
    int active_status=1; //whenever the active status is 1 the game doesn't stop
    int mode;
    cout<<"\t\t\tCHOOSE GAME MODE "<<endl;
    cout<<"1: Campaign mode"<<endl;
    cout<<"2: stages"<<endl;
    cout<<"3: Multiplayer"<<endl;
    cin>>mode;

    if(mode==3)
    {
        two_player_main();
        return 0;
    }
    int stage = 0;

   while(true)
    {
    int height=40; //board parameters
    int width=60;
    char arr[height][60]; // background
    int seed_r;//for food
    int seed_c;
    vector<int>snake_r; //snake body
    vector<int>snake_c;
    snake_r.push_back(15);//starting points
    snake_c.push_back(8);


    if(mode==2)
    {
        cout<<"choose stage"<<endl;
        cout<<"1: stage 1"<<endl;
        cout<<"2: stage 2"<<endl;
        cout<<"3: stage 3"<<endl;
        cout<<"4: stage 4"<<endl;
        cin>> stage;
    }
    else
    {
        stage ++;
    }

    seed_r = (seed(arr,height, width, snake_c, snake_r))[0]; //seed row's coordinate
    seed_c = (seed(arr,height, width, snake_c, snake_r))[1]; //seed column's coordinate
      if(stage==1)
      {
        level_1(arr,height,width, snake_r, snake_c, seed_r, seed_c);
      }
      else if(stage==2)
      {
        level_2(arr,height,width,snake_r,snake_c,seed_r,seed_c);

      }
      else if(stage==3)
      {
        level_3(arr,height,width,snake_r,snake_c,seed_r,seed_c);
      }
      else if(stage==4)
      {
          level_4(arr,height,width,snake_r,snake_c,seed_r,seed_c);
      }
      else
      {
            cout<<"Invalid input";
      }

      if(mode==1 && stage==5)
      {
        break;
      }
        display(arr,height,snake_r);
        active_status = game_play(snake_r,snake_c,arr,height,width,seed_r,seed_c,stage);
        if(mode == 2)
        {
            break;
        }
        if(active_status == 0)
        {
            break;
        }
   }
   system("cls");
   char further;
   if(active_status == 0)
    {
        cout<<endl<<endl;
     cout<<"\t\t\tGAME OVER"<<endl<<endl;
     cout<<"press any key to go back to mode select"<<endl;
     cin>>further;
   }
   else if(active_status ==2)
   {
     cout<<"\t\t\tCongratulations, you won!!!"<<endl;

     cin>>further;
   }
     system("cls");
    }
    return 0;
}
void loading ()
 {

     system("cls") ;

            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << "\t\t\t\t\t\t" << "Loading...\n\n" << "\t\t\t\t\t\t" ;

            char box =178 ;
            char color = 219 ;

            for (int i =0 ; i<=20 ; i++)

                    {
                        cout << box ;  // Printing boxes
                    }

            cout<<"\r" <<  "\t\t\t\t\t\t" ;   //\r for repeating the same line instead moving to the other

            for ( int j = 0 ; j<=20 ; j++)

                    {
                        cout << color ; Sleep(180);  // Filling the boxes with black color with a delay
                    }

            system ("cls") ;
 }
 void level_no ()

 {

     system("cls") ;

            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << "\t\t\t\t\t\t" << "LeveL:" << lev << "\n\n" << "\t\t\t\t\t\t" ;

            char box =178 ;
            char color = 219 ;

            for (int i =0 ; i<=20 ; i++)

                    {
                        cout << box ;  // Printing boxes
                    }

            cout<<"\r" <<  "\t\t\t\t\t\t" ;   //\r for repeating the same line instead moving to the other

            for ( int j = 0 ; j<=20 ; j++)

                    {
                        cout << color ; Sleep(180);  // Filling the boxes with black color with a delay
                    }

            system ("cls") ;
 }
int menu (int &scr, int &tail_length, int &h_x, int &h_y, int &t_x, int &t_y, int &height, int &width)
 {
    system ("cls") ;
    system ("Color F0") ;
    cout << "\n\n\n\n\n\n\t\t\t\t\t ----------------------" ;
    cout << "\n\t\t\t\t\t|                      |" ;
    cout << "\n\t\t\t\t\t|      SNAKE GAME      |" ;
    cout << "\n\t\t\t\t\t|                      |" ;
    cout << "\n\t\t\t\t\t ----------------------\n" ;
    cout << "\n\t\t\t\tCopyrights R (2019) Tehreem Arshad\n" ;
    cout << "Controls:\n" ;
    cout << "          w or i = UP\n" ;
    cout << "          s or k = DOWN\n" ;
    cout << "          a or j = LEFT\n" ;
    cout << "          d or l = RIGHT\n" ;
    cout <<  endl ;
    string name ;
    cout << "Enter your name: " ;
    cin >> name ;
    cout <<  endl ;
    cout << "> Press 1 to start game" << endl ;
    cout << "> Press 2 for options" << endl ;
    cout << "> Press 3 to exit" << endl ;

    int press ;
    cin >> press ;
    if ( press == 1) {
                            system (h_x, h_y, t_x, t_y, height, width);
 // it will start the game and will ccntinue till the death of snake

                            while (!end) {
                                                board(scr, tail_length, h_x, h_y, t_x, t_y, height, width) ;
                                                feed() ;
                                                process (scr, tail_length, h_x, h_y, t_x, t_y, height, width) ;
                                                Sleep (100) ;
                                         }

                            loading();
                            cout << name << " " << "Your Score is: " << scr ;
                            cout << endl << endl << "Press ""y"" to save the score\nPress ""p"" to play again\nPress any other key to quit game" ;
                            string save ;
                            cout << endl ;
                            cin >> save ;
                            if (save == "p") { scr =0 ; height = 22; width = 22 ; lev=1 ; tail_length =0 ; menu (scr, tail_length, h_x, h_y, t_x, t_y, height, width) ;}
                            if (save == "y") {
                                                    if (save!="y") {
                                                                        return 0;
                                                                   }
// if "y" it will save the file with th given name by user
                                                    if (save=="y") {    system("cls") ;
                                                                        cout << "Enter 'q' to quit\n" ;
                                                                        label :
                                                                        string filename ;
                                                                        cout << "Name your file> ";
                                                                        cin.ignore () ;
                                                                        cin >> filename ;
                                                                        ifstream file1 ;
                                                                        file1.open ( filename.c_str() );
                                    // if new file is created it will go to the down3
                                                    if (!file1)    {
                                                                        goto down3;
                                                                        return 0 ;
                                                                   }
                                   // if file already exists with the same name
                                                else if (file1)    {
                                                                        cout << "Already exist\n" ;  goto down3 ;
                                                                   }
                                  // saving the newly created file
                            down3 :
                            cout << " Saved." ;
                            ofstream file ;
                            file.open ( filename.c_str() );
                            file << scr ;
                            file.close();

                                                                        }
                                               }
                    }
    if ( press == 2) { system ("cls") ; options () ; scr =0 ;
                       height = 22; width = 22 ; lev=1 ; tail_length =0 ; menu (scr, tail_length, h_x, h_y, t_x, t_y, height, width) ;
                     }
    if ( press == 3) { return 1 ;}

 }

int options ()
 {
    system ("cls") ;
    cout  << "> Press 1 for full screen\n" ;
   // cout  << "> Press 2 to change difficulty level\n" ;
    cout  << "> Press 2 to view your score\n" ;

    int press ;
    cin >> press ;
    if (press == 1) { system("mode 650");   }                    // for full screen
    if (press == 2) {  cout << "Enter file name: " ;             // if you want to view your score again
                                        string a ;
                                        cin >> a ;
                                        ifstream file ;
                                        file.open (a.c_str()) ;
                                         if (!file)
                                {
                                        cout << "Not exist\n" ; // if such file doesnt exist
                                        return 0 ;
                                }

                                    else if (file)             // if file exists
                                      {

                                        string temp ;
                                       while (file >> temp )
                                       {

                                         cout << temp << "\t"   ;
                                       }
}
 }
 }

 void system(int &h_x, int &h_y, int &t_x, int &t_y, int &height, int &width)

 {
     end = false ;
    h_x = width/2 ;
    h_y = height/2 ;          // To start snake from the center
    t_x = rand () % width ;
    t_y = rand () % height ; // to create food for snake
 }

  void board (int &scr, int &tail_length, int &h_x, int &h_y, int &t_x, int &t_y, int &height, int &width)

 {
     cout << endl ;
    system ("cls") ; // Clears screen

     cout << endl << "Press ""p"" to Pause " << endl << "SCORE: " << scr << endl;
    for (int i=0 ; i<width+2 ; i ++ ) // Because we have printed 20 spaces we need to more characters i.e. width + 2
    {
        cout << "*" ;
    }
     cout << endl ;

    for (int j=0 ; j<height ; j++)
    {
        for (int k=0 ; k<width ; k++)
        {
            if ( k==0) {cout <<"*" ;} // Prints * at (0,0) , (1,0), (2,0) and so on .. vertical wall
            if (j==h_y && k==h_x) {cout <<  "Q" ;} //Printing initial position of snake
            else if (j==t_y && k==t_x) {cout << "o" ;} //Printing initial position of food
            else {
                    bool border = false ;
                    for (int i =0 ; i < tail_length ; i++ )
                    {
                            if (tail1[i]==k && tail2[i] ==j) { cout << "O" ; border = true;} // Because printing O itself move borders forward
                    }
                            if (!border) cout << " " ;

                }
            if (k==width-1) {cout <<"*" ;} //width-1 because j<width not (for right wall)
                             }
            cout << endl ;
    }


    for (int i=0 ; i<width+2 ; i ++ ) // width+2 because number of spaces are 20
    {
        cout << "*" ;
    }

 }

  void feed ()

 {
     cout << endl;
    if (kbhit())// When player press the button
  {
       char ch = getch();

   switch (ch)// To take character
   /*
        i
      j + l
        k
            */
   {
        case'j':
        direction = LEFT;
        break;
        case'k':
        direction = DOWN;
        break;
        case'l':
        direction = RIGHT;
        break;
        case'i':
        direction = UP;
        break;


        case'a':
        direction = LEFT;
        break;
        case's':
        direction = DOWN;
        break;
        case'd':
        direction = RIGHT;
        break;
        case'w':
        direction = UP;
        break;
        case'p':
        system ("pause") ;
        break;
   }
 }
 }

 int process (int &scr, int &tail_length, int &h_x, int &h_y, int &t_x, int &t_y, int &height, int &width)
{
    int x1 = tail1 [0] ; // Previous x coordinate of the tail
    int y1 = tail2 [0] ; // Previous y coordinate of the tail
    int temp1 , temp2 ;
    tail1[0] = h_x; //0 means that after 0 position elements will follow head
    tail2[0] = h_y;
    for (int i =1; i <tail_length ; i++)
    {
        temp1 = tail1 [i] ;
        temp2 = tail2 [i] ;
        tail1 [i] = x1 ;
        tail2 [i] = y1 ;
        x1 = temp1 ;
        y1 = temp2 ;  // increasing the length of snake, when it eats food
    }

    switch (direction)
 {
      case LEFT://decrease value of x coordinate when j is pressed
      h_x--;
      break;
      case RIGHT://increase value of x coordinate when l is pressed
      h_x++;
      break;
      case UP:
      h_y--;//decrease value of y coordinate when i is pressed
      break;
      case DOWN:
      h_y++;//increase value of y coordinate when k is pressed
      break;
      default:
      break;
 }

 if (h_x>width-1 || h_x<0 || h_y> height-1 || h_y<0)
      end = true;  //when snake hit the wall game end
for (int i =0 ; i< tail_length; i++)
{
    if (tail1[i]==h_x && tail2[i]==h_y)
    end = true ;
}

 if (h_x== t_x && h_y == t_y) {
                         scr += 5 ; // Adding score
                         // it will move to level 2 at score 10
                         if (scr==10) { lev ++ ;height = 16; width = 16;
                                        h_x = width/2 ;
                                        h_y = height/2 ; // To start snake from the center
                                        t_x = rand () % width ;
                                        t_y = rand () % height ; level_no() ; system ("Color 0B") ;  }
                         t_x= rand () % width ;
                         t_y = rand () % height ;
                         tail_length ++ ; // It increases the tail
                         // it will move to level 3 (final) at score 20
                          if (scr==20) { lev ++ ;height = 12; width = 12;
                                        h_x = width/2 ;
                                        h_y = height/2 ; // To start snake from the center
                                        t_x = rand () % width ;
                                        t_y = rand () % height ; level_no() ; Sleep(90) ; system ("Color 0C") ;  }
                         t_x= rand () % width ;
                         t_y = rand () % height ;
                         tail_length ++ ; //

                      }


}

/////////////////////////////////////////////////////////////////////////////////////////////
 int game_play(vector<int> snake_r,vector<int> snake_c,char arr[][60],int height,int width,int seed_r,int seed_c,int stage)//snake movements
{ /*
  snake directions
       w
     a   d
       s
*/
   int active_status = 1;
 while(active_status == 1) //movements
        {
       char key=getch();// reading character and entering
       while(!kbhit())//as a counter to pressing key
          {
              for(int i=snake_r.size()-1;i>0;i--)//forming snake
             {
                 snake_r[i]=snake_r[i-1];
                 snake_c[i]=snake_c[i-1];
             }
        if(key=='w')
           {
              snake_r[0]--;
           }
        else if(key=='s')
           {
             snake_r[0]++;
           }
        else if(key=='d')
           {
             snake_c[0]++;
           }
        else if(key=='a')
           {
              snake_c[0]--;
           }
        else if(key=='p')
           {
               system("pause");
           }
        active_status = death(arr,height,snake_r,snake_c,width); //break kbhit loop when active status is zero
        if(active_status==0 ) // for breaking getch loop
           {
                break;
           }
        if(snake_r[0]==seed_r&&snake_c[0]==seed_c) //check when snake eats the seed
        {
          snake_growth(snake_r, snake_c, seed_r, seed_c);
          cout<<"\a"; //bell sound

        if(snake_r.size() == 4) //level up condition
        {
            active_status = 2;
            return active_status;
        }
        seed_r = (seed(arr,height, width, snake_c, snake_r))[0]; //seed sponing
        seed_c = (seed(arr,height, width, snake_c, snake_r))[1];
        }
        if(stage==1)
        {
          level_1(arr,height,width,snake_r, snake_c, seed_r, seed_c);
        }
        else if(stage ==2)
        {
            level_2(arr,height,width,snake_r,snake_c,seed_r,seed_c);
        }
        else if (stage==3)
        {
            level_3(arr,height,width,snake_r,snake_c,seed_r,seed_c);
        }
         else if(stage==4)
        {
          level_4(arr,height,width,snake_r,snake_c,seed_r,seed_c);
        }
        display(arr,height,snake_r);
       }

     }
     return active_status;
}
void level_1(char arr[][60],int height,int width, vector<int> snake_r,vector<int> snake_c, int seed_r, int seed_c) //background filling
{
    system("color 2A");
    for(int i=0;i<height;i++)  // full-fill array
    {
        for(int j=0;j<width;j++)
        {
            if((i==0)||(i==height-1)) //walls
            {
                arr[i][j]='#';
            }
            else if((j==0)||(j==width-1))
            {
                arr[i][j]='#';
            }
            else if(i==seed_r && j==seed_c) //seed
            {
                arr[i][j] = '.';
            }
            else
            {
                arr[i][j]='s';
            }
            for(int p=0;p<snake_c.size();p++) //snake's body
            {
                if(i==snake_r[p]&& j==snake_c[p])
                {
                    arr[i][j]='*';
                }
            }
            arr[snake_r[0]][snake_c[0]] = 'X'; //snake's head
        }
    }
}
void level_2(char arr[][60],int height,int width, vector<int> snake_r,vector<int> snake_c, int seed_r, int seed_c)
{     system("color 5D");
      for(int i=0;i<height;i++)  // full-fill array
    {
        for(int j=0;j<width;j++)
        {
            if((i==0)||(i==height-1))
            {
                arr[i][j]='#';
            }
            else if((j==0)||(j==width-1))
            {
                arr[i][j]='#';
            }
            else if(i==seed_r && j==seed_c)
            {
                arr[i][j] = '.';
            }
            else if(i==8 && j>=15 && j<=45)
            {
                arr[i][j]='#';
            }
            else if(i==32 && j>=15 && j<=45)
            {
                arr[i][j]='#';
            }
            else if(j==15 && i>=8 && i<=13)
            {
                arr[i][j]='#';
            }
            else if(j==15 && i>=27 && i<=32)
            {
                arr[i][j]='#';
            }
            else if(j==45 && i>=8 && i<=13)
            {
                arr[i][j]='#';
            }
            else if(j==45 && i>=27 && i<=32)
            {
                arr[i][j]='#';
            }
             else
            {
                arr[i][j]='s';
            }

            for(int p=0;p<snake_c.size();p++)
            {
                if(i==snake_r[p]&& j==snake_c[p])
                {
                    arr[i][j]='*';
                }
            }
            arr[snake_r[0]][snake_c[0]] = 'X';
       }
    }
}
void level_3(char arr[][60],int height,int width, vector<int> snake_r,vector<int> snake_c, int seed_r, int seed_c)
{  system("color 4C");
    for(int i=0;i<height;i++)  // full-fill array
    {
        for(int j=0;j<width;j++)
        {
            if((i==0)||(i==height-1))
            {
                arr[i][j]='#';
            }
            else if((j==0)||(j==width-1))
            {
                arr[i][j]='#';
            }
            else if(i==seed_r && j==seed_c)
            {
                arr[i][j] = '.';
            }
            else if(j==20 && (i<=13))
            {
                arr[i][j]='#';
            }
             else if(j==40 && (i>=23 ))
            {
                arr[i][j]='#';
            }
            else if(i==10 && j>=40)
            {
                arr[i][j]='#';
            }
            else
            {
                arr[i][j]='s';
            }
            for(int p=0;p<snake_c.size();p++)
            {
                if(i==snake_r[p]&& j==snake_c[p])
                {
                    arr[i][j]='*';
                }
            }
            arr[snake_r[0]][snake_c[0]] = 'X';
        }
    }
}
void level_4(char arr[][60],int height,int width, vector<int> snake_r,vector<int> snake_c, int seed_r, int seed_c)
{  system("color 3B");
     for(int i=0;i<height;i++)  // full-fill array
    {
        for(int j=0;j<width;j++)
        {
            if((i==0)||(i==height-1))
            {
                arr[i][j]='#';
            }
            else if((j==0)||(j==width-1))
            {
                arr[i][j]='#';
            }
            else if(i==seed_r && j==seed_c)
            {
                arr[i][j] = '.';
            }
            else if(j==10 && i<=5)
            {
                arr[i][j]= '#';
            }
            else if(i==7 && j<=7)
            {
                arr[i][j]='#';
            }
            else if(j==5 && i>=7 && i<=10)
            {
                arr[i][j]='#';
            }
            else if(i==10 && j>=5 && j<=20)
            {
                arr[i][j]='#';
            }
            else if(j==20 && i>=7 && i<=15)
            {
                arr[i][j]='#';
            }
            else if(i==13 && j>=20 && j<=30 )
            {
                arr[i][j]='#';
            }
            else if(j==30  && i>=4 && i<=13)
            {
                arr[i][j]='#';
            }
            else if(i==5 && j>=30 && j<=40)
            {
                arr[i][j]='#';
            }
            else if(j==36 && i>=5 && i<=10)
            {
                arr[i][j]='#';
            }
            else if(i==10 && j>=36 && j<=51)
            {
                arr[i][j]='#';
            }
            else if(j==50 && i>=5 &&i<=18)
            {
                arr[i][j]='#';
            }
            else if(j==15 && i>=20 &&i<=29)
            {
                arr[i][j]='#';
            }
            else if(i==24 && j>=30 && j<=45)
            {
                arr[i][j]='#';
            }
            else if(i==35 && j>=7 && j<=36)
            {
                arr[i][j]='#';
            }
            else if(j==36 && i>=24 && i<=35)
            {
                arr[i][j]='#';
            }
            else if(j==45 && i>=27 && i<=35)
            {
                arr[i][j]='#';
            }
            else if(i==33 && j>=45 && j<=52)
            {
                arr[i][j]='#';
            }
            else if(j==52&& i>=33 && i<=35)
            {
                arr[i][j]='#';
            }

             else
            {
                arr[i][j]='s';
            }

            for(int p=0;p<snake_c.size();p++)
            {
                if(i==snake_r[p]&& j==snake_c[p])
                {
                    arr[i][j]='*';
                }
            }
            arr[snake_r[0]][snake_c[0]] = 'X';
        }
    }
}
void display(char arr[][60],int height,vector<int>snake_r) //display
{
 for(int i=0; i<100000; i++)//For slowing loop
    {
        for(int k=0; k<500; k++)
          {
          }
    }
    system("cls");

    char wall =220;//char body =44;
    char head =2;
    char body=4;
    char seed=248;

    for(int i=0;i<40;i++)
    {
        for(int j=0;j<60;j++)
        {
            if(arr[i][j]=='#') //wall
            {
                cout<<wall;
            }

            else if(arr[i][j]=='s') //space
            {
                cout<<" ";
            }
            else if(arr[i][j]=='X') //snake's head
            {
              cout<<head;
            }
            else if(arr[i][j]=='*') //snake's body
            {
              cout<<body;
            }
            else if(arr[i][j]=='.') //snake
            {
              cout<<seed;
            }
        }
        cout<<endl;
    }
    cout<<"SCORE= "<<snake_r.size()-1<<endl;
}
vector<int> seed(char arr[][60],int height,int width,vector<int>snake_c,vector<int>snake_r)
{
srand(time(NULL)); //because time is constantly changing
int seed_r;
int seed_c;

    bool br = true;
    vector<int>seed_v;

    while(true)
    {
        seed_r= (rand() % (height-3))+1;
        seed_c= (rand() % (width-3))+1;

        for(int i=0;i<snake_c.size();i++)
            {
         if( seed_r==snake_r[i]&&seed_c==snake_c[i] || arr[seed_r][seed_c]=='#')
                {
                    br = false;
                    break; //for breaking for loop if a match is found
                }
                else
                {
                    br = true;
                }
            }
         if(br==true) //for breaking while loop if seed does not coincide with snakes's coordinates
               {
                    break;
               }
    }
    seed_v.push_back(seed_r); //seed's coordinates
    seed_v.push_back(seed_c);

         return seed_v;
}
void snake_growth(vector<int>&snake_r,vector<int>&snake_c,int seed_r,int seed_c)
{

        snake_r.push_back(snake_r[snake_r.size()-1]); //enters new element to the tail having last coordinate's value
        snake_c.push_back(snake_c[snake_r.size()-1]);

              for(int i=snake_r.size()-1;i>0;i--) // pushes all the values towards head
             {
                 snake_r[i]=snake_r[i-1];
                 snake_c[i]=snake_c[i-1];
             }

}
int death(char arr[][60],int height,vector<int>snake_r,vector<int>snake_c,int width)
{
    for(int i=1;i<snake_c.size()-1;i++)
        {
           if(arr[snake_r[0]][snake_c[0]] == '*') //snakes's own body
            {
              return 0;
            }
        }
    if(arr[snake_r[0]][snake_c[0]]=='#') //wall
    {
        return 0;
    }
    else
    {
        return 1; //game status
    }
}
///////////////////////////////////////////////////////////////////////////////////
int two_player_main()
{

   system("color F0");
    int height =50; //board parameters
    int width =70;
    char arr [height ][70]; // background

    int seed_r ;//for food
    int seed_c ;
    vector<int>snake_r; //snake body
    vector<int>snake_c;
    vector<int>snake_r2; //snake body
    vector<int>snake_c2;

    snake_r.push_back(15);//starting points
    snake_c.push_back(8);
    snake_r2.push_back(35);//starting points
    snake_c2.push_back(40);


   seed_r = (seed_2p (arr ,height , width , snake_c, snake_r,snake_c2,snake_r2))[0]; //seed row's coordinate
   seed_c  = (seed_2p (arr ,height , width , snake_c, snake_r,snake_c2,snake_r2))[1]; //seed column's coordinate
   level_2p (arr ,height ,width ,snake_r,snake_c,snake_r2,snake_c2,seed_r ,seed_c );

   display_2p (arr ,height ,snake_r,snake_r2);
   game_play_2p (snake_r,snake_c,arr ,height ,width ,seed_r ,seed_c ,snake_r2,snake_c2);


   return 0;
}
vector<int> seed_2p (char arr [][70],int height ,int width ,vector<int>snake_c,vector<int>snake_r,vector<int>snake_c2,vector<int>snake_r2)
{
srand(time(NULL));
int seed_r ;
int seed_c ;

    bool br = true;
    vector<int>seed_v ;

    while(true)
    {
        seed_r = (rand() % (height -3))+1;
        seed_c = (rand() % (width -3))+1;


        for(int i=0;i<snake_c.size();i++)
            {
                if(arr [seed_r ][seed_c ]=='*'|| arr [seed_r ][seed_c ]=='X' || arr [seed_r ][seed_c ]=='#')
                {
                    br = false;
                    break;
                }
                else
                {
                    br = true;
                }
            }

         if(br==true) //for breaking while loop if seed does not coincide with snakes's coordinates
               {

                    break;
               }


    }
    seed_v .push_back(seed_r ); //seed's coordinates
    seed_v .push_back(seed_c );

         return seed_v ;
}

void level_2p (char arr [][70],int height ,int width , vector<int> snake_r,vector<int> snake_c,vector<int> snake_r2,vector<int> snake_c2, int seed_r , int seed_c )
{
    for(int i=0;i<height ;i++)  // full-fill array
    {
        for(int j=0;j<width ;j++)
        {
            if((i==0)||(i==height -1)) //walls
            {

                arr [i][j]='#';
            }
            else if((j==0)||(j==width -1))
            {

                arr [i][j]='#';
            }
            else if(i==seed_r  && j==seed_c ) //seed
            {

                arr [i][j]='.';
            }
            else
            {

                arr [i][j]='s';
            }

            for(int p=0;p<snake_c.size();p++) //snake's body
            {

                if(i==snake_r[p]&& j==snake_c[p])
                {
                    arr [i][j]='*';
                }
            }
            arr [snake_r[0]][snake_c[0]] = 'X'; //snake's head


            for(int p=0;p<snake_c2.size();p++) //snake's body
            {

                if(i==snake_r2[p]&& j==snake_c2[p])
                {
                    arr [i][j]='*';
                }
            }
            arr [snake_r2[0]][snake_c2[0]] = 'X'; //snake's head
        }

    }

}

void display_2p (char arr [][70],int height ,vector<int>snake_r,vector<int>snake_r2) //display
{
 for(int i=0; i<100000; i++)//For slowing loop
    {
        for(int k=0; k<500; k++)
          {
          }
    }

    system("cls");

    char wall =4;
    //char body =44;
    char head =2;

    for(int i=0;i<50;i++)
    {
        for(int j=0;j<70;j++)
        {
            if(arr [i][j]=='#') //wall
            {
                cout<<wall;
            }

            else if(arr [i][j]=='s') //space
            {
                cout<<" ";
            }
            else if(arr [i][j]=='X') //snake's head
            {
              cout<<head;
            }
            else if(arr [i][j]=='*') //snake's body
            {
              cout<<"O";
            }
            else if(arr [i][j]=='.') //snake
            {
              cout<<"o";
            }

        }
        cout<<endl;
    }
  cout<<"SCORE1= "<<snake_r.size()-1<<endl;
  cout<<"SCORE2= "<<snake_r2.size()-1<<endl;
}

int game_play_2p (vector<int> snake_r,vector<int> snake_c,char arr [][70],int height ,int width ,int seed_r ,int seed_c ,vector<int> snake_r2,vector<int> snake_c2)//snake movements
{ /*
  snake directions
 for snake 1                     for snake 2
       w                             i
     a   d                         j   l
       s                             k
*/
int active_status=1;
char key1='b', key2='b';

 while(active_status==1) //movements
        {

       char key=getch();// reading character and entering

       if((key1=='w' && key =='s')||(key1=='s' && key =='w')||(key1=='a' && key =='d')||(key1=='d' && key =='a'))
        {
            key = key1;
       }
       else if((key1=='i' && key =='k')||(key1=='k' && key =='i')||(key1=='j' && key =='l')||(key1=='l' && key =='j'))
        {
            key = key1;
       }



       while(!kbhit())//as a counter to pressing key
          {
              if(key=='w'||key=='a'||key=='s'||key=='d')
              {
                  key1 = key;
              }
              else if(key=='i'||key=='j'||key=='k'||key=='l')
              {
                  key2 = key;
              }

              for(int i=snake_r.size()-1;i>0;i--)//forming snake
             {
                 snake_r[i]=snake_r[i-1];
                 snake_c[i]=snake_c[i-1];
             }

              for(int i=snake_r2.size()-1;i>0;i--)//forming snake
             {
                 snake_r2[i]=snake_r2[i-1];
                 snake_c2[i]=snake_c2[i-1];
             }
        if(key1=='w')
           {
              snake_r[0]--;
           }
        else if(key1=='s')
           {
             snake_r[0]++;
           }
        else if(key1=='d')
           {
             snake_c[0]++;
           }
        else if(key1=='a')
           {
              snake_c[0]--;
           }

        if(key2=='i')
           {
              snake_r2[0]--;
           }
        else if(key2=='k')
           {
             snake_r2[0]++;
           }
        else if(key2=='l')
           {
             snake_c2[0]++;
           }
        else if(key2=='j')
           {
              snake_c2[0]--;
           }
       active_status = death_2p(arr ,height ,snake_r,snake_c,width ,snake_r2,snake_c2); //break kbhit loop when active status is zero
        if(active_status==0 ) // for breaking getch loop
           {
                break;
           }


             bool grow = snake_growth_2p (snake_r, snake_c,snake_r2,snake_c2,seed_r , seed_c );
            if(grow){
            seed_r  = (seed_2p (arr ,height , width , snake_c, snake_r,snake_c2,snake_r2))[0]; //seed row's coordinate
              seed_c  = (seed_2p (arr ,height , width , snake_c, snake_r,snake_c2,snake_r2))[1];

            }







      level_2p (arr ,height ,width ,snake_r,snake_c,snake_r2,snake_c2,seed_r ,seed_c );

      display_2p(arr ,height ,snake_r,snake_r2);

       }

     }

}
int death_2p (char arr [][70],int height ,vector<int>snake_r,vector<int>snake_c,int width ,vector<int>snake_r2,vector<int>snake_c2)
{
    if(arr [snake_r[0]][snake_c[0]] == '*')
            {
              return 0;
            }

    else if(arr [snake_r2[0]][snake_c2[0]] == '*')
            {
              return 0;
            }

    else if(snake_c2[0] == snake_c[0] && snake_r[0]==snake_r2[0])// for both snake's head
        {
            return 0;
        }
    else if(arr [snake_r[0]][snake_c[0]]=='#' || arr [snake_r2[0]][snake_c2[0]]=='#') //for walls
       {
        return 0;
       }
    else
      {
        return 1;
      }
}

bool snake_growth_2p (vector<int>&snake_r,vector<int>&snake_c,vector<int>&snake_r2,vector<int>&snake_c2,int seed_r ,int seed_c )
{
    if(snake_r[0]==seed_r &&snake_c[0]==seed_c )
        {
        snake_r.push_back(snake_r[snake_r.size()-1]); //enters new element to the tail having last coordinate's value
        snake_c.push_back(snake_c[snake_r.size()-1]);

              for(int i=snake_r.size()-1;i>0;i--) // pushes all the values towards head
             {
                 snake_r[i]=snake_r[i-1];
                 snake_c[i]=snake_c[i-1];
             }
             return 1;

        }
    else if(snake_r2[0]==seed_r  && snake_c2[0]==seed_c )
    {
        snake_r2.push_back(snake_r2[snake_r2.size()-1]); //enters new element to the tail having last coordinate's value
        snake_c2.push_back(snake_c2[snake_r2.size()-1]);

              for(int i=snake_r2.size()-1;i>0;i--) // pushes all the values towards head
             {
                 snake_r2[i]=snake_r2[i-1];
                 snake_c2[i]=snake_c2[i-1];
             }
             return 1;
    }
    else{return 0;}
}
