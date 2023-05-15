#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEAM_NAME_LEN 20

// Function to generate a random score for a team
int generateTeamScore() {
 return rand() % 8; // Generate a random score between 0 and 9
}
int stade() {
 return rand() % 5; // Generate a random score between 0 and 5
}
int y() {
 return rand() % 5;
 } // Generate a random score between 0 and 2
int r() {
 return rand() % 2;
 } // Generate a random score between 0 and 2

int proba() {
 return rand() % 100; // give the probability of a win 
}
int tirss() {
 return rand() % 100; // Generate a random score between 0 and 9
}
int horsjeux() {
 return rand() % 7; // Generate a random score between 0 and 9
}

struct team
{
 int teamp ;
 char teamn[20] ;
 int goalsscored;
 int recived;
 int tirs ;
 int tirscadré;
 int passes;
 int horsjeux;
};

void trietableau(struct team T[], int s){
 int l, p;
 struct team tmpp;
 for (l = 0; l < s-1; l++)
 {
 for (p = l+1; p < s; p++)
 {
 if (T[l].teamp < T[p].teamp)
 {
 tmpp = T[l];
 T[l] = T[p];
 T[p] = tmpp;
 } 
 else{
 if (T[l].teamp==T[p].teamp)
 {
if (T[l].goalsscored < T[p].goalsscored)
{
  tmpp = T[l];
 T[l] = T[p];
 T[p] = tmpp;
}



else{
  if (T[l].goalsscored == T[p].goalsscored)
  {if (T[l].goalsscored > T[p].goalsscored)
  {
   tmpp = T[l];
 T[l] = T[p];
 T[p] = tmpp;
  }
  
  }
  
}
}
}
}
}

}



int main() {
  printf("\033[0m"); // reset text color to default
  printf("\n");
  printf("\n");
  sleep(2);
  printf("\033[33m");
  printf("%*s", 93 , "||||||||||||||||||||||||||||Fun is about to start||||||||||||||||||||\n");
  printf("%*s", 93 , "|| -* in this fantansy you should enter a pair number of team      ||\n");
  printf("%*s", 93 , "|| furthermore we will give you the matchmaking between these teams||\n");
  printf("%*s", 93 , "|| the points,goals scored,goals recived, difference of goals      ||\n");
  printf("%*s", 93 , "|| yellow cards,red cards and also supporters preduction           ||\n");
  printf("%*s", 93 , "||                                                                 ||\n"); 
  printf("%*s", 93 , "||-* press the number 0 if you want to start the game              ||\n");
  printf("%*s", 93 , "|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
  printf("\033[0m");
 int t;
 scanf("%d",&t); 
if (t==0)
{

 srand(time(0));
 int n, i, j, day = 1;
 do {
 printf("Enter a pair number of teams which should be between 10 and 20: ");
 scanf("%d", &n);
 } while ( n < 8 || n > 22 || n%2!=0 );

 struct team tab[n];

 int yellowcardd[n];
 int redcardd[n];
 int differnceofgoals[n];
 for (i = 0; i < n; i++) {
 printf("Enter name of team %d: ", i + 1);
 scanf("%s", tab[i].teamn);
 }
 for (i = 0; i < n; i++) {
 tab[i].teamp = 0;
 tab[i].goalsscored=0;
 tab[i].recived=0;
 yellowcardd[i]=0;
 redcardd[i]=0;
 differnceofgoals[i]=0;

 }
 

char stadium[5][30] = {
    "Wembley Stadium",
    "Ethihad stadium",
    "Baraki Stadium",
    "Camp Nou Stadium",
    "Santiago Bernabio"
};
 int num_days = n - 1 ;
 int matches_played = 0;
 int played[n][n];
 
 for (i = 0; i < n; i++) {
 for (j = 0; j < n; j++) {
 played[i][j] = 0;
 }
 }
 for (i = 0; i < num_days; i++) {
 printf(" \033[1;35m Day %d \033[0m:\n", day);
 for (j = 0; j < n/2; j++) {
 int team1 = (i + j) % (n-1);
 int team2 = (i - j + n - 1) % (n-1);
 if(team1 == team2) {
 team2 = n - 1;
 }
 if (!played[team1][team2]) {
 // First match of the day
 int probawin1 = proba();
 int probawin2= 100-probawin1;
 int score1 = generateTeamScore();
 int score2 = generateTeamScore();
 int yellowcard=y();
 int redcard=r();
 int stadei=stade();
 int tirs=tirss();
 int tirscadre= tirs/2;
 int horsjeuxx=horsjeux();
 int passess=tirs+150;
 printf("\033[1;33m %s \033[0m \033[33m vs \033[0m \033[1;33m %s \033[0m \n" ,tab[team1].teamn, tab[team2].teamn);
 sleep(1);
 printf("-this game is programed in:\033[1;33m %s \033[0m\n",stadium[stadei] );
  sleep(1);
 printf("-supporters prediction of win | %s -> %d% / %d% <- %s \n",tab[team1].teamn,probawin1,probawin2,tab[team2].teamn);
  sleep(1);
 if (score1 > score2) {
 printf("-the final score \033[32m %s \033[0m -> %d : %d <- \033[1;31m %s \033[0m \n", tab[team1].teamn , score1, score2 , tab[team2].teamn );
 tab[team1].teamp = tab[team1].teamp + 3;
 } else if (score1 < score2) {
 tab[team2].teamp = tab[team2].teamp + 3;
 printf("-the final score \033[1;31m%s \033[0m -> %d : %d <- \033[32m%s \033[0m \n", tab[team1].teamn, score1, score2 ,tab[team2].teamn );
 } else {
 printf("-the final score \033[1;32m%s \033[0m -> %d : %d <- \033[32m%s \033[0m \n", tab[team1].teamn, score1, score2 ,tab[team2].teamn );
 tab[team1].teamp = tab[team2].teamp + 1;
 tab[team2].teamp = tab[team2].teamp + 1;
 }
 tab[team1].tirs=tirs;
 tab[team1].horsjeux=horsjeuxx;
 tab[team1].tirscadré=tirscadre;
 tab[team1].passes=passess;
 tab[team2].tirs=tirs;
 tab[team2].horsjeux=horsjeuxx;
 tab[team2].tirscadré=tirscadre;
 tab[team2].passes=passess;
 
 tab[team1].goalsscored=score1;
 tab[team2].goalsscored=score2;
 tab[team1].recived=score2;
 tab[team2].recived=score1;
 yellowcardd[team1]=yellowcard;
 redcardd[team1]=redcard;
 yellowcardd[team2]=yellowcard;
 redcardd[team2]=redcard;
 differnceofgoals[team1]=score1-score2;
 differnceofgoals[team2]=score2-score1;

 played[team1][team2] = 1;
 played[team2][team1] = 1; 
 } 

 else {
 int tmp_team = (j + i) % n;
 while (played[tmp_team][team2] || tmp_team == team2) {
 tmp_team = (tmp_team + 1) % n;
 }
 int probawin1= proba();
 int probawin2= 100 - probawin1;
 int score1 = generateTeamScore();
 int score2 = generateTeamScore();
 int yellowcard=y();
 int redcard=r();
 int tirs=tirss();
 int tirscadre= tirs/2;
 int horsjeuxx=horsjeux();
 int passess=tirs+150;
 printf("-\033[1;31m %s \033[0m \033[33m vs \033[0m \033[1;31m %s \033[0m \n", matches_played + 1, tab[tmp_team].teamn, tab[team2].teamn);
  sleep(1);
 printf("-supporters prediction of win | %s-> %d%/ %d%<-%s \n ",tab[tmp_team].teamn,probawin1,probawin2, tab[team2].teamn);
  sleep(1);
 if (score1 > score2) {
 printf("-the final score \033[32m %s \033[0m -> %d : %d <- \033[1;31m %s \033[0m \n", tab[tmp_team].teamn, score1, score2 , tab[team2].teamn );
 tab[tmp_team].teamp += 3;
 } else if (score1 < score2) {
 printf("-the final score \033[1;31m%s \033[0m -> %d : %d <- \033[32m%s \033[0m \n", tab[tmp_team].teamn, score1, score2 , tab[team2].teamn ); 
 tab[team2].teamp += 3;
 } else {
 printf("-the final score \033[1;32m%s \033[0m -> %d : %d <- \033[32m%s \033[0m \n", tab[tmp_team].teamn, score1, score2 , tab[team2].teamn );
 tab[tmp_team].teamp += 1;
 tab[team2].teamp += 1;
 }
 tab[tmp_team].goalsscored=score1;
 tab[team2].goalsscored=score2;
 tab[tmp_team].tirs=tirs;
 tab[tmp_team].horsjeux=horsjeuxx;
 tab[tmp_team].tirscadré=tirscadre;
 tab[tmp_team].passes=passess;
 tab[team2].tirs=tirs;
 tab[team2].horsjeux=horsjeuxx;
 tab[team2].tirscadré=tirscadre;
 tab[team2].passes=passess;
 tab[tmp_team].recived=score2;
 tab[team2].recived=score1;
 yellowcardd[tmp_team]=yellowcard;
 redcardd[tmp_team]=redcard;
 yellowcardd[team2]=yellowcard;
 redcardd[team2]=redcard;
 differnceofgoals[tmp_team]=score1-score2;
 differnceofgoals[team2]=score2-score1;
 
 played[tmp_team][team2] = 1;
 played[team2][tmp_team] = 1;
 }
 matches_played++;
 }
 day++;
 int k ;
 printf("%*s", 50,"\033[1;35mDay Detail\033[0m");
 printf("\n");
sleep(1);
 for ( k = 0; k < n ; k++)
 {
 
 printf(" \n *%5s ||%5d tirs  ||%5d tirscadre ||%5d passes ||%5d horsjeux || \n ", tab[k].teamn , tab[k].tirs , tab[k].tirscadré , tab[k].passes,tab[k].horsjeux );
 
 } 
printf("\n");
printf("\n");
printf("\n");
printf("%*s", 50,"\033[1;35mfinal table\033[0m");
printf("\n");
sleep(3);

 
 trietableau(tab , n);
 sleep(1);
 for ( k = 0; k < n ; k++)
 {
 
 printf(" \n *%5d ||%5s ||%5d pts ||%5dgs ||%5dgr ||%5d ||\033[1;33m %5dcard\033[0m ||\033[1;31m %5dcard\033[0m \n ",k+1 , tab[k].teamn , tab[k].teamp , tab[k].goalsscored , tab[k].recived,differnceofgoals[k],yellowcardd[k],redcardd[k] );
 
 } 
 sleep(5);
 }
 printf("\n");
 printf("\n");
 printf("\n");
 
 printf("----------------------------congratulation for \033[1;33m%s\033[0m being the winner of yacine's fantasy------------------------------ \n",tab[0].teamn);
  return 0;
 }
 }