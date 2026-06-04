// Copy your code of Step 1 and extend it.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ship {
    char name[32];
    int x1;
    int y1;
    int x2;
    int y2;
    int hit;
};

void initialize(struct Ship * ships) {
    strcpy(ships[0].name, "Carrier");
    ships[0].x1 = 2;
    ships[0].y1 = 2;
    ships[0].x2 = 6;
    ships[0].y2 = 2;
    ships[0].hit = 0;

    strcpy(ships[1].name, "Battleship");
    ships[1].x1 = 3;
    ships[1].y1 = 4;
    ships[1].x2 = 3;
    ships[1].y2 = 7;
    ships[1].hit = 0;

    strcpy(ships[2].name, "Cruiser");
    ships[2].x1 = 7;
    ships[2].y1 = 4;
    ships[2].x2 = 9;
    ships[2].y2 = 4;
    ships[2].hit = 0;

    strcpy(ships[3].name, "Submarine");
    ships[3].x1 = 5;
    ships[3].y1 = 5;
    ships[3].x2 = 5;
    ships[3].y2 = 7;
    ships[3].hit = 0;
    
    strcpy(ships[4].name, "Destroyer");
    ships[4].x1 = 8;
    ships[4].y1 = 8;
    ships[4].x2 = 9;
    ships[4].y2 = 8;
    ships[4].hit = 0;
}

int isHit(struct Ship ship, int x, int y) {
if (x >= ship.x1 && x <= ship.x2 && y >= ship.y1 && y <= ship.y2) {
return 1;
}
return 0;
}

int isFinished(struct Ship * ships, int n) {
for (int i = 0; i < n; i++) {
if (ships[i].hit == 0) {
return 0;
}
}
return 1;
}

int main() {
struct Ship ships[5];
initialize(ships);
while (1) {
    int x, y;
    printf("Enter coordinates to attack (x y): ");
    scanf("%d %d", &x, &y);

    int hit = 0;
    for (int i = 0; i < 5; ++i) {
        if (isHit(ships[i], x, y)) {
            ships[i].hit = 1;
            hit = 1;
            printf("You hit a %s!\n", ships[i].name);
        }
    }
    if (!hit) {
        printf("miss\n");
    }

    if (isFinished(ships, 5)) {
        printf("All ships are sunk\n");
        break;
    }
}
return 0;
}
