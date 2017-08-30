#include"mysubject.h"
int main()
{	
	char ch='a';
	DEP *head = NULL;
	load_list(&head);
	pphead = head;
	initgraph(800, 500);// ��ʼ��ͼ�δ���
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
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 18;                      // ��������߶�
	f.lfWidth = 10;
	_tcscpy(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱
	settextstyle(&f);                     // ����������ʽ
	outtextxy(10, 5, _T("������Ŀ"));
	outtextxy(10, 35, _T("����ϵͳ"));
	f.lfHeight = 15;
	f.lfWidth = 8;
	f.lfWeight = 10;
	_tcscpy(f.lfFaceName, _T("����"));
	settextstyle(&f);
	outtextxy(10, 65, "�ļ�(D)");
	outtextxy(10, 90, "����ά��(F)");	
	outtextxy(10, 115, "���ݲ�ѯ(S)");
	outtextxy(10, 140, "����ͳ��(T)");
	outtextxy(10, 165, "����(H)");
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
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = a.height;                      // ��������߶�
	f.lfWidth = a.width;
	f.lfWeight = 1;
	_tcscpy(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱
	settextstyle(&f);                     // ����������ʽ
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
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 16;                      // ��������߶�
	f.lfWidth = 7;
	f.lfWeight = 100;
	_tcscpy(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱
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
	if (a == 0)//�޸ĳ�����
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
	else if (a == 2)//�޸��޸�Ժϵʱ����Ϣ��
	{
		for (n = 0; n < 9; n++)
		{
			Chang_block[n].on = Chang_block[n].on^ 1;
		}
	}
	else if (a == 3)//�޸��޸�Ժϵʱ���ı�
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
	char *a = "��ҳ",*b="��ҳ>Ժϵ����ά��",*c="��ҳ>�Ŷ���Ϣά��",*d="��ҳ>��Ŀ��Ϣά��";
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
				outtextxy(200, 100,"��Ȩ���У����пƼ���ѧ�����ѧԺ ���" );
				outtextxy(200, 150,"һ�в���������ʾ��Ϣ���������̲�������" );
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
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 16;                      // ��������߶�
	f.lfWidth = 7;
	f.lfWeight = 100;
	_tcscpy(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱
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
		    	outtextxy(620, 180 + 30 * i, "�޸�:");
		    	outtextxy(660, 180 + 30 * i, ch1);
			    outtextxy(700, 180 + 30 * i, "ɾ��:");
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
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 16;                      // ��������߶�
	f.lfWidth = 7;
	f.lfWeight = 100;
	_tcscpy(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱
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
     		outtextxy(620, 180 + 30 * i, "�޸�:");
     		outtextxy(660, 180 + 30 * i, ch1);
    		outtextxy(700, 180 + 30 * i, "ɾ��:");
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
	gettextstyle(&f);                     // ��ȡ��ǰ��������
	f.lfHeight = 16;                      // ��������߶�
	f.lfWidth = 7;
	f.lfWeight = 100;
	_tcscpy(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱
	settextstyle(&f);
	line(270, 140, 270,410 );
	line(400, 140, 400,410 );
	line(600,140,600,410);
	line(680,140,680,410);
	setcolor(BLUE);
	outtextxy(165, 150, "Ժϵ����");
	outtextxy(315,150,"������");
	outtextxy(465,150,"��ϵ�绰");
	outtextxy(603, 150, "¼����Ϣ(P)");
	setcolor(BLACK);
	 for(i=0;p!=NULL;i++,p=p->next,ch1++,cha++)
    {
    	outtextxy(165, 180+30*i,p->dname);
	    outtextxy(315,180+30*i,p->dperson);
     	outtextxy(465,180+30*i,p->dphone);
		outtextxy(620, 180 + 30 * i, "�޸�:");
		outtextxy(660, 180 + 30 * i, ch1);
		outtextxy(700, 180 + 30 * i, "ɾ��:");
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
			InputBox(p->dname, 20, "�������µ�Ժϵ��Ϣ��", "Ժϵ��Ϣά��", p->dname, 250, 50, false);
		}
		else if (cha == '2')
		{
			InputBox(p->dperson, 20, "�������µĸ����ˣ�", "Ժϵ��Ϣά��", p->dperson, 250, 50, false);
		}
		else if (cha == '3')
		{
			InputBox(p->dphone, 20, "�������µ���ϵ�绰��", "Ժϵ��Ϣά��", p->dphone, 250, 50, false);
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
	InputBox(p->dname, 20, "�������µ�Ժϵ���ƣ�", "Ժϵ��Ϣά��", "", 250, 50);
	InputBox(p->dperson, 20, "�������µĸ����ˣ�", "Ժϵ��Ϣά��","" , 250, 50);
	InputBox(p->dphone, 20, "�������µ���ϵ�绰��", "Ժϵ��Ϣά��","" , 250, 50);
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
			InputBox( pgrp->gname, 20, "�������µ��Ŷ����ƣ�","�Ŷ���Ϣά��",pgrp->gname,250,50,false);
		}
		else if (cha== '2')
		{
			InputBox(pgrp->person, 20, "�������µĸ����ˣ�","�Ŷ���Ϣά��", pgrp->person,250,50,false);
		}
		else if (cha== '3')
		{
			InputBox(mys, 20, "�������µĽ�ʦ������","�Ŷ���Ϣά��",mys,250,50,false);
			sscanf(mys, "%d", &(pgrp->tp));
		}
		else if (cha == '4')
		{
			InputBox(yours, 20, "�������µ��о���������","�Ŷ���Ϣά��",yours,250,50,false);
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
	char s[200] = "����������¼����Ŷ�������Ժϵ:\n";
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
	InputBox(ch, 2, s, "�Ŷ���Ϣά��", "1", 250, 50, false);

	if ((ch[0] > '0')&&(ch[0] < i + '0'))
	{
		GRP *pgrp;
		pgrp = (GRP *)malloc(sizeof(GRP));
		for(ch1='1';ch1!=ch[0];ch1++,p=p->next)
		{ }
		InputBox(pgrp->gname, 20, "�������Ŷ����ƣ�", "�Ŷ���Ϣά��");
		InputBox(pgrp->person, 20, "�����븺���ˣ�", "�Ŷ���Ϣά��");
		InputBox(mys, 20, "�������ʦ������", "�Ŷ���Ϣά��");
		sscanf(mys, "%d", &(pgrp->tp));
		InputBox(yours, 20, "�������о���������", "�Ŷ���Ϣά��");
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
			InputBox(psub->sname, 20, "�������µ���Ŀ��ţ�", "��Ŀ��Ϣά��", psub->sname, 250, 50, false);
		}
		else if (cha == '2')
		{
			InputBox(information_of_change6[1].s, 20, "�������µ���Ŀ���", "��Ŀ��Ϣά��", information_of_change6[1].s, 250, 50, false);
			psub->type=information_of_change6[1].s[0];
		}
		else if (cha == '3')
		{
			InputBox(psub->time, 20, "�������µ���ʼʱ�䣺", "��Ŀ��Ϣά��", psub->time, 250, 50, false);
		}
		else if (cha == '4')
		{
			InputBox(s, 20, "�������µ���Ŀ���ѣ�", "��Ŀ��Ϣά��", s, 250, 50, false);
			psub->money = atof(s);
		}
		else if (cha == '5')
		{
			InputBox(psub->sperson, 20, "�������µ���Ŀ�����ˣ�", "��Ŀ��Ϣά��", psub->sperson, 250, 50, false);
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
	char s[200] = "����������¼�����Ŀ������Ժϵ:\n";
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
	InputBox(ch, 2, s, "��Ŀ��Ϣά��", "1", 250, 50);

	if ((ch[0] > '0') && (ch[0] < i + '0'))
	{

		for (ch1 = '1'; ch1 != ch[0]; ch1++, p = p->next)
		{
		}
		pgrp = p->head_group;
		strcpy(s, "����������¼�����Ŀ�������Ŷ�:\n");
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
    	InputBox(ch, 2, s, "��Ŀ��Ϣά��", "1", 250, 50);
		if ((ch[0] > '0') && (ch[0] < i + '0'))
		{
			pgrp = p->head_group;
			for (ch1 = '1'; ch1 != ch[0]; ch1++, pgrp = pgrp->next)
			{
			}
			InputBox(psub->sname, 20, "��������Ŀ��ţ�", "��Ŀ��Ϣά��","0123456789", 250, 50);
			InputBox(ch, 2, "��������Ŀ���", "��Ŀ��Ϣά��", "1", 250, 50);
			psub->type = ch[0];
			InputBox(psub->time, 20, "�������µ���ʼʱ�䣺", "��Ŀ��Ϣά��","2015/01", 250, 50);
			InputBox(s, 20, "�������µ���Ŀ���ѣ�", "��Ŀ��Ϣά��", "0", 250, 50);
			InputBox(psub->sperson, 20, "�������µ���Ŀ�����ˣ�", "��Ŀ��Ϣά��", " ", 250, 50);
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
			mid[2].sit = 0;//����Ϣ��Ѱ���ɫ
			Search_department();
			ch = 'q';
        	Search_statics(1);
            mid[2].sit = 0;
		}
		else if (ch == 'b' || ch == 'B')
		{
        	Search_statics(1);
			mid[2].sit = 0;//����Ϣ��Ѱ���ɫ
			Search_group();
			ch = 'q';
        	Search_statics(1);
            mid[2].sit = 0;
		}
		else if (ch == 'c' || ch == 'C')
		{
        	Search_statics(1);
			mid[2].sit = 0;//����Ϣ��Ѱ���ɫ
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
	else if (a == 2)//�޸�ԺϵѰ����ʾ��
	{
		statics(2);
		for (n = 0; n < 2; n++)
		infor_of_dep_search[n].on = infor_of_dep_search[n].on ^ 1;
	}
	else if(a==3) //�޸�Ժϵ��Ϣ��
	{
		for (n = 0; n < 3; n++)
			information_of_department[n].on = information_of_department[n].on ^ 1;
	}
	else if (a == 4)//�޸��Ŷ�Ѱ����ʾ��
	{
		statics(2);
		for (n = 0; n < 2; n++)
		infor_of_grp_search[n].on = infor_of_grp_search[n].on ^ 1;
	}
	else if (a == 5)//�޸���ĿѰ����ʾ��
	{
		statics(2);
		for (n = 0; n < 2; n++)
		infor_of_sub_search[n].on = infor_of_sub_search[n].on ^ 1;
	}	
}

void Search_department(void)
{
	char ch='p';
	char *initial="��ҳ",*a = "��ҳ>Ժϵ��Ϣ��ѯ",mm[20];
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
			InputBox(s, 20, "������������ҵ�Ժϵ�ĸ����ˣ�", "Ժϵ��Ϣ��ѯ", "����", 250, 50);
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
                outtextxy(165, 180 ,"��ƥ��Ժϵ");
			while(ch!='q'&&ch != 'Q')
				inputcs(4, &ch);
            statics(0);
            Search_statics(3);
			Search_statics(2);
		}
		else if (ch == '2')
		{
			InputBox(s, 20, "����������ģ�����ҵ�Ժϵ����", "Ժϵ��Ϣ��ѯ", "m", 250, 50);
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
	char *initial = "��ҳ",*a = "��ҳ>�Ŷ���Ϣ��ѯ", mm[20];
	char mys[20],s[20],com[10],yours[100]="���������Ľ�ʦ����";
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
			InputBox(s, 20, "����������ģ�����ҵ��Ŷ�����", "�Ŷ���Ϣ��ѯ", " ", 250, 50);
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
			InputBox(s, 2, "������������ҵ�����Ϊ��\n��ʦ����1.>  2.>=\n3.=  4.<  5.<=", "�Ŷ���Ϣ��ѯ", "1", 250, 80);
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
			InputBox(com, 10, yours, "�Ŷ���Ϣ��ѯ", "1", 250, 80);
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
	char *initial="��ҳ",*a = "��ҳ>��Ŀ��Ϣ��ѯ",mm[20];
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
			InputBox(s, 20, "������������ҵ���Ŀ�ı�ţ�", "��Ŀ��Ϣ��ѯ", "1234567890", 250, 50);
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
			InputBox(s, 20, "������������ҵ���Ŀ�������Ŷӣ�", "��Ŀ��Ϣ��ѯ", "�����Ӧ��", 250, 50);
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
			mid[3].sit = 0;//����Ϣ��Ѱ���ɫ
			count1(depo_head);
			ch = 'q';
			Count_statics(1);
			mid[3].sit = 0;
		}
		else if(ch=='b'||ch=='B')
		{
			Count_statics(1);
			mid[3].sit = 0;//����Ϣ��Ѱ���ɫ
			count2(depo_head);
			ch = 'q';
			Count_statics(1);
			mid[3].sit = 0;
		}
		else if (ch == 'c' || ch == 'C')
		{
			Count_statics(1);
			mid[3].sit = 0;//����Ϣ��Ѱ���ɫ
			count3(grpo_head);
			ch = 'q';
			Count_statics(1);
			mid[3].sit = 0;
		}
		else if (ch == 'd' || ch == 'D')
		{
			Count_statics(1);
			mid[3].sit = 0;//����Ϣ��Ѱ���ɫ
			count4(grpo_head);
			ch = 'q';
			Count_statics(1);
			mid[3].sit = 0;
		}
		else if (ch == 'e' || ch == 'E')
		{
			Count_statics(1);
			mid[3].sit = 0;//����Ϣ��Ѱ���ɫ
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
	char *initial = "��ҳ", *a = "��ҳ>Ժϵ����ͳ��", mm[20];
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
	outtextxy(180,150,"Ժϵ����");
	outtextxy(310,150,"�о�������");
	outtextxy(480,150,"��ʦ����");
	outtextxy(605,150,"�о������ʦ������");
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
	char *initial = "��ҳ", *a = "��ҳ>Ժϵ������Ŀͳ��", mm[20];
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
	outtextxy(160, 150, "Ժϵ����");
	outtextxy(290, 150, "973��Ŀ��");
	outtextxy(410, 150, "863��Ŀ��");
	outtextxy(520, 150, "�о��ܾ���");
	outtextxy(650, 150, "������Ŀ��");
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
	char *initial = "��ҳ", *a = "��ҳ>�����Ŷ���Ŀͳ��", mm[20];
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
	outtextxy(180, 150, "�Ŷ�����");
	outtextxy(360, 150, "�����ܾ���");
	outtextxy(600, 150, "��Ŀ����");
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
	char *initial = "��ҳ", *a = "��ҳ>�����Ŷӱ�ֵͳ��", mm[20];
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
	outtextxy(180, 150, "�Ŷ�����");
	outtextxy(310, 150, "������Ŀ��");
	outtextxy(480, 150, "��ʦ����");
	outtextxy(575, 150, "������Ŀ�����ʦ������");
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
	char *initial = "��ҳ", *a = "��ҳ>��ʦƽ������ͳ��", mm[20];
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
	outtextxy(180, 150, "�Ŷ�����");
	outtextxy(330, 150, "���о���");
	outtextxy(470, 150, "��ʦ����");
	outtextxy(615, 150, "��ʦƽ������");
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
*�������ƣ�creat_list
*�������ܣ�����һ�����������ʮ�ֽ�������
*�����������������ͷָ��ĵ�ַ
*����������������������ĵ�ַ��ͷָ�븳ֵ
*����ֵ  ����
*����˵�����˺�����������Ĺ����ж��ǽ�������ȳ���
*/
void creat_list(DEP **head)
{
	DEP *hp = NULL, *p;
	GRP *pgrp;
	SUB *psub;
	char ch = '1';
	while (ch == '1')
	{
		p = (DEP *)malloc(sizeof(DEP));    /*����Ժϵ��Ϣ�Ľڵ�*/
		scanf("%s %s %s", p->dname, p->dperson, p->dphone);
		getchar();       /*�̵��س�����ͬ*/
		p->head_group = NULL;     /*ʹ�Ŷ���Ϣ������ͷ�ÿ�*/
		p->next = hp;
		hp = p;     /*����ȳ��Ľڵ�*/
		printf("Continue? 1 or 0\n");
		ch = getchar();
		getchar();
	}
	(*head) = hp;      /*ͨ��ָ��ʹ��������ͷָ��ı�*/
	p = (*head);       /*ָ����ͷ���к�������*/
	while (p != NULL)
	{
		ch = '1';
		while (ch == '1')
		{
			pgrp = (GRP *)malloc(sizeof(GRP));     /*�����Ŷ���Ϣ�Ľڵ�*/
			scanf("%s %s %d %d", pgrp->gname, pgrp->person, &pgrp->tp, &pgrp->mp);
			getchar();
			strcpy(pgrp->dname, p->dname);     /*����ͬ��Ժϵ��Ϣ���и�ֵ*/
			pgrp->head_subject = NULL;      /*ʹ��Ŀ��Ϣ����ͷ�ÿ�*/
			pgrp->next = p->head_group;
			p->head_group = pgrp;       /*����ȳ��Ľڵ�*/
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
				psub = (SUB *)malloc(sizeof(SUB));      /*������Ŀ��Ϣ�Ľڵ�*/
				scanf("%s %c %s %f %s", psub->sname, &psub->type, psub->time, &psub->money, psub->sperson);
				getchar();
				strcpy(psub->gname, pgrp->gname);
				psub->next = pgrp->head_subject;
				pgrp->head_subject = psub;     /*����ȳ��Ľڵ�*/
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
*�������ƣ�trave_list
*�������ܣ����������������������ʮ�ֽ�������
*����������������е�ͷָ��
*�����������
*����ֵ  ����
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
*�������ƣ�save_list
*�������ܣ����洴���ʮ�ֽ�������
*����������������е�ͷָ��
*�������������������������ļ�
*����ֵ����
*/
void save_list(DEP *head)
{
	FILE *out1, *out2, *out3;
	DEP *p = head;
	GRP *pgrp;
	SUB *psub;
	if ((out1 = fopen("D:\\class\\departments.dat", "wb")) == NULL)  /*��Ժϵ��Ϣ�ļ�*/
	{
		printf("\t����Ժϵ��Ϣʧ��\n");
		exit(-1);
	}
	if ((out2 = fopen("D:\\class\\groups.dat", "wb")) == NULL)      /*���Ŷ���Ϣ�ļ�*/
	{
		printf("\t�����Ŷ���Ϣʧ��\n");
		exit(-1);
	}
	if ((out3 = fopen("D:\\class\\subjects.dat", "wb")) == NULL)     /*����Ŀ��Ϣ�ļ�*/
	{
		printf("\t������Ŀ��Ϣʧ��\n");
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
*�������ƣ�load_list
*�������ܣ��Ӷ������ļ����뵽ʮ�ֽ�������֮��
*���������������ͷָ��ĵ�ַ
*����������������������ĵ�ַ��ͷָ�븳ֵ
*����ֵ����
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
		printf("Ժϵ��Ϣ����ʧ��!\n");
		exit(-1);
	}
	else
		printf("Ժϵ��Ϣ���سɹ�!\n");
	if ((in2 = fopen("groups.dat", "rb")) == NULL)
	{
		printf("�Ŷ���Ϣ����ʧ��!\n");
		exit(-1);
	}
	else
		printf("�Ŷ���Ϣ���سɹ�!\n");
	if ((in3 = fopen("subjects.dat", "rb")) == NULL)
	{
		printf("��Ŀ��Ϣ����ʧ��!\n");
		exit(-1);
	}
	else
		printf("��Ŀ��Ϣ���سɹ�!\n");  /*�жϸ�����Ϣ�Ƿ�����ɹ�*/
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