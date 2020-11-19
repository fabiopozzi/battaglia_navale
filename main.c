#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>

int righe, colonne;

void create_player(void)
{
    char nome[100];
    printf("\tInserisci nome primo giocatore");
    scanf("%99s", nome);
}

void riempi_tabellone(void)
{

    printf("disegna tabellone");
}

void init_screen(void)
{
    initscr();
    getmaxyx(stdscr, righe, colonne); /* ottieni la dimensione del terminale */
    keypad(stdscr, TRUE);			/* permetti uso F1-F12 e tasti freccia */
    noecho();						/* no keyboard echo per l'input utente */
    mvprintw(righe/2, (colonne/2) - 15, "Battaglia navale v.0.0.1");
    refresh();
}

int main(int argc, char *argv[])
{
    init_screen();
    //create_player();
    //riempi_tabellone();
    //game_loop();

    getch();
    endwin();
    return 0;
}
