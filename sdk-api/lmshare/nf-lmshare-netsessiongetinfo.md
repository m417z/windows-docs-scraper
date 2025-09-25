# NetSessionGetInfo function

## Description

Retrieves information about a session established between a particular server and workstation.

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `UncClientName` [in]

Pointer to a string that specifies the name of the computer session for which information is to be returned. This parameter is required and cannot be **NULL**. For more information, see
[NetSessionEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsessionenum).

### `username` [in]

Pointer to a string that specifies the name of the user whose session information is to be returned. This parameter is required and cannot be **NULL**.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return the name of the computer that established the session. <br><br>The *bufptr* parameter points to a [SESSION_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_0) structure. |
| **1** | Return the name of the computer, name of the user, and open files, pipes, and devices on the computer. <br><br>The *bufptr* parameter points to a [SESSION_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_1) structure. |
| **2** | In addition to the information indicated for level 1, return the type of client and how the user established the session. <br><br>The *bufptr* parameter points to a [SESSION_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_2) structure. |
| **10** | Return the name of the computer; name of the user; and active and idle times for the session. <br><br>The *bufptr* parameter points to a [SESSION_INFO_10](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_10) structure. |

### `bufptr` [out]

Pointer to the buffer that receives the data. The format of this data depends on the value of the *level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_LEVEL** | The value specified for the *level* parameter is not valid. |
| **ERROR_INVALID_PARAMETER** | The specified parameter is not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory is available. |
| **NERR_ClientNameNotFound** | A session does not exist with the computer name. |
| **NERR_InvalidComputer** | The computer name is not valid. |
| **NERR_UserNotFound** | The user name could not be found. |

## Remarks

Only members of the Administrators or Server Operators local group can successfully execute the
**NetSessionGetInfo** function at level 1 or level 2. No special group membership is required for level 0 or level 10 calls.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management session functions. For more information, see
[IADsSession](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssession) and
[IADsFileServiceOperations](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsfileserviceoperations).

If you call this function at information level 1 or 2 on a member server or workstation, all authenticated users can view the information.

#### Examples

The following code sample demonstrates how to retrieve information about a session using a call to the
**NetSessionGetInfo** function. The sample calls
**NetSessionGetInfo**, specifying information level 10 (
[SESSION_INFO_10](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_10)). If the call succeeds, the code prints information about the session. Finally, the sample frees the memory allocated for the information buffer.

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
   DWORD dwLevel = 10;
   LPSESSION_INFO_10 pBuf = NULL;
   LPTSTR pszServerName = NULL;
   LPTSTR pszUNCClientName = NULL;
   LPTSTR pszUserName = NULL;
   NET_API_STATUS nStatus;
   //
   // Check command line arguments.
   //
   if (argc == 3)
   {
      pszUNCClientName = argv[1];
      pszUserName = argv[2];
   }
   else if (argc == 4)
   {
      pszServerName = argv[1];
      pszUNCClientName = argv[2];
      pszUserName = argv[3];
   }
   else
   {
      wprintf(L"Usage: %s [\\\\ServerName] \\\\ClientName UserName\n", argv[0]);
      exit(1);
   }
   //
   // Call the NetSessionGetInfo function, specifying level 10.
   //
   nStatus = NetSessionGetInfo(pszServerName,
                               pszUNCClientName,
                               pszUserName,
                               dwLevel,
                               (LPBYTE *)&pBuf);
   //
   // If the call succeeds,
   //
   if (nStatus == NERR_Success)
   {
      if (pBuf != NULL)
      {
         //
         // Print the session information.
         //
         wprintf(L"\n\tClient: %s\n", pBuf->sesi10_cname);
         wprintf(L"\tUser:   %s\n", pBuf->sesi10_username);
         printf("\tActive: %d\n", pBuf->sesi10_time);
         printf("\tIdle:   %d\n", pBuf->sesi10_idle_time);
      }
   }
   //
   // Otherwise, indicate a system error.
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

[NetSessionDel](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsessiondel)

[NetSessionEnum](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsessionenum)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[SESSION_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_0)

[SESSION_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_1)

[SESSION_INFO_10](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_10)

[SESSION_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_2)

[Session
Functions](https://learn.microsoft.com/windows/desktop/NetShare/session-functions)