# NetDfsGetInfo function

## Description

Retrieves information about a specified Distributed File System (DFS) root or link in a DFS namespace.

## Parameters

### `DfsEntryPath` [in]

Pointer to a string that specifies the Universal Naming Convention (UNC) path of a DFS root or link.

For a link, the string can be in one of two forms. The first form is as follows:

\\*ServerName*\*DfsName*\*link_path*

where *ServerName* is the name of the root target server that hosts the stand-alone
DFS namespace; *DfsName* is the name of the DFS namespace; and
*link_path* is a DFS link.

The second form is as follows:

\\*DomainName*\*DomDfsname*\*link_path*

where *DomainName* is the name of the domain that hosts the domain-based DFS
namespace; *DomDfsname* is the name of the DFS namespace; and
*link_path* is a DFS link.

For a root, the string can be in one of two forms:

\\*ServerName*\*DfsName*

or

\\*DomainName*\*DomDfsname*

where the values of the names are the same as those described previously.

This parameter is required.

### `ServerName` [in, optional]

This parameter is currently ignored and should be **NULL**.

### `ShareName` [in, optional]

This parameter is currently ignored and should be **NULL**.

### `Level` [in]

Specifies the information level of the request. This parameter can be one of the following values.

#### 1

Return the DFS root or DFS link name. The *Buffer* parameter points to a
[DFS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_1) structure.

#### 2

Return the DFS root or DFS link name, status, and the number of DFS targets. The
*Buffer* parameter points to a
[DFS_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_2) structure.

#### 3

Return the DFS root or DFS link name, status, and target information. The
*Buffer* parameter points to a
[DFS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_3) structure.

#### 4

Return the DFS root or DFS link name, status, GUID, time-out, and target information. The
*Buffer* parameter points to a
[DFS_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_4) structure.

#### 5

Return the name, status, **GUID**, time-out, property flags, metadata size, and number of targets for a DFS
root and all links under the root. The *Buffer* parameter points to an array of
[DFS_INFO_5](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_5) structures.

#### 6

Return the name, status, **GUID**, time-out, property flags, metadata size, DFS target information for a root
or link, and a list of DFS targets. The *Buffer* parameter points to an array of
[DFS_INFO_6](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_6) structures.

#### 7

Return the version number **GUID** of the DFS metadata. The *Buffer* parameter points
to an array of [DFS_INFO_7](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_7) structures.

#### 8

Return the name, status, **GUID**, time-out, property flags, metadata size, number of targets, and link reparse
point security descriptors for a DFS root and all links under the root. The *Buffer*
parameter points to an array of [DFS_INFO_8](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_8) structures.

#### 9

Return the name, status, **GUID**, time-out, property flags, metadata size, DFS target information, link
reparse point security descriptors, and a list of DFS targets for a root or link. The
*Buffer* parameter points to an array of
[DFS_INFO_9](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_9) structures.

#### 50

Return the DFS metadata version and capabilities of an existing DFS namespace. The
*Buffer* parameter points to a
[DFS_INFO_50](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_50) structure.

#### 100

Return a comment about the DFS root or DFS link. The *Buffer* parameter points to
a [DFS_INFO_100](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_100) structure.

#### 150

Return the security descriptor for the DFS link's reparse point. The *Buffer*
parameter points to a [DFS_INFO_150](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_150) structure.

**Note** This value is natively supported only if the DFS link resides on a server that is running
Windows Server 2008 or later.

### `Buffer` [out]

Pointer to the address of a buffer that receives the requested information structures. The format of this
data depends on the value of the *Level* parameter. This buffer is allocated by the
system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. For more information,
see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers)
and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

No special group membership is required for using the
**NetDfsGetInfo** function.

An application calling the **NetDfsGetInfo** function may
indirectly cause the local DFS Namespace server servicing the function call to perform a full synchronization of
the related namespace metadata from the PDC emulator master for that domain. This full synchronization could
happen even when root scalability mode is configured for that namespace. In order to avoid this side-effect, if
the intent is to only retrieve the physical UNC pathname used by a specific DFSN client machine corresponding a
given DFS namespace path, then one alternative is to use the WDK API
[ZwQueryInformationFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/nf-ntifs-ntqueryinformationfile), passing
**FileNetworkPhysicalNameInformation** as the
*FileInformationClass* parameter and passing the address of a caller-allocated
[FILE_NETWORK_PHYSICAL_NAME_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/ntifs/ns-ntifs-_file_network_physical_name_information)
structure as the *FileInformation* parameter. Please see the WDK for more information on
calling WDK APIs.

#### Examples

The following code sample demonstrates how to retrieve information about a DFS link using a call to the
**NetDfsGetInfo** function. The sample calls
**NetDfsGetInfo**, specifying information level 3
([DFS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_3)). If the call succeeds, the
sample prints information about the DFS link, including the name and status of each target referenced by the
link. Finally, the code sample frees the memory allocated for the information buffer.

```cpp
#include <windows.h>
#include <lm.h>
#include <lmdfs.h>
#include <stdio.h>
#pragma comment(lib, "Netapi32.lib")

void wmain(int argc, wchar_t *argv[ ])
{
   PDFS_INFO_3 pData;
   PDFS_STORAGE_INFO ps;
   DWORD er = 0, tr = 0, res, j;

   //
   // Check command line arguments.
   //
   if (argc<2)
      wprintf(L"Syntax: %s DfsEntryPath\n", argv[0]);
   else
   {
      //
      // Call the NetDfsGetInfo function, specifying level 3.
      //
      res = NetDfsGetInfo(argv[1], NULL, NULL, 3, (LPBYTE *) &pData);
      //
      // If the call succeeds, print the data.
      //
      if(res==0)
      {
         printf("%-30S Storages: %u\nComment: %S\n", pData->EntryPath, pData->NumberOfStorages, pData->Comment);
         ps = pData->Storage;
         //
         // Loop through each target.
         //
         for(j = 1; j <= pData->NumberOfStorages;j++)
         {
            //
            // Print the status (Offline/Online) and the name
            // of each target referenced by the DFS link.
            //
            printf("    %S  ", (ps->State == DFS_STORAGE_STATE_OFFLINE) ? TEXT("Offline"): TEXT("Online "));
            printf("\\\\%S\\%S\n", ps->ServerName, ps->ShareName);
            ps++;
         }
         //
         // Free the allocated memory.
         //
         NetApiBufferFree(pData);
      }
      else
         printf("Error: %u\n", res);
   }
   return;
}

```

## See also

[DFS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_1)

[DFS_INFO_100](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_100)

[DFS_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_2)

[DFS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_3)

[DFS_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_4)

[DFS_INFO_5](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_5)

[DFS_INFO_6](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_6)

[DFS_INFO_7](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_7)

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsEnum](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsenum)

[Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)