//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	long SC_DRAGMOVE = 0xF012;
	if(Button == mbLeft)

	{
		ReleaseCapture();
		SendMessage(Handle, WM_SYSCOMMAND, SC_DRAGMOVE, 0);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
		Form2->Left = Screen->Width - Form2->Width;
		Form2->Top = Screen->Height - Form2->Height - 30;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SpeedButton5Click(TObject *Sender)
{
	Form2->Close();
	Form1->Show();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void __fastcall TForm2::btn_blockMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	btn_block->Color = 0x004d8c3e;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btn_blockMouseLeave(TObject *Sender)
{
	btn_block->Color = 0x005EC472;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btn_ignoreMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	btn_ignore->Color = 0x00000095;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btn_ignoreMouseLeave(TObject *Sender)
{
	btn_ignore->Color = clRed;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btn_removeMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{
	btn_remove->Color = 0x005B3940;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btn_removeMouseLeave(TObject *Sender)
{
	btn_remove->Color = 0x00A8737C;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btn_blockMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	btn_block->Color = 0x0096D8A3;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btn_blockMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	btn_block->Color = 0x005EC472;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btn_ignoreMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	btn_ignore->Color = 0x007171FF;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btn_ignoreMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	btn_ignore->Color = clRed;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btn_removeMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y)
{
	btn_remove->Color = 0x00C2A0A7;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btn_removeMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	btn_remove->Color = 0x007D4F58;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Label6Click(TObject *Sender)
{
		int Key= Application->MessageBox(L"Are you sure you want ignore the risks and run potential risked software?", L"Potential high risk detected", MB_YESNO|MB_ICONQUESTION|MB_DEFBUTTON2);
}
//---------------------------------------------------------------------------


