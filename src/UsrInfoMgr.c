#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "delay.h"

// /home/messycode/lookupinator/peopleFiles

char *homeDir();
// there is probbaly a better way todo this....
int displayUsrInfo(char *name) {
	printf("%s\n", name);
    delay(1.5);
    // system("clear");
    printf("Catched Home: %s\n", homeDir());

    char peopleFiles_dataDir[80];
    char catPFDcmd[80];
    strcpy(peopleFiles_dataDir, homeDir());
    strcat(peopleFiles_dataDir, "/lookupinator/peopleFiles/");

    printf("Varible Home -- LPF : %s\n", peopleFiles_dataDir);

    strcat(peopleFiles_dataDir, name);
    strcat(peopleFiles_dataDir, ".txt");

    printf("LPF.txt location : %s\n", peopleFiles_dataDir);
    printf("Working on Command to READ LPF\n");

    strcpy(catPFDcmd, "cat ");
    strcat(catPFDcmd, peopleFiles_dataDir);    

    printf("DONE\nCOMMAND: %s\n", catPFDcmd);

    printf("\n\n");
    system(catPFDcmd);
    printf("\n\n");

    
}

void listLPF() {
    // copy code from above
    printf("Catched Home: %s\n", homeDir());

    char peopleFiles_dataDir[80];
    char commandToExec[80];
    strcpy(peopleFiles_dataDir, homeDir());
    strcat(peopleFiles_dataDir, "/lookupinator/peopleFiles/");

    printf("Varible Home -- LPF : %s\n", peopleFiles_dataDir);

    strcpy(commandToExec, "ls -l ");
    strcat(commandToExec, peopleFiles_dataDir);

    printf("Command: %s\n\n", commandToExec);
    system(commandToExec);
}


/* 
    char str[80];
    strcpy(str, "these ");
    strcat(str, "strings ");
    strcat(str, "are ");
    strcat(str, "concatenated.");
*/

char *homeDir() {
    #include <unistd.h>
    #include <pwd.h>
    #include <sys/types.h>

    char *homedir = getenv("HOME");

    uid_t uid = getuid();
    struct passwd *pw = getpwuid(uid);

    if (pw == NULL) {
        printf("Failed\n");
        exit(EXIT_FAILURE);
    }

    return pw->pw_dir;
}
