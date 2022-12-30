#include "main.h"

int main(void)
{
	path_list_t *head;

	head = NULL;

	head = create_path_list();

	print_path_list(head);

	return (0);
}
