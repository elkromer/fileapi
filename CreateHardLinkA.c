#include <stdio.h>
#include <windows.h>
#include <fileapi.h>

/* Create hardlink https://docs.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-createhardlinka
 * A hardlink is a new filesystem object that points to a file on disk. Deleting the original filesystem object and the link will keep working.
 * Date: 9/24/21
 */

int main () {
	LPCSTR fHardlinkName = (LPCSTR)"NewFile";
	LPCSTR fTargetName = (LPCSTR)"NewFile.txt";

	DWORD ret = CreateHardLinkA(fHardlinkName, fTargetName, NULL);

	if (!ret) {
		DWORD error = GetLastError();
		printf("**Error %d**\n", error);
		return error;
	}

	return 0;
}