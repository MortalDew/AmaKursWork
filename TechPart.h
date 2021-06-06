//---------------------------------------------------------------------------

#ifndef TechPartH
#define TechPartH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <ctime> // äëÿ time()
#include <cstdlib> // äëÿ rand() è srand()
#include "PlayForm.h"

int Win(bool add, bool get, int who){
	static int PlayerWin;
	static int DealerWin;

	if (add){
		if (who == 1) PlayerWin++;
		if (who == 2) DealerWin++;
	}
	if (get) {
		if (who == 1) return PlayerWin;
		if (who == 2) return DealerWin;
	}
	return 0;
}
enum CardSuit
{
	SUIT_TREFU,
	SUIT_BYBNU,
	SUIT_CHERVU,
	SUIT_PIKI,
	MAX_SUITS
};

enum CardRank
{
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_VALET,
	RANK_DAMA,
	RANK_KOROL,
	RANK_TYZ,
	MAX_RANKS
};

struct Card
{
	CardRank rank;
	CardSuit suit;
};

String GetCardName(const Card &card)
{

	String FileName = GetCurrentDir() + "/Deck/";
	switch (card.rank)
	{
		case RANK_2:		FileName += '2'; break;
		case RANK_3:		FileName += '3'; break;
		case RANK_4:		FileName += '4'; break;
		case RANK_5:		FileName += '5'; break;
		case RANK_6:		FileName += '6'; break;
		case RANK_7:		FileName += '7'; break;
		case RANK_8:		FileName += '8'; break;
		case RANK_9:		FileName += '9'; break;
		case RANK_10:		FileName += 'T'; break;
		case RANK_VALET:	FileName += 'J'; break;
		case RANK_DAMA:	    FileName += 'Q'; break;
		case RANK_KOROL:	FileName += 'K'; break;
		case RANK_TYZ:		FileName += 'A'; break;
	}
		switch (card.suit)
	{
		case SUIT_TREFU:	FileName += "TR"; break;
		case SUIT_BYBNU:	FileName += "BY"; break;
		case SUIT_CHERVU:	FileName += "CH"; break;
		case SUIT_PIKI:	    FileName += "PI"; break;
	}

	FileName += ".jpg";
	return FileName;
}

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Ðàâíîìåðíî ðàñïðåäåëÿåì ãåíåðàöèþ ñëó÷àéíîãî ÷èñëà â äèàïàçîíå çíà÷åíèé
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void swapCard(Card &a, Card &b)
{
	Card temp = a;
	a = b;
	b = temp;
}
void shuffleDeck(Card *deck)
{
	// Ïåðåáèðàåì êàæäóþ êàðòó â êîëîäå
	for (int index = 0; index < 52; ++index)
	{
		// Âûáèðàåì ëþáóþ ñëó÷àéíóþ êàðòó
		int swapIndex = getRandomNumber(0, 51);
		// Ìåíÿåì ìåñòàìè ñ íàøåé òåêóùåé êàðòîé
		swapCard(deck[index], deck[swapIndex]);
	}
}

int getCardValue(const Card &card)
{
	switch (card.rank)
	{
	case RANK_2:		return 2;
	case RANK_3:		return 3;
	case RANK_4:		return 4;
	case RANK_5:		return 5;
	case RANK_6:		return 6;
	case RANK_7:		return 7;
	case RANK_8:		return 8;
	case RANK_9:		return 9;
	case RANK_10:		return 10;
	case RANK_VALET:	return 10;
	case RANK_DAMA:	    return 10;
	case RANK_KOROL:	return 10;
	case RANK_TYZ:		return 11;
	}

	return 0;
}

#endif
