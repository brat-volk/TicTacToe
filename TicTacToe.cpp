#include <iostream>
#include <string>


int CheckPlayersTurn(int TurnNumber) {

    if (TurnNumber% 2 != 0) { 
        return 1; 
    }
    else { 
        return 2; 
    }
}

int main()
{
    while (1) {
        int TurnCounter = 1;
        int State = 0;
        int CheckBoard[9] = { 0,0,0,0,0,0,0,0,0 };

        while (1) {
            int PlayersTurn = CheckPlayersTurn(TurnCounter);
            int ChosenSpace;
            State = 3;
            input:

            std::cout << "Please, Player " << PlayersTurn << " choose a space from 1 to 9:";
            std::cin >> ChosenSpace;
            std::cout << std::endl;

            ChosenSpace = ChosenSpace - 1;
            if (CheckBoard[ChosenSpace] == 0) {
                CheckBoard[ChosenSpace] = PlayersTurn;
            }
            else {
                std::cout << "The space you selected has already been filled" << std::endl;
                goto input;
            }
            for (int s = 0; s < 8; s++) {
                if (CheckBoard[s] == 0) {
                    State = 0;
                }
            }
            for (int j = 0; j < 2; j++) {
                j = j * 3;
                if (CheckBoard[j] == PlayersTurn && CheckBoard[j] == CheckBoard[j + 1] && CheckBoard[j] == CheckBoard[j + 2]) {
                    State = PlayersTurn;
                }
            }
            for (int i = 0; i < 2; i++) {
                if (CheckBoard[i] == PlayersTurn && CheckBoard[i] == CheckBoard[i + 3] && CheckBoard[i] == CheckBoard[i + 6]) {
                    State = PlayersTurn;
                }
            }
            
            if (ChosenSpace % 2 == 0) {
                if (CheckBoard[0] == PlayersTurn && CheckBoard[0] == CheckBoard[4] && CheckBoard[0] == CheckBoard[8]) {
                    State = PlayersTurn;
                }
                if (CheckBoard[2] == PlayersTurn && CheckBoard[2] == CheckBoard[4] && CheckBoard[2] == CheckBoard[6]) {
                    State = PlayersTurn;
                }
            }

            for (int k = 0; k < 9; k++) {       
                int jk = k + 1;
                std::cout << CheckBoard[k] << " ";
                if (jk%3 == 0) {
                    std::cout << std::endl;
                }
            }    
            std::cout << std::endl;

            if (State != 0) {
                if (State == 3) {
                    std::cout << "Draw" << std::endl;
                    std::cin.ignore();
                    std::cin.get();
                    return 0;
                }
                std::cout << "Player " << State << " won" << std::endl;
                std::cin.ignore();
                std::cin.get();
                return 0;
            }
            TurnCounter++;
        }
    }
}