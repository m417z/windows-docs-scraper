## Description

The **NetServerTransportEnum** function supplies information about transport protocols that are managed by the server.

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return information about the transport protocol, including name, address, and location on the network. The *bufptr* parameter points to an array of [SERVER_TRANSPORT_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_0) structures. |
| **1** | Return information about the transport protocol, including name, address, network location, and domain. The *bufptr* parameter points to an array of [SERVER_TRANSPORT_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_1) structures. |

### `bufptr` [out]

Pointer to the buffer that receives the data. The format of this data depends on the value of the *level* parameter. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. Note that you must free the buffer even if the function fails with ERROR_MORE_DATA.

### `prefmaxlen` [in]

Specifies the preferred maximum length of returned data, in bytes. If you specify MAX_PREFERRED_LENGTH, the function allocates the amount of memory required for the data. If you specify another value in this parameter, it can restrict the number of bytes that the function returns. If the buffer size is insufficient to hold all entries, the function returns ERROR_MORE_DATA. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

### `entriesread` [out]

Pointer to a value that receives the count of elements actually enumerated.

### `totalentries` [out]

Pointer to a value that receives the total number of entries that could have been enumerated from the current resume position. Note that applications should consider this value only as a hint.

### `resume_handle` [in, out]

Pointer to a value that contains a resume handle which is used to continue an existing server transport search. The handle should be zero on the first call and left unchanged for subsequent calls. If this parameter is **NULL**, no resume handle is stored.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_LEVEL** | The value specified for the *level* parameter is invalid. |
| **ERROR_MORE_DATA** | More entries are available. Specify a large enough buffer to receive all entries. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory is available. |
| **NERR_BufTooSmall** | The supplied buffer is too small. |

## Remarks

Only Authenticated Users can successfully call this function.**Windows XP/2000:** No special group membership is required to successfully execute this function.

## Examples

The following code sample demonstrates how to retrieve information about transport protocols that are managed by the server, using a call to the
**NetServerTransportEnum** function. The sample calls
**NetServerTransportEnum**, specifying information level 0 (
[SERVER_TRANSPORT_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_0)). The sample prints the name of each transport protocol and the total number enumerated. Finally, the code sample frees the memory allocated for the information buffer.

```cpp
#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")

#include <stdio.h>
#include <assert.h>
#include <windows.h>
#include <lm.h>

int wmain(int argc, wchar_t *argv[])
{
   LPSERVER_TRANSPORT_INFO_0 pBuf = NULL;
   LPSERVER_TRANSPORT_INFO_0 pTmpBuf;
   DWORD dwLevel = 0;
   DWORD dwPrefMaxLen = MAX_PREFERRED_LENGTH;
   DWORD dwEntriesRead = 0;
   DWORD dwTotalEntries = 0;
   DWORD dwResumeHandle = 0;
   DWORD dwTotalCount = 0;
   NET_API_STATUS nStatus;
   LPTSTR pszServerName = NULL;
   DWORD i;

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
   // Call the NetServerTransportEnum function; specify level 0.
   //
   do // begin do
   {
      nStatus = NetServerTransportEnum(pszServerName,
                                       dwLevel,
                                       (LPBYTE *) &pBuf,
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
            // Loop through the entries;
            //  process access errors.
            //
            for (i = 0; i < dwEntriesRead; i++)
            {
               assert(pTmpBuf != NULL);

               if (pTmpBuf == NULL)
               {
                  fprintf(stderr, "An access violation has occurred\n");
                  break;
               }
               //
               // Print the transport protocol name.
               //
               wprintf(L"\tTransport: %s\n", pTmpBuf->svti0_transportname);

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
      // Free the allocated buffer.
      //
      if (pBuf != NULL)
      {
         NetApiBufferFree(pBuf);
         pBuf = NULL;
      }
   //
   // Continue to call NetServerTransportEnum while
   //  there are more entries.
   //
   }
   while (nStatus == ERROR_MORE_DATA); // end do

   // Check again for an allocated buffer.
   //
   if (pBuf != NULL)
      NetApiBufferFree(pBuf);
   //
   // Print the final count of transports enumerated.
   //
   fprintf(stderr, "\nTotal of %d entries enumerated\n", dwTotalCount);

   return 0;
}
```

## See also

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[SERVER_TRANSPORT_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_0)

[SERVER_TRANSPORT_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmserver/ns-lmserver-server_transport_info_1)

[Server and Workstation Transport Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/server-and-workstation-transport-functions)