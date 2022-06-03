#pragma once
#include <vector>
#include <string>

enum Ranks { two = 2, three = 3, four = 4, five = 5, six = 6, seven = 7, eight = 8, nine = 9, ten = 10, jack = 10, queen = 10, king = 10, ace = 1 };
enum Suits { spades, clubs, diamonds, hearts };

class Card
{
protected:
	Ranks m_value;
	Suits m_suit;
	bool m_faceUp{ 0 }; //0 - рубашкой кверху, 1 - в открытую
public:
	Card(Ranks value, Suits suit, bool faceUp = 0) : m_value(value), m_suit(suit), m_faceUp(faceUp) {}

	void Flip()
	{
		m_faceUp = !m_faceUp;
	}

	Ranks GetValue() const
	{
		return m_value;
	}
};

class Hand
{
protected:
	std::vector<Card*> m_hand;
public:
	Hand() {}
	virtual ~Hand() {}

	void Add(Card* card)
	{
		m_hand.push_back(card);
	}

	void Clear()
	{
		m_hand.clear();
	}

	int GetValue() const
	{
		int sum{ 0 };
		int aces{ 0 };
		for (size_t i = 0; i < m_hand.size(); i++)
		{
			if (m_hand[i]->GetValue() == ace)
			{
				sum += 11;
				aces++;
			}
			else
				sum += m_hand[i]->GetValue();
		}

		//if total value exceeds 21 we remove extra 10 points per ace reducing it from 11 to 1. This way aces work even if drawn from index 0 and value exceeds 21 later on
		if (sum > 21 && aces > 0)
			sum = sum - (aces * 10);

		return sum;
	}
};