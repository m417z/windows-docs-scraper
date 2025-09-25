# NetShareAdd function

## Description

Shares a server resource.

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **2** | Specifies information about the shared resource, including the name of the resource, type and permissions, and number of connections. The *buf* parameter points to a [SHARE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_2) structure. |
| **502** | Specifies information about the shared resource, including the name of the resource, type and permissions, number of connections, and other pertinent information. The *buf* parameter points to a [SHARE_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_502) structure. |
| **503** | Specifies information about the shared resource, including the name of the resource, type and permissions, number of connections, and other pertinent information. The *buf* parameter points to a [SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503) structure. |

### `buf` [in]

Pointer to the buffer that specifies the data. The format of this data depends on the value of the *level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `parm_err` [out]

Pointer to a value that receives the index of the first member of the share information structure that causes the **ERROR_INVALID_PARAMETER** error. If this parameter is **NULL**, the index is not returned on error. For more information, see the
[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo) function.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_LEVEL** | The value specified for the *level* parameter is not valid. |
| **ERROR_INVALID_NAME** | The character or file system name is not valid. |
| **ERROR_INVALID_PARAMETER** | The specified parameter is not valid. |
| **NERR_DuplicateShare** | The share name is already in use on this server. |
| **NERR_RedirectedPath** | The operation is not valid for a redirected resource. The specified device name is assigned to a shared resource. |
| **NERR_UnknownDevDir** | The device or directory does not exist. |

## Remarks

This function applies only to Server Message Block (SMB) shares. For other types of shares, such as Distributed File System (DFS) or WebDAV shares, use [Windows Networking (WNet) functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions), which support all types of shares.

Only members of the Administrators, System Operators, or Power Users local group can add file shares with a call to the
**NetShareAdd** function. The Print Operator can add printer shares.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management share functions. For more information, see
[IADsFileShare](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsfileshare).

If 503 is specified for the *level* parameter, the remote server specified in the **shi503_servername** member of the [SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503) structure must have been bound to a transport protocol using the [NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex) function. In the call to **NetServerTransportAddEx**, either 2 or 3 must have been specified for the *level* parameter, and the **SVTI2_SCOPED_NAME** flag must have been specified in the [SERVER_TRANSPORT_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_2) structure for the transport protocol.

#### Examples

The following code sample demonstrates how to share a network resource using a call to the
**NetShareAdd** function. The code sample fills in the members of the
[SHARE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_2) structure and calls
**NetShareAdd**, specifying information level 2. A password is not required because these platforms do not support share-level security.

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
   SHARE_INFO_2 p;
   DWORD parm_err = 0;

   if(argc<2)
      printf("Usage: NetShareAdd server\n");
   else
   {
      //
      // Fill in the SHARE_INFO_2 structure.
      //
      p.shi2_netname = TEXT("TESTSHARE");
      p.shi2_type = STYPE_DISKTREE; // disk drive
      p.shi2_remark = TEXT("TESTSHARE to test NetShareAdd");
      p.shi2_permissions = 0;
      p.shi2_max_uses = 4;
      p.shi2_current_uses = 0;
      p.shi2_path = TEXT("C:\\");
      p.shi2_passwd = NULL; // no password
      //
      // Call the NetShareAdd function,
      //  specifying level 2.
      //
      res=NetShareAdd(argv[1], 2, (LPBYTE) &p, &parm_err);
      //
      // If the call succeeds, inform the user.
      //
      if(res==0)
         printf("Share created.\n");

      // Otherwise, print an error,
      //  and identify the parameter in error.
      //
      else
         printf("Error: %u\tparmerr=%u\n", res, parm_err);
   }
   return;
}

```

## See also

[NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex)

[NetShareDel](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharedel)

[NetShareDelEx](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharedelex)

[NetShareSetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharesetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Share Functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions)

[SHARE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_2)

[SHARE_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_502)

[SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503)