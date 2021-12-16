#include <stdio.h>
#include <windows.h>
#include <minwinbase.h>
#include <fileapi.h>

/* Desc: Set file attributes https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-setfileattributesa
 * Date: 11/07/21
 */

int main () {
	LPCSTR fName = (LPCSTR)"C:\\temp\\simple.txt";
	
	if (!SetFileAttributesA(fName, FILE_ATTRIBUTE_READONLY)) {
		DWORD error = GetLastError();
		printf("**Error %d**\n", error);
		return error;
	};

	return 0;
}