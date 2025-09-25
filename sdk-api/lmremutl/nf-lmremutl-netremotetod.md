# NetRemoteTOD function

## Description

The
**NetRemoteTOD** function returns the time of day information from a specified server.

## Parameters

### `UncServerName` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `BufferPtr` [out]

Pointer to the address that receives the
[TIME_OF_DAY_INFO](https://learn.microsoft.com/windows/desktop/api/lmremutl/ns-lmremutl-time_of_day_info) information structure. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

No special group membership is required to successfully execute the
**NetRemoteTOD** function.

#### Examples

The following code sample demonstrates how to retrieve and print the current date and time with a call to the
**NetRemoteTOD** function. To do this, the sample uses the
[TIME_OF_DAY_INFO](https://learn.microsoft.com/windows/desktop/api/lmremutl/ns-lmremutl-time_of_day_info) structure. Finally, the sample frees the memory allocated for the information buffer.

```cpp
#include <stdio.h>
#include <windows.h>
#include <lm.h>
#pragma comment(lib, "netapi32.lib")

#ifndef UNICODE
#define UNICODE
#endif

int wmain(int argc, wchar_t *argv[])
{
   LPTIME_OF_DAY_INFO pBuf = NULL;
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
   // Call the NetRemoteTOD function.
   //
   nStatus = NetRemoteTOD((LPCWSTR) pszServerName,
                          (LPBYTE *)&pBuf);
   //
   // If the function succeeds, display the current date and time.
   //
   if (nStatus == NERR_Success)
   {
      if (pBuf != NULL)
      {
         fprintf(stderr, "\nThe current date is: %d/%d/%d\n",
                 pBuf->tod_month, pBuf->tod_day, pBuf->tod_year);
         fprintf(stderr, "The current time is: %d:%d:%d\n",
                 pBuf->tod_hours, pBuf->tod_mins, pBuf->tod_secs);
      }
   }
   //
   // Otherwise, display a system error.
   else
      fprintf(stderr, "A system error has occurred: %d\n", nStatus);
   //
   // Free the allocated buffer.
   //
   if (pBuf != NULL)
      NetApiBufferFree(pBuf);

   return 0;
}

```

## See also

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Remote
Utility Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/remote-utility-functions)

[TIME_OF_DAY_INFO](https://learn.microsoft.com/windows/desktop/api/lmremutl/ns-lmremutl-time_of_day_info)