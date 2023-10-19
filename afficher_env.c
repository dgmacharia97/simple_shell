#include "shell_sh.h"


/**
 * afficher_env - affiche la chaîne d'environnement sur stdout
 *
 * Retour : 0
 */
void afficher_env(void)
{
    int y = 0;
    char **env = environ;

    while (env[y])
    {
        write(STDOUT_FILENO, (const void *)env[y], _strlen(env[y]));
        write(STDOUT_FILENO, "\n", 1);
        y++;
    }
}
