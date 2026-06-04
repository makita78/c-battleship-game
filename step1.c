#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ship {
    char name[32];
    int left;
    int right;
    int hit;
};

void initialize(struct Ship * ships) {
    strcpy(ships[0].name, "Carrier");
    ships[0].left = 2;
    ships[0].right = 6;
    ships[0].hit = 0;

    strcpy(ships[1].name, "Submarine");
    ships[1].left = 15;
    ships[1].right = 17;
    ships[1].hit = 0;

    strcpy(ships[2].name, "Destroyer");
    ships[2].left = 8;
    ships[2].right = 9;
    ships[2].hit = 0;
}

int isHit(struct Ship ship, int pos) {
    if (pos >= ship.left && pos <= ship.right) {
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
    struct Ship ships[3];
    initialize(ships);

    while (1) {
        int pos = 0;
        printf("Enter a position to attack: ");
        scanf("%d", & pos);

        int hit = 0;
        for (int i = 0; i < 3; ++i) {
            if (isHit(ships[i], pos)) {
                ships[i].hit = 1;
                hit = 1;
                printf("You hit a %s!\n", ships[i].name);
            }
        }
        if (!hit) {
            printf("miss\n");
        }

        if (isFinished(ships, 3)) {
            printf("All ships are sunk\n");
            break;
        }
    }
    return 0;
}
