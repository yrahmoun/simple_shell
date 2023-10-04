#include "shell.h"

/**
 * free_list_env - frees linked list env_t
 * @head: pointer to linked list
 */

void free_list_env(env_t *head)
{
	env_t *aux;

	while (head)
	{
		aux = head->next;
		free(head->str);
		free(head);
		head = aux;
	}
}
