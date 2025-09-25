# NetUserSetGroups function

## Description

The
**NetUserSetGroups** function sets global group memberships for a specified user account.

## Parameters

### `servername` [in]

A pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `username` [in]

A pointer to a constant string that specifies the name of the user for which to set global group memberships. For more information, see the Remarks section.

### `level` [in]

The information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | The *buf* parameter points to an array of [GROUP_USERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_0) structures that specifies global group names. |
| **1** | The *buf* parameter points to an array of [GROUP_USERS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_1) structures that specifies global group names with attributes. |

### `buf` [in]

A pointer to the buffer that specifies the data. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `num_entries` [in]

The number of entries contained in the array pointed to by the *buf* parameter.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_LEVEL** | The system call level is not correct. This error is returned if the *level* parameter was specified as a value other than 0 or 1. |
| **ERROR_INVALID_PARAMETER** | A parameter passed was not valid. This error is returned if the *num_entries* parameter was not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory was available to complete the operation. |
| **NERR_InvalidComputer** | The computer name is invalid. |
| **NERR_NotPrimary** | The operation is allowed only on the primary domain controller of the domain. |
| **NERR_GroupNotFound** | The group group name specified by the **grui0_name** in the [GROUP_USERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_0) structure or **grui1_name** member in the [GROUP_USERS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_1) structure pointed to by the *buf* parameter does not exist. |
| **NERR_InternalError** | An internal error occurred. |
| **NERR_UserNotFound** | The user name could not be found. |

## Remarks

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management user functions. For more information, see
[IADsUser](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsuser) and
[IADsComputer](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadscomputer).

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits only Domain Admins and Account Operators to call this function. On a member server or workstation, only Administrators and Power Users can call this function. For more information, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the User object is used to perform the access check for this function.

To grant a user membership in one existing global group, you can call the
[NetGroupAddUser](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupadduser) function.

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

#### Examples

The following code sample demonstrates how to set global group memberships for a user account with a call to the
**NetUserSetGroups** function. The code sample fills in the **grui0_name** member of the
[GROUP_USERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_0) structure and calls
**NetUserSetGroups**, specifying information level 0.

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
   DWORD dwLevel = 0;
   GROUP_USERS_INFO_0 gi;
   NET_API_STATUS nStatus;

   if (argc != 4)
   {
      fwprintf(stderr, L"Usage: %s \\\\ServerName UserName GroupName\n", argv[0]);
      exit(1);
   }
   //
   // Fill in the GROUP_USERS_INFO_0 structure member.
   //
   gi.grui0_name = argv[3];
   //
   // Call the NetUserSetGroups function; specify level 0.
   //
   nStatus = NetUserSetGroups(argv[1],
                              argv[2],
                              dwLevel,
                              (LPBYTE)&gi,
                              1);
   //
   // If the call succeeds, inform the user.
   //
   if (nStatus == NERR_Success)
      fwprintf(stderr, L"Group membership has been successful for %s\n", argv[2]);
   //
   // Otherwise, print the system error.
   //
   else
      fprintf(stderr, "A system error has occurred: %d\n", nStatus);

   return 0;
}

```

## See also

[GROUP_USERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_0)

[GROUP_USERS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_1)

[NetGroupAddUser](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupadduser)

[NetUserGetGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetgroups)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[User Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/user-functions)