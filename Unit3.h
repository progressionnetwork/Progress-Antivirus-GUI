//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TShape *Shape_header;
	TImage *Image1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label4;
	TLabel *label_warning;
	TSpeedButton *SpeedButton1;
	TLabel *label_status;
	TShape *Shape2;
	TPanel *btn_block;
	TLabel *lbl_scan;
	TPanel *btn_ignore;
	TLabel *Label1;
	TPanel *btn_remove;
	TLabel *Label7;
	TSpeedButton *SpeedButton3;
	TShape *Shape8;
	TShape *Shape1;
	TLabel *Label5;
	TLabel *lbl_final_action;
	TImage *Image2;
	TLabel *Label10;
	TSpeedButton *SpeedButton2;
	TShape *Shape3;
	TPopupMenu *PopupMenu1;
	TMenuItem *Blockexecution1;
	TMenuItem *Blockexecutionandremove1;
	TMenuItem *Blockexecutionandmovetoquarantine1;
	TShape *Shape4;
	TSpeedButton *SpeedButton4;
	TPopupMenu *PopupMenu2;
	TMenuItem *Ingoreonce1;
	TMenuItem *Ignorealwaysexecute1;
	TSpeedButton *SpeedButton5;
	TPopupMenu *popup_sett;
	TMenuItem *Settingsofnotifications1;
	TLabel *Label6;
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall btn_blockMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall btn_blockMouseLeave(TObject *Sender);
	void __fastcall btn_blockMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall btn_blockMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall btn_ignoreMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall btn_ignoreMouseLeave(TObject *Sender);
	void __fastcall btn_ignoreMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall btn_ignoreMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall btn_removeMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall btn_removeMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall btn_removeMouseLeave(TObject *Sender);
	void __fastcall btn_removeMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall Shape_headerMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall btn_blockClick(TObject *Sender);
	void __fastcall btn_ignoreClick(TObject *Sender);
	void __fastcall Label5MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Label5MouseLeave(TObject *Sender);
	void __fastcall btn_removeClick(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall SpeedButton5Click(TObject *Sender);
	void __fastcall Label5Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);





private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
