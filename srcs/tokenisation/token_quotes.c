/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding <wding@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:54:02 by lcao              #+#    #+#             */
/*   Updated: 2025/06/17 19:25:21 by wding            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*extract_quoted_content(const char *line, int *i, char quote)
{
	int		start;
	char	*temp;

	start = *i;
	while (line[*i] && line[*i] != quote)
		(*i)++;
	if (!line[*i])
		return (NULL);
	temp = ft_strndup(line + start, *i - start);
	return (temp);
}

static char	*process_quote_content(char *temp, char quote, t_shell *shell)
{
	char	*expanded;

	if (quote == '"')
	{
		expanded = expand_variables(temp, shell);
		free(temp);
		return (expanded);
	}
	return (temp);
}

static char	*join_to_word(char **word, char *content, int *in_word)
{
	char	*joined;

	if (*in_word)
	{
		joined = ft_strjoin(*word, content);
		free(*word);
		free(content);
		return (joined);
	}
	else
	{
		*in_word = 1;
		return (content);
	}
}

int	tokenizer_handle_quote(const char *line, int *i, t_token_data *data)
{
	char	quote;
	char	*temp;
	char	*processed;

	quote = line[(*i)++];
	temp = extract_quoted_content(line, i, quote);
	if (!temp)
		return (0);
	processed = process_quote_content(temp, quote, data->shell);
	data->word = join_to_word(&data->word, processed, &data->in_word);
	(*i)++;
	return (1);
}
