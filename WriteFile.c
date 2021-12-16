#include <stdio.h>
#include <windows.h>
#include <fileapi.h>

/* Desc: Write to a file https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-writefile
 * Date: 9/20/21
 */

int main() {

	// Open the file
	LPCSTR fName = (LPCSTR) "NewFile.txt";
	
	DWORD dAccess 		= GENERIC_WRITE;
	DWORD sMode 		= FILE_SHARE_WRITE;
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
	
	// Write to the file
	const char fData[] = "Hello world";

	DWORD status;
	DWORD nBytes = 11;
	LPDWORD nBytesWritten;

	status = WriteFile(hFile,
						fData,
						nBytes,
						nBytesWritten,
						NULL);
	
	if (!status) {
		DWORD error = GetLastError();
		printf("**Error %d**\n", error);
		return error;
	}


	// Close the handle
	hRet = CloseHandle(hFile);

	if (!hRet) {
		DWORD error = GetLastError();
		printf("**Error Closing Handle %d**\n", error);
		return error;
	}

	return 0;
}