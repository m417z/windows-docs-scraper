# NetDfsEnum function

## Description

Enumerates the Distributed File System (DFS) namespaces hosted on a server or DFS links of a namespace hosted by
a server.

## Parameters

### `DfsName` [in]

Pointer to a string that specifies the Universal Naming Convention (UNC) path of the DFS root or link.

When you specify information level 200
([DFS_INFO_200](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_200)), this parameter is the name of a
domain. When you specify information level 300
([DFS_INFO_300](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_300)), this parameter is the name of a
server.

For all other levels, the string can be in one of the following four forms:

*ServerName*\*DfsName*

or

*ServerName*\*DfsName*\*link_path*

where *ServerName* is the name of the root target server that hosts the stand-alone
DFS namespace; *Dfsname* is the name of the DFS namespace; and
*link_path* is a DFS link.

The string can also be of the following forms:

*DomainName*\*DomainName\DomDfsName*

or

*DomainName*\*DomDfsName*\*link_path*

where *DomainName* is the name of the domain that hosts the domain-based DFS root;
*DomDfsName* is the name of the DFS namespace; and
*link_path* is a DFS link.

You can precede the string with backslashes (\\), but they are not required. This parameter is required.

### `Level` [in]

Specifies the information level of the request. This parameter can be one of the following values.

#### 1

Return the name of the DFS root and all links under the root. The *Buffer*
parameter points to an array of [DFS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_1)
structures.

#### 2

Return the name, comment, status, and the number of targets for the DFS root and all links under the
root. The *Buffer* parameter points to an array of
[DFS_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_2) structures.

#### 3

Return the name, comment, status, number of targets, and information about each target for the DFS root
and all links under the root. The *Buffer* parameter points to an array of
[DFS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_3) structures.

#### 4

Return the name, comment, status, **GUID**, time-out, number of targets, and information about each target
for the DFS root and all links under the root. The *Buffer* parameter points to an
array of [DFS_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_4) structures.

#### 5

Return the name, status, **GUID**, time-out, property flags, metadata size, and number of targets for a DFS
root and all links under the root. The *Buffer* parameter points to an array of
[DFS_INFO_5](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_5) structures.

#### 6

Return the name, status, **GUID**, time-out, property flags, metadata size, DFS target information for a root
or link, and a list of DFS targets. The *Buffer* parameter points to an array of
[DFS_INFO_6](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_6) structures.

#### 8

Return the name, status, **GUID**, time-out, property flags, metadata size, number of targets, and link
reparse point security descriptors for a DFS root and all links under the root. The
*Buffer* parameter points to an array of
[DFS_INFO_8](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_8) structures.

#### 9

Return the name, status, **GUID**, time-out, property flags, metadata size, DFS target information, link
reparse point security descriptors, and a list of DFS targets for a root or link. The
*Buffer* parameter points to an array of
[DFS_INFO_9](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_9) structures.

#### 200

Return the list of domain-based DFS namespaces in the domain. The *Buffer*
parameter points to an array of
[DFS_INFO_200](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_200) structures.

#### 300

Return the stand-alone and domain-based DFS namespaces hosted by a server. The
*Buffer* parameter points to an array of
[DFS_INFO_300](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_300) structures.

### `PrefMaxLen` [in]

Specifies the number of bytes that should be returned by this function in the information structure buffer.
If this parameter is **MAX_PREFERRED_LENGTH**, the function allocates the amount of memory required for the data.
For more information, see the following Remarks section. This parameter is ignored if you specify level 200 or
level 300.

### `Buffer` [out]

Pointer to a buffer that receives the requested information structures. The format of this data depends on the value of the *Level* parameter. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function.

### `EntriesRead` [out]

Pointer to a value that receives the actual number of entries returned in the response.

### `ResumeHandle` [in, out]

Pointer to a value that contains a handle to be used for continuing an enumeration when more data is available than can be returned in a single call to this function. The handle should be zero on the first call and left unchanged for subsequent calls. For more information, see the following Remarks section.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If no more entries are available to be enumerated, the return value is **ERROR_NO_MORE_ITEMS**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

No special group membership is required for using the
**NetDfsEnum** function.

Call the
**NetDfsEnum** function with the *ResumeHandle* parameter set to zero to begin the enumeration. To continue the enumeration operation, call this function with the *ResumeHandle* returned by the previous call to
**NetDfsEnum**. If this function does not return **ERROR_NO_MORE_ITEMS**, subsequent calls to this API will return the remaining links. Once **ERROR_NO_MORE_ITEMS** is returned, all available DFS links have been retrieved.

The
**NetDfsEnum** function allocates the memory required for the information structure buffer. If you specify an amount in the *PrefMaxLen* parameter, it restricts the memory that the function returns. However, the actual size of the memory that the
**NetDfsEnum** function allocates can be greater than the amount you specify. For additional information see
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

Due to the possibility of concurrent updates to the DFS namespace, the caller should not assume completeness or uniqueness of the results returned when resuming an enumeration operation.

#### Examples

The following code sample demonstrates how to list the DFS links in a named DFS root with a call to the
**NetDfsEnum** function. The sample calls
**NetDfsEnum**, specifying information level 3 (
[DFS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_3)). The sample code loops through the entries and prints the retrieved data and the status of each host server referenced by the DFS link. Finally, the sample frees the memory allocated for the information buffer.

```cpp
#include <windows.h>
#include <lm.h>
#include <lmdfs.h>
#include <stdio.h>

#pragma comment(lib, "Netapi32.lib")

void wmain(int argc, wchar_t *argv[ ])
{
    PDFS_INFO_3 pData, p;
    PDFS_STORAGE_INFO ps;
    DWORD er = 0, hResume = 0, res, i, j;

    if(argc < 2)
        wprintf(L"Syntax: %s \\\\DfsName\n", argv[0]);
    else
    {
        //
        // Call the NetDfsEnum function, specifying level 3.
        //
        res = NetDfsEnum(argv[1], 3, MAX_PREFERRED_LENGTH, (LPBYTE *) &pData, &er, &hResume);

        // Call NetDfsEnum until all available entries are returned.
        // NetDfsEnum will return ERROR_NO_MORE_ITEMS when all entries
        // have been obtained.
        while (res == ERROR_SUCCESS)
        {
            p = pData;
            //
            // Loop through the entries; print the data.
            //
            for(i = 1; i <= er; i++)
            {
                printf("%-30S%u\n", p->EntryPath, p->NumberOfStorages);
                ps = p->Storage;
                //
                // Loop through each target.
                //
                for(j = 1; j <= p->NumberOfStorages; j++)
                {
                    //
                    // Print the status (Offline/Online) and the name
                    // of each target referenced by the DFS link.
                    //
                    printf("    %S  ", (ps->State == DFS_STORAGE_STATE_OFFLINE) ? TEXT("Offline"):TEXT("Online "));
                    printf("\\\\%S\\%S\n", ps->ServerName, ps->ShareName);
                    ps++;
                }
                p++;
            }
            // Free the allocated buffer.
            //
            NetApiBufferFree(pData);

            res = NetDfsEnum(argv[1], 3, MAX_PREFERRED_LENGTH, (LPBYTE *) &pData, &er, &hResume);
        }

        if (res == ERROR_NO_MORE_ITEMS)
        {
            // the last of the entries have been processed.
            res = ERROR_SUCCESS;
            printf("Enumeration done\n");
        }
        else
        {
            // an error occurred.
            printf("Error: %u\n", res);
        }
    }
    return;
}

```

## See also

[DFS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_1)

[DFS_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_2)

[DFS_INFO_200](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_200)

[DFS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_3)

[DFS_INFO_300](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_300)

[DFS_INFO_4](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_4)

[DFS_INFO_5](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_5)

[DFS_INFO_6](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_6)

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsAdd](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsadd)

[NetDfsRemove](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsremove)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)