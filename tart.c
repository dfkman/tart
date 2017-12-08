#include <ncurses.h>
#include <stdio.h>
#include <string.h>

#define WIDTH 30
#define HEIGHT 10

void drawgrid(WINDOW * wind, int r, int c);

int fx = 0;
int fy = 0;

char grid [8][8];


//saves the current grid to a file as plaintext
void savetofile(char * filename)
{
	FILE * fileloc;
	fileloc = fopen(filename, "w+");
	for (int r = 0; r < 8; r++){
		for (int c = 0; c < 8; c++){
			fputc(grid[r][c], fileloc);
		}
			fputc('\n',fileloc);
	}
	fclose(fileloc);
	return;
}

void getfilename(){
	char buffer [256];
	echo();
	getstr(buffer);
	savetofile(buffer);
	return;
}

//Creates the basic 8x8 grid for editing
void initgrid()
{
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			grid[i][k] = '0';
		}
	}
}	

int main(void)
{
	initgrid();
	WINDOW * menu;
	int row = 0;
	int col = 0;
	initscr();
	clear();
	noecho();
	cbreak();
	fx = (42 - WIDTH) / 2;
	fy = (12 - HEIGHT) / 2;
	menu = newwin(HEIGHT, WIDTH, fx, fy);
	keypad(menu, TRUE);
	mvprintw(0,0, "tart proof of concept (space to edit, 0 to close)");
	mvprintw(1,0, "press s to save.");
	refresh();
	int c;
	drawgrid(menu, row, col);
	while (c != '0')
	{
		mvwprintw(menu,1,0,"%d",row);
		mvwprintw(menu,2,0,"%d",col);
		mvwprintw(menu,3,0,"%c",grid[row][col]);
		c = wgetch(menu);
		switch(c)
		{
			case KEY_UP:
				if(row == 0)
					row = 7;
				else
					row--;
				break;
			case KEY_DOWN:
				if (row == 7)
					row = 0;
				else
					row++;
				break;
			
			case KEY_LEFT:
				if (col == 0)
					col = 7;
				else
					col--;
				break;
			case KEY_RIGHT:
				if (col == 7)
					col = 0;
				else
					col++;
				break;
			case ' ':
				if (grid[row][col] == '0')
					grid[row][col] = '1';
				else
					grid[row][col] = '0';
				break;
			case 's':
				mvprintw(4,0,"Insert file name: ");
				refresh();
				getfilename();
				break;
			default:
				break;
		}
		drawgrid(menu,row,col);
		
	}
	clrtoeol();
	refresh();
	endwin();
	return 0;	
}


//(re)draws the grid based on the grid var
// row and col represent the highlighted char
void drawgrid(WINDOW * wind, int row, int col)
{
	int x,y,i;
	x = 2;
	y = 2;
	for (i = 0; i < 8; i++)
	{
		x = 2;
		for (int j = 0; j < 8; j++)
		{
		if (col == (j) && row == (i))
		{
			wattron(wind, A_REVERSE);
			mvwprintw(wind, y,x, "%c", grid[y-2][x-2]);
			wattroff(wind, A_REVERSE);
		}
		else
			mvwprintw(wind,y,x,"%c", grid[y-2][x-2]);
		x++;
		}
		y++;
	}
	wrefresh(wind);
}
 
