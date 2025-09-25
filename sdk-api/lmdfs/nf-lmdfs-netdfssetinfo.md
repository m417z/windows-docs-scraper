# NetDfsSetInfo function

## Description

Sets or modifies information about a specific Distributed File System (DFS) root, root target, link, or link
target.

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

### `ServerName` [in, optional]

Pointer to a string that specifies the DFS link target server name. This parameter is optional. For more
information, see the Remarks section.

### `ShareName` [in, optional]

Pointer to a string that specifies the DFS link target share name. This may also be a share name with a
path relative to the share. For example, "share1\mydir1\mydir2". This parameter is optional. For more
information, see the Remarks section.

### `Level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

#### 100

Set the comment associated with the DFS root or link specified in the
*DfsEntryPath* parameter. The *Buffer* parameter points to a
[DFS_INFO_100](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_100) structure.

#### 101

Set the storage state associated with the DFS root or link specified in the
*DfsEntryPath* parameter. The *Buffer* parameter points to a
[DFS_INFO_101](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_101) structure.

#### 102

Set the time-out value associated with the DFS root or link specified in the
*DfsEntryPath* parameter. The *Buffer* parameter points to a
[DFS_INFO_102](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_102) structure.

#### 103

Set the property flags for the DFS root or link specified in the *DfsEntryPath*
parameter. The *Buffer* parameter points to a
[DFS_INFO_103](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_103) structure.

#### 104

Set the target priority rank and class for the root target or link target specified in the
*DfsEntryPath* parameter. The *Buffer* parameter points to a
[DFS_INFO_104](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_104) structure.

#### 105

Set the comment, state, and time-out information, as well as property flags, for the DFS root or link
specified in the *DfsEntryPath* parameter. The *Buffer*
parameter points to a [DFS_INFO_105](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_105) structure.

#### 106

Set the target state and priority for the root target or link target specified in the
*DfsEntryPath* parameter. This information cannot be set for a DFS namespace root or
link, only for a root target or link target. The *Buffer* parameter points to a
[DFS_INFO_106](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_106) structure.

#### 107

Set the comment, state, time-out information, and property flags for the DFS root or link specified in the
*DfsEntryPath* parameter. For DFS links, you can also set the security descriptor for
the link's reparse point. The *Buffer* parameter points to a
[DFS_INFO_107](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_107) structure.

#### 150

Set the security descriptor for a DFS link's reparse point. The *Buffer* parameter
points to a [DFS_INFO_150](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_150) structure.

### `Buffer` [in]

Pointer to a buffer that specifies the data. The format of this data depends on the value of the
*Level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The caller must have Administrator privilege on the DFS server. For more information about calling functions
that require administrator privileges, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

If you specify both the *ServerName* and *ShareName*
parameters, the **NetDfsSetInfo** function sets or modifies information specific to
that root target or link target. If the parameters are **NULL**, the function sets or
modifies information that is specific to the DFS namespace root or the DFS link instead of a specific DFS root
target or link target.

Because only one comment and one time-out can be set for a DFS root or link, the
*ServerName* and *ShareName* parameters are ignored for
information levels 100 and 102. These parameters are required for level 101.

For information level 101, the **DFS_VOLUME_STATE_RESYNCHRONIZE** and **DFS_VOLUME_STATE_STANDBY** state values can be
set as follows for a specific domain-based DFS root when there is more than one DFS root target for the DFS
namespace:

The *DfsEntryPath* parameter specifies the domain-based DFS namespace, and the
*ServerName* and *ShareName* parameters taken together specify
the DFS root target on which the set-information operation is to be performed.

#### Examples

The following code sample demonstrates how to associate a comment with a DFS link using a call to the
**NetDfsSetInfo** function. The sample specifies information level 100
([DFS_INFO_100](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_100)).

```cpp
#include <windows.h>
#include <lm.h>
#include <lmdfs.h>
#include <stdio.h>
#pragma comment(lib, "Netapi32.lib")

void wmain(int argc, wchar_t *argv[])
{
   DFS_INFO_100 dfsData;
   DWORD res;
   //
   // Check command line arguments.
   //
   if (argc<2)
      wprintf(L"Syntax: %s DfsEntryPath [\"Comment\"]\n", argv[0]);
   else
   {
      //
      // Fill in DFS_INFO_100 structure member.
      //
      dfsData.Comment = argc < 3 ? NULL : argv[2];
      //
      // Call the NetDfsSetInfo function, specifying level 100.
      //
      res = NetDfsSetInfo(argv[1], NULL, NULL, 100, (LPBYTE) &dfsData);
      //
      // Display the result of the call.
      //
      if(res == 0)
         printf("Comment set.\n");
      else
         printf("Error: %u", res);
   }
   return;
}

```

## See also

[DFS_INFO_100](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_100)

[DFS_INFO_101](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_101)

[DFS_INFO_102](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_102)

[DFS_INFO_103](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_103)

[DFS_INFO_104](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_104)

[DFS_INFO_105](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_105)

[DFS_INFO_106](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_106)

[DFS_INFO_107](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_107)

[DFS_INFO_150](https://learn.microsoft.com/windows/desktop/api/lmdfs/ns-lmdfs-dfs_info_150)

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsEnum](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsenum)

[Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)