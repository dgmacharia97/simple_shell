#include "shell_sh.h"

/**
* ajouter_var_env - ajoute un chemin à la commande
* @path : chemin de la commande
* @commande : commande entrée par l'utilisateur
* Retour : tampon contenant la commande avec le chemin en cas de succès
* NULL en cas d'échec
*/
char *ajouter_var_env(char *path, char *commande)
{
	char *buffer;
	size_t i = 0, j = 0;

	if (commande == 0)
		commande = "";

	if (path == 0)
		path = "";

	buffer = malloc(sizeof(char) * (_strlen(path) + _strlen(commande) + 2));
	if (!buffer)
		return (NULL);

	while (path[i])
	{
		buffer[i] = path[i];
		i++;
	}

	if (path[i - 1] != '/')
	{
		buffer[i] = '/';
		i++;
	}
	while (commande[j])
	{
		buffer[i + j] = commande[j];
		j++;
	}
	buffer[i + j] = '\0';
	return (buffer);
}
