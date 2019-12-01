#include <stdio.h>

int main(){
  //3D array that holds each of the 9 digits as well as the negative symbol
  const char segments[11][3][3] =
  {{{' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'}},
  {{' ', ' ', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}},
  {{' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '}},
  {{' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'}},
  {{' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'}},
  {{' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'}},
  {{' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'}},
  {{' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}},
  {{' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'}},
  {{' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'}},
  {{' ', ' ', ' '}, {' ', '_', ' '}, {' ', ' ', ' '}}};
  char input = 'Y';
  //Program loops until user specifies to end it
  while (input == 'Y'){

    //Asks user to input an integer to display
    printf("Please input an integer to display: ");
    char integer[12];
    scanf("%s", integer);

    //Prints out the given integer in the format provided
    for (int j = 0; j < 3; j++){

      for (int i = 0; integer[i] != '\0'; i++){
        int x;
        if (integer[i] == '-'){
          x = 10;
        }

        else{
          x = integer[i] - '0';
        }

        for (int k = 0; k < 3; k++){
          printf("%c", segments[x][j][k]);
        }
      }
      printf("\n");
    }
    printf("Do you like to continue? Y/N: \n");
    scanf(" %c", &input);
  }
}
