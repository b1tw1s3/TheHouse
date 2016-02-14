#include <stdio.h>

int main()
{
	/*
		Rooms:
		00 01 02     
		10 11 12               
		20 21 22
		n => -10 | s => +10 | w => -1 | e => +1 

		X kitchen pantry
		X dinnig  bathroom
		X bedroom X
	*/

	unsigned int current_room = 11;
	char prompt = 'y';

	while ( prompt != 'q')
	{
		// Output
		switch (current_room)
		{
		case 11:
			printf("You are in the dinning room.\n");
			break;
		case 12:
			printf("You are in the bathroom.\n");
			break;
		case 01:
			printf("You are in the kitchen.\n");
			break;
		case 21:
			printf("You are in the bedroom.\n");
			break;
		case 02:
			printf("You are in the pantry.\n");
			break;
		}

		// Input
		printf("Which direction you want to go (n/s/e/w/q)? > ");
		prompt = getchar();
		fflush(stdin);

		// Movement Logic
		unsigned int new_room = current_room;
		switch (prompt)
		{
		case 'n':
			new_room -= 10;
			break;
		case 's':
			new_room += 10;
			break;
		case 'w':
			new_room -= 1;
			break;
		case 'e':
			new_room += 1;
			break;
		default:
			printf("Invalid Command!\n");
			break;
		}

		// Walkability
		if (new_room == 01 || new_room == 11 || new_room == 21 || new_room == 02 || new_room == 12)
			current_room = new_room;
		else
			printf("You can't go in that direction.\n");	
	}

	return 0;
}