#include <graphics.h> 
#include <conio.h> 
#define PI 3.14159265 
void showhead();	//输出头
void showhand();	//输出手
void showbody();
void main() {
	initgraph(800, 600);
	setorigin(400, 300);
	setbkcolor(WHITE); 

	cleardevice();
	showhead();					//头
	showhand();
	showbody();
	setfillcolor(RED);				//脖子
	fillroundrect(-50, -130, 50, -120, 15, 15);
	setfillcolor(YELLOW);		//铃铛
	fillcircle(0, -115, 10);
	setlinecolor(BLACK);		//铃铛的线
	line(-9, -118, 9, -118);
	line(-8, -121, 8, -121);
	line(0, -110, 0, -105);
	putpixel(0, -110, BLACK);
	
	//showbody();
	_getch();
	closegraph();
}
void showhead()
{
	setfillcolor(BLUE);		//头
	setlinecolor(BLACK);
	fillcircle(0, -200, 80);
	setfillcolor(WHITE);	//脸
	fillcircle(0, -190, 70);
	setfillcolor(WHITE);	//眼睛
	fillcircle(-20, -250,20);
	fillcircle(20, -250, 20);
	setfillcolor(BLACK);	//眼球
	fillcircle(-10, -250, 5);
	fillcircle(10, -250, 5);
	setfillcolor(RED);		//鼻子
	fillcircle(0, -232, 7);
	setlinecolor(BLACK);	//胡须加人中
	line(0, -225, 0, -160);
	line(-10, -210, -50, -215);
	line(-10, -200, -60, -200);
	line(-10, -190, -50, -185);
	line(10, -210, 50, -215);
	line(10, -200, 60, -200);
	line(10, -190, 50, -185);
	line(-30, -160, 30, -160);
}
void showhand()
{
	/*setlinecolor(BLACK);
	line(-48, -120, -85, -90);
	line(-48, -95, -70, -75);
	line(48, -120, 85, -90);
	line(48, -95, 70, -75);*/
	//floodfill(-47, -100, BLACK);
	setfillcolor(WHITE);		//手
	circle(-85, -75, 15);
	circle(85, -75, 15);
	setfillcolor(BLUE);			//多边形画身体
	POINT pts[] = { { -48, -120 },{ -85, -90 },{ -70,-75 },{ -48,-95 },{ -48,-30 },{-3,-30},{0,-35},{3,-30}, { 48,-30 },{ 48,-95 },{ 70,-75 },{ 85,-90 },{ 48,-120 } };
	fillpolygon(pts, 13);
}
void showbody()
{
	/*setfillcolor(BLUE);
	setlinecolor(WHITE);
	fillroundrect(-48, -120, 48, -30, 5, 5);*/
	
	setfillcolor(WHITE);		//口袋
	setlinecolor(BLACK);
	fillcircle(0, -95, 35);
	circle(0, -100, 20);
	setlinecolor(WHITE);
	fillrectangle(-20, -120, 20, -100);
	setlinecolor(BLACK);
	line(-20, -100, 20, -100);
//	arc(-20, -100, 20, -100, -45.0, 45.0);

	setlinecolor(BLACK);
	line(-48, -100, -48, -30);
	line(48, -100, 48, -30);
	setfillcolor(WHITE);
	fillroundrect(-55, -30, 0, -15, 20, 20);
	fillroundrect(0, -30, 55, -15, 20, 20);
	//setfillcolor(BLUE);
	//fillroundrect(-48, -120, 48, -30, 5, 5);
}