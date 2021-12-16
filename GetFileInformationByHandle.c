#include <stdio.h>
#include <windows.h>
#include <fileapi.h>

/* Get file information https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfileinformationbyhandle
 * Date: 9/24/21
 */

int main () {
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

	BY_HANDLE_FILE_INFORMATION fInfo;
	DWORD ret = GetFileInformationByHandle(hFile, &fInfo);

	if (!ret) {
		DWORD error = GetLastError();
		printf("**Error %d**\n", error);
		return error;
	}

	printf("HighTimeSince1601=%d\n", fInfo.ftLastAccessTime.dwHighDateTime);

	return 0;
}