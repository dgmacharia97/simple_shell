#include "shell_sh.h"

/**
 * executeur - exécute les commandes saisies par les utilisateurs
 * @cmd_entree : commande
 * @tab_commande : tableau de vecteurs de pointeurs vers les commandes
 * Retour : 0
 */
void executeur(char *cmd_entree, char **tab_commande)
{
    pid_t child_pid;
    int status;
    char **env = environ;

    child_pid = fork();
    if (child_pid < 0)
        perror(cmd_entree);
    if (child_pid == 0)
    {
        execve(cmd_entree, tab_commande, env);
        perror(cmd_entree);
        free(cmd_entree);
        libere_buffers(tab_commande);
        exit(98);
    }
    else
        wait(&status);
}
