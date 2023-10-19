#include "shell_sh.h"

/**
 * constructeur - gère l'exécution des fonctions intégrées
 * @commande : commandes tokenisées
 * @ligne : entrée lue depuis stdin
 *
 * Retour : 1 si exécuté, 0 sinon
 */
int constructeur(char **commande, char *ligne)
{
    struct builtin builtin = {"env", "exit"};

    if (_strcmp(*commande, builtin.env) == 0)
    {
        afficher_env();
        return (1);
    }
    else if (_strcmp(*commande, builtin.exit) == 0)
    {
        cmd_exit(commande, ligne);
        return (1);
    }
    return (0);
}
