# NetWkstaUserEnum function

## Description

The
**NetWkstaUserEnum** function lists information about all users currently logged on to the workstation. This list includes interactive, service and batch logons.

## Parameters

### `servername` [in]

Pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return the names of users currently logged on to the workstation. The *bufptr* parameter points to an array of [WKSTA_USER_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_user_info_0) structures. |
| **1** | Return the names of the current users and the domains accessed by the workstation. The *bufptr* parameter points to an array of [WKSTA_USER_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_user_info_1) structures. |

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

### `resumehandle` [in, out]

Pointer to a value that contains a resume handle which is used to continue an existing search. The handle should be zero on the first call and left unchanged for subsequent calls. If this parameter is **NULL**, no resume handle is stored.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_MORE_DATA** | More entries are available. Specify a large enough buffer to receive all entries. |
| **ERROR_INVALID_LEVEL** | The *level* parameter is invalid. |

## Remarks

Note that since the
**NetWkstaUserEnum** function lists entries for service and batch logons, as well as for interactive logons, the function can return entries for users who have logged off a workstation. This can occur, for example, when a user calls a service that impersonates the user. In this instance,
**NetWkstaUserEnum** returns an entry for the user until the service stops impersonating the user.

**Windows Server 2003 and Windows XP:** If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the ACL for the securable object. To enable anonymous access, the user Anonymous must be a member of the "Pre-Windows 2000 compatible access" group. This is because anonymous tokens do not include the Everyone group SID by default. If you call this function on a member server or workstation, all authenticated users can view the information. Anonymous access is also permitted if the RestrictAnonymous policy setting permits anonymous access. If the RestrictAnonymous policy setting does not permit anonymous access, only an administrator can successfully execute the function. Members of the Administrators, and the Server, System and Print Operator local groups can also view information. For more information about restricting anonymous access, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

**Windows 2000:** If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the securable object. The default ACL permits all authenticated users and members of the "
[Pre-Windows 2000 compatible access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)" group to view the information. By default, the "Pre-Windows 2000 compatible access" group includes Everyone as a member. This enables anonymous access to the information if the system allows anonymous access. If you call this function on a member server or workstation, all authenticated users can view the information. Anonymous access is also permitted if the RestrictAnonymous policy setting allows anonymous access.

To compile an application that uses this function, define the _WIN32_WINNT macro as 0x0400 or later. For more information,see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

#### Examples

The following code sample demonstrates how to list information about all users currently logged on to a workstation using a call to the
**NetWkstaUserEnum** function. The sample calls
**NetWkstaUserEnum**, specifying information level 0 (
[WKSTA_USER_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_user_info_0)). The sample loops through the entries and prints the names of the users logged on to a workstation. Finally, the code sample frees the memory allocated for the information buffer, and prints the total number of users enumerated.

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
   LPWKSTA_USER_INFO_0 pBuf = NULL;
   LPWKSTA_USER_INFO_0 pTmpBuf;
   DWORD dwLevel = 0;
   DWORD dwPrefMaxLen = MAX_PREFERRED_LENGTH;
   DWORD dwEntriesRead = 0;
   DWORD dwTotalEntries = 0;
   DWORD dwResumeHandle = 0;
   DWORD i;
   DWORD dwTotalCount = 0;
   NET_API_STATUS nStatus;
   LPWSTR pszServerName = NULL;

   if (argc > 2)
   {
      fwprintf(stderr, L"Usage: %s [\\\\ServerName]\n", argv[0]);
      exit(1);
   }
   // The server is not the default local computer.
   //
   if (argc == 2)
      pszServerName = argv[1];
   fwprintf(stderr, L"\nUsers currently logged on %s:\n", pszServerName);
   //
   // Call the NetWkstaUserEnum function, specifying level 0.
   //
   do // begin do
   {
      nStatus = NetWkstaUserEnum( pszServerName,
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
                  //
                  // Only members of the Administrators local group
                  //  can successfully execute NetWkstaUserEnum
                  //  locally and on a remote server.
                  //
                  fprintf(stderr, "An access violation has occurred\n");
                  break;
               }
               //
               // Print the user logged on to the workstation.
               //
               wprintf(L"\t-- %s\n", pTmpBuf->wkui0_username);

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
   // Continue to call NetWkstaUserEnum while
   //  there are more entries.
   //
   while (nStatus == ERROR_MORE_DATA); // end do
   //
   // Check again for allocated memory.
   //
   if (pBuf != NULL)
      NetApiBufferFree(pBuf);
   //
   // Print the final count of workstation users.
   //
   fprintf(stderr, "\nTotal of %d entries enumerated\n", dwTotalCount);

   return 0;
}

```

## See also

[NetWkstaGetInfo](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstagetinfo)

[NetWkstaSetInfo](https://learn.microsoft.com/windows/desktop/api/lmwksta/nf-lmwksta-netwkstasetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[WKSTA_USER_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_user_info_0)

[WKSTA_USER_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmwksta/ns-lmwksta-wksta_user_info_1)

[Workstation and Workstation User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/workstation-and-workstation-user-functions)