#include <stdio.h>
#include <windows.h>
#include <fileapi.h>

/* Create directory https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createdirectorya
 * Date: 9/24/21
 */

int main () {
	LPCSTR dName = (LPCSTR) "NewDirectory";

	if (!CreateDirectory(dName, NULL)) {
		DWORD error = GetLastError();
		printf("**Error %d*\n", error);
		return error;
	}

	return 0;
}