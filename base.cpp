#include<iostream.h> 
#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<conio.h> 
#include<dos.h> 
void Display(char [20][77],char,float); 
class Players 
{ 
 public: 
 char Name[10]; 
 char Token; 
 int Score; 
 int POSx; 
 int POSy; 
 char move; 
 int shoot; 
 void Run(char [20][77],char,int &,int &,int &,char,int &); 
}; 
void Players::Run(char map[20][77],char Token,int &Score,int &y,int &x,char move,int &shoot) 
{ 
 if(move=='w') 
 { 
  if(map[y-1][x]==' ' && y>0) 
  { 
   map[y][x] = ' '; 
   map[--y][x] = Token; 
  } 
  else 
  { 
   if(Token=='.' || Token==',' || Token=='+' || Token=='o') 
   { 
    if(y>0) 
    Score++; 
    shoot=0; 
   } 
  } 
 } 
 if(move=='s') 
 { 
  if(map[y+1][x]==' ' && y<19) 
  { 
   map[y][x] = ' '; 
   map[++y][x] = Token; 
  } 
  else 
  { 
   if(Token=='.' || Token==',' || Token=='+' || Token=='o') 
   { 
   if(y<19) 
   Score++; 
   shoot=0; 
   } 
  } 
 } 
 if(move=='a') 
 { 
  if(map[y][x-1]==' ' && x>0) 
  { 
   map[y][x] = ' '; 
   map[y][--x] = Token; 
  } 
  else 
  { 
   if(Token=='.' || Token==',' || Token=='+' || Token=='o') 
   { 
    if(x>0) 
    Score++; 
    shoot=0; 
   } 
  } 
 } 
 if(move=='d') 
 { 
  if(map[y][x+1]==' ' && x<77) 
  { 
   map[y][x] = ' '; 
   map[y][++x] = Token; 
  } 
  else 
  { 
   if(Token=='.' || Token==',' || Token=='+' || Token=='o') 
   { 
    if(x<77) 
    Score++; 
    shoot=0; 
   } 
  } 
 } 
} 
void Display(char map[20][77],char symbol,float timer) 
{ 
 clrscr(); 
 int i,j,k; 
 for(k=0;k<69;k++) 
 cout<<symbol; 
 cout<<" Time: "<<int(timer)<<endl; 
 for(i=0;i<20;i++) 
 { 
  cout<<symbol; 
  for(j=0;j<77;j++) 
  { 
   cout<<map[i][j]; 
  } 
  cout<<symbol<<endl; 
 } 
} 
void main() 
{ 
 Players P[4],B[4]; 
 randomize(); 
 clrscr(); 
 
 strcpy(P[0].Name,"Comp 1"); 
 strcpy(P[1].Name,"Comp 2"); 
 strcpy(P[2].Name,"Comp 3"); 
 strcpy(P[3].Name,"Comp 4"); 
 B[0].Token = '.'; B[1].Token = ',';  B[2].Token = '+'; B[3].Token = 'o'; 
 
 P[0].POSx = 36; P[0].POSy = 12; 
 P[1].POSx = 35; P[1].POSy = 6; 
 P[2].POSx = 26; P[2].POSy = 14; 
 P[3].POSx = 15; P[3].POSy = 16; 
 
 B[0].POSx = 36; B[0].POSy = 12; 
 B[1].POSx = 35; B[1].POSy = 6; 
 B[2].POSx = 26; B[2].POSy = 14; 
 B[3].POSx = 15; B[3].POSy = 16; 
 
 P[0].Score=0; P[1].Score=0; P[2].Score=0; P[3].Score=0; 
 B[0].shoot=0; B[1].shoot=0; B[2].shoot=0; B[3].shoot=0; 
 
 P[0].move = 'a'; 
 P[1].move = 'd'; 
 P[2].move = 'w'; 
 P[3].move = 's'; 
 
 B[0].move = 'a'; 
 B[1].move = 'd'; 
 B[2].move = 'w'; 
 B[3].move = 's'; 
 
 char in[4],Winner[10],RanNum,map[20][77]; 
 int y,x,i,j,NoP,speed=0; 
 int len[4],seconds,HigSco; 
 float timer=0; 
 for(i=0;i<20;i++) 
 { 
  for(j=0;j<77;j++) 
  map[i][j]=' '; 
 } 
 j = 1; 
 cout<<"\t\t\t"<<"WELCOME TO SHOOTER GAME !!!!!!"<<"\n\n"; 
 cout<<"This is a Shooting Game in which 4 Units Battle with each other"<<"\n\n"; 
 cout<<"Each Unit/Token has different type of Bullets"<<"\n\n"; 
 cout<<"Only 1 Bullet can be fired at a time"<<endl; 
 cout<<"The Unit whose Bullet touched another Unit will get 1 Point"<<"\n\n"; 
 cout<<"The Unit with Highest Score Wins the Game !!!!!!"<<"\n\n\n\t\t\t"; 
 cout<<"Press Any Key to Start.........."; 
 getch(); 
 
 clrscr(); 
 cout<<"No: of Players: "; cin>>NoP; 
 cout<<endl; 
 for(i=0;i<NoP;i++) 
 { 
  cout<<"Name of Player (Limit=10): "; gets(P[i].Name); 
  cout<<"Player "<<i+1<<" Token: ";  cin>>P[i].Token; 
  len[i] = strlen(P[i].Name); 
  cout<<endl; 
  if(i==0) 
  { 
   cout<<"At the Left Side of the Alphabet Part of Keyboard:"<<endl; 
   cout<<"'w' = Up, 's' = Down, 'a' = Left, 'd' = Right, 'z' = Shoot"<<endl; 
   cout<<"You have '.' Bullets"<<"\n\n\n"; 
  } 
  if(i==1) 
  { 
   cout<<"At the NumPad Side of the Keyboard:"<<endl; 
   cout<<"'8' = Up, '2' = Down, '4' = Left, '6' = Right, '0' = Shoot"<<endl; 
   cout<<"You have ',' Bullets"<<"\n\n\n"; 
  } 
  if(i==2) 
  { 
   cout<<"At the Middle Side of the Alphabet Part of Keyboard:"<<endl; 
   cout<<"'t' = Up, 'g' = Down, 'f' = Left, 'h' = Right, 'v' = Shoot"<<endl; 
   cout<<"You have '+' Bullets"<<"\n\n\n"; 
  } 
  if(i==3) 
  { 
   cout<<"At the Right Side of the Alphabet Part of Keyboard:"<<endl; 
   cout<<"'i' = Up, 'k' = Down, 'j' = Left, 'l' = Right, 'm' = Shoot"<<endl; 
   cout<<"You have 'o' Bullets"<<"\n\n\n"; 
  } 
 } 
 for(i=NoP;i<4;i++) 
 { 
  do 
  { 
   P[i].Token = P[i-NoP].Token + j; 
   j++; 
  } 
  while(P[i].Token=='.' || P[i].Token==',' || P[i].Token=='+' || P[i].Token=='o'); 
  len[i] = strlen(P[i].Name); 
 } 
 
 cout<<endl<<"Duration of Match (in seconds): "; cin>>seconds; 
 clrscr(); 
 while(timer<seconds+1) 
 { 
  map[P[0].POSy][P[0].POSx] = P[0].Token; 
  map[P[1].POSy][P[1].POSx] = P[1].Token; 
  map[P[2].POSy][P[2].POSx] = P[2].Token; 
  map[P[3].POSy][P[3].POSx] = P[3].Token; 
 
  for(i=0;i<4;i++) 
  { 
   if(B[i].shoot==0) 
   { 
    if(P[i].move=='w') 
    { 
     B[i].POSy = P[i].POSy - 1; 
     B[i].POSx = P[i].POSx; 
    } 
    if(P[i].move=='s') 
    { 
     B[i].POSy = P[i].POSy + 1; 
     B[i].POSx = P[i].POSx; 
    } 
    if(P[i].move=='a') 
    { 
     B[i].POSy = P[i].POSy; 
     B[i].POSx = P[i].POSx - 1; 
    } 
    if(P[i].move=='d') 
    { 
     B[i].POSy = P[i].POSy; 
     B[i].POSx = P[i].POSx + 1; 
    } 
    B[i].move = P[i].move; 
   } 
  } 
 
  Display(map,'|',timer); 
  printf("| %s = %d ",P[0].Name,P[0].Score); 
  for(i=0;i<(13-len[0]);i++) 
  cout<<"|"; 
  printf(" %s = %d ",P[1].Name,P[1].Score); 
  for(i=0;i<(12-len[1]);i++) 
  cout<<"|"; 
  printf(" %s = %d ",P[2].Name,P[2].Score); 
  for(i=0;i<(12-len[2]);i++) 
  cout<<"|"; 
  printf(" %s = %d ",P[3].Name,P[3].Score); 
  for(i=0;i<(13-len[3]);i++) 
  cout<<"|"; 
  for(i=NoP;i<4;i++) 
  { 
   RanNum = random(5); 
   if(RanNum==0) 
   in[i] = 'w'; 
   else if(RanNum==1) 
   in[i] = 's'; 
   else if(RanNum==2) 
   in[i] = 'a'; 
   else if(RanNum==3) 
   in[i] = 'd'; 
   else if(RanNum==4) 
   in[i] = 'z'; 
 
   if(in[i]!='z') 
   P[i].move = in[i]; 
  } 
 
  if(kbhit()) 
  { 
   in[0] = getch(); 
   for(i=1;i<NoP;i++) 
   { 
    if(in[0]!='z') 
    in[i] = in[0]; 
   } 
   if(in[1]=='8')  in[1]='w'; 
   if(in[1]=='2')  in[1]='s'; 
   if(in[1]=='4')  in[1]='a'; 
   if(in[1]=='6')  in[1]='d'; 
   if(in[1]=='0')  in[1]='z'; 
 
   if(in[2]=='t')  in[2]='w'; 
   if(in[2]=='g')  in[2]='s'; 
   if(in[2]=='f')  in[2]='a'; 
   if(in[2]=='h')  in[2]='d'; 
   if(in[2]=='v')  in[2]='z'; 
 
   if(in[3]=='i')  in[3]='w'; 
   if(in[3]=='k')  in[3]='s'; 
   if(in[3]=='j')  in[3]='a'; 
   if(in[3]=='l')  in[3]='d'; 
   if(in[3]=='m')  in[3]='z'; 
 
   if(in[0]=='w' || in[0]=='s' || in[0]=='a' || in[0]=='d') 
   P[0].move = in[0]; 
 
   if(in[0]=='8' || in[0]=='2' || in[0]=='4' || in[0]=='6') 
   P[1].move = in[1]; 
 
   if(in[0]=='t' || in[0]=='g' || in[0]=='f' || in[0]=='h') 
   P[2].move = in[2]; 
 
   if(in[0]=='i' || in[0]=='k' || in[0]=='j' || in[0]=='l') 
   P[3].move = in[3]; 
  } 
 
  if(speed%6==0) 
  { 
   speed=0; 
   P[0].Run(map,P[0].Token,P[0].Score,P[0].POSy,P[0].POSx,P[0].move,B[0].shoot); 
   P[1].Run(map,P[1].Token,P[1].Score,P[1].POSy,P[1].POSx,P[1].move,B[1].shoot); 
   P[2].Run(map,P[2].Token,P[2].Score,P[2].POSy,P[2].POSx,P[2].move,B[2].shoot); 
   P[3].Run(map,P[3].Token,P[3].Score,P[3].POSy,P[3].POSx,P[3].move,B[3].shoot); 
  } 
  speed++; 
 
  for(i=0;i<4;i++) 
  { 
   if(in[i]=='z' || B[i].shoot==1) 
   { 
    B[i].shoot=1; 
    B[i].Run(map,B[i].Token,P[i].Score,B[i].POSy,B[i].POSx,B[i].move,B[i].shoot); 
    if(B[i].shoot==0) 
    { 
     in[i] = P[i].move; 
     map[B[i].POSy][B[i].POSx]=' '; 
    } 
   } 
  } 
  delay(50); 
  timer+=0.05; 
 } 
 delay(2000); 
 clrscr(); 
 cout<<"\n\n\t\t\t\t"<<"SCORES:"<<"\n\n\n\t"; 
 printf(" %s    =    %d \n\n\t",P[0].Name,P[0].Score); 
 printf(" %s    =    %d \n\n\t",P[1].Name,P[1].Score); 
 printf(" %s    =    %d \n\n\t",P[2].Name,P[2].Score); 
 printf(" %s    =    %d ",P[3].Name,P[3].Score); 
 
 HigSco = P[0].Score; 
 strcpy(Winner,P[0].Name); 
 for(i=1;i<4;i++) 
 { 
  if(P[i].Score>HigSco) 
  { 
   HigSco = P[i].Score; 
   strcpy(Winner,P[i].Name); 
  } 
 } 
 for(i=0;i<3;i++) 
 { 
  for(j=i+1;j<4;j++) 
  { 
   if(P[i].Score==P[j].Score && P[i].Score==HigSco) 
   strcpy(Winner,"Nobody"); 
  } 
 } 
 cout<<"\n\n\n\t\t\t"<<"The Winner of this Game is "; 
 puts(Winner); cout<<"\n\t\t\t ! @ # $ % ^ & * ( )"; 
 getch(); 
} 
