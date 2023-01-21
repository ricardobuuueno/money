#pragma once

#include <string>
#include <filesystem>

namespace dd 
{

	class listener final 
	{
	public:
		explicit listener(const std::string& path, const unsigned wait)
			: m_path(path), m_wait(wait) 
		{}

		[[nodiscard]] bool found();
		void process();
		void wait();

	private:
		std::filesystem::path m_path;
		unsigned m_wait;

	};

}