#include "shell_sh.h"

/**
 * _putchar - écrit le caractère c sur stdout
 * @c : Le caractère à imprimer
 *
 * Retour : En cas de succès, renvoie 1.
 * En cas d'erreur, renvoie -1 et définit errno en conséquence.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * print_s - imprime une chaîne de caractères
 * @s : Chaîne de caractères à imprimer
 *
 * Retour : nombre de caractères imprimés
 */
int print_s(char *s)
{
    int i = 0;

    while (s[i] != '\0')
    {
        _putchar(s[i]);
        i++;
    }

    return (i);
}
