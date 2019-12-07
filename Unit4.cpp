//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_Details *Form_Details;
//---------------------------------------------------------------------------
__fastcall TForm_Details::TForm_Details(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_Details::Button1Click(TObject *Sender)
{
	Form_Details->Close();
}
//---------------------------------------------------------------------------
