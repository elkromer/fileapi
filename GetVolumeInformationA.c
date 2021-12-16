#include <stdio.h>
#include <windows.h>
#include <fileapi.h>

/* Get volume information https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getvolumeinformationa
 * Date: 9/23/21
 */

int main () {
	LPCSTR lRootName 				= (LPCSTR) "G:\\";
	DWORD nVolumeSerial 			= 0;
	DWORD nMaximumComponentLength 	= 0;
	DWORD mFileSystemFlags 			= 0;
	
	char bFileSystemName[MAX_PATH + 1];
	char bVolumeName[MAX_PATH + 1];
	bVolumeName[MAX_PATH + 1]		= '\0';
	bFileSystemName[MAX_PATH + 1] 	= '\0';
	
	DWORD ret = GetVolumeInformationA(lRootName,
									 bVolumeName,
									 MAX_PATH,
									 &nVolumeSerial,
									 &nMaximumComponentLength,
									 &mFileSystemFlags,
									 bFileSystemName,
									 MAX_PATH);

	if (!ret) {
		DWORD error = GetLastError();
		printf("**Error %d**\n", error);
		return error;
	}

	printf("VolumeName=%s\n", bVolumeName);
	printf("VolumeSerial=%d\n", nVolumeSerial);
	printf("FileSystemName=%s\n", bFileSystemName);

	printf("Flags=0x%08X\n", mFileSystemFlags);
	if (mFileSystemFlags & FILE_CASE_PRESERVED_NAMES) {
		printf("  Preserved casing of file names\n");
	}
	if (mFileSystemFlags & FILE_CASE_SENSITIVE_SEARCH) {
		printf("  Case-sensitive file names\n");
	}
	if (mFileSystemFlags & FILE_FILE_COMPRESSION) {
		printf("  File based compression\n");
	}
	if (mFileSystemFlags & FILE_NAMED_STREAMS) {
		printf("  Named streams\n");
	}
	if (mFileSystemFlags & FILE_PERSISTENT_ACLS) {
		printf("  Preserve and enforce ACLs\n");
	}
	if (mFileSystemFlags & FILE_READ_ONLY_VOLUME) {
		printf("  Read-only\n");
	}
	if (mFileSystemFlags & FILE_SEQUENTIAL_WRITE_ONCE) {
		printf("  Single sequential write\n");
	}
	if (mFileSystemFlags & FILE_SUPPORTS_ENCRYPTION) {
		printf("  EFS\n");
	}
	if (mFileSystemFlags & FILE_SUPPORTS_EXTENDED_ATTRIBUTES) {
		printf("  Extended attributes\n");
	}
	if (mFileSystemFlags & FILE_SUPPORTS_HARD_LINKS) {
		printf("  Hard links\n");
	}
	if (mFileSystemFlags & FILE_SUPPORTS_OBJECT_IDS) {
		printf("  Object identifiers\n");
	}
	if (mFileSystemFlags & FILE_SUPPORTS_OPEN_BY_FILE_ID) {
		printf("  Open by file ID\n");
	}
	if (mFileSystemFlags & FILE_SUPPORTS_REPARSE_POINTS) {
		printf("  Reparse points\n");
	}
	if (mFileSystemFlags & FILE_SUPPORTS_SPARSE_FILES) {
		printf("  Sparse files\n");
	}
	if (mFileSystemFlags & FILE_SUPPORTS_TRANSACTIONS) {
		printf("  KTM transactions\n");
	}
	if (mFileSystemFlags & FILE_SUPPORTS_USN_JOURNAL) {
		printf("  USN journals\n");
	}
	if (mFileSystemFlags & FILE_VOLUME_IS_COMPRESSED) {
		printf("  Is compressed\n");
	}
	if (mFileSystemFlags & FILE_VOLUME_QUOTAS) {
		printf("  Disk quotas\n");
	}
	if (mFileSystemFlags & FILE_UNICODE_ON_DISK) {
		printf("  Unicode in filenames on disk\n");
	}
	return 0;
}
