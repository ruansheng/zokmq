#include<getopt.h>

char* const short_options = "vdhs:p:c:";

struct option long_options[] = {
    {"version", 0, NULL, 'v'},
    {"daemon", 0, NULL, 'd'},
    {"server", 1, NULL, 's'},
    {"port", 1, NULL, 'p'},
    {"config", 0, NULL, 'c'},
    {"help", 0, NULL, 'h'}
};
