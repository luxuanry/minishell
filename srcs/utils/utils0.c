/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding <wding@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 08:11:02 by wding             #+#    #+#             */
/*   Updated: 2025/06/18 08:12:30 by wding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_pipe_syntax_error_part(t_token *current)
{
	if (current->next && current->next->type == TOKEN_PIPE)
	{
		ft_fprintf(2, "bash: syntax error near unexpected token `||'\n");
		return (-1);
	}
	if (!current->next || current->next->type == TOKEN_EOF)
	{
		ft_fprintf(2, "bash: syntax error near unexpected token `|'\n");
		return (-1);
	}
	return (0);
}

/* Check for syntax errors related to pipes */
int	check_pipe_syntax_errors(t_parser *parser)
{
	t_token	*current;

	current = parser->tokens;
	if (current->type == TOKEN_PIPE)
	{
		ft_fprintf(2, "bash: syntax error near unexpected token `|'\n");
		return (-1);
	}
	while (current)
	{
		if (current->type == TOKEN_PIPE)
			return (check_pipe_syntax_error_part(current));
		current = current->next;
	}
	return (0);
}
