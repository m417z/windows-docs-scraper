# NetDfsAdd function

## Description

Creates a new Distributed File System (DFS) link or adds
targets to an existing link in a DFS namespace.

## Parameters

### `DfsEntryPath` [in]

Pointer to a string that specifies the Universal Naming Convention (UNC) path of a DFS link in a DFS namespace.

The string can be in one of two forms. The first form is as follows:

\\*ServerName*\*DfsName*\*link_path*

where *ServerName* is the name of the root target server that hosts a stand-alone DFS namespace; *DfsName* is the name of the DFS namespace; and
*link_path* is a DFS link.

The second form is as follows:

\\*DomainName*\*DomDfsname*\*link_path*

where *DomainName* is the name of the domain that hosts a domain-based DFS namespace; *DomDfsname* is the name of
the domain-based DFS namespace; and
*link_path* is a DFS link.

This parameter is required.

### `ServerName` [in]

Pointer to a string that specifies the link target server name. This parameter
is required.

### `ShareName` [in]

Pointer to a string that specifies the link target share name. This can also be a share name with a path relative to the share. For example, *share1\mydir1\mydir2*. This parameter is required.

### `Comment` [in, optional]

Pointer to a string that specifies an optional comment associated with the DFS link. This parameter is
ignored when the function adds a target to an existing link.

### `Flags` [in]

This parameter can specify the following value, or you can specify zero for no flags.

#### DFS_ADD_VOLUME (0x00000001)

Create a DFS link. If the DFS link already exists, the **NetDfsAdd**
function fails. For more information, see the Remarks section.

#### DFS_RESTORE_VOLUME (0x00000002)

This flag is not supported.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The DFS namespace must already exist. This function does not create a new DFS namespace.

The caller must have Administrator privilege on the DFS server. For more information about calling functions that require administrator privileges, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

Use of the **DFS_ADD_VOLUME** flag is optional. If you specify
**DFS_ADD_VOLUME** and the link already exists, **NetDfsAdd**
fails. If you do not specify **DFS_ADD_VOLUME**,
**NetDfsAdd** creates the link, if required, and adds the target to the link. You
should specify this value when you need to determine when new links are created.

#### Examples

The following code sample demonstrates how to create a new DFS link using a call to the
**NetDfsAdd** function. Because the sample specifies the value
**DFS_ADD_VOLUME** in the *Flags* parameter, the call to
**NetDfsAdd** fails if the DFS link already exists. To add additional targets to an
existing DFS link, you can specify zero in the *Flags* parameter.

```cpp
#include <windows.h>
#include <lm.h>
#include <lmdfs.h>
#include <stdio.h>
#pragma comment(lib, "NetApi32.lib")

void wmain(int argc, wchar_t *argv[ ])
{
   DWORD res;
   LPTSTR lpszComment;
   lpszComment = argc < 5 ? NULL : argv[4];
   //
   // Check for required parameters.
   //
   if (argc < 4)
      wprintf(L"Syntax: %s DfsEntryPath ServerName ShareName [\"Comment\"]\n", argv[0]);
   else
   {
      //
      // Call the NetDfsAdd function; fail the call
      // if the DFS link already exists (DFS_ADD_VOLUME).
         //
      // To add a second storage to a DFS link, change
      // the last parameter to 0.
      //
      res = NetDfsAdd(argv[1], argv[2], argv[3], lpszComment, DFS_ADD_VOLUME);
      //
      // If the call succeeds,
      //
      if(res == 0)
         printf("Added DFS link\n");
      else
         printf("Error: %u\n", res);
   }
   return;
}

```

## See also

[Distributed File System
(DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsAddFtRoot](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsaddftroot)

[NetDfsAddStdRoot](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsaddstdroot)

[NetDfsEnum](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsenum)

[NetDfsRemove](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsremove)

[Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)