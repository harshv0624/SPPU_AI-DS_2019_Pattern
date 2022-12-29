#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
using namespace std;

class pattern{
	int xmin,xmax,ymin,ymax;
	public:
		void start();
		void dda(int x1,int y1,int x2,int y2);
		void breshnam(int xc,int yc,int r);
		void drawCircle(int xc,int yc,int x,int y){
//cout<<xc<<"\t"<<yc<<"\t"<<x<<"\t"<<y<<"\n";
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, WHITE);
    putpixel(xc + y, yc + x, WHITE);
    putpixel(xc - y, yc + x, WHITE);
    putpixel(xc + y, yc - x, WHITE);
    putpixel(xc - y, yc - x, WHITE);
    putpixel(xc + x, yc + y, WHITE);


		}
};

void pattern::breshnam(int xc,int yc,int r){
	int x=0;
	int y=r;
	int d=3-(2*r);
	
	while(y>=x){
		cout<<"\n"<<xc<<" ";
		cout<<"\nLoop\n";
		x++;
		if(d>0){
			y--;
			d=d+4*(x-y)+10;
		}
		else{
			d=d+4*x+6;
		}
		
		drawCircle(xc,yc,x,y);
		delay(100);
	}
}
void pattern::dda(int x1,int y1,int x2,int y2){
	float dx=x2-x1;
	float dy=y2-y1;
	int steps=dx>=dy?dx:dy;
	float x_inc=dx/(float)steps;
	float y_inc=dy/(float)steps;
	
	float x=x1;
	float y=y1;
	for(int i=0;i<steps;i++){
		putpixel(x,y,15);
		x+=x_inc;
		y+=y_inc;
	}
}

void pattern::start(){
	cout<<"Enter Coordinates: ";
	cin>>xmin>>ymin>>xmax>>ymax;
	dda(xmin,ymin,xmax,ymin);
	dda(xmax,ymin,xmax,ymax);
	dda(xmin,ymax,xmax,ymax);
	dda(xmin,ymin,xmin,ymax);
	getch();
	
	float xmid=(xmin+xmax)/2;
	float ymid=(ymin+ymax)/2;
	
	dda(xmin,ymid,xmid,ymax); 
	dda(xmid,ymax,xmax,ymid);
	dda(xmid,ymin,xmax,ymid);   
	dda(xmid,ymin,xmin,ymid);
	getch();    
	
    float side = sqrt(pow((ymin - ymid), 2) + pow((xmid - xmin), 2));
    cout<<xmid<<"\n";
    float r = side / 2;
    cout<<r;
	breshnam(xmid,ymid,r);
                                                                                                                                                                                                           
}

int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	pattern obj;
	obj.start();
	
}
