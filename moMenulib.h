#ifndef moMenulib_h
#define moMenulib_h

struct menuItem{
	char text[16];
	menuItem *next,*prev;
};

class moMenu{
	public:
		moMenu();
		char* getText();
		void setTop(menuItem *menuTop);
		void setNext(menuItem *cur,menuItem *join);
		void setPrev(menuItem *cur,menuItem *previous);

		int moveLeft(char *lTop,char *lBot);
		int moveRight(char *lTop,char *lBot);
		int moveUp(char *lTop,char *lBot);
		int moveDown(char *lTop,char *lBot);
	private:
		menuItem *top;
		menuItem *cursorLoc;
		
};

//Bounds are not clearly defined (next ==null doesn't work)
//Down arrow doesn't work

#endif