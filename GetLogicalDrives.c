#include <stdio.h>
#include <windows.h>
#include <fileapi.h>

/* Get logical drives https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getlogicaldrives
 * Date: 9/23/21
 */

int main () {
	DWORD lDrives;

	lDrives = GetLogicalDrives();

	if (!lDrives) {
		DWORD error = GetLastError();
		printf("**Error %d**\n", error);
		return error;
	}

	printf("Drives=0x%08X\n", lDrives);
	
	DWORD start = 1;
	DWORD amount = 3;
	DWORD result = start << amount;
	printf("%d << %d = %d\n", start, amount, result);

	for (int i = 0; i < 26; i++) {
		if (lDrives & (1 << i)) {
			char dName[] = { (TEXT('A') + i), '\0' };
			printf("%s\n", dName);
		}
	}

	return 0;
}