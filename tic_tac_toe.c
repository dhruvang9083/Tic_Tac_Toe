#include<stdio.h>
#include<conio.h>

int row,column;
char matrix[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void display()
 {

	for(row = 0; row < 3; row++)
        {
            for (column = 0; column < 3; column++)
             {
                printf("\t[%c]",matrix[row][column]);

             }
printf("\n");
        }
 }

char player = 'x';

void ChangeValue() {
	int num;
	printf("enter number between 1 to 9 to put your sign: ");
	scanf("%d",&num);

	if (num == 1)
		matrix[0][0] = player;
	else if (num == 2)
		matrix[0][1] = player;
	else if (num == 3)
		matrix[0][2] = player;
	else if (num == 4)
		matrix[1][0] = player;
	else if (num == 5)
		matrix[1][1] = player;
	else if (num == 6)
		matrix[1][2] = player;
	else if (num == 7)
		matrix[2][0] = player;
	else if (num == 8)
		matrix[2][1] = player;
	else if (num == 9)
		matrix[2][2] = player;

}

char whoWon() {
	for (row = 0; row < 3; row++)
        {
            if (matrix[row][0] == 'x' && matrix[row][1] == 'x' && matrix[row][2] == 'x')
            {
                return 'x';
                break;
            }
        }

	for (column = 0; column < 3; column++)
        {
            if (matrix[0][column] == 'x' && matrix[1][column] == 'x' && matrix[2][column] == 'x')
            {
                return 'x';
                break;
            }
        }

	if (matrix[0][0] == 'x' && matrix[1][1] == 'x' && matrix[2][2] == 'x')
		return 'x';

	if (matrix[0][2] == 'x' && matrix[1][1] == 'x' && matrix[2][0] == 'x')
		return 'x';

	for (row = 0; row < 3; row++) {
		if (matrix[row][0] == 'o' && matrix[row][1] == 'o' && matrix[row][2] == 'o') {
			return 'o';
			break;
		}
	}

	for (column = 0; column < 3; column++) {
		if (matrix[0][column] == 'o' && matrix[1][column] == 'o' && matrix[2][column] == 'o') {
			return 'o';
			break;
		}
	}

	if (matrix[0][0] == 'o' && matrix[1][1] == 'o' && matrix[2][2] == 'o')
		return 'o';

	if (matrix[0][2] == 'o' && matrix[1][1] == 'o' && matrix[2][0] == 'o')
		return 'o';
	return '/';
}

void togglePlayer() {
	if (player == 'x') {
		player = 'o';
	}
	else
		player = 'x';
}

int main() {
	display();
	int n = 0;
	while (n<9)
	{
		ChangeValue();
		display();
		if (whoWon() == 'x') {
			printf("Player 1 won");
			break;
		}
		else if(whoWon() == 'o'){
			printf("Player 2 won");
			break;
		}

		togglePlayer();
		n++;
	}

	if (whoWon() == '/') {
		printf("Match Drawn");
	}
	system("pause");
	return 0;
}
