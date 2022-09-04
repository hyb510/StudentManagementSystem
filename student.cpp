#include "student.h"
#include <iostream>
#include <string.h>
#include <cassert>

#define MAX_SIZE 100

Students STUS[MAX_SIZE];
uint32_t COUNTER;

Students::Students()
	:iXh(1), cName("hub"), iAge(0), cGender("��"), cMajors("junior"),cCity("����")
{
	//iXh = 1;
	//cName = "���ޱ�";
	//iAge = 0;
	//cMajors = "junior";
	//char cGender[20] = "��";
	//cCity = "����";
}

static uint32_t FindPosition(uint32_t iXh)
{
	uint32_t position;
	for (position = 0; position < MAX_SIZE; position++)
	{
		if (STUS[position].iXh == iXh)
		{
			return position;
		}
	}
	return -1;
}

static void OutStudent(Students& stu)
{
	printf("iXh:%d\n", stu.iXh);
	printf("cName:%s\n", stu.cName);
	printf("iAge:%d\n", stu.iAge);
	printf("cGender:%s\n", stu.cGender);
	printf("cMajors:%s\n", stu.cMajors);
	printf("cCity:%s\n", stu.cCity);
}

uint8_t* Students::MyStrcopy(uint8_t* dest, const uint8_t* src)
{
	assert(dest != NULL);
	assert(src != NULL);
	uint8_t* ret = dest;
	while (*dest++ = *src)
	{
	}
	return ret;
}

Students Students::AddStudentInfo(Students &stu)
{
	printf("����������ѧ�ţ�");
	scanf_s(" %ud", &stu.iXh);
	printf("������ѧ�����֣�");
	scanf_s(" %s", &stu.cName, 20);
	printf("������ѧ���Ա�");
	scanf_s(" %s", &stu.cGender, 20);
	printf("������ѧ�����䣺");
	scanf_s(" %hd", &stu.iAge);
	printf("������ѧ��רҵ��");
	scanf_s(" %s", &stu.cMajors, 20);
	printf("������ѧ�����У�");
	scanf_s(" %s", &stu.cCity, 20);
	printf("\n");

	return stu;
}

void Students::AddStudent(Students& stu)
{
	if (COUNTER >= MAX_SIZE) return;
	STUS[COUNTER] = stu;
	COUNTER++;
	printf("ѧ����Ϣ�����!\n\n\n");
}

void Students::DelStudent(uint32_t iXh)
{
	uint32_t position = FindPosition(iXh);
	if (position == -1)
	{
		printf("ɾ����ѧ����Ϣʧ��!\n\n\n");
		return;
	}
	uint32_t i;
	for (i = position; i < COUNTER - 1; i++)
	{
		STUS[i] = STUS[i + 1];
	}
	COUNTER--;
	printf("��ѧ����Ϣ��ɾ��!\n\n\n");
}

void Students::UpdateStudent(uint32_t iXh, Students& Newstu)
{
	uint32_t pos = FindPosition(iXh);
	if (pos == -1)
	{
		printf("�޸�ѧ����Ϣʧ��!\n\n\n");
		return;
	}
	MyStrcopy(STUS[pos].cName, Newstu.cName);
	STUS[pos].iAge = Newstu.iAge;
	MyStrcopy(STUS[pos].cGender, Newstu.cGender);
	MyStrcopy(STUS[pos].cCity, Newstu.cCity);

	printf("��ѧ����Ϣ�޸ĳɹ�!\n\n\n");
}

Students Students::FindStudent(uint32_t iXh)
{
	uint32_t pos = FindPosition(iXh);
	if (pos == -1)
	{
		printf("ѧ��ѧ��δ�ҵ������޴���!\n");
	}

	return STUS[pos];
}

void Students::DelayAll()
{
	uint32_t i;
	for (i = 0; i < COUNTER; i++)
	{
		OutStudent(STUS[i]);
		printf("---------------------------\n");
	}
}


Students::~Students()
{
}

int main(void)
{
	Students STU;
	while (1)
	{
		printf("***********ѧ������ϵͳ**********\n");
		printf("	  1.���ѧ����Ϣ\n");
		printf("	  2.ɾ��ѧ����Ϣ\n");
		printf("	  3.�޸�ѧ����Ϣ\n");
		printf("	  4.����ѧ����Ϣ\n");
		printf("	  5.��ʾ����ѧ����Ϣ\n");
		printf("	  0.�˳�ѧ������ϵͳ\n");
		printf("*********************************\n");

		uint32_t iCount = 0, iHx = 0;
		printf("\n����ѡ��");
		scanf_s(" %d", &iCount);
		switch (iCount)
		{
		case 1:
			printf("=====���������ѧ����Ϣ=====\n");
			STU = STU.AddStudentInfo(STU);
			STU.AddStudent(STU);
			break;
		case 2:
			printf("������ɾ����ѧ��ѧ�ţ�");
			scanf_s(" %d", &iHx);
			STU.FindStudent(iHx);
			STU.DelStudent(iHx);
			break;
		case 3:
			printf("�������޸�ѧ����ѧ�ţ�");
			scanf_s(" %d", &iHx);
			STU.FindStudent(iHx);
			STU = STU.AddStudentInfo(STU);
			STU.UpdateStudent(iHx, STU);
			break;
		case 4:
			printf("�������ѯѧ����ѧ�ţ�");
			scanf_s(" %d", &iHx);
			STU = STU.FindStudent(iHx);
			printf("%d %s %d %s %s %s\n", STU.iXh, STU.cName, STU.iAge, STU.cGender, STU.cMajors, STU.cCity);
			break;
		case 5:
			printf("��ʾ����ѧ����Ϣ��\n");
			STU.DelayAll();
			break;
		case 0:
			printf("���˳���\n");
			exit(0);
		default:
			printf("����������������룡\n\n\n");
			break;
		}
	}

	return 0;
}
