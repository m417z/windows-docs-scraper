# NetServerGetInfo function

## Description

The
**NetServerGetInfo** function retrieves current configuration information for the specified server.

## Parameters

### `servername` [in]

Pointer to a string that specifies the name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **100** | Return the server name and platform information. The *bufptr* parameter points to a [SERVER_INFO_100](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_100) structure. |
| **101** | Return the server name, type, and associated software. The *bufptr* parameter points to a [SERVER_INFO_101](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_101) structure. |
| **102** | Return the server name, type, associated software, and other attributes. The *bufptr* parameter points to a [SERVER_INFO_102](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_102) structure. |

### `bufptr` [out]

Pointer to the buffer that receives the data. The format of this data depends on the value of the *level* parameter.

This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED**<br><br>5 | The user does not have access to the requested information. |
| **ERROR_INVALID_LEVEL**<br><br>124 | The value specified for the *level* parameter is invalid. |
| **ERROR_INVALID_PARAMETER**<br><br>87 | The specified parameter is invalid. |
| **ERROR_NOT_ENOUGH_MEMORY**<br><br>8 | Insufficient memory is available. |
| **NERR_ServerNotStarted**<br><br>2114 | The server service is not started. |

## Remarks

Only the Administrators or Server Operators local group, or those with Print or Server Operator group membership, can successfully execute the
**NetServerGetInfo** function at level 102. No special group membership is required for level 100 or level 101 calls.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management server functions. For more information, see
[IADsComputer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscomputer).

#### Examples

The following code sample demonstrates how to retrieve current configuration information for a server using a call to the
**NetServerGetInfo** function. The sample calls
**NetServerGetInfo**, specifying information level 101 ([SERVER_INFO_101](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_101)). If the call succeeds, the code attempts to identify the type of server. Finally, the sample frees the memory allocated for the information buffer.

```cpp
#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")

#include <stdio.h>
#include <windows.h>
#include <lm.h>

int wmain(int argc, wchar_t *argv[])
{
   DWORD dwLevel = 101;
   LPSERVER_INFO_101 pBuf = NULL;
   NET_API_STATUS nStatus;
   LPTSTR pszServerName = NULL;

   if (argc > 2)
   {
      fwprintf(stderr, L"Usage: %s [\\\\ServerName]\n", argv[0]);
      exit(1);
   }
   // The server is not the default local computer.
   //
   if (argc == 2)
      pszServerName = (LPTSTR) argv[1];
   //
   // Call the NetServerGetInfo function, specifying level 101.
   //
   nStatus = NetServerGetInfo(pszServerName,
                              dwLevel,
                              (LPBYTE *)&pBuf);
   //
   // If the call succeeds,
   //
   if (nStatus == NERR_Success)
   {
      //
      // Check for the type of server.
      //
      if ((pBuf->sv101_type & SV_TYPE_DOMAIN_CTRL) ||
         (pBuf->sv101_type & SV_TYPE_DOMAIN_BAKCTRL) ||
         (pBuf->sv101_type & SV_TYPE_SERVER_NT))
         printf("This is a server\n");
      else
         printf("This is a workstation\n");
   }
   //
   // Otherwise, print the system error.
   //
   else
      fprintf(stderr, "A system error has occurred: %d\n", nStatus);
   //
   // Free the allocated memory.
   //
   if (pBuf != NULL)
      NetApiBufferFree(pBuf);

   return 0;
}

```

## See also

[NetRemoteComputerSupports](https://learn.microsoft.com/windows/desktop/api/lmremutl/nf-lmremutl-netremotecomputersupports)

[NetServerSetInfo](https://learn.microsoft.com/windows/desktop/api/lmserver/nf-lmserver-netserversetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[SERVER_INFO_100](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_100)

[SERVER_INFO_101](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_101)

[SERVER_INFO_102](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_info_102)

[Server
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-functions)