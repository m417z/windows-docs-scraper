# NetWkstaGetInfo function

## Description

The
**NetWkstaGetInfo** function returns information about the configuration of a workstation.

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **100** | Return information about the workstation environment, including platform-specific information, the name of the domain and the local computer, and information concerning the operating system. The *bufptr* parameter points to a [WKSTA_INFO_100](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_info_100) structure. |
| **101** | In addition to level 100 information, return the path to the LANMAN directory. The *bufptr* parameter points to a [WKSTA_INFO_101](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_info_101) structure. |
| **102** | In addition to level 101 information, return the number of users who are logged on to the local computer. The *bufptr* parameter points to a [WKSTA_INFO_102](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_info_102) structure. |

### `bufptr` [out]

Pointer to the buffer that receives the data. The format of this data depends on the value of the *level* parameter. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_LEVEL** | The *level* parameter is invalid. |

## Remarks

**Windows Server 2003 and Windows XP:**  If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the ACL for the securable object. To enable anonymous access, the user Anonymous must be a member of the "Pre-Windows 2000 compatible access" group. This is because anonymous tokens do not include the Everyone group SID by default. If you call this function on a member server or workstation, all authenticated users can view the information. Anonymous access is also permitted if the EveryoneIncludesAnonymous policy setting allows anonymous access. Anonymous access is always permitted for level 100. If you call this function at level 101, authenticated users can view the information. Members of the Administrators, and the Server, System and Print Operator local groups can view information at levels 102 and 502. For more information about restricting anonymous access, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

**Windows 2000:** If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the securable object. The default ACL permits all authenticated users and members of the "
[Pre-Windows 2000 compatible access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)" group to view the information. By default, the "Pre-Windows 2000 compatible access" group includes Everyone as a member. This enables anonymous access to the information if the system allows anonymous access. If you call this function on a member server or workstation, all authenticated users can view the information. Anonymous access is also permitted if the RestrictAnonymous policy setting allows anonymous access.

To compile an application that uses this function, define the _WIN32_WINNT macro as 0x0400 or later. For more information,see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

#### Examples

The following code sample demonstrates how to retrieve information about the configuration elements for a workstation using a call to the
**NetWkstaGetInfo** function. The sample calls
**NetWkstaGetInfo**, specifying information level 102 (
[WKSTA_INFO_102](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_info_102)). If the call succeeds, the sample prints information about the workstation. Finally, the code sample frees the memory allocated for the information buffer.

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
   DWORD dwLevel = 102;
   LPWKSTA_INFO_102 pBuf = NULL;
   NET_API_STATUS nStatus;
   LPWSTR pszServerName = NULL;
   //
   // Check command line arguments.
   //
   if (argc > 2)
   {
      fwprintf(stderr, L"Usage: %s [\\\\ServerName]\n", argv[0]);
      exit(1);
   }
   // The server is not the default local computer.
   //
   if (argc == 2)
      pszServerName = argv[1];
   //
   // Call the NetWkstaGetInfo function, specifying level 102.
   //
   nStatus = NetWkstaGetInfo(pszServerName,
                             dwLevel,
                             (LPBYTE *)&pBuf);
   //
   // If the call is successful,
   //  print the workstation data.
   //
   if (nStatus == NERR_Success)
   {
      printf("\n\tPlatform: %d\n", pBuf->wki102_platform_id);
      wprintf(L"\tName:     %s\n", pBuf->wki102_computername);
      printf("\tVersion:  %d.%d\n", pBuf->wki102_ver_major,
                                  pBuf->wki102_ver_minor);
      wprintf(L"\tDomain:   %s\n", pBuf->wki102_langroup);
      wprintf(L"\tLan Root: %s\n", pBuf->wki102_lanroot);
      wprintf(L"\t# Logged On Users: %d\n", pBuf->wki102_logged_on_users);
   }
   //
   // Otherwise, indicate the system error.
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

[WKSTA_INFO_100](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_info_100)

[WKSTA_INFO_101](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_info_101)

[WKSTA_INFO_102](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_info_102)

[Workstation and Workstation User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/workstation-and-workstation-user-functions)