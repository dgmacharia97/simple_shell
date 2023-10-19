#include "shell_sh.h"

/**
 * cmd_prompt_user - affiche $ pour indiquer à l'utilisateur que le programme est
 * prêt à recevoir son entrée
 * affiche le prompt si le shell est en mode interactif
 * Retour : pas de valeur de retour
 */
void cmd_prompt_user(void)
{
    if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
        flags.interactive = 1;
    if (flags.interactive)
        write(STDERR_FILENO, "$ ", 2);
}
