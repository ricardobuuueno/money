#include "listener.hpp"
#include "reader.hpp"

#include <Windows.h>

namespace dd
{

	bool listener::found()
	{
		return !std::filesystem::is_empty(m_path);
	}

	void listener::process()
	{
		std::vector<std::string> files{};

		if (std::filesystem::exists(m_path))
		{
			for (auto const& entry : std::filesystem::directory_iterator{ m_path }) 
			{
				files.emplace_back(entry.path().string());
			}
		}

		for (auto const& filename : files) {
			file txt{ filename };
			if (txt.open()) {
				txt.read_all();
			}
		}
	}

	void listener::wait()
	{
		Sleep(m_wait);
	}

}