#include<iostream>
#include<vector>
#include<cmath>
#include<graphics.h>
#include<windows.h>
#include<stdio.h>
using namespace std;

void quickHull(vector<struct locations> inputs);
void findHull(vector<struct locations> Sk,struct locations P,struct locations Q);

struct locations{
	float x;
	float y;
	};

int inputg_int(int x,int y){
    char ch;
    char name[100];
    int i=0;
    int sign=1;
    do{
        ch=getch();
        if(int(ch)==8){
                if(i>0)
            name[--i]='\0';
        else
            sign=1;
        }
        if(int(ch)>=48 && int(ch)<=57){
                name[i++]=ch;
                name[i]='\0';
                if(name[0]=='0')i--;
        }
        outtextxy(x,y,"                                                   ");
        if((ch=='-' && i==0) || sign==-1){
            outtextxy(x,y,"-");
            sign=-1;
        }
        outtextxy(x+20,y,name);
    }while(int(ch)!=13);
    return atoi(name)*sign;
}
vector<struct locations> convexHull;

int main()
{
	vector<struct locations> inputs;
	struct locations first;
	//cout<<inputs[2].x;

	int width =  GetSystemMetrics(SM_CXSCREEN);
    int height = GetSystemMetrics(SM_CYSCREEN);
    initwindow(width,height,"",-3,-3);
    settextstyle(10,0,2);
    setcolor(10);
    outtextxy(150,25, "  Enter no. of points : ");
    int n=inputg_int(450,25);
    int k,xx,yy,i=0;
    k=n;
    char cord[100];
    POINT cursor;
    while(k){
        GetCursorPos(&cursor);
        xx=cursor.x;
        yy=cursor.y;
        if(GetAsyncKeyState(VK_LBUTTON)){
            setcolor(10);circle(xx,yy,1);
            setcolor(8);circle(xx,yy,2);
            setcolor(6);circle(xx,yy,3);
            setcolor(4);circle(xx,yy,4);
            setcolor(10);circle(xx,yy,5);
            delay(400);
            first.x=xx;
            first.y=yy;
            inputs.push_back(first);
            settextstyle(10,0,1);
            sprintf(cord,"( %d,%d )",xx,yy);
            outtextxy(xx+10,yy,cord);
            i++;k--;
        }
    }

	quickHull(inputs);
	//cout<<inputs[1].x;
	/*for(int i=0;i<convexHull.size();i++){
		cout<<"x "<<convexHull[i].x<<"  y"<<convexHull[i].y<<"\n";
	}*/

	for (int i = 0; i < convexHull.size();i++)
	{
		cout<<convexHull[i].x<<" "<<convexHull[i].y<<endl;
        setcolor(YELLOW);line(convexHull[i].x,convexHull[i].y,convexHull[(i+1)%convexHull.size()].x,convexHull[(i+1)%convexHull.size()].y);
	}

	delay(150);
    getch();
    closegraph();
    return 0;
}

void quickHull(vector<struct locations> inputs){
	int minindex=0,maxindex=0,minx=inputs[0].x,maxx=inputs[0].x;
	for(int i=0;i<inputs.size();i++){
		if(inputs[i].x<minx){
			minx=inputs[i].x;
			minindex=i;
		}
		if(inputs[i].x>maxx){
			maxx=inputs[i].x;
			maxindex=i;
		}
	}
	convexHull.push_back(inputs[minindex]);
	convexHull.push_back(inputs[maxindex]);
	vector<struct locations> S1,S2;
	float sloperef=(inputs[maxindex].y-inputs[minindex].y)/(inputs[maxindex].x-inputs[minindex].x);
	for(int i=0;i<inputs.size();i++){
		if(i==minindex || i==maxindex){
			continue;
		}
		if((inputs[i].y-inputs[minindex].y)/(inputs[i].x-inputs[minindex].x)<sloperef){
			S1.push_back(inputs[i]);
		}
		if((inputs[i].y-inputs[minindex].y)/(inputs[i].x-inputs[minindex].x)>sloperef){
			S2.push_back(inputs[i]);
		}
	}
	//cout<<S1.size();
	//cout<<S2.size();
	findHull(S1,inputs[minindex],inputs[maxindex]);
	findHull(S2,inputs[maxindex],inputs[minindex]);
	//clockwise setting convex hull
	for(int i=0;i<convexHull.size();i++){
        if(convexHull[i].x==inputs[minindex].x && convexHull[i].y==inputs[minindex].y){
            struct locations temp=convexHull[i];
            convexHull[i]=convexHull[0];
            convexHull[0]=temp;
            break;
        }
    }
    vector<float> slopes;
    slopes.push_back((0.0));
    for(int i=1;i<convexHull.size();i++){
        slopes.push_back((convexHull[i].y-convexHull[0].y)/(convexHull[i].x-convexHull[0].x));
    }
    //for(int i=0;i<slopes.size();i++){
    //    cout<<" "<<slopes[i];
    //}
    //cout<<"\n";
    for(int i=1;i<slopes.size()-1;i++){
        for(int j=i+1;j<slopes.size();j++){
            if(slopes[j]>slopes[i]){
                float temp=slopes[j];
                slopes[j]=slopes[i];
                slopes[i]=temp;
                struct locations sectemp=convexHull[i];
                convexHull[i]=convexHull[j];
                convexHull[j]=sectemp;
            }
        }
    }
    //for(int i=0;i<slopes.size();i++){
    //    cout<<" "<<slopes[i];
    //}
    //cout<<"\n";
}

void findHull(vector<struct locations> Sk,struct locations P,struct locations Q){
	if(Sk.size()==0){
		return;
	}
	float maxdistance=0,maxindex=0;
	float m=(Q.y-P.y)/(Q.x-P.x);
	float denominator=sqrt(m*m +1);
	for(int i=0;i<Sk.size();i++){
		float distance=abs(m*Sk[i].x - Sk[i].y + P.y - m*P.x)/denominator;
		if(distance>maxdistance){
			maxdistance=distance;
			maxindex=i;
		}
	}
	convexHull.push_back(Sk[maxindex]);
	struct locations C=Sk[maxindex];
	vector<struct locations> S1,S2;
	float sloperefS1=(C.y-P.y)/(C.x-P.x);
	float sloperefS2=(Q.y-C.y)/(Q.x-C.x);
	for(int i=0;i<Sk.size();i++){
		if(i==maxindex){
			continue;
		}
		if((Sk[i].y-P.y)/(Sk[i].x-P.x)<sloperefS1){
			S1.push_back(Sk[i]);
		}
		if((Q.y-Sk[i].y)/(Q.x-Sk[i].x)>sloperefS2){
			S2.push_back(Sk[i]);
		}
	}
	findHull(S1,P,C);
	findHull(S2,C,Q);
}

