#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
using namespace std;

class trans{
	int val;
	public:
		void setvalue(int num){
			val=num;			
		}
		
		int disp(){
			return val;
		}
		
		trans operator +(trans o){
			trans t;
			t.val=val+o.val;
			return t;
		}

};

class rot{
	int x1=0,y1=0,x2=0,y2=0;
	float r=0,t=0;
};

class scaling{
	int val;
	public:
		void setvalue(int value){
			val=value;
		}
		
		int disp(){
			return val;	
		}
		
		scaling operator * (scaling s){
			scaling s1;
			s1.val=val*s.val;
			return s1;
		}
};

int main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	int x1=100,y1=100,x2=300,y2=100,x3=150,y3=50,tx,ty;
	int choice;
	cout<<"Enter Choice\n1.Translation\n2.Scaling\n3.ROTATION\n";
	cin>>choice;
	switch(choice){
		case 1:
			trans t1,t2,t3,t4,t5,t6,t7,t8;
			cout<<"Enter translation factor: ";
			cin>>tx>>ty;
			t1.setvalue(x1);
			t2.setvalue(y1);
			t3.setvalue(x2);
			t4.setvalue(y2);
			t5.setvalue(x3);
			t6.setvalue(y3);
			setcolor(WHITE);
			line(x1,y1,x2,y2);
			line(x2,y2,x3,y3);
			line(x3,y3,x1,y2);
			setcolor(GREEN);
			t7.setvalue(tx);
			t8.setvalue(ty);
			t1=t1+t7;
			t2=t2+t8;
			t3=t3+t7;
			t4=t4+t8;
			t5=t5+t7;
			t6=t6+t8;
			line(t1.disp(),t2.disp(),t3.disp(),t4.disp());
			line(t3.disp(),t4.disp(),t5.disp(),t6.disp());
			line(t5.disp(),t6.disp(),t1.disp(),t2.disp());
			getch();
			break;
		case 2:
			int sx,sy;
			scaling s1,s2,s3,s4,s5,s6,s7,s8;
			cout<<"Enter scaling factor sx: ";
			cin>>sx;
			cout<<"Enter scaling for sy: ";
			cin>>sy;
			s1.setvalue(x1);
			s2.setvalue(y1);
			s3.setvalue(x2);
			s4.setvalue(y2);
			s5.setvalue(x3);
			s6.setvalue(y3);
			setcolor(WHITE);
			line(x1,y1,x2,y2);
			line(x2,y2,x3,y3);
			line(x3,y3,x1,y2);
			
			setcolor(GREEN);
			
			s7.setvalue(sx);
			s8.setvalue(sy);
			
			s1=s1*s7;
			s2=s2*s8;
			s3=s3*s7;
			s4=s4*s8;
			s5=s5*s7;
			s6=s6*s8;
			cout<<s1.disp();
			line(s1.disp(),s2.disp(),s3.disp(),s4.disp());
			line(s3.disp(),s4.disp(),s5.disp(),s6.disp());
			line(s5.disp(),s6.disp(),s1.disp(),s2.disp());
			getch();
			break;
			
		case 3:
			float r,t;
			int nx1,nx2,ny1,ny2,nx3,ny3;
			cout<<"Enter Rotation Angle: ";
			cin>>r;
			t=3.14*r/180;
			nx1=abs(x1*cos(t)-y1*sin(t));
			nx2=abs(x2*cos(t)-y2*sin(t));
			nx3=abs(x3*cos(t)-y3*sin(t));
			ny1=abs(x1*sin(t)+y1*cos(t));
			ny2=abs(x2*sin(t)+y2*cos(t));
			ny3=abs(x3*sin(t)+y2*cos(t));
			setcolor(WHITE);
			line(x1,y1,x2,y2);
			line(x2,y2,x3,y3);
			line(x3,y3,x1,y2);
			
			setcolor(GREEN);
			line(nx1,ny1,nx2,ny2);
			line(nx2,ny2,nx3,ny3);
			line(nx3,ny3,nx1,ny1);
			getch();
			break;
			
	}
}

