#include "shell_sh.h"

/**
 * tokenizeur - crée des jetons à partir de l'entrée donnée
 * @line : à être tokenisé
 *
 * Retour : un tableau de chaînes de caractères
 */
char **tokenizeur(char *line)
{
    char *buf = NULL, *bufp = NULL, *jeton = NULL, *delim = " :\t\r\n";
    char **jetons = NULL;
    int taille_jetons = 1;
    size_t index = 0, flag = 0;

    buf = _strdup(line);
    if (!buf)
        return (NULL);
    bufp = buf;

    while (*bufp)
    {
        if (_strchr(delim, *bufp) != NULL && flag == 0)
        {
            taille_jetons++;
            flag = 1;
        }
        else if (_strchr(delim, *bufp) == NULL && flag == 1)
            flag = 0;
        bufp++;
    }
    jetons = malloc(sizeof(char *) * (taille_jetons + 1));
    jeton = strtok(buf, delim);
    while (jeton)
    {
        jetons[index] = _strdup(jeton);
        if (jetons[index] == NULL)
        {
            free(jetons);
            return (NULL);
        }
        jeton = strtok(NULL, delim);
        index++;
    }
    jetons[index] = '\0';
    free(buf);
    return (jetons);
}
