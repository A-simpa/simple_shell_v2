#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char **split_words(char *str);

char **split_words(char *str)
{
	int i = 0, j = 0, count = 0 /** Number Of Words */;
	int prev = 0, cur = 0;
	char **arr, buf;

	/** Counting the number of words */
	while (str[i] != '\0')
	{
		if (i == 0 && str[i] == ' ')
		{
			i++;
			continue;
		}
		else if ( (str[i] == ' ' || !(str[i+1])) && str[i-1] != ' ')
			count++;
		i++;
	}

	arr = malloc(sizeof(char *) * (count + 1));
	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == ' ')
		{
			i++;
			continue;
		}
		else if ( (str[i] == ' ' || !(str[i+1])) && str[i-1] != ' ')
		{
			cur = i;
			if (str[i + 1])
			{
				buf = str[cur];
				str[cur] = '\0';
			}

			while (str[prev] == ' ' || str[prev] == '\n')
				prev++;
			arr[j] = malloc(sizeof(char) * (cur - prev + 1));
			strcpy(arr[j++], &(str[prev]));
			str[i] = buf;
			prev = cur;
		}
		i++;
	}

	arr[count+1] = NULL;

	return (arr);
}


int main(void)
{
	char str[] = "Hello Milk Way";
	char **arr;
	int i;

	arr = split_words(str);

	for (i = 0; arr[i]; arr++)
		printf("%s\n", arr[i]);

	return (EXIT_SUCCESS);
}
































