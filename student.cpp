#include "student.h"
#include <iostream>
#include <string.h>
#include <cassert>

#define MAX_SIZE 100

Students STUS[MAX_SIZE];
uint32_t COUNTER;

Students::Students()
	:iXh(1), cName("hub"), iAge(0), cGender("男"), cMajors("junior"),cCity("深圳")
{
	//iXh = 1;
	//cName = "郝艳冰";
	//iAge = 0;
	//cMajors = "junior";
	//char cGender[20] = "男";
	//cCity = "深圳";
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
	printf("请输入整数学号：");
	scanf_s(" %ud", &stu.iXh);
	printf("请输入学生名字：");
	scanf_s(" %s", &stu.cName, 20);
	printf("请输入学生性别：");
	scanf_s(" %s", &stu.cGender, 20);
	printf("请输入学生年龄：");
	scanf_s(" %hd", &stu.iAge);
	printf("请输入学生专业：");
	scanf_s(" %s", &stu.cMajors, 20);
	printf("请输入学生城市：");
	scanf_s(" %s", &stu.cCity, 20);
	printf("\n");

	return stu;
}

void Students::AddStudent(Students& stu)
{
	if (COUNTER >= MAX_SIZE) return;
	STUS[COUNTER] = stu;
	COUNTER++;
	printf("学生信息已添加!\n\n\n");
}

void Students::DelStudent(uint32_t iXh)
{
	uint32_t position = FindPosition(iXh);
	if (position == -1)
	{
		printf("删除此学生信息失败!\n\n\n");
		return;
	}
	uint32_t i;
	for (i = position; i < COUNTER - 1; i++)
	{
		STUS[i] = STUS[i + 1];
	}
	COUNTER--;
	printf("此学生信息已删除!\n\n\n");
}

void Students::UpdateStudent(uint32_t iXh, Students& Newstu)
{
	uint32_t pos = FindPosition(iXh);
	if (pos == -1)
	{
		printf("修改学生信息失败!\n\n\n");
		return;
	}
	MyStrcopy(STUS[pos].cName, Newstu.cName);
	STUS[pos].iAge = Newstu.iAge;
	MyStrcopy(STUS[pos].cGender, Newstu.cGender);
	MyStrcopy(STUS[pos].cCity, Newstu.cCity);

	printf("此学生信息修改成功!\n\n\n");
}

Students Students::FindStudent(uint32_t iXh)
{
	uint32_t pos = FindPosition(iXh);
	if (pos == -1)
	{
		printf("学生学号未找到！查无此人!\n");
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
		printf("***********学生管理系统**********\n");
		printf("	  1.添加学生信息\n");
		printf("	  2.删除学生信息\n");
		printf("	  3.修改学生信息\n");
		printf("	  4.查找学生信息\n");
		printf("	  5.显示所有学生信息\n");
		printf("	  0.退出学生管理系统\n");
		printf("*********************************\n");

		uint32_t iCount = 0, iHx = 0;
		printf("\n进行选择：");
		scanf_s(" %d", &iCount);
		switch (iCount)
		{
		case 1:
			printf("=====请输入添加学生信息=====\n");
			STU = STU.AddStudentInfo(STU);
			STU.AddStudent(STU);
			break;
		case 2:
			printf("请输入删除的学生学号：");
			scanf_s(" %d", &iHx);
			STU.FindStudent(iHx);
			STU.DelStudent(iHx);
			break;
		case 3:
			printf("请输入修改学生的学号：");
			scanf_s(" %d", &iHx);
			STU.FindStudent(iHx);
			STU = STU.AddStudentInfo(STU);
			STU.UpdateStudent(iHx, STU);
			break;
		case 4:
			printf("请输入查询学生的学号：");
			scanf_s(" %d", &iHx);
			STU = STU.FindStudent(iHx);
			printf("%d %s %d %s %s %s\n", STU.iXh, STU.cName, STU.iAge, STU.cGender, STU.cMajors, STU.cCity);
			break;
		case 5:
			printf("显示所有学生信息：\n");
			STU.DelayAll();
			break;
		case 0:
			printf("已退出！\n");
			exit(0);
		default:
			printf("输入错误，请重新输入！\n\n\n");
			break;
		}
	}

	return 0;
}
