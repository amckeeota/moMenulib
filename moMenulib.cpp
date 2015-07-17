//Menu object creation class

#include "Arduino.h"
#include "moMenulib.h"
#include "moLCDlib.h"

moMenu::moMenu(){}

char* moMenu::getText(){
	return cursorLoc->text;
}

void moMenu::setTop(menuItem *menuTop){
	top = menuTop;
	cursorLoc = menuTop;
}

void moMenu::setNext(menuItem *cur,menuItem *join){
	cur->next = join;
}

void moMenu::setPrev(menuItem *cur,menuItem *previous){
	int len = 0;
	while (cur[len].next==NULL){
		cur[len].prev = previous;
		len++;
	}
}

bool moMenu::moveLeft(char *lTop,char *lBot){
	if(cursorLoc->prev!=NULL){
		cursorLoc = cursorLoc->prev;
		if((cursorLoc+1)==NULL){
			for(int i=0;i<16;i++)
				lBot[i] = cursorLoc->text[i];
			for(int i=0;i<16;i++)
				lTop[i] = (cursorLoc-1)->text[i];
		}
		else{
			for(int i=0;i<16;i++)
				lTop[i] = cursorLoc->text[i];
			for(int i=0;i<16;i++)
				lBot[i] = (cursorLoc+1)->text[i];
		}	
		return true;
	}
	return false;
}
bool moMenu::moveRight(char *lTop,char *lBot){
	if(cursorLoc->next!=NULL){
		cursorLoc=cursorLoc->next;
		if((cursorLoc+1)==NULL){
			for(int i=0;i<16;i++)
				lBot[i] = cursorLoc->text[i];
			for(int i=0;i<16;i++)
				lTop[i] = (cursorLoc-1)->text[i];
		}
		else{
			for(int i=0;i<16;i++)
				lTop[i] = cursorLoc->text[i];
			for(int i=0;i<16;i++)
				lBot[i] = (cursorLoc+1)->text[i];
		}	
		return true;
	}
	return false;
}
bool moMenu::moveUp(char *lTop,char *lBot){
	if((cursorLoc)->text!=NULL){
		cursorLoc--;
		if((cursorLoc+1)==NULL){
			for(int i=0;i<16;i++)
				lBot[i] = cursorLoc->text[i];
			for(int i=0;i<16;i++)
				lTop[i] = (cursorLoc-1)->text[i];
		}
		else{
			for(int i=0;i<16;i++)
				lTop[i] = cursorLoc->text[i];
			for(int i=0;i<16;i++)
				lBot[i] = (cursorLoc+1)->text[i];
		}	
		return true;
	}
	return false;
}
bool moMenu::moveDown(char *lTop,char *lBot){
	if((cursorLoc+1)!=NULL){
		cursorLoc++;
		if((cursorLoc+1)==NULL){
			for(int i=0;i<16;i++)
				lBot[i] = cursorLoc->text[i];
			for(int i=0;i<16;i++)
				lTop[i] = (cursorLoc-1)->text[i];
		}
		else{
			for(int i=0;i<16;i++)
				lTop[i] = cursorLoc->text[i];
			for(int i=0;i<16;i++)
				lBot[i] = (cursorLoc+1)->text[i];
		}	
		return true;
	}
	return false;
}

void moMenu::setLines(char* lT,char *lB){
	if((cursorLoc+1)==NULL){
		lB = cursorLoc->text;
		lT = (cursorLoc-1)->text;
	}
	else{
		lT = cursorLoc->text;
		lB = (cursorLoc+1)->text;
	}	
}