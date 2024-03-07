#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <conio.h>
    #define CLEAR_SCREEN "cls"
#else
    #include <unistd.h>
    #include <termios.h>
    #define CLEAR_SCREEN "clear"
#endif

#include "getch.c"

#define SCREEN_SIZE 100

#define PLAYER_ICON 'A'

void clear_screen() {
    system(CLEAR_SCREEN);
}

void print_score(int score)
{
	printf("SCORE:       %d", score);
}

void print_enemys()
{
	for (int i=1; i<SCREEN_SIZE-1; i++)
	{
		printf("\n");
	}
}

void print_player(int player_pos_x)
{
	int empty_spaces_to_left = player_pos_x - 1;
    int empty_spaces_to_right = (SCREEN_SIZE - player_pos_x) - 1;

	for (int i = 0; i <= empty_spaces_to_left; i++) {
        printf(" ");
    }
    printf("%c", PLAYER_ICON);
    for (int i = 0; i < empty_spaces_to_right; i++) {
        printf(" ");
    }
    printf("\n");
}

void update_screen(int player_pos_x, int score) {
    clear_screen();
    
    print_score(score);
    print_enemys();
    print_player(player_pos_x);
    
}

void use_key(char key, int *player_pos_x) {
    if (key == 'a' && (*player_pos_x) > 0) {
        (*player_pos_x)--;
    } else if (key == 'd' && (*player_pos_x) < SCREEN_SIZE) {
        (*player_pos_x)++;
    }
}

void start_game() {
    char key;
    int player_pos_x = SCREEN_SIZE / 2;
    int score = 0;

    while (1) {
        update_screen(player_pos_x, score);
        key = getch();
        use_key(key, &player_pos_x);
    }
}

int main() {
    start_game();
    return 0;
}
