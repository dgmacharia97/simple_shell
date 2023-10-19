#include "shell_sh.h"

/**
 * tester_chemin - vérifie si le chemin est valide
 * @chemin: chemin tokenisé
 * @commande: commande saisie par l'utilisateur
 *
 * Retour : chemin avec la commande ajoutée en cas de succès
 * NULL en cas d'échec
 */
char *tester_chemin(char **chemin, char *commande)
{
    int i = 0;
    char *resultat;

    while (chemin[i])
    {
        resultat = ajouter_var_env(chemin[i], commande);
        if (access(resultat, F_OK | X_OK) == 0)
            return (resultat);
        free(resultat);
        i++;
    }
    return NULL;
}
