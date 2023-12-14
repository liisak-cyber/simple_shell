#ifndef SHELL_H
#define SHELL_H

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

/* environment variables */
extern char **environ;
extern __signhandler_t signal(int __sig, __signhandler_t __handler);

/* handle built-in commands */
int command_checker(char **cmd, char *buf);
void user_prompt(void);
void signal_handler(int m);
char **command_tokenizer(char *line);
char *validate_path(char **path, char *command);
char *modify_path(char *path, char *command);
int execute_builtin(char **command, char *line);
void exit_command(char **command, char *line);


void display_env_info(void);

/* string manipulation functions */
int compare_strings(char *s1, char *s2);
int calculate_string_length(char *s);
int compare_strings_partial(char *s1, char *s2, int n);
char *duplicate_string(char *s);
char *find_character(char *s, char c);

void execute_program(char *cp, char **cmd);
char *retrieve_executable_path(void);

/* memory management function for efficient deallocation */
void release_memory_buffers(char **buf);

struct custom_builtins
{
	char *env_var;
	char *exit_cmd;
} custom_builtins;

struct program_information
{
	int exit_status;
	int line_count;
} program_information;

struct operational_flags
{
	bool is_interactive_mode;
} operational_flags;

#endif /* CUSTOM_SHELL_H */
