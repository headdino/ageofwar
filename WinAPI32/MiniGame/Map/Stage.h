#pragma once

class Stage
{
private:
	Image* m_bg;
	int m_stage;
	float m_lpsp;

public:
	Stage();
	~Stage();

	//�������� ������� �־��ִ� �� 0�� �� 1�� �縷
	void init(int stage);
	void Render(void);
	void Render(int a);
};

