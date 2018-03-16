#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "ledit.h"

#define WIDTH 80
#define HEIGHT 40

void drawgrid(WINDOW * wind, int r, int c);

int fx = 0;
int fy = 0;

//A struct representation of a pixel, and its location
typedef struct{
	uint32_t red;
	uint32_t green;
	uint32_t blue;
	uint32_t alpha;
	int x;
	int y;
} Pixel;


//Saves the current pixel to the image in memory
void savetopic(Pixel px, Image img)
{
	img.data[4*img.width*px.y+4*px.x+0] = px.red;
	img.data[4*img.width*px.y+4*px.x+1] = px.green;
	img.data[4*img.width*px.y+4*px.x+2] = px.blue;
	img.data[4*img.width*px.y+4*px.x+3] = px.alpha;
	return;
}

Pixel newpixel(Image img, int x, int y)
{
	
}

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

//Gets filename for saving
//currently a legacy button (e.g. names are cmd line args now)

int main(int argc, char * []argv)
{
	Image pic = loadimage(argv[1]);
	
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
	mvprintw(0,0, "tart ALPHA");
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
				saveimage(argv[1],pic);
				mvprintw(menu,4,0,"Saving.");
				refresh();
				break;
			default:
				break;
		}
		drawgrid(menu,row,col);
		
	}
	clrtoeol();
	refresh();
	endwin();
	cleanup(pic);
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

//Draws the "Big Picture" version of the image
//e.g. a rough representation of where the user is
//on the currently loaded image in relation to the edit grid
void drawbig(WINDOW * wind, Image img, int ux, int uy)
{
	int 
	if (img.width > img.height)

}
 
