#include <stdio.h>
#include <windows.h>
#include <minwinbase.h>
#include <fileapi.h>

/* Desc: Get file attributes https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getfileattributesa
 * Date: 9/20/21
 */

int main () {
	LPCSTR fName = (LPCSTR)"C:\\temp\\simple.txt";
	
	// Get file attributes only
	// DWORD fAttrs = GetFileAttributesA(fName);
	// if (fAttrs == INVALID_FILE_ATTRIBUTES) {
	// 	DWORD error = GetLastError();
	// 	printf("**Error %d**\n", error);
	// 	return error;
	// }
	// printf("fAttrs=0x%08X\n", fAttrs);
	// if (fAttrs & FILE_ATTRIBUTE_DIRECTORY) {
	// 	printf("Directory\n");
	// }
	// if (fAttrs & FILE_ATTRIBUTE_READONLY) {
	// 	printf("Read-only\n");
	// }
	// if (fAttrs & FILE_ATTRIBUTE_REPARSE_POINT) {
	// 	printf("Reparse point\n");
	// }
	// if (fAttrs & FILE_ATTRIBUTE_ARCHIVE) {
	// 	printf("Archive\n");
	// }

	// Get extended attributes
	WIN32_FILE_ATTRIBUTE_DATA fAttrsEx;
	if(!GetFileAttributesExA(fName, GetFileExInfoStandard, &fAttrsEx)) {
		DWORD error = GetLastError();
		printf("**Error %08X**\n", error);
		return error;
	} 
	printf("FileSize=%d\n", fAttrsEx.nFileSizeLow);
	return 0;
}