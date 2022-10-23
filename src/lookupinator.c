#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int displayUsrInfo(char *name);
void testEnv();
char *IDtoName(char *ID);

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
        "_FILLER_"
};
int NAME_CAPT = sizeof names / sizeof names[0];

int main() {

	//testEnv();

	char whatNameLookup[30];



	int needCheckName = 0;

	while(1) {
		printf("\n\nEnter a name/command >> ");
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
		else if (strcmp(whatNameLookup, "list") == 0) {
			int I_LIST = 0;
			for(I_LIST = 0; I_LIST < NAME_CAPT; I_LIST++) {
				printf("%d - %s\n",I_LIST, names[I_LIST]);
			}
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
                printf("%s", IDtoName(ID_TOKEN));
//                displayUsrInfo(IDtoName(ID_TOKEN));


//				int I_ID_CHECKER = 0;
//				for (I_ID_CHECKER = 0; I_ID_CHECKER < NAME_CAPT; I_ID_CHECKER++) {
//					if (strcmp(ID_TOKEN, names[I_ID_CHECKER]) == 0) {
//						printf("found %s\n", names[I_ID_CHECKER]);
//						displayUsrInfo(I_ID_CHECKER);
//						break;
//					}
//					else {
//						printf("%s is not %s\n", ID_TOKEN, names[I_ID_CHECKER]);
//					} // else above
//				} // for loop
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

int displayUsrInfo(char *name) {
	printf("%s\n", name);
}

// yes, yes, i know, its the worst code to worldkind, that's why im called messycode
char *IDtoName(char *ID) {
    if (strcmp(ID, "0") == 0) {
        return (unsigned char *)names[0];
    }
    if (strcmp(ID, "1") == 0) {
        return (unsigned char *)names[1];
    }
    if (strcmp(ID, "2") == 0) {
        return (unsigned char *)names[2];
    }
    if (strcmp(ID, "3") == 0) {
        return (unsigned char *)names[3];
    }
    if (strcmp(ID, "4") == 0) {
        return (unsigned char *)names[4];
    }
    if (strcmp(ID, "5") == 0) {
        return (unsigned char *)names[5];
    }
    if (strcmp(ID, "6") == 0) {
        return (unsigned char *)names[6];
    }
    if (strcmp(ID, "7") == 0) {
        return (unsigned char *)names[7];
    }
    if (strcmp(ID, "8") == 0) {
        return (unsigned char *)names[8];
    }
    if (strcmp(ID, "9") == 0) {
        return (unsigned char *)names[9];
    }
    if (strcmp(ID, "10") == 0) {
        return (unsigned char *)names[10];
    }
}

// testEnv() is a test function to test C code, it will exit when its done exit
// DO NOT PUT THIS IN PRODUCTION, DON'T FORGET THIS TIME
void testEnv() {

	exit(0);
}


