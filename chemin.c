#include "shell_sh.h"

/**
 * trouver_chemin - trouve le chemin dans l'environnement global
 * Retour : NULL si le chemin n'est pas trouvé, sinon le chemin s'il est trouvé.
 */
char *trouver_chemin(void)
{
    int y;
    char **env = environ, *chemin = NULL;

    while (*env)
    {
        if (_strncmp(*env, "PATH=", 5) == 0)
        {
            chemin = *env;
            while (*chemin && y < 5)
            {
                chemin++;
                y++;
            }
            return (chemin);
        }
        env++;
    }
    return (NULL);
}
