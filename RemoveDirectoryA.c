#include <stdio.h>
#include <windows.h>
#include <fileapi.h>

/* Remove directory https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-removedirectorya
 * Date: 9/24/21
 */

int main () {
	LPCSTR dName = (LPCSTR) "NewDirectory";
	
	if (!RemoveDirectoryA(dName)) {
		DWORD error = GetLastError();
		printf("**Error %d*\n", error);
		return error;
	}

	return 0;
}