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

		bool moveLeft(char *lTop,char *lBot);
		bool moveRight(char *lTop,char *lBot);
		bool moveUp(char *lTop,char *lBot);
		bool moveDown(char *lTop,char *lBot);
	private:
		void setLines(char* lT,char* lB);
		menuItem *top;
		menuItem *cursorLoc;
		
};

//Bounds are not clearly defined (next ==null doesn't work)
//Down arrow doesn't work

#endif