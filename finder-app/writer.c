#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    // init syslog
    openlog("writer", LOG_PID || LOG_CONS, LOG_USER);

    if(argc != 3){
        fprintf(stderr, "Usage: %s <file path> <string to write>\n", argv[0]);
        closelog();
        return 1;
    }

    char *writeFile = argv[1];
    char *writestr = argv[2];

    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writeFile);

    FILE *fp = fopen(writeFile, "w");

    if(fp == NULL){
        syslog(LOG_ERR, "Failed to open %s for writing", writeFile);
        perror("Error opening file, try again with a valid path");
        closelog();
        fclose(fp);
        return 1;
    }

    if (fputs(writestr, fp) == EOF){
        syslog(LOG_ERR, "Failed to write %s to %s", writestr, writeFile);
        perror("Error writing to file");
        fclose(fp);
        closelog();
        return 1;
    }
    fclose(fp);
    syslog(LOG_INFO, "Successfully written to file");
    closelog();

    return 0;
}