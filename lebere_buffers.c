#include "shell_sh.h"

/**
 * libere_buffers - libère les tampons
 * @buffer : tampon à libérer
 *
 * Retour : pas de valeur de retour
 */
void libere_buffers(char **buffer)
{
    int i = 0;

    if (!buffer || buffer == NULL)
        return;
    while (buffer[i])
    {
        free(buffer[i]);
        i++;
    }
    free(buffer);
}
