//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#pragma hdrstop

#include "PlayForm.h"
#include "StartForm.h"
#include "TechPart.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int CardPlace = 0;
int DealerCardPlace = 0;
int playerTotal = 0;
int dealerTotal = 0;
Card deck[52];
Card *cardPtr = &deck[0];
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	srand(static_cast<unsigned int>(time(0))); // ????????????? ???????? ????????? ????? ? ???????? ?????????? ?????
	rand(); // ???? ??????????? Visual Studio, ?????????? ?????? ??????????????? ????????? ?????



	// ????? ???? ?? ??????? (?? ???????????) ???????????????? ?????? ?????, ?? ?? ???? ????????????! ???? ??? ? ??????!
	int card = 0;
	for (int suit = 0; suit < MAX_SUITS; ++suit)
	for (int rank = 0; rank < MAX_RANKS; ++rank)
	{
		deck[card].suit = static_cast<CardSuit>(suit);
		deck[card].rank = static_cast<CardRank>(rank);
		++card;
	}

	shuffleDeck(deck);

	Sleep(100);
	ImageD1->Picture->LoadFromFile(GetCardName(*cardPtr));
	dealerTotal += getCardValue(*cardPtr++);
	DealerCardPlace++;

	LabelDealer->Caption = dealerTotal;

	// ????? ???????? ??? ?????

	ButtonHit->Click();
	ButtonHit->Click();

	LabelPlayer->Caption = playerTotal;

}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonExitClick(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonHitClick(TObject *Sender)
{

	String Path = GetCardName(*cardPtr);
	playerTotal += getCardValue(*cardPtr++);
	LabelPlayer->Caption = playerTotal;

	Sleep(100);

	switch(CardPlace)
	{
		case 0:
		{
			Image1->Picture->LoadFromFile(Path);
			CardPlace++;
		};break;
		case 1:
		{
			Image2->Picture->LoadFromFile(Path);
			CardPlace++;
		};break;
		case 2:
		{
			Image3->Picture->LoadFromFile(Path);
			CardPlace++;
		};break;
		case 3:
		{
			Image4->Picture->LoadFromFile(Path);
			CardPlace++;
		};break;
		case 4:
		{
			Image5->Picture->LoadFromFile(Path);
			CardPlace++;
		};break;
		case 5:
		{
			Image6->Picture->LoadFromFile(Path);
			CardPlace = 0;
		};break;
		default:
		{
			ShowMessage("You lose");
		}
	}

	if (playerTotal>21) {
		ResultPanel->Caption = "You Lose";
		ResultPanel->Show();
		Win(1,0,2);
	}



}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonStandClick(TObject *Sender)
{
	while (dealerTotal<17)
	{
		String DealerPath = GetCardName(*cardPtr);
		dealerTotal += getCardValue(*cardPtr++);
		LabelDealer->Caption = dealerTotal;
		Sleep(300);
		switch(DealerCardPlace)
		{
			case 0:
			{
				ImageD1->Picture->LoadFromFile(DealerPath);
				DealerCardPlace++;
			};break;
			case 1:
			{
				ImageD2->Picture->LoadFromFile(DealerPath);
				DealerCardPlace++;
			};break;
			case 2:
			{
				ImageD3->Picture->LoadFromFile(DealerPath);
				DealerCardPlace++;
			};break;
			case 3:
			{
				ImageD4->Picture->LoadFromFile(DealerPath);
				DealerCardPlace++;
			};break;
			case 4:
			{
				ImageD5->Picture->LoadFromFile(DealerPath);
				DealerCardPlace=0;
			};break;
			case 5:
			{
				ImageD6->Picture->LoadFromFile(DealerPath);
				DealerCardPlace=0;
			};break;
			default:
			{
				ShowMessage("Dealer lose");
			}
		}
	}
	if (dealerTotal>21)
	{
		ResultPanel->Caption = "You Win";
		ResultPanel->Show();
		Win(1,0,1);
	}
	else
		{
			if (dealerTotal >= playerTotal)
			{
				ResultPanel->Caption = "You Lose";
				ResultPanel->Show();
				Win(1,0,2);
			}
			else
				{
					ResultPanel->Caption = "You Win";
					ResultPanel->Show();
					Win(1,0,1);
				}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ResultPanelClick(TObject *Sender)
{
	Form2->Hide();
	Form2->Close();
	Form1->Show();
	ResultPanel->Hide();

	dealerTotal = 0;
	LabelDealer->Caption = 0;
	playerTotal = 0;
	LabelPlayer->Caption = 0;

	Image1->Picture = NULL;
	Image2->Picture = NULL;
	Image3->Picture = NULL;
	Image4->Picture = NULL;
	Image5->Picture = NULL;
	Image6->Picture = NULL;
	ImageD1->Picture = NULL;
	ImageD2->Picture = NULL;
	ImageD3->Picture = NULL;
	ImageD4->Picture = NULL;
	ImageD5->Picture = NULL;
	ImageD6->Picture = NULL;

	CardPlace = 2;
	DealerCardPlace = 1;

	shuffleDeck(deck);

	cardPtr = &deck[0];

	ImageD1->Picture->LoadFromFile(GetCardName(*cardPtr));
	dealerTotal += getCardValue(*cardPtr++);

	LabelDealer->Caption = dealerTotal;

	// ????? ???????? ??? ?????

	Image1->Picture->LoadFromFile(GetCardName(*cardPtr));
	playerTotal += getCardValue(*cardPtr++);

	Image2->Picture->LoadFromFile(GetCardName(*cardPtr));
	playerTotal += getCardValue(*cardPtr++);

	LabelPlayer->Caption = playerTotal;


}
//---------------------------------------------------------------------------

