#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * add_dnodeint- adds a node at the head
 * @head: a pointer to a pointer to the head
 * @n: the value to put in the new node
 * Return: the new node
*/

void push(stack_t **head, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)	
		return;

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;

	if (*head != NULL)
		(*head)->prev = new_node;

	*head = new_node;

	return;

	/*if (*head == NULL)
	{
		free(new_node);
		*head = malloc(sizeof(stack_t));
		(*head)->n = n;
		(*head)->next = NULL;
		(*head)->prev = NULL;
		return;
	}

	(*head)->prev = new_node;
	(*new_node).next = *head;
	(*new_node).prev = NULL;
	new_node->n = n;
	*head = new_node;*/

}

void pall(stack_t *head)
{
	while (head != NULL)
	{
		printf("%d\n", (*head).n);
		head = (*head).next;
	}
}

void free_stack(stack_t *head)
{
	stack_t *freer = head;

	if (head == NULL)
		return;

	while ((*freer).next != NULL)
	{
		freer = (*freer).next;
		free((*freer).prev);
	}

	free(freer);
}
