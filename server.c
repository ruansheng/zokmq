#include<stdio.h>

#include"server.h"
#include"opt.h"
#include"version.h"

void usage() {
    fprintf(stderr, "Usage: ./zokmq-server -v or --version\n");
    fprintf(stderr, "       ./zokmq-server -h or --help\n");
    fprintf(stderr, "       ./zokmq-server -d or --daemon\n");
    fprintf(stderr, "       ./zokmq-server -s 127.0.0.1  or --server 127.0.0.1\n");
    fprintf(stderr, "       ./zokmq-server -p 1919  or --port 1919\n");
    fprintf(stderr, "       ./zokmq-server -c /zokmq.conf  or --config /zokmq.conf\n");
    exit(1);
}

void version() {
    printf("zokmq server version:%s\n", ZOKMQ_VERSION);
    exit(1);
}

void parseArgv(int argc, char *argv[]) {
    char* ip;
    char* port;
    char* config;

    int c;
    while((c = getopt_long(argc, argv, short_options, long_options, NULL)) != -1) {
	switch(c) {
	    case 'v':	
		version();
		break;
	    case 'd':
		printf("d\n");
		break;
	    case 'h':
		usage();	
		break;
	    case 's':
		ip = optarg;
		printf("s:%s\n", ip);
		break;
	    case 'p':
		port = optarg;
		printf("p:%s\n", port);
		break;
	    case 'c':
		config = optarg;
		printf("c:%s\n", config);
		break;	
	    default:
		usage();
		break;	
	}
    }
}

void daemonMode() {
    pid_t process_id = 0;
    pid_t sid =0;

    process_id = fork();
    
    if (process_id < 0) {
	printf("fork failed!n");
        exit(1);
    }

    if (process_id > 0) {
	printf("process_id of child process %d \n", process_id);
	exit(0);
    }

    umask(0);

    sid = setsid();

    if(sid < 0) {
	exit(1);
    }

    chdir("/");
    
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}

int main(int argc, char *argv[]) {
    parseArgv(argc, argv);

    daemonMode();

    while(1) {
	sleep(1);
    }

    return 0;
}

