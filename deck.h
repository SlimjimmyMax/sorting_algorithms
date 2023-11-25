#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Represents the value of the card
 * From "Ace" to "King"
 * @kind: Represents kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of cards
 *
 * @card: Represents pointer to the card of the node
 * @prev: Represents pointer to the previous node of the list
 * @next: Represents pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif
