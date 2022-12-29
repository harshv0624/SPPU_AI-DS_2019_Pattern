//Write C++ program to draw a concave polygon and fill it with desired color using scan fill algorithm. Apply the concept of inheritance.

//header files
#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;

class Line{
	
	//class which contains drawline function... only for completing inheritance purpose
	public:
	void drawline(int x1,int y1,int x2,int y2){
		line(x1,y1,x2,y2);
	}
};

class polygon:public Line{
	//class which contains main functions
	
	//variable declarations and functions
	int x[20],y[20],n,k,ymax,ymin,x_int[20];
	float m[20];
	public:
	void accept();
	void scanfill(); 
};

void polygon::accept(){
	
	//accepting edges and y and y co ordinates of polygon
	cout<<"Enter Edge: ";
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter x and y coordinates: ";
		cin>>x[i]>>y[i];
	}
	
	//setting last co-ordinates same as firsr co-ordinates
	x[n]=x[0];
	y[n]=y[0];
	
	//Drawing polygon
	for(int i=0;i<=n-1;i++){
		drawline(x[i],y[i],x[i+1],y[i+1]);
	}
}

void polygon::scanfill(){
	
	ymin=500;
	ymax=0;
	float dx,dy;
	setcolor(YELLOW);
	
	for(int i=0;i<n;i++){
		
		//Finding slope of every coordinates
		if(y[i]<=ymin)
		ymin=y[i];
		if(y[i]>=ymax)
		ymax=y[i];
		
		dx=x[i+1]-x[i];
		dy=y[i+1]-y[i];
		
		if(dx==0)
		m[i]=0;
		if(dy==0)
		m[i]=1;
		if(dx!=0 && dy!=0)
		m[i]=(float)(dx/dy);
	}
	
	int Y;
	for(Y=ymax;Y>=ymin;Y--){
		
		//finding intersection points
		k=0;
		for(int i=0;i<n;i++){
			if((y[i]>Y&&y[i+1]<=Y) || (y[i]<=Y&&y[i+1]>Y)){
				x_int[k]=(x[i]+(m[i]*(Y-y[i])));
				k++;
			}
		}
		
		//sorting intersection points
		
		for(int i=0;i<k-1;i++){
			for(int j=0;j<k-1;j++){
				if(x_int[i]>x_int[i+1]){
					int temp=x_int[i];
					x_int[i]=x_int[i+1];
					x_int[i+1]=temp;
				}
			}
		}
		
		//Filling Polygon
		for(int i=0;i<k-1;i=i+2){
			drawline(x_int[i],Y,x_int[i+1],Y);
			delay(100);
		}
	}
	
	
}
int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	polygon obj;
	obj.accept();
	obj.scanfill();
	getch();
	closegraph();
}
