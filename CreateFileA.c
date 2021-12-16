#include <stdio.h>
#include <windows.h>
#include <fileapi.h>

/* Desc: Creates a file using the fileapi https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilea
 * Date: 9/20/21
 */

int main() {
	
	LPCSTR fName = (LPCSTR) "NewFile.txt";
	
	DWORD dAccess 		= GENERIC_WRITE;
	DWORD sMode 		= FILE_SHARE_WRITE;
	DWORD cDisposition 	= CREATE_ALWAYS;
	DWORD fFlags 		= FILE_ATTRIBUTE_NORMAL;

	HANDLE hFile = CreateFileA(fName,
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

	DWORD hRet = CloseHandle(hFile);

	if (!hRet) {
		DWORD error = GetLastError();
		printf("**Error Closing Handle %d**\n", error);
		return error;
	}

	return 0;
}

void PrintConstants() {
	printf("Access Rights\n  GENERIC_ALL=0x%X\n  GENERIC_EXECUTE=0x%X\n  GENERIC_WRITE=0x%08x\n  GENERIC_READ=0x%X\n", GENERIC_ALL, GENERIC_EXECUTE, GENERIC_WRITE, GENERIC_READ);
}