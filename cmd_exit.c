#include "shell_sh.h"

/**
 * cmd_exit - gère la commande exit
 * @commande : commande tokenisée
 * @ligne : entrée lue depuis stdin
 *
 * Retour : pas de valeur de retour
 */
void cmd_exit(char **commande, char *ligne)
{
	free(ligne);
	libere_buffers(commande);
	exit(0);
}
