//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TRectangle *Rectangle1;
	TPath *Path1;
	TRectangle *Rectangle2;
	TButton *Button1;
	TTimer *Timer1;
	TText *Text1;
	TSwitch *Switch1;
	TRectangle *Rectangle3;
	TSwitch *Switch2;
	TRectangle *Rectangle4;
	TRectangle *Rectangle5;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Switch1Switch(TObject *Sender);
	void __fastcall Switch2Switch(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void __fastcall set_level(TPath * pth, int lvl);
	void __fastcall create_point(TComponent* Owner,TPath * pth);
	void __fastcall move_point(TPath * pth);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
