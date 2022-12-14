#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "delay.h"
#include "UsrInfoMgr.h"

int displayUsrInfo(char *name);
char *IDtoName(char *ID);
void delay(int number_of_seconds);

/* in_stable codes
	 0: DEV
	 1: stable
	 2: beta
	>3: unknown
*/
const int in_stable = 2;
const char *VERSION = "0.8.6";
const char *names[] = {
        "jake",
        "richie",
        "emilio",
        "chi",
        "immaculata",
        "lissy",
        "fransico",
        "joey",
        "jason",
        "william",
		"Mother",
		"Father"
};

int NAME_CAPT = sizeof names / sizeof names[0];

int os_id = 0;

int main() {
	#ifdef _WIN32
	    printf("Windows\n");
		os_id = 0;
	#elif __linux__
	    printf("Linux\n");
		os_id = 1;
	#elif __unix__
	    printf("Other unix OS\n");
		os_id = 1;
	#else
	    printf("Unidentified OS\n");
		os_id = 2;
	#endif

	char whatNameLookup[30];

	// should be reversed
	int needCheckName = 0;

	// main loop (Like an game loop)
	while(1) {
		printf("\nEnter a name/command >> ");
		scanf("%s", whatNameLookup);
		needCheckName = 0;


		// converts "whatNameLookup" tolower so it can reduce the amount of errors
		int j = 0;
		while (whatNameLookup[j]) {
			whatNameLookup[j] = tolower(whatNameLookup[j]);
			j++;
		}


		if (strcmp(whatNameLookup, "exit") == 0) {
			printf("Laters\n");
			return 0;
		}
		else if ((strcmp(whatNameLookup, "list") == 0) || (strcmp(whatNameLookup, "ls") == 0)) {
			int I_LIST = 0;
			for(I_LIST = 0; I_LIST < NAME_CAPT; I_LIST++) {
				printf("%d - %s\n",I_LIST, names[I_LIST]);
			}
			needCheckName = 1;
		}
		else if ((strcmp(whatNameLookup, "clear") == 0) || (strcmp(whatNameLookup, "cls") == 0)) {
			printf("clearing...\n");
			system("clear");
			needCheckName = 1;
		}
		else if (strcmp(whatNameLookup, "_ver") == 0) {
			printf("Lookupinator %s\n", VERSION);
			if (in_stable == 1) {
				printf("In stable build");
			}
			else if (in_stable == 0) {
				printf("In Dev build");
			}
			else if (in_stable == 2) {
				printf("In beta build");
			}
			else {
				printf("In unknown build");
			}

			needCheckName = 1;
		}
		// lists the LPF (Lookupinator People Files)
		else if (strcmp(whatNameLookup, "lpf") == 0) {
			listLPF();

			needCheckName = 1;
		}


		// I know it's a mess down here :/
		if (needCheckName == 0){

			int USE_ID = 0;

			// starts to check if the command is requesting to use an ID and if so seporate and just get the value
			printf("Checking for ID\n\n");
			int DASH_COUNTER = 0;
			// int I_ID_NAME_CHECKER = 0;
			char *ID_TOKEN = strtok(whatNameLookup, "-");
			if (strcmp(ID_TOKEN, "id") == 0) {
				while (ID_TOKEN != NULL) {
					printf("%s\n", ID_TOKEN);
					if (DASH_COUNTER == 0) {
        				ID_TOKEN = strtok(NULL, "-");
					}
					else if (DASH_COUNTER == 2) {
						break;
					}
					DASH_COUNTER++;
				}
				USE_ID = 1;

			}

			printf("ID : %s\n", ID_TOKEN);

			if (USE_ID == 1) {
				printf("Yes ID\nchecking Identifiers\n");
                displayUsrInfo(IDtoName(ID_TOKEN));
			}
			else {
				printf("No ID\nchecking names\n");
				int I_NAME_CHECKER = 0;
				for (I_NAME_CHECKER = 0; I_NAME_CHECKER < NAME_CAPT; I_NAME_CHECKER++) {
					if (strcmp(whatNameLookup, names[I_NAME_CHECKER]) == 0) {
						printf("found %s\n", names[I_NAME_CHECKER]);
                        char a[20];
                        sprintf(a, "%d", I_NAME_CHECKER);
						displayUsrInfo(IDtoName(a));
						break;
					}
					else {
						printf("%s is not %s\n", whatNameLookup, names[I_NAME_CHECKER]);
					} // else above
				} // for loop
			} // checking if useing ID
		} // if needCheckName
	} // while loop


    return 0;
}

// char str[ENOUGH];
// sprintf(str, "%d", 42);
char *IDtoName(char *ID) {
	printf("converting ID to name...\n");
	int FORI = 0;
	char TEMP_NUM_STR[10];
	for (FORI = 0; FORI < NAME_CAPT; FORI++) {
		sprintf(TEMP_NUM_STR, "%d", FORI);
		if (strcmp(ID, TEMP_NUM_STR) == 0) {
			printf("successfully converted ID to name\n");
        	return (unsigned char *)names[FORI]; // just leave it... i dont know why its red :/
    	}
	}
}

