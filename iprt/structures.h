#ifndef _STRUCTURES_
#define _STRUCTURES_

//����
struct Color
{
	unsigned short r, g, b;
};

//������� � ��������� ������������
struct XYZ
{
	double x, y, z;
};


//�������� �����
struct Light
{
	XYZ pos;
	Color col;
};

#endif//_STRUCTURES_