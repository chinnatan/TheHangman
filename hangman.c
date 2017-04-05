#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int rand_word();
int blankspace(int lens);
void screen_type();
void screen_start();

struct save
{
	char save[10][1000];
};

struct save read_vocab(int types)
{
	FILE *ptr_file;
    int i = 0, line = 5;
    struct save result;
    if(types == 1)
    {
    	ptr_file = fopen("./vocab/animals.txt","r");
	
	    while(line--){
		    fscanf(ptr_file,"%s", result.save[i]);
		    i++;
		}
	    fclose(ptr_file);
	}
	else if(types == 2)
    {
    	ptr_file = fopen("./vocab/fruits.txt","r");
	
	    while(line--){
		    fscanf(ptr_file,"%s", result.save[i]);
		    i++;
		}
	    fclose(ptr_file);
	}
	else if(types == 3)
    {
    	ptr_file = fopen("./vocab/occupations.txt","r");
	
	    while(line--){
		    fscanf(ptr_file,"%s", result.save[i]);
		    i++;
		}
	    fclose(ptr_file);
	}
    
    return result;
}

struct save read_hint(int types)
{
    FILE *ptr_file;
    int i = 0, line = 5;
    struct save result;
    if(types == 1)
    {
        ptr_file = fopen("./hint/animals.txt","r");
    
        while(line--){
            fscanf(ptr_file,"%[^\n]s", result.save[i]);
            i++;
        }
        fclose(ptr_file);
    }
    else if(types == 2)
    {
        ptr_file = fopen("./hint/fruits.txt","r");
    
        while(line--){
            fscanf(ptr_file,"%[^\n]s", result.save[i]);
            i++;
        }
        fclose(ptr_file);
    }
    else if(types == 3)
    {
        ptr_file = fopen("./hint/occupations.txt","r");
    
        while(line--){
            fscanf(ptr_file,"%[^\n]s", result.save[i]);
            i++;
        }
        fclose(ptr_file);
    }
    
    return result;
}

int rand_word()
{
	srand(time(NULL));
    int i, result_rand;
    result_rand = rand() % 10;
    return result_rand;
}

int main()
{
	int type, rands, len = 0, i = 0, count = 0, result = 0, flag = 0;
	char space = '_', bspace[10], check[10];
    struct save vocab, hint;
	screen_type();
	printf("\tChoose Type : ");
	scanf("%d", &type);
	system("cls");
	if(type >= 1 && type <= 3)
	{
		vocab = read_vocab(type);
		hint = read_hint(type);
		rands = rand_word();
		len = strlen(vocab.save[rands]);
		screen_start();
		printf("\t|");
		blankspace(len);
		for(i = 0;i < len;i++)
		{
			printf("%c ", space);
			bspace[i] = space;
		}
		blankspace(len);
		printf("|\n");
		printf("\t#####################\t\n");
		while(count < len)
		{
			printf("\n\tEnter a character : ");
			scanf("%s", check);
			printf("%s", check);
			for(i = 0;i < len;i++)
			{
				if (check[0] == vocab.save[rands][i])
		   		{
			   		bspace[i] = vocab.save[rands][i];
					flag = 1;
					result++;
				}
			}
			system("cls");
			screen_start();
			printf("\t|");
			blankspace(len);
			for(i = 0 ;i < len;i++)
				printf("%c ", bspace[i]);
			blankspace(len);
			printf("|\n");
			printf("\t#####################\t\n");
			if(flag == 0)
			{
				count++;
				printf("\n\n\n\t%c is a wrong guess", check[0]);
				printf("\n\n\n\t(you have %d more guesses)", len - count);
			}
			else
			{
				printf("\n\n\tyou are correct!!");
	   			printf("\n\t(you have %d more words to go)\n", len - result);
			}
			if(count > (len / 2))
				printf("\n\n\tHint : %s\n", hint.save[0]);
			if((result + count == len) || (count - result == len))
				break;
		}
        if(result == len)
            printf("\n\tYou Win, You want play again (y/n) ?");
        else
            printf("\n\tYou lose, You want play again (y/n) ?");
    }
    
    return 0;
}

void screen_type()
{
//	printf("\t#####################\t\n");
//	printf("\t#### The Hangman ####\t\n");
//	printf("\t#####################\t\n");
//	printf("\t#####################\t\n");
//	printf("\t## Choose Category ##\t\n");
//	printf("\t#####################\t\n");
//	printf("\t|-----1. Animals----|\t\n");
//	printf("\t|-----2. Fruits-----|\t\n");
//	printf("\t|---3. Occupation---|\t\n");
//	printf("\t#####################\t\n");
	system("MODE 150, 30");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
	printf("\t\t _	 _         _         _ _      _   _ _ _ _ _ _   _            _         _         _ _      _ \n");
	printf("\t\t| |	| |       / \\       |   \\    | | |  _ _ _ _ _| | \\          / |       / \\       |   \\    | |\n");
	printf("\t\t| |	| |      /   \\      | |\\ \\   | | | |           |  \\        /  |      /   \\      | |\\ \\   | |\n");
	printf("\t\t| |_ _ _| |     / / \\ \\     | | \\ \\  | | | |    _ _ _  |   \\      /   |     / / \\ \\     | | \\ \\  | |\n");
	printf("\t\t|  _ _ _  |    / /_ _\\ \\    | |  \\ \\ | | | |   |_ _  | | |\\ \\    / /| |    / /_ _\\ \\    | |  \\ \\ | |\n");
	printf("\t\t| |	| |   / _ _ _ _ \\   | |   \\ \\| | | |       | | | | \\ \\  / / | |   / _ _ _ _ \\   | |   \\ \\| |\n");
	printf("\t\t| |	| |  / /       \\ \\  | |    \\   | | |_ _ _ _| | | |  \\ \\/ /  | |  / /       \\ \\  | |    \\   |\n");
	printf("\t\t|_|	|_| /_/         \\_\\ |_|     \\_ | |_ _ _ _ _ _| |_|   \\__/   |_| /_/         \\_\\ |_|     \\_ |\n\n");
	printf("\t\t#####################################################################################################\n\n");
	printf("\t\t\t\t\t\t\t1. Animals\n");
	printf("\t\t\t\t\t\t\t2. Fruits\n");
	printf("\t\t\t\t\t\t\t3. Occupation\n\n");
	printf("\t\t#####################################################################################################\n\n");
}

void screen_start()
{
	printf("\t#####################\t\n");
	printf("\t#### The Hangman ####\t\n");
	printf("\t#####################\t\n");
	printf("\t#####################\t\n");
	printf("\t####### Start #######\t\n");
	printf("\t#####################\t\n");
}

int blankspace(int lens)
{
	int i;
	for(i = 0;i < 9 - lens;i++)
		printf(" ");
}
