# NetShareSetInfo function

## Description

Sets the parameters of a shared resource.

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `netname` [in]

Pointer to a string that specifies the name of the share to set information on.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **1** | Specifies information about the shared resource, including the name and type of the resource, and a comment associated with the resource. The *buf* parameter points to a [SHARE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1) structure. |
| **2** | Specifies information about the shared resource, including the name of the resource, type and permissions, password, and number of connections. The *buf* parameter points to a [SHARE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_2) structure. |
| **502** | Specifies information about the shared resource, including the name and type of the resource, required permissions, number of connections, and other pertinent information. The *buf* parameter points to a [SHARE_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_502) structure. |
| **503** | Specifies the name of the shared resource. The *buf* parameter points to a [SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503) structure. All members of this structure except **shi503_servername** are ignored by the **NetShareSetInfo** function.<br><br>**Windows Server 2003 and Windows XP:** This information level is not supported. |
| **1004** | Specifies a comment associated with the shared resource. The *buf* parameter points to a [SHARE_INFO_1004](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1004) structure. |
| **1005** | Specifies a set of flags describing the shared resource. The *buf* parameter points to a [SHARE_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1005) structure. |
| **1006** | Specifies the maximum number of concurrent connections that the shared resource can accommodate. The *buf* parameter points to a [SHARE_INFO_1006](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1006) structure. |
| **1501** | Specifies the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) associated with the specified share. The *buf* parameter points to a [SHARE_INFO_1501](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1501) structure. |

### `buf` [in]

Pointer to the buffer that specifies the data. The format of this data depends on the value of the *level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `parm_err` [out]

Pointer to a value that receives the index of the first member of the share information structure that causes the **ERROR_INVALID_PARAMETER** error. If this parameter is **NULL**, the index is not returned on error. For more information, see the following Remarks section.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_LEVEL** | The value specified for the *level* parameter is not valid. |
| **ERROR_INVALID_PARAMETER** | The specified parameter is not valid. For more information, see the following Remarks section. |
| **NERR_NetNameNotFound** | The share name does not exist. |

## Remarks

This function applies only to Server Message Block (SMB) shares. For other types of shares, such as Distributed File System (DFS) or WebDAV shares, use [Windows Networking (WNet) functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions), which support all types of shares.

Only members of the Administrators or Power Users local group, or those with Print or Server Operator group membership, can successfully execute the
**NetShareSetInfo** function. The Print Operator can set information only about Printer shares.

If the
**NetShareSetInfo** function returns **ERROR_INVALID_PARAMETER**, you can use the *parm_err* parameter to indicate the first member of the share information structure that is not valid. (A share information structure begins with **SHARE_INFO_** and its format is specified by the *level* parameter.) The following table lists the values that can be returned in the *parm_err* parameter and the corresponding structure member that is in error. (The prefix **shi*_** indicates that the member can begin with multiple prefixes, for example, *shi2_* or **shi502_**.)

| Value | Member |
| --- | --- |
| SHARE_NETNAME_PARMNUM | **shi*_netname** |
| SHARE_TYPE_PARMNUM | **shi*_type** |
| SHARE_REMARK_PARMNUM | **shi*_remark** |
| SHARE_PERMISSIONS_PARMNUM | **shi*_permissions** |
| SHARE_MAX_USES_PARMNUM | **shi*_max_uses** |
| SHARE_CURRENT_USES_PARMNUM | **shi*_current_uses** |
| SHARE_PATH_PARMNUM | **shi*_path** |
| SHARE_PASSWD_PARMNUM | **shi*_passwd** |
| SHARE_FILE_SD_PARMNUM | **shi*_security_descriptor** |

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management share functions. For more information, see
[IADsFileShare](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsfileshare).

If 503 is specified for the *level* parameter, the remote server specified in the **shi503_servername** member of the [SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503) structure must have been bound to a transport protocol using the [NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex) function. In the call to **NetServerTransportAddEx**, either 2 or 3 must have been specified for the *level* parameter, and the **SVTI2_SCOPED_NAME** flag must have been specified in the [SERVER_TRANSPORT_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_2) structure for the transport protocol.

#### Examples

The following code sample demonstrates how to set the comment associated with a shared resource using a call to the
**NetShareSetInfo** function. To do this, the sample specifies information level 1004 ([SHARE_INFO_1004](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1004)).

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
   SHARE_INFO_1004 p;
   NET_API_STATUS res;
   DWORD parm_err = 0;

   if(argc<4)
      printf("Usage: SetInfo server share \"remark\"\n");
   else
   {
      //
      // Fill in SHARE_INFO_1004 structure member.
      //
      p.shi1004_remark=argv[3];
      //
      // Call the NetShareSetInfo function,
      //  specifying information level 1004.
      //
      res=NetShareSetInfo(argv[1], argv[2], 1004, (LPBYTE)&p, &parm_err);
      //
      // Display the result of the call.
      //
      if(res==0)
         printf("Remark set.\n");
      else
         printf("Error: %u\tparmerr=%u\n", res, parm_err);
   }
   return;
}

```

## See also

[NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex)

[NetShareGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsharegetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Share Functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions)

[SHARE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1)

[SHARE_INFO_1004](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1004)

[SHARE_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1005)

[SHARE_INFO_1006](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1006)

[SHARE_INFO_1501](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1501)

[SHARE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_2)

[SHARE_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_502)

[SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503)