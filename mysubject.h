#include <graphics.h>			// 绘图库头文件，绘图语句需要
#include <conio.h>				// 控制台输入输出头文件，getch()语句需要
#include <stdio.h>
#include<stdlib.h>
#include <string.h>

/**
*科研项目信息的链表
*链表内容见链表后备注
*/
typedef struct subject_list
{
	char sname[15];       /* 项目编号*/
	char type;            /* 项目类别*/
	char time[8];         /* 项目起始时间*/
	float money;          /* 项目经费*/
	char sperson[12], gname[30];   /* 项目时间     //所属团队*/
	struct subject_list *next;    /* 指向下一个项目节点的自引用指针*/
}SUB;


/**
*团队信息的链表
*/
typedef struct group_list
{
	char gname[30], person[12];     /*团队名称   //负责人*/
	int tp, mp;      /* 教师人数    //研究生人数*/
	char dname[20];    /* 所属院系*/
	SUB *head_subject;      /* 指向项目信息链的头指针*/
	struct group_list *next;       /* 指向下一个团队节点的自引用指针*/
}GRP;


/**
*院系信息的链表
*/
typedef struct department_list
{
	char dname[20], dperson[12], dphone[15];    /*院系名称  //负责人  //联系电话*/
	GRP *head_group;       /*指向团队信息链的头指针*/
	struct department_list *next;      /*指向下一个院系信息的自引用指针*/
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

FBLOCK fixss[3] = { { ss[0],102,90,15,8,"院系信息维护(a)" },{ ss[1],102,115,15,8,"团队信息维护(b)" },{ ss[2],102,140,15,8,"项目信息维护(c)" } };
FBLOCK ftitle = { title,120,23,15,6,"首页" }, fCOT = { COT,110,48,18,9,"请按照相关提示信息进行操作" };
FBLOCK fchoice[3] = { { Choice[0],555,460,18,7,"上一页(-)" },{ Choice[1],625,460,18,7,"下一页(+)" },{ Choice[2],695,460,18,7,"返回(q)" } };
FBLOCK fsearch_block[3] = { { search_block[0],102,115,15,8,"院系信息查询(a)" },{ search_block[1],102,140,15,8,"团队信息查询(b)" },{ search_block[2],102,165,15,8,"项目信息查询(c)" } };
FBLOCK fcount_block[5] = { { count_block[0],102,140,15,8,"院系人数统计(a)" },{ count_block[1],102,165,15,8,"院系科研项目统计(b)" },{ count_block[2],102,190,15,8,"科研团队项目统计(c)" },{ count_block[3],102,215,15,8,"科研团队比值统计(d)" },{ count_block[4],102,240,15,8,"教师平均经费统计(e)" } };

MT information_of_change = { 120, 100, 0,"您想修改下列哪一项信息：" };
MT information_of_change1[3] = { { 205, 150,0,"院系信息(1)" },{ 205, 180,0,"负责人(2)" },{ 205, 210,0,"联系电话(3)" } };
MT information_of_change2[3] = { { 365, 150,0 },{ 365, 180,0 },{ 365, 210,0 } };
MT information_of_change3[4] = { { 205,150,0,"团队名称(1)" } ,{ 205,180,0,"负责人(2)" } ,{ 205,210,0,"教师人数(3)" } ,{ 205,240,0,"研究生人数(4)" } };
MT information_of_change4[4] = { { 365,150,0 } ,{ 365,180,0 } ,{ 365,210,0 } ,{ 365,240,0 } };
MT information_of_change5[5] = { { 205,150,0,"项目编号(1)" } ,{ 205,180,0,"项目类别(2)" } ,{ 205,210,0,"起始时间(3)" } ,{ 205,240,0,"项目经费(4)" },{ 205,270,0,"项目负责人(5)" } };
MT information_of_change6[6] = { { 365,150,0 } ,{ 365,180,0 } ,{ 365,210,0 } ,{ 365,240,0 },{ 365,270,0 } };
MT information_of_group[6] = { { 180,150,0,"团队名称" },{ 290,150,0,"负责人" },{ 355,150,0,"教师人数" },{ 425,150,0,"研究生人数" },{ 525,150,0,"所属院系" },{ 605,150,0,"录入信息(P)" } };
MT information_of_Subjects[7] = { { 163,150,0,"项目编号" },{ 245,150,0,"项目类别" },{ 305,150,0,"起始时间" },{ 375,150,0,"项目经费" },{ 445,150,0,"项目负责人" },{ 525,150,0,"所属团队" },{ 605,150,0,"录入信息(P)" } };
MT information_of_subjects[7] = { { 163,150,0,"项目编号" },{ 245,150,0,"项目类别" },{ 305,150,0,"起始时间" },{ 370,150,0,"项目经费(万)" },{ 455,150,0,"项目负责人" },{ 535,150,0,"所属团队" },{ 605,150,0,"录入信息(P)" } };
MT infor_of_dep_Search[2] = { { 205,150,0,"院系负责人条件查找(1)" } ,{ 205,180,0,"院系名模糊查找(2)" } };
MT infor_of_dep_search[2] = { { 205,150,0,"院系负责人条件查找(1)" } ,{ 205,180,0,"院系名模糊查找(2)" } };
MT infor_of_grp_Search[2] = { { 205,150,0,"团队名称模糊查找(1)" } ,{ 205,180,0,"教师人数条件查找(2)" } };
MT infor_of_grp_search[2] = { { 205,150,0,"团队名称模糊查找(1)" } ,{ 205,180,0,"教师人数条件查找(2)" } };
MT infor_of_sub_Search[2] = { { 205,150,0,"团队名称模糊查找(1)" } ,{ 205,180,0,"教师人数条件查找(2)" } };
MT infor_of_sub_search[2] = { { 205,150,0,"项目编号查找(1)" } ,{ 205,180,0,"项目所属团队查找(2)" } };
MT information_of_department[3] = { { 165, 150,0,"院系名称" },{ 315,150,0,"负责人" },{ 465,150,0,"联系电话" } };

IMAGE natsu;
MOUSEMSG myms;

CAN Group_change = { ',',1,0 };
CAN Sub_change = { ',',1,0 };
DEP *pphead;
int odcflag = 0;
void creat_list(DEP **head);        /*创建十字交叉链表*/
void save_list(DEP *head);         /*保存十字交叉链表*/
void load_list(DEP **head);         /*读取十字交叉链表*/
void tarve_list(DEP *head);         /*遍历十字交叉链表*/

void Change_mid(void);       /*改变中间框数值*/
void Change_infor(void);
void Change_CB(void);

void draw_all_blocks(void);   /*画出所有方块*/
void draw_all_txt(void);
void background(void);      /*背景输出函数*/
void draw_txt(MT a);
void draw_block(BLOCK a);    /*画框*/
void draw_fblock(FBLOCK a);  /*画出带有字的框*/
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
void input(void);    /*键盘输入读取函数*/

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

