/**
 *  Вам необходимо построить поле для игры «Сапёр» по его конфигурации — высоте, ширине и
 *  координатам расставленных на нем мин.
 *  
 *  Вкратце напомним правила построения поля для игры «Сапёр»:
 *  
 *  * поле состоит из клеток с минами и пустых клеток;
 *  * клетки с миной обозначаются символом *;
 *  * пустые клетки содержат число от 0 до 8 — количество мин на соседних клетках.
 *  
 *  Формат ввода
 *  ------------
 *  В первой строке содержатся три числа:
 *  
 *  число m от 1 до 100 — количество строк на поле;
 *  число n от 1 до 100 — количество столбцов на поле;
 *  число k от 0 до mn — количество мин на поле.
 *  В следующих k строках содержатся пары чисел с координатами мин (номерами строки и столбца).
 *  Нумерация ведётся с единицы.
 *  
 *  Формат вывода
 *  -------------
 *  Выведите построенное поле, разделяя строки поля символом \n, а столбцы — пробелом.
 *  
 *  Ввод
 *  3 2 2
 *  1 1
 *  2 2
 *  Вывод
 *  * 2
 *  2 *
 *  1 1
 */

#include <iostream>
#include <vector>

#define MAGIC_MINE_NUMBER 42

int main() {
    int row, column, mines;
    std::cin >> row >> column >> mines;

    std::vector<std::vector<int>> field(row, std::vector<int>(column, 0));
    for (int m = 0; m < mines; m++) {
        int x, y;
        std::cin >> x >> y;
        field[x - 1][y - 1] = MAGIC_MINE_NUMBER;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (field[i][j] != MAGIC_MINE_NUMBER) {
                continue;
            }

            // 1. left top number
            if (i - 1 >= 0 && j - 1 >= 0) {
                if (field[i - 1][j - 1] != MAGIC_MINE_NUMBER) {
                    field[i - 1][j - 1] += 1;
                }
            }

            // 2. top number
            if (i - 1 >= 0) {
                if (field[i - 1][j] != MAGIC_MINE_NUMBER) {
                    field[i - 1][j] += 1;
                }
            }

            // 3. right top number
            if (i - 1 >= 0 && j + 1 < column) {
                if (field[i - 1][j + 1] != MAGIC_MINE_NUMBER) {
                    field[i - 1][j + 1] += 1;
                }
            }

            // 4. right number
            if (j + 1 < column) {
                if (field[i][j + 1] != MAGIC_MINE_NUMBER) {
                    field[i][j + 1] += 1;
                }
            }

            // 5. right bottom number
            if (i + 1 < row && j + 1 < column) {
                if (field[i + 1][j + 1] != MAGIC_MINE_NUMBER) {
                    field[i + 1][j + 1] += 1;
                }
            }

            // 6. bottom number
            if (i + 1 < row) {
                if (field[i + 1][j] != MAGIC_MINE_NUMBER) {
                    field[i + 1][j] += 1;
                }
            }

            // 7. left bottom number
            if (i + 1 < row && j - 1 >= 0) {
                if (field[i + 1][j - 1] != MAGIC_MINE_NUMBER) {
                    field[i + 1][j - 1] += 1;
                }
            }

            // 8. left number
            if (j - 1 >= 0) {
                if (field[i][j - 1] != MAGIC_MINE_NUMBER) {
                    field[i][j - 1] += 1;
                }
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (field[i][j] == MAGIC_MINE_NUMBER) {
                std::cout << "*";
            } else {
                std::cout << field[i][j];
            }

            if (j == column - 1) {
                std::cout << std::endl;
            } else {
                std::cout << " ";
            }
        }
    }
}
