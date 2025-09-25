# NetSessionDel function

## Description

Ends a network session between a server and a workstation.

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `UncClientName` [in]

Pointer to a string that specifies the computer name of the client to disconnect. If the *UncClientName* parameter is **NULL**, then all the sessions of the user identified by the *username* parameter will be deleted on the server specified by the *servername* parameter. For more information, see
[NetSessionEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsessionenum).

### `username` [in]

Pointer to a string that specifies the name of the user whose session is to be terminated. If this parameter is **NULL**, all users' sessions from the client specified by the *UncClientName* parameter are to be terminated.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_PARAMETER** | The specified parameter is not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory is available. |
| **NERR_ClientNameNotFound** | A session does not exist with that computer name. |

## Remarks

Only members of the Administrators or Server Operators local group can successfully execute the
**NetSessionDel** function.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management session functions. For more information, see
[IADsSession](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssession) and
[IADsFileServiceOperations](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsfileserviceoperations).

#### Examples

The following code sample demonstrates how to terminate a session between a server and a workstation using a call to the **NetSessionDel** function.

```cpp
#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "Netapi32.lib")

#include <stdio.h>
#include <windows.h>
#include <lm.h>

int wmain(int argc, wchar_t *argv[])
{
   DWORD dwError = 0;
   LPTSTR pszServerName = NULL;
   LPTSTR pszClientName = NULL;
   LPTSTR pszUserName = NULL;
   NET_API_STATUS nStatus;
   //
   // Check command line arguments.
   //
   if (argc > 4)
   {
      wprintf(L"Usage: %s [\\\\ServerName] [\\\\ClientName] [UserName]\n", argv[0]);
      exit(1);
   }

   if (argc >= 2)
      pszServerName = argv[1];

   if (argc >= 3)
      pszClientName = argv[2];

   if (argc == 4)
      pszUserName = argv[3];
   //
   // Call the NetSessionDel function to delete the session.
   //
   nStatus = NetSessionDel(pszServerName,
                           pszClientName,
                           pszUserName);
   //
   // Display the result of the call.
   //
   if (nStatus == NERR_Success)
      fprintf(stderr, "The specified session(s) has been successfully deleted\n");
   else
      fprintf(stderr, "A system error has occurred: %d\n", nStatus);

   return 0;
}

```

## See also

[NetSessionEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsessionenum)

[NetSessionGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsessiongetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Session
Functions](https://learn.microsoft.com/windows/desktop/NetShare/session-functions)