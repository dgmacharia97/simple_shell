#include "shell_sh.h"

int main(int ac, char **av, char *envp[])
{
    char *ligne = NULL, *commande_chemin = NULL, *chemin = NULL;
    size_t taille_buff = 0;
    ssize_t taille_ligne = 0;
    char **commande = NULL, **chemins = NULL;
    (void)envp, (void)av;
    if (ac < 1)
        return (-1);
    signal(SIGINT, constructeur_signal);
    while (1)
    {
        libere_buffers(commande);
        libere_buffers(chemins);
        free(commande_chemin);
        cmd_prompt_user();
        taille_ligne = getline(&ligne, &taille_buff, stdin);
        if (taille_ligne < 0)
            break;
        info.ln_count++;
        if (ligne[taille_ligne - 1] == '\n')
            ligne[taille_ligne - 1] = '\0';
        commande = tokenizeur(ligne);
        if (commande == NULL || *commande == NULL || **commande == '\0')
            continue;
        if (fonction_integre(commande, ligne))
            continue;
        chemin = trouver_chemin();
        chemins = tokenizeur(chemin);
        commande_chemin = tester_chemin(chemins, commande[0]);
        if (!commande_chemin)
            perror(av[0]);
        else
            executeur(commande_chemin, commande);
    }
    if (taille_ligne < 0 && flags.interactive)
        write(STDERR_FILENO, "\n", 1);
    free(ligne);
    return (0);
}
