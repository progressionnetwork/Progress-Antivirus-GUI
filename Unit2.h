//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TSpeedButton *SpeedButton5;
	TLabel *Label5;
	TPanel *btn_block;
	TLabel *lbl_scan;
	TPanel *btn_ignore;
	TLabel *Label6;
	TPanel *btn_remove;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall btn_blockMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall btn_blockMouseLeave(TObject *Sender);
	void __fastcall btn_ignoreMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall btn_ignoreMouseLeave(TObject *Sender);
	void __fastcall btn_removeMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall btn_removeMouseLeave(TObject *Sender);
	void __fastcall btn_blockMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall btn_blockMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall btn_ignoreMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall btn_ignoreMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall btn_removeMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall btn_removeMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Label6Click(TObject *Sender);



private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
