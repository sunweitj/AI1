#ifndef CMyTimer_H
#define CMyTimer_H
//-----------------------------------------------------------------------
//
//  Name: CMyTimer.h
//
//  Author: Mat Buckland 2002 (fup@btinternet.com)
//
//	Desc: Windows timer class
//
//-----------------------------------------------------------------------

#include <windows.h>


class CMyTimer
{

private:

	LONGLONG	m_CurrentTime,
	          m_LastTime,
				    m_NextTime,
				    m_FrameTime,
				    m_PerfCountFreq;

	double		m_TimeElapsed,
				    m_TimeScale;

	float		  m_FPS;


public:

  //ctors
	CMyTimer();
	CMyTimer(float fps);


	//whatdayaknow, this starts the timer
  void		Start();

	//determines if enough time has passed to move onto next frame
  bool		ReadyForNextFrame();

	//only use this after a call to the above.
	double	GetTimeElapsed(){return m_TimeElapsed;}

	double	TimeElapsed();

};



#endif

	
