#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;

class lineclipping{
	int x1,x2,y1,y2;
	int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8;
	int xmin=100,xmax=400,ymin=100,ymax=400,x,y;
	public:
		void clip();
		int getcode(int x,int y);
};

int lineclipping::getcode(int x,int y){
	int code=0;
	if(y>ymax)
	code=TOP;
	if(y<ymin)
	code=BOTTOM;
	if(x>xmax)
	code=RIGHT;
	if(x<xmin)
	code=LEFT;
	
	return code;
}

void lineclipping::clip(){

	int code1,code2;
	setcolor(15);
	rectangle(xmin,ymin,xmax,ymax);
	
	setcolor(YELLOW);
	cout<<"Enter Line Coordinates:\n";
	cout<<"Enter X1 and Y1: ";
	cin>>x1>>y1;
	cout<<"Enter X2 and Y2: ";
	cin>>x2>>y2;
	
	line(x1,y1,x2,y2);
	getch();
	code1=getcode(x1,y1);
	code2=getcode(x2,y2);
	float m;
	int temp;
	int accept=0;
	while(1){
		m=(float)(y2-y1)/(x2-x1);
		if(code1 == 0 && code2 == 0){
			accept=1;
			break;
		}
		else if((code1 & code2)!=0){
			break;
		}
		else{
			if(code1==0)
			temp=code2;
			else
			temp=code1;
			
			if(temp & TOP){
				x=x1 + (ymax-y1)/m;
				y=ymax;
			}
			else if(temp & BOTTOM){
				x=x1+(ymin-y1)/m;
				y=ymin;
			}
			else if(temp & LEFT){
				y=y1+m*(xmin-x1);
				x=xmin;
			}
			else if(temp & RIGHT){
				y=y1+m*(xmax-x1);
				x=xmax;
			}
			
			if(temp==code1){
				x1=x;
				y1=y;
				code1=getcode(x1,y1);
			}else{
				x2=x;
				y2=y;
				code2=getcode(x2,y2);
			}
		}
	}
	
	if(accept==1)
		cleardevice();
		rectangle(xmin,ymin,xmax,ymax);
		setcolor(YELLOW);
		line(x1,y1,x2,y2);
		getch();
		closegraph();
	
}

int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	lineclipping obj;
	obj.clip();

return 0;
}
