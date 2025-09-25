# NetWkstaUserSetInfo function

## Description

The
**NetWkstaUserSetInfo** function sets the user-specific information about the configuration elements for a workstation.

## Parameters

### `reserved`

This parameter must be set to zero.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **1** | Specifies information about the workstation, including the name of the current user and the domains accessed by the workstation. The *buf* parameter points to a [WKSTA_USER_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_user_info_1) structure. |
| **1101** | Specifies domains browsed by the workstation. The *buf* parameter points to a [WKSTA_USER_INFO_1101](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_user_info_1101) structure. |

### `buf` [in]

Pointer to the buffer that specifies the data. The format of this data depends on the value of the *level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `parm_err` [out]

Pointer to a value that receives the index of the first parameter that causes the ERROR_INVALID_PARAMETER error. If this parameter is **NULL**, the index is not returned on error.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_LEVEL** | The *level* parameter is invalid. |
| **ERROR_INVALID_PARAMETER** | One of the function parameters is invalid. |

## Remarks

The
**NetWkstaUserSetInfo** function only works locally. Administrator group membership is required.

Domain names in the **wkui1101_oth_domains** member of the
[WKSTA_USER_INFO_1101](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_user_info_1101) structure are separated by spaces. An empty list is valid. A **NULL** pointer means to leave the member unmodified. The **wkui1101_oth_domains** member cannot be set with MS-DOS. When setting this element,
**NetWkstaUserSetInfo** rejects the request if the name list was invalid or if a name could not be added to one or more of the network adapters managed by the system.

If the
**NetWkstaUserSetInfo** function returns ERROR_INVALID_PARAMETER, you can use the *parm_err* parameter to indicate the member of the workstation user information structure that is invalid. (A workstation user information structure begins with WKSTA_USER_INFO_ and its format is specified by the *level* parameter.) The following table lists the value that can be returned in the *parm_err* parameter and the corresponding structure member that is in error. (The prefix wkui*_ indicates that the member can begin with multiple prefixes, for example, wkui0_ or wkui1_.)

| Value | Member |
| --- | --- |
| WKSTA_OTH_DOMAINS_PARMNUM | wkui*_oth_domains |

#### Examples

The following code sample demonstrates how to set user-specific information for a workstation using a call to the
**NetWkstaUserSetInfo** function, specifying information level 1101 (
[WKSTA_USER_INFO_1101](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_user_info_1101)).

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
   DWORD dwLevel = 1101;
   WKSTA_USER_INFO_1101 wui;
   NET_API_STATUS nStatus;

   if (argc != 2)
   {
      fwprintf(stderr, L"Usage: %s OtherDomains\n", argv[0]);
      exit(1);
   }
   //
   // Fill in the WKSTA_USER_INFO_1101 structure member.
   //
   wui.wkui1101_oth_domains = argv[1];
   //
   // Call the NetWkstaUserSetInfo function
   //  to change the list of domains browsed by
   //  the workstation; specify level 1101.
   //
   nStatus = NetWkstaUserSetInfo(NULL,
                                 dwLevel,
                                 (LPBYTE)&wui,
                                 NULL);
   //
   // Display the result of the call.
   //
   if (nStatus == NERR_Success)
      fprintf(stderr, "Workstation user information has been changed\n");
   else
      fprintf(stderr, "A system error has occurred: %d\n", nStatus);

   return 0;
}

```

## See also

[NetWkstaUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstausergetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[WKSTA_USER_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_user_info_1)

[WKSTA_USER_INFO_1101](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_user_info_1101)

[Workstation and Workstation User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/workstation-and-workstation-user-functions)