#include <stdio.h>
#include <windows.h>
#include <fileapi.h>

/* Move file https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-movefilea
 * Date: 9/24/21
 */

int main () {
	// Directory example
	LPCSTR fSourceName = (LPCSTR)"NewDirectory";
	LPCSTR fNewName = (LPCSTR)"MaggieIsABadKitty";

	DWORD ret = MoveFileA(fSourceName, fNewName);

	if (!ret) {
		DWORD error = GetLastError();
		printf("**Error %d**\n", error);
		return error;
	}

	// File example
	LPCSTR fSourceFileName = (LPCSTR)"NewFile.txt";
	LPCSTR fNewFileName = (LPCSTR)"MandyWillDoAMurder.jpg";

	DWORD ret2 = MoveFileA(fSourceFileName, fNewFileName);

	if (!ret2) {
		DWORD error = GetLastError();
		printf("**Error %d**\n", error);
		return error;
	}

	return 0;
}