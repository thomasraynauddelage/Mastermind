#define NUMBER_OF_COLORS 3
#define NUMBER_OF_HOLES 4
#define NUMBER_OF_TRIES 10
#define CORRECT 2
#define POSSIBLE 1
#define IMPOSSIBLE 0
#define TRUE 1
#define FALSE 0
#include <string.h>

//Implementation with only 3 colors, color mixing was a hastle, possibly extend on that later

struct Color
{
  int in_combination;
  char* name;
  /*possible positions is an array of 4 values representing the 4 possible positions in the 4 holes
  0000: color not in combination not used in practice since in_combination
  1111: color could be anywhere in combination
  1100:color is on the left side
  0011: color is on the right side
  1000:color is in the first position
  */
  int position[NUMBER_OF_HOLES];
  //the possible number of repetitions of the color in the combination
  int possible_number;
  //the number of possible
  int definite_number;
  int available_for_answer;
  int possible_spots;

};

int wrong_position_right_color;
int right_position_right_color;

struct Color colors[NUMBER_OF_COLORS];

  //int sensorRed = 0;
  //int sensorGreen = 1;
  //int sensorBlue = 2;
 
  int led1_red = 11;
  int led1_green = 12;
  int led1_blue = 13;
  
  int led2_red = 8;
  int led2_green = 9;
  int led2_blue = 10;
  
  int led3_red = 5;
  int led3_green = 6;
  int led3_blue = 7;
  
  int led4_red = 2;
  int led4_green = 3;
  int led4_blue = 4;

  //int motor = 15;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
 
  //pinMode(sensorRed, OUTPUT); //Red LED
 // pinMode(sensorGreen, OUTPUT); //Green LED 
 // pinMode(sensorBlue, OUTPUT); //Blue LED 
  
  pinMode(led1_red, OUTPUT); //Red LED
  pinMode(led1_green, OUTPUT); //Green LED 
  pinMode(led1_blue, OUTPUT); //Blue LED 
  
  pinMode(led2_red, OUTPUT); //Red LED
  pinMode(led2_green, OUTPUT); //Green LED 
  pinMode(led2_blue, OUTPUT); //Blue LED 

  pinMode(led3_red, OUTPUT); //Red LED
  pinMode(led3_green, OUTPUT); //Green LED 
  pinMode(led3_blue, OUTPUT); //Blue LED 

  pinMode(led3_red, OUTPUT); //Red LED
  pinMode(led3_green, OUTPUT); //Green LED 
  pinMode(led3_blue, OUTPUT); //Blue LED 

   //pinMode(motor, OUTPUT); //motor 

}

int getFeedback(void){
  /*printf("how did I do?\n");
  printf("number of right color in right position: ");
  scanf("%d", &right_position_right_color);
  printf("\n");
  printf("number of right color in wrong position: ");
  scanf("%d", &wrong_position_right_color);
  printf("\n");
  return 0;*/

  delay(5000);
  right_position_right_color = 0;
  wrong_position_right_color = 0;
  digitalWrite(led1_red,LOW);
  digitalWrite(led1_green,LOW);
  digitalWrite(led1_blue,LOW);
  
}

int printGuess(int first, int second, int third, int fourth){
  //printf("My guess is: %s %s %s %s\n", colors[first].name, colors[second].name, colors[third].name,colors[fourth].name);
  //LIGHT THE GUESSES
      Serial.println("Values: ");
      Serial.print(first);
      Serial.print(second);
      Serial.print(third);
      Serial.print(fourth);
      
      
      digitalWrite(led1_red,LOW);
      digitalWrite(led1_green,LOW);
      digitalWrite(led1_blue,LOW);

      digitalWrite(led2_red,LOW);
      digitalWrite(led2_green,LOW);
      digitalWrite(led2_blue,LOW);
      
      digitalWrite(led3_red,LOW);
      digitalWrite(led3_green,LOW);
      digitalWrite(led3_blue,LOW);
      
      digitalWrite(led4_red,LOW);
      digitalWrite(led4_green,LOW);
      digitalWrite(led4_blue,LOW);
      delay(1000);
      


      //FIRST LED
      if(strcmp(colors[first].name, "white")==0){//first LED white
      digitalWrite(led1_red,HIGH);
      digitalWrite(led1_green,HIGH);
      digitalWrite(led1_blue,HIGH);
 
      }
      else if(strcmp(colors[first].name, "purple") == 0){//first LED purple
        digitalWrite(led1_red,HIGH);
        digitalWrite(led1_blue,HIGH);
      }
      else if(strcmp(colors[first].name, "yellow") == 0){//first LED yellow
        digitalWrite(led1_red,HIGH);
        digitalWrite(led1_green,HIGH);
      }

      else if(strcmp(colors[first].name, "green") == 0){//first LED green
        digitalWrite(led1_green,HIGH);
      }
      else if(strcmp(colors[first].name, "red") == 0){//first LED red
        digitalWrite(led1_red,HIGH);
      }
      else if(strcmp(colors[first].name, "blue") == 0){//first LED blue
        digitalWrite(led1_blue,HIGH);
      }

       //SECOND LED
      if(strcmp(colors[first].name, "white")==0){//second LED white
      digitalWrite(led2_red,HIGH);
      digitalWrite(led2_green,HIGH);
      digitalWrite(led2_blue,HIGH);
 
      }
      else if(strcmp(colors[first].name, "purple") == 0){//second LED purple
        digitalWrite(led2_red,HIGH);
        digitalWrite(led2_blue,HIGH);
      }
      else if(strcmp(colors[first].name, "yellow") == 0){//second LED yellow
        digitalWrite(led2_red,HIGH);
        digitalWrite(led2_green,HIGH);
      }

      else if(strcmp(colors[first].name, "green") == 0){//second LED green
        digitalWrite(led2_green,HIGH);
      }
      else if(strcmp(colors[first].name, "red") == 0){//second LED red
        digitalWrite(led2_red,HIGH);
      }
      else if(strcmp(colors[first].name, "blue") == 0){//second LED blue
        digitalWrite(led2_blue,HIGH);
      }
       //THIRD LED
      if(strcmp(colors[first].name, "white")==0){//third LED white
      digitalWrite(led3_red,HIGH);
      digitalWrite(led3_green,HIGH);
      digitalWrite(led3_blue,HIGH);
 
      }
      else if(strcmp(colors[first].name, "purple") == 0){//third LED purple
        digitalWrite(led3_red,HIGH);
        digitalWrite(led3_blue,HIGH);
      }
      else if(strcmp(colors[first].name, "yellow") == 0){//third LED yellow
        digitalWrite(led3_red,HIGH);
        digitalWrite(led3_green,HIGH);
      }

      else if(strcmp(colors[first].name, "green") == 0){//third LED green
        digitalWrite(led3_green,HIGH);
      }
      else if(strcmp(colors[first].name, "red") == 0){//third LED red
        digitalWrite(led3_red,HIGH);
      }
      else if(strcmp(colors[first].name, "blue") == 0){//third LED blue
        digitalWrite(led3_blue,HIGH);
      }
       //FOURTH LED
      if(strcmp(colors[first].name, "white")==0){//fourth LED white
      digitalWrite(led4_red,HIGH);
      digitalWrite(led4_green,HIGH);
      digitalWrite(led4_blue,HIGH);
 
      }
      else if(strcmp(colors[first].name, "purple") == 0){//fourth LED purple
        digitalWrite(led4_red,HIGH);
        digitalWrite(led4_blue,HIGH);
      }
      else if(strcmp(colors[first].name, "yellow") == 0){//fourth LED yellow
        digitalWrite(led4_red,HIGH);
        digitalWrite(led4_green,HIGH);
      }

      else if(strcmp(colors[first].name, "green") == 0){//fourth LED green
        digitalWrite(led4_green,HIGH);
      }
      else if(strcmp(colors[first].name, "red") == 0){//fourth LED red
        digitalWrite(led4_red,HIGH);
      }
      else if(strcmp(colors[first].name, "blue") == 0){//fourth LED blue
        digitalWrite(led4_blue,HIGH);
      }
    
  
  

  return 0;

}




void loop() {
  // put your main code here, to run repeatedly:
  int turn = 0;

//RANDOMIZE THE COLORS
  /*colors[0].name = "white";
  colors[1].name = "purple";
  colors[2].name = "yellow";
  colors[3].name = "green";
  colors[4].name = "red";
  colors[5].name = "blue";
*/

colors[0].name = "red";
colors[1].name = "green";
colors[2].name = "blue";


  for (int i = 0; i < NUMBER_OF_COLORS; i++ ){
      colors[i].possible_number = NUMBER_OF_HOLES;
      colors[i].definite_number = 0;
      colors[i].in_combination = FALSE;
      colors[i].possible_spots = NUMBER_OF_HOLES;
    for(int j = 0; j < NUMBER_OF_HOLES; j++){
      colors[i].position[j] = POSSIBLE;
    }
  }

  //for (int i = 0; i < NUMBER_OF_COLORS; i++ ){
    //printf("Color %d is %s\n", i, colors[i].name);
  //}

  int color_count = 0;//tracks the number of colors tried to loop through all of them if necessary
  int colors_found = 0;//tracks the number of colors found in the code
  int answer[4];
  int base;
  int guesses[NUMBER_OF_TRIES][NUMBER_OF_HOLES];
  int pegs[NUMBER_OF_TRIES][2];
  int min_rprc;
  int min_rpwc;
  int three_occurences;
  int tried_ABAB = FALSE;
  int tried_ABBA = FALSE;
  int tried_BAAB = FALSE;
  
  while(turn < NUMBER_OF_TRIES){

  //printf("\nTURN %d\n\n", turn+1);
  //TESTING PURPOSES, CHANGE THAT
  if(turn == 3){
    turn = 0;
  }

    if(turn == NUMBER_OF_COLORS && colors_found != NUMBER_OF_HOLES){//means at least 3 occurences of one color that is not the base color
      //printf("MUST BE ONE COLOR 3 OCCCURENCES\n");
      for(int i = 0; i < NUMBER_OF_COLORS; i ++){
        if(colors[i].possible_number == 3){
          colors[i].definite_number = 3;
          colors_found = NUMBER_OF_HOLES;
          three_occurences = TRUE;

        }
      }

    }
    if(colors_found == NUMBER_OF_HOLES){//found all the colors not right order
      //printf("FOUND ALL THE COLORS\n");

      
      for(int i = 0; i< NUMBER_OF_COLORS; i++){//specific case where it is later determined that there are 2 occurences of a color and not 3
        if(colors[i].possible_number == 3 && colors[i].definite_number == 0 ){
          colors[i].definite_number = 2;
        }
      }

      //BEFORE
      /*for(int i = 0; i < NUMBER_OF_COLORS; i++){//First we assign all the spots we know are correct
        if(colors[i].in_combination){
          printf("%s in combination\n", colors[i].name);
          for(int j = 0; j< NUMBER_OF_HOLES; j++){
            printf(" BEFORE FOR COLOR %s postion %d is %d\n", colors[i].name,j,colors[i].position[j]);
            
          }

        }
      }*/

      if(!three_occurences){
        //remove some potential guesses based on
        min_rprc = NUMBER_OF_HOLES;//find the minimum number of red pegs in guesses with base,base,color_count,color_count
        min_rpwc = NUMBER_OF_HOLES;//find the minimum number of white pegs in guesses with base,base,color_count,color_count

        for(int i = 0; i < NUMBER_OF_COLORS; i++){
          if(colors[i].in_combination){
            if(pegs[i][0] < min_rprc){
              min_rprc = pegs[i][0];
            }
            if(pegs[i][1] < min_rpwc){
              min_rpwc = pegs[i][1];
            }         

          }
        }

        //CHECK THIS PART ADDED BASE CASE

        for(int i = 0; i < NUMBER_OF_COLORS; i++){//remove possibilities based on previous cases compared to the base case
          if(colors[i].in_combination){
            if(pegs[i][0]-min_rprc>0 && pegs[i][1] == min_rpwc && i!=base){//must be on right side
              colors[i].position[0] = IMPOSSIBLE;
              colors[i].position[1] = IMPOSSIBLE;
              colors[i].possible_spots = 2;
            }
            if(pegs[i][1]-min_rpwc>0 && pegs[i][0] == min_rprc && pegs[i][0]<2 && i!=base){//must be on the left side CHECK THIS
              colors[i].position[2] = IMPOSSIBLE;
              colors[i].position[3] = IMPOSSIBLE;
              colors[i].possible_spots = 2;
            }
          }
        }
      }

      for(int i = 0; i< NUMBER_OF_HOLES; i++){
        answer[i] = -1;
      }
      for(int i = 0; i < NUMBER_OF_COLORS; i++){//First we assign all the spots we know are correct
        if(colors[i].in_combination){
          colors[i].available_for_answer = colors[i].definite_number;
          //printf("%s in combination\n", colors[i].name);
          for(int j = 0; j< NUMBER_OF_HOLES; j++){
            //printf("FOR COLOR %s postion %d is %d\n", colors[i].name,j,colors[i].position[j]);
            if (colors[i].position[j] == CORRECT){
              //printf("Found correct position for %s at position %d\n",colors[i].name, j);
              answer[j] = i;
              colors[i].available_for_answer--;
            }
          }

        }
      }
      for(int i = 0; i < NUMBER_OF_COLORS; i++){//Then we assign possible colors to the remaining spots  when 2 possible spots
        if(colors[i].in_combination){
          //printf("Checking color: %s ", colors[i].name);
          for(int j = 0; j< NUMBER_OF_HOLES; j++){
            if (colors[i].position[j] == POSSIBLE && answer[j] == -1 && colors[i].available_for_answer>0 && colors[i].possible_spots == 2){//assign first those that only have 2 possible spots to avoid being stuck with an impossible spot
              //printf("trying %s at position %d\n", colors[i].name, j);
              answer[j] = i;
              colors[i].available_for_answer--;
            }
          }

        }
      }

      for(int i = 0; i < NUMBER_OF_COLORS; i++){//Then we assign possible colors to the remaining spots when 4 possible spots 
        if(colors[i].in_combination){
          //printf("Checking color: %s ", colors[i].name);
          for(int j = 0; j< NUMBER_OF_HOLES; j++){
            if (colors[i].position[j] == POSSIBLE && answer[j] == -1 && colors[i].available_for_answer>0 && colors[i].possible_spots == 4){//assign the rest (the colors that have 4 possible spots)
              //printf("trying %s at position %d\n", colors[i].name, j);
              answer[j] = i;
              colors[i].available_for_answer--;
            }
          }

        }
      }

      int colors_in_answer[2];
      int sum_colors = 0;
      int sum_possibilities = 0;
      


      for(int i = 0; i<NUMBER_OF_COLORS;i++){
        if(colors[i].in_combination){
          if(colors[i].definite_number==2){
            //printf("%s definitely 2\n",colors[i].name);
            sum_colors ++;
            sum_possibilities+=colors[i].possible_spots;
          }
        }
      }
      if(sum_colors==2 && sum_possibilities ==4 ){//2 colors 2 occurrences split half half AABB or BBAA
        //printf("It Worked AABB\n");

      }
      

      else if(sum_colors==2 && sum_possibilities==8){// 2 colors 2 occurrences ABAB ABBA BAAB BABA
        //printf("IT Worked ABAB\n");
        if(pegs[turn-1][1] == NUMBER_OF_HOLES){//try BABA and BAAB
          answer[0] = guesses[turn-1][1];
          answer[1] = guesses[turn-1][0];
          answer[2] = guesses[turn-1][3]; 
          answer[3] = guesses[turn-1][2];

        }
        else if(!tried_ABAB){//ABAB
          
          answer[0] = guesses[turn-1][0];
          answer[1] = guesses[turn-1][2];
          answer[2] = guesses[turn-1][1]; 
          answer[3] = guesses[turn-1][3];
          tried_ABAB = TRUE;
        }
        else if( !tried_ABBA){//ABBA
          answer[0] = guesses[turn-2][0];
          answer[1] = guesses[turn-2][2];
          answer[2] = guesses[turn-2][3]; 
          answer[3] = guesses[turn-2][1];


        }

      }
      else{
        if(pegs[turn-1][0] == 2 && pegs[turn-1][1] == 2 && guesses[turn-1][0] != guesses[turn-1][1] && guesses[turn-1][0] != guesses[turn-1][1]){//check if 2 base first
          //try switching the position of the first 2
          answer[0] = guesses[turn-1][1];
          answer[1] = guesses[turn-1][0];
          answer[2] = guesses[turn-1][2]; 
          answer[3] = guesses[turn-1][3];

        } 
        else if (pegs[turn-1][0] == 2 && pegs[turn-1][1] == 2 /*&& tried_left_side*/){
          answer[0] = guesses[turn-1][0];
          answer[1] = guesses[turn-1][1];
          answer[2] = guesses[turn-1][3]; 
          answer[3] = guesses[turn-1][2]; 
        }
        else if(pegs[turn-1][1] == NUMBER_OF_HOLES){
          //change positions for both left and right side
          answer[0] = guesses[turn-1][1];
          answer[1] = guesses[turn-1][0];
          answer[2] = guesses[turn-1][3]; 
          answer[3] = guesses[turn-1][2];

        }
      }
      printGuess(answer[0],answer[1],answer[2],answer[3]);
      guesses[turn][0] = answer[0];
      guesses[turn][1] = answer[1];
      guesses[turn][2] = answer[2];
      guesses[turn][3] = answer[3];

      getFeedback();
      pegs[turn][0] = right_position_right_color;
      pegs[turn][1] = wrong_position_right_color;


    }
    else if(colors_found == 0){//loop guessing all the same color until at least one is found for the base
      printGuess(color_count,color_count,color_count,color_count);
      for(int i = 0; i < NUMBER_OF_HOLES; i++){
        guesses[turn][i] = color_count;
      }
      getFeedback();
      pegs[turn][0] = right_position_right_color;
      pegs[turn][1] = wrong_position_right_color;
      colors[color_count].definite_number = right_position_right_color;
      //printf("There are %d %s\n", colors[color_count].definite_number, colors[color_count].name);
      colors_found = colors[color_count].definite_number;
      if(colors_found!=0){//as soon as one color is found it becomes the base
        base = color_count;
        colors[base].in_combination = TRUE;
        //for(int i =0; i<)
      }

    }
    else{//a base color has been found
      printGuess(base,base,color_count,color_count);
      guesses[turn][0] = base;
      guesses[turn][1] = base;
      guesses[turn][2] = color_count;
      guesses[turn][3] = color_count;

      getFeedback();

      pegs[turn][0] = right_position_right_color;
      pegs[turn][1] = wrong_position_right_color;

      if(colors[base].definite_number <=2){

        if(right_position_right_color + wrong_position_right_color > colors[base].definite_number){//works only if base color number <=2 
          
          if(right_position_right_color+wrong_position_right_color == 3 && colors[base].definite_number == 1){
            colors[color_count].in_combination = TRUE;
            colors[color_count].possible_number = 3;//might be 3 occurences of the color
            colors_found += right_position_right_color + wrong_position_right_color - colors[base].definite_number;//just add 2 to colrs_found counter as it is not sure
            //printf("might be 3\n");
          }
          //MIGHT BE 3 COLORS IN NEW TEST CHECK FOR THAT
          else{
            colors[color_count].in_combination = TRUE;
            colors[color_count].definite_number = right_position_right_color + wrong_position_right_color - colors[base].definite_number;//determine the number of occurences of a non-base
            colors_found += colors[color_count].definite_number;
          }
            //printf("there is %s in the code\n", colors[color_count].name);



        }
        else{//if the number of pegs is equal to the definite number of base color(1 or 2)
          colors[color_count].definite_number = 0;//if no extra pegs are added it means the color is not in the code
          //printf("there is no %s in the code\n", colors[color_count].name);
          if(colors[base].definite_number == 1 && right_position_right_color == 1 ){//one base color and red peg -> left side
            colors[base].position[2] = IMPOSSIBLE;
            colors[base].position[3] = IMPOSSIBLE;
            colors[base].possible_spots = 2;

          }
          if(colors[base].definite_number == 1 && wrong_position_right_color == 1 ){//one base color and white peg ->right side
            colors[base].position[0] = IMPOSSIBLE;
            colors[base].position[1] = IMPOSSIBLE;
            colors[base].possible_spots = 2;

          }

          if(colors[base].definite_number == 2 && right_position_right_color == 2 ){//2 base color and 2 red peg ->1st and 2nd position
            colors[base].position[0] = CORRECT;
            colors[base].position[1] = CORRECT;
            colors[base].position[2] = IMPOSSIBLE;
            colors[base].position[3] = IMPOSSIBLE;
            colors[base].possible_spots = 2;

          }

          if(colors[base].definite_number == 2 && wrong_position_right_color == 2 ){//2 base color and 2 white peg -> 3rd and 4th position
            colors[base].position[0] = IMPOSSIBLE;
            colors[base].position[1] = IMPOSSIBLE;
            colors[base].position[2] = CORRECT;
            colors[base].position[3] = CORRECT;
            colors[base].possible_spots = 2;

          }





        }

      }
      else{//base color number = 3
        //printf("BASE IS 3");
        three_occurences = TRUE;

        //Add this case
        if(right_position_right_color == 1){ //guarantees 2 occurences of the color are on the right side
          colors[base].position[2] = CORRECT;
          colors[base].position[3] = CORRECT;


        }
        if(right_position_right_color == 2 && wrong_position_right_color == 0){//guarantees 2 occurences of the color on the left side
          colors[base].position[0] = CORRECT;
          colors[base].position[1] = CORRECT;
        }
        if(right_position_right_color+wrong_position_right_color>2){//found the last color in combination
          //printf("FOUND LAST COLOR\n");
          colors[color_count].in_combination = TRUE;
          colors[color_count].definite_number = 1;
          colors_found += colors[color_count].definite_number;
      

        }


      }
    }
    
    
  
    if(right_position_right_color == NUMBER_OF_HOLES){
     // printf("I win!\n");
     // return 0;
    }
    if(colors_found != NUMBER_OF_HOLES){
      color_count++;
    }
   // for(int i = 0; i<= turn; i ++){
   //   printf("GUESS %d: %s %s %s %s and Feedback %d red %d white\n",i+1,colors[guesses[i][0]].name,colors[guesses[i][1]].name,colors[guesses[i][2]].name,colors[guesses[i][3]].name,pegs[i][0],pegs[i][1]);
   // }
    turn++;

  }

//I lose
  printf("I lose!");



  

}
