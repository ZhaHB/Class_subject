#include"mysubject.h"
int main()
{	
	char ch='a';
	DEP *head = NULL;
	load_list(&head);
	pphead = head;
	initgraph(800, 500);// 初始化图形窗口
	Change_mid();
	Change_infor();
	Change_CB();
	input();
	//save_list(head);
	closegraph();
	return 0;
}

void Change_mid(void)
{
	int i = 60, n = 0;
	while (n != 5)
	{
		mid[n].x1 = 0;
		mid[n].x2 = 100;
		mid[n].y1 = i;
		mid[n].y2 = i + 25;
		mid[n].sit = 1;
		mid[n].on = 1;
		i = i + 25;
		n++;
	}
}
void Change_infor(void)
{
	int i = 140, n = 0;
	while (n != 9)
	{
		infor[n].x1 = 140;
		infor[n].x2 = 750;
		infor[n].y1 = i;
		infor[n].y2 = i + 30; 
		infor[n].sit = 1;
		infor[n].on = 0;
		i = i + 30;
		n++;
	}
}

void Change_CB(void)
{
	int i = 140, n = 0;
	while (n != 9)
	{
		Chang_block[n].x1 = 200;
		Chang_block[n].x2 = 500;
		Chang_block[n].y1 = i;
		Chang_block[n].y2 = i + 30;
		Chang_block[n].sit = 1;
		Chang_block[n].on = 0;
		i = i + 30;
		n++;
	}
}

void background()
{
	draw_all_blocks();
	out_dep_cot(pphead);
	out_grp_cot();
	out_sub_cot();
	draw_all_txt();
	setbkmode(TRANSPARENT);
	setcolor(RGB(50,50,50));
	LOGFONT f;
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 18;                      // 设置字体高度
	f.lfWidth = 10;
	_tcscpy(f.lfFaceName, _T("宋体"));    // 设置字体为“黑体”
	settextstyle(&f);                     // 设置字体样式
	outtextxy(10, 5, _T("科研项目"));
	outtextxy(10, 35, _T("管理系统"));
	f.lfHeight = 15;
	f.lfWidth = 8;
	f.lfWeight = 10;
	_tcscpy(f.lfFaceName, _T("黑体"));
	settextstyle(&f);
	outtextxy(10, 65, "文件(D)");
	outtextxy(10, 90, "数据维护(F)");	
	outtextxy(10, 115, "数据查询(S)");
	outtextxy(10, 140, "数据统计(T)");
	outtextxy(10, 165, "帮助(H)");
}

void draw_block(BLOCK a)
{
	if (a.on == 0)
		return;
	if (a.sit == 0)
		setfillcolor(RGB(173, 216, 230));
	else if (a.sit == 1)
		setfillcolor(RGB(245, 245, 245));
	else if(a.sit==2)
		setfillcolor(RGB(240, 240, 240));
	else if (a.sit == 3)
		setfillcolor(RGB(0, 191, 255));
	else if (a.sit == 4)
		setfillcolor(RGB(100,149,237));
	else
		setfillcolor(WHITE);
	fillrectangle(a.x1, a.y1, a.x2, a.y2);
	setcolor(BLACK);
	line(a.x1, a.y1, a.x1, a.y2);
	line(a.x1, a.y1, a.x2, a.y1);
	line(a.x2, a.y1, a.x2, a.y2);
	line(a.x1, a.y2, a.x2, a.y2);
}


void draw_fblock(FBLOCK a)
{
	if (a.bl.on == 0)
		return;
	draw_block(a.bl);
	setbkmode(TRANSPARENT);
	setcolor(BLACK);
	LOGFONT f;
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = a.height;                      // 设置字体高度
	f.lfWidth = a.width;
	f.lfWeight = 1;
	_tcscpy(f.lfFaceName, _T("黑体"));    // 设置字体为“黑体”
	settextstyle(&f);                     // 设置字体样式
	outtextxy(a.x,a.y,a.s);
}

void draw_all_blocks(void)
{
	int  n = 0;
	draw_block(top);
	draw_block(right);
	draw_block(bottom);
	for (n=0;n != 5;n++)
	{
	    draw_block(mid[n]);
	}
	draw_fblock(ftitle);
	draw_fblock(fCOT);
	for (n=0; n != 9; n++)
	{
		draw_block(infor[n]);
	}
	for (n=0; n != 9; n++)
	{
		draw_block(Chang_block[n]);
		if (Chang_block[n].on == 1&&infor_of_dep_search[0].on==0&&infor_of_grp_search[0].on==0&&infor_of_sub_search[0].on==0)
			line(350, 140, 350, 410);
	}
	for (n=0; n != 3; n++)
	{
		draw_fblock(fixss[n]);
	}
	for (n=0; n != 3; n++)
	{
		draw_fblock(fchoice[n]);
	}
	for (n=0; n != 3; n++)
	{
		draw_fblock(fsearch_block[n]);
	}
	for (n=0; n != 5; n++)
	{
		draw_fblock(fcount_block[n]);
	}
}

void draw_txt(MT a)
{
	if (a.on == 1)
	{
		outtextxy(a.x, a.y, a.s);
	}
}

void draw_all_txt(void)
{
	int n = 0;
	setcolor(BLUE);
	LOGFONT f;
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 16;                      // 设置字体高度
	f.lfWidth = 7;
	f.lfWeight = 100;
	_tcscpy(f.lfFaceName, _T("黑体"));    // 设置字体为“黑体”
	settextstyle(&f);
	draw_txt(information_of_change);
	setcolor(BLACK);
	for (n = 0; n != 3; n++)
	{
		draw_txt(information_of_change1[n]);
		draw_txt(information_of_change2[n]);
	}
	for (n = 0; n != 4; n++)
	{
		draw_txt(information_of_change3[n]);
		draw_txt(information_of_change4[n]);
	}
	for (n = 0; n != 5; n++)
	{
		draw_txt(information_of_change5[n]);
		draw_txt(information_of_change6[n]);
	}
	for (n = 0; n != 2; n++)
	{
		setcolor(BLUE);
		draw_txt(infor_of_dep_search[n]);
		draw_txt(infor_of_grp_search[n]);
		draw_txt(infor_of_sub_search[n]);
		setcolor(BLACK);
	}

	if (information_of_group[0].on == 1)
	{
		line(280, 140, 280, 410);		
		line(350, 140, 350, 410);
		line(420, 140, 420, 410);
		line(500, 140, 500, 410);
		line(600, 140, 600, 410);
		line(680, 140, 680, 410);
		setcolor(BLUE);
		for (n = 0; n != 6; n++)
		{
			draw_txt(information_of_group[n]);
		}
		setcolor(BLACK);
	}
	if (information_of_subjects[0].on == 1)
	{
		line(240, 140, 240, 410);
		line(300, 140, 300, 410);
		line(370, 140, 370, 410);
		line(450, 140, 450, 410);
		line(530, 140, 530, 410);
		line(600, 140, 600, 410);
		line(680, 140, 680, 410);
		setcolor(BLUE);
		for (n = 0; n != 7; n++)
		{
			draw_txt(information_of_subjects[n]);
		}
		setcolor(BLACK);
	}
	if (information_of_department[0].on == 1)
	{
		line(270, 140, 270, 410);
		line(400, 140, 400, 410);
		line(600, 140, 600, 410);
		line(680, 140, 680, 410);
		setcolor(BLUE);
		for (n = 0; n != 3; n++)
		{
			draw_txt(information_of_department[n]);
		}
		setcolor(BLACK);
	}
}

void statics(int a)
{
	int n = 0;
	if (a == 0)//修改长条框
	{
		for (n = 0; n < 9; n++)
		{
			infor[n].on = infor[n].on^ 1;
		}
	}
	else if (a == 1)
	{
	  mid[1].sit =mid[1].sit^1;
	  for (n = 0; n != 3; n++)
	  {
		fixss[n].bl.on = (fixss[n].bl.on) ^ 1;
	  }
	}
	else if (a == 2)//修改修改院系时的信息框
	{
		for (n = 0; n < 9; n++)
		{
			Chang_block[n].on = Chang_block[n].on^ 1;
		}
	}
	else if (a == 3)//修改修改院系时的文本
	{

		for (n = 0; n < 3; n++)
		{
			information_of_change1[n].on = information_of_change1[n].on ^ 1;
			information_of_change2[n].on = information_of_change2[n].on ^ 1;
		}
	}
	else if (a == 4)
	{
		for (n = 0; n < 7; n++)
		{
			information_of_group[n].on =( information_of_group[n].on )^ 1;
		}
	}
	else if (a == 5)
	{
		Group_change.on = Group_change.on ^ 1;
		for (n = 0; n < 4; n++)
		{
			information_of_change3[n].on = information_of_change3[n].on ^ 1;
			information_of_change4[n].on = information_of_change4[n].on ^ 1;
		}
	}
	else if (a == 6)
	{
		for (n = 0; n < 8; n++)
		{
			information_of_subjects[n].on =( information_of_subjects[n].on )^ 1;
		}
	}
	else if (a == 7)
	{
		Sub_change.on=Sub_change.on^1;
		for (n = 0; n < 5; n++)
		{
			information_of_change5[n].on = information_of_change5[n].on ^ 1;
			information_of_change6[n].on = information_of_change6[n].on ^ 1;
		}
	}
}

void input()
{
	char ch = 'a';
	char *a = "首页",*b="首页>院系数据维护",*c="首页>团队信息维护",*d="首页>项目信息维护";
	int flag=0,situation=1,n=1,max=0,mymax=0;
	int m;
	loadimage(&natsu, "natsu.jpg");
	DEP *p = pphead;
	GRP *pgrp;
	SUB *psub;
	while (ch != 'q'&&ch!='Q')
	{
		p = pphead;
		max = 0,mymax=0;
     	while (p != NULL)
	   {
			pgrp = p->head_group;
			while (pgrp != NULL)
			{
				psub = pgrp->head_subject;
				while (psub != NULL)
				{
					psub = psub->next;
					mymax++;
				}
		       max++;
			   pgrp = pgrp->next;
			}
		   p = p->next;
	   }
      max =(max-1) / 8 + 1;
	  mymax = (mymax - 1) / 8 + 1;
	  if (Group_change.count > max)
		  Group_change.count = max;
	  if (Sub_change.count > mymax)
		  Sub_change.count = mymax;
	  background();
	  if (flag == 0&&situation==1)
		  inputcs(1, &ch);
	  else if (flag == 2&&situation==1)
		  inputcs(2, &ch);
	  else if(situation==2||situation==3||situation==4)
		  inputcs(3, &ch);
	  if (situation == 1)
	  {
		ftitle.s = a;
		fCOT.bl.on = 0;
	    switch (flag)
	    {
	    case 0:
	        if (ch == 'f' || ch == 'F')
	        {
		      flag = 2;
			  statics(1);
			  break;
	        }
			else if (ch == 's' || ch == 'S')
			{
				Search();
				break;
			}
			else if (ch == 't' || ch == 'T')
			{
				Count();
				break;
			}
			else if (ch == 'h' || ch == 'H')
			{
				setcolor(BLUE);
				outtextxy(200, 100,"版权所有：华中科技大学计算机学院 陈宇航" );
				outtextxy(200, 150,"一切操作按照提示信息鼠标点击或键盘操作即可" );
				putimage(400, 200, &natsu);
				while(ch!='q'&&ch!='Q')
					inputcs(4, &ch);
				ch = 'P';
			}
	    case 2:
		    if (ch == 'f' || ch == 'F')
		    {
			    flag = 0;
			    statics(1);
			    break;
		    }
			else if (ch == 'a' || ch == 'A')
			{
				ftitle.s = b;
				statics(0);
			    statics(1);
				fCOT.bl.on = 1;
			    mid[1].sit = 0;
			    situation = 2;
				odcflag = 1;
				information_of_change.on = 1;
				flag = 0;
				break;
			}
			else if (ch == 'b' || ch == 'B')
			{
				ftitle.s = c;
				statics(0);
			    statics(1);
				statics(4);
				fCOT.bl.on = 1;
			    mid[1].sit = 0;	
		        Group_change.on = 1;
				information_of_change.on = 1;
				situation = 3;
				flag = 0;
				break;
			}
			else if (ch == 'c' || ch == 'C')
			{
				ftitle.s = d;
				statics(0);
			    statics(1);
				statics(6);
		        Group_change.on = 0;
				fCOT.bl.on = 1;
			    mid[1].sit = 0;
				situation = 4;
				information_of_change.on = 1;
				Sub_change.on = 1;
				flag = 0;
				break;
			}
	    }
	  }
	  else if (situation == 2)
	  {
		  if (ch == 'q' || ch == 'Q')
		  {
			  ch = 'p';
			  situation = 1;
			  ftitle.s = a;
			  mid[1].sit = 1;
			  fCOT.bl.on = 0;
			  statics(0);
			  Group_change.on = 0;
			  odcflag = 0;
			  information_of_change.on = 0;
		  }
		  else if(ch >= '1'&&ch <= '8') 
		  {
			  odcflag = 0;
			  statics(0);
			  statics(2);
			  change_department(ch);
		  }
		  else if ((ch >= 'a'&&ch <= 'i'))
		  {
			  if (ch == 'a')
				  pphead = pphead->next;
			  else
				  delect_department(ch);
		  }
		  else if (ch == 'p' || ch == 'P')
		  {
			  input_department();
		  }
	  }
	  else if (situation == 3)
	  {
		  if (ch == 'q' || ch == 'Q')
		  {
			  ch = 'p';
			  situation = 1;
			  ftitle.s = a;
			  mid[1].sit = 1;
			  fCOT.bl.on = 0;
			  statics(0);
			  statics(4);
			  Group_change.on = 0;
			  information_of_change.on = 0;
		  }
		  else if (ch == '_' || ch == '-')
		  {
			 if (Group_change.count > 1)
				  Group_change.count--;
		  }
		  else if (ch == '+' || ch == '=')
		  {
			  if (Group_change.count  < max)
				  Group_change.count ++;
		  }
		  else if (ch >= '1' &&ch <= '8')
		  {
			  statics(0);
			  statics(2);
			  statics(4);
			  Group_change.ch = ch;
			  change_group();
		  }
		  else if (ch >= 'a'&&ch <= 'i')
		  {
			  Group_change.ch = ch;
			  delect_group();
		  }
		  else if (ch == 'p' || ch == 'P')
		  {
			  input_group();
		  }
	  }
	  else if (situation == 4)
	  {
		  if (ch == 'q' || ch == 'Q')
		  {
			  ch = 'p';
			  situation = 1;
			  ftitle.s = a;
			  mid[1].sit = 1;
			  fCOT.bl.on = 0;
			  statics(0);
			  statics(6);
			  Group_change.on = 0;
			  Sub_change.on = 0;
			  information_of_change.on = 0;
		  }
		  else if (ch == '_' || ch == '-')
		  {
			  if (Sub_change.count > 1)
				  Sub_change.count--;
		  }
		  else if (ch == '+' || ch == '=')
		  {
			  if (Sub_change.count  < mymax)
				  Sub_change.count++;
		  }
		  else if (ch >= '1' &&ch <= '8')
		  {
			  statics(0);
			  statics(2);
			  statics(6);
			  Group_change.on = 0;
			  Sub_change.ch = ch;
			  change_subject();
		  }
		  else if (ch >= 'a'&&ch <= 'i')
		  {
			  Sub_change.ch = ch;
			  delect_subject();
		  }
		  else if (ch == 'p' || ch == 'P')
		  {
			  input_subject();
		  }
	  }
	}

}

void out_sub_cot(void)
{
	if (Sub_change.on == 0)
		return ;
	setcolor(BLACK);
	LOGFONT f;
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 16;                      // 设置字体高度
	f.lfWidth = 7;
	f.lfWeight = 100;
	_tcscpy(f.lfFaceName, _T("黑体"));    // 设置字体为“黑体”
	settextstyle(&f);
	int i, thiscount = 1;
	char ch1 = '1', cha = 'a';
	char s[10];
	DEP *p = pphead;
	GRP *pgrp = NULL;
	SUB *psub = NULL;
	for (thiscount = 1, i = 0; thiscount != Sub_change.count;)
	{
		if (pgrp == NULL)
			pgrp = p->head_group;
		while (pgrp != NULL&&i != 8)
		{
			if (psub == NULL)
				psub = pgrp->head_subject;
			while (psub != NULL&&i!= 8)
			{
				psub = psub->next;
				i++;
			}
			if(i!=8)
			pgrp = pgrp->next;
		}
		if (pgrp == NULL&&psub==NULL)
		{
		  while (pgrp == NULL)
		  {
			p = p->next, pgrp = p->head_group;
		  }
			psub=pgrp->head_subject;
		}
		if (psub == NULL)
		{
		  pgrp = pgrp->next;
		  while (pgrp == NULL)
		  {
			p = p->next, pgrp = p->head_group;
		  }
		  psub = pgrp->head_subject;
		}
		if (i == 8)
		{
			i = 0;
			thiscount++;
		}
	}
	for (i = 0; p != NULL&&i<8; p = p->next)
	{
		if (pgrp == NULL)
			pgrp = p->head_group;
		for (; pgrp != NULL&&i<8; pgrp = pgrp->next)
		{
			if (psub == NULL)
				psub = pgrp->head_subject;
			for (; psub != NULL&&i < 8; psub = psub->next, i++, ch1++, cha++)
			{
		    	outtextxy(160, 180 + 30 * i, psub->sname);
		    	outtextxy(265, 180 + 30 * i, psub->type);
		    	outtextxy(305, 180 + 30 * i, psub->time);
				gcvt(psub->money, 4, s);
				s[4] = '\0';
		    	outtextxy(385, 180 + 30 * i, s);
		    	outtextxy(455, 180 + 30 * i, psub->sperson);
		    	outtextxy(535, 180 + 30 * i, psub->gname);
		    	outtextxy(620, 180 + 30 * i, "修改:");
		    	outtextxy(660, 180 + 30 * i, ch1);
			    outtextxy(700, 180 + 30 * i, "删除:");
		     	outtextxy(740, 180 + 30 * i, cha);
			}
		}

	}
}

void out_grp_cot(void)
{
	if (Group_change.on == 0)
		return;
	int i,thiscount=1;
	char ch1 = '1',cha='a';
	char s[5];
	DEP *p = pphead;
	GRP *pgrp=NULL;
	setcolor(BLACK);
	LOGFONT f;
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 16;                      // 设置字体高度
	f.lfWidth = 7;
	f.lfWeight = 100;
	_tcscpy(f.lfFaceName, _T("黑体"));    // 设置字体为“黑体”
	settextstyle(&f);
	for (thiscount = 1,i=0; thiscount != Group_change.count;)
	{
		if(pgrp==NULL)
		pgrp = p->head_group;
		while (pgrp != NULL&&i != 8)
		{
			pgrp = pgrp->next;
			i++;
		}
		if (i == 8)
		{
			i = 0;
			thiscount++;
		}
		if (pgrp == NULL&&i!=8)
		{
			p = p->next, pgrp = p->head_group;
		}
	}
	for (i = 0; p != NULL&&i<8;p = p->next  )
	{
		if(pgrp==NULL)
		pgrp = p->head_group;
		for (; pgrp != NULL&&i<8; pgrp = pgrp->next,i++, ch1++, cha++)
		{
	     	outtextxy(165, 180 + 30 * i, pgrp->gname);
		    outtextxy(295, 180 + 30 * i, pgrp->person);
			_stprintf_s(s, "%d", pgrp->tp);
	     	outtextxy(365, 180 + 30 * i,s);
            _stprintf_s(s, "%d", pgrp->mp);
     		outtextxy(435, 180 + 30 * i, s);
     		outtextxy(515, 180 + 30 * i, pgrp->dname);
     		outtextxy(620, 180 + 30 * i, "修改:");
     		outtextxy(660, 180 + 30 * i, ch1);
    		outtextxy(700, 180 + 30 * i, "删除:");
    		outtextxy(740, 180 + 30 * i, cha);
		}

	}

}

void out_dep_cot(DEP *head)
{
	if (odcflag == 0)
		return;
	DEP *p = head;
	int i = 0;
	char ch1 = '1', cha = 'a';
	setcolor(BLACK);
	LOGFONT f;
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 16;                      // 设置字体高度
	f.lfWidth = 7;
	f.lfWeight = 100;
	_tcscpy(f.lfFaceName, _T("黑体"));    // 设置字体为“黑体”
	settextstyle(&f);
	line(270, 140, 270,410 );
	line(400, 140, 400,410 );
	line(600,140,600,410);
	line(680,140,680,410);
	setcolor(BLUE);
	outtextxy(165, 150, "院系名称");
	outtextxy(315,150,"负责人");
	outtextxy(465,150,"联系电话");
	outtextxy(603, 150, "录入信息(P)");
	setcolor(BLACK);
	 for(i=0;p!=NULL;i++,p=p->next,ch1++,cha++)
    {
    	outtextxy(165, 180+30*i,p->dname);
	    outtextxy(315,180+30*i,p->dperson);
     	outtextxy(465,180+30*i,p->dphone);
		outtextxy(620, 180 + 30 * i, "修改:");
		outtextxy(660, 180 + 30 * i, ch1);
		outtextxy(700, 180 + 30 * i, "删除:");
		outtextxy(740, 180 + 30 * i, cha);
    }
}

void change_department(char ch)
{
	DEP *p = pphead;
	char aaa = '1', cha = 'a';
	int i = 1;
	statics(3);
	while (cha != 'q'&&cha != 'Q')
	{
		for (aaa = '1'; aaa != ch&&p != NULL; aaa++)
		{
			p = p->next;
		}
		information_of_change2[0].s = p->dname;
		information_of_change2[1].s = p->dperson;
		information_of_change2[2].s = p->dphone;
		background();
		inputcs(4, &cha);
		if (cha == '1')
		{
			InputBox(p->dname, 20, "请输入新的院系信息：", "院系信息维护", p->dname, 250, 50, false);
		}
		else if (cha == '2')
		{
			InputBox(p->dperson, 20, "请输入新的负责人：", "院系信息维护", p->dperson, 250, 50, false);
		}
		else if (cha == '3')
		{
			InputBox(p->dphone, 20, "请输入新的联系电话：", "院系信息维护", p->dphone, 250, 50, false);
		}
	}
		statics(0);
		statics(2);
		odcflag = 1;
		statics(3);
}

void delect_department(char ch)
{
	char cha= 'b';
	DEP *p = pphead;
	for(cha='b';p->next->next!=NULL&&cha!=ch;cha++,p=p->next)
	{
	}
		p->next = p->next->next;
}

void input_department(void)
{
	DEP *p;
	p = (DEP *)malloc(sizeof(DEP));
	InputBox(p->dname, 20, "请输入新的院系名称：", "院系信息维护", "", 250, 50);
	InputBox(p->dperson, 20, "请输入新的负责人：", "院系信息维护","" , 250, 50);
	InputBox(p->dphone, 20, "请输入新的联系电话：", "院系信息维护","" , 250, 50);
	p->next = pphead;
	p->head_group = NULL;
	pphead = p;
}

void change_group()
{
	DEP *p = pphead;
	GRP *pgrp = NULL;
	char aaa = '1',cha='a',mys[5],yours[5];
	int i = 1, thiscount = 1;
	pgrp = p->head_group;
	for (thiscount = 1, i = 0; thiscount != Group_change.count;)
	{
		if (pgrp == NULL)
			pgrp = p->head_group;
		while (pgrp != NULL&&i != 8)
		{
			pgrp = pgrp->next;
			i++;
		}
		if (i == 8)
		{
			i = 0;
			thiscount++;
		}
		if (pgrp == NULL)
		{
			p = p->next, pgrp = p->head_group;
		}
	}
    	statics(5);
    	for (aaa = '1'; aaa != Group_change.ch&&p!=NULL; )
	   {
			if (pgrp == NULL)
				pgrp = p->head_group;
			while (aaa != Group_change.ch&&pgrp != NULL)
			{
				pgrp = pgrp->next;
				aaa++;
			}
	    	p = p->next;
	   }
			if (pgrp == NULL)
				pgrp = p->head_group;
	while (cha != 'q'&&cha != 'Q')
	{
    	information_of_change4[0].s = pgrp->gname;
    	information_of_change4[1].s = pgrp->person;
		_stprintf_s(mys,"%d", pgrp->tp);
     	information_of_change4[2].s = mys;
		_stprintf_s(yours,"%d", pgrp->mp);
     	information_of_change4[3].s = yours;
		background();
		inputcs(4, &cha);
		if (cha== '1')
		{
			InputBox( pgrp->gname, 20, "请输入新的团队名称：","团队信息维护",pgrp->gname,250,50,false);
		}
		else if (cha== '2')
		{
			InputBox(pgrp->person, 20, "请输入新的负责人：","团队信息维护", pgrp->person,250,50,false);
		}
		else if (cha== '3')
		{
			InputBox(mys, 20, "请输入新的教师人数：","团队信息维护",mys,250,50,false);
			sscanf(mys, "%d", &(pgrp->tp));
		}
		else if (cha == '4')
		{
			InputBox(yours, 20, "请输入新的研究生人数：","团队信息维护",yours,250,50,false);
			sscanf(yours, "%d", &(pgrp->mp));
		}
	}
	statics(5);
	statics(0);
	statics(2);
	statics(4);
}

void delect_group()
{
	DEP *p = pphead,*pp=pphead;
	GRP *pgrp = NULL,*ppgrp=NULL;
	char aaa = 'a',cha='a';
	int i = 1, thiscount = 1;
	pgrp = p->head_group;
	while (pp != NULL)
	{
	   pgrp = pp->head_group;
	   while (pgrp != NULL)
	   {
		   cha++;
		   pgrp = pgrp->next;
	   }
	   pp = pp->next;
	}
	if (Group_change.ch >= cha)
		return;
	pgrp = p->head_group;
	for (thiscount = 1, i = 0; thiscount != Group_change.count;)
	{
		if (pgrp == NULL)
			pgrp = p->head_group;
		while (pgrp != NULL&&i != 8)
		{
			ppgrp = pgrp;
			pgrp = pgrp->next;
			i++;
		}
		if (i == 8)
		{
			i = 0;
			thiscount++;
		}
		if (pgrp == NULL)
		{
			ppgrp = NULL;
			p = p->next, pgrp = p->head_group;
		}
	}
	for (aaa = 'a'; aaa != Group_change.ch&&p != NULL; )
	{
		if (pgrp == NULL)
			pgrp = p->head_group;
		while (aaa != Group_change.ch&&pgrp != NULL)
		{
			ppgrp = pgrp;
			pgrp = pgrp->next;
			aaa++;
		}
		p = p->next;
		if (pgrp == NULL)
		{
			ppgrp = NULL;
			pgrp = p->head_group;
		}
	}
	while (pgrp == NULL)
	{
		ppgrp =NULL;
		p = p->next;
		pgrp = p->head_group;
	}
	if (ppgrp == NULL)
		p->head_group = pgrp->next;
	else
		ppgrp->next = ppgrp->next->next;
}

void input_group()
{
	DEP *p = pphead;
	char ch1 = '1',ch[2];
	char cha[3]="1.";
	char  mys[5], yours[5];
	int i = 1;
	char s[200] = "请输入您想录入的团队所属的院系:\n";
	while (p != NULL)
	{
		cha[0] = ch1;
	    strcat(s, cha);
		strcat(s, p->dname);
		strcat(s, "\t");
		if(i%2==0)
		strcat(s, "\n");
		i++;
		ch1++;
		p = p->next;

	}
	p = pphead;
	InputBox(ch, 2, s, "团队信息维护", "1", 250, 50, false);

	if ((ch[0] > '0')&&(ch[0] < i + '0'))
	{
		GRP *pgrp;
		pgrp = (GRP *)malloc(sizeof(GRP));
		for(ch1='1';ch1!=ch[0];ch1++,p=p->next)
		{ }
		InputBox(pgrp->gname, 20, "请输入团队名称：", "团队信息维护");
		InputBox(pgrp->person, 20, "请输入负责人：", "团队信息维护");
		InputBox(mys, 20, "请输入教师人数：", "团队信息维护");
		sscanf(mys, "%d", &(pgrp->tp));
		InputBox(yours, 20, "请输入研究生人数：", "团队信息维护");
		sscanf(yours, "%d", &(pgrp->mp));
		strcpy(pgrp->dname , p->dname);
		pgrp->next = p->head_group;
		p->head_group = pgrp;
	}
}

void change_subject()
{
	statics(7);
	int i, thiscount = 1;
	char s[10],types[10];
	char aaa = '1', cha = 'a';
	DEP *p = pphead;
	GRP *pgrp = NULL;
	SUB *psub = NULL;


	for (thiscount = 1, i = 0; thiscount != Sub_change.count;)
	{
		if (pgrp == NULL)
			pgrp = p->head_group;
		while (pgrp != NULL&&i != 8)
		{
			if (psub == NULL)
				psub = pgrp->head_subject;
			while (psub != NULL&&i != 8)
			{
				psub = psub->next;
				i++;
			}
			if (i != 8)
				pgrp = pgrp->next;
		}
		if (i == 8)
		{
			i = 0;
			thiscount++;
		}
		if (pgrp == NULL&&i != 8)
		{
			p = p->next, pgrp = p->head_group;
		}
	}

		for (aaa = '1'; aaa != Sub_change.ch&&p != NULL; )
		{
			if (pgrp == NULL)
				pgrp = p->head_group;
			while (aaa != Sub_change.ch&&pgrp != NULL)
			{
				if (psub == NULL)
					psub = pgrp->head_subject;
				while (aaa != Sub_change.ch&&psub != NULL)
				{
					psub = psub->next;
     				aaa++;
				}
			     if(aaa != Sub_change.ch)
				pgrp = pgrp->next;
			}
            if(aaa != Sub_change.ch)
			p = p->next;
		}
		if (pgrp == NULL)
		{
			p = p->next;
			pgrp = p->head_group;
		}
		while (psub == NULL)
		{
			pgrp = pgrp->next;
		  while (pgrp == NULL)
		  {
			p = p->next;
			pgrp = p->head_group;
		  }
			psub = pgrp->head_subject;
		}
	while (cha != 'q'&&cha != 'Q')
	{
		information_of_change6[0].s = psub->sname;
		information_of_change6[1].s = types;
		information_of_change6[1].s[0] = psub->type;
		information_of_change6[1].s[1] = '\0';
		information_of_change6[2].s =psub->time;
		gcvt(psub->money, 4, s);
		information_of_change6[3].s = s;
		information_of_change6[4].s =psub->sperson;
		background();
		inputcs(4, &cha);
		if (cha == '1')
		{
			InputBox(psub->sname, 20, "请输入新的项目编号：", "项目信息维护", psub->sname, 250, 50, false);
		}
		else if (cha == '2')
		{
			InputBox(information_of_change6[1].s, 20, "请输入新的项目类别：", "项目信息维护", information_of_change6[1].s, 250, 50, false);
			psub->type=information_of_change6[1].s[0];
		}
		else if (cha == '3')
		{
			InputBox(psub->time, 20, "请输入新的起始时间：", "项目信息维护", psub->time, 250, 50, false);
		}
		else if (cha == '4')
		{
			InputBox(s, 20, "请输入新的项目经费：", "项目信息维护", s, 250, 50, false);
			psub->money = atof(s);
		}
		else if (cha == '5')
		{
			InputBox(psub->sperson, 20, "请输入新的项目负责人：", "项目信息维护", psub->sperson, 250, 50, false);
		}
		background();
	}
	statics(7);
	statics(0);
	statics(2);
	statics(6);
	Group_change.on = 0;
}

void delect_subject()
{
	int i, thiscount = 1;
	char s[10], types[10];
	char aaa = '1', cha = 'a';
	DEP *p = pphead,*p1=pphead;
	GRP *pgrp = NULL,*p2;
	SUB *psub = NULL,*ppsub=NULL,*p3;
	p = pphead;
	pgrp = p->head_group;
	psub = pgrp->head_subject;
	for (thiscount = 1, i = 0; thiscount != Sub_change.count;)
	{
		if (pgrp == NULL)
			pgrp = p->head_group;
		while (pgrp != NULL&&i != 8)
		{
			if (psub == NULL)
				psub = pgrp->head_subject;
			while (psub != NULL&&i != 8)
			{
				ppsub = psub;
				psub = psub->next;
				i++;
			}
			if (i != 8)
				pgrp = pgrp->next;
		}
		if (i == 8)
		{
			i = 0;
			thiscount++;
		}
		if (pgrp == NULL&&i != 8)
		{
			p = p->next, pgrp = p->head_group;
		}
	}
	p1 = p;
	p2 = pgrp;
	p3 = psub;
	while (p1!= NULL)
	{
		if(p2==NULL)
		p2 = p1->head_group;
		while (p2 != NULL)
		{
			if(p3==NULL)
			p3 = p2->head_subject;
			while (p3 != NULL)
			{
				p3= p3->next;
				cha++;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
	if (Sub_change.ch >= cha)
		return;
	for (aaa = 'a'; aaa != Sub_change.ch&&p != NULL; )
	{
		if (pgrp == NULL)
			pgrp = p->head_group;
		while (aaa != Sub_change.ch&&pgrp != NULL)
		{
			if(psub==NULL)
			psub = pgrp->head_subject;
			while (aaa != Sub_change.ch&&psub != NULL)
			{
				ppsub = psub;
				psub = psub->next;
                aaa++;
			}
			if(aaa != Sub_change.ch)
			pgrp = pgrp->next;
		}
		if (aaa != Sub_change.ch)
		p = p->next;
	}
	if (ppsub == NULL)
	{
		while(pgrp->head_subject == NULL)
		{
			pgrp = pgrp->next;
			while (pgrp == NULL)
			{
				p = p->next;
				pgrp = p->head_group;
			}
		}
		pgrp->head_subject= pgrp->head_subject->next;
	}
	else if(psub==NULL)
	{ 
		pgrp = pgrp->next;
		if (pgrp == NULL)
		{
			p = p->next;
			pgrp = p->head_group;
		}
		while (pgrp->head_subject == NULL)
		{
			pgrp = pgrp->next;
		    if (pgrp == NULL)
		    {
	    		p = p->next;
	    		pgrp = p->head_group;
	    	}
		}
		pgrp->head_subject= pgrp->head_subject->next;
	}
	else
		ppsub->next=ppsub->next->next;
}

void input_subject(void)
{
	DEP *p = pphead;
	GRP *pgrp;
	SUB *psub;
	psub = (SUB *)malloc(sizeof(SUB));
	char ch1 = '1', ch[2];
	char cha[3] = "1.";
	char  mys[5], yours[5];
	int i = 1;
	char s[200] = "请输入您想录入的项目所属的院系:\n";
	while (p != NULL)
	{
		cha[0] = ch1;
		strcat(s, cha);
		strcat(s, p->dname);
		strcat(s, "\t");
		if (i % 2 == 0)
			strcat(s, "\n");
		i++;
		ch1++;
		p = p->next;

	}
	p = pphead;
	InputBox(ch, 2, s, "项目信息维护", "1", 250, 50);

	if ((ch[0] > '0') && (ch[0] < i + '0'))
	{

		for (ch1 = '1'; ch1 != ch[0]; ch1++, p = p->next)
		{
		}
		pgrp = p->head_group;
		strcpy(s, "请输入您想录入的项目所属的团队:\n");
		strcpy(cha, "1.");
		ch1 = '1',i=1;
		while (pgrp != NULL)
		{
			cha[0] = ch1;
			strcat(s, cha);
			strcat(s, pgrp->gname);
			strcat(s, "\t");
			if (i % 2 == 0)
				strcat(s, "\n");
			ch1++;
			i++;
			pgrp= pgrp->next;
		}
    	InputBox(ch, 2, s, "项目信息维护", "1", 250, 50);
		if ((ch[0] > '0') && (ch[0] < i + '0'))
		{
			pgrp = p->head_group;
			for (ch1 = '1'; ch1 != ch[0]; ch1++, pgrp = pgrp->next)
			{
			}
			InputBox(psub->sname, 20, "请输入项目编号：", "项目信息维护","0123456789", 250, 50);
			InputBox(ch, 2, "请输入项目类别：", "项目信息维护", "1", 250, 50);
			psub->type = ch[0];
			InputBox(psub->time, 20, "请输入新的起始时间：", "项目信息维护","2015/01", 250, 50);
			InputBox(s, 20, "请输入新的项目经费：", "项目信息维护", "0", 250, 50);
			InputBox(psub->sperson, 20, "请输入新的项目负责人：", "项目信息维护", " ", 250, 50);
			psub->money = atof(s);
			strcpy(psub->gname,pgrp->gname);
			psub->next = pgrp->head_subject;
			pgrp->head_subject= psub;
		}
	}
}

void Search(void)
{
	char ch='p';
	Search_statics(1);
	background();
	while (ch != 's'&&ch != 'S'&&ch!='Q'&&ch!='q')
	{
		inputcs(5, &ch);
		if (ch == 'a' || ch == 'A')
		{
        	Search_statics(1);
			mid[2].sit = 0;//把信息找寻框变色
			Search_department();
			ch = 'q';
        	Search_statics(1);
            mid[2].sit = 0;
		}
		else if (ch == 'b' || ch == 'B')
		{
        	Search_statics(1);
			mid[2].sit = 0;//把信息找寻框变色
			Search_group();
			ch = 'q';
        	Search_statics(1);
            mid[2].sit = 0;
		}
		else if (ch == 'c' || ch == 'C')
		{
        	Search_statics(1);
			mid[2].sit = 0;//把信息找寻框变色
			Search_subject();
			ch = 'q';
        	Search_statics(1);
            mid[2].sit = 0;
		}
	}
	Search_statics(1);
}

void Search_statics(int a)
{
	int n;
	if (a == 1)
	{
		mid[2].sit = mid[2].sit ^ 1;
		for (n = 0; n < 3; n++)
			fsearch_block[n].bl.on = fsearch_block[n].bl.on ^ 1;
	}
	else if (a == 2)//修改院系寻找提示框
	{
		statics(2);
		for (n = 0; n < 2; n++)
		infor_of_dep_search[n].on = infor_of_dep_search[n].on ^ 1;
	}
	else if(a==3) //修该院系信息框
	{
		for (n = 0; n < 3; n++)
			information_of_department[n].on = information_of_department[n].on ^ 1;
	}
	else if (a == 4)//修改团队寻找提示框
	{
		statics(2);
		for (n = 0; n < 2; n++)
		infor_of_grp_search[n].on = infor_of_grp_search[n].on ^ 1;
	}
	else if (a == 5)//修改项目寻找提示框
	{
		statics(2);
		for (n = 0; n < 2; n++)
		infor_of_sub_search[n].on = infor_of_sub_search[n].on ^ 1;
	}	
}

void Search_department(void)
{
	char ch='p';
	char *initial="首页",*a = "首页>院系信息查询",mm[20];
	char s[20];
	int i = 0;
	DEP *p = pphead;
	ftitle.s = a;
	Search_statics(2);
	fCOT.bl.on = 1;
	background();
	while (ch != 'q'&&ch != 'Q')
	{
		inputcs(4, &ch);
		if (ch == '1')
		{
			InputBox(s, 20, "请输入您想查找的院系的负责人：", "院系信息查询", "张三", 250, 50);
         	Search_statics(2);
            Search_statics(3);
			statics(0);
            background();
			while (p != NULL &&(strcmp(p->dperson, s)!=0))
				p = p->next;
			if (p)
			{
                outtextxy(165, 180 ,p->dname);				
				outtextxy(315, 180 , p->dperson);
				outtextxy(465, 180, p->dphone);
			}
			else
                outtextxy(165, 180 ,"无匹配院系");
			while(ch!='q'&&ch != 'Q')
				inputcs(4, &ch);
            statics(0);
            Search_statics(3);
			Search_statics(2);
		}
		else if (ch == '2')
		{
			InputBox(s, 20, "请输入您想模糊查找的院系名：", "院系信息查询", "m", 250, 50);
         	Search_statics(2);
            Search_statics(3);
			statics(0);
            background();
			p = pphead;
			while (p != NULL)
			{
				strcpy(mm , p->dname);
				if (strstr(strupr(mm), strupr(s)))
				{
                outtextxy(165, 180+30*i ,p->dname);				
				outtextxy(315, 180 + 30 * i, p->dperson);
				outtextxy(465, 180 +30 * i, p->dphone);
				i++;
				}
				p = p->next;
			}
			while(ch!='q'&&ch != 'Q')
				inputcs(4, &ch);
            statics(0);
            Search_statics(3);
			Search_statics(2);
		}
	}
	fCOT.bl.on = 0;
	ftitle.s = initial;
	Search_statics(2);
}

void Search_group(void)
{
	char ch = 'p';
	char *initial = "首页",*a = "首页>团队信息查询", mm[20];
	char mys[20],s[20],com[10],yours[100]="您想搜索的教师人数";
	int i = 0,mycom;
	DEP *p = pphead;
	GRP *pgrp = NULL;
	ftitle.s = a;
	Search_statics(4);
	fCOT.bl.on = 1;
	background();
	while (ch != 'q'&&ch != 'Q')
	{
		inputcs(4, &ch);
		if (ch == '1')
		{
			InputBox(s, 20, "请输入您想模糊查找的团队名：", "团队信息查询", " ", 250, 50);
         	Search_statics(4);
            statics(4);
			statics(0);
			information_of_group[5].on = 0;
            background();
			p = pphead;
			i = 0;
			while (p != NULL)
			{
				pgrp = p->head_group;
				while (pgrp != NULL)
				{
		     		strcpy(mm, pgrp->gname);
			     	if (strstr(strupr(mm), strupr(s)))
		     		{
						outtextxy(165, 180 + 30 * i, pgrp->gname);
						outtextxy(295, 180 + 30 * i, pgrp->person);
						_stprintf_s(s, "%d", pgrp->tp);
						outtextxy(365, 180 + 30 * i, s);
						_stprintf_s(s, "%d", pgrp->mp);
						outtextxy(435, 180 + 30 * i, s);
						outtextxy(515, 180 + 30 * i, pgrp->dname);
		    			i++;
		    		}
					pgrp = pgrp->next;
				}
				p = p->next;
			}
			while (ch != 'q'&&ch != 'Q')
				inputcs(4, &ch);
			information_of_group[5].on = 0;
			statics(0);
			statics(4);
			Search_statics(4);
		}
		else if (ch == '2')
		{
			s[0] = 0;
			while(s[0]<'1'||s[0]>'5')
			InputBox(s, 2, "请输入您想查找的条件为：\n教师数：1.>  2.>=\n3.=  4.<  5.<=", "团队信息查询", "1", 250, 80);
			if (s[0] == '1')
				strcat(yours, ">");
			else if (s[0] == '2')
				strcat(yours, ">=");
			else if (s[0] == '3')
				strcat(yours, "=");
			else if (s[0] == '4')
				strcat(yours, "<");
			else if (s[0] == '5')
				strcat(yours, "<=");
			InputBox(com, 10, yours, "团队信息查询", "1", 250, 80);
			mycom = atoi(com);
         	Search_statics(4);
            statics(4);
			statics(0);
			information_of_group[5].on = 0;
            background();
			p = pphead;
			i = 0;
			while (p != NULL&&i<8)
			{
				pgrp = p->head_group;
				while (pgrp != NULL&&i<8)
				{
			     	if (group_compare(pgrp->tp,mycom,s[0]))
		     		{
						outtextxy(165, 180 + 30 * i, pgrp->gname);
						outtextxy(295, 180 + 30 * i, pgrp->person);
						_stprintf_s(mys, "%d", pgrp->tp);
						outtextxy(365, 180 + 30 * i,mys);
						_stprintf_s(mys, "%d", pgrp->mp);
						outtextxy(435, 180 + 30 * i, mys);
						outtextxy(515, 180 + 30 * i, pgrp->dname);
		    			i++;
		    		}
					pgrp = pgrp->next;
				}
				p = p->next;
			}
			while (ch != 'q'&&ch != 'Q')
				inputcs(4, &ch);
			information_of_group[5].on = 0;
			statics(0);
			statics(4);
			Search_statics(4);
		}
	}
	fCOT.bl.on = 0;
	ftitle.s = initial;
	Search_statics(4);
}

void Search_subject(void)
{
	char ch='p';
	char *initial="首页",*a = "首页>项目信息查询",mm[20];
	char s[20];
	int i = 0;
	DEP *p = pphead;
	GRP *pgrp = NULL;
	SUB *psub = NULL;
	ftitle.s = a;
	Search_statics(5);
	fCOT.bl.on = 1;
	background();
	while (ch != 'q'&&ch != 'Q')
	{
		inputcs(4, &ch);
		if (ch == '1')
		{
			InputBox(s, 20, "请输入您想查找的项目的编号：", "项目信息查询", "1234567890", 250, 50);
			Search_statics(5);
			statics(6);
			statics(0);
			information_of_subjects[6].on = 0;
			background();
			p = pphead;
			i = 0;
			while (p != NULL)
			{
				pgrp = p->head_group;
				while (pgrp != NULL)
				{
					psub = pgrp->head_subject;
					while (psub != NULL)
					{
						if (!strcmp(s, psub->sname))
						{
							outtextxy(160, 180 + 30 * i, psub->sname);
							outtextxy(265, 180 + 30 * i, psub->type);
							outtextxy(305, 180 + 30 * i, psub->time);
							gcvt(psub->money, 4, mm);
							mm[4] = '\0';
							outtextxy(385, 180 + 30 * i, mm);
							outtextxy(455, 180 + 30 * i, psub->sperson);
							outtextxy(532, 180 + 30 * i, psub->gname);
							i++;
						}
						psub = psub->next;
					}
					pgrp = pgrp->next;
				}
				p = p->next;
			}
			while (ch != 'q'&&ch != 'Q')
				inputcs(4, &ch);
			information_of_group[6].on = 0;
			statics(0);
			statics(6);
			Search_statics(5);
		}
		else if (ch == '2')
		{
			InputBox(s, 20, "请输入您想查找的项目所属的团队：", "项目信息查询", "计算机应用", 250, 50);
			Search_statics(5);
			statics(6);
			statics(0);
			information_of_subjects[6].on = 0;
			background();
			p = pphead;
			i = 0;
			while (p != NULL)
			{
				pgrp = p->head_group;
				while (pgrp != NULL)
				{
					if (!strcmp(s, pgrp->gname))
					{				
						psub = pgrp->head_subject;
				        while (psub != NULL)
						{
							outtextxy(160, 180 + 30 * i, psub->sname);
							outtextxy(265, 180 + 30 * i, psub->type);
							outtextxy(305, 180 + 30 * i, psub->time);
							gcvt(psub->money, 4, mm);
							mm[4] = '\0';
							outtextxy(385, 180 + 30 * i, mm);
							outtextxy(455, 180 + 30 * i, psub->sperson);
							outtextxy(532, 180 + 30 * i, psub->gname);
							i++;
                            psub = psub->next;
						 }
					}
					pgrp = pgrp->next;
				}
				p = p->next;
			}
			while (ch != 'q'&&ch != 'Q')
				inputcs(4, &ch);
			information_of_group[6].on = 0;
			statics(0);
			statics(6);
			Search_statics(5);
		}
	}
	fCOT.bl.on = 0;
	ftitle.s = initial;
	Search_statics(5);
}

int group_compare(int a, int b, char c)
{
	if (c == '1')
	{
		if (a > b)
			return 1;
	}
	else if (c == '2')
	{
		if (a >= b)
			return 1;
	}
	else if (c == '3')
	{
		if (a == b)
			return 1;
	}
	else if (c == '4')
	{
		if (a < b)
			return 1;
	}
	else if (c == '5')
	{
		if (a <= b)
			return 1;
	}
	return 0;
}

void Count(void)
{
	char ch = 'p';
	DEPO *depo_head;
	GRPO *grpo_head;
	load_list_only(&depo_head, &grpo_head);
	Count_statics(1);
	background();
	while (ch != 't'&&ch != 'T'&&ch != 'Q'&&ch != 'q')
	{
		inputcs(6, &ch);
		if (ch == 'a'||ch=='A')
		{
			Count_statics(1);
			mid[3].sit = 0;//把信息找寻框变色
			count1(depo_head);
			ch = 'q';
			Count_statics(1);
			mid[3].sit = 0;
		}
		else if(ch=='b'||ch=='B')
		{
			Count_statics(1);
			mid[3].sit = 0;//把信息找寻框变色
			count2(depo_head);
			ch = 'q';
			Count_statics(1);
			mid[3].sit = 0;
		}
		else if (ch == 'c' || ch == 'C')
		{
			Count_statics(1);
			mid[3].sit = 0;//把信息找寻框变色
			count3(grpo_head);
			ch = 'q';
			Count_statics(1);
			mid[3].sit = 0;
		}
		else if (ch == 'd' || ch == 'D')
		{
			Count_statics(1);
			mid[3].sit = 0;//把信息找寻框变色
			count4(grpo_head);
			ch = 'q';
			Count_statics(1);
			mid[3].sit = 0;
		}
		else if (ch == 'e' || ch == 'E')
		{
			Count_statics(1);
			mid[3].sit = 0;//把信息找寻框变色
			count5(grpo_head);
			ch = 'q';
			Count_statics(1);
			mid[3].sit = 0;
		}
	}
	Count_statics(1);
}

void load_list_only(DEPO **depo_head, GRPO **grpo_head)
{
	DEP *p = pphead;
	GRP *pgrp;
	SUB *psub;
	DEPO *hdepo=NULL, *depo;
	GRPO *hgrpo=NULL, *grpo;
	while (p != NULL)
	{
		depo = (DEPO *)malloc(sizeof(DEPO));
		depo->next = hdepo;
		depo->department = p;
		depo->master = depo->subject863 = depo->subject973 = depo->teacher = depo->teacher = 0;
		depo->total_money = depo->total_subjects = 0;
		pgrp = p->head_group;
		while (pgrp != NULL)
		{
			grpo = (GRPO *)malloc(sizeof(GRPO));
			grpo->next = hgrpo;
			grpo->group = pgrp;
			grpo->teacher = grpo->total_money = grpo->total_subject = 0;
			depo->teacher = depo->teacher + pgrp->tp;
			depo->master = depo->master +pgrp->mp;
			grpo->teacher = pgrp->tp;
			psub = pgrp->head_subject;
			while (psub != NULL)
			{
				(grpo->total_subject)++;
				grpo->total_money = grpo->total_money + psub->money;
				if (psub->type == '1')
					(depo->subject973)++;
				else if (psub->type == '3')
					(depo->subject863)++;
				psub = psub->next;
			}
			grpo->sub_to_tc = ((float)grpo->total_subject) / grpo->teacher;
			grpo->m_to_t = grpo->total_money / grpo->teacher;
			depo->total_money = depo->total_money + grpo->total_money;
			depo->total_subjects = depo->total_subjects + grpo->total_subject;
			depo->m_to_t = ((float)depo->master) / (depo->teacher);
			
			pgrp = pgrp->next;
			hgrpo = grpo;
		}
		p = p->next;
		hdepo = depo;
	}
	(*depo_head) = hdepo;
	(*grpo_head) = hgrpo;
}

void Count_statics(int a)
{
	int n;
	if (a == 1)
	{
		mid[3].sit = mid[3].sit ^ 1;
		for (n = 0; n < 6; n++)
			fcount_block[n].bl.on = fcount_block[n].bl.on ^ 1;
	}
}

void count1(DEPO *head)
{
	DEPO *p = head,*myhead=head;
	char ch = 'p';
	char *initial = "首页", *a = "首页>院系人数统计", mm[20];
	char s[20];
	int i = 0,n;
	for (; head != NULL; head = head->next)
	{
		for (p = head->next; p != NULL; p = p->next)
		{
			if (head->m_to_t < p->m_to_t)
			{
				swap(&(head->department),&(p->department));
				swap(&(head->master), &(p->master));
				swap(&(head->m_to_t), &(p->m_to_t));
				swap(&(head->subject863), &(p->subject863));
				swap(&(head->subject973), &(p->subject973));
				swap(&(head->teacher), &(p->teacher));
				swap(&(head->total_money), &(p->total_money));
				swap(&(head->total_subjects), &(p->total_subjects));
			}
		}
	}
	ftitle.s = a;
	fCOT.bl.on = 1;
    statics(0);
	background();
	line(280, 140, 280, 410);
	line(420, 140, 420, 410);
	line(600, 140, 600, 410);
	setcolor(BLUE);
	outtextxy(180,150,"院系名称");
	outtextxy(310,150,"研究生人数");
	outtextxy(480,150,"教师人数");
	outtextxy(605,150,"研究生与教师人数比");
	setcolor(BLACK);
	for (p = myhead,i=1; p != NULL; p = p->next)
	{
    	outtextxy(180,150 + 30 * i,p->department->dname);
    	_stprintf_s(s, "%d", p->master);
    	outtextxy(340,150 + 30 * i,s);
    	_stprintf_s(s, "%d", p->teacher);
    	outtextxy(490,150 + 30 * i,s);
    	_stprintf_s(s, "%.2f", p->m_to_t);
     	outtextxy(635,150 + 30 * i,s);
    	i++;
	}
	while(ch!='q'&&ch!='Q')
		inputcs(4, &ch);
	ftitle.s = initial;
	fCOT.bl.on = 0;
	statics(0);
}

void count2(DEPO *head)
{
	DEPO *p = head, *myhead = head;
	char ch = 'p';
	char *initial = "首页", *a = "首页>院系科研项目统计", mm[20];
	char s[20];
	int i = 0, n;
	for (; head != NULL; head = head->next)
	{
		for (p = head->next; p != NULL; p = p->next)
		{
			if (head->total_subjects< p->total_subjects)
			{
				swap(&(head->department), &(p->department));
				swap(&(head->master), &(p->master));
				swap(&(head->m_to_t), &(p->m_to_t));
				swap(&(head->subject863), &(p->subject863));
				swap(&(head->subject973), &(p->subject973));
				swap(&(head->teacher), &(p->teacher));
				swap(&(head->total_money), &(p->total_money));
				swap(&(head->total_subjects), &(p->total_subjects));
			}
		}
	}
	ftitle.s = a;
	fCOT.bl.on = 1;
	statics(0);
	background();
	line(260, 140, 260, 410);
	line(380, 140, 380, 410);
	line(500, 140, 500, 410);
	line(630, 140, 630, 410);
	setcolor(BLUE);
	outtextxy(160, 150, "院系名称");
	outtextxy(290, 150, "973项目数");
	outtextxy(410, 150, "863项目数");
	outtextxy(520, 150, "研究总经费");
	outtextxy(650, 150, "科研项目数");
	setcolor(BLACK);	
	for (p = myhead, i = 1; p != NULL; p = p->next)
	{
     	outtextxy(160, 150 + 30 * i, p->department->dname);
		_stprintf_s(s, "%d", p->subject973);
    	outtextxy(320, 150 + 30 * i, s);
		_stprintf_s(s, "%d", p->subject863);
    	outtextxy(440, 150 + 30 * i, s);
		_stprintf_s(s, "%.2f", p->total_money);
    	outtextxy(530, 150 + 30 * i, s);
		_stprintf_s(s, "%d", p->total_subjects);
    	outtextxy(690, 150 + 30 * i, s);
		i++;
	}
	while (ch != 'q'&&ch != 'Q')
		inputcs(4, &ch);
	ftitle.s = initial;
	fCOT.bl.on = 0;
	statics(0);
}

void count3(GRPO *head)
{
	GRPO *p = head, *myhead = head;
	char ch = 'p';
	char *initial = "首页", *a = "首页>科研团队项目统计", mm[20];
	char s[20];
	int i = 0, n;
	for (; head != NULL; head = head->next)
	{
		for (p = head->next; p != NULL; p = p->next)
		{
			if (head->total_money < p->total_money)
			{
				swap(&(head->group), &(p->group));
				swap(&(head->sub_to_tc), &(p->sub_to_tc));
				swap(&(head->teacher), &(p->teacher));
				swap(&(head->total_money), &(p->total_money));
				swap(&(head->total_subject), &(p->total_subject));
				swap(&(head->m_to_t), &(head->m_to_t));
			}
		}
	}
	ftitle.s = a;
	fCOT.bl.on = 1;
	statics(0);
	background();
	line(300, 140, 300, 410);
	line(500, 140, 500, 410);
	setcolor(BLUE);
	outtextxy(180, 150, "团队名称");
	outtextxy(360, 150, "科研总经费");
	outtextxy(600, 150, "项目总数");
	setcolor(BLACK);
	for (p = myhead, i = 1; p != NULL&&i!=9; p = p->next)
	{
		outtextxy(180, 150 + 30 * i, p->group->gname);
		_stprintf_s(s, "%.2f", p->total_money);
		outtextxy(370, 150 + 30 * i, s);
		_stprintf_s(s, "%d", p->total_subject);
		outtextxy(630, 150 + 30 * i, s);
		i++;
	}
	while (ch != 'q'&&ch != 'Q')
		inputcs(4, &ch);
	ftitle.s = initial;
	fCOT.bl.on = 0;
	statics(0);
}

void count4(GRPO *head)
{
	GRPO *p = head, *myhead = head;
	char ch = 'p';
	char *initial = "首页", *a = "首页>科研团队比值统计", mm[20];
	char s[20];
	int i = 0, n;
	for (; head != NULL; head = head->next)
	{
		for (p = head->next; p != NULL; p = p->next)
		{
			if (head->sub_to_tc < p->sub_to_tc)
			{
				swap(&(head->group), &(p->group));
				swap(&(head->sub_to_tc), &(p->sub_to_tc));
				swap(&(head->teacher), &(p->teacher));
				swap(&(head->total_money), &(p->total_money));
				swap(&(head->total_subject), &(p->total_subject));
				swap(&(head->m_to_t), &(head->m_to_t));
			}
		}
	}
	ftitle.s = a;
	fCOT.bl.on = 1;
	statics(0);
	background();
	line(280, 140, 280, 410);
	line(420, 140, 420, 410);
	line(570, 140, 570, 410);
	setcolor(BLUE);
	outtextxy(180, 150, "团队名称");
	outtextxy(310, 150, "科研项目数");
	outtextxy(480, 150, "教师人数");
	outtextxy(575, 150, "科研项目数与教师人数比");
	setcolor(BLACK);
	for (p = myhead, i = 1; p != NULL&&i != 9; p = p->next)
	{
		outtextxy(180, 150 + 30 * i, p->group->gname);
		_stprintf_s(s, "%d", p->total_subject);
		outtextxy(340, 150 + 30 * i, s);
		_stprintf_s(s, "%d", p->teacher);
		outtextxy(490, 150 + 30 * i, s);
		_stprintf_s(s, "%.2f", p->sub_to_tc);
		outtextxy(635, 150 + 30 * i, s);
		i++;
	}
	while (ch != 'q'&&ch != 'Q')
		inputcs(4, &ch);
	ftitle.s = initial;
	fCOT.bl.on = 0;
	statics(0);
}

void count5(GRPO *head)
{
	GRPO *p = head, *myhead = head;
	char ch = 'p';
	char *initial = "首页", *a = "首页>教师平均经费统计", mm[20];
	char s[20];
	int i = 0, n;
	for (; head != NULL; head = head->next)
	{
		for (p = head->next; p != NULL; p = p->next)
		{
			if (head->m_to_t< p->m_to_t)
			{
				swap(&(head->group), &(p->group));
				swap(&(head->sub_to_tc), &(p->sub_to_tc));
				swap(&(head->teacher), &(p->teacher));
				swap(&(head->total_money), &(p->total_money));
				swap(&(head->total_subject), &(p->total_subject));
				swap(&(head->m_to_t), &(head->m_to_t));
			}
		}
	}
	ftitle.s = a;
	fCOT.bl.on = 1;
	statics(0);
	background();
	line(280, 140, 280, 410);
	line(420, 140, 420, 410);
	line(570, 140, 570, 410);
	setcolor(BLUE);
	outtextxy(180, 150, "团队名称");
	outtextxy(330, 150, "科研经费");
	outtextxy(470, 150, "教师人数");
	outtextxy(615, 150, "教师平均经费");
	setcolor(BLACK);
	for (p = myhead, i = 1; p != NULL&&i != 9; p = p->next)
	{
		outtextxy(180, 150 + 30 * i, p->group->gname);
		_stprintf_s(s, "%.2f", p->total_money);
		outtextxy(340, 150 + 30 * i, s);
		_stprintf_s(s, "%d", p->teacher);
		outtextxy(490, 150 + 30 * i, s);
		_stprintf_s(s, "%.2f", p->m_to_t);
		outtextxy(635, 150 + 30 * i, s);
		i++;
	}
	while (ch != 'q'&&ch != 'Q')
		inputcs(4, &ch);
	ftitle.s = initial;
	fCOT.bl.on = 0;
	statics(0);
}

void swap(int *a, int *b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
void swap(float *a, float *b)
{
	float c;
	c = *a;
	*a = *b;
	*b = c;
}
void swap(DEP **a, DEP **b)
{
	DEP *c;
	c = *a;
	*a = *b;
	*b = c;
}
void swap(GRP **a, GRP **b)
{
	GRP *c;
	c = *a;
	*a = *b;
	*b = c;
}

void inputcs(int a, char *c)
{
	int n;
	int flag = 1;
	FlushMouseMsgBuffer();
	while (flag)
	{
		if (a == 1)
		{
			if (kbhit())
			{
				*c = getch();
				flag = 0;
			}
			if (MouseHit())
			{
				myms = GetMouseMsg();
				if (myms.mkLButton)
					if (myms.x > 0 && myms.x < 100)
					{
						if (myms.y > 60 && myms.y <= 85)
						{
							*c = 'd';
							flag = 0;
						}
						else if (myms.y > 85 && myms.y <= 105)
						{
							*c = 'f';
							flag = 0;
						}
						else if (myms.y > 105 && myms.y <= 130)
						{
							*c = 's';
							flag = 0;
						}
						else if (myms.y > 130 && myms.y <= 155)
						{
							*c = 't';
							flag = 0;
						}
						else if (myms.y > 155 && myms.y <= 180)
						{
							*c = 'h';
							flag = 0;
						}
					}
					else if (myms.x > 690 && myms.x < 760 && myms.y>458 && myms.y < 480)
					{
						*c = 'q';
						flag = 0;
					}
			}
		}
		else if (a == 2)
		{
			if (kbhit())
			{
				*c = getch();
				flag = 0;
			}
			if (MouseHit())
			{
				myms = GetMouseMsg();
				if (myms.mkLButton)
					if (myms.x > 60 && myms.x < 100 && myms.y > 85 && myms.y <= 105)
					{
						*c = 'f';
						flag = 0;
					}
					else if (myms.x >= 100 && myms.x < 220)
					{
						if (myms.y > 85 && myms.y <= 105)
						{
							*c = 'a';
							flag = 0;
						}
						else if (myms.y > 105 && myms.y <= 130)
						{
							*c = 'b';
							flag = 0;
						}
						else if (myms.y > 130 && myms.y <= 155)
						{
							*c = 'c';
							flag = 0;
						}
					}
			}
		}
		else if (a == 3)
		{
			if (kbhit())
			{
				*c = getch();
				flag = 0;
			}
			if (MouseHit())
			{
				myms = GetMouseMsg();
				if (myms.mkLButton)
					if (myms.x > 600 && myms.y < 680)
					{
						if (myms.y > 140 && myms.y < 170)
						{
							*c = 'p';
							flag = 0;
						}
						else if (myms.y >= 170 && myms.y < 410)
						{
							*c = '1' + (myms.y - 170) / 30;
							flag = 0;
						}
					}
				if (myms.mkLButton)
					 if (myms.x >= 680 && myms.y < 750)
					{
						if (myms.y >= 170 && myms.y < 410)
						{
							*c = 'a' + (myms.y - 170) / 30;
							flag = 0;
						}
					}
				if (myms.mkLButton)
					 if (myms.y > 458 && myms.y < 480)
					{
						if (myms.x > 690 && myms.x < 760)
						{
							*c = 'q';
							flag = 0;
						}
						else if (myms.x <= 690 && myms.x > 620)
						{
							*c = '+';
							flag = 0;
						}
						else if (myms.x > 550 && myms.x < 620)
						{
							*c = '-';
							flag = 0;
						}
					}
			}
		}
		else if (a == 4)
		{
			if (kbhit())
			{
				*c = getch();
				flag = 0;
			}
			if (MouseHit())
			{
				myms = GetMouseMsg();
				if (myms.mkLButton)
					if (myms.y > 458 && myms.y < 480)
					{
						if (myms.x > 690 && myms.x < 760)
						{
							*c = 'q';
							flag = 0;
						}
						else if (myms.x <= 690 && myms.x > 620)
						{
							*c = '+';
							flag = 0;
						}
						else if (myms.x > 550 && myms.x < 620)
						{
							*c = '-';
							flag = 0;
						}
					}
				if (myms.mkLButton)
					if (myms.x > 200 & myms.x < 500)
					{
						*c = '1' + (myms.y - 140) / 30;
						flag = 0;
					}
			}
		}
		else if (a == 5)
		{
			if (kbhit())
			{
				*c = getch();
				flag = 0;
			}
			if (MouseHit())
			{
				myms = GetMouseMsg();
				if (myms.mkLButton)
					if (myms.x > 60 && myms.x < 100 && myms.y > 105 && myms.y <= 130)
					{
						*c = 's';
						flag = 0;
					}
					else if (myms.x >= 100 && myms.x < 220)
					{
						 if (myms.y > 105 && myms.y <= 130)
						{
							*c = 'a';
							flag = 0;
						}
						else if (myms.y > 130 && myms.y <= 155)
						{
							*c = 'b';
							flag = 0;
						}
						else if (myms.y > 155 && myms.y <= 180)
						{
							*c = 'c';
							flag = 0;
						}
					}
			}
		}
		else if (a == 6)
		{
			if (kbhit())
			{
				*c = getch();
				flag = 0;
			}
			if (MouseHit())
			{
				myms = GetMouseMsg();
				if (myms.mkLButton)
					if (myms.x > 60 && myms.x < 100 && myms.y > 130 && myms.y <= 155)
					{
						*c = 't';
						flag = 0;
					}
					else if (myms.x >= 100 && myms.x < 220)
					{
						if (myms.y > 130 && myms.y <= 155)
						{
							*c = 'a';
							flag = 0;
						}
						else if (myms.y > 155 && myms.y <= 180)
						{
							*c = 'b';
							flag = 0;
						}
						else if (myms.y > 180 && myms.y <= 205)
						{
							*c = 'c';
							flag = 0;
						}
						else if (myms.y > 205 && myms.y <= 230)
						{
							*c = 'd';
							flag = 0;
						}
						else if (myms.y > 230 && myms.y <= 255)
						{
							*c = 'e';
							flag = 0;
						}
					}
			}
		}
	}
}

/**
*函数名称：creat_list
*函数功能：创建一个三个方向的十字交叉链表
*输入参数：主函数中头指针的地址
*输出参数：用主函数传来的地址对头指针赋值
*返回值  ：无
*调用说明：此函数建立链表的过程中都是建立后进先出链
*/
void creat_list(DEP **head)
{
	DEP *hp = NULL, *p;
	GRP *pgrp;
	SUB *psub;
	char ch = '1';
	while (ch == '1')
	{
		p = (DEP *)malloc(sizeof(DEP));    /*创建院系信息的节点*/
		scanf("%s %s %s", p->dname, p->dperson, p->dphone);
		getchar();       /*吞掉回车，后同*/
		p->head_group = NULL;     /*使团队信息链的链头置空*/
		p->next = hp;
		hp = p;     /*后进先出的节点*/
		printf("Continue? 1 or 0\n");
		ch = getchar();
		getchar();
	}
	(*head) = hp;      /*通过指针使主函数中头指针改变*/
	p = (*head);       /*指向链头进行后续操作*/
	while (p != NULL)
	{
		ch = '1';
		while (ch == '1')
		{
			pgrp = (GRP *)malloc(sizeof(GRP));     /*创建团队信息的节点*/
			scanf("%s %s %d %d", pgrp->gname, pgrp->person, &pgrp->tp, &pgrp->mp);
			getchar();
			strcpy(pgrp->dname, p->dname);     /*给相同的院系信息进行赋值*/
			pgrp->head_subject = NULL;      /*使项目信息链链头置空*/
			pgrp->next = p->head_group;
			p->head_group = pgrp;       /*后进先出的节点*/
			printf("Continue %s's group? 1 or 0\n", p->dname);
			ch = getchar();
			getchar();
		}
		p = p->next;
	}
	p = (*head);
	while (p != NULL)
	{
		pgrp = p->head_group;
		while ((pgrp) != NULL)
		{
			ch = '1';
			while (ch == '1')
			{
				psub = (SUB *)malloc(sizeof(SUB));      /*创建项目信息的节点*/
				scanf("%s %c %s %f %s", psub->sname, &psub->type, psub->time, &psub->money, psub->sperson);
				getchar();
				strcpy(psub->gname, pgrp->gname);
				psub->next = pgrp->head_subject;
				pgrp->head_subject = psub;     /*后进先出的节点*/
				printf("Continue %s's subject? 1 or 0\n", pgrp->gname);
				ch = getchar();
				getchar();
			}
			pgrp = pgrp->next;
		}
		p = p->next;
	}
}

/**
*函数名称：trave_list
*函数功能：遍历并输出这个三个方向的十字交叉链表
*输入参数：主函数中的头指针
*输出参数：无
*返回值  ：无
*/
void tarve_list(DEP *head)
{
	DEP *p = head;
	GRP *pgrp;
	SUB *psub;
	while (p != NULL)
	{
		printf("\n%-20s %-12s %-15s\n", p->dname, p->dperson, p->dphone);
		pgrp = p->head_group;
		while (pgrp != NULL)
		{
			printf("%-20s %-12s %-3d %-3d %-20s\n", pgrp->gname, pgrp->person, pgrp->tp, pgrp->mp, pgrp->dname);
			psub = pgrp->head_subject;
			while (psub != NULL)
			{
				printf("%-15s %c %-8s %-6.1f %-12s %-20s\n", psub->sname, psub->type, psub->time, psub->money, psub->sperson, psub->gname);
				psub = psub->next;
			}
			pgrp = pgrp->next;
		}
		p = p->next;
	}
}

/**
*函数名称：save_list
*函数功能：保存创造的十字交叉链表
*输入参数：主函数中的头指针
*输出参数：创造的三个二进制文件
*返回值：无
*/
void save_list(DEP *head)
{
	FILE *out1, *out2, *out3;
	DEP *p = head;
	GRP *pgrp;
	SUB *psub;
	if ((out1 = fopen("D:\\class\\departments.dat", "wb")) == NULL)  /*打开院系信息文件*/
	{
		printf("\t保存院系信息失败\n");
		exit(-1);
	}
	if ((out2 = fopen("D:\\class\\groups.dat", "wb")) == NULL)      /*打开团队信息文件*/
	{
		printf("\t保存团队信息失败\n");
		exit(-1);
	}
	if ((out3 = fopen("D:\\class\\subjects.dat", "wb")) == NULL)     /*打开项目信息文件*/
	{
		printf("\t保存项目信息失败\n");
		exit(-1);
	}
	while (p != NULL)
	{
		fwrite(p, sizeof(DEP), 1, out1);
		pgrp = p->head_group;
		while (pgrp != NULL)
		{
			fwrite(pgrp, sizeof(GRP), 1, out2);
			psub = pgrp->head_subject;
			while (psub != NULL)
			{
				fwrite(psub, sizeof(SUB), 1, out3);
				psub = psub->next;
			}
			pgrp = pgrp->next;
		}
		p = p->next;
	}
	fclose(out1);
	fclose(out2);
	fclose(out3);
}

/**
*函数名称：load_list
*函数功能：从二进制文件读入到十字交叉链表之中
*输入参数：主函数头指针的地址
*输出参数：用主函数传来的地址对头指针赋值
*返回值：无
*/
void load_list(DEP **head)
{
	FILE *in1, *in2, *in3;
	DEP *hp = NULL, *p;
	GRP *pgrp;
	SUB *psub;
	int flag = 1;
	if ((in1 = fopen("departments.dat", "rb")) == NULL)
	{
		printf("院系信息加载失败!\n");
		exit(-1);
	}
	else
		printf("院系信息加载成功!\n");
	if ((in2 = fopen("groups.dat", "rb")) == NULL)
	{
		printf("团队信息加载失败!\n");
		exit(-1);
	}
	else
		printf("团队信息加载成功!\n");
	if ((in3 = fopen("subjects.dat", "rb")) == NULL)
	{
		printf("项目信息加载失败!\n");
		exit(-1);
	}
	else
		printf("项目信息加载成功!\n");  /*判断各种信息是否载入成功*/
	while (!feof(in1))
	{
		p = (DEP *)malloc(sizeof(DEP));
		fread(p, sizeof(DEP), 1, in1);
		if (!feof(in1))
		{
			p->head_group = NULL;
			p->next = hp;
			hp = p;
		}
	}
	(*head) = hp;
	while (!feof(in2))
	{
		pgrp = (GRP *)malloc(sizeof(GRP));
		fread(pgrp, sizeof(GRP), 1, in2);
		if (!feof(in2))
		{
			p = (*head);
			while (p != NULL)
			{
				if (!strcmp(p->dname, pgrp->dname))
				{
					pgrp->head_subject = NULL;
					pgrp->next = p->head_group;
					p->head_group = pgrp;
					break;
				}
				else
					p = p->next;
			}
		}
	}
	while (!feof(in3))
	{
		psub = (SUB *)malloc(sizeof(SUB));
		fread(psub, sizeof(SUB), 1, in3);
		flag = 1;
		if (!feof(in3))
		{
			p = (*head);
			while ((p != NULL) && flag)
			{
				pgrp = p->head_group;
				while ((pgrp != NULL) && flag)
				{
					if (!strcmp(pgrp->gname, psub->gname))
					{
						psub->next = pgrp->head_subject;
						pgrp->head_subject = psub;
						flag = 0;
					}
					else
						pgrp = pgrp->next;
				}
				p = p->next;
			}
		}
	}
	fclose(in1);
	fclose(in2);
	fclose(in3);
}