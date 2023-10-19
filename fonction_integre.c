#include "shell_sh.h"

/**
 * fonction_integre - vérifie s'il s'agit d'une fonction intégrée
 * @commande : entrée utilisateur tokenisée
 * @buffer : ligne obtenue à partir de la fonction getline
 * Retour : 1 si la commande est exécutée, 0 si la commande n'est pas exécutée
 */
int fonction_integre(char **commande, char *buffer)
{
    if (constructeur(commande, buffer))
        return (1);
    else if (**commande == '/')
    {
        executeur(commande[0], commande);
        return (1);
    }
    return (0);
}
