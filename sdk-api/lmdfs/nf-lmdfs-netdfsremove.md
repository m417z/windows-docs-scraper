# NetDfsRemove function

## Description

Removes a Distributed File System (DFS) link or a specific link target of a DFS link in a DFS
namespace. When removing a specific link target, the link itself is removed if the last link target of the link is
removed.

## Parameters

### `DfsEntryPath` [in]

Pointer to a string that specifies the Universal Naming Convention (UNC) path of the DFS link.

The string can be in one of two forms. The first form is as follows:

\\*ShareName*\*DfsName*\*link_path*

where *ShareName* is the name of the root target server that hosts the stand-alone
DFS namespace; *DfsName* is the name of the DFS namespace; and
*link_path* is a DFS link.

The second form is as follows:

\\*DomainName*\*DomDfsname*\*link_path*

where *DomainName* is the name of the domain that hosts the domain-based DFS
namespace; *DomDfsname* is the name of the DFS namespace; and
*link_path* is a DFS link.

This parameter is required.

### `ServerName` [in, optional]

Pointer to a string that specifies the server name of the link target. For more information, see the
following Remarks section. Set this parameter to **NULL** if the link and all link targets
are to be removed.

### `ShareName` [in, optional]

Pointer to a string that specifies the share name of the link target. Set this parameter to
**NULL** if the link and all link targets are to be removed.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The caller must have Administrator privilege on the DFS server. For more information about calling functions
that require administrator privileges, see
[Running with Special Privileges](https://learn.microsoft.com/windows/desktop/SecBP/running-with-special-privileges).

When you call **NetDfsRemove** to remove a target from a
link, you must specify the same target server name in the *ServerName* parameter that you
specified when you created the link. For example, if you specified the target server's DNS name when you added the
target to the link, you must specify the same DNS name when you remove the link. You cannot specify the NetBIOS
name.

#### Examples

The following code sample demonstrates how to remove a target from a DFS link using a call to the
**NetDfsRemove** function.

```cpp
#include <windows.h>
#include <lm.h>
#include <lmdfs.h>
#include <stdio.h>
#pragma comment(lib, "Netapi32.lib")

void wmain(int argc, wchar_t *argv[])
{
   DWORD res;
   //
   // All parameters are required.
   //
   if (argc < 4)
      wprintf(L"Syntax: %s DfsEntryPath ServerName ShareName\n", argv[0]);
   else
   {
      //
      // Call the NetDfsRemove function
      //  to remove the DFS link.
      //
      res = NetDfsRemove(argv[1], argv[2], argv[3]);
      //
      // Display the result of the call.
      //
      if(res == 0)
         printf("Removed DFS link\n");
      else
         printf("Error: %u\n", res);
   }
   return;
}

```

## See also

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[NetDfsAdd](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsadd)

[NetDfsEnum](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsenum)

[NetDfsRemoveFtRoot](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsremoveftroot)

[NetDfsRemoveStdRoot](https://learn.microsoft.com/previous-versions/windows/desktop/api/lmdfs/nf-lmdfs-netdfsremovestdroot)

[Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)