#include "shell_sh.h"

/**
 * _strcmp - compare deux chaînes de caractères
 * @s1: comparée à s2;
 * @s2: comparée à s1;
 *
 * Retour : retourne la différence entre les chaînes
 */
int _strcmp(char *s1, char *s2)
{
    int i = 0, sortie;

    while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0')
        i++;

    sortie = (*(s1 + i) - *(s2 + i));

    return (sortie);
}

/**
 * _strlen - renvoie la longueur d'une chaîne de caractères
 * @s: chaîne passée en argument
 *
 * Retour : renvoie la longueur de la chaîne passée
 */
int _strlen(char *s)
{
    int compteur = 0;

    while (*s != '\0')
    {
        compteur++;
        s++;
    }
    return (compteur);
}

/**
 * _strncmp - compare deux chaînes de caractères jusqu'à n octets
 * @s1: comparée à s2
 * @s2: comparée à s1
 * @n: nombre d'octets
 *
 * Retour : différence entre s1 et s2
 */
int _strncmp(char *s1, char *s2, int n)
{
    int i;

    for (i = 0; s1[i] && s2[i] && i < n; i++)
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}

/**
 * _strdup - duplique une chaîne de caractères
 * @s: chaîne à dupliquer
 *
 * Retour : pointeur vers la chaîne dupliquée
 */
char *_strdup(char *s)
{
    char *ptr;
    int i, len;

    if (s == NULL)
        return (NULL);

    len = _strlen(s);

    ptr = malloc(sizeof(char) * (len + 1));
    if (!ptr)
        return (NULL);
    for (i = 0; *s != '\0'; s++, i++)
        ptr[i] = s[0];

    ptr[i++] = '\0';
    return (ptr);
}

/**
 * _strchr - localise un caractère dans une chaîne de caractères
 * @s: chaîne à vérifier
 * @c: caractère à localiser
 *
 * Retour : renvoie un pointeur vers la première occurrence du caractère
 * ou NULL si le caractère n'est pas trouvé
 */
char *_strchr(char *s, char c)
{
    while (*s)
    {
        if (*s == c)
            return (s);
        s++;
    }
    if (!c)
        return (s);
    return (NULL);
}
