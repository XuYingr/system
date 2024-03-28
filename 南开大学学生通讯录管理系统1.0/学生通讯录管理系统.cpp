#include<iostream>
#undef UNICODE
#include<conio.h>
#include<stdio.h>
#include<graphics.h> //easyx图形库头文件
#include<mmsyscom.h>//鼠标多媒体库头文件
#include<cstring>
using namespace std;
struct Student {
	char s_number[5];//学号
	char s_name[9];//姓名
	char s_sex[3];//性别
	char s_phone[12];//电话
	char s_school[17];//所属学院
	Student* next;
};
Student* head = NULL;
unsigned int count;
void nodoLine()//表格绘制
{
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 3);
	line(0, 2, 1000, 2);
	line(0, 6, 1000, 6);
	line(0, 30, 1000, 30);
	line(0, 34, 1000, 34);
	line(2, 0, 2, 565);
	line(6, 0, 6, 565);
	line(997, 0, 997, 565);
	line(993, 0, 993, 565);
	line(0, 567, 1000, 567);
	line(0, 565, 1000, 565);
	setlinestyle(PS_SOLID, 1);
	line(204, 0, 204, 565);
	line(404, 0, 404, 565);
	line(604, 0, 604, 565);
	line(804, 0, 804, 565);
	for (int i = 0; i < 21; i++)
	{
		line(0, 60 + 25 * i, 1000, 60 + 25 * i);
	}
	settextcolor(RED);
	outtextxy(10, 10, "学号");
	outtextxy(210, 10, "姓名");
	outtextxy(410, 10, "性别");
	outtextxy(610, 10, "电话");
	outtextxy(810, 10, "所属学院");
	settextcolor(BLACK);
}
Student* mycreat() {// 创建通讯录信息函数定义 
	Student* head, * p1, * p2;
	head = NULL;
	int n = 0;
	p1 = p2 = new Student;
	InputBox(p1->s_number, 5, "请输入学生学号");
	InputBox(p1->s_name, 9, "请输入学生姓名");
	InputBox(p1->s_sex, 3, "请输入学生性别");
	InputBox(p1->s_phone, 12, "请输入学生手机号");
	InputBox(p1->s_school, 17, "请输入学生所属学院");
	while (p1->s_number[0] != '0') {
		n = n + 1;
		if (n == 1)head = p1;
		else p2->next = p1;
		p2 = p1;
		p1 = new Student;
		InputBox(p1->s_number, 5, "请输入学生学号");
		InputBox(p1->s_name, 9, "请输入学生姓名");
		InputBox(p1->s_sex, 3, "请输入学生性别");
		InputBox(p1->s_phone, 12, "请输入学生手机号");
		InputBox(p1->s_school, 17, "请输入学生所属学院");
	}
	p2->next = NULL;
	settextstyle(25, 0, "楷体");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	char arr[] = "已成功创建一个通讯录";
	outtextxy(440, 300, arr);
	return (head);
}
void mydisplay(Student* head) {// 显示通讯录信息函数定义 
	Student* p1;
	p1 = head;
	unsigned int i;
	i = 37;
	nodoLine();
	while (p1 != NULL) {
		outtextxy(13, i, p1->s_number);
		outtextxy(213, i, p1->s_name);
		outtextxy(413, i, p1->s_sex);
		outtextxy(613, i, p1->s_phone);
		outtextxy(813, i, p1->s_school);//文字输出形式
		i += 25;
		p1 = p1->next;
	}
}
void search1(Student* head) {//学号查找
	char num[5];
	Student* p;
	p = head;
	InputBox(num, 5, "请输入需要查找学生的学号");
	bool finded = false;
	while (p != NULL) {
		if (strcmp(p->s_number, num) == 0) {
			finded = true;
			nodoLine();
			outtextxy(13, 37, p->s_number);
			outtextxy(213, 37, p->s_name);
			outtextxy(413, 37, p->s_sex);
			outtextxy(613, 37, p->s_phone);
			outtextxy(813, 37, p->s_school);
		}
		p = p->next;
	}
	if (!finded) {
		settextstyle(25, 0, "楷体");
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		char arr[] = "没有查询到该同学的信息";
		outtextxy(440, 300, arr);
	}

}
void search2(Student* head) {//姓名查找
	char name[9];
	Student* p;
	p = head;
	InputBox(name, 9, "请输入需要查找学生的姓名");
	bool finded = false;
	while (p != NULL) {
		if (strcmp(p->s_name, name) == 0) {
			finded = true;
			nodoLine();
			outtextxy(13, 37, p->s_number);
			outtextxy(213, 37, p->s_name);
			outtextxy(413, 37, p->s_sex);
			outtextxy(613, 37, p->s_phone);
			outtextxy(813, 37, p->s_school);
		}
		p = p->next;
	}
	if (!finded) {
		settextstyle(25, 0, "楷体");
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		char arr[] = "没有查询到该同学的信息";
		outtextxy(440, 300, arr);
	}
}
Student* myadd(Student* head) {// 添加通讯录信息函数定义
	Student* p0, * p1, * p2;
	p1 = head;
	p2 = new Student;
	p0 = new Student; // 插入节点
	InputBox(p0->s_number, 5, "请输入需要添加学生学号");
	InputBox(p0->s_name, 9, "请输入需要添加学生姓名");
	InputBox(p0->s_sex, 3, "请输入需要添加学生性别");
	InputBox(p0->s_phone, 12, "请输入需要添加学生手机号");
	InputBox(p0->s_school, 17, "请输入需要添加学生所属学院");
	Student* p;
	p = head;
	bool finded = false;
	while (p != NULL) {
		if (strcmp(p->s_number, p0->s_number) == 0) {
			finded = true;
			settextstyle(25, 0, "楷体");
			settextcolor(BLACK);
			setbkmode(TRANSPARENT);
			char arr[] = "已存在该同学的信息，请检查输入是否有误";
			outtextxy(380, 300, arr);
			break;
		}
		p = p->next;
	}
	if (!finded) {
		if (head == NULL) {
			head = p0; p0->next = NULL;
		}
		else
			while ((int)(p0->s_number) > (int)(p1->s_number) && p1->next != NULL)
			{
				p2 = p1;
				p1 = p1->next;// p0,p1和p2位置: p2->p1->p0
			}

		if ((int)(p0->s_number) <= (int)(p1->s_number))
		{
			if (p1 == head)
			{// 头部前段插入 p0和p1位置: p0->p1->...
				head = p0;
				p0->next = p1;
			}
			else
			{// 插入中间节点 p0,p1和p2位置: p2-> p0 -> p1
				p2->next = p0;
				p0->next = p1;
			}
		}
		else
		{   // 尾部插入节点 p0,p1和p2位置: p2->p1->p0->NULL
			p1->next = p0;
			p0->next = NULL;
		}
		settextstyle(25, 0, "楷体");
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		char arr[] = "已成功添加该学生的信息";
		outtextxy(440, 300, arr);
	}
	return head;
}
void mymodify(Student* head) {// 修改通讯录信息函数定义 
	char ans[2];
	InputBox(ans, 2, "请先查询需要修改信息的同学(1.学号 2.姓名)");
	if (ans[0] == '2') {
		char ans2[2];
		char name[9];
		Student* p;
		p = head;
		InputBox(name, 9, "请输入需要查找学生的姓名");
		bool finded = false;
		while (p != NULL) {
			if (strcmp(p->s_name, name) == 0) {
				finded = true;
				nodoLine();
				outtextxy(13, 37, p->s_number);
				outtextxy(213, 37, p->s_name);
				outtextxy(413, 37, p->s_sex);
				outtextxy(613, 37, p->s_phone);
				outtextxy(813, 37, p->s_school);
				InputBox(ans2, 2, "请输入需要修改的信息(1.学号 2.姓名 3.性别 4.电话 5.学院)");
				switch (ans2[0]) {
				case '1':InputBox(p->s_number, 5, "请输入修改后的学号"); break;
				case '2':InputBox(p->s_name, 9, "请输入修改后的姓名"); break;
				case '3':InputBox(p->s_sex, 3, "请输入修改后的性别"); break;
				case '4':InputBox(p->s_phone, 12, "请输入修改后的电话"); break;
				case '5':InputBox(p->s_school, 17, "请输入修改后的学院"); break;
				}
				break;
			}
			p = p->next;
		}
		settextstyle(25, 0, "楷体");
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		char arr[] = "已成功修改该学生的信息";
		outtextxy(440, 600, arr);
		if (!finded) {
			settextstyle(25, 0, "楷体");
			settextcolor(BLACK);
			setbkmode(TRANSPARENT);
			char arr[] = "没有查询到该同学的信息";
			outtextxy(440, 600, arr);
		}
	}
	else if (ans[0] == '1') {
		char ans3[2];
		char number[9];
		Student* p;
		p = head;
		InputBox(number, 5, "请输入需要查找学生的学号");
		bool finded = false;
		while (p != NULL) {
			if (strcmp(p->s_number, number) == 0) {
				finded = true;
				nodoLine();
				outtextxy(13, 37, p->s_number);
				outtextxy(213, 37, p->s_name);
				outtextxy(413, 37, p->s_sex);
				outtextxy(613, 37, p->s_phone);
				outtextxy(813, 37, p->s_school);
				InputBox(ans3, 2, "请输入需要修改的信息(1.学号 2.姓名 3.性别 4.电话 5.学院)");
				switch (ans3[0]) {
				case '1':InputBox(p->s_number, 5, "请输入修改后的学号"); break;
				case '2':InputBox(p->s_name, 9, "请输入修改后的姓名"); break;
				case '3':InputBox(p->s_sex, 3, "请输入修改后的性别"); break;
				case '4':InputBox(p->s_phone, 12, "请输入修改后的电话"); break;
				case '5':InputBox(p->s_school, 17, "请输入修改后的学院"); break;
				}
				break;
			}
			p = p->next;
		}
		settextstyle(25, 0, "楷体");
		settextcolor(BLACK);
		setbkmode(TRANSPARENT);
		char arr[] = "已成功修改该学生的信息";
		outtextxy(440, 600, arr);
		if (!finded) {
			settextstyle(25, 0, "楷体");
			settextcolor(BLACK);
			setbkmode(TRANSPARENT);
			char arr[] = "没有查询到该同学的信息";
			outtextxy(440, 600, arr);
		}
	}
}
Student* mydelete(Student* head) {// 删除通讯录信息函数定义
	char ansdel[2];
	char c[2];
	InputBox(ansdel, 2, "请选择根据何种方式确定需要删除学生（1.学号 2.姓名）");
	if (ansdel[0] == '1') {
		char delnumber[5];
		InputBox(delnumber, 5, "请输入需要删除的学生学号");
		struct Student* p1, * p2 = NULL;
		if (head == NULL)
		{
			settextstyle(25, 0, "楷体");
			settextcolor(BLACK);
			setbkmode(TRANSPARENT);
			char arr[] = "通讯录为空";
			outtextxy(440, 600, arr);
		}
		p1 = head;
		while (strcmp(delnumber, p1->s_number) != 0 && p1->next != NULL)
		{
			p2 = p1; p1 = p1->next;
		}
		if (strcmp(delnumber, p1->s_number) == 0)
		{
			nodoLine();
			outtextxy(13, 37, p1->s_number);
			outtextxy(213, 37, p1->s_name);
			outtextxy(413, 37, p1->s_sex);
			outtextxy(613, 37, p1->s_phone);
			outtextxy(813, 37, p1->s_school);
			InputBox(c, 2, "确定要删除该同学的信息吗？（是:y,否:n）");
			if (c[0] == 'n') return head;
			else {
				if (strcmp(delnumber, head->s_number) == 0)head = p1->next;
				else p2->next = p1->next;
			}
			settextstyle(25, 0, "楷体");
			settextcolor(BLACK);
			setbkmode(TRANSPARENT);
			char arrdel[] = "已成功删除该学生的信息";
			outtextxy(440, 600, arrdel);
		}
		else {
			settextstyle(25, 0, "楷体");
			settextcolor(BLACK);
			setbkmode(TRANSPARENT);
			char arrdel2[] = "通讯录中没有录入该同学的信息";
			outtextxy(440, 600, arrdel2);
		}
		return head;

	}
	else if (ansdel[0] == '2') {
		char delname[9];
		InputBox(delname, 9, "请输入需要删除的学生姓名");
		struct Student* p1, * p2 = NULL;
		if (head == NULL)
		{
			settextstyle(25, 0, "楷体");
			settextcolor(BLACK);
			setbkmode(TRANSPARENT);
			char arr[] = "通讯录为空";
			outtextxy(440, 600, arr);
		}
		p1 = head;
		while (strcmp(delname, p1->s_name) != 0 && p1->next != NULL)
		{
			p2 = p1; p1 = p1->next;
		}
		if (strcmp(delname, p1->s_name) == 0)
		{
			nodoLine();
			outtextxy(13, 37, p1->s_number);
			outtextxy(213, 37, p1->s_name);
			outtextxy(413, 37, p1->s_sex);
			outtextxy(613, 37, p1->s_phone);
			outtextxy(813, 37, p1->s_school);
			InputBox(c, 2, "确定要删除该同学的信息吗？（是:y,否:n）");
			if (c[0] == 'n') return head;
			else {
				if (strcmp(delname, head->s_name) == 0)head = p1->next;
				else p2->next = p1->next;
			}
			settextstyle(25, 0, "楷体");
			settextcolor(BLACK);
			setbkmode(TRANSPARENT);
			char arrdel[] = "已成功删除该学生的信息";
			outtextxy(440, 600, arrdel);
		}
		else {
			settextstyle(25, 0, "楷体");
			settextcolor(BLACK);
			setbkmode(TRANSPARENT);
			char arrdel2[] = "通讯录中没有录入该同学的信息";
			outtextxy(440, 600, arrdel2);
		}
		return head;

	}
}
void fuzhi(char a[], char b[], int n) {//数组复制函数
	for (int i = 0; i < n; i++)
	{
		a[i] = b[i];
	}

}
void mysort(Student* head) {// 通讯录信息排序函数定义 
	Student* p;
	char temp[5], temp2[9], temp3[3], temp4[12], temp5[17];
	int flag;
	while (true) {
		flag = 0;
		for (p = head; p->next != NULL; p = p->next) {
			if (strcmp(p->s_number, p->next->s_number) == 1) {
				fuzhi(temp, p->s_number, 5);
				fuzhi(p->s_number, p->next->s_number, 5);
				fuzhi(p->next->s_number, temp, 5);
				fuzhi(temp2, p->s_name, 9);
				fuzhi(p->s_name, p->next->s_name, 9);
				fuzhi(p->next->s_name, temp2, 9);
				fuzhi(temp3, p->s_sex, 3);
				fuzhi(p->s_sex, p->next->s_sex, 3);
				fuzhi(p->next->s_sex, temp3, 3);
				fuzhi(temp4, p->s_phone, 12);
				fuzhi(p->s_phone, p->next->s_phone, 12);
				fuzhi(p->next->s_phone, temp4, 12);
				fuzhi(temp5, p->s_school, 17);
				fuzhi(p->s_school, p->next->s_school, 17);
				fuzhi(p->next->s_school, temp5, 17);
				flag = 1;
			}
		}
		if (flag == 0)break;
	}
	settextstyle(25, 0, "楷体");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	char arr[] = "已完成按照学号（从小到大）排序";
	outtextxy(440, 300, arr);
}
void showmenu() {//主页面函数
	initgraph(1080, 700);//创建窗口
	//显示图片
	//1.定义图片变量
	IMAGE img;
	//2.把图片保存到定义好的变量load中去加载 
	//项目-属性-配置属性-常规-字符集-改为多字节字符集
	loadimage(&img, "res/startground1.0.jpg");
	putimage(0, 0, &img);
	//3.通过颜色设置背景
	setbkcolor(YELLOW);
	cleardevice;
	settextstyle(50, 0, "华文新魏");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	char arr[] = "南开大学学生通讯录管理系统";
	outtextxy(280, 80, arr);
	//创建按钮，并且选中可以看到框
	MOUSEMSG m;
	settextstyle(25, 0, "楷体");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	char arrzuozhe[] = "作者: nku2311344徐盈蕊";
	outtextxy(400, 140, arrzuozhe);
	settextstyle(20, 0, "楷体");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	char arrbanben[] = "版本:nku23级c++大作业1.0";
	outtextxy(420, 170, arrbanben);
	//创建通讯录
	setfillcolor(WHITE);
	fillrectangle(450, 200, 650, 250);
	settextstyle(25, 0, "微软黑体");
	setbkmode(TRANSPARENT);
	outtextxy(480, 215, "创建通讯录");
	//显示通讯录
	setfillcolor(WHITE);
	fillrectangle(450, 255, 650, 305);
	settextstyle(25, 0, "微软黑体");
	setbkmode(TRANSPARENT);
	outtextxy(480, 270, "显示通讯录");
	//查询通讯录
	setfillcolor(WHITE);
	fillrectangle(450, 310, 650, 360);
	settextstyle(25, 0, "微软黑体");
	setbkmode(TRANSPARENT);
	outtextxy(480, 325, "查询通讯录");
	//添加通讯录
	setfillcolor(WHITE);
	fillrectangle(450, 365, 650, 415);
	settextstyle(25, 0, "微软黑体");
	setbkmode(TRANSPARENT);
	outtextxy(480, 380, "添加通讯录");
	//修改通讯录
	setfillcolor(WHITE);
	fillrectangle(450, 420, 650, 470);
	settextstyle(25, 0, "微软黑体");
	setbkmode(TRANSPARENT);
	outtextxy(480, 435, "修改通讯录");
	//删除通讯录
	setfillcolor(WHITE);
	fillrectangle(450, 475, 650, 525);
	settextstyle(25, 0, "微软黑体");
	setbkmode(TRANSPARENT);
	outtextxy(480, 490, "删除通讯录");
	//排序通讯录
	setfillcolor(WHITE);
	fillrectangle(450, 530, 650, 580);
	settextstyle(25, 0, "微软黑体");
	setbkmode(TRANSPARENT);
	outtextxy(480, 545, "排序通讯录");
	//退出通讯录
	setfillcolor(WHITE);
	fillrectangle(450, 585, 650, 635);
	settextstyle(25, 0, "微软黑体");
	setbkmode(TRANSPARENT);
	outtextxy(480, 600, "退出通讯录");
	while (1) {
		m = GetMouseMsg();
		//创建通讯录
		//全部输入0表示输入结束
		if (m.x >= 450 && m.x <= 650 && m.y >= 200 && m.y <= 250) {
			setlinecolor(RED);
			rectangle(448, 198, 652, 252);
			if (m.uMsg == WM_LBUTTONDOWN) {		//如果按下鼠标左键实现相应功能.
				//putimage(0, 0, &img);
				loadimage(NULL, _T("IMAGE"), _T("Background"));
				settextstyle(25, 0, "楷体");
				settextcolor(BLACK);
				setbkmode(TRANSPARENT);
				char arr[] = "全部输入0表示输入结束";
				outtextxy(440, 150, arr);
				head = mycreat();
				break;
			}
		}
		else {	//当鼠标不在目标位置就覆盖之前的边框.
			setlinecolor(WHITE);
			rectangle(448, 198, 652, 252);
		}
		//显示通讯录
		if (m.x >= 450 && m.x <= 650 && m.y >= 255 && m.y <= 305) {
			setlinecolor(RED);
			rectangle(448, 253, 652, 307);
			if (m.uMsg == WM_LBUTTONDOWN) {		//如果按下鼠标左键实现相应功能.
				//putimage(0, 0, &img);
				loadimage(NULL, _T("IMAGE"), _T("Background"));
				mydisplay(head);
				break;
			}
		}
		else {	//当鼠标不在目标位置就覆盖之前的边框.
			setlinecolor(WHITE);
			rectangle(448, 253, 652, 307);
		}
		//查询通讯录
		if (m.x >= 450 && m.x <= 650 && m.y >= 310 && m.y <= 360) {
			setlinecolor(RED);
			rectangle(448, 308, 652, 362);
			if (m.uMsg == WM_LBUTTONDOWN) {		//如果按下鼠标左键实现相应功能.
				//putimage(0, 0, &img);
				loadimage(NULL, _T("IMAGE"), _T("Background"));
				char ans[2];
				InputBox(ans, 2, "请输入根据何种方式查询（1.学号 2.姓名）");
				if (ans[0] == '1') {
					search1(head);
				}
				else if (ans[0] == '2') {
					search2(head);
				}
				break;
			}
		}
		else {	//当鼠标不在目标位置就覆盖之前的边框.
			setlinecolor(WHITE);
			rectangle(448, 308, 652, 362);
		}
		//添加通讯录
		if (m.x >= 450 && m.x <= 650 && m.y >= 365 && m.y <= 415) {
			setlinecolor(RED);
			rectangle(448, 363, 652, 417);
			if (m.uMsg == WM_LBUTTONDOWN) {		//如果按下鼠标左键实现相应功能.
				//putimage(0, 0, &img);
				loadimage(NULL, _T("IMAGE"), _T("Background"));
				myadd(head);
				break;
			}
		}
		else {	//当鼠标不在目标位置就覆盖之前的边框.
			setlinecolor(WHITE);
			rectangle(448, 363, 652, 417);
		}
		//修改通讯录
		if (m.x >= 450 && m.x <= 650 && m.y >= 420 && m.y <= 470) {
			setlinecolor(RED);
			rectangle(448, 418, 652, 472);
			if (m.uMsg == WM_LBUTTONDOWN) {		//如果按下鼠标左键实现相应功能.
				//putimage(0, 0, &img);
				loadimage(NULL, _T("IMAGE"), _T("Background"));
				mymodify(head);
				break;
			}
		}
		else {	//当鼠标不在目标位置就覆盖之前的边框.
			setlinecolor(WHITE);
			rectangle(448, 418, 652, 472);
		}
		//删除通讯录
		if (m.x >= 450 && m.x <= 650 && m.y >= 475 && m.y <= 525) {
			setlinecolor(RED);
			rectangle(448, 473, 652, 527);
			if (m.uMsg == WM_LBUTTONDOWN) {		//如果按下鼠标左键实现相应功能.
				//putimage(0, 0, &img);
				loadimage(NULL, _T("IMAGE"), _T("Background"));
				mydelete(head);
				break;
			}
		}
		else {	//当鼠标不在目标位置就覆盖之前的边框.
			setlinecolor(WHITE);
			rectangle(448, 473, 652, 527);
		}
		//排序通讯录
		if (m.x >= 450 && m.x <= 650 && m.y >= 530 && m.y <= 580) {
			setlinecolor(RED);
			rectangle(448, 528, 652, 582);
			if (m.uMsg == WM_LBUTTONDOWN) {		//如果按下鼠标左键实现相应功能.
				//putimage(0, 0, &img);
				loadimage(NULL, _T("IMAGE"), _T("Background"));
				mysort(head);
				break;
			}
		}
		else {	//当鼠标不在目标位置就覆盖之前的边框.
			setlinecolor(WHITE);
			rectangle(448, 528, 652, 582);
		}
		//退出通讯录
		if (m.x >= 450 && m.x <= 650 && m.y >= 585 && m.y <= 635) {
			setlinecolor(RED);
			rectangle(448, 583, 652, 637);
			if (m.uMsg == WM_LBUTTONDOWN) {		//如果按下鼠标左键实现相应功能.
				closegraph();
				printf("您已退出通讯录，如有需要请关闭程序再次打开");
				break;
			}
		}
		else {	//当鼠标不在目标位置就覆盖之前的边框.
			setlinecolor(WHITE);
			rectangle(448, 583, 652, 637);
		}
	}
}
int main() {
	showmenu();
	while (1) {
		if (!_kbhit()) {
			//鼠标点任意处回到界面，但是不能立刻弹出
			MOUSEMSG m1 = GetMouseMsg();
			if (m1.uMsg == WM_LBUTTONDOWN || m1.uMsg == WM_RBUTTONDOWN) {
				
				showmenu();
			}
		}
	}
	// 按任意键退出
	_getch();
	closegraph();//关闭窗口
}