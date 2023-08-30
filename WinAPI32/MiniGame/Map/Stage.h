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

	//스테이지 어디인지 넣어주는 것 0은 숲 1은 사막
	void init(int stage);
	void Render(void);
	void Render(int a);
};

