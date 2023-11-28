#include "lists.h"

/**
 * insert_node - Incorporates a given numeric
 *               value into a sorted singly-linked list.
 * @head: A reference to the initial node of the linked list.
 * @number: The numeric value to be added.
 * Return: Returns NULL in case of failure;
 *         otherwise, returns a pointer to the newly inserted node.
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = *head, *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;

	if (node == NULL || node->n >= number)
	{
		new->next = node;
		*head = new;
		return (new);
	}

	while (node && node->next && node->next->n < number)
		node = node->next;

	new->next = node->next;
	node->next = new;

	return (new);
}
