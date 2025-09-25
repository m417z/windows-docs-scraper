# NetUserGetLocalGroups function

## Description

The
**NetUserGetLocalGroups** function retrieves a list of local groups to which a specified user belongs.

## Parameters

### `servername` [in]

A pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `username` [in]

A pointer to a constant string that specifies the name of the user for which to return local group membership information. If the string is of the form *DomainName*\*UserName* the user name is expected to be found on that domain. If the string is of the form *UserName*, the user name is expected to be found on the server specified by the *servername* parameter. For more information, see the Remarks section.

### `level` [in]

The information level of the data. This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **0** | Return the names of the local groups to which the user belongs. The *bufptr* parameter points to an array of [LOCALGROUP_USERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_users_info_0) structures. |

### `flags` [in]

A bitmask of flags that affect the operation. Currently, only the value defined is **LG_INCLUDE_INDIRECT**. If this bit is set, the function also returns the names of the local groups in which the user is indirectly a member (that is, the user has membership in a global group that is itself a member of one or more local groups).

### `bufptr` [out]

A pointer to the buffer that receives the data. The format of this data depends on the value of the *level* parameter. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. Note that you must free the buffer even if the function fails with **ERROR_MORE_DATA**.

### `prefmaxlen` [in]

The preferred maximum length, in bytes, of the returned data. If **MAX_PREFERRED_LENGTH** is specified in this parameter, the function allocates the amount of memory required for the data. If another value is specified in this parameter, it can restrict the number of bytes that the function returns. If the buffer size is insufficient to hold all entries, the function returns **ERROR_MORE_DATA**. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

### `entriesread` [out]

A pointer to a value that receives the count of elements actually enumerated.

### `totalentries` [out]

A pointer to a value that receives the total number of entries that could have been enumerated.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access rights to the requested information. This error is also returned if the *servername* parameter has a trailing blank. |
| **ERROR_INVALID_LEVEL** | The system call level is not correct. This error is returned if the *level* parameter was not specified as 0. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if the *flags* parameter contains a value other than **LG_INCLUDE_INDIRECT**. |
| **ERROR_MORE_DATA** | More entries are available. Specify a large enough buffer to receive all entries. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory was available to complete the operation. |
| **NERR_DCNotFound** | The domain controller could not be found. |
| **NERR_UserNotFound** | The user could not be found. This error is returned if the *username* could not be found. |
| **RPC_S_SERVER_UNAVAILABLE** | The RPC server is unavailable. This error is returned if the *servername* parameter could not be found. |

## Remarks

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management user functions. For more information, see
[IADsUser](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsuser) and
[IADsComputer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscomputer).

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits all authenticated users and members of the "[Pre-Windows 2000 compatible access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)" group to view the information. If you call this function on a member server or workstation, all authenticated users can view the information. For information about anonymous access and restricting anonymous access on these platforms, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the Domain object is used to perform the access check for this function. The caller must have Read Property permission on the Domain object.

To retrieve a list of global groups to which a specified user belongs, you can call the
[NetUserGetGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetgroups) function.

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

#### Examples

The following code sample demonstrates how to retrieve a list of the local groups to which a user belongs with a call to the
**NetUserGetLocalGroups** function. The sample calls
**NetUserGetLocalGroups**, specifying information level 0 ([LOCALGROUP_USERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_users_info_0)). The sample loops through the entries and prints the name of each local group in which the user has membership. If all available entries are not enumerated, it also prints the number of entries actually enumerated and the total number of entries available. Finally, the code sample frees the memory allocated for the information buffer.

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
   LPLOCALGROUP_USERS_INFO_0 pBuf = NULL;
   DWORD dwLevel = 0;
   DWORD dwFlags = LG_INCLUDE_INDIRECT ;
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
   // Call the NetUserGetLocalGroups function
   //  specifying information level 0.
   //
   //  The LG_INCLUDE_INDIRECT flag specifies that the
   //   function should also return the names of the local
   //   groups in which the user is indirectly a member.
   //
   nStatus = NetUserGetLocalGroups(argv[1],
                                   argv[2],
                                   dwLevel,
                                   dwFlags,
                                   (LPBYTE *) &pBuf,
                                   dwPrefMaxLen,
                                   &dwEntriesRead,
                                   &dwTotalEntries);
   //
   // If the call succeeds,
   //
   if (nStatus == NERR_Success)
   {
      LPLOCALGROUP_USERS_INFO_0 pTmpBuf;
      DWORD i;
      DWORD dwTotalCount = 0;

      if ((pTmpBuf = pBuf) != NULL)
      {
         fprintf(stderr, "\nLocal group(s):\n");
         //
         // Loop through the entries and
         //  print the names of the local groups
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

            wprintf(L"\t-- %s\n", pTmpBuf->lgrui0_name);

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
   // Free the allocated memory.
   //
   if (pBuf != NULL)
      NetApiBufferFree(pBuf);

   return 0;
}

```

## See also

[LOCALGROUP_USERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_users_info_0)

[NetUserGetGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetgroups)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)