#ifndef __STUDENT_H__
#define __STUDENT_H__
#include <windows.h>
#include <stdint.h>

class Students
{
public:
	Students();
	~Students();

	uint32_t iXh;
	uint8_t cName[20];	
	uint16_t iAge;
	uint8_t cGender[10];
	uint8_t cMajors[20];
	uint8_t cCity[20];

	Students AddStudentInfo(Students &stu);
	void AddStudent(Students &stu);
	void DelStudent(uint32_t xh);
	void UpdateStudent(uint32_t xh,Students &Newstu);
	Students FindStudent(uint32_t xh);
	void DelayAll();
	uint8_t* MyStrcopy(uint8_t* dest, const uint8_t* src);

private:

};





#endif // !__STUDENT_H__