#include <iostream>
#include <cstdlib>
#include <ctime>

int generateRandomPoints() {
    return rand() % 10 + 1;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    int player1Score = 0;
    int player2Score = 0;

    bool player1Continues = true;
    bool player2Continues = true;

    while (true) {
        if (player1Continues) {
            int points = generateRandomPoints();
            std::cout << "Игрок 1 прибавляет " << points << " очков. Текущий счет: " << player1Score + points << std::endl;

            if (player1Score + points >= 20) {
                player1Continues = false;
            }
            else {
                std::cout << "Игрок 1, хотите продолжить игру? (1 - да, 0 - нет): ";
                std::cin >> player1Continues;
            }

            player1Score += points;
        }

        if (player2Continues) {
            int points = generateRandomPoints();
            std::cout << "Игрок 2 прибавляет " << points << " очков. Текущий счет: " << player2Score + points << std::endl;

            if (player2Score + points >= 20) {
                player2Continues = false;
            }
            else {
                std::cout << "Игрок 2, хотите продолжить игру? (1 - да, 0 - нет): ";
                std::cin >> player2Continues;
            }

            player2Score += points;
        }

        if ((!player1Continues && !player2Continues) || (player1Score >= 20 && player2Score >= 20)) {
            break;
        }
    }

    if (player1Score >= 20 && player2Score >= 20) {
        std::cout << "Ничья!" << std::endl;
    }
    else if (player1Score > 20) {
        std::cout << "Игрок 1 проиграл!" << std::endl;
    }
    else if (player2Score > 20) {
        std::cout << "Игрок 2 проиграл!" << std::endl;
    }
    else if (player1Score >= player2Score) {
        std::cout << "Игрок 2 проиграл!" << std::endl;
    }
    else if (player2Score >= player1Score) {
        std::cout << "Игрок 1 проиграл!" << std::endl;
    }

    return 0;
}

