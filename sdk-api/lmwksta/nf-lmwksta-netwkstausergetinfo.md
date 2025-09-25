# NetWkstaUserGetInfo function

## Description

The
**NetWkstaUserGetInfo** function returns information about the currently logged-on user. This function must be called in the context of the logged-on user.

## Parameters

### `reserved`

This parameter must be set to **NULL**.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return the name of the user currently logged on to the workstation. The *bufptr* parameter points to a [WKSTA_USER_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_user_info_0) structure. |
| **1** | Return information about the workstation, including the name of the current user and the domains accessed by the workstation. The *bufptr* parameter points to a [WKSTA_USER_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_user_info_1) structure. |
| **1101** | Return domains browsed by the workstation. The *bufptr* parameter points to a [WKSTA_USER_INFO_1101](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_user_info_1101) structure. |

### `bufptr` [out]

Pointer to the buffer that receives the data. The format of this data depends on the value of the *bufptr* parameter. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | The system ran out of memory resources. Either the network manager configuration is incorrect, or the program is running on a system with insufficient memory. |
| **ERROR_INVALID_LEVEL** | The *level* parameter is invalid. |
| **ERROR_INVALID_PARAMETER** | One of the function parameters is invalid. |

## Remarks

The
**NetWkstaUserGetInfo** function only works locally.

#### Examples

The following code sample demonstrates how to retrieve information about the currently logged-on user using a call to the
**NetWkstaUserGetInfo** function. The sample calls
**NetWkstaUserGetInfo**, specifying information level 1 (
[WKSTA_USER_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_user_info_1)). If the call succeeds, the sample prints information about the logged-on user. Finally, the sample frees the memory allocated for the information buffer.

```cpp
#ifndef UNICODE
#define UNICODE
#endif
#pragma comment(lib, "netapi32.lib")

#include <stdio.h>
#include <windows.h>
#include <lm.h>

int wmain(void)
{
   DWORD dwLevel = 1;
   LPWKSTA_USER_INFO_1 pBuf = NULL;
   NET_API_STATUS nStatus;
   //
   // Call the NetWkstaUserGetInfo function;
   //  specify level 1.
   //
   nStatus = NetWkstaUserGetInfo(NULL,
                                 dwLevel,
                                 (LPBYTE *)&pBuf);
   //
   // If the call succeeds, print the information
   //  about the logged-on user.
   //
   if (nStatus == NERR_Success)
   {
      if (pBuf != NULL)
      {
         wprintf(L"\n\tUser:          %s\n", pBuf->wkui1_username);
         wprintf(L"\tDomain:        %s\n", pBuf->wkui1_logon_domain);
         wprintf(L"\tOther Domains: %s\n", pBuf->wkui1_oth_domains);
         wprintf(L"\tLogon Server:  %s\n", pBuf->wkui1_logon_server);
      }
   }
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

[NetWkstaSetInfo](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstasetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[WKSTA_USER_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_user_info_0)

[WKSTA_USER_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_user_info_1)

[WKSTA_USER_INFO_1101](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_user_info_1101)

[Workstation and Workstation User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/workstation-and-workstation-user-functions)