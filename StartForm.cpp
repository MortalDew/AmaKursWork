//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>

#pragma hdrstop

#include "StartForm.h"
#include "PlayForm.h"
#include "TechPart.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Sleep(300);
	Form2->Show();
	Form1->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
	ScoreLabelLeft->Caption = Win(0,1,1);
	ScoreLabelRight->Caption = Win(0,1,2);
}
//---------------------------------------------------------------------------

