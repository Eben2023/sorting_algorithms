#include <stdlib.h>
#include <string.h>
#include "deck.h"

/**
 * compare_cards - Helper function to compare two cards
 *
 * @card1: Pointer to the first card
 * @card2: Pointer to the second card
 *
 * Return: Negative value if card1 is less than card2,
 * Positive value if card1 is greater than card2,
 * 0 if card1 and card2 are equal
 */
int compare_cards(const void *card1, const void *card2)
{
const card_t *c1 = *((const card_t **)card1);
const card_t *c2 = *((const card_t **)card2);

int value_cmp = strcmp(c1->value, c2->value);
int kind_cmp = c1->kind - c2->kind;

if (value_cmp == 0)
return kind_cmp;
else
return value_cmp;
}

/**
 * sort_deck - Sorts a deck of cards in ascending order
 *
 * @deck: Pointer to the deck of cards
 */
void sort_deck(deck_node_t **deck)
{
if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
return;

size_t deck_size = 0;
deck_node_t *current = *deck;

// Count the number of cards in the deck
while (current != NULL)
{
deck_size++;
current = current->next;
}

// Create an array of card pointers
card_t *card_array[deck_size];
current = *deck;
size_t i = 0;

while (current != NULL)
{
card_array[i++] = (card_t *)current->card;
current = current->next;
}

// Sort the card array using qsort
qsort(card_array, deck_size, sizeof(card_t *), compare_cards);

// Update the deck nodes with the sorted cards
current = *deck;
i = 0;

while (current != NULL)
{
current->card = card_array[i++];
current = current->next;
}
}
