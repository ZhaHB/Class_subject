#include <graphics.h>			// ��ͼ��ͷ�ļ�����ͼ�����Ҫ
#include <conio.h>				// ����̨�������ͷ�ļ���getch()�����Ҫ
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

/**
*������Ŀ��Ϣ������
*�������ݼ������ע
*/
typedef struct subject_list
{
	char sname[15];       /* ��Ŀ���*/
	char type;            /* ��Ŀ���*/
	char time[8];         /* ��Ŀ��ʼʱ��*/
	float money;          /* ��Ŀ����*/
	char sperson[12], gname[30];   /* ��Ŀʱ��     //�����Ŷ�*/
	struct subject_list *next;    /* ָ����һ����Ŀ�ڵ��������ָ��*/
}SUB;


/**
*�Ŷ���Ϣ������
*/
typedef struct group_list
{
	char gname[30], person[12];     /*�Ŷ�����   //������*/
	int tp, mp;      /* ��ʦ����    //�о�������*/
	char dname[20];    /* ����Ժϵ*/
	SUB *head_subject;      /* ָ����Ŀ��Ϣ����ͷָ��*/
	struct group_list *next;       /* ָ����һ���Ŷӽڵ��������ָ��*/
}GRP;


/**
*Ժϵ��Ϣ������
*/
typedef struct department_list
{
	char dname[20], dperson[12], dphone[15];    /*Ժϵ����  //������  //��ϵ�绰*/
	GRP *head_group;       /*ָ���Ŷ���Ϣ����ͷָ��*/
	struct department_list *next;      /*ָ����һ��Ժϵ��Ϣ��������ָ��*/
}DEP;

typedef struct block
{
	int x1, y1, x2, y2;
	int sit;
	int on;
}BLOCK;

typedef struct fix_block
{
	BLOCK bl;
	int x, y, height, width;
	char *s;
}FBLOCK;
typedef struct mytxt
{
	int x, y;
	int on;
	char *s;
}MT;
typedef struct can
{
	char ch;
	int count;
	int on;
}CAN;

typedef struct department_only
{
	DEP *department;
	struct department_only *next;
	int teacher = 0, master = 0;
	float m_to_t = 0;
	int total_subjects = 0, subject973 = 0, subject863 = 0;
	float total_money = 0;
}DEPO;

typedef struct group_only
{
	GRP *group;
	struct group_only *next;
	int total_subject = 0, teacher = 0;
	float total_money = 0, sub_to_tc = 0;
	float m_to_t;
}GRPO;

BLOCK top = { 0, 0, 100, 60,3,1 }, bottom = { 0,60,100,500,1,1 }, title = { 100,0,800,40,2,1 };
BLOCK right = { 100,0,800,500,100,1 }, mid[5];
BLOCK ss[3] = { { 100,85,220,110,1,0 },{ 100,110,220,135,1,0 },{ 100,135,220,160,1,0 } };
BLOCK COT = { 100,40,800,70,4,0 };
BLOCK infor[9];
BLOCK Chang_block[9];
BLOCK Choice[3] = { { 550,458,620,480,1,1 },{ 620,458,690,480,1,1 },{ 690,458,760,480,1,1 } };
BLOCK search_block[3] = { { 100,110,220,135,1,0 },{ 100,135,220,160,1,0 },{ 100,160,220,185,1,0 } };
BLOCK count_block[5] = { { 100,135,250,160,1,0 },{ 100,160,250,185,1,0 },{ 100,185,250,210,1,0 },{ 100,210,250,235,1,0 },{ 100,235,250,260,1,0 } };

FBLOCK fixss[3] = { { ss[0],102,90,15,8,"Ժϵ��Ϣά��(a)" },{ ss[1],102,115,15,8,"�Ŷ���Ϣά��(b)" },{ ss[2],102,140,15,8,"��Ŀ��Ϣά��(c)" } };
FBLOCK ftitle = { title,120,23,15,6,"��ҳ" }, fCOT = { COT,110,48,18,9,"�밴�������ʾ��Ϣ���в���" };
FBLOCK fchoice[3] = { { Choice[0],555,460,18,7,"��һҳ(-)" },{ Choice[1],625,460,18,7,"��һҳ(+)" },{ Choice[2],695,460,18,7,"����(q)" } };
FBLOCK fsearch_block[3] = { { search_block[0],102,115,15,8,"Ժϵ��Ϣ��ѯ(a)" },{ search_block[1],102,140,15,8,"�Ŷ���Ϣ��ѯ(b)" },{ search_block[2],102,165,15,8,"��Ŀ��Ϣ��ѯ(c)" } };
FBLOCK fcount_block[5] = { { count_block[0],102,140,15,8,"Ժϵ����ͳ��(a)" },{ count_block[1],102,165,15,8,"Ժϵ������Ŀͳ��(b)" },{ count_block[2],102,190,15,8,"�����Ŷ���Ŀͳ��(c)" },{ count_block[3],102,215,15,8,"�����Ŷӱ�ֵͳ��(d)" },{ count_block[4],102,240,15,8,"��ʦƽ������ͳ��(e)" } };

MT information_of_change = { 120, 100, 0,"�����޸�������һ����Ϣ��" };
MT information_of_change1[3] = { { 205, 150,0,"Ժϵ��Ϣ(1)" },{ 205, 180,0,"������(2)" },{ 205, 210,0,"��ϵ�绰(3)" } };
MT information_of_change2[3] = { { 365, 150,0 },{ 365, 180,0 },{ 365, 210,0 } };
MT information_of_change3[4] = { { 205,150,0,"�Ŷ�����(1)" } ,{ 205,180,0,"������(2)" } ,{ 205,210,0,"��ʦ����(3)" } ,{ 205,240,0,"�о�������(4)" } };
MT information_of_change4[4] = { { 365,150,0 } ,{ 365,180,0 } ,{ 365,210,0 } ,{ 365,240,0 } };
MT information_of_change5[5] = { { 205,150,0,"��Ŀ���(1)" } ,{ 205,180,0,"��Ŀ���(2)" } ,{ 205,210,0,"��ʼʱ��(3)" } ,{ 205,240,0,"��Ŀ����(4)" },{ 205,270,0,"��Ŀ������(5)" } };
MT information_of_change6[6] = { { 365,150,0 } ,{ 365,180,0 } ,{ 365,210,0 } ,{ 365,240,0 },{ 365,270,0 } };
MT information_of_group[6] = { { 180,150,0,"�Ŷ�����" },{ 290,150,0,"������" },{ 355,150,0,"��ʦ����" },{ 425,150,0,"�о�������" },{ 525,150,0,"����Ժϵ" },{ 605,150,0,"¼����Ϣ(P)" } };
MT information_of_Subjects[7] = { { 163,150,0,"��Ŀ���" },{ 245,150,0,"��Ŀ���" },{ 305,150,0,"��ʼʱ��" },{ 375,150,0,"��Ŀ����" },{ 445,150,0,"��Ŀ������" },{ 525,150,0,"�����Ŷ�" },{ 605,150,0,"¼����Ϣ(P)" } };
MT information_of_subjects[7] = { { 163,150,0,"��Ŀ���" },{ 245,150,0,"��Ŀ���" },{ 305,150,0,"��ʼʱ��" },{ 370,150,0,"��Ŀ����(��)" },{ 455,150,0,"��Ŀ������" },{ 535,150,0,"�����Ŷ�" },{ 605,150,0,"¼����Ϣ(P)" } };
MT infor_of_dep_Search[2] = { { 205,150,0,"Ժϵ��������������(1)" } ,{ 205,180,0,"Ժϵ��ģ������(2)" } };
MT infor_of_dep_search[2] = { { 205,150,0,"Ժϵ��������������(1)" } ,{ 205,180,0,"Ժϵ��ģ������(2)" } };
MT infor_of_grp_Search[2] = { { 205,150,0,"�Ŷ�����ģ������(1)" } ,{ 205,180,0,"��ʦ������������(2)" } };
MT infor_of_grp_search[2] = { { 205,150,0,"�Ŷ�����ģ������(1)" } ,{ 205,180,0,"��ʦ������������(2)" } };
MT infor_of_sub_Search[2] = { { 205,150,0,"�Ŷ�����ģ������(1)" } ,{ 205,180,0,"��ʦ������������(2)" } };
MT infor_of_sub_search[2] = { { 205,150,0,"��Ŀ��Ų���(1)" } ,{ 205,180,0,"��Ŀ�����ŶӲ���(2)" } };
MT information_of_department[3] = { { 165, 150,0,"Ժϵ����" },{ 315,150,0,"������" },{ 465,150,0,"��ϵ�绰" } };

IMAGE natsu;
MOUSEMSG myms;

CAN Group_change = { ',',1,0 };
CAN Sub_change = { ',',1,0 };
DEP *pphead;
int odcflag = 0;
void creat_list(DEP **head);        /*����ʮ�ֽ�������*/
void save_list(DEP *head);         /*����ʮ�ֽ�������*/
void load_list(DEP **head);         /*��ȡʮ�ֽ�������*/
void tarve_list(DEP *head);         /*����ʮ�ֽ�������*/

void Change_mid(void);       /*�ı��м����ֵ*/
void Change_infor(void);
void Change_CB(void);

void draw_all_blocks(void);   /*�������з���*/
void draw_all_txt(void);
void background(void);      /*�����������*/
void draw_txt(MT a);
void draw_block(BLOCK a);    /*����*/
void draw_fblock(FBLOCK a);  /*���������ֵĿ�*/
void out_dep_cot(DEP *head);
void out_grp_cot(void);
void out_sub_cot(void);

void change_department(char ch);
void delect_department(char ch);
void input_department(void);
void change_group();
void delect_group();
void input_group();
void change_subject();
void delect_subject();
void input_subject();
void statics(int a);
void input(void);    /*���������ȡ����*/

void Search(void);
void Search_statics(int a);
void Search_department(void);
void Search_group(void);
void Search_subject(void);
int group_compare(int a, int b, char c);

void Count(void);
void Count_statics(int a);
void load_list_only(DEPO **depo_head, GRPO **grpo_head);
void count1(DEPO *head);
void count2(DEPO *head);
void count3(GRPO *head);
void count4(GRPO *head);
void count5(GRPO *head);
void swap(int *a, int *b);
void swap(float *a, float *b);
void swap(DEP **a, DEP **b);
void swap(GRP **a, GRP **b);
void inputcs(int a, char *c);

