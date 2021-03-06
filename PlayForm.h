//---------------------------------------------------------------------------

#ifndef PlayFormH
#define PlayFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <pngimage.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TImage *Image2;
	TImage *Image3;
	TImage *Image4;
	TButton *ButtonExit;
	TButton *ButtonHit;
	TImage *DeckPic;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *LabelPlayer;
	TLabel *LabelDealer;
	TImage *ImageD1;
	TImage *ImageD2;
	TImage *ImageD3;
	TImage *ImageD4;
	TButton *ButtonStand;
	TImage *BackgroundImage;
	TPanel *ResultPanel;
	TImage *ImageD5;
	TImage *ImageD6;
	TImage *Image5;
	TImage *Image6;
	void __fastcall ButtonExitClick(TObject *Sender);
	void __fastcall ButtonHitClick(TObject *Sender);
	void __fastcall ButtonStandClick(TObject *Sender);
	void __fastcall ResultPanelClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
