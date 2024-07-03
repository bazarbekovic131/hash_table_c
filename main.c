//
//  main.c
//  memory_allocator
//
//  Created by Akha on 03.07.2024.
//

#include <stdio.h> // fprintf, printf, stderr, getchar, perror
#include <stdlib.h> // allocators, exit statuses
#include <string.h> // string funcs: strcmp, strtok
#include <sys/wait.h> // waitpid() function
#include <unistd.h> // chdir, fork, exec functions, pid_tt typedef

// this doesn't work

//#define LSH_RL_BUFSIZE 1024
//char* lsh_read_line(void) {
//    int bufsize = LSH_RL_BUFSIZE;
//    int pos = 0;
//    char* buffer = malloc(sizeof(char) * bufsize);
//    int c;
//    
//    if(!buffer) {
//        fprintf(stderr, "lsh: allocation error!\n");
//        exit(EXIT_FAILURE);
//    }
//    
//    while (1) {
//        c = getchar();
//        if (c== EOF || c == '\n') {
//            buffer[pos] = '\0';
//            return buffer;
//        }
//        else {
//            buffer[pos] = c;
//        }
//        pos++;
//        
//        if (pos >= bufsize) {
//            bufsize += LSH_RL_BUFSIZE;
//            buffer = realloc(buffer, bufsize);
//            if(!buffer) {
//                fprintf(stderr, "lsh: allocation error!\n");
//                exit(EXIT_FAILURE);
//            }
//        }
//    }
//}
//
//#define LSH_TOKEN_BUFSIZE 64
//#define LSH_TOKEN_DELIMITER " \t\r\n\a"
//char **lsh_split_line(char* line) {
//    int bufsize = LSH_TOKEN_BUFSIZE;
//    int pos = 0;
//    
//    char** tokens = malloc(sizeof(char*) * bufsize);
//    char* token;
//    
//    if (!tokens) {
//        fprintf(stderr, "lsh: allocation error!\n");
//        exit(EXIT_FAILURE);
//    }
//    
//    token = strtok(line, LSH_TOKEN_DELIMITER);
//    while(token != NULL ) {
//        tokens[pos] = token;
//        pos++;
//        
//        if (pos >= bufsize) {
//            bufsize += LSH_TOKEN_BUFSIZE;
//            tokens = realloc(tokens, bufsize);
//            
//            if (!tokens) {
//                fprintf(stderr, "lsh: allocation error!\n");
//                exit(EXIT_FAILURE);
//            }
//        }
//    }
//    tokens[pos] = NULL;
//    return tokens;
//}
//
//
///*
//  Function Declarations for builtin shell commands:
// */
//int lsh_cd(char **args);
//int lsh_help(char **args);
//int lsh_exit(char **args);
//
///*
//  List of builtin commands, followed by their corresponding functions.
// */
//
//char *builtin_str[] = {
//    "cd",
//    "help",
//    "exit"
//};
//
//int (*builtin_func[]) (char **) = {
//    &lsh_cd,
//    &lsh_help,
//    &lsh_exit
//};
//
//int lsh_num_builtins(void) {
//    return sizeof(builtin_str) / sizeof(char *);
//}
//
///*
//  Builtin function implementations.
//*/
//int lsh_cd(char **args)
//{
//    if (args[1] == NULL) {
//        fprintf(stderr, "lsh: expected argument to \"cd\"\n");
//    } else {
//        if (chdir(args[1]) != 0) {
//          perror("lsh");
//        }
//    }
//    return 1;
//}
//
//int lsh_help(char **args)
//{
//    int i;
//    printf("Stephen Brennan's LSH\n");
//    printf("Type program names and arguments, and hit enter.\n");
//    printf("The following are built in:\n");
//
//    for (i = 0; i < lsh_num_builtins(); i++) {
//    printf("  %s\n", builtin_str[i]);
//    }
//
//    printf("Use the man command for information on other programs.\n");
//    return 1;
//}
//
//int lsh_exit(char **args)
//{
//    return 0;
//}
//
//
//int lsh_launch(char** args) {
//    pid_t pid, wpid;
//    int status;
//
//    pid = fork();
//    if (pid == 0) {
//        // Child process
//        if (execvp(args[0], args) == -1) {
//          perror("lsh");
//        }
//        exit(EXIT_FAILURE);
//    } else if (pid < 0) {
//        // Error forking
//        perror("lsh");
//    } else {
//        // Parent process
//        do {
//          wpid = waitpid(pid, &status, WUNTRACED);
//        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
//    }
//
//    return 1;
//}
//
//int lsh_execute(char** args) {
//    int i;
//    
//    if (args[0] == NULL) {
//        return 1;
//    }
//    
//    for ( i = 0; i < lsh_num_builtins(); i++) {
//        if (strcmp(args[0], builtin_str[i]) == 0) {
//            return (*builtin_func[i])(args);
//        }
//    }
//    
//    return lsh_launch(args);
//}
//
//
//void loop_lsh(void) {
//    char* line;
//    char **args;
//    int status;
//    
//    do {
//        printf(">0 ");
//        line = lsh_read_line();
//        args = lsh_split_line(line);
//        status = lsh_execute(args);
//        
//        free(line);
//        free(args);
//    } while (status);
//}



#include "hash_table.h"
#include "prime.h"

int main(int argc, const char * argv[]) {
    // load config
    // run command loop
    // loop_lsh();
    // perform shutdown/cleanup
    
    
    
    return EXIT_SUCCESS;
}

