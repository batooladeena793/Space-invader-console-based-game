#include <iostream>
#include <conio.h>
#include <windows.h>
#include<fstream>
using namespace std;
char box = 219;
char head = 153;
int bulletX[100];
int bulletY[100];
int bulletCount = 0;
int shooterX = 2;
int shooterY = 26;
char en[2][3]{
    {'<', head, '>'},
    {'/', '|', '\\'}};
int enBulletX[100];
int enBulletY[100];
int enBulletCount = 0;
int enemy1X = 6;
int enemy1Y = 6;
string enemyDirection1 = "down";
int timer = 0;
char en2[3][3]{
    {box, box, box},
    {' ', box, ' '},
    {' ', box, ' '}};
int en2BulletX[100];
int en2BulletY[100];
int en2BulletCount = 0;
int enemy2X = 85;
int enemy2Y = 4;
string enemyDirection2 = "left";
int timer1 = 0;
char en3[2][3]{
    {'<', head, '>'},
    {'/', '|', '\\'}};
int en3BulletX[100];
int en3BulletY[100];
int en3BulletCount = 0;
int enemy3X = 123;
int enemy3Y = 4;
string enemyDirection3 = "down";
int timer2 = 0;
int score = 0;
int highscore=0;
int health = 50;
int check = 0;
int check1 = 0;
int check2 = 0;
int e1Helth = 10;
int e2Helth = 10;
int e3Helth = 05;

// game Functions
string mainMenu();
void start();
void instructions();
void clearScreen();
void printLogo();
void printMaze();
void printSpaceship();
void gameOver();
void won();

// windows.h
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);

// player functions
void Spaceship();
void eraseSpaceship();
void moveSpLeft();
void moveSpRight();
void removeBulletFromArray(int index);

// Enemy function
void printEnemy1();
void moveEnemy1();
void eraseEnemy1();
void printEnemy2();
void moveEnemy2();
void eraseEnemy2();
void printEnemy3();
void moveEnemy3();
void eraseEnemy3();

//  Player Bullets functions
void generateBullet();
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void moveBullet();
void bulletCollisionWithEnemy1();
void bulletCollisionWithEnemy2();
void bulletCollisionWithEnemy3();

// enemy bullets functions
void generateEnemy1Bullet();
void printEnBullet(int x, int y);
void eraseEnBullet(int x, int y);
void moveEnBullet();
void en1Collision();
void removeEnBulletFromArray(int idx);
void generateEnemy2Bullet();
void moveEn2Bullet();
void removeEn2BulletFromArray(int idx);
void en2Collision();
void generateEnemy3Bullet();
void moveEn3Bullet();
void removeEn3BulletFromArray(int idx);
void en3Collision();
// scores Functions
void addScore();
void printScore();
void loadScore();
void saveScore();
// health Functions
void printHealth();
void remHelth();
void en1H();
void en2H();
void en3H();

 int main()
{
    string menuCount = "0";
    while (menuCount != "3")
    {
        printLogo();
        Sleep(300);
        printSpaceship();
        menuCount = mainMenu();
        if (menuCount == "1")
        {
            system("cls");
            start();
        }
        else if (menuCount == "2")
        {
            system("cls");
            printLogo();
            printSpaceship();
            instructions();
        }
    }
    clearScreen();
}

void printLogo()
{

cout << "\t\t\t\t\t\t\t\t\t\t  #####   ######     #     #####   #######                      " << endl;
cout << "\t\t\t\t\t\t\t\t\t\t #     #  #     #   # #   #     #  #                          " << endl;
cout << "\t\t\t\t\t\t\t\t\t\t #        #     #  #   #  #        #                          " << endl;
cout << "\t\t\t\t\t\t\t\t\t\t #####    ######  #     # #        #####                      " << endl;
cout << "\t\t\t\t\t\t\t\t\t\t      #  #        ####### #        #                          " << endl;
cout << "\t\t\t\t\t\t\t\t\t\t      #  #        #      ##      # #                        " << endl;
cout << "\t\t\t\t\t\t\t\t\t\t #####   #        #      # #####   #######                    " << endl;
Sleep(300);
cout << "\t\t\t\t\t\t\t\t\t                                                             " << endl;
cout << "\t\t\t\t\t\t\t\t\t ### #     # #     #    #    ######  ####### ######   ##### " << endl;
cout << "\t\t\t\t\t\t\t\t\t  #  ##    # #     #   # #   #     # #       #     # #     #" << endl;
cout << "\t\t\t\t\t\t\t\t\t  #  # #   # #     #  #   #  #     # #       #     # #      " << endl;
cout << "\t\t\t\t\t\t\t\t\t  #  #  #  # #     # #     # #     # #####   ######   ##### " << endl;
cout << "\t\t\t\t\t\t\t\t\t  #  #   # #  #   #  ####### #     # #       #   #         #" << endl;
cout << "\t\t\t\t\t\t\t\t\t  #  #    ##   # #   #     # #     # #       #    #  #     #" << endl;
cout << "\t\t\t\t\t\t\t\t\t ### #     #    #    #     # ######  ####### #     #  #####  " << endl;
}

void printMaze()
{
    cout << "#######################################################################################################################################"<<endl;
    cout << "#    -----------------------------------------------------------------------------------------------------------------------------    #"<<endl;
    cout << "#######################################################################################################################################"<< endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "%                                                                                                                                     %" << endl;
    Sleep(30);
    cout << "#######################################################################################################################################" <<endl;
    cout << "#    -----------------------------------------------------------------------------------------------------------------------------    #" <<endl;
    cout << "#######################################################################################################################################" << endl;
    Sleep(30);
    cout << endl;
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void printSpaceship()
{
    
    cout << "\t\t\t\t\t\t\t\t\t\t               _________        " << endl;
    Sleep(30);
    cout << "\t\t\t\t\t\t\t\t\t\t              (=========)       " << endl;
    Sleep(30);
    cout << "\t\t\t\t\t\t\t\t\t\t              |== / \\ ==|       " << endl;
    Sleep(30);
    cout << "\t\t\t\t\t\t\t\t\t\t              |= / _ \\ =|       " << endl;
    Sleep(30);
    cout << "\t\t\t\t\t\t\t\t\t\t           _  |=| ( ) |=|  _     " << endl;
    Sleep(30);
    cout << "\t\t\t\t\t\t\t\t\t\t          /=\\ |=|     |=| /=\\   " << endl;
    Sleep(30);
    cout << "\t\t\t\t\t\t\t\t\t\t          |=| |=| | | |=| |=|   " << endl;
    Sleep(30);
    cout << "\t\t\t\t\t\t\t\t\t\t          |=| |=| | | |=| |=|   " << endl;
    Sleep(30);
    cout << "\t\t\t\t\t\t\t\t\t\t          |=| |/  | |  \\| |=|   " << endl;
    Sleep(30);
    cout << "\t\t\t\t\t\t\t\t\t\t          |=| /   |_|   \\ |=|   " << endl;
    Sleep(30);
    cout << "\t\t\t\t\t\t\t\t\t\t          |=|(___________)|=|   " << endl;
    Sleep(30);
    cout << "\t\t\t\t\t\t\t\t\t\t          |=|    ( ) ( )  |=|   " << endl;
    Sleep(30);
    cout << "\t\t\t\t\t\t\t\t\t\t         /===\\           /===\\  " << endl;
    Sleep(30);
    cout << "\t\t\t\t\t\t\t\t\t\t        |||||||         ||||||| " << endl;
    Sleep(30);
    cout << "\t\t\t\t\t\t\t\t\t\t        -------         ------- " << endl;
    Sleep(30);
    cout << "\t\t\t\t\t\t\t\t\t\t         (~~~)            (~~~)  " << endl;
    Sleep(30);
}


void moveSpLeft()
{
    char next = getCharAtxy(shooterX - 1, shooterY);
    if (next == ' ')
    {
        eraseSpaceship();
        shooterX = shooterX - 1;
        Spaceship();
    }
}

void moveSpRight()
{
    char next = getCharAtxy(shooterX + 15, shooterY);
    if (next == ' ')
    {
        eraseSpaceship();
        shooterX = shooterX + 1;
        Spaceship();
    }
}

void generateBullet()
{
    bulletX[bulletCount] = shooterX + 6;
    bulletY[bulletCount] = shooterY - 1;
    gotoxy(shooterX + 6, shooterY - 1);
    cout << "^";
    bulletCount++;
}

void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "^";
}

void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void moveBullet()
{
    for (int x = 0; x < bulletCount; x++)
    {
        char next = getCharAtxy(bulletX[x], bulletY[x] - 1);
        if (next != ' ')
        {
            eraseBullet(bulletX[x], bulletY[x]);
            removeBulletFromArray(x);
        }
        else
        {
            eraseBullet(bulletX[x], bulletY[x]);
            bulletY[x] = bulletY[x] - 1;
            printBullet(bulletX[x], bulletY[x]);
        }
    }
}

void removeBulletFromArray(int idx)
{
    for (int x = idx; x < bulletCount - 1; x++)
    {
        bulletX[x] = bulletX[x + 1];
        bulletY[x] = bulletY[x + 1];
    }
    bulletCount--;
}

void printEnemy1()
{
    string temp = "" ;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp = temp + en[i][j] ;
        }
        gotoxy(enemy1X, enemy1Y + i);
        cout << temp;
        temp = "" ;
    }
}

void eraseEnemy1()
{
    for (int i = 0; i < 2; i++)
    {
        gotoxy(enemy1X, enemy1Y + i) ;
        cout << "   " ;
    }
}

void printEnemy2()
{
    string temp = "" ;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp = temp + en2[i][j] ;
        }
        gotoxy(enemy2X, enemy2Y + i);
        cout << temp;
        temp = "" ;
    }
}

void eraseEnemy2()
{
    for (int i = 0; i < 3; i++)
    {
        gotoxy(enemy2X, enemy2Y + i) ;
        cout << "   " ;
    }
}

void printEnemy3()
{
    string temp = "" ;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp = temp + en3[i][j] ;
        }
        gotoxy(enemy3X, enemy3Y + i);
        cout << temp;
        temp = "" ;
    }
}

void eraseEnemy3()
{
    for (int i = 0; i < 2; i++)
    {
        gotoxy(enemy3X, enemy3Y + i) ;
        cout << "   " ;
    }
}

void bulletCollisionWithEnemy1()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (bulletY[x] - 1 == enemy1X && (bulletX[x] == enemy1X || bulletX[x] == enemy1X + 1 || bulletX[x] == enemy1X + 2))
        {
            addScore();
            en1H();
              if (e1Helth == 0)
            {
                eraseEnemy1();
                check++;
                break;
            }
            eraseBullet(bulletX[x], bulletY[x]);
            removeBulletFromArray(x);
        }
    }
}

void bulletCollisionWithEnemy2()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (bulletY[x] - 1 == enemy2Y && (bulletX[x] == enemy2X || bulletX[x] == enemy2X + 1 || bulletX[x] == enemy2X + 2))
        {
            addScore();
            en2H();
            if (e2Helth == 0)
            {
                eraseEnemy2();
                check++;
                break;
            }
            eraseBullet(bulletX[x], bulletY[x]);
            removeBulletFromArray(x);
        }
    }
}

void bulletCollisionWithEnemy3()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (bulletY[x] - 1 == enemy3Y && (bulletX[x] == enemy3X || bulletX[x] == enemy3X + 1 || bulletX[x] == enemy3X + 2))
        {
            addScore();
            en3H();
             if (e3Helth == 0)
            {
                eraseEnemy3();
                check++;
                break;
            }
            eraseBullet(bulletX[x], bulletY[x]);
            removeBulletFromArray(x);
        }
    }
}

void moveEnemy1()
{

    if (enemyDirection1 == "down")
    {
        char next = getCharAtxy(enemy1X, enemy1Y + 3);
        if (next == ' ')
        {
            eraseEnemy1();
            enemy1Y++;
            printEnemy1();
        }
        if (next != ' ' || enemy1Y == 15)
        {
            enemyDirection1 = "up";
        }
    }
    if (enemyDirection1 == "up")
    {
        char next = getCharAtxy(enemy1X, enemy1Y - 1);
        if (next == ' ')
        {
            eraseEnemy1();
            enemy1Y--;
            printEnemy1();
        }
        if (next != ' ')
        {
            enemyDirection1 = "down";
        }
    }
}

void moveEnemy2()
{

    if (enemyDirection2 == "right")
    {
        char next = getCharAtxy(enemy2X + 3, enemy2Y);
        if (next == ' ')
        {
            eraseEnemy2();
            enemy2X++;
            printEnemy2();
        }
        if (next != ' ')
        {
            enemyDirection2 = "left";
        }
    }
    if (enemyDirection2 == "left")
    {
        char next = getCharAtxy(enemy2X - 1, enemy2Y);
        if (next == ' ')
        {
            eraseEnemy2();
            enemy2X--;
            printEnemy2();
        }
        if (next != ' ')
        {
            enemyDirection2 = "right";
        }
    }
}

void moveEnemy3()
{

    if (enemyDirection3 == "down")
    {
        char next = getCharAtxy(enemy3X, enemy3Y + 2);
        if (next == ' ')
        {
            eraseEnemy3();
            enemy3Y++;
            printEnemy3();
        }
        if (next != ' ' || enemy3Y == 15)
        {
            enemyDirection3 = "up";
        }
    }
    if (enemyDirection3 == "up")
    {
        char next = getCharAtxy(enemy3X, enemy3Y - 1);
        if (next == ' ')
        {
            eraseEnemy3();
            enemy3Y--;
            printEnemy3();
        }
        if (next != ' ')
        {
            enemyDirection3 = "down";
        }
    }
}

void printEnBullet(int x, int y)
{
    gotoxy(x, y);
    cout << ".";
}

void eraseEnBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void generateEnemy1Bullet()
{
    enBulletX[enBulletCount] = enemy1X + 1;
    enBulletY[enBulletCount] = enemy1Y + 2;
    gotoxy(enemy1X + 1, enemy1Y + 2);
    cout << ".";
    enBulletCount++;
}

void moveEnBullet()
{
    for (int x = 0; x < enBulletCount; x++)
    {
        char next = getCharAtxy(enBulletX[x], enBulletY[x] + 1);
        if (next != ' ' && next != '.' )
        {
            eraseEnBullet(enBulletX[x], enBulletY[x]);
            removeEnBulletFromArray(x);
        }
        else
        {
            eraseEnBullet(enBulletX[x], enBulletY[x]);
            enBulletY[x] = enBulletY[x] + 1;
            printEnBullet(enBulletX[x], enBulletY[x]);
        }
    }
}

void removeEnBulletFromArray(int idx)
{
    for (int x = idx; x < enBulletCount - 1; x++)
    {
        enBulletX[x] = enBulletX[x + 1];
        enBulletY[x] = enBulletY[x + 1];
    }
    enBulletCount--;
}

void generateEnemy2Bullet()
{
    en2BulletX[en2BulletCount] = enemy2X + 1;
    en2BulletY[en2BulletCount] = enemy2Y + 2;
    gotoxy(enemy2X + 1, enemy2Y + 2);
    cout << ".";
    en2BulletCount++;
}

void moveEn2Bullet()
{
    for (int x = 0; x < en2BulletCount; x++)
    {
        char next = getCharAtxy(en2BulletX[x], en2BulletY[x] + 1);
        if (next != ' ' && next != '.' )
        {
            eraseEnBullet(en2BulletX[x], en2BulletY[x]);
            removeEn2BulletFromArray(x);
        }
        else
        {
            eraseEnBullet(en2BulletX[x], en2BulletY[x]);
            en2BulletY[x] = en2BulletY[x] + 1;
            printEnBullet(en2BulletX[x], en2BulletY[x]);
        }
    }
}

void removeEn2BulletFromArray(int idx)
{
    for (int x = idx; x < en2BulletCount - 1; x++)
    {
        en2BulletX[x] = en2BulletX[x + 1];
        en2BulletY[x] = en2BulletY[x + 1];
    }
    en2BulletCount--;
}

void generateEnemy3Bullet()
{
    en3BulletX[en3BulletCount] = enemy3X + 1;
    en3BulletY[en3BulletCount] = enemy3Y + 2;
    gotoxy(enemy3X + 1, enemy3Y + 2);
    cout << ".";
    en3BulletCount++;
}

void moveEn3Bullet()
{
     for (int x = 0; x < en3BulletCount; x++)
    {
        char next = getCharAtxy(en3BulletX[x], en3BulletY[x] + 1);
        if (next != ' ' && next != '.' )
        {
            eraseEnBullet(en3BulletX[x], en3BulletY[x]);
            removeEn3BulletFromArray(x);
        }
        else
        {
            eraseEnBullet(en3BulletX[x], en3BulletY[x]);
            en3BulletY[x] = en3BulletY[x] + 1;
            printEnBullet(en3BulletX[x], en3BulletY[x]);
        }
    }
}

void removeEn3BulletFromArray(int idx)
{
    for (int x = idx; x < en3BulletCount - 1; x++)
    {
        en3BulletX[x] = en3BulletX[x + 1];
        en3BulletY[x] = en3BulletY[x + 1];
    }
    en3BulletCount--;
}

void printScore()
{
    gotoxy(137, 10);
    cout << "Score: " << score;
    gotoxy(137,11);
    cout<<"High score: "<<highscore;
}

void addScore()
{
    score++;
}

void loadScore()
{
    fstream file;
    file.open("score.txt",ios::in);
    if(file)
    {
        file>>highscore;
        file.close();
    }
    else
    {
        highscore=0;
    }
}
void saveScore()
{
    if(score>highscore)
    {
        fstream file;
        file.open("score.txt",ios::out);
        file<<score;
        file.close();
    }
}
void printHealth()
{
    gotoxy(137, 12);
    cout << "Health: " << health << "  ";
}

void remHelth()
{
    health--;
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

string mainMenu()
{
    cout << "MAIN MENU" << endl;
    cout << endl;
    string option;
    cout << "Press 1 to Start" << endl;
    cout << "Press 2 For instructions" << endl;
    cout << "press 3 to exit" << endl
         << endl;
    cout << "Enter your option!" << endl;
    cin >> option;
    return option;
}

void start()
{
    loadScore();
    system("cls");
    printMaze();
    Sleep(500);
    Spaceship();
    while (!(GetAsyncKeyState(VK_ESCAPE)))
    {
        printScore();
        printHealth();
        if (GetAsyncKeyState(VK_LEFT))
        {
            moveSpLeft();
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            moveSpRight();
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            generateBullet();
        }

        if (timer == 3 && e1Helth > 0)
        {
            printEnemy1();
            moveEnemy1();
            generateEnemy1Bullet();
            timer = 0;
        }

        if (e1Helth == 0)
        {
            eraseEnemy1();
            check++;
        }
        if (timer1 == 6 && e2Helth > 0)
        {
            printEnemy2();
            moveEnemy2();
            generateEnemy2Bullet();
            timer1 = 0;
        }

        if (e2Helth == 0)
        {
            eraseEnemy2();
            check1++;
        }

        if (timer2 == 5 && e3Helth > 0)
        {
            printEnemy3();
            moveEnemy3();
            generateEnemy3Bullet();
            timer2 = 0;
        }

        if (e3Helth == 0)
        {
            eraseEnemy3();
            check2++;
        }
        if (health == 0)
        {
            gameOver();
        }
        if (check > 1 && check1 > 0 && check2 > 0)
        {
            won();
        }
        moveBullet();
        moveEnBullet();
        moveEn2Bullet();
        moveEn3Bullet();
        en1Collision();
        en2Collision();
        en3Collision();
        bulletCollisionWithEnemy1();
        bulletCollisionWithEnemy2();
        bulletCollisionWithEnemy3();
        timer++;
        timer1++;
        timer2++;
        Sleep(40) ;
    }
    clearScreen();
}

void instructions()
{
    cout << "INSTRUCTIONS" << endl;
    cout << endl;
    cout << "Press Right-KEY to move right" << endl;
    cout << "Press Left-KEY to move left" << endl;
    cout << "Press Space-KEY to fire " << endl;
    cout << "Press Esacpe to Exit game " << endl;
    clearScreen();
}

void clearScreen()
{
    cout << "Press Any Key to Continue.." << endl;
    getch();
    system("cls");
}

void en1Collision()
{
    for (int x = 0; x < enBulletCount; x++)
    {
        if (enBulletY[x] + 1 == shooterY && (enBulletX[x] >= shooterX && enBulletX[x] <= shooterX+13 ) )
        {
            remHelth();
            eraseEnBullet(enBulletX[x], enBulletY[x]);
            removeEnBulletFromArray(x);
        }
    }
}

void en2Collision()
{
    for (int x = 0; x < en2BulletCount; x++)
    {
        if (en2BulletY[x] + 1 == shooterY && (en2BulletX[x] >= shooterX && en2BulletX[x] <= shooterX+13 ) )
        {
            remHelth();
            eraseEnBullet(en2BulletX[x], en2BulletY[x]);
            removeEn2BulletFromArray(x);
        }
    }
}

void en3Collision()
{
    for (int x = 0; x < en3BulletCount; x++)
    {
        if (en3BulletY[x] + 1 == shooterY && (en3BulletX[x] >= shooterX && en3BulletX[x] <= shooterX+13 ) )
        {
            remHelth();
            eraseEnBullet(en3BulletX[x], en3BulletY[x]);
            removeEn3BulletFromArray(x);
        }
    }
}

void en1H()
{
    e1Helth--;
}

void en2H()
{
    e2Helth--;
}

void en3H()
{
    e3Helth--;
}

void gameOver()
{
    system("cls");
    cout << "   _____                                                            " << endl;
    cout << "  / ____|                                                           " << endl;
    cout << " | |  __    __ _   _ __ ___     ___      ___   __   __   ___   _ __  " << endl;
    cout << " | | |_ |  / _` | | '_ ` _ \\   / _ \\    / _ \\  \\ \\ / /  / _ \\ | '__| " << endl;
    cout << " | |__| | | (_| | | | | | | | |  __/   | (_) |  \\ V /  |  __/ | |    " << endl;
    cout << "  \\_____|  \\__,_| |_| |_| |_|  \\___|    \\___/    \\_/    \\___| |_|    " << endl;
    cout << endl;
    cout << "You Score:" << score << endl;
    saveScore();
    exit(0);
}

void won()
{
    saveScore();
    system("cls");
    
    cout << " __     __                   __          __                " << endl;
    cout << " \\ \\   / /                   \\ \\        / /                " << endl;
    cout << "  \\ \\_/ /    ___    _   _     \\ \\  /\\  / /    ___    _ __  " << endl;
    cout << "   \\   /    / _ \\  | | | |     \\ \\/  \\/ /    / _ \\  | '_ \\ " << endl;
    cout << "    | |    | (_) | | |_| |      \\  /\\  /    | (_) | | | | |" << endl;
    cout << "    |_|     \\___/   \\__,_|       \\/  \\/      \\___/  |_| |_|" << endl;
    cout << "                                                            " << endl;
    cout << endl;
    cout << "You Score:" << score << endl;
    exit(0);
}
void Spaceship()
{
    gotoxy(shooterX, shooterY);

    cout << "      /\\      ";

    gotoxy(shooterX, shooterY + 1);

    cout << "   __/~~\\__   ";

    gotoxy(shooterX, shooterY + 2);

    cout << "/    |  |    \\";

    gotoxy(shooterX, shooterY + 3);

    cout << "=====.  .=====";

    gotoxy(shooterX, shooterY + 4);

    cout << "     ||||     ";
}
void eraseSpaceship()

{

    gotoxy(shooterX, shooterY);

    cout << "              ";

    gotoxy(shooterX, shooterY + 1);

    cout << "              ";

    gotoxy(shooterX, shooterY + 2);

    cout << "              ";

    gotoxy(shooterX, shooterY + 3);

    cout << "              ";

    gotoxy(shooterX, shooterY + 4);

    cout << "              ";
}

