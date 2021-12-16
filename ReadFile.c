#include <stdio.h>
#include <windows.h>
#include <fileapi.h>

/* Desc: Read from a file https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-readfile
 * Date: 9/20/21
 */

int main() {

	// Open the file
	LPCSTR fName = (LPCSTR) "C:\\temp\\aaa.txt";
	
	DWORD dAccess 		= GENERIC_READ;
	DWORD sMode 		= FILE_SHARE_READ;
	DWORD cDisposition 	= CREATE_ALWAYS;
	DWORD fFlags 		= FILE_ATTRIBUTE_NORMAL;

	HANDLE hFile;

	hFile = CreateFileA(fName,
						dAccess,
						sMode,
						NULL,
						cDisposition,
						fFlags,
						NULL);

	if (hFile == INVALID_HANDLE_VALUE) {
		DWORD error = GetLastError();
		printf("**Error %d**\n", error);
		return error;
	} 

	// Read from the file
	char* fData;
	DWORD nBytes = 2;
	LPDWORD nBytesRead;

	if (!ReadFile(hFile, fData, nBytes, nBytesRead, NULL)) {
		DWORD error = GetLastError();
		printf("**Error %d**\n", error);
		return error;
	}

	printf("%s\n", fData);

	// Close the handle
	DWORD hRet;

	hRet = CloseHandle(hFile);

	if (!hRet) {
		DWORD error = GetLastError();
		printf("**Error Closing Handle %d**\n", error);
		return error;
	}

	return 0;
}