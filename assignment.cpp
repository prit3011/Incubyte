#include <iostream>
using namespace std;

class Spacecraft {
private:
    int x, y, z; // Current coordinates (x, y, z)
    char direction; // Current direction (N, S, E, W, U, D)

public:
    // Constructor to initialize the spacecraft's starting position and direction
    Spacecraft(int startX, int startY, int startZ, char startDirection)
        : x(startX), y(startY), z(startZ), direction(startDirection) {}

    // Method to move the spacecraft forward
    void moveForward() {
        switch (direction) {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            case 'U':
                z++;
                break;
            case 'D':
                z--;
                break;
        }
    }

    // Method to move the spacecraft backward
    void moveBackward() {
        // Similar to moveForward, but with reversed direction
        switch (direction) {
            case 'N':
                y--;
                break;
            case 'S':
                y++;
                break;
            case 'E':
                x--;
                break;
            case 'W':
                x++;
                break;
            case 'U':
                z--;
                break;
            case 'D':
                z++;
                break;
        }
    }

    // Method to turn the spacecraft left
    void turnLeft() {
        switch (direction) {
            case 'N':
                direction = 'W';
                break;
            case 'S':
                direction = 'E';
                break;
            case 'E':
                direction = 'N';
                break;
            case 'W':
                direction = 'S';
                break;
        }
    }

    // Method to turn the spacecraft right
    void turnRight() {
        // Similar to turnLeft, but with reversed direction
        switch (direction) {
            case 'N':
                direction = 'E';
                break;
            case 'S':
                direction = 'W';
                break;
            case 'E':
                direction = 'S';
                break;
            case 'W':
                direction = 'N';
                break;
        }
    }

    // Method to turn the spacecraft up
    void turnUp() {
        if (direction == 'N' || direction == 'S') {
            direction = 'U';
        }
    }

    // Method to turn the spacecraft down
    void turnDown() {
        // Similar to turnUp, but with reversed direction
        if (direction == 'N' || direction == 'S') {
            direction = 'D';
        }
    }

    // Method to get the current position
    
    string getCurrentPosition() {
        return "(" + to_string(x) + ", " + to_string(y) + ", " + to_string(z) + ")";
    }

    // Method to get the current direction
    char getCurrentDirection() {
        return direction;
    }
};

int main() {
    Spacecraft spacecraft(0, 0, 0, 'N');
    string commands[] = {"f", "r", "u", "b", "l"};

    for (const string& command : commands) {
        if (command == "f") {
            spacecraft.moveForward();
        } else if (command == "b") {
            spacecraft.moveBackward();
        } else if (command == "r") {
            spacecraft.turnRight();
        } else if (command == "l") {
            spacecraft.turnLeft();
        } else if (command == "u") {
            spacecraft.turnUp();
        } else if (command == "d") {
            spacecraft.turnDown();
        }
    }

    cout << "Final Position: " << spacecraft.getCurrentPosition() << endl;
    cout << "Final Direction: " << spacecraft.getCurrentDirection() << endl;

    return 0;
}
