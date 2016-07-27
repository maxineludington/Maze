//
//  main.cpp
//  Maze
//
//  Created by Maxine Ludington on 7/27/16.
//  Copyright © 2016 Maxine Ludington. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//using namespace std;

struct Position {
    int x;
    int y;
};
struct Position player, target, enemy1, enemy2, enemy3;

char direction1 = 1, direction2 = 1, direction3=1;
void DrawMap();
void HandleEnemy();
int Modulo(int nb, int mod);
bool gameOn = true;
void HandlePlayer(char input);
//void exit();

int main()
{
    //Initial positions
    player.x = 2, player.y = 5;
    target.x = 3, target.y = 0;
    enemy1.x = 0, enemy1.y = 1;
    enemy2.x = 5, enemy2.y = 3;
    enemy3.x = 2, enemy3.y = 7;
    //Game Loop
    while (gameOn) {
        DrawMap();
        char input;
        printf("Enter a choice: w, a, s, d or e(xit)\n");
        scanf("%c", &input);
        
        if (input == 'e') {
            //exit program
            goto Exit;
        }
        else {
            HandlePlayer(input);
            HandleEnemy();
            system("cls");
            
            if((player.x == enemy1.x && player.y == enemy1.y) || //collision wiht enemy
               (player.x == enemy2.x && player.y == enemy2.y)){
                printf("Sorry, you've failed.");
                goto Exit;
            }
            else if (player.x == target.x && player.y == target.y) { // reached target
                printf("You won!");
                goto Exit;
            }
            
        }
        
    }
Exit:
    printf("\n");
    //system("pause");
    return 0;
}

//void exit() {
//	printf("\n");
//	gameOn = false;
//}

void DrawMap() {
    int y = 0;
    for (y = 0; y < 6; y++) { //rows
        printf("\t-------------------\n");
        printf("\t");
        int x = 0;
        for (x = 0; x < 7; x++) { //columns
            printf(" |  ");
            if (x == target.x && y == target.y) {
                printf("T ");
            }
            else if (x == enemy1.x && y==enemy1.y) {
                printf(".-.");
            }
            else if (x == enemy2.x && y == enemy2.y) {
                printf(">.<");
            }
            else if (x == enemy3.x && y == enemy3.y) {
                    printf("~.~");
            }
            else if (x == player.x && y == player.y) {
                printf(" P");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\t-------------------\n");
    printf("\n");
}

void HandlePlayer(char input) {
    int tempx = player.x;
    int tempy = player.y;
    
    if (input == 'a'){
        tempx--;
    }
    if (input == 'd') {
        tempx++;
    }
    if (input == 'w') {
        tempy--;
    }
    if (input == 's') {
        tempy++;
    }
    
    player.x = Modulo(tempx, 6);
    player.y = Modulo(tempy, 6);
}

void HandleEnemy()
{
        //Enemy1
    
    if (direction1)
    {
        enemy1.x++;
    }
    else
    {
        enemy1.x--;
    }
    
    if (enemy1.x == 0 || enemy2.x >= 5)
    {
        direction1 = !direction1;
    }
   
        //Enemy2
    
    if (direction2)
    {
        enemy2.x -= 2;
    }
    else
    {
        enemy2.x += 2;
    }
    if (enemy2.x <= 0 || enemy2.x >= 5)
    {
        if (direction2)
        {
            enemy2.x++;
        }
        else
        {
            enemy2.x--;
        }
        direction2 = !direction2;
   
        //Enemy3
        
    if (direction3)
    {
        enemy3.x += 3;
    }
    else
    {
        enemy3.x -= 3;
    }
    if (enemy3.x >= 0 || enemy2.x <= 5)
    {
        if (direction3)
        {
            enemy3.x++;
        }
        else
        {
            enemy3.x--;
        }
        direction3 = !direction3;
    }
    }
    
}

int Modulo(int nb, int mod)
{
    if (nb < 0)
    {
        nb += mod;
    }
    return nb % mod;
}


