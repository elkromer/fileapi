#include <stdio.h>
#include <windows.h>
#include <fileapi.h>

/* Create symlink https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createsymboliclinka
 * Symlink is a new filesystem object that points to another filesystem object. Delete the original filesystem object and the link breaks.
 * Date: 9/24/21
 */

int main () {
	LPCSTR fSymlinkName = (LPCSTR)"NewFile";
	LPCSTR fTargetName = (LPCSTR)"NewFile.txt";
	DWORD fFlags = 2;

	DWORD ret = CreateSymbolicLinkA(fSymlinkName, fTargetName, fFlags);

	if (!ret) {
		DWORD error = GetLastError();
		printf("**Error %d**\n", error);
		return error;
	}

	return 0;
}