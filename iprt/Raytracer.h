#ifndef _RAYTRACER_
#define _RAYTRACER_

#include<vector>
#include<cmath>
#include"structures.h"
#include"Primitives.h"
#include"util.h"

//�����, ������� ���������� ������������ �����
class Raytracer{
public:
	//����������� ������. ��������� ��� ��, ��� �������� � ����������� ������ � ���������� � ����� ��, ��� ���
	//����. ��� ����� ��������� � ������� ����� ������ ��� �������... �� ��� �����.
	Raytracer(XYZ eyePos, XYZ planePos, XYZ planeOX, XYZ planeOY, double planeSizeX, 
		double planeSizeY, int resoluionX, int resolutionY);

	//����� ��������� ����� ��������� �������
	Color getPixelColor(int x, int y);

	//��� �� �������� - ����� �������� ��������� ����� � �������� ����� ��������������
	void AddPrimitive(Primitive * s);
	void AddLight(Light l);

	void SetBackground(Color c);
	void SetGlobalLight(Color c);

	~Raytracer();
private:
	//������� ������ ��� ����� � ��������� ����� � �����
	std::vector<Primitive *> m_primitives;
	std::vector<Light> m_lights;

	//������� �����
	XYZ m_eyePos;

	//���������� ������ ������, � �����, � ������� ��������� ������� (0, 0)
	XYZ m_planeCenter;
	XYZ m_planeZero;

	//�������, ������������ ���� OX � OY ������
	XYZ m_planeOX;
	XYZ m_planeOY;

	//������� ������
	double m_planeSizeX, m_planeSizeY;

	//���������� ������
	int m_resolutionX, m_resolutionY;

	//������� ������� � ������������
	double m_pixelSizeX, m_pixelSizeY;

	Color m_globalLight;
	Color m_background;

	//��������������� �����, ������� ��������� ��������� ����� ����������� ���� � ����� �� ����.
	//ray - ���������� ����,
	//source - ������� ����,
	//s � len - ��������� �� �������, � ������� ��������� �����, � ������� ��������� ����������� �
	//����� �� ����������� ��������������.
	//���� ����������� ���������� ����� ����� true, ����� false
	bool calculateCross(XYZ ray, XYZ source, Primitive ** s, double * len, bool refractive);

	Color calcCrossColor(XYZ ray, XYZ source, int iterNum, double currRefraction, bool refractive);
};

#endif//_RAYTRACER_