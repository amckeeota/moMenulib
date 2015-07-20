//Menu object creation class

#include "Arduino.h"
#include "moMenulib.h"
#include "moLCDlib.h"

moMenu::moMenu(){}

char* moMenu::getText(){
	return cursorLoc->text;
}

void moMenu::setTop(menuItem *menuTop){
	top = &menuTop[0];
	cursorLoc = &menuTop[0];
}

void moMenu::setNext(menuItem *cur,menuItem *join){
	cur->next = join;
}

void moMenu::setPrev(menuItem *cur,menuItem *previous){
	int len = 1;
	while(cur[len].text[0]!='\0'){
		cur[len].prev=previous;
		len++;
	}
}

int moMenu::moveLeft(char *lTop,char *lBot){
	if(cursorLoc->prev!=NULL){
		Serial.println(cursorLoc->prev->text);
		cursorLoc = cursorLoc->prev;
		if(cursorLoc[1].text[0]=='\0'){
			for(int i=0;i<16;i++)
				lBot[i] = cursorLoc->text[i];
			for(int i=0;i<16;i++)
				lTop[i] = (cursorLoc-1)->text[i];
			return 2;
		}
		else{
			for(int i=0;i<16;i++)
				lTop[i] = cursorLoc->text[i];
			for(int i=0;i<16;i++)
				lBot[i] = (cursorLoc+1)->text[i];
		}	
		return 1;
	}
	return 0;
}
int moMenu::moveRight(char *lTop,char *lBot){
	if(cursorLoc->next!=NULL){
		Serial.println(cursorLoc->next->text);
		cursorLoc=cursorLoc->next;
		//if the next cursor has only 
		
		for(int i=0;i<16;i++)
			lTop[i] = cursorLoc->text[i];
		for(int i=0;i<16;i++)
			lBot[i] = (cursorLoc+1)->text[i];
		return 1;
	}
	return 0;
}
int moMenu::moveUp(char *lTop,char *lBot){
	if((cursorLoc-1)->text[0]!='\0'){
		Serial.println((cursorLoc-1)->text);
		cursorLoc--;
		for(int i=0;i<16;i++)
			lTop[i] = cursorLoc->text[i];
		for(int i=0;i<16;i++)
			lBot[i] = (cursorLoc+1)->text[i];
		return 1;
	}
	return 0;
}
int moMenu::moveDown(char *lTop,char *lBot){
	//If there is one more menuItem below cursorLoc
	//then move pointer to next item
	if(cursorLoc[1].text[0]!='\0'){
		Serial.println(cursorLoc[1].text);
		cursorLoc++;
		//If, after moving, there is nothing below,
		//keep 
		if(cursorLoc[1].text[0]=='\0'){
			for(int i=0;i<16;i++)
				lBot[i] = cursorLoc->text[i];
			for(int i=0;i<16;i++)
				lTop[i] = (cursorLoc-1)->text[i];
			return 2;
		}
		else{
			for(int i=0;i<16;i++)
				lTop[i] = cursorLoc->text[i];
			for(int i=0;i<16;i++)
				lBot[i] = (cursorLoc+1)->text[i];
			return 1;
		}	
	}
	return 0;
}
