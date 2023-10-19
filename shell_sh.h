#ifndef SHELL_SH_H
#define SHELL_SH_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>

int fonction_integre(char **cmd, char *buf);
void cmd_prompt_user(void);
void constructeur_signal(int m);
char **tokenizeur(char *line);
char *tester_chemin(char **path, char *command);
char *ajouter_var_env(char *path, char *command);
int constructeur(char **command, char *line);
void cmd_exit(char **command, char *line);

void afficher_env(void);

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);

void executeur(char *cmd_entree, char **tab_commande);
char *trouver_chemin(void);

void libere_buffers(char **buffer);

extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

struct builtin
{
    char *env;
    char *exit;
} builtin;

struct info
{
    int final_exit;
    int ln_count;
} info;

struct flags
{
    bool interactive;
} flags;

#endif
