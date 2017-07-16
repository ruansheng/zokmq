#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/stat.h>

#define SERVER "127.0.0.1"
#define PORT 1919

/** zokmq server*/
typedef struct {
    int port;  // port
    long host;  // ip long
    int run_mode; // run mode
    char *config_file; // config file
    struct timeval start_tv; // start time
} server;

/**zokmq cxt*/
typedef struct {
    int port;
    long host;  // 
    struct timeval tv; // time
} ctx;



