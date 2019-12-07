//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"
#include "Unit3.h"
#include "Unit1.h"
#include "booldefines.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;

bool remove_malware = false;
bool block_malware = false;
bool ignore_malware = false;

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::SpeedButton1Click(TObject *Sender)
{
	int i = 0;

	PlaySound(L"C:\\WINDOWS\\Media\\Windows Battery Critical.wav",NULL,SND_ASYNC) ;

	if (remove_malware == false && block_malware == false && ignore_malware == false) {
		Application->MessageBox(L"Please select how to handle this risk", L"Potential high risk detected", MB_ICONWARNING);
	} else {

		Form3->Left = Screen->Width - Form3->Width - 8;

		for (i = 0; i < 300; i++) {
			i=i+2;

			Form3->Top = Screen->Height - Form3->Height + i;

			Form3->UpdateControlState();
			Form3->Update();
			Sleep(1);
		}

		Form3->Close();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm3::btn_blockMouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	btn_block->Color = 0x004d8c3e;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::btn_blockMouseLeave(TObject *Sender)
{
	btn_block->Color = 0x005EC472;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::btn_ignoreMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	btn_ignore->Color = 0x00000095;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::btn_ignoreMouseLeave(TObject *Sender)
{
	btn_ignore->Color = clRed;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::btn_removeMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	btn_remove->Color = 0x005B3940;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::btn_removeMouseLeave(TObject *Sender)
{
	btn_remove->Color = 0x00A8737C;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::btn_blockMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	btn_block->Color = 0x0096D8A3;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::btn_blockMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	btn_block->Color = 0x005EC472;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::btn_ignoreMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	btn_ignore->Color = 0x004444FF;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::btn_ignoreMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	btn_ignore->Color = 0x007171FF;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::btn_removeMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	btn_remove->Color = 0x00C2A0A7;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::btn_removeMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	btn_remove->Color = 0x007D4F58;
}

void __fastcall TForm3::Shape_headerMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
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
void __fastcall TForm3::FormPaint(TObject *Sender)
{
	DwmDropShadow(Form3->Handle);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::btn_blockClick(TObject *Sender)
{
	Form3->Cursor = crHourGlass;
	Sleep(1500);
	Form3->Cursor = crArrow;

	PlaySound(L"C:\\WINDOWS\\Media\\Windows Message Nudge.wav",NULL,SND_ASYNC) ;

	Shape_header->Brush->Color = 0x005EC472;
	label_warning->Caption = "Threat successfully blocked";
	label_status->Caption = "Your device is protected";
	lbl_final_action->Caption = "Thread successfully blocked";

	if (Form1->prot_enabled == true && Form1->p2p_enabled == true) {
		Form1->shape_status->Brush->Color = 0x005EC472;
		Form1->label_status->Caption = "Your PC is protected and secured";
		Form1->label_threat->Caption = "No active threats found";
		Form1->image_threat_status->Picture = Form1->img_secure_green->Picture;
		Form1->img_ok_not_ok->Picture = Form1->img_ok->Picture;
	}  else {
		Form1->shape_status->Brush->Color = 0x0000D0FD;
		Form1->label_status->Caption = "Some functions was disabled";
		Form1->label_threat->Caption = "No active threats found";
		Form1->image_threat_status->Picture = Form1->img_secure_green->Picture;
		Form1->img_ok_not_ok->Picture = Form1->img_warn->Picture;
	}

	block_malware = true;

	Form3->UpdateControlState();
	Form3->Update();
	Form1->UpdateControlState();
	Form1->Update();

	SpeedButton1->Click();

	Form1->panel_menu_homeClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::btn_ignoreClick(TObject *Sender)
{
	PlaySound(L"C:\\WINDOWS\\Media\\Windows Battery Critical.wav",NULL,SND_ASYNC) ;

	int Key= Application->MessageBox(L"Are you sure you want to ignore this risks and run potential risked software?", L"Potential high risk detected", MB_YESNO|MB_ICONWARNING|MB_DEFBUTTON2);

	ignore_malware = true;

	SpeedButton1->Click();

	Form1->panel_menu_homeClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Label5MouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y)
{
	Label5->Font->Style = TFontStyles() << fsUnderline;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Label5MouseLeave(TObject *Sender)
{
	Label5->Font->Style = TFontStyles();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::btn_removeClick(TObject *Sender)
{
	Form3->Cursor = crHourGlass;
	Sleep(1500);

	Form3->Cursor = crArrow;
	PlaySound(L"C:\\WINDOWS\\Media\\Windows Message Nudge.wav",NULL,SND_ASYNC) ;

	Shape_header->Brush->Color = 0x007D4F58;

	label_warning->Caption = "Threat successfully handled";
	label_status->Caption = "File was added to exclusions list";
	lbl_final_action->Caption = "Threat successfully added to exclusions list";

	Form3->UpdateControlState();
	Form3->Update();

	if (Form1->prot_enabled == true && Form1->p2p_enabled == true) {
		Form1->shape_status->Brush->Color = 0x005EC472;
		Form1->label_status->Caption = "Your PC is protected and secured";
		Form1->label_threat->Caption = "No active threats found";
		Form1->image_threat_status->Picture = Form1->img_secure_green->Picture;
		Form1->img_ok_not_ok->Picture = Form1->img_ok->Picture;
	}  else {
		Form1->shape_status->Brush->Color = 0x0000D0FD;
		Form1->label_status->Caption = "Some functions was disabled";
		Form1->label_threat->Caption = "No active threats found";
		Form1->image_threat_status->Picture = Form1->img_secure_green->Picture;
		Form1->img_ok_not_ok->Picture = Form1->img_warn->Picture;
	}

	remove_malware = true;

	Form1->UpdateControlState();
	Form1->Update();

	SpeedButton1->Click();

	Form1->panel_menu_homeClick(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::SpeedButton2Click(TObject *Sender)
{
	POINT cur_pos;
	GetCursorPos(&cur_pos);
	PopupMenu1->Popup(cur_pos.x,cur_pos.y);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::SpeedButton4Click(TObject *Sender)
{
	POINT cur_pos;
	GetCursorPos(&cur_pos);
	PopupMenu2->Popup(cur_pos.x,cur_pos.y);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::SpeedButton5Click(TObject *Sender)
{
	POINT cur_pos;
	GetCursorPos(&cur_pos);
	popup_sett->Popup(cur_pos.x,cur_pos.y);
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Label5Click(TObject *Sender)
{
	ShellExecuteA(0, "open", "https://pr.network", NULL, NULL, SW_SHOWDEFAULT);
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormShow(TObject *Sender)
{
	PlaySound(L"C:\\WINDOWS\\Media\\Windows User Account Control.wav",NULL,SND_ASYNC) ;
}
//---------------------------------------------------------------------------

