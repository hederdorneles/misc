#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

char board[SIZE][SIZE];
char currentPlayer;

void initBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    currentPlayer = 'X';
}

void printBoard() {
    printf("\n 0 1 2\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool makeMove(int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return false;
    }
    if (board[row][col] != ' ') {
        return false;
    }
    board[row][col] = currentPlayer;
    return true;
}

bool checkWin() {
    // check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    // check columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    // check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

bool checkTie() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ')
                return false;
    }
}

int main() {
    initBoard();
    while (true) {
        printBoard();
        printf("\nJogador %c, qual é a sua jogada? (linha coluna)\n", currentPlayer);
        int row, col;
        scanf("%d %d", & row, & col);
        if (!makeMove(row, col)) {
            printf("Jogada inválida. Tente novamente.\n");
            continue;
        }
        if (checkWin()) {
            printf("\nJogador %c venceu!\n", currentPlayer);
            break;
        }
        if (checkTie()) {
            printf("\nEmpate!\n");
            break;
        }
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }
    return 0;
}
