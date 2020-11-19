#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ncurses.h>

#define MSG_INIZIALE "Battaglia navale v 0.0.1"

int righe, colonne;

void create_player(void)
{
    char nome[100];
    printf("\tInserisci nome primo giocatore");
    scanf("%99s", nome);
}

void riempi_tabellone(void)
{
    int r, c;
    char lettera[] = "0";
    const int dim_tab = 10;
    const int off_iniz_righe = 5;
    const int off_iniz_col = 5;

    clear(); // pulisci schermo
    /* intestazione colonne */
    for (c = 0; c < dim_tab; c++){
        mvprintw(off_iniz_righe - 1, off_iniz_col + (2 * c), lettera);
        lettera[0]++;
    }
    /* intestazione righe */
    lettera[0] = 'a';
    for (r = 0; r < dim_tab; r++){
        mvprintw(off_iniz_righe + r, off_iniz_righe - 1, lettera);
        lettera[0]++;
    }
}

void init_screen(void)
{
    initscr();
    getmaxyx(stdscr, righe, colonne); /* ottieni la dimensione del terminale */
    keypad(stdscr, TRUE);			/* permetti uso F1-F12 e tasti freccia */
    noecho();						/* no keyboard echo per l'input utente */
    int col_messaggio = (colonne/2) - (strlen(MSG_INIZIALE) / 2);
    mvprintw(righe/2, col_messaggio, MSG_INIZIALE);
    refresh();
}

int main(int argc, char *argv[])
{
    init_screen();
    getch();
    //create_player();
    riempi_tabellone();
    //game_loop();

    getch();
    endwin();
    return 0;
}
