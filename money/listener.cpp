#include "listener.hpp"

#include <Windows.h>

namespace dd
{

	bool listener::found()
	{
		return !std::filesystem::is_empty(m_path);
	}

	void listener::process()
	{

	}

	void listener::wait()
	{
		Sleep(m_wait);
	}

}