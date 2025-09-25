# NetShareDel function

## Description

Deletes a share name from a server's list of shared resources, disconnecting all connections to the shared resource.

The extended function [NetShareDelEx](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharedelex) allows the caller to specify a [SHARE_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_0), [SHARE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1), [SHARE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_2), [SHARE_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_502), or [SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503) structure.

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** is defined.

### `netname` [in]

Pointer to a string that specifies the name of the share to delete.

This string is Unicode if **_WIN32_WINNT** or **FORCE_UNICODE** is defined.

### `reserved`

Reserved, must be zero.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_PARAMETER** | The specified parameter is not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory is available. |
| **NERR_NetNameNotFound** | The share name does not exist. |

## Remarks

This function applies only to Server Message Block (SMB) shares. For other types of shares, such as Distributed File System (DFS) or WebDAV shares, use [Windows Networking (WNet) functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions), which support all types of shares.

Only members of the Administrators, Server Operators, or Power Users local group, or those with Server Operator group membership, can successfully delete file shares with a call to the
**NetShareDel** function. The Print Operator can delete printer shares.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management share functions. For more information, see
[IADsFileShare](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsfileshare).

#### Examples

The following code sample demonstrates how to delete a share using a call to the **NetShareDel** function.

```cpp
#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include <stdio.h>
#include <lm.h>
#pragma comment(lib, "Netapi32.lib")

void wmain( int argc, TCHAR *argv[ ])
{
   NET_API_STATUS res;

   if(argc<3)
      printf("Usage: NetShareDel server share\n");
   else
   {
      //
      // Call the NetShareDel function to delete the share.
      //
      res=NetShareDel(argv[1], argv[2], 0);
      //
      // Display the result of the call.
      //
      if(res==0)
         printf("Share Removed.\n");
      else
         printf("Error: %u\n", res);
   }
   return;
}

```

## See also

[NetShareAdd](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netshareadd)

[NetShareDelEx](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharedelex)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Share Functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions)