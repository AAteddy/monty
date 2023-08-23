#include "monty.h"

/**
 * set_op_tok_error - A function that sets last element of
 *                    op_toks to be an error code.
 * @error_code: Integer to store as a string in op_toks.
 */
void set_op_tok_error(int error_code)
{
	char **new_tokn = NULL;
	char *strg_exit = NULL;
	int tokn_leng = 0, i = 0;

	tokn_leng = token_arr_len();
	new_tokn = malloc(sizeof(char *) * (tokn_leng + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	while (i < tokn_leng)
	{
		new_tokn[i] = op_toks[i];
		i++;
	}
	strg_exit = get_int(error_code);
	if (!strg_exit)
	{
		free(new_tokn);
		malloc_error();
		return;
	}
	new_tokn[i++] = strg_exit;
	new_tokn[i] = NULL;
	free(op_toks);
	op_toks = new_tokn;
}
