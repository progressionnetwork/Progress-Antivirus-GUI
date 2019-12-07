//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm_Details : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TRichEdit *RichEdit1;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm_Details(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_Details *Form_Details;
//---------------------------------------------------------------------------
#endif
