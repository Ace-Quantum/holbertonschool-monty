#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * add_dnodeint- adds a node at the head
 * @head: a pointer to a pointer to the head
 * @n: the value to put in the new node
 * Return: the new node
*/

void push(stack_t **head, const int n)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		//return (NULL);

	(*new_node).n = n;

	if (*head == NULL)
	{
		(*new_node).next = NULL;
		(*new_node).prev = NULL;
		*head = new_node;
		//return (new_node);
	}

	(*head)->prev = new_node;
	(*new_node).next = *head;
	(*new_node).prev = NULL;
	*head = new_node;

	//return (new_node);
}

void pall(stack_t *head)
{
	while (head != NULL)
	{
		printf("%d\n", (*head).n);
		head = (*head).next;
	}
}