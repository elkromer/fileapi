#include <stdio.h>
#include <windows.h>
#include <fileapi.h>

/* Get disk free space https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-getdiskfreespacea
 * Date: 9/24/21
 */

int main () {
	LPCSTR dRoot 				= (LPCSTR) "C:\\";
	DWORD nSectorsPerCluster 	= 0;
	DWORD nBytesPerSector 		= 0;
	DWORD nFreeClusters 		= 0;
	DWORD nTotalClusters 		= 0;

	DWORD ret = GetDiskFreeSpaceA(dRoot,
								  &nSectorsPerCluster,
								  &nBytesPerSector,
								  &nFreeClusters,
								  &nTotalClusters);
	
	if (!ret) {
		DWORD error;
		printf("**Error %d**\n");
		return error;
	}

	printf("SectorsPerCluster=%d\n", nSectorsPerCluster);
	printf("BytesPerSector=%d\n", nBytesPerSector);
	printf("FreeClusters=%d\n", nFreeClusters);
	printf("TotalClusters=%d\n", nTotalClusters);
	return 0;
}