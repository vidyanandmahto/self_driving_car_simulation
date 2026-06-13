#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

const int ROWS = 9;
const int COLS = 40;

const char ROAD = '.';
const char CAR = 'C';
const char OBSTACLE = 'X';
const char LANE = '|';

class Environment {
public:
    vector<vector<char>> grid;

    Environment() {
        grid.resize(ROWS, vector<char>(COLS, ROAD));

        // Lane dividers
        for (int i = 0; i < ROWS; i++) {
            grid[i][13] = LANE;
            grid[i][26] = LANE;
        }

        // Obstacles
        grid[4][15] = OBSTACLE;
        grid[2][20] = OBSTACLE;
        grid[6][30] = OBSTACLE;
    }

    bool obstacleAhead(int r, int c) {
        return (c + 1 < COLS && grid[r][c + 1] == OBSTACLE);
    }

    bool isObstacle(int r, int c) {
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS)
            return true;

        return grid[r][c] == OBSTACLE;
    }

    void draw(int carRow, int carCol) {

#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {

                if (i == carRow && j == carCol)
                    cout << CAR;
                else
                    cout << grid[i][j];
            }
            cout << endl;
        }
    }
};

class Car {
public:
    int row, col;

    Car() {
        row = 4;
        col = 0;
    }

    void move() {
        col++;
    }

    void changeLaneUp() {
        if (row >= 3)
            row -= 3;
    }

    void changeLaneDown() {
        if (row <= ROWS - 4)
            row += 3;
    }
};

int main() {

    Environment env;
    Car car;

    while (car.col < COLS - 1) {

        if (env.obstacleAhead(car.row, car.col)) {

            // Try upper lane first
            if (car.row >= 3 &&
                !env.isObstacle(car.row - 3, car.col + 1)) {

                car.changeLaneUp();
            }

            // Otherwise try lower lane
            else if (car.row <= ROWS - 4 &&
                     !env.isObstacle(car.row + 3, car.col + 1)) {

                car.changeLaneDown();
            }

            // No lane available
            else {
                cout << "\nCollision! No safe lane available.\n";
                return 0;
            }
        }

        car.move();
        env.draw(car.row, car.col);

        this_thread::sleep_for(chrono::milliseconds(200));
    }

    cout << "\nSimulation completed successfully.\n";

    return 0;
}