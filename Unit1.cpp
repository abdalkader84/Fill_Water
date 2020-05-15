//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
unsigned long tim;
int level;
int phs;
float e=2.7182;
bool start_fill=false;
bool start_sink=false;
bool on1=false;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	level=Path1->Height;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::set_level(TPath * pth, int lvl)
{
	pth->Data->Clear();
	pth->Data->MoveTo(TPointF(0,pth->Height));
	pth->Data->LineTo(TPointF(0,0));
	pth->Data->LineTo(TPointF(0,lvl));
	//-------------------------------------------
	for (int i=0; i <(int) pth->Width; i++) {
		pth->Data->LineTo(TPointF(i,lvl+5*sin(3*i*3.1415/180 + phs*3.1415/180)));
	}
	//-------------------------------------------
	pth->Data->LineTo(TPointF(pth->Width,lvl));
	pth->Data->LineTo(TPointF(pth->Width,0));
	pth->Data->LineTo(TPointF(pth->Width,pth->Height));
	pth->Data->ClosePath();
	phs+=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	tim++;
	if (Path1->Height- level>=Rectangle5->Position->Y)
	{
	   on1=false;
	   Rectangle4->Fill->Color=0xffffffff;
	}
	else
	{
	   Rectangle4->Fill->Color=0xffff0000;
	}
	if (Path1->Height- level<Rectangle4->Position->Y)
	{
	   on1=true;
	   Rectangle5->Fill->Color=0xffff0000;
	}
	else
	{
       Rectangle5->Fill->Color=0xffffffff;
    }
	if (on1==true)
	{
		if (start_fill==true) {
			level--;
			if (level<0) {
				level=0;
			}
		}
		if (level>0) {
				create_point(Form1,Path1);
		}

	}
	else
	{
		start_fill=false;
	}
    if (start_sink==true) {
		   level++;
		}
	if (level<Path1->Height-3) {
		set_level(Path1,level);

	}
	move_point(Path1);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::create_point(TComponent* Owner,TPath * pth)
{
	for (int i=0; i<4; i++)
	{
       TCircle * c=new TCircle(Owner);
		c->Position->Point=TPointF(0,0);
		c->Width=RandomRange(4,8);
		c->Height=c->Width;
		c->TagFloat=RandomRange(pth->Width/4,pth->Width/2);
		c->Tag=tim;
		c->Fill->Color=0xFF6BB8F7;
		c->Stroke->Kind=0;
		pth->AddObject(c);
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::move_point(TPath * pth)
{
	for (int i=0; i<pth->Children->Count; i++) {
		TCircle * c= (TCircle *) pth->Children->Items[i];
		if (c->ClassName()=="TCircle") {

			float f=1/ (float)(tim-c->Tag);
			f=(1-Power(e,f)/e);
			f=c->TagFloat *f;
			c->Position->X=f;
			//Text1->Text=FloatToStrF(f,ffFixed,2,2)+" , "+FloatToStrF(c->TagFloat,ffFixed,2,2);
			c->Opacity=c->Opacity-0.01;
			c->Position->Y=c->Position->Y+5;
			if (c->Position->Y>level) {
				pth->RemoveObject(c);
				c->DisposeOf();
				start_fill=true;
			}


		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	//create_point(Form1,Path1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Switch1Switch(TObject *Sender)
{
	if (Path1->Height- level<Rectangle5->Position->Y) {
	   on1=Switch1->IsChecked;

	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Switch2Switch(TObject *Sender)
{
	start_sink=Switch2->IsChecked;

}
//---------------------------------------------------------------------------

