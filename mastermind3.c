/*Thomas Raynaud de Lage
trying to implement an algorithm to solve mastermind problems
inspiration https://www.youtube.com/watch?v=rmp05sCXTRg
*/

#define NUMBER_OF_COLORS 6
#define NUMBER_OF_HOLES 4
#define NUMBER_OF_TRIES 10
#define CORRECT 2
#define POSSIBLE 1
#define IMPOSSIBLE 0
#define TRUE 1
#define FALSE 0
#include <stdio.h>


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

};

int wrong_position_right_color;
int right_position_right_color;
int wrong_color;

struct Color colors[NUMBER_OF_COLORS];


int getFeedback(void){
	printf("how did I do?\n");
	printf("number of right color in right position: ");
	scanf("%d", &right_position_right_color);
	printf("\n");
	printf("number of right color in wrong position: ");
	scanf("%d", &wrong_position_right_color);
	printf("\n");
	printf("number of wrong color: ");
	scanf("%d", &wrong_color);
	printf("\n");
	return 0;
}

int printGuess(int first, int second, int third, int fourth){
	printf("My guess is: %s %s %s %s\n", colors[first].name, colors[second].name, colors[third].name,colors[fourth].name);
	return 0;

}

int main (void){


	int turn = 0;

	colors[0].name = "white";
	colors[1].name = "purple";
	colors[2].name = "yellow";
	colors[3].name = "green";
	colors[4].name = "red";
	colors[5].name = "blue";



	for (int i = 0; i < NUMBER_OF_COLORS; i++ ){
			colors[i].possible_number = NUMBER_OF_HOLES;
			colors[i].in_combination = FALSE;
		for(int j = 0; j < NUMBER_OF_HOLES; j++){
			colors[i].position[j] = POSSIBLE;
		}
	}

	for (int i = 0; i < NUMBER_OF_COLORS; i++ ){
		printf("Color %d is %s\n", i, colors[i].name);
	}

	int color_count = 0;//tracks the number of colors tried to loop through all of them if necessary
	int colors_found = 0;
	int answer[4];
	int base;
	int guesses[NUMBER_OF_TRIES][NUMBER_OF_HOLES];
	int pegs[NUMBER_OF_TRIES][3];

	for(int i = 0; i< NUMBER_OF_TRIES; i++){

	}
	
	while(turn < NUMBER_OF_TRIES){
	printf("this is turn %d\n", turn+1);

		if(turn == NUMBER_OF_COLORS && colors_found != NUMBER_OF_HOLES){//means at least 3 of one color that is not the base color

		}
		if(colors_found == NUMBER_OF_HOLES){//found all the colors not right order
			printf("FOUND ALL THE COLORS\n");
			for(int i = 0; i < NUMBER_OF_COLORS; i++){
				if(colors[i].in_combination){
					printf("%s in combination\n", colors[i].name);
					for(int j = 0; j< NUMBER_OF_HOLES; j++){
						if (colors[i].position[j] == CORRECT){
							answer[j] = i;//FININSH THIS////////////////////////////
						}
					}
				}
			}

		}
		else if(colors_found == 0){//loop guessing all the same color until at least one is found for the base
			printGuess(color_count,color_count,color_count,color_count);
			for(int i = 0; i < NUMBER_OF_HOLES; i++){
				guesses[turn][i] = color_count;
			}
			getFeedback();
			pegs[turn][0] = right_position_right_color;
			pegs[turn][1] = wrong_position_right_color;
			pegs[turn][2] = wrong_color;
			colors[color_count].definite_number = right_position_right_color;
			printf("There are %d %s\n", colors[color_count].definite_number, colors[color_count].name);
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
			pegs[turn][2] = wrong_color;

			if(colors[base].definite_number <=2){

				if(right_position_right_color + wrong_position_right_color > colors[base].definite_number){//works only if base color number <=2 
					
					//MIGHT BE 3 COLORS IN NEW TEST CHECK FOR THAT
					colors[color_count].in_combination = TRUE;
					colors[color_count].definite_number = right_position_right_color + wrong_position_right_color - colors[base].definite_number;//determine the number of occurences of a non-base
					colors_found += colors[color_count].definite_number;
					printf("there is %s in the code\n", colors[color_count].name);



				}
				else{//if the number of pegs is equal to the definite number of base color(1 or 2)
					colors[color_count].definite_number = 0;//if no extra pegs are added it means the color is not in the code
					printf("there is no %s in the code\n", colors[color_count].name);
					if(colors[base].definite_number == 1 && right_position_right_color == 1 ){//one base color and red peg -> left side
						colors[base].position[2] = IMPOSSIBLE;
						colors[base].position[3] = IMPOSSIBLE;

					}
					if(colors[base].definite_number == 1 && wrong_position_right_color == 1 ){//one base color and white peg ->right side
						colors[base].position[0] = IMPOSSIBLE;
						colors[base].position[1] = IMPOSSIBLE;

					}

					if(colors[base].definite_number == 2 && right_position_right_color == 2 ){//2 base color and 2 red peg ->1st and 2nd position
						colors[base].position[0] = CORRECT;
						colors[base].position[1] = CORRECT;
						colors[base].position[2] = IMPOSSIBLE;
						colors[base].position[3] = IMPOSSIBLE;

					}

					if(colors[base].definite_number == 2 && wrong_position_right_color == 2 ){//2 base color and 2 white peg -> 3rd and 4th position
						colors[base].position[0] = IMPOSSIBLE;
						colors[base].position[1] = IMPOSSIBLE;
						colors[base].position[2] = CORRECT;
						colors[base].position[3] = CORRECT;

					}





				}

			}
			else{//base color number = 3

				//Add this case


			}
		}
		
		
	
		if(right_position_right_color == NUMBER_OF_HOLES){
			printf("I win!\n");
			return 0;
		}
		if(colors_found != NUMBER_OF_HOLES){
			color_count++;
		}
		for(int i = 0; i<= turn; i ++){
			printf("GUESS %d: %s %s %s %s and Feedback %d red %d white %d none\n",i+1,colors[guesses[i][0]].name,colors[guesses[i][1]].name,colors[guesses[i][2]].name,colors[guesses[i][3]].name,pegs[i][0],pegs[i][1],pegs[i][2]);
		}
		turn++;

	}

	printf("I lose!");

}


