#include<iostream>
#undef UNICODE
#include<conio.h>
#include<stdio.h>
#include<graphics.h> //easyxͼ�ο�ͷ�ļ�
#include<mmsyscom.h>//����ý���ͷ�ļ�
#include<cstring>
#include <fstream>
using namespace std;
//ѧ��ͨѶ¼����ϵͳ7.0
//�����˹�����ע�Ṧ��
//�����ڴ������½�����Ա�˻�������
int flag = 0;
int lab = 0;
struct Student {
	char s_number[11];//ѧ��
	char s_name[9];//����
	char s_sex[3];//�Ա�
	char s_phone[12];//�绰
	char s_school[25];//����ѧԺ
	Student* next;
};
Student* head = NULL;
unsigned int count;
void nodoLine()//������
{
	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 3);
	line(0, 2, 1067, 2);
	line(0, 6, 1067, 6);
	line(0, 30, 1067, 30);
	line(0, 34, 1067, 34);
	line(2, 0, 2, 565);
	line(6, 0, 6, 565);
	line(1064, 0, 1064, 565);
	line(1060, 0, 1060, 565);
	line(0, 567, 1067, 567);
	line(0, 565, 1067, 565);
	setlinestyle(PS_SOLID, 1);
	line(204, 0, 204, 565);
	line(404, 0, 404, 565);
	line(504, 0, 504, 565);
	line(704, 0, 704, 565);
	for (int i = 0; i < 21; i++)
	{
		line(0, 60 + 25 * i, 1067, 60 + 25 * i);
	}
	settextcolor(WHITE);
	outtextxy(10, 10, "ѧ��");
	outtextxy(210, 10, "����");
	outtextxy(410, 10, "�Ա�");
	outtextxy(510, 10, "�绰");
	outtextxy(710, 10, "����ѧԺ");
	settextcolor(BLUE);
}
Student* mycreat()
{// ����ͨѶ¼��Ϣ�������� 
	Student* head, * p1, * p2;
	head = NULL;
	int n = 0;
	p1 = p2 = new Student;
	InputBox(p1->s_number, 11, "������ѧ��ѧ��");
	InputBox(p1->s_name, 9, "������ѧ������");
	InputBox(p1->s_sex, 3, "������ѧ���Ա�");
	InputBox(p1->s_phone, 12, "������ѧ���ֻ���");
	InputBox(p1->s_school, 25, "������ѧ������ѧԺ");
	//������һ��0ʱ����������
	while (p1->s_number[0] != '0')
	{
		n = n + 1;
		if (n == 1)head = p1;
		else p2->next = p1;//��ÿ����ѧ����ӵ������ĩβ��
		p2 = p1;
		p1 = new Student;//Ϊ��һ��ѧ�������µ�Student���󣬲���p1ָ������
		InputBox(p1->s_number, 11, "������ѧ��ѧ��");
		InputBox(p1->s_name, 9, "������ѧ������");
		InputBox(p1->s_sex, 3, "������ѧ���Ա�");
		InputBox(p1->s_phone, 12, "������ѧ���ֻ���");
		InputBox(p1->s_school, 25, "������ѧ������ѧԺ");
	}
	p2->next = NULL; //��ѭ������ʱ�����һ��ѧ������һ��ָ�루��p2->next��������ΪNULL����ʾ����Ľ�����
	settextstyle(25, 0, "����");
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	char arr[] = "�ѳɹ�����һ��ͨѶ¼";
	outtextxy(440, 300, arr);
	return (head);
}
void mydisplay(Student* head)
{// ��ʾͨѶ¼��Ϣ�������� 
	Student* p1;
	p1 = head;
	unsigned int i;
	i = 37;
	nodoLine();
	while (p1 != NULL && i < 541)
	{
		settextcolor(WHITE);
		outtextxy(13, i, p1->s_number);
		outtextxy(213, i, p1->s_name);
		outtextxy(413, i, p1->s_sex);
		outtextxy(513, i, p1->s_phone);
		outtextxy(713, i, p1->s_school);//���������ʽ
		i += 25;
		p1 = p1->next;
	}
		
}
void search1(Student* head) 
{//ѧ�Ų���
	char num[11];
	Student* p;
	p = head;
	InputBox(num, 11, "��������Ҫ����ѧ����ѧ��");
	bool finded = false;
	while (p != NULL) {
		if (strcmp(p->s_number, num) == 0) {
			finded = true;
			nodoLine();
			settextcolor(WHITE);
			outtextxy(13, 37, p->s_number);
			outtextxy(213, 37, p->s_name);
			outtextxy(413, 37, p->s_sex);
			outtextxy(513, 37, p->s_phone);
			outtextxy(713, 37, p->s_school);
		}
		p = p->next;
	}
	if (!finded) {
		settextstyle(25, 0, "����");
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		char arr[] = "û�в�ѯ����ͬѧ����Ϣ";
		outtextxy(440, 300, arr);
	}

}
void search2(Student* head) 
{//��������
	char name[9];
	Student* p;
	p = head;
	InputBox(name, 9, "��������Ҫ����ѧ��������");
	bool finded = false;
	while (p != NULL) {
		if (strcmp(p->s_name, name) == 0) {
			finded = true;
			nodoLine();
			settextcolor(WHITE);
			outtextxy(13, 37, p->s_number);
			outtextxy(213, 37, p->s_name);
			outtextxy(413, 37, p->s_sex);
			outtextxy(513, 37, p->s_phone);
			outtextxy(713, 37, p->s_school);
		}
		p = p->next;
	}
	if (!finded) {
		settextstyle(25, 0, "����");
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		char arr[] = "û�в�ѯ����ͬѧ����Ϣ";
		outtextxy(440, 300, arr);
	}
}
Student* myadd(Student* head) 
{// ���ͨѶ¼��Ϣ��������
	Student* p0, * p1, * p2;
	p1 = head;
	p2 = new Student;
	p0 = new Student; // ����ڵ�
	InputBox(p0->s_number, 11, "��������Ҫ���ѧ��ѧ��");
	InputBox(p0->s_name, 9, "��������Ҫ���ѧ������");
	InputBox(p0->s_sex, 3, "��������Ҫ���ѧ���Ա�");
	InputBox(p0->s_phone, 12, "��������Ҫ���ѧ���ֻ���");
	InputBox(p0->s_school, 25, "��������Ҫ���ѧ������ѧԺ");
	Student* p;
	p = head;
	bool finded = false;
	while (p != NULL) {
		if (strcmp(p->s_number, p0->s_number) == 0) {
			finded = true;
			settextstyle(25, 0, "����");
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			char arr[] = "�Ѵ��ڸ�ͬѧ����Ϣ�����������Ƿ�����";
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
				p1 = p1->next;// p0,p1��p2λ��: p2->p1->p0
			}

		if ((int)(p0->s_number) <= (int)(p1->s_number))
		{
			if (p1 == head)
			{// ͷ��ǰ�β��� p0��p1λ��: p0->p1->...
				head = p0;
				p0->next = p1;
			}
			else
			{// �����м�ڵ� p0,p1��p2λ��: p2-> p0 -> p1
				p2->next = p0;
				p0->next = p1;
			}
		}
		else
		{   // β������ڵ� p0,p1��p2λ��: p2->p1->p0->NULL
			p1->next = p0;
			p0->next = NULL;
		}
		settextstyle(25, 0, "����");
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		char arr[] = "�ѳɹ���Ӹ�ѧ������Ϣ";
		outtextxy(440, 300, arr);
	}
	return head;
}
void mymodify(Student* head) 
{// �޸�ͨѶ¼��Ϣ�������� 
	char ans[2];
	InputBox(ans, 2, "���Ȳ�ѯ��Ҫ�޸���Ϣ��ͬѧ(1.ѧ�� 2.����)");
	if (ans[0] == '2') {
		char ans2[2];
		char name[9];
		Student* p;
		p = head;
		InputBox(name, 9, "��������Ҫ����ѧ��������");
		bool finded = false;
		while (p != NULL) {
			if (strcmp(p->s_name, name) == 0) {
				finded = true;
				nodoLine();
				settextcolor(WHITE);
				outtextxy(13, 37, p->s_number);
				outtextxy(213, 37, p->s_name);
				outtextxy(413, 37, p->s_sex);
				outtextxy(513, 37, p->s_phone);
				outtextxy(713, 37, p->s_school);
				InputBox(ans2, 2, "��������Ҫ�޸ĵ���Ϣ(1.ѧ�� 2.���� 3.�Ա� 4.�绰 5.ѧԺ)");
				switch (ans2[0]) {
				case '1':InputBox(p->s_number, 11, "�������޸ĺ��ѧ��"); break;
				case '2':InputBox(p->s_name, 9, "�������޸ĺ������"); break;
				case '3':InputBox(p->s_sex, 3, "�������޸ĺ���Ա�"); break;
				case '4':InputBox(p->s_phone, 12, "�������޸ĺ�ĵ绰"); break;
				case '5':InputBox(p->s_school, 25, "�������޸ĺ��ѧԺ"); break;
				}
				break;
			}
			p = p->next;
		}
		settextstyle(25, 0, "����");
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		char arr[] = "�ѳɹ��޸ĸ�ѧ������Ϣ";
		outtextxy(440, 600, arr);
		if (!finded) {
			settextstyle(25, 0, "����");
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			char arr[] = "û�в�ѯ����ͬѧ����Ϣ";
			outtextxy(440, 600, arr);
		}
	}
	else if (ans[0] == '1') {
		char ans3[2];
		char number[11];
		Student* p;
		p = head;
		InputBox(number, 11, "��������Ҫ����ѧ����ѧ��");
		bool finded = false;
		while (p != NULL) {
			if (strcmp(p->s_number, number) == 0) {
				finded = true;
				nodoLine();
				settextcolor(WHITE);
				outtextxy(13, 37, p->s_number);
				outtextxy(213, 37, p->s_name);
				outtextxy(413, 37, p->s_sex);
				outtextxy(513, 37, p->s_phone);
				outtextxy(713, 37, p->s_school);
				InputBox(ans3, 2, "��������Ҫ�޸ĵ���Ϣ(1.ѧ�� 2.���� 3.�Ա� 4.�绰 5.ѧԺ)");
				switch (ans3[0]) {
				case '1':InputBox(p->s_number, 11, "�������޸ĺ��ѧ��"); break;
				case '2':InputBox(p->s_name, 9, "�������޸ĺ������"); break;
				case '3':InputBox(p->s_sex, 3, "�������޸ĺ���Ա�"); break;
				case '4':InputBox(p->s_phone, 12, "�������޸ĺ�ĵ绰"); break;
				case '5':InputBox(p->s_school, 25, "�������޸ĺ��ѧԺ"); break;
				}
				break;
			}
			p = p->next;
		}
		settextstyle(25, 0, "����");
		settextcolor(WHITE);
		setbkmode(TRANSPARENT);
		char arr[] = "�ѳɹ��޸ĸ�ѧ������Ϣ";
		outtextxy(440, 600, arr);
		if (!finded) {
			settextstyle(25, 0, "����");
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			char arr[] = "û�в�ѯ����ͬѧ����Ϣ";
			outtextxy(440, 600, arr);
		}
	}
}
Student* mydelete(Student* head) 
{// ɾ��ͨѶ¼��Ϣ��������
	char ansdel[2];
	char c[2];
	InputBox(ansdel, 2, "��ѡ����ݺ��ַ�ʽȷ����Ҫɾ��ѧ����1.ѧ�� 2.������");
	if (ansdel[0] == '1') {
		char delnumber[11];
		InputBox(delnumber, 11, "��������Ҫɾ����ѧ��ѧ��");
		struct Student* p1, * p2 = NULL;
		if (head == NULL)
		{
			settextstyle(25, 0, "����");
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			char arr[] = "ͨѶ¼Ϊ��";
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
			settextcolor(WHITE);
			outtextxy(13, 37, p1->s_number);
			outtextxy(213, 37, p1->s_name);
			outtextxy(413, 37, p1->s_sex);
			outtextxy(513, 37, p1->s_phone);
			outtextxy(713, 37, p1->s_school);
			InputBox(c, 2, "ȷ��Ҫɾ����ͬѧ����Ϣ�𣿣���:y,��:n��");
			if (c[0] == 'n') return head;
			else {
				if (strcmp(delnumber, head->s_number) == 0)head = p1->next;
				else p2->next = p1->next;
			}
			settextstyle(25, 0, "����");
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			char arrdel[] = "�ѳɹ�ɾ����ѧ������Ϣ";
			outtextxy(440, 600, arrdel);
		}
		else {
			settextstyle(25, 0, "����");
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			char arrdel2[] = "ͨѶ¼��û��¼���ͬѧ����Ϣ";
			outtextxy(440, 600, arrdel2);
		}
		return head;

	}
	else if (ansdel[0] == '2') 
	{
		char delname[9];
		InputBox(delname, 9, "��������Ҫɾ����ѧ������");
		struct Student* p1, * p2 = NULL;
		if (head == NULL)
		{
			settextstyle(25, 0, "����");
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			char arr[] = "ͨѶ¼Ϊ��";
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
			settextcolor(WHITE);
			outtextxy(13, 37, p1->s_number);
			outtextxy(213, 37, p1->s_name);
			outtextxy(413, 37, p1->s_sex);
			outtextxy(513, 37, p1->s_phone);
			outtextxy(713, 37, p1->s_school);
			InputBox(c, 2, "ȷ��Ҫɾ����ͬѧ����Ϣ�𣿣���:y,��:n��");
			if (c[0] == 'n') return head;
			else {
				if (strcmp(delname, head->s_name) == 0)head = p1->next;
				else p2->next = p1->next;
			}
			settextstyle(25, 0, "����");
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			char arrdel[] = "�ѳɹ�ɾ����ѧ������Ϣ";
			outtextxy(440, 600, arrdel);
		}
		else {
			settextstyle(25, 0, "����");
			settextcolor(WHITE);
			setbkmode(TRANSPARENT);
			char arrdel2[] = "ͨѶ¼��û��¼���ͬѧ����Ϣ";
			outtextxy(440, 600, arrdel2);
		}
		return head;

	}
}
void fuzhi(char a[], char b[], int n) 
{//���鸴�ƺ���
	for (int i = 0; i < n; i++)
	{
		a[i] = b[i];
	}

}
void mysort(Student* head) 
{// ͨѶ¼��Ϣ���������� 
	Student* p;
	char temp[11], temp2[9], temp3[3], temp4[12], temp5[25];
	int flag1;
	while (true) 
	{
		flag1 = 0;
		for (p = head; p->next != NULL; p = p->next) 
		{
			if (strcmp(p->s_number, p->next->s_number) == 1) 
			{
				fuzhi(temp, p->s_number, 11);
				fuzhi(p->s_number, p->next->s_number, 11);
				fuzhi(p->next->s_number, temp, 11);
				fuzhi(temp2, p->s_name, 9);
				fuzhi(p->s_name, p->next->s_name, 9);
				fuzhi(p->next->s_name, temp2, 9);
				fuzhi(temp3, p->s_sex, 3);
				fuzhi(p->s_sex, p->next->s_sex, 3);
				fuzhi(p->next->s_sex, temp3, 3);
				fuzhi(temp4, p->s_phone, 12);
				fuzhi(p->s_phone, p->next->s_phone, 12);
				fuzhi(p->next->s_phone, temp4, 12);
				fuzhi(temp5, p->s_school, 25);
				fuzhi(p->s_school, p->next->s_school, 25);
				fuzhi(p->next->s_school, temp5, 25);
				flag1 = 1;
			}
		}
		if (flag1 == 0)break;
	}
	settextstyle(25, 0, "����");
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	char arr[] = "����ɰ���ѧ�ţ���С��������";
	outtextxy(440, 300, arr);
}
char setNumberNew[20];
char setPassWordNew[20];
void ManSignIn()
{
	if (lab == 0)
	{
		initgraph(1080, 700);//��������
	}
	IMAGE img;
	loadimage(&img, "res/startground1.0.jpg");
	putimage(0, 0, &img);
	//setbkcolor(YELLOW);
	cleardevice;
	settextstyle(50, 0, "������κ");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	char arr[] = "�Ͽ���ѧѧ��ͨѶ¼����ϵͳ";
	outtextxy(280, 80, arr);
	//������ť������ѡ�п��Կ�����
	MOUSEMSG m;
	settextstyle(25, 0, "����");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	char arrzuozhe[] = "����: nku2311344��ӯ��";
	outtextxy(400, 140, arrzuozhe);
	settextstyle(20, 0, "����");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	char arrbanben[] = "�汾:nku23��c++����ҵ7.0";
	outtextxy(420, 170, arrbanben);
	char setNumber[9] = "xyrnkuer";
	char InsetNumber[20];
	char setPassWord[8] = "2311344";
	char InsetPassWord[20];
	//����û��������붼��ȷ�Ž�������Ա����
	//���򵯴���ʾ����
	while (1)
	{
		InputBox(InsetNumber, 20, "���������Ա�˺�");
		InputBox(InsetPassWord, 20, "����������");
		/*ifstream UserSignIn;
		UserSignIn.open("UserSignIn.txt", ios::in);
		UserSignIn >> setNumberNew >> setPassWordNew;
		UserSignIn.close();// �ر��ļ�*/
		if ((strcmp(setNumber, InsetNumber) == 0 && strcmp(setPassWord, InsetPassWord) == 0)
			|| (strcmp(setNumberNew, InsetNumber) == 0 && strcmp(setPassWordNew, InsetPassWord) == 0))
		{
			//cleardevice();//����
			flag = 1;
			break;
		}
		else
		{
			HWND SignError = GetHWnd();//����������ڻ�ȡ��ͼ���ھ����
			int isok = MessageBox(SignError, "�û������������!", "��ʾ", MB_OK);
			continue;
		}
	}
}
void ManRegister()
{
	char InsetNumberNew[20];
	char InsetPassWordNew[20];
	InputBox(InsetNumberNew, 20, "�����ù���Ա�˺�");
	InputBox(InsetPassWordNew, 20, "����������");
	strcpy_s(setNumberNew, InsetNumberNew);
	strcpy_s(setPassWordNew,InsetPassWordNew);
	/*fstream myFile;
	myFile.open("UserSignIn.txt", ios::app); 
	myFile << InsetNumberNew << " "<< InsetPassWordNew << endl;
	myFile.close();*/
	lab = 1;
	ManSignIn();

}
void showmenu() 
{//��ҳ�溯��
	if (flag == 0)
	{
		initgraph(1080, 700);//��������
	}
	//��ʾͼƬ
	//1.����ͼƬ����
	IMAGE img;
	//2.��ͼƬ���浽����õı���load��ȥ���� 
	//��Ŀ-����-��������-����-�ַ���-��Ϊ���ֽ��ַ���
	loadimage(&img, "res/startground1.0.jpg");
	putimage(0, 0, &img);
	//3.ͨ����ɫ���ñ���
	setbkcolor(YELLOW);
	cleardevice;
	settextstyle(50, 0, "������κ");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	char arr[] = "�Ͽ���ѧѧ��ͨѶ¼����ϵͳ";
	outtextxy(280, 80, arr);
	//������ť������ѡ�п��Կ�����
	MOUSEMSG m;
	settextstyle(25, 0, "����");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	char arrzuozhe[] = "����: nku2311344��ӯ��";
	outtextxy(400, 140, arrzuozhe);
	settextstyle(20, 0, "����");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	char arrbanben[] = "�汾:nku23��c++����ҵ7.0";
	outtextxy(420, 170, arrbanben);
	//����ͨѶ¼
	setfillcolor(WHITE);
	solidrectangle(450, 200, 650, 250);
	settextstyle(25, 0, "΢�����");
	setbkmode(TRANSPARENT);
	outtextxy(480, 215, "����ͨѶ¼");
	//��ʾͨѶ¼
	setfillcolor(WHITE);
	solidrectangle(450, 255, 650, 305);
	settextstyle(25, 0, "΢�����");
	setbkmode(TRANSPARENT);
	outtextxy(480, 270, "��ʾͨѶ¼");
	//��ѯͨѶ¼
	setfillcolor(WHITE);
	solidrectangle(450, 310, 650, 360);
	settextstyle(25, 0, "΢�����");
	setbkmode(TRANSPARENT);
	outtextxy(480, 325, "��ѯͨѶ¼");
	//���ͨѶ¼
	setfillcolor(WHITE);
	solidrectangle(450, 365, 650, 415);
	settextstyle(25, 0, "΢�����");
	setbkmode(TRANSPARENT);
	outtextxy(480, 380, "���ͨѶ¼");
	//�޸�ͨѶ¼
	setfillcolor(WHITE);
	solidrectangle(450, 420, 650, 470);
	settextstyle(25, 0, "΢�����");
	setbkmode(TRANSPARENT);
	outtextxy(480, 435, "�޸�ͨѶ¼");
	//ɾ��ͨѶ¼
	setfillcolor(WHITE);
	solidrectangle(450, 475, 650, 525);
	settextstyle(25, 0, "΢�����");
	setbkmode(TRANSPARENT);
	outtextxy(480, 490, "ɾ��ͨѶ¼");
	//����ͨѶ¼
	setfillcolor(WHITE);
	solidrectangle(450, 530, 650, 580);
	settextstyle(25, 0, "΢�����");
	setbkmode(TRANSPARENT);
	outtextxy(480, 545, "����ͨѶ¼");
	//�˳�ͨѶ¼
	setfillcolor(WHITE);
	solidrectangle(450, 585, 650, 635);
	settextstyle(25, 0, "΢�����");
	setbkmode(TRANSPARENT);
	outtextxy(480, 600, "�˳�ͨѶ¼");
	setfillcolor(WHITE);
	solidrectangle(450, 640, 650, 690);
	settextstyle(25, 0, "΢�����");
	setbkmode(TRANSPARENT);
	outtextxy(480, 655, "ע�����Ա");
	while (1) {
		m = GetMouseMsg();
		//����ͨѶ¼
		//ȫ������һ��0��ʾ�������
		if (m.x >= 450 && m.x <= 650 && m.y >= 200 && m.y <= 250) {
			setlinecolor(RED);
			rectangle(448, 198, 652, 252);
			if (m.uMsg == WM_LBUTTONDOWN) {		//�������������ʵ����Ӧ����.
				loadimage(&img, "res/backgroundblue1.0.jpg");
				putimage(0, 0, &img);
				settextstyle(25, 0, "����");
				settextcolor(WHITE);
				setbkmode(TRANSPARENT);
				char arr[] = "ȫ������һ��0��ʾ�������";
				outtextxy(440, 150, arr);
				head = mycreat();
				break;
			}
		}
		else {	//����겻��Ŀ��λ�þ͸���֮ǰ�ı߿�.
			setlinecolor(WHITE);
			rectangle(448, 198, 652, 252);
		}
		//��ʾͨѶ¼
		if (m.x >= 450 && m.x <= 650 && m.y >= 255 && m.y <= 305) {
			setlinecolor(RED);
			rectangle(448, 253, 652, 307);
			if (m.uMsg == WM_LBUTTONDOWN) {		//�������������ʵ����Ӧ����.
				loadimage(&img, "res/backgroundblue1.0.jpg");
				putimage(0, 0, &img);
				mydisplay(head);
				break;
			}
		}
		else {	//����겻��Ŀ��λ�þ͸���֮ǰ�ı߿�.
			setlinecolor(WHITE);
			rectangle(448, 253, 652, 307);
		}
		//��ѯͨѶ¼
		if (m.x >= 450 && m.x <= 650 && m.y >= 310 && m.y <= 360) {
			setlinecolor(RED);
			rectangle(448, 308, 652, 362);
			if (m.uMsg == WM_LBUTTONDOWN) {	//�������������ʵ����Ӧ����.
				loadimage(&img, "res/background1.0.jpg");
				putimage(0, 0, &img);
				char ans[2];
				InputBox(ans, 2, "��������ݺ��ַ�ʽ��ѯ��1.ѧ�� 2.������");
				if (ans[0] == '1') {
					search1(head);
				}
				else if (ans[0] == '2') {
					search2(head);
				}
				break;
			}
		}
		else {	//����겻��Ŀ��λ�þ͸���֮ǰ�ı߿�.
			setlinecolor(WHITE);
			rectangle(448, 308, 652, 362);
		}
		//���ͨѶ¼
		if (m.x >= 450 && m.x <= 650 && m.y >= 365 && m.y <= 415) {
			setlinecolor(RED);
			rectangle(448, 363, 652, 417);
			if (m.uMsg == WM_LBUTTONDOWN) {		//�������������ʵ����Ӧ����.
				loadimage(&img, "res/background1.0.jpg");
				putimage(0, 0, &img);
				myadd(head);
				break;
			}
		}
		else {	//����겻��Ŀ��λ�þ͸���֮ǰ�ı߿�.
			setlinecolor(WHITE);
			rectangle(448, 363, 652, 417);
		}
		//�޸�ͨѶ¼
		if (m.x >= 450 && m.x <= 650 && m.y >= 420 && m.y <= 470) {
			setlinecolor(RED);
			rectangle(448, 418, 652, 472);
			if (m.uMsg == WM_LBUTTONDOWN) {		//�������������ʵ����Ӧ����.
				loadimage(&img, "res/background1.0.jpg");
				putimage(0, 0, &img);
				mymodify(head);
				break;
			}
		}
		else {	//����겻��Ŀ��λ�þ͸���֮ǰ�ı߿�.
			setlinecolor(WHITE);
			rectangle(448, 418, 652, 472);
		}
		//ɾ��ͨѶ¼
		if (m.x >= 450 && m.x <= 650 && m.y >= 475 && m.y <= 525) {
			setlinecolor(RED);
			rectangle(448, 473, 652, 527);
			if (m.uMsg == WM_LBUTTONDOWN) {		//�������������ʵ����Ӧ����.
				loadimage(&img, "res/background1.0.jpg");
				putimage(0, 0, &img);
				mydelete(head);
				break;
			}
		}
		else {	//����겻��Ŀ��λ�þ͸���֮ǰ�ı߿�.
			setlinecolor(WHITE);
			rectangle(448, 473, 652, 527);
		}
		//����ͨѶ¼
		if (m.x >= 450 && m.x <= 650 && m.y >= 530 && m.y <= 580) {
			setlinecolor(RED);
			rectangle(448, 528, 652, 582);
			if (m.uMsg == WM_LBUTTONDOWN) {		//�������������ʵ����Ӧ����.
				loadimage(&img, "res/background1.0.jpg");
				putimage(0, 0, &img);
				mysort(head);
				break;
			}
		}
		else {	//����겻��Ŀ��λ�þ͸���֮ǰ�ı߿�.
			setlinecolor(WHITE);
			rectangle(448, 528, 652, 582);
		}
		//�˳�ͨѶ¼
		if (m.x >= 450 && m.x <= 650 && m.y >= 585 && m.y <= 635) {
			setlinecolor(RED);
			rectangle(448, 583, 652, 637);
			if (m.uMsg == WM_LBUTTONDOWN) {		//�������������ʵ����Ӧ����.
				closegraph();
				printf("�����˳�ͨѶ¼��������Ҫ��رճ����ٴδ�");
				break;
			}
		}
		else {	//����겻��Ŀ��λ�þ͸���֮ǰ�ı߿�.
			setlinecolor(WHITE);
			rectangle(448, 583, 652, 637);
		}
		//ע�����Ա
		if (m.x >= 450 && m.x <= 650 && m.y >= 640 && m.y <= 690) {
			setlinecolor(RED);
			rectangle(448, 638, 652, 692);
			if (m.uMsg == WM_LBUTTONDOWN) {		//�������������ʵ����Ӧ����.
				loadimage(&img, "res/startground1.0.jpg");
				putimage(0, 0, &img);
				ManRegister();
				break;
			}
		}
		else {	//����겻��Ŀ��λ�þ͸���֮ǰ�ı߿�.
			setlinecolor(WHITE);
			rectangle(448, 638, 652, 692);
		}
	}
}
int main() 
{
	ManSignIn();
	showmenu();
	while (1) 
	{
		if (!_kbhit()) 
		{
			//�������⴦�ص����棬���ǵ�һ�β������̵���(3.0�汾���޸���
			MOUSEMSG m1 = GetMouseMsg();
			if (m1.uMsg == WM_RBUTTONDOWN)//�Ҽ�����
			{
				flag = 1;
				showmenu();
			}
		}
	}
	// ��������˳�
	_getch();
	closegraph();//�رմ���
}