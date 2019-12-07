//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "mmsystem.h"
#include <tchar.h>
#include <windows.h>
#include <String.h>
#include <Clipbrd.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "perfgrap"
#pragma resource "*.dfm"
TForm1 *Form1;



TClipboard *nClip = Clipboard();

bool menu_home = true;
bool menu_scan = false;
bool menu_protection = false;
bool menu_sync = false;
bool menu_quarantine = false;
bool menu_settings = false;
bool menu_about = false;

bool addr1 = false;
bool addr2 = false;
bool p2p_slider = false;
bool prot_slider = false;
bool show_exclusions = false;

bool settings_slider_exclusions_processes = false;

typedef HRESULT (__stdcall *lpfnDwmSetWindowAttribute)(HWND hWnd, DWORD dwAttribute, LPCVOID pvAttribute, DWORD cbAttribute);
typedef HRESULT (__stdcall *lpfnDwmExtendFrameIntoClientArea)(HWND hWnd, const MARGINS *pMarInset);
lpfnDwmSetWindowAttribute fDwmSetWindowAttribute = 0;
lpfnDwmExtendFrameIntoClientArea fDwmExtendFrameIntoClientArea = 0;

HRESULT DwmDropShadow(HWND hWnd)
{
	int attr = 2;
	HRESULT hr = S_OK;
	fDwmSetWindowAttribute = (lpfnDwmSetWindowAttribute)GetProcAddress(GetModuleHandle(_T("dwmapi.dll")), "DwmSetWindowAttribute");
	fDwmExtendFrameIntoClientArea = (lpfnDwmExtendFrameIntoClientArea)GetProcAddress(GetModuleHandle(_T("dwmapi.dll")), "DwmExtendFrameIntoClientArea");
	if (DwmSetWindowAttribute == 0 || DwmExtendFrameIntoClientArea == 0)
		return S_FALSE;
	hr = fDwmSetWindowAttribute(hWnd, attr, &attr, sizeof(int));
	if (SUCCEEDED(hr))
	{
		MARGINS margins = {0, 0, 1 , 0};
		hr = fDwmExtendFrameIntoClientArea(hWnd, &margins);
		return hr;
	}

	return hr;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
	Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
	Application->Minimize();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	long SC_DRAGMOVE = 0xF012;
	if(Button == mbLeft)

	{
		ReleaseCapture();
		SendMessage(Handle, WM_SYSCOMMAND, SC_DRAGMOVE, 0);
		int Transparency = 100; //transparency level (0-100%)
		long ExtStyle = GetWindowLong(Handle, GWL_EXSTYLE);
		SetWindowLong(Handle, GWL_EXSTYLE, ExtStyle | WS_EX_LAYERED);
		::SetLayeredWindowAttributes(Handle, 0 , (255 * Transparency) / 100, LWA_ALPHA);
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	//const CS_DROPSHADOW = 0x002000;
  // SetClassLong(Form1->Handle, GCL_STYLE, GetClassLong(Form1->Handle, GCL_STYLE) | CS_DROPSHADOW) ;
  // SystemParametersInfo(0x1025, true, NULL, 0);
  // RecreateWnd();

  page_tabs->Width = 769;
  page_tabs->Top = 32;
  page_tabs->Left = 232;
  page_tabs->Height = 595;

  prot_enabled = true;
  p2p_enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	SpeedButton1->Font->Color = clSilver;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1MouseLeave(TObject *Sender)
{
	SpeedButton1->Font->Color = clWhite;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2MouseLeave(TObject *Sender)
{
	 SpeedButton2->Font->Color = clWhite;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	 SpeedButton2->Font->Color = clSilver;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	SpeedButton3->Font->Color = clSilver;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3MouseLeave(TObject *Sender)
{
	SpeedButton3->Font->Color = clWhite;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_scanMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	if (menu_scan == false) panel_menu_scan->Color = 0x00342124;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_protectionMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	if (menu_protection == false) panel_menu_protection->Color = 0x00342124;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::panel_menu_syncMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
   if (menu_sync == false)	panel_menu_sync->Color = 0x00342124;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_quarantineMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
   if (menu_quarantine == false)	panel_menu_quarantine->Color = 0x00342124;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_settingsMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	if (menu_settings == false) panel_menu_settings->Color = 0x00342124;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_scanMouseLeave(TObject *Sender)
{
   if (menu_scan == false)	panel_menu_scan->Color = 0x0056363C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_protectionMouseLeave(TObject *Sender)
{
   if (menu_protection == false) panel_menu_protection->Color = 0x0056363C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_settingsMouseLeave(TObject *Sender)
{
   if (menu_settings == false) panel_menu_settings->Color = 0x0056363C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_syncMouseLeave(TObject *Sender)
{
   if (menu_sync == false)	panel_menu_sync->Color = 0x0056363C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_quarantineMouseLeave(TObject *Sender)
{
   if (menu_quarantine == false)	panel_menu_quarantine->Color = 0x0056363C;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_aboutMouseLeave(TObject *Sender)
{
  if (menu_about == false)	 panel_menu_about->Color = 0x0056363C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_aboutMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	  if (menu_about == false) panel_menu_about->Color = 0x00342124;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::panel_menu_scanMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
   if (menu_scan == false)	panel_menu_scan->Color = 0x0085545C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_scanMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
   if (menu_scan == false)	panel_menu_scan->Color = 0x003C2C1C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_protectionMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
  if (menu_protection == false)	panel_menu_protection->Color = 0x0085545C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_syncMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
  if (menu_sync == false)	panel_menu_sync->Color = 0x0085545C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_quarantineMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if (menu_quarantine == false) panel_menu_quarantine->Color = 0x0085545C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_settingsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if (menu_settings == false)	panel_menu_settings->Color = 0x0085545C;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::panel_menu_aboutMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
		if (menu_about == false)	panel_menu_about->Color = 0x0085545C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_aboutMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if (menu_about == false) panel_menu_about->Color = 0x003C2C1C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_settingsMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if (menu_settings == false)	panel_menu_settings->Color = 0x003C2C1C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_quarantineMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if (menu_quarantine == false)	panel_menu_quarantine->Color = 0x003C2C1C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_syncMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if (menu_sync == false) panel_menu_sync->Color = 0x003C2C1C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_protectionMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
   if (menu_protection == false)	panel_menu_protection->Color = 0x003C2C1C;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::panel_menu_scanClick(TObject *Sender)
{
	/*Application->CreateForm(__classid(TForm2), &Form2);
	Form2->Show();   */

	page_tabs->ActivePage = tab_scan;

	// static menu button colors
	panel_menu_home->Color = 0x0056363C;
	panel_menu_scan->Color = clWhite;
	panel_menu_protection->Color = 0x0056363C;
	panel_menu_sync->Color = 0x0056363C;
	panel_menu_quarantine->Color = 0x0056363C;
	panel_menu_settings->Color = 0x0056363C;
	panel_menu_about->Color = 0x0056363C;

	// static menu button font colors
	lbl_home->Font->Color = clWhite;
	lbl_scan->Font->Color = clBlack;
	lbl_prot->Font->Color = clWhite;
	lbl_sync->Font->Color = clWhite;
	lbl_quar->Font->Color = clWhite;
	lbl_sett->Font->Color = clWhite;
	lbl_about->Font->Color = clWhite;

	// static menu button images
	img_home->Picture = img_home_white->Picture;
	img_scan->Picture = img_scan_black->Picture;
	img_prot->Picture = img_prot_white->Picture;
	img_sync->Picture = img_sync_white->Picture;
	img_quar->Picture = img_quar_white->Picture;
	img_sett->Picture = img_sett_white->Picture;
	img_about->Picture = img_about_white->Picture;

	// global panel & button state switch
	menu_home = false;
	menu_scan = true;
	menu_protection = false;
	menu_sync = false;
	menu_quarantine = false;
	menu_settings = false;
	menu_about = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::OpenProgress1Click(TObject *Sender)
{
	Form1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Exit1Click(TObject *Sender)
{
	ExitProcess(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	/*CanClose=false;
	Form1->Hide(); */
	ExitProcess(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrayIcon1DblClick(TObject *Sender)
{
	Form1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TrayIcon1Click(TObject *Sender)
{
	Form1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ApplicationEvents1Deactivate(TObject *Sender)
{
	Form1->Panel1->Color = 0x004E3137;
	Form1->Shape1->Brush->Color = 0x004E3137;

	int Transparency = 80; //transparency level (0-100%)
	long ExtStyle = GetWindowLong(Handle, GWL_EXSTYLE);
	SetWindowLong(Handle, GWL_EXSTYLE, ExtStyle | WS_EX_LAYERED);
	::SetLayeredWindowAttributes(Handle, 0 , (255 * Transparency) / 100, LWA_ALPHA);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ApplicationEvents1Activate(TObject *Sender)
{
	Form1->Panel1->Color = 0x004E3137;
	Form1->Shape1->Brush->Color = 0x004E3137;

	int Transparency = 100; //transparency level (0-100%)
	long ExtStyle = GetWindowLong(Handle, GWL_EXSTYLE);
	SetWindowLong(Handle, GWL_EXSTYLE, ExtStyle | WS_EX_LAYERED);
	::SetLayeredWindowAttributes(Handle, 0 , (255 * Transparency) / 100, LWA_ALPHA);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ApplicationEvents1Minimize(TObject *Sender)
{
   TrayIcon1->Visible = true;
	Application->Minimize();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ApplicationEvents1Restore(TObject *Sender)
{
   TrayIcon1->Visible = false;
    Application->Restore();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_homeClick(TObject *Sender)
{
	page_tabs->ActivePage = tab_home;


	// static menu button colors
	panel_menu_home->Color = clWhite;
	panel_menu_scan->Color = 0x0056363C;
	panel_menu_protection->Color = 0x0056363C;
	panel_menu_sync->Color = 0x0056363C;
	panel_menu_quarantine->Color = 0x0056363C;
	panel_menu_settings->Color = 0x0056363C;
	panel_menu_about->Color = 0x0056363C;

	// static menu button font colors
	lbl_home->Font->Color = clBlack;
	lbl_scan->Font->Color = clWhite;
	lbl_prot->Font->Color = clWhite;
	lbl_sync->Font->Color = clWhite;
	lbl_quar->Font->Color = clWhite;
	lbl_sett->Font->Color = clWhite;
	lbl_about->Font->Color = clWhite;

	// static menu button images
	img_home->Picture = img_home_black->Picture;
	img_scan->Picture = img_scan_white->Picture;
	img_prot->Picture = img_prot_white->Picture;
	img_sync->Picture = img_sync_white->Picture;
	img_quar->Picture = img_quar_white->Picture;
	img_sett->Picture = img_sett_white->Picture;
	img_about->Picture = img_about_white->Picture;

	// global panel & button state switch
	menu_home = true;
	menu_scan = false;
	menu_protection = false;
	menu_sync = false;
	menu_quarantine = false;
	menu_settings = false;
	menu_about = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_homeMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	if (menu_home == false) panel_menu_home->Color = 0x00342124;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_homeMouseLeave(TObject *Sender)
{
  if (menu_home == false) 	panel_menu_home->Color = 0x0056363C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_homeMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	if (menu_home == false) panel_menu_home->Color = 0x003C2C1C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_homeMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
   if (menu_home == false) 	panel_menu_home->Color = 0x0085545C;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_protectionClick(TObject *Sender)
{
	// panel switcher
	page_tabs->ActivePage = tab_wallet;

	// static menu button colors
	panel_menu_home->Color = 0x0056363C;
	panel_menu_scan->Color = 0x0056363C;
	panel_menu_protection->Color = clWhite;
	panel_menu_sync->Color = 0x0056363C;
	panel_menu_quarantine->Color = 0x0056363C;
	panel_menu_settings->Color = 0x0056363C;
	panel_menu_about->Color = 0x0056363C;

	// static menu button font colors
	lbl_home->Font->Color = clWhite;
	lbl_scan->Font->Color = clWhite;
	lbl_prot->Font->Color = clBlack;
	lbl_sync->Font->Color = clWhite;
	lbl_quar->Font->Color = clWhite;
	lbl_sett->Font->Color = clWhite;
	lbl_about->Font->Color = clWhite;

	// static menu button images
	img_home->Picture = img_home_white->Picture;
	img_scan->Picture = img_scan_white->Picture;
	img_prot->Picture = img_prot_black->Picture;
	img_sync->Picture = img_sync_white->Picture;
	img_quar->Picture = img_quar_white->Picture;
	img_sett->Picture = img_sett_white->Picture;
	img_about->Picture = img_about_white->Picture;

	// global panel & button state switch
	menu_home = false;
	menu_scan = false;
	menu_protection = true;
	menu_sync = false;
	menu_quarantine = false;
	menu_settings = false;
	menu_about = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_syncClick(TObject *Sender)
{
	// panel switcher
	page_tabs->ActivePage = tab_sync;

	panel_menu_home->Color = 0x0056363C;
	panel_menu_scan->Color = 0x0056363C;
	panel_menu_protection->Color = 0x0056363C;
	panel_menu_sync->Color = clWhite;
	panel_menu_quarantine->Color = 0x0056363C;
	panel_menu_settings->Color = 0x0056363C;
	panel_menu_about->Color = 0x0056363C;

	lbl_home->Font->Color = clWhite;
	lbl_scan->Font->Color = clWhite;
	lbl_prot->Font->Color = clWhite;
	lbl_sync->Font->Color = clBlack;
	lbl_quar->Font->Color = clWhite;
	lbl_sett->Font->Color = clWhite;
	lbl_about->Font->Color = clWhite;

	img_home->Picture = img_home_white->Picture;
	img_scan->Picture = img_scan_white->Picture;
	img_prot->Picture = img_prot_white->Picture;
	img_sync->Picture = img_sync_black->Picture;
	img_quar->Picture = img_quar_white->Picture;
	img_sett->Picture = img_sett_white->Picture;
	img_about->Picture = img_about_white->Picture;

	menu_home = false;
	menu_scan = false;
	menu_protection = false;
	menu_sync = true;
	menu_quarantine = false;
	menu_settings = false;
	menu_about = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_quarantineClick(TObject *Sender)
{
	// panel switcher
	page_tabs->ActivePage = tab_quar;

	panel_menu_home->Color = 0x0056363C;
	panel_menu_scan->Color = 0x0056363C;
	panel_menu_protection->Color = 0x0056363C;
	panel_menu_sync->Color = 0x0056363C;
	panel_menu_quarantine->Color = clWhite;
	panel_menu_settings->Color = 0x0056363C;
	panel_menu_about->Color = 0x0056363C;

	lbl_home->Font->Color = clWhite;
	lbl_scan->Font->Color = clWhite;
	lbl_prot->Font->Color = clWhite;
	lbl_sync->Font->Color = clWhite;
	lbl_quar->Font->Color = clBlack;
	lbl_sett->Font->Color = clWhite;
	lbl_about->Font->Color = clWhite;

	img_home->Picture = img_home_white->Picture;
	img_scan->Picture = img_scan_white->Picture;
	img_prot->Picture = img_prot_white->Picture;
	img_sync->Picture = img_sync_white->Picture;
	img_quar->Picture = img_quar_black->Picture;
	img_sett->Picture = img_sett_white->Picture;
	img_about->Picture = img_about_white->Picture;

	menu_home = false;
	menu_scan = false;
	menu_protection = false;
	menu_sync = false;
	menu_quarantine = true;
	menu_settings = false;
	menu_about = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_settingsClick(TObject *Sender)
{
	// panel switcher
	page_tabs->ActivePage = tab_sett;

	// static menu button colors
	panel_menu_home->Color = 0x0056363C;
	panel_menu_scan->Color = 0x0056363C;
	panel_menu_protection->Color = 0x0056363C;
	panel_menu_sync->Color = 0x0056363C;
	panel_menu_quarantine->Color = 0x0056363C;
	panel_menu_settings->Color = clWhite;
	panel_menu_about->Color = 0x0056363C;

	lbl_home->Font->Color = clWhite;
	lbl_scan->Font->Color = clWhite;
	lbl_prot->Font->Color = clWhite;
	lbl_sync->Font->Color = clWhite;
	lbl_quar->Font->Color = clWhite;
	lbl_sett->Font->Color = clBlack;
	lbl_about->Font->Color = clWhite;

	img_home->Picture = img_home_white->Picture;
	img_scan->Picture = img_scan_white->Picture;
	img_prot->Picture = img_prot_white->Picture;
	img_sync->Picture = img_sync_white->Picture;
	img_quar->Picture = img_quar_white->Picture;
	img_sett->Picture = img_sett_black->Picture;
	img_about->Picture = img_about_white->Picture;

	menu_home = false;
	menu_scan = false;
	menu_protection = false;
	menu_sync = false;
	menu_quarantine = false;
	menu_settings = true;
	menu_about = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::panel_menu_aboutClick(TObject *Sender)
{
	// panel switcher
	page_tabs->ActivePage = tab_about;

	// static menu button colors
	panel_menu_home->Color = 0x0056363C;
	panel_menu_scan->Color = 0x0056363C;
	panel_menu_protection->Color = 0x0056363C;
	panel_menu_sync->Color = 0x0056363C;
	panel_menu_quarantine->Color = 0x0056363C;
	panel_menu_settings->Color = 0x0056363C;
	panel_menu_about->Color = clWhite;

	lbl_home->Font->Color = clWhite;
	lbl_scan->Font->Color = clWhite;
	lbl_prot->Font->Color = clWhite;
	lbl_sync->Font->Color = clWhite;
	lbl_quar->Font->Color = clWhite;
	lbl_sett->Font->Color = clWhite;
	lbl_about->Font->Color = clBlack;

	img_home->Picture = img_home_white->Picture;
	img_scan->Picture = img_scan_white->Picture;
	img_prot->Picture = img_prot_white->Picture;
	img_sync->Picture = img_sync_white->Picture;
	img_quar->Picture = img_quar_white->Picture;
	img_sett->Picture = img_sett_white->Picture;
	img_about->Picture = img_about_black->Picture;

	menu_home = false;
	menu_scan = false;
	menu_protection = false;
	menu_sync = false;
	menu_quarantine = false;
	menu_settings = false;
	menu_about = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label13Click(TObject *Sender)
{
	ShellExecuteA(0, "open", "https://progression.network", NULL, NULL, SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

int counter = 0;
int sec = 0;
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{

	int a;
	randomize();
	a=random(100);
	ProgressBar1->Position = a;
	ProgressBar1->StepIt();

	counter++;
	lbl_checked_obj->Caption = IntToStr(counter);

	sec = counter;
	if ((sec / 60) != 0)
	{
	 lbl_sec_counter->Caption = IntToStr(0);
   //	 lbl_min_elapsed->Caption = IntToStr(StrToInt(lbl_min_elapsed->Caption) + 1);
	 sec = 0;
	}
	else
	{
	 lbl_sec_counter->Caption = IntToStr(sec);
	}

	if ((sec == 60))
	{
	   sec = 0;
	}

	if ((counter == 55) && panel_scan->Visible == true)
	{
	   SpeedButton3->Click();
	}

	Memo1->Lines->Add("C:\\Windows\\system32\\"+IntToStr(counter)+".exe - Clean");

	//---------------------------------------------------------------------------
	// Sync animation inline
	//---------------------------------------------------------------------------
	if (a < 5) {
	   anim3->Visible = true;
	   anim10->Visible = false;
	   anim11->Visible = true;
	   anim12->Visible = false;
	   anim13->Visible = false;
	   anim14->Visible = true;
	   anim15->Visible = true;
	   anim16->Visible = false;
	   anim17->Visible = false;
	   anim18->Visible = false;
	   anim19->Visible = false;
	   anim3->Visible = false;
	   anim9->Visible = false;
	}
	if (a > 5 && a < 10) {
	   anim3->Visible = false;
	   anim10->Visible = true;
	   anim11->Visible = false;
	   anim12->Visible = false;
	   anim13->Visible = true;
	   anim14->Visible = false;
	   anim15->Visible = false;
	   anim16->Visible = false;
	   anim17->Visible = true;
	   anim18->Visible = false;
	   anim19->Visible = false;
	   anim3->Visible = false;
	   anim9->Visible = false;
	}
	if (a > 10 && a < 20) {
	   anim3->Visible = false;
	   anim10->Visible = false;
	   anim11->Visible = false;
	   anim12->Visible = false;
	   anim13->Visible = false;
	   anim14->Visible = true;
	   anim15->Visible = true;
	   anim16->Visible = true;
	   anim17->Visible = false;
	   anim18->Visible = true;
	   anim19->Visible = false;
	   anim3->Visible = false;
	   anim9->Visible = false;
	}
	if (a > 20 && a < 30) {
	   anim3->Visible = false;
	   anim10->Visible = false;
	   anim11->Visible = false;
	   anim12->Visible = false;
	   anim13->Visible = false;
	   anim14->Visible = false;
	   anim15->Visible = false;
	   anim16->Visible = true;
	   anim17->Visible = true;
	   anim18->Visible = true;
	   anim19->Visible = false;
	   anim3->Visible = false;
	   anim9->Visible = false;
	}
	if (a > 30 && a < 40) {
	   anim3->Visible = false;
	   anim10->Visible = false;
	   anim11->Visible = false;
	   anim12->Visible = true;
	   anim13->Visible = true;
	   anim14->Visible = false;
	   anim15->Visible = false;
	   anim16->Visible = false;
	   anim17->Visible = true;
	   anim18->Visible = false;
	   anim19->Visible = true;
	   anim3->Visible = false;
	   anim9->Visible = true;
	}
	if (a > 40 && a < 50) {
	   anim3->Visible = false;
	   anim10->Visible = false;
	   anim11->Visible = true;
	   anim12->Visible = false;
	   anim13->Visible = false;
	   anim14->Visible = true;
	   anim15->Visible = true;
	   anim16->Visible = false;
	   anim17->Visible = false;
	   anim18->Visible = false;
	   anim19->Visible = false;
	   anim3->Visible = true;
	   anim9->Visible = true;
	}
	if (a > 50 && a < 60) {
	   anim3->Visible = false;
	   anim10->Visible = true;
	   anim11->Visible = true;
	   anim12->Visible = true;
	   anim13->Visible = false;
	   anim14->Visible = false;
	   anim15->Visible = false;
	   anim16->Visible = false;
	   anim17->Visible = false;
	   anim18->Visible = false;
	   anim19->Visible = true;
	   anim3->Visible = true;
	   anim9->Visible = false;
	}
	if (a > 60 && a < 70) {
	   anim3->Visible = false;
	   anim10->Visible = false;
	   anim11->Visible = false;
	   anim12->Visible = false;
	   anim13->Visible = false;
	   anim14->Visible = true;
	   anim15->Visible = true;
	   anim16->Visible = true;
	   anim17->Visible = true;
	   anim18->Visible = false;
	   anim19->Visible = true;
	   anim3->Visible = false;
	   anim9->Visible = false;
	}
	if (a > 70 && a < 80) {
	   anim3->Visible = false;
	   anim10->Visible = true;
	   anim11->Visible = false;
	   anim12->Visible = false;
	   anim13->Visible = true;
	   anim14->Visible = true;
	   anim15->Visible = true;
	   anim16->Visible = false;
	   anim17->Visible = false;
	   anim18->Visible = false;
	   anim19->Visible = false;
	   anim3->Visible = false;
	   anim9->Visible = false;
	}
	if (a > 80 && a < 90) {
	   anim3->Visible = false;
	   anim10->Visible = true;
	   anim11->Visible = true;
	   anim12->Visible = false;
	   anim13->Visible = false;
	   anim14->Visible = true;
	   anim15->Visible = true;
	   anim16->Visible = false;
	   anim17->Visible = false;
	   anim18->Visible = true;
	   anim19->Visible = false;
	   anim3->Visible = false;
	   anim9->Visible = true;
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::btn_stopClick(TObject *Sender)
{
	Timer1->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormPaint(TObject *Sender)
{
	DwmDropShadow(Form1->Handle);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
	nClip->SetTextBuf(lbl_addr1->Caption.c_str());

	ShowMessage("Your wallet ID was copied to the clipboard.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Copytransaction1Click(TObject *Sender)
{
	String transactionID = "";

	if(ListView1->Selected != NULL) {
		transactionID = ListView1->Items->Item[ListView1->ItemIndex]->SubItems->Strings[0];
		nClip->SetTextBuf(transactionID.c_str());
		ShowMessage("Selected transaction ID is copied: " + transactionID);
	}

	if(ListView2->Selected != NULL) {
		transactionID = ListView2->Items->Item[ListView2->ItemIndex]->SubItems->Strings[0];
		nClip->SetTextBuf(transactionID.c_str());
		ShowMessage("Selected transaction ID is copied: " + transactionID);
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit7Click(TObject *Sender)
{
		Edit7->Font->Color = clBlack;
		Edit7->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	Edit3->Color = 0x00FFFEF9;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3MouseLeave(TObject *Sender)
{
	Edit3->Color = clWhite;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4MouseLeave(TObject *Sender)
{
	Edit4->Color = clWhite;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	Edit4->Color = 0x00FFFEF9;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit7MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	Edit7->Color = 0x00FFFEF9;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit7MouseLeave(TObject *Sender)
{
	Edit7->Color = clWhite;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2MouseLeave(TObject *Sender)
{
	Edit2->Color = clWhite;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	Edit2->Color = 0x00FFFEF9;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Click(TObject *Sender)
{
	Edit1->Font->Color = clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	Edit1->Color = 0x00FFFEF9;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1MouseLeave(TObject *Sender)
{
	Edit1->Color = clWhite;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Copyaddress1Click(TObject *Sender)
{

	if (addr1 == true) {
		nClip->SetTextBuf(lbl_addr1->Caption.c_str());
	}

	if (addr2 == true) {
		nClip->SetTextBuf(lbl_addr2->Caption.c_str());
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::lbl_addr1ContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled)

{
	addr1 = true;
	addr2 = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lbl_addr2ContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled)

{
	addr1 = false;
	addr2 = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	nClip->SetTextBuf(lbl_addr2->Caption.c_str());

	ShowMessage("Your wallet ID was copied to the clipboard.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	nClip->SetTextBuf(Edit2->Text.c_str());

	ShowMessage("Your wallet ID was copied to the clipboard.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListView1ColumnRightClick(TObject *Sender, TListColumn *Column,
          TPoint &Point)
{
	//nClip->SetTextBuf(ListView1->ItemFocused->Caption.c_str());

	ShowMessage( "Selected transaction ID is copied.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListView2ColumnRightClick(TObject *Sender, TListColumn *Column,
          TPoint &Point)
{
	//nClip->SetTextBuf(ListView2->ItemFocused->Caption.c_str());

	ShowMessage( "Selected transaction ID is copied.");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PageControl1Enter(TObject *Sender)
{
	ListView1->Items->Add();
	ListView1->Items->Item[1]->Caption = "21.01.18 at 23:14:00";
	ListView1->Items->Item[1]->SubItems->Add("000000000000000000307bd3c2722ec364d8b19043ef9dc22df55f7459d21b00");
	ListView1->Items->Item[1]->SubItems->Add("200 PRU");
	ListView1->Items->Item[1]->SubItems->Add("24823 PRU");

	ListView2->Items->Add();
	ListView2->Items->Item[1]->Caption = "20.02.18 at 21:04:01";
	ListView2->Items->Item[1]->SubItems->Add("000000000000000000307bd3c2722ec364d8b19043ef9dc22df55f7459d21b00");
	ListView2->Items->Item[1]->SubItems->Add("-200 PRU");
	ListView2->Items->Item[1]->SubItems->Add("24623 PRU");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label64MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	Label64->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label64MouseLeave(TObject *Sender)
{
	Label64->Font->Style = TFontStyles();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label64Click(TObject *Sender)
{
	ShellExecuteA(0, "open", "https://progression.network", NULL, NULL, SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit3Change(TObject *Sender)
{
		Edit3->Font->Color = clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4Change(TObject *Sender)
{
		Edit4->Font->Color = clBlack;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormShow(TObject *Sender)
{
	for (int i(0); i < page_tabs->PageCount; ++i)
		page_tabs->Pages[i]->TabVisible = false;

    page_tabs->ActivePage = tab_home;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::FormMoveX(TMessage &msg)
{
      int Transparency = 80; //transparency level (0-100%)
	  long ExtStyle = GetWindowLong(Handle, GWL_EXSTYLE);
	  SetWindowLong(Handle, GWL_EXSTYLE, ExtStyle | WS_EX_LAYERED);
	  ::SetLayeredWindowAttributes(Handle, 0 , (255 * Transparency) / 100, LWA_ALPHA);
}


void __fastcall TForm1::FormDragOver(TObject *Sender, TObject *Source, int X, int Y,
          TDragState State, bool &Accept)
{
			int Transparency = 80; //transparency level (0-100%)

}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled)
{
   //	page_tabs->SelectNextPage(true, false);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled)
{
   //	page_tabs->SelectNextPage(false, false);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{

	Form1->shape_status->Brush->Color = 0x004444FF;
	Form1->label_status->Caption = "Alert! Risk activity was detected";
	Form1->label_threat->Caption = "1 active threat was found";
	Form1->image_threat_status->Picture = Form1->img_secure_red->Picture;
	Form1->img_ok_not_ok->Picture = Form1->img_not_ok->Picture;

	Form3->Show();

	int i = 0;

	Form3->Left = Screen->Width - Form3->Width - 8;

	for (i = 0; i < 307; i++) {
		i=i+2;
		Form3->Top = Screen->Height - i;

		Form3->UpdateControlState();
		Form3->Update();
		Form1->UpdateControlState();
		Form1->Update();

		Sleep(1);
	}

   //	Form3->Top = Screen->Height - Form3->Height - 50;

	/*
	AnsiString strMessage = L"Progress Antivirus MVP";
	AnsiString strCountry = L"https://progression.network";
	AnsiString strCity    = L" ";
	AnsiString strFinal   = L"Have a nice trip.";

	ShowMessage(strMessage + sLineBreak + strCountry + sLineBreak +
			strCity + sLineBreak + strFinal);
	*/

}
//---------------------------------------------------------------------------

void __fastcall TForm1::OpeninProgressExplorer1Click(TObject *Sender)
{
	AnsiString transactionID = "";

	if(ListView1->Selected != NULL) {
		transactionID = "https://progression.network/tx=" + ListView1->Items->Item[ListView1->ItemIndex]->SubItems->Strings[0];
		LPCSTR lpUrl = transactionID.c_str();
		ShellExecuteA(0, "open", lpUrl, NULL, NULL, SW_SHOWDEFAULT);
	}

	if(ListView2->Selected != NULL) {
		transactionID = "https://progression.network/tx=" + ListView2->Items->Item[ListView2->ItemIndex]->SubItems->Strings[0];
		LPCSTR lpUrl = transactionID.c_str();
		ShellExecuteA(0, "open", lpUrl, NULL, NULL, SW_SHOWDEFAULT);
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Details1Click(TObject *Sender)
{
	AnsiString transactionURL = "";
	AnsiString transactionID = "";
	AnsiString date_time = "";
	AnsiString amount = "";
	AnsiString balance = "";
	int a;

	randomize();
	a=random(100);

	if(ListView1->Selected != NULL) {
		transactionID = ListView1->Items->Item[ListView1->ItemIndex]->SubItems->Strings[0];
		date_time     = ListView1->Items->Item[ListView1->ItemIndex]->Caption;
		amount        = ListView1->Items->Item[ListView1->ItemIndex]->SubItems->Strings[1];
		balance       = ListView1->Items->Item[ListView1->ItemIndex]->SubItems->Strings[2];
		transactionURL = "https://progression.network/tx=" + ListView1->Items->Item[ListView1->ItemIndex]->SubItems->Strings[0];
	}

	if(ListView2->Selected != NULL) {
		transactionID = ListView2->Items->Item[ListView2->ItemIndex]->SubItems->Strings[0];
		date_time     = ListView2->Items->Item[ListView2->ItemIndex]->Caption;
		amount        = ListView2->Items->Item[ListView2->ItemIndex]->SubItems->Strings[1];
		balance       = ListView2->Items->Item[ListView2->ItemIndex]->SubItems->Strings[2];
		transactionURL = "https://progression.network/tx=" + ListView2->Items->Item[ListView2->ItemIndex]->SubItems->Strings[0];
	}

	Form_Details->RichEdit1->Clear();

	Form_Details->RichEdit1->SelAttributes->Style = Form_Details->RichEdit1->SelAttributes->Style << fsBold;
	Form_Details->RichEdit1->SelText = "Date: ";
	Form_Details->RichEdit1->SelAttributes->Style = TFontStyles();
	Form_Details->RichEdit1->SelText = date_time;
	Form_Details->RichEdit1->Lines->Add("");

	Form_Details->RichEdit1->SelAttributes->Style = Form_Details->RichEdit1->SelAttributes->Style << fsBold;
	Form_Details->RichEdit1->SelText = "Confirmations: ";
	Form_Details->RichEdit1->SelAttributes->Style = TFontStyles();
	Form_Details->RichEdit1->SelText = IntToStr(a);
	Form_Details->RichEdit1->Lines->Add("");

	Form_Details->RichEdit1->SelAttributes->Style = Form_Details->RichEdit1->SelAttributes->Style << fsBold;
	Form_Details->RichEdit1->SelText = "To: ";
	Form_Details->RichEdit1->SelAttributes->Style = TFontStyles();
	Form_Details->RichEdit1->SelText = "PKiJMnNHRAU7trtph3DVjCAqaf3RE28P84";
	Form_Details->RichEdit1->Lines->Add("");

	Form_Details->RichEdit1->SelAttributes->Style = Form_Details->RichEdit1->SelAttributes->Style << fsBold;
	Form_Details->RichEdit1->SelText = "Amount: ";
	Form_Details->RichEdit1->SelAttributes->Style = TFontStyles();
	Form_Details->RichEdit1->SelText = amount;
	Form_Details->RichEdit1->Lines->Add("");

	Form_Details->RichEdit1->SelAttributes->Style = Form_Details->RichEdit1->SelAttributes->Style << fsBold;
	Form_Details->RichEdit1->SelText = "Fee: ";
	Form_Details->RichEdit1->SelAttributes->Style = TFontStyles();
	Form_Details->RichEdit1->SelText = "0.0"+IntToStr(a)+" PRU";
	Form_Details->RichEdit1->Lines->Add("");

	Form_Details->RichEdit1->SelAttributes->Style = Form_Details->RichEdit1->SelAttributes->Style << fsBold;
	Form_Details->RichEdit1->SelText = "Balance: ";
	Form_Details->RichEdit1->SelAttributes->Style = TFontStyles();
	Form_Details->RichEdit1->SelText = balance;
	Form_Details->RichEdit1->Lines->Add("");

	Form_Details->RichEdit1->SelAttributes->Style = Form_Details->RichEdit1->SelAttributes->Style << fsBold;
	Form_Details->RichEdit1->SelText = "Transaction ID: ";
	Form_Details->RichEdit1->SelAttributes->Style = TFontStyles();
	Form_Details->RichEdit1->SelText = transactionID;
	Form_Details->RichEdit1->Lines->Add("");

	Form_Details->RichEdit1->SelAttributes->Style = Form_Details->RichEdit1->SelAttributes->Style << fsBold;
	Form_Details->RichEdit1->SelText = "Explorer link: ";
	Form_Details->RichEdit1->SelAttributes->Style = TFontStyles();
	Form_Details->RichEdit1->SelAttributes->Color = clBlue;
	Form_Details->RichEdit1->SelText = transactionURL;
	Form_Details->RichEdit1->Lines->Add("");

	Form_Details->RichEdit1->SelAttributes = Form_Details->RichEdit1->DefAttributes;

	Form_Details->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::lbl_exclusionsMouseActivate(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y, int HitTest, TMouseActivate &MouseActivate)

{
	show_exclusions = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lbl_call_exclude_processes_listMouseLeave(TObject *Sender)
{
	  lbl_call_exclude_processes_list->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lbl_call_exclude_processes_listMouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	  lbl_call_exclude_processes_list->Font->Style = TFontStyles();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall TForm1::ApplicationEvents1Message(tagMSG &Msg, bool &Handled)
{
	if(Msg.message == WM_NCLBUTTONDOWN && Msg.wParam == 8)
	{
	Application->Minimize();
	Handled = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lbl_reportsClick(TObject *Sender)
{
	tab_reports->PageControl->ActivePage = tab_reports;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_p2p_sliderClick(TObject *Sender)
{
	p2p_slider = true;
	prot_slider = false;

	POINT cur_pos;
	GetCursorPos(&cur_pos);
	popup_enable_disable->Popup(cur_pos.x,cur_pos.y);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::btn_prot_sliderClick(TObject *Sender)
{
	prot_slider = true;
	p2p_slider = false;

	POINT cur_pos;
	GetCursorPos(&cur_pos);
	popup_enable_disable->Popup(cur_pos.x,cur_pos.y);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lbl_reportsMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	lbl_reports->Font->Color = clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lbl_reportsMouseLeave(TObject *Sender)
{
	lbl_reports->Font->Color = clWhite;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lbl_exclusionsMouseLeave(TObject *Sender)
{
	 lbl_exclusions->Font->Color = clWhite;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lbl_exclusionsMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y)
{
	 lbl_exclusions->Font->Color = clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lbl_home2MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
		lbl_home2->Font->Color = 0x00805600;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lbl_home2MouseLeave(TObject *Sender)
{
		lbl_home2->Font->Color = clBlack;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Enable1Click(TObject *Sender)
{
	if (p2p_slider == true) {
		lbl_p2p_enable_disable->Caption = "Enabled";
		lbl_p2p_enable_disable->Font->Color = 0x005EC472;
		btn_p2p_slider->Left = 162;
		btn_p2p_slider->Font->Color = 0x005EC472;
		p2p_enabled = true;
	}
	if (prot_slider == true) {
		lbl_prot_enable_disable->Caption = "Enabled";
		lbl_prot_enable_disable->Font->Color = 0x005EC472;
		btn_prot_slider->Left = 154;
		btn_prot_slider->Font->Color = 0x005EC472;
		prot_enabled = true;
	}

	if (prot_enabled == true && p2p_enabled == true) {
		Form1->shape_status->Brush->Color = 0x005EC472;
		Form1->label_status->Caption = "Your PC is protected and secured";
		Form1->img_ok_not_ok->Picture = Form1->img_ok->Picture;
		PlaySound(L"C:\\WINDOWS\\Media\\Windows Message Nudge.wav",NULL,SND_ASYNC) ;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Disable1Click(TObject *Sender)
{
	if (p2p_slider == true) {
		lbl_p2p_enable_disable->Caption = "Disabled";
		lbl_p2p_enable_disable->Font->Color = 0x004444FF;
		btn_p2p_slider->Left = 168;
		btn_p2p_slider->Font->Color = 0x004444FF;
		p2p_enabled = false;
	}
	if (prot_slider == true) {
		lbl_prot_enable_disable->Caption = "Disabled";
		lbl_prot_enable_disable->Font->Color = 0x004444FF;
		btn_prot_slider->Left = 160;
		btn_prot_slider->Font->Color = 0x004444FF;
		prot_enabled = false;
	}

	if (prot_enabled == false || p2p_enabled == false) {
		Form1->shape_status->Brush->Color = 0x0000D0FD;
		Form1->label_status->Caption = "Some functions was disabled";
		Form1->img_ok_not_ok->Picture = Form1->img_warn->Picture;
		PlaySound(L"C:\\WINDOWS\\Media\\Windows Default.wav",NULL,SND_ASYNC) ;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::lbl_exclusionsClick(TObject *Sender)
{
		tab_reports->PageControl->ActivePage = tab_exclusions;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label3MouseLeave(TObject *Sender)
{
	   Label3->Font->Color = clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label3MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	   Label3->Font->Color = 0x00805600;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::list_reportClick(TObject *Sender)
{
	String Object = "";
	String ObjectPath = "";
	String Event = "";
	String Action = "";
	String Date = "";
	String AccessedBy = "";

	if(list_report->Selected != NULL) {
		Object = list_report->Items->Item[list_report->ItemIndex]->Caption;
		ObjectPath = list_report->Items->Item[list_report->ItemIndex]->SubItems->Strings[2];
		Object = Object + " ("+ObjectPath+")";
		Event = "Malicious file detected";
		Action = list_report->Items->Item[list_report->ItemIndex]->SubItems->Strings[1];
		Date = list_report->Items->Item[list_report->ItemIndex]->SubItems->Strings[0];
		AccessedBy = list_report->Items->Item[list_report->ItemIndex]->SubItems->Strings[3];

		lbl_obj->Caption = Object;
		lbl_accessedby->Caption = AccessedBy;
		lbl_event->Caption = Event;
		lbl_event->Font->Color = clRed;
		lbl_action->Caption = Action;
		lbl_date->Caption = Date;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label8MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	   Label8->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label8MouseLeave(TObject *Sender)
{
	   Label8->Font->Style = TFontStyles();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label12MouseLeave(TObject *Sender)
{
	   Label12->Font->Style = TFontStyles();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label12MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	   Label12->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------





