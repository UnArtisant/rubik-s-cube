//
// Created by Sautron Tom on 04/05/2021.
//




#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "conio.h"

int c_kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if (ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}


static int getCursorPosition2(int *x, int *y)
{
  *x = -1;
  *y = -1;

  char buf[32];
  unsigned int i = 0;
  int ch;

  printf("\x1B[6n");

  while (i < sizeof(buf) - 1)
  {
    ch = c_getch();
    if (ch == EOF || ch == 'R') break;
    buf[i++] = ch;
  }
  buf[i] = '\0';

  if (buf[0] != '\x1b' || buf[1] != '[') return -1;

  if (sscanf(&buf[2], "%d;%d", y, x) != 2) return -1;

  return 0;
}

int c_wherex(void)
{
  int x, y;
  getCursorPosition2(&x, &y);
  return x;
}

int c_wherey(void)
{
  int x, y;
  getCursorPosition2(&x, &y);
  return y;
}


void c_gotoxy(int x, int y)
{
  printf("\x1b[%d;%dH", y, x);
  fflush(stdout);
}

void c_clrscr()
{
  puts("\x1b[2J\x1b[1;1H");
  fflush(stdout);
}

void c_textcolor(int newcolor)
{
  //https://en.wikipedia.org/wiki/ANSI_escape_code

  const char * s = "\x1b[30m";

  switch (newcolor)
  {
  case BLACK:
    s = "\x1b[30m";
    break;

  case BLUE:
    s = "\x1b[34m";
    break;

  case GREEN:
    s = "\x1b[32m";
    break;

  case CYAN:
    s = "\x1b[36m";
    break;

  case RED:
    s = "\x1b[31;1m";
    break;

  case MAGENTA:
    s = "\x1b[35m";
    break;

  case BROWN:
    s = "\x1b[31m";
    break;

  case LIGHTGRAY:
    s = "\x1b[30;1m";
    break;

  case DARKGRAY:
    s = "\x1b[30m";
    break;

  case LIGHTBLUE:
    s = "\x1b[34;1m";
    break;

  case LIGHTGREEN:
    s = "\x1b[32,1m";;
    break;

  case LIGHTCYAN:
    s = "\x1b[36;1m";
    break;

  case LIGHTRED:
    s = "\x1b[31;1m";
    break;

  case LIGHTMAGENTA:
    s = "\x1b[35;1m";
    break;

  case YELLOW:
    s = "\x1b[33;1m";
    break;

  case WHITE:
    s = "\x1b[37;1m";
    break;

  case BLINK:
    s = "\x1b[30m";
    break;
  };

  printf("%s", s);
}

void c_textbackground(int newcolor)
{
  //https://en.wikipedia.org/wiki/ANSI_escape_code

  const char * s = "\x1b[40m";

  switch (newcolor)
  {
  case BLACK:
    s = "\x1b[40m";
    break;

  case BLUE:
    s = "\x1b[44m";
    break;

  case GREEN:
    s = "\x1b[42m";
    break;

  case CYAN:
    s = "\x1b[46m";
    break;

  case RED:
    s = "\x1b[41;1m";
    break;

  case MAGENTA:
    s = "\x1b[45m";
    break;

  case BROWN:
    s = "\x1b[41m";
    break;

  case LIGHTGRAY:
    s = "\x1b[40;1m";
    break;

  case DARKGRAY:
    s = "\x1b[40m";
    break;

  case LIGHTBLUE:
    s = "\x1b[44;1m";
    break;

  case LIGHTGREEN:
    s = "\x1b[42,1m";;
    break;

  case LIGHTCYAN:
    s = "\x1b[46;1m";
    break;

  case LIGHTRED:
    s = "\x1b[41;1m";
    break;

  case LIGHTMAGENTA:
    s = "\x1b[45;1m";
    break;

  case YELLOW:
    s = "\x1b[43;1m";
    break;

  case WHITE:
    s = "\x1b[47;1m";
    break;

  case BLINK:
    s = "\x1b[40m";
    break;
  };

  puts(s);
}


/* Read 1 character - echo defines echo mode */
/*
static char getch_(int echo)
{
  struct termios old, new;
  int ch;
  tcgetattr(0, &old);
  new = old;
  new.c_lflag &= ~ICANON;
  if (!echo)
  {
    new.c_lflag &= ~ECHO;
  }
  tcsetattr(0, TCSANOW, &new);
  ch = getchar();
  tcsetattr(0, TCSANOW, &old);
  return ch;
}
*/

/* Read 1 character without echo */
int c_getch(void)
{
  struct termios old, new;
  int ch;

  tcgetattr(0, &old);

  new = old;
  new.c_lflag &= ~ICANON;
  new.c_lflag &= ~ECHO;
  tcsetattr(0, TCSANOW, &new);

  ch = getchar();

  tcsetattr(0, TCSANOW, &old);

  return ch;
}

/* Read 1 character with echo */
int c_getche(void)
{
  struct termios old, new;
  int ch;

  tcgetattr(0, &old);

  new = old;
  new.c_lflag &= ~ICANON;
  //new.c_lflag &= ~ECHO;
  tcsetattr(0, TCSANOW, &new);

  ch = getchar();

  tcsetattr(0, TCSANOW, &old);
  return ch;
}


void c_setcursortype(int cur_t)
{
  switch (cur_t)
  {
  case _NOCURSOR:
    printf("\x1b[?25l");
    break;

  case _NORMALCURSOR:
    printf("\x1b[?25h");
    break;

  case _SOLIDCURSOR://TODO
    printf("\x1b[?25h");
    break;
  }
}

void c_gettextinfo(struct text_info *r)
{

  struct winsize w;
  ioctl(0, TIOCGWINSZ, &w);

  r->screenheight = w.ws_row;
  r->screenwidth = w.ws_col;

  int x, y;
  getCursorPosition2(&x, &y);


  r->curx = x;
  r->cury = y;

}

void c_textattr(int newattr)
{
  //tODO
}


