#include "stdafx.h"
#include "classFILE.h"

classFILE::classFILE() : Status(FileClose), fp(NULL), FileName("~backup.tmp") // Создаём обьект FILE и открываем фаил для записи 
{
	if( fopen_s(&fp, FileName.data(),"rb") == NULL )
	{
		Status = FileOpen;
		ExitProgram = ErrorExit;
	}
	else
	{
		ExitProgram = GoodExit;
	}
	
}

bool classFILE::FileReadDATA(std::string EnterFilename, void *pReadData,  size_t ReadByte, size_t NumBlock)//Метод чтнения из файла
{
	if(ExitProgram == ErrorExit && Status == FileOpen)
	{
		if( fread(pReadData,ReadByte,NumBlock,fp) !=  NumBlock)
		{
			this->~classFILE();
			return false;
		}
		else
		{
			return true;
		}
	}
	else if(ExitProgram == GoodExit)
	{
		
		if( fread(pReadData,ReadByte,NumBlock,fp) !=  NumBlock)
		{
			this->~classFILE();
			return false;
		}
		else
		{
			return true;
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool classFILE::OpenFAIL() // Метод открытия файла Backup
{
	if( fopen_s(&fp, FileName.data(),"r+b") )
	{
		if( fopen_s(&fp, FileName.data(),"w+b") )
		{
			this->~classFILE();
			return false;
		}
		else
		{
			return true;
			Status = FileOpen;
		}
	}
	else
	{
		return true;
		Status = FileOpen;
	}

}

bool classFILE::FileWriteDATAforBackup(const void *pDATA, size_t SizeByteData, size_t NumBlock)//Метод записи в фаил Backup
{
	if(this->Status == FileClose)
	{
		if( !this->OpenFAIL() )
		{
			return false;
		}
	}
	if( fwrite(pDATA, SizeByteData, NumBlock, fp) != NumBlock )
	{
		rewind(fp);
		this->~classFILE();
		return false;
	}
	this->~classFILE();
	return true;
}

classFILE::~classFILE()
{
	fclose(fp);
	Status = FileClose;
	fp = NULL;
}
