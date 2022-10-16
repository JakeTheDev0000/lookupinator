#include <stdio.h>
#include <string.h>

int main() {
	char whatNameLookup[30];
	const char *names[] = {
		"jake",
		"richie",
		"emilio"
	};
	int NAME_CAPT = sizeof names / sizeof names[0];

	while(1) {
		printf("Enter a name >> ");
		scanf("%s", &whatNameLookup);

		int I_NAME_CHECKER = 0;
		for (I_NAME_CHECKER = 0; I_NAME_CHECKER < NAME_CAPT; I_NAME_CHECKER++) {
			if (strcmp(whatNameLookup, names[I_NAME_CHECKER]) == 0) {
				printf("found %s\n", names[I_NAME_CHECKER]);
			}
			else {
				printf("%s is not %s\n", whatNameLookup, names[I_NAME_CHECKER]);
			}
		}
	}


    return 0;
}

void displayUsrInfo() {

}
