//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <windows.h>
//---------------------------------------------------------------------------
USEFORM("Unit2.cpp", Form2);
USEFORM("Unit3.cpp", Form3);
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit4.cpp", Form_Details);
//---------------------------------------------------------------------------
#define APPLICATION_INSTANCE_MUTEX_NAME "{DA49C4EE-B1FA-4359-A07C-51BD5B5F71AE}"

int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{

	//Make sure at most one instance of the tool is running

	HANDLE hMutexOneInstance(::CreateMutexA( NULL, TRUE, APPLICATION_INSTANCE_MUTEX_NAME));
	bool bAlreadyRunning((::GetLastError() == ERROR_ALREADY_EXISTS));
	if (hMutexOneInstance == NULL || bAlreadyRunning)
	{
		if(hMutexOneInstance)
		{
			::ReleaseMutex(hMutexOneInstance);
			::CloseHandle(hMutexOneInstance);
		}
		ExitProcess(0);
	}

	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->CreateForm(__classid(TForm3), &Form3);
		Application->CreateForm(__classid(TForm_Details), &Form_Details);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
