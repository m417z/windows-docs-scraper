# NetShareGetInfo function

## Description

Retrieves information about a particular shared resource on a server.

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `netname` [in]

Pointer to a string that specifies the name of the share for which to return information.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return the share name. The *bufptr* parameter points to a [SHARE_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_0) structure. |
| **1** | Return information about the shared resource, including the name and type of the resource, and a comment associated with the resource. The *bufptr* parameter points to a [SHARE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1) structure. |
| **2** | Return information about the shared resource, including name of the resource, type and permissions, password, and number of connections. The *bufptr* parameter points to a [SHARE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_2) structure. |
| **501** | Return the name and type of the resource, and a comment associated with the resource. The *bufptr* parameter points to a [SHARE_INFO_501](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_501) structure. |
| **502** | Return information about the shared resource, including name of the resource, type and permissions, number of connections, and other pertinent information. The *bufptr* parameter points to a [SHARE_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_502) structure. |
| **503** | Specifies information about the shared resource, including the name of the resource, type and permissions, number of connections, and other pertinent information. The *buf* parameter points to a [SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503) structure. If the **shi503_servername** member of this structure is "*", there is no configured server name.<br><br>**Windows Server 2003 and Windows XP:** This information level is not supported. |
| **1005** | Return a value that indicates whether the share is the root volume in a Dfs tree structure. The *bufptr* parameter points to a [SHARE_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1005) structure. |

### `bufptr` [out]

Pointer to the buffer that receives the data. The format of this data depends on the value of the *level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_LEVEL** | The value specified for the *level* parameter is not valid. |
| **ERROR_INVALID_PARAMETER** | The specified parameter is not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory is available. |
| **NERR_NetNameNotFound** | The share name does not exist. |

## Remarks

This function applies only to Server Message Block (SMB) shares. For other types of shares, such as Distributed File System (DFS) or WebDAV shares, use [Windows Networking (WNet) functions](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-functions), which support all types of shares.

For interactive users (users who are logged on locally to the machine), no special group membership is required to execute the **NetShareGetInfo** function. For non-interactive users, Administrator, Power User, Print Operator, or Server Operator group membership is required to successfully execute the
[NetShareEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netshareenum) function at levels 2, 502, and 503. No special group membership is required for level 0 or level 1 calls.

**Windows Server 2003 and Windows XP:** For all users, Administrator, Power User, Print Operator, or Server Operator group membership is required to successfully execute the
**NetShareGetInfo** function at levels 2 and 502.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management share functions. For more information, see
[IADsFileShare](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsfileshare).

If 503 is specified for the *level* parameter, the remote server specified in the **shi503_servername** member of the [SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503) structure must have been bound to a transport protocol using the [NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex) function. In the call to **NetServerTransportAddEx**, either 2 or 3 must have been specified for the *level* parameter, and the **SVTI2_SCOPED_NAME** flag must have been specified in the [SERVER_TRANSPORT_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_2) structure for the transport protocol.

#### Examples

The following code sample demonstrates how to retrieve information about a particular shared resource using a call to the
**NetShareGetInfo** function. The sample calls
**NetShareGetInfo**, specifying information level 502 (
[SHARE_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_502)). If the call succeeds, the code prints the retrieved data. The sample also calls the
[IsValidSecurityDescriptor](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-isvalidsecuritydescriptor) function to validate the **shi502_security_descriptor** member. Finally, the sample frees the memory allocated for the information buffer.

```cpp
#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include <stdio.h>
#include <lm.h>

#pragma comment(lib, "Netapi32.lib")
#pragma comment(lib, "Advapi32.lib")

void wmain( int argc, TCHAR *lpszArgv[ ])
{
   PSHARE_INFO_502 BufPtr;
   NET_API_STATUS res;
   LPTSTR   lpszServer = NULL, lpszShare;
   //
   // Check command line arguments.
   //
   switch(argc)
   {
   case 3:
      lpszServer = lpszArgv[2];
   case 2:
      lpszShare = lpszArgv[1];
      break;
   default:
      printf("Usage: NetShareGetInfo sharename <servername>\n");
      return;
   }
   //
   // Call the NetShareGetInfo function, specifying level 502.
   //
   if((res = NetShareGetInfo (lpszServer,lpszShare,502,(LPBYTE *) &BufPtr)) == ERROR_SUCCESS)
   {
      //
      // Print the retrieved data.
      //
      printf("%S\t%S\t%u\n",BufPtr->shi502_netname, BufPtr->shi502_path, BufPtr->shi502_current_uses);
      //
      // Validate the value of the
      //  shi502_security_descriptor member.
      //
      if (IsValidSecurityDescriptor(BufPtr->shi502_security_descriptor))
         printf("It has a valid Security Descriptor.\n");
      else
         printf("It does not have a valid Security Descriptor.\n");
      //
      // Free the allocated memory.
      //
      NetApiBufferFree(BufPtr);
   }
   else
      printf("Error: %ld\n",res);
   return;
}

```

## See also

[NetServerTransportAddEx](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netservertransportaddex)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Share Functions](https://learn.microsoft.com/windows/desktop/NetShare/network-share-functions)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor)

[SHARE_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_0)

[SHARE_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1)

[SHARE_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_1005)

[SHARE_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_2)

[SHARE_INFO_501](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_501)

[SHARE_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_502)

[SHARE_INFO_503](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-share_info_503)