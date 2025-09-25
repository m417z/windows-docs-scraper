# NetUserGetGroups function

## Description

The
**NetUserGetGroups** function retrieves a list of global groups to which a specified user belongs.

## Parameters

### `servername` [in]

A pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `username` [in]

A pointer to a constant string that specifies the name of the user to search for in each group account. For more information, see the following Remarks section.

### `level` [in]

The information level of the data requested. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return the names of the global groups to which the user belongs. The *bufptr* parameter points to an array of [GROUP_USERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_0) structures. |
| **1** | Return the names of the global groups to which the user belongs with attributes. The *bufptr* parameter points to an array of [GROUP_USERS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_1) structures. |

### `bufptr` [out]

A pointer to the buffer that receives the data. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. Note that you must free the buffer even if the function fails with ERROR_MORE_DATA.

### `prefmaxlen` [in]

The preferred maximum length, in bytes, of returned data. If MAX_PREFERRED_LENGTH is specified, the function allocates the amount of memory required for the data. If another value is specified in this parameter, it can restrict the number of bytes that the function returns. If the buffer size is insufficient to hold all entries, the function returns ERROR_MORE_DATA. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

### `entriesread` [out]

A pointer to a value that receives the count of elements actually retrieved.

### `totalentries` [out]

A pointer to a value that receives the total number of entries that could have been retrieved.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access rights to the requested information. |
| **ERROR_BAD_NETPATH** | The network path was not found. This error is returned if the *servername* parameter could not be found. |
| **ERROR_INVALID_LEVEL** | The system call level is not correct. This error is returned if the *level* parameter was specified as a value other than 0 or 1. |
| **ERROR_INVALID_NAME** | The name syntax is incorrect. This error is returned if the *servername* parameter has leading or trailing blanks or contains an illegal character. |
| **ERROR_MORE_DATA** | More entries are available. Specify a large enough buffer to receive all entries. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory was available to complete the operation. |
| **NERR_InternalError** | An internal error occurred. |
| **NERR_UserNotFound** | The user could not be found. This error is returned if the *username* could not be found. |

## Remarks

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management user functions. For more information, see
[IADsUser](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsuser) and
[IADsComputer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscomputer).

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits all authenticated users and members of the "[Pre-Windows 2000 compatible access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)" group to view the information. If you call this function on a member server or workstation, all authenticated users can view the information. For information about anonymous access and restricting anonymous access on these platforms, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the User object is used to perform the access check for this function.

To retrieve a list of the local groups to which a user belongs, you can call the
[NetUserGetLocalGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetlocalgroups) function. Network groups are separate and distinct from Windows NT system groups.

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

#### Examples

The following code sample demonstrates how to retrieve a list of global groups to which a user belongs with a call to the
**NetUserGetGroups** function. The sample calls
**NetUserGetGroups**, specifying information level 0 (
[GROUP_USERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_0)). The code loops through the entries and prints the name of the global groups in which the user has membership. The sample also prints the total number of entries that are available and the number of entries actually enumerated if they do not match. Finally, the code sample frees the memory allocated for the buffer.

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
   LPGROUP_USERS_INFO_0 pBuf = NULL;
   DWORD dwLevel = 0;
   DWORD dwPrefMaxLen = MAX_PREFERRED_LENGTH;
   DWORD dwEntriesRead = 0;
   DWORD dwTotalEntries = 0;
   NET_API_STATUS nStatus;

   if (argc != 3)
   {
      fwprintf(stderr, L"Usage: %s \\\\ServerName UserName\n", argv[0]);
      exit(1);
   }
   //
   // Call the NetUserGetGroups function, specifying level 0.
   //
   nStatus = NetUserGetGroups(argv[1],
                              argv[2],
                              dwLevel,
                              (LPBYTE*)&pBuf,
                              dwPrefMaxLen,
                              &dwEntriesRead,
                              &dwTotalEntries);
   //
   // If the call succeeds,
   //
   if (nStatus == NERR_Success)
   {
      LPGROUP_USERS_INFO_0 pTmpBuf;
      DWORD i;
      DWORD dwTotalCount = 0;

      if ((pTmpBuf = pBuf) != NULL)
      {
         fprintf(stderr, "\nGlobal group(s):\n");
         //
         // Loop through the entries;
         //  print the name of the global groups
         //  to which the user belongs.
         //
         for (i = 0; i < dwEntriesRead; i++)
         {
            assert(pTmpBuf != NULL);

            if (pTmpBuf == NULL)
            {
               fprintf(stderr, "An access violation has occurred\n");
               break;
            }

            wprintf(L"\t-- %s\n", pTmpBuf->grui0_name);

            pTmpBuf++;
            dwTotalCount++;
         }
      }
      //
      // If all available entries were
      //  not enumerated, print the number actually
      //  enumerated and the total number available.
      //
      if (dwEntriesRead < dwTotalEntries)
         fprintf(stderr, "\nTotal entries: %d", dwTotalEntries);
      //
      // Otherwise, just print the total.
      //
      printf("\nEntries enumerated: %d\n", dwTotalCount);
   }
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

[GROUP_USERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_0)

[GROUP_USERS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_1)

[NetGroupGetUsers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupgetusers)

[NetQueryDisplayInformation](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netquerydisplayinformation)

[NetUserGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetinfo)

[NetUserGetLocalGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetlocalgroups)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)