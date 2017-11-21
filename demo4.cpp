//#define width 640
//#define high 480
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<time.h>
void main()
{
	initgraph(640, 480);		//定义画布
	int rectWidth = 640 / 16;	//定义格子大小
	int rectHeight = (480 - 40) / 8;
	srand((unsigned)time(NULL));//随机数种子
//	int k;
	for (int i = 0; i<8; i++)//画出16*8的画板
	{
		for (int j = 0; j<16; j++)
		{
			setcolor(RED);
			setfillcolor(WHITE);
			fillrectangle(rectWidth*j, rectHeight*i, rectWidth*j + rectWidth, rectHeight*i + rectHeight);
		};
	}
	int a[16];//用数组记录鼠标位置的颜色,使用16*3的数组存储随机颜色
	int c[16][3];
	for (int i = 0; i < 16; i++)		//取随机颜色
	{
		for (int j = 0; j < 3; j++)
		{
			c[i][j] = rand() % 255;
		}
		a[i] = i;						//用a[i]记录颜色的顺序
	}
	for (int b = 0; b<16; b++)			//画取色版
	{
		setcolor(BLUE);
		setfillcolor(RGB(c[b][0], c[b][1], c[b][2]));
		fillrectangle(b*rectWidth, 480 - 40, rectWidth*b + rectWidth, 480);
	}
	MOUSEMSG m;				//定义鼠标	
	while (1)
	{
		if (MouseHit())		//接收鼠标消息
		{
			m = GetMouseMsg();
			if (m.mkLButton)//鼠标点击的判断
			{
				if (m.y >= (480 - 40))		//鼠标在取色区域，并取颜色
				{
					for (int l = 0; l < 16; l++)
					{
						if (m.x >= l*rectWidth&&m.x <= (l + 1)*rectWidth)
						{
							setfillcolor(RGB(c[l][0], c[l][1], c[l][2]));
							//fillcircle(m.x, m.y - 120, 10);
							//k = l;
						}
					}
				}
				if(! (m.y >= (480 - 40)))		//鼠标不在取色区域，点击任意格子填充颜色
				{
					for (int i = 0; i < 8; i++)
					{
						for (int j = 0; j < 16; j++)
						{
							if ((m.x >= j * 40 && m.x <= (j + 1) * 40) && (m.y >= i * 55 && m.y <= (i + 1) * 55))
							{
								//setfillcolor(RGB(c[a[j]][0], c[a[j]][1], c[a[j]][2])); 
								//setfillcolor(RGB(c[k][0], c[k][1], c[k][2]));
								fillrectangle(j * 40, i * 55, (j + 1) * 40, (i + 1) * 55);
							}
						}
					}
				}
			}
		}
	}
	closegraph();
	_getch();
}
