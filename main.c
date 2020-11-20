#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ncurses.h>
#include<time.h>

#define MSG_INIZIALE "Battaglia navale v 0.0.1"
#define NUM_RIGHE 10
#define NUM_COL 20
#define ROW_OFFSET 5
#define COL_OFFSET 6

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
    const int off_iniz_righe = 5;
    const int off_iniz_col = 6;

    clear(); // pulisci schermo
    /* intestazione colonne */
    for (c = 0; c < NUM_RIGHE; c++){
        mvprintw(off_iniz_righe - 1, off_iniz_col + (2 * c), lettera);
        lettera[0]++;
    }
    /* intestazione righe */
    lettera[0] = 'a';
    for (r = 0; r < NUM_RIGHE; r++){
        mvprintw(off_iniz_righe + r, off_iniz_righe - 1, lettera);
        lettera[0]++;
    }
}

void nave_orizzontale(char s[])
{
    int r, c;
    r = (rand() % NUM_RIGHE) + ROW_OFFSET;
    // prendi riga a caso
    c = (rand() % (NUM_COL - strlen(s))) + COL_OFFSET;
    // rendi numero pari
    c = (c % 2 == 0)? c : c + 1;
    mvprintw(r, c, s);
}

void disegna_navi()
{
    /* disegna nave da 2 */
    srand(time(NULL));

    nave_orizzontale("X X");
    nave_orizzontale("X X");
    nave_orizzontale("X X");

    nave_orizzontale("X X X");
    nave_orizzontale("X X X X");

    /* disegna nave da 3 in verticale */
    /*
    r = (rand()%(DIM_TAB - 3)) + row_offset;
    c = (rand()%DIM_TAB) + col_offset;
    mvprintw(r, c, "X");
    mvprintw(r + 1, c, "X");
    mvprintw(r + 2, c, "X");
    */
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
    disegna_navi();
    //game_loop();

    getch();
    endwin();
    return 0;
}
