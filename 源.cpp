#include<graphics.h>
#include<stdio.h>
#include<ege\sys_edit.h>
int rand()
{
	return random(65536);
}
struct Tickets
{
	float now_money = 0, bought_money = 0, usedmoney[10] = { 0 };
	int owned_number=0,seed=50;
	int updown;
}ticket[5];
struct Player
{
	float money=10000, debt=11000;
	int day=1;
	
}player;
void change()
{
	int m;
	for (int i = 0; i < 5; i++)
	{
		ticket[i].updown = 0;

		
		
			m = rand() % 100;
			double up;
			up = (rand() % 1000) / 10000.0;

			if (m > ticket[i].seed)
			{
				ticket[i].updown = 1;
				ticket[i].seed++;
				if (ticket[i].seed > 70)
					ticket[i].seed = 70;
				up = 0-up;
			}
			if (m <= ticket[i].seed)
			{
				ticket[i].updown = -1;
				ticket[i].seed--;
				if (ticket[i].seed < 30)
					ticket[i].seed = 30;

			}
			up = 1 + up;
			ticket[i].now_money = ticket[i].now_money* up;

			for (int j = 0; j < 9; j++)
				ticket[i].usedmoney[j] = ticket[i].usedmoney[j + 1];
			ticket[i].usedmoney[9] = ticket[i].now_money;
			if (ticket[i].usedmoney[9]> ticket[i].usedmoney[8])
				ticket[i].updown = 1;
			else
				ticket[i].updown = -1;

	}
	
}
void first()
{
	for (int i = 0; i < 5; i++)
	{
		ticket[i].owned_number = 0;
		ticket[i].updown = 0;
		ticket[i].now_money = rand() % 100/100.0*10;
		ticket[i].seed = 50;
		for (int j = 0,m; j < 15; j++)
		{
			m = rand() % 100;
			double up;
			up =( rand() % 1000 )/ 10000.0;
	
			if (m > ticket[i].seed)
			{
				ticket[i].updown = -1;
				ticket[i].seed ++;
				if (ticket[i].seed > 70)
					ticket[i].seed = 70;
				up = 0 - up;
			}
			if(m<=ticket[i].seed)
			{
				ticket[i].updown = 1;
				ticket[i].seed--;
				if (ticket[i].seed < 30)
					ticket[i].seed = 30;
				
			}
			ticket[i].now_money = ticket[i].now_money*(1+up);

			ticket[i].usedmoney[j] = ticket[i].now_money;
			if (ticket[i].now_money > ticket[i].usedmoney[8])
				ticket[i].updown = 1;
			else
				ticket[i].updown = -1;
		}
		ticket[i].owned_number = 0;
		ticket[i].bought_money = 0;
		ticket[i].seed = 50;
		if (ticket[i].usedmoney[9] > ticket[i].usedmoney[8])
			ticket[i].updown = 1;
		else
			ticket[i].updown = -1;
	}

}
void drawK(int num)
{
	randomize();
	cleardevice();
	xyprintf(0,0,"�۸�����ͼ");
	rectangle(20, 50, 380, 350);
	setcolor(EGERGB(255, 255, 255));
	setfillcolor(EGERGB(255, 255, 255));
		fillellipse(20, 200, 5, 5);
		float number[10];
	for (int i =0 ; i < 10; i++)
	{
		
		number[i] = ticket[num].usedmoney[i];
		
	}
	for (int i = 0; i<9; ++i)  //�Ƚ�n-1��
	{
		for (int j = 0,buf; j<9- i; ++j)  //ÿ�ֱȽ�n-1-i��,
		{
			if (number[j] < number[j + 1])
			{
				buf = number[j];
				number[j] = number[j + 1];
				number[j + 1] = buf;
			}
		}
	}
	int a = ticket[num].usedmoney[0];
	float max = number[0], min = number[9];
	float b;
	if ((max - a)>(a - min))
		b = 150 / (float)(max - a);
	else 
		b = 150 / (float)(a - min);
	for (int i=1; i < 10; i++)
	{
		if ((ticket[num].usedmoney[i - 1] - ticket[num].usedmoney[i])>0)
		{
			setcolor(EGERGB(0, 255, 0));
			setfillcolor(EGERGB(0, 255, 0));
		}
		else
		{
			setcolor(EGERGB(255, 0, 0));
			setfillcolor(EGERGB(255, 0, 0));
		}
		line(40 * i - 20, 200 - (ticket[num].usedmoney[i - 1] - ticket[num].usedmoney[0])*b, 40 * i + 20, 200 - (ticket[num].usedmoney[i] - ticket[num].usedmoney[0])*b);
		fillellipse(40 * i + 20, 200 - (ticket[num].usedmoney[i] - ticket[num].usedmoney[0])*b, 5, 5);
	}
	getch();
}
void draw()
{
	setcolor(WHITE);
	setbkcolor(BLACK);
	setfont(20, 0, "����");
	xyprintf(0, 10, "����     �۸�  �����  ������");
	setfont(15, 0, "����");
	if (ticket[0].updown==1)
		setcolor(EGERGB(255,0,0));
	if (ticket[0].updown == -1)
		setcolor(EGERGB(0, 255, 0));
	xyprintf(0, 35,  "���������� %5.2f   %5.2f	        %d", ticket[0].now_money, ticket[0].bought_money, ticket[0].owned_number);
	if (ticket[1].updown==1)
		setcolor(EGERGB(255, 0, 0));
	if (ticket[1].updown == -1)
		setcolor(EGERGB(0, 255, 0));
	xyprintf(0, 60,  "��ѧ�ý��� %5.2f   %5.2f	        %d", ticket[1].now_money, ticket[1].bought_money, ticket[1].owned_number);
	if (ticket[2].updown ==1)
		setcolor(EGERGB(255, 0, 0));
	if (ticket[2].updown == -1)
		setcolor(EGERGB(0, 255, 0));
	xyprintf(0, 85,  "��׬Ǯ��� %5.2f   %5.2f        %d", ticket[2].now_money, ticket[2].bought_money, ticket[2].owned_number);
	if (ticket[3].updown ==1)
		setcolor(EGERGB(255, 0, 0));
	if (ticket[3].updown == -1)
		setcolor(EGERGB(0, 255, 0));
	xyprintf(0, 110, "���ٴ��� %5.2f   %5.2f	        %d", ticket[3].now_money, ticket[3].bought_money, ticket[3].owned_number);
	if (ticket[4].updown ==1)
		setcolor(EGERGB(255, 0, 0));
	if (ticket[4].updown == -1)
		setcolor(EGERGB(0, 255, 0));
	xyprintf(0, 135, "�����ܿƼ� %5.2f   %5.2f	        %d", ticket[4].now_money, ticket[4].bought_money, ticket[4].owned_number);
	setcolor(EGERGB(255, 255, 255));
	for (int i = 0; i < 5; i++)
	{
		circle(320, 42+25*i, 10);
		circle(350, 42 + 25 * i, 10);
		outtextxy(316, 35 + 25 * i, "+");
		outtextxy(346, 35 + 25 * i, "-");
	}
	line(0, 200, 400, 200);
	xyprintf(0, 210, "���:%6.2f Ƿ��:%5.2f ��%d��", player.money, player.debt, player.day);
	setfillcolor(LIGHTGRAY);
	
	setcolor(WHITE);
	setfont(20, 0, "system");
	

	bar3d(50, 250, 150, 300, 5, true);
	bar3d(250, 250, 350, 300, 5, true);
	setfontbkcolor(LIGHTGRAY);
	xyprintf(65, 265, "��һ��");
	xyprintf(275, 265, "����");

}
int BackMoney()
{
	setcolor(EGERGB(255, 255, 255));
	setfont(20, 0, "����");
	setfontbkcolor(BLACK);
wrong:
	cleardevice();
	xyprintf(20, 20, "������Ҫ����Ľ��");
	flushkey();
	char text[15] = "";
	sys_edit editbox;
	editbox.create(true);
	editbox.move(50, 100);
	editbox.size(250, 40);
	editbox.setbgcolor(BLACK);
	editbox.setcolor(WHITE);
	editbox.setfont(20, 0, "����");
	editbox.visible(true);
	char buffersize[50];
	float n = 0;
	bool onlynum = true;
	editbox.setfocus();
	for (; is_run(); delay_jfps(60))
	{

		onlynum = true;
		bool isOutput = false;
		while (kbmsg())
		{
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up))
			{
				isOutput = true;
			}
		}
		if (isOutput)
		{
			editbox.gettext(50, buffersize);
			editbox.destroy();
			break;
		}



	}
	editbox.destroy();
	cleardevice();
	sscanf(buffersize, "%f", &n);
	if ( n<0||n>player.money)
		goto wrong;
	flushkey();
	if (n > player.debt)
	{
		player.debt = 0;
		player.money -= player.debt;
		return 0;
	}
	else
	{
		player.debt -= n;
		player.money -= n;
		return 0;
	}
	
}
void buy(int num)
{ 
	setcolor(EGERGB(255, 255, 255));
	setfont(20, 0, "����");
	setfontbkcolor(BLACK);
wrong:
	cleardevice();
	xyprintf(20, 20, "������Ҫ���������");
	flushkey();
	char text[15] = "";
	sys_edit editbox;
	editbox.create(true);
	editbox.move(50, 100);
	editbox.size(250, 40);
	editbox.setbgcolor(BLACK);
	editbox.setcolor(WHITE);
	editbox.setfont(20, 0, "����");
	editbox.visible(true);
	char buffersize[50];
	int n=0;
	bool onlynum = true;
	editbox.setfocus();
	for (; is_run(); delay_jfps(60))
	{
		
		onlynum = true;
		bool isOutput = false;
		while (kbmsg())
		{
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up))
			{
				isOutput = true;
			}
		}
		if (isOutput)
		{
			editbox.gettext(50, buffersize);
			editbox.destroy();
			break;
		}

		
		
	}
	editbox.destroy();
	sscanf(buffersize, "%d", &n);
	if (ticket[num].now_money*n>player.money||n<0)
		goto wrong;
	flushkey();
	ticket[num].owned_number += n;
	if (n != 0)
	{
		ticket[num].bought_money = (ticket[num].bought_money*(ticket[num].owned_number - n) + ticket[num].now_money*n) / ticket[num].owned_number;
	}
	player.money -= ticket[num].now_money*n;
}
void sell(int num)
{
	setcolor(EGERGB(255, 255, 255));
	setfont(20, 0, "����");
	setfontbkcolor(BLACK);
wrong:
	cleardevice();
	xyprintf(20, 20, "������Ҫ���۵�����");
	flushkey();
	char text[15] = "";
	sys_edit editbox;
	editbox.create(true);
	editbox.move(50, 100);
	editbox.size(250, 40);
	editbox.setbgcolor(BLACK);
	editbox.setcolor(WHITE);
	editbox.setfont(20, 0, "����");
	editbox.visible(true);
	char buffersize[50];
	int n = 0;
	bool onlynum = true;
	editbox.setfocus();
	for (; is_run(); delay_jfps(60))
	{

		onlynum = true;
		bool isOutput = false;
		while (kbmsg())
		{
			key_msg msg = getkey();
			if ((msg.key == key_enter) && (msg.msg == key_msg_up))
			{
				isOutput = true;
			}
		}
		if (isOutput)
		{
			editbox.gettext(50, buffersize);
			editbox.destroy();
			break;
		}



	}
	editbox.destroy();
	sscanf(buffersize, "%d", &n);
	if (n>ticket[num].owned_number||n<0)
		goto wrong;
	flushkey();
	ticket[num].owned_number -= n;
	if (ticket[num].owned_number == 0)
		ticket[num].bought_money = 0;
	player.money += ticket[num].now_money*n;
}
void game()
{
	cleardevice();
	delay_fps(120);
	setcolor(WHITE);
	if (player.debt < 0.01)
		player.debt = 0;
	mouse_msg msg;
	for (; (player.money < 100000) || (player.debt > 0);delay_jfps(60),player.day++, player.debt *= 1.004)
	{ leap:
		change();
		for (; (player.money < 100000) || (player.debt > 0); delay_jfps(60))
		{
			solution:
			cleardevice();
			mouse_msg msg = { 0 };
			draw();

			while (mousemsg())
			{
				msg = getmouse();
			}
			if (msg.is_left() && msg.is_down())
			{
				int i;
				i = msg.y - 30;
				i = (i - (i % 25)) / 25;
				if (i <= 4)
				{
					if (msg.x < 300) drawK(i);
					else if (msg.x >= 300 && msg.x < 335) buy(i);
					else if (msg.x >= 335) sell(i);
				}
				else {
					if (msg.x >= 50 && msg.x <= 150 && msg.y >= 250 && msg.y <= 300)
						break;
					else if (msg.x >= 250 && msg.x <= 350 && msg.y >= 250 && msg.y <= 300)
					{
						BackMoney(); 
						goto solution;
					}
					
				}
			}
			
		}
	}
}
int main()
{
	first();
	randomize();
	setcaption(L"�ϲ����ɼ�");
	initgraph(400, 600, INIT_RENDERMANUAL|INIT_WITHLOGO);
	
	setbkcolor(WHITE);
	setfont(70, 0, "����");
	setcolor(BLACK);
	outtextxy(25, 0, "�ϲ����ɼ�");
	setfont(50, 0, "����");
	outtextxy(50, 200, "������Ĵ���");
	sys_edit inpush;
	inpush.create(true);
	inpush.move(50, 270);
	inpush.size(300, 45);
	inpush.setcolor(BLACK);
	inpush.setfont(40, 0, "����");
	inpush.visible(true);
	delay_fps(60);
	inpush.settext("����Ǯ");
	inpush.setfocus();
	const int buffSize = 100;
	char strBuffer[100] = "";
	int buffLen = 0;
	for (; is_run(); delay_fps(60))
	{
		bool isOutput=false;
			while (kbmsg())
			{
				key_msg msg=getkey();
					if ((msg.key == key_enter) && (msg.msg == key_msg_up))
					{
						isOutput=true;
					}
			}
		if (isOutput)
		{
			inpush.gettext(buffSize, strBuffer);
			inpush.destroy();
			break;
		}
	}
	cleardevice();
		setfont(30, 0, "����");
	rectprintf(20, 20, 380, 580,"%s,�㱾����ԣ���������������˳��ɶ�ѩ�ϼ�˪����������⣬��Ƿ����11000��Ǯ������������������ڵ�10000Ԫ��װ��win7��MacBook��ȥ���д���һ����\nĿ��:\n1.�������д���\n2.�ﵽ100000Ԫ\n����:��������ÿ��0.4%\n�����ƿɲ鿴����",strBuffer);
	getch();


	game();
	cleardevice();
	setfontbkcolor(BLACK);
	setfont(20, 0, "����");
	xyprintf(0, 0, "�𾴵� %s����׬ȡ100000����%d��",strBuffer, player.day);
	getch();
	
}