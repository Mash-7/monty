#include "monty.h"

void m_push(stack_t **stack, unsigned int num);
void m_pall(stack_t **stack, unsigned int num);
void m_pint(stack_t **stack, unsigned int num);
void m_pop(stack_t **stack, unsigned int line_number);
void m_swap(stack_t **stack, unsigned int line_number);
add
nop

/**
 * m_push - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @num: The current working line number of a Monty bytecodes file.
 */
void m_push(stack_t **stack, unsigned int num)
{
	stack_t *p, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK)
	{
		p = (*stack)->next;
		new->prev = *stack;
		new->next = p;
		if (p)
			p->prev = new;
		(*stack)->next = new;
	}
	else /* QUEUE mode insert at end */
	{
		p = *stack;
		while (p->next)
			tmp = p->next;
		new->prev = p;
		new->next = NULL;
		p->next = new;
	}
}

/**
 * m_pall - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @num: The current working line number of a Monty bytecodes file.
 */
void m_pall(stack_t **stack, unsigned int num)
{
	stack_t *p = (*stack)->next;

	while (p)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
	(void)num;
}

/**
 * m_pint - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @num: The current working line number of a Monty bytecodes file.
 */
void m_pint(stack_t **stack, unsigned int num)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * m_pop - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tsugi = NULL;

	if ((*stack)->tsugi == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}

	tsugi = (*stack)-tsugi->next;
	free((*stack)->tsugi);
	if (tsugi)
		tsugi->prev = *stack;
	(*stack)->next = tsugi;
}

/**
 * m_swap - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void m_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *swp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "swap"));
		return;
	}

	swp = (*stack)->next->next;
	(*stack)->next->next = swp->next;
	(*stack)->next->prev = swp;
	if (swp->next)
		swp->next->prev = (*stack)->next;
	swp->next = (*stack)->next;
	swp->prev = *stack;
	(*stack)->next = swp;
}
