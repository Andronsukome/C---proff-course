#pragma once
#include <string>

class classFILE
{
private:
	enum FileStatus {FileClose = 0, FileOpen = 1, ErrorExit = 2, GoodExit = 3};
	FileStatus Status;
	FileStatus ExitProgram;
	std::string FileName;
	FILE *fp;
	bool OpenFAIL();
public:
	classFILE();
	bool FileWriteDATAforBackup(const void *pDATA, size_t SizeByteData, size_t NumBlock); 
	bool FileReadDATA(std::string EnterFilename, void *pReadData,  size_t ReadByte, size_t NumBlock);
	~classFILE();
};
