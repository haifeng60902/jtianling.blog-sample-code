/***********************************************************************

  ��Ȩ����(C) 2009 ��������
  Copyright (C) 2009 JTianLing

  *********************************************************************
  ��һ���������������������������������������� GNU ͨ�ù������
  ֤�������޸ĺ����·�����һ���򡣻��������֤�ĵڶ��棬���ߣ��������ѡ
  �����κθ��µİ汾��
  ������һ�����Ŀ����ϣ�������ã���û���κε���������û���ʺ��ض�Ŀ
  �ĵ������ĵ���������ϸ���������� GNU ͨ�ù������֤��
  ��Ӧ���Ѿ��ͳ���һ���յ�һ�� GNU ͨ�ù������֤�ĸ����������û�У�
	д�Ÿ���
    The Free Software Foundation, Inc.,  675  Mass Ave,  Cambridge,
    MA02139,  USA
 *********************************************************************
  ��ӭ�����������ҳ����������˵�����۸������BUG�Ϳ��ԸĽ�֮��

  	Webs	: groups.google.com/group/jiutianfile
  	Blog	: blog.csdn.net/vagrxie
  	E-mail	: JTianLing@GMail.com
  	QQ	: 375454

  ��������Google Project Host���棬��Mercurial����
  Mercurial��ʹ�÷������Բο�
  http://blog.csdn.net/vagrxie/archive/2009/09/25/4593687.aspx
 *********************************************************************/
/***********************************************************************
	�ļ���Ϣ��
	��������:	2009-10-20
	�ļ���: 	GLShape.h
	�ļ�˵��:	CGLShapeͷ�ļ�
 *********************************************************************/
#ifndef __GLSHAPE_H__
#define __GLSHAPE_H__
#include <GL/glew.h>
#include <GL/wglew.h>
#include "Defines.h"
// ����ʵ���ƶ�����ת��
class CGLShape
{
public:
	CGLShape(void)
	{
		mfPosX = 0.0;
		mfPosY = 0.0;
		memset(mfvColor, 0, sizeof(mfvColor));
		mfDegree = 0.0;
		mfSize = 1.0;
	}
	virtual ~CGLShape(void) { }

	void SetSize(GLfloat afSize) { mfSize = afSize; }

	void SetColor(GLfloat afRed, GLfloat afGreen, GLfloat afBlue, GLfloat afAlpha = 1.0)
	{
		mfvColor[0] = afRed;
		mfvColor[1] = afGreen;
		mfvColor[2] = afBlue;
		mfvColor[3] = afAlpha;
	}

	// ���ƫ��(�ⲿ����ϵ����)
	void Move(int aiPosX, int aiPosY) 
	{
		mfPosX += 2.0f * aiPosX/(float)WIDTH;
		mfPosY += -(2.0f * aiPosY/(float)HEIGHT);
	}

	// �ƶ�����λ��(Windows����ϵ��)
	void MoveTo(int aiPosX, int aiPosY)
	{
		mfPosX = (2.0f * aiPosX - (float)WIDTH) / (float)WIDTH;
		mfPosY = -(2.0f * aiPosY - (float)HEIGHT) / (float)HEIGHT;
	}

	// ��ת,����ʱ��Ϊ������
	void Rotate(GLfloat aiDegree) { mfDegree += aiDegree; }

	// ��ת��
	void RotateTo(GLfloat aiDegree) { mfDegree = aiDegree; }

	// OpenGL����ϵ
	void SetPos(GLfloat afPosX, GLfloat afPosY) { mfPosX = afPosX; mfPosY = afPosY; }
	void GetPos(GLfloat& afPosX, GLfloat& afPosY) { afPosX = mfPosX; afPosY = mfPosY; }

	void Draw()
	{
		glLoadIdentity();
		glColor4fv(mfvColor);

		glPushMatrix();
		glTranslatef(mfPosX, mfPosY, 0.0);
		glRotatef(mfDegree, 0.0, 0.0, 1.0);

		DrawImp();

		glPopMatrix();
	}

protected:
	// �ػ�ʱ��Ҫ���õĺ���,�ɸ�����ʵ��
	virtual void DrawImp() = 0;

	// λ����Ϣ,û����POINT��Ϊ�˽���������ֲ
	GLfloat mfPosX;
	GLfloat mfPosY;

	// ��ɫ
	GLfloat mfvColor[4];

	// ��ת����
	GLfloat mfDegree;

	// ��С
	GLfloat mfSize;
};

#endif
