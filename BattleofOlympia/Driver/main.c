#include "corefiles.h"
#include "commands.h"
#include "adt.h"

#include <stdio.h>
#include <string.h>

boolean gameOver;
Stack S_moves;

int main () {
    int n, m;
    char colors[] = {'1', '2'};
    printf("Enter map size: ");
    scanf("%d %d", &n, &m);
    CreateMap(n, m);
    CreatePlayers(2, colors);
    CreateQueue(2);

    POINT coordinates[] = {{1, 2}, {5, 5}};
    InitializeMap(2, coordinates, n*m/15);
    InitializePlayers(2, coordinates);
    InitializeQueue(2);

    PrintMap();
    printf("\n");
    EndTurn();

    char command[11];
    do {
        printf("Your input: ");
        scanf(" %s", command);
        if (!strcmp(command, "MOVE")) {
            Move(GetSelectedUnit());
        } else if (!strcmp(command, "UNDO")) {

        } else if (!strcmp(command, "CHANGE_UNIT")) {
            ChangeUnit(GetCurrentPlayer());
        } else if (!strcmp(command, "RECRUIT")) {
            RecruitUnit(GetCurrentPlayer(), GetSelectedUnit());
        } else if (!strcmp(command, "ATTACK")) {
            Attack(GetSelectedUnit());
        } else if (!strcmp(command, "MAP")) {
            PrintMap();
        } else if (!strcmp(command, "INFO")) {
            PrintInfoGame();
        } else if (!strcmp(command, "END_TURN")) {
            EndTurn();
        } else if (!strcmp(command, "SAVE")) {
            printf("We don't have save feature. Heckin' bamboozled.\n");
        } else {
            printf("Invalid input\n");
        }
    } while (strcmp(command, "EXIT"));

    return 0;
}