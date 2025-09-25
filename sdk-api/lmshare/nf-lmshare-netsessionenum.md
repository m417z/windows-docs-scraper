# NetSessionEnum function

## Description

Provides information about sessions established on a server.

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `UncClientName` [in]

Pointer to a string that specifies the name of the computer session for which information is to be returned. If this parameter is **NULL**,
**NetSessionEnum** returns information for all computer sessions on the server.

### `username` [in]

Pointer to a string that specifies the name of the user for which information is to be returned. If this parameter is **NULL**,
**NetSessionEnum** returns information for all users.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return the name of the computer that established the session. The *bufptr* parameter points to an array of [SESSION_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_0) structures. |
| **1** | Return the name of the computer, name of the user, and open files, pipes, and devices on the computer. The *bufptr* parameter points to an array of [SESSION_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_1) structures. |
| **2** | In addition to the information indicated for level 1, return the type of client and how the user established the session. The *bufptr* parameter points to an array of [SESSION_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_2) structures. |
| **10** | Return the name of the computer, name of the user, and active and idle times for the session. The *bufptr* parameter points to an array of [SESSION_INFO_10](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_10) structures. |
| **502** | Return the name of the computer; name of the user; open files, pipes, and devices on the computer; and the name of the transport the client is using. The *bufptr* parameter points to an array of [SESSION_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_502) structures. |

### `bufptr` [out]

Pointer to the buffer that receives the data. The format of this data depends on the value of the *level* parameter.

This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. Note that you must free the buffer even if the function fails with **ERROR_MORE_DATA**.

### `prefmaxlen` [in]

Specifies the preferred maximum length of returned data, in bytes. If you specify **MAX_PREFERRED_LENGTH**, the function allocates the amount of memory required for the data. If you specify another value in this parameter, it can restrict the number of bytes that the function returns. If the buffer size is insufficient to hold all entries, the function returns **ERROR_MORE_DATA**. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

### `entriesread` [out]

Pointer to a value that receives the count of elements actually enumerated.

### `totalentries` [out]

Pointer to a value that receives the total number of entries that could have been enumerated from the current resume position. Note that applications should consider this value only as a hint.

### `resume_handle` [in, out]

Pointer to a value that contains a resume handle which is used to continue an existing session search. The handle should be zero on the first call and left unchanged for subsequent calls. If *resume_handle* is **NULL**, no resume handle is stored.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_LEVEL** | The value specified for the *level* parameter is not valid. |
| **ERROR_INVALID_PARAMETER** | The specified parameter is not valid. |
| **ERROR_MORE_DATA** | More entries are available. Specify a large enough buffer to receive all entries. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory is available. |
| **NERR_ClientNameNotFound** | A session does not exist with the computer name. |
| **NERR_InvalidComputer** | The computer name is not valid. |
| **NERR_UserNotFound** | The user name could not be found. |

## Remarks

Only members of the Administrators or Server Operators local group can successfully execute the
**NetSessionEnum** function at level 1 or level 2.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management session functions. For more information, see
[IADsSession](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadssession) and
[IADsFileServiceOperations](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsfileserviceoperations).

#### Examples

The following code sample demonstrates how to retrieve information about current sessions using a call to the
**NetSessionEnum** function. The sample calls
**NetSessionEnum**, specifying information level 10 (
[SESSION_INFO_10](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_10)). The sample loops through the entries and prints the retrieved information. Finally, the code prints the total number of sessions enumerated and frees the memory allocated for the information buffer.

```cpp
#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "Netapi32.lib")

#include <stdio.h>
#include <assert.h>
#include <windows.h>
#include <lm.h>

int wmain(int argc, wchar_t *argv[])
{
   LPSESSION_INFO_10 pBuf = NULL;
   LPSESSION_INFO_10 pTmpBuf;
   DWORD dwLevel = 10;
   DWORD dwPrefMaxLen = MAX_PREFERRED_LENGTH;
   DWORD dwEntriesRead = 0;
   DWORD dwTotalEntries = 0;
   DWORD dwResumeHandle = 0;
   DWORD i;
   DWORD dwTotalCount = 0;
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
   // Call the NetSessionEnum function, specifying level 10.
   //
   do // begin do
   {
      nStatus = NetSessionEnum(pszServerName,
                               pszClientName,
                               pszUserName,
                               dwLevel,
                               (LPBYTE*)&pBuf,
                               dwPrefMaxLen,
                               &dwEntriesRead,
                               &dwTotalEntries,
                               &dwResumeHandle);
      //
      // If the call succeeds,
      //
      if ((nStatus == NERR_Success) || (nStatus == ERROR_MORE_DATA))
      {
         if ((pTmpBuf = pBuf) != NULL)
         {
            //
            // Loop through the entries.
            //
            for (i = 0; (i < dwEntriesRead); i++)
            {
               assert(pTmpBuf != NULL);

               if (pTmpBuf == NULL)
               {
                  fprintf(stderr, "An access violation has occurred\n");
                  break;
               }
               //
               // Print the retrieved data.
               //
               wprintf(L"\n\tClient: %s\n", pTmpBuf->sesi10_cname);
               wprintf(L"\tUser:   %s\n", pTmpBuf->sesi10_username);
               printf("\tActive: %d\n", pTmpBuf->sesi10_time);
               printf("\tIdle:   %d\n", pTmpBuf->sesi10_idle_time);

               pTmpBuf++;
               dwTotalCount++;
            }
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
      {
         NetApiBufferFree(pBuf);
         pBuf = NULL;
      }
   }
   //
   // Continue to call NetSessionEnum while
   //  there are more entries.
   //
   while (nStatus == ERROR_MORE_DATA); // end do

   // Check again for an allocated buffer.
   //
   if (pBuf != NULL)
      NetApiBufferFree(pBuf);
   //
   // Print the final count of sessions enumerated.
   //
   fprintf(stderr, "\nTotal of %d entries enumerated\n", dwTotalCount);

   return 0;
}

```

## See also

[NetSessionGetInfo](https://learn.microsoft.com/windows/desktop/api/lmshare/nf-lmshare-netsessiongetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[SESSION_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_0)

[SESSION_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_1)

[SESSION_INFO_10](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_10)

[SESSION_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_2)

[SESSION_INFO_502](https://learn.microsoft.com/windows/desktop/api/lmshare/ns-lmshare-session_info_502)

[Session
Functions](https://learn.microsoft.com/windows/desktop/NetShare/session-functions)