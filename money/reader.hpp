#pragma once

#include <string>
#include <fstream>
 
namespace dd
{

	template <typename T>
	struct field final
	{
		const unsigned start;
		const unsigned end;
		T value;
	};

	class header final
	{
	public:
		explicit header(const std::string& line)
		{

		}

		static bool is_header(const std::string& line)
		{
			return (line.substr(0, 2) == "00");
		}

	private:
		field<std::string> type{ 1,2 };
		field<std::string> name{ 3,15 };
		field<std::string> origin{ 16,23 };
		field<std::string> date{ 24,31 };
		field<std::string> reserve{ 32,245 };
	};

	class data final
	{
	public:
		explicit data(const std::string& line)
		{

		}

		static bool is_data(const std::string& line)
		{
			return (line.substr(0, 2) == "01");
		}

	private:
	};

	class footer final
	{
	public:
		explicit footer(const std::string& line)
		{

		}

		static bool is_footer(const std::string& line)
		{
			return (line.substr(0, 2) == "99");
		}

	private:
	};

	class file final
	{
	public:
		explicit file(const std::string& filepath)
			: filepath(filepath) 
		{}

		~file();

		[[nodiscard]] bool open() noexcept;
		void read_all();

	private:
		const std::string filepath;
		std::ifstream filestream;

	};

}