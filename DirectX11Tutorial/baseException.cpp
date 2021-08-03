#include "baseException.h"
#include <sstream>

baseException::baseException(int line, const char* file) noexcept
	:line(line), file(file)
{
}

const char* baseException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl << GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* baseException::GetType() const noexcept
{
	return "base exception";
}

int baseException::GetLine() const noexcept
{
	return line;
}

const std::string& baseException::GetFile() const noexcept
{
	return file;
}

std::string baseException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}