#include <stdio.h>
#include <windows.h>
#include <fileapi.h>

/* Desc: Deletes a file using the fileapi https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-deletefilea
 * Date: 9/20/21
 */

int main() {
	LPCSTR fName = (LPCSTR) "NewFile.txt";

	DWORD ret;

	ret = DeleteFileA(fName);

	if (!ret) {
		DWORD error = GetLastError();
		printf("**Error %d**\n", error);
		return error;
	}

	return 0;
}

void PrintErrors() {
	printf("Errors\n  ERROR_FILE_NOT_FOUND=0x%08x\n  ERROR_ACCESS_DENIED=0x%08x\n", ERROR_FILE_NOT_FOUND, ERROR_ACCESS_DENIED);
}