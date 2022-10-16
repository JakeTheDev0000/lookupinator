#include <stdio.h>
#include <string.h>

int displayUsrInfo(int nameID);

int main() {
	char whatNameLookup[30];
	const char *names[] = {
		"jake",
		"richie",
		"emilio",
		"chi",
		"immaculata",
		"lissy",
		"fransico",
		"joey",
		"jason"
	};
	int NAME_CAPT = sizeof names / sizeof names[0];
	int needCheckName = 0;

	while(1) {
		printf("\n\nEnter a name >> ");
		scanf("%s", &whatNameLookup);
		needCheckName = 0;

		if (strcmp(whatNameLookup, "exit") == 0) {
			return 0;
		}
		else if (strcmp(whatNameLookup, "list") == 0) {
			int I_LIST = 0;
			for(I_LIST = 0; I_LIST < NAME_CAPT; I_LIST++) {
				printf("%d - %s\n",I_LIST, names[I_LIST]);
			}
			needCheckName = 1;
			
		}
		
		// I know its a mess down here :/ 
		if (needCheckName == 0){
			int I_NAME_CHECKER = 0;
			for (I_NAME_CHECKER = 0; I_NAME_CHECKER < NAME_CAPT; I_NAME_CHECKER++) {
				if (strcmp(whatNameLookup, names[I_NAME_CHECKER]) == 0) {
					printf("found %s\n", names[I_NAME_CHECKER]);
					displayUsrInfo(I_NAME_CHECKER);
					break;
				}
				else {
					printf("%s is not %s\n", whatNameLookup, names[I_NAME_CHECKER]);
				} // else above
			} // for loop
		} // if needCheckName
	} // while loop


    return 0;
}

int displayUsrInfo(int nameID) {
	printf("%d\n", nameID);
}
