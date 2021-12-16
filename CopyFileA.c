#include <stdio.h>
#include <windows.h>
#include <fileapi.h>

/* Create symlink https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createsymboliclinka
 * Date: 9/24/21
 */

int main () {
	LPCSTR fExistingFile = (LPCSTR)"NewFile.txt";
	LPCSTR fNewFile = (LPCSTR)"NewFile2.txt";
	BOOL fOverwrite = 1; // true

	DWORD ret = CopyFileA(fExistingFile, fNewFile, !fOverwrite);

	if (!ret) {
		DWORD error = GetLastError();
		printf("**Error %d**\n", error);
		return error;
	}

	return 0;
}