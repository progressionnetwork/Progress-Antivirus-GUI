//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.XPMan.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.AppEvnts.hpp>
#include <Vcl.Menus.hpp>
#include "perfgrap.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Touch.GestureCtrls.hpp>
//---------------------------------------------------------------------------


class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TSpeedButton *SpeedButton1;
	TSpeedButton *SpeedButton2;
	TSpeedButton *SpeedButton3;
	TShape *Shape1;
	TPanel *Panel1;
	TLabel *Label1;
	TImage *Image13;
	TLabel *Label4;
	TPanel *panel_menu_home;
	TLabel *lbl_home;
	TImage *img_home;
	TPanel *panel_menu_scan;
	TLabel *lbl_scan;
	TImage *img_scan;
	TPanel *panel_menu_protection;
	TLabel *lbl_prot;
	TImage *img_prot;
	TPanel *panel_menu_sync;
	TLabel *lbl_sync;
	TImage *img_sync;
	TPanel *panel_menu_quarantine;
	TLabel *lbl_quar;
	TImage *img_quar;
	TPanel *panel_menu_settings;
	TLabel *lbl_sett;
	TImage *img_sett;
	TPanel *panel_menu_about;
	TLabel *lbl_about;
	TImage *img_about;
	TLabel *Label2;
	TTrayIcon *TrayIcon1;
	TApplicationEvents *ApplicationEvents1;
	TPopupMenu *PopupTray;
	TMenuItem *OpenProgress1;
	TMenuItem *Quarantine1;
	TMenuItem *Settings1;
	TMenuItem *Synthronization1;
	TMenuItem *N1;
	TMenuItem *About1;
	TMenuItem *N2;
	TMenuItem *Exit1;
	TLabel *Label13;
	TTimer *Timer1;
	TPopupMenu *PopupTransactionsMenu;
	TMenuItem *Copytransaction1;
	TMenuItem *Details1;
	TMenuItem *OpeninProgressExplorer1;
	TPopupMenu *PopupAddr;
	TMenuItem *Copyaddress1;
	TPageControl *page_tabs;
	TTabSheet *tab_home;
	TTabSheet *tab_scan;
	TTabSheet *tab_wallet;
	TTabSheet *tab_sync;
	TTabSheet *tab_quar;
	TTabSheet *tab_sett;
	TTabSheet *tab_about;
	TPanel *panel_scan;
	TImage *Image8;
	TLabel *Label19;
	TLabel *Label20;
	TLabel *Label21;
	TLabel *Label22;
	TLabel *lbl_checked_obj;
	TLabel *lbl_min_elapsed;
	TLabel *Label25;
	TLabel *Label26;
	TLabel *Label27;
	TLabel *lbl_totalobjects;
	TLabel *Label31;
	TLabel *Label32;
	TLabel *Label33;
	TLabel *Label34;
	TLabel *Label35;
	TLabel *Label17;
	TLabel *lbl_sec_counter;
	TLabel *Label23;
	TProgressBar *ProgressBar1;
	TButton *btn_cancel;
	TButton *btn_pause;
	TButton *btn_stop;
	TMemo *Memo1;
	TPanel *panel_prot;
	TLabel *Label18;
	TLabel *Label38;
	TLabel *Label52;
	TPageControl *PageControl1;
	TTabSheet *TabSheet1;
	TGroupBox *GroupBox1;
	TLabel *Label29;
	TLabel *Label28;
	TLabel *Label37;
	TLabel *Label30;
	TLabel *Label24;
	TLabel *Label41;
	TLabel *Label42;
	TLabel *Label43;
	TLabel *Label44;
	TLabel *Label45;
	TShape *Shape4;
	TLabel *lbl_addr1;
	TLabel *Label47;
	TSpeedButton *SpeedButton4;
	TLabel *Label39;
	TLabel *Label40;
	TImage *Image9;
	TLabel *Label66;
	TShape *Shape8;
	TTabSheet *TabSheet2;
	TLabel *Label51;
	TGroupBox *GroupBox2;
	TLabel *Label36;
	TLabel *Label48;
	TListView *ListView1;
	TGroupBox *GroupBox3;
	TLabel *Label49;
	TLabel *Label50;
	TListView *ListView2;
	TEdit *Edit1;
	TButton *Button4;
	TTabSheet *TabSheet3;
	TGroupBox *GroupBox4;
	TLabel *Label53;
	TLabel *Label54;
	TLabel *Label55;
	TLabel *Label56;
	TShape *Shape6;
	TEdit *Edit2;
	TButton *Button1;
	TButton *Button2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TButton *Button3;
	TGroupBox *GroupBox5;
	TLabel *Label57;
	TShape *Shape5;
	TLabel *lbl_addr2;
	TImage *Image10;
	TLabel *Label59;
	TLabel *Label60;
	TLabel *Label61;
	TButton *Button5;
	TTabSheet *TabSheet4;
	TGroupBox *GroupBox6;
	TLabel *Label46;
	TLabel *Label58;
	TLabel *Label62;
	TLabel *Label63;
	TLabel *Label65;
	TShape *Shape7;
	TLabel *Label64;
	TButton *Button6;
	TButton *Button7;
	TButton *Button9;
	TPanel *panel_sync;
	TLabel *Label68;
	TLabel *Label69;
	TLabel *Label70;
	TLabel *Label67;
	TPageControl *page_sett_tabs;
	TTabSheet *TabSheet5;
	TTabSheet *TabSheet6;
	TTabSheet *tab_sett_notify;
	TImage *Image1;
	TImage *img_ok_not_ok;
	TImage *img_about_black;
	TImage *img_about_white;
	TImage *img_home_black;
	TImage *img_home_white;
	TImage *img_prot_black;
	TImage *img_prot_white;
	TImage *img_quar_black;
	TImage *img_quar_white;
	TImage *img_scan_black;
	TImage *img_scan_white;
	TImage *img_sett_black;
	TImage *img_sett_white;
	TImage *img_sync_black;
	TImage *img_sync_white;
	TLabel *lbl_exclusions;
	TLabel *label_status;
	TLabel *lbl_reports;
	TPanel *Panel2;
	TImage *Image4;
	TLabel *Label7;
	TPanel *Panel3;
	TImage *Image3;
	TImage *Image5;
	TLabel *lbl_prot_enable_disable;
	TLabel *Label16;
	TPanel *Panel4;
	TLabel *Label9;
	TLabel *Label10;
	TImage *Image6;
	TPanel *Panel5;
	TImage *Image7;
	TLabel *Label5;
	TLabel *Label11;
	TShape *shape_status;
	TLabel *lbl_p2p_enable_disable;
	TCheckBox *CheckBox1;
	TBalloonHint *BalloonHint1;
	TLabel *Label71;
	TLabel *label_threat;
	TCheckBox *CheckBox2;
	TImage *image_threat_status;
	TCheckBox *CheckBox4;
	TCheckBox *CheckBox3;
	TImage *img_secure_red;
	TImage *img_secure_green;
	TImage *img_ok;
	TImage *img_not_ok;
	TButton *Button8;
	TButton *btn_settings;
	TCheckBox *CheckBox5;
	TCheckBox *CheckBox6;
	TTabSheet *tab_reports;
	TListView *list_report;
	TLabel *lbl_home2;
	TLabel *lbl_balance;
	TImageList *ImageList1;
	TSpeedButton *btn_p2p_slider;
	TSpeedButton *btn_prot_slider;
	TPopupMenu *popup_enable_disable;
	TMenuItem *Enable1;
	TMenuItem *Disable1;
	TLabel *Label15;
	TLabel *Label72;
	TImage *img_warn;
	TTabSheet *tab_exclusions;
	TLabel *Label12;
	TLabel *Label8;
	TLabel *lbl_call_exclude_processes_list;
	TLabel *Label3;
	TLabel *Label6;
	TLabel *Label14;
	TPanel *Panel6;
	TLabel *Label73;
	TLabel *Label74;
	TLabel *lbl_obj;
	TLabel *Label76;
	TLabel *Label77;
	TLabel *lbl_accessedby;
	TLabel *lbl_event;
	TLabel *lbl_action;
	TLabel *Label75;
	TLabel *lbl_date;
	TShape *Shape2;
	TImage *Image2;
	TLabel *Label78;
	TLabel *Label79;
	TLabel *Label81;
	TLabel *Label80;
	TLabel *Label82;
	TLabel *Label83;
	TLabel *Label84;
	TLabel *Label85;
	TLabel *Label86;
	TLabel *Label87;
	TLabel *Label88;
	TLabel *Label89;
	TLabel *Label90;
	TLabel *Label91;
	TLabel *Label92;
	TLabel *Label93;
	TLabel *Label94;
	TRichEdit *RichEdit1;
	TLabel *Label95;
	TLabel *Label96;
	TImage *Image11;
	TShape *anim3;
	TShape *anim9;
	TShape *anim10;
	TShape *anim11;
	TShape *anim12;
	TShape *anim13;
	TShape *anim14;
	TShape *anim15;
	TShape *anim16;
	TShape *anim17;
	TShape *anim18;
	TShape *anim19;
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall SpeedButton2Click(TObject *Sender);
	void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall SpeedButton1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall SpeedButton1MouseLeave(TObject *Sender);
	void __fastcall SpeedButton2MouseLeave(TObject *Sender);
	void __fastcall SpeedButton2MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall SpeedButton3MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall SpeedButton3MouseLeave(TObject *Sender);
	void __fastcall panel_menu_scanMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall panel_menu_protectionMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall panel_menu_syncMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall panel_menu_quarantineMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall panel_menu_settingsMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall panel_menu_scanMouseLeave(TObject *Sender);
	void __fastcall panel_menu_protectionMouseLeave(TObject *Sender);
	void __fastcall panel_menu_syncMouseLeave(TObject *Sender);
	void __fastcall panel_menu_quarantineMouseLeave(TObject *Sender);
	void __fastcall panel_menu_settingsMouseLeave(TObject *Sender);
	void __fastcall panel_menu_aboutMouseLeave(TObject *Sender);
	void __fastcall panel_menu_aboutMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall panel_menu_scanMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall panel_menu_scanMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall panel_menu_protectionMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall panel_menu_syncMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall panel_menu_quarantineMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall panel_menu_settingsMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall panel_menu_aboutMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall panel_menu_aboutMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall panel_menu_settingsMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall panel_menu_quarantineMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall panel_menu_syncMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall panel_menu_protectionMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall panel_menu_scanClick(TObject *Sender);
	void __fastcall OpenProgress1Click(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall TrayIcon1DblClick(TObject *Sender);
	void __fastcall TrayIcon1Click(TObject *Sender);
	void __fastcall ApplicationEvents1Deactivate(TObject *Sender);
	void __fastcall ApplicationEvents1Activate(TObject *Sender);
	void __fastcall ApplicationEvents1Minimize(TObject *Sender);
	void __fastcall ApplicationEvents1Restore(TObject *Sender);
	void __fastcall panel_menu_homeClick(TObject *Sender);
	void __fastcall panel_menu_homeMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall panel_menu_homeMouseLeave(TObject *Sender);
	void __fastcall panel_menu_homeMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall panel_menu_homeMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall panel_menu_protectionClick(TObject *Sender);
	void __fastcall panel_menu_syncClick(TObject *Sender);
	void __fastcall panel_menu_quarantineClick(TObject *Sender);
	void __fastcall panel_menu_settingsClick(TObject *Sender);
	void __fastcall panel_menu_aboutClick(TObject *Sender);
	void __fastcall Label13Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall btn_stopClick(TObject *Sender);
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall SpeedButton4Click(TObject *Sender);
	void __fastcall Copytransaction1Click(TObject *Sender);
	void __fastcall Edit7Click(TObject *Sender);
	void __fastcall Edit3MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Edit3MouseLeave(TObject *Sender);
	void __fastcall Edit4MouseLeave(TObject *Sender);
	void __fastcall Edit4MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Edit7MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Edit7MouseLeave(TObject *Sender);
	void __fastcall Edit2MouseLeave(TObject *Sender);
	void __fastcall Edit2MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Edit1Click(TObject *Sender);
	void __fastcall Edit1MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Edit1MouseLeave(TObject *Sender);
	void __fastcall Copyaddress1Click(TObject *Sender);
	void __fastcall lbl_addr1ContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled);
	void __fastcall lbl_addr2ContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall ListView1ColumnRightClick(TObject *Sender, TListColumn *Column,
          TPoint &Point);
	void __fastcall ListView2ColumnRightClick(TObject *Sender, TListColumn *Column,
          TPoint &Point);
	void __fastcall PageControl1Enter(TObject *Sender);
	void __fastcall Label64MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Label64MouseLeave(TObject *Sender);
	void __fastcall Label64Click(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall Edit4Change(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormDragOver(TObject *Sender, TObject *Source, int X, int Y, TDragState State,
          bool &Accept);
	void __fastcall FormMouseWheelUp(TObject *Sender, TShiftState Shift, TPoint &MousePos,
          bool &Handled);
	void __fastcall FormMouseWheelDown(TObject *Sender, TShiftState Shift, TPoint &MousePos,
		  bool &Handled);
	void __fastcall SpeedButton3Click(TObject *Sender);
	void __fastcall OpeninProgressExplorer1Click(TObject *Sender);
	void __fastcall Details1Click(TObject *Sender);
	void __fastcall lbl_exclusionsMouseActivate(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y, int HitTest, TMouseActivate &MouseActivate);
	void __fastcall lbl_call_exclude_processes_listMouseLeave(TObject *Sender);
	void __fastcall lbl_call_exclude_processes_listMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall ApplicationEvents1Message(tagMSG &Msg, bool &Handled);
	void __fastcall lbl_reportsClick(TObject *Sender);
	void __fastcall btn_p2p_sliderClick(TObject *Sender);
	void __fastcall btn_prot_sliderClick(TObject *Sender);
	void __fastcall lbl_reportsMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall lbl_reportsMouseLeave(TObject *Sender);
	void __fastcall lbl_exclusionsMouseLeave(TObject *Sender);
	void __fastcall lbl_exclusionsMouseMove(TObject *Sender, TShiftState Shift, int X,
		  int Y);
	void __fastcall lbl_home2MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall lbl_home2MouseLeave(TObject *Sender);
	void __fastcall Enable1Click(TObject *Sender);
	void __fastcall Disable1Click(TObject *Sender);
	void __fastcall lbl_exclusionsClick(TObject *Sender);
	void __fastcall Label3MouseLeave(TObject *Sender);
	void __fastcall Label3MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall list_reportClick(TObject *Sender);
	void __fastcall Label8MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
	void __fastcall Label8MouseLeave(TObject *Sender);
	void __fastcall Label12MouseLeave(TObject *Sender);
	void __fastcall Label12MouseMove(TObject *Sender, TShiftState Shift, int X, int Y);













private:	// User declarations
	void __fastcall TForm1::FormMoveX(TMessage &msg);
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

	BEGIN_MESSAGE_MAP
		VCL_MESSAGE_HANDLER( WM_MOVE, TMessage, FormMoveX )
	END_MESSAGE_MAP(TForm)

	bool prot_enabled;
	bool p2p_enabled;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
HRESULT DwmDropShadow(HWND hWnd);
//---------------------------------------------------------------------------
#endif
