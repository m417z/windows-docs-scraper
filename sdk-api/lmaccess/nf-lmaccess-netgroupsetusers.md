# NetGroupSetUsers function

## Description

The
**NetGroupSetUsers** function sets the membership for the specified global group. Each user you specify is enrolled as a member of the global group. Users you do not specify, but who are currently members of the global group, will have their membership revoked.

## Parameters

### `servername` [in]

A pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `groupname` [in]

A pointer to a constant string that specifies the name of the global group of interest. For more information, see the Remarks section.

### `level` [in]

The information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | The *buf* parameter points to an array of [GROUP_USERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_0) structures that specify user names. |
| **1** | The *buf* parameter points to an array of [GROUP_USERS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_1) structures that specifies user names and the attributes of the group. |

### `buf` [in]

A pointer to the buffer that contains the data. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `totalentries` [in]

The number of entries in the buffer pointed to by the *buf* parameter.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_LEVEL** | The system call level is not correct. This error is returned if the *level* parameter was specified as a value other than 0 or 1. |
| **ERROR_INVALID_PARAMETER** | A parameter passed was not valid. This error is returned if the *totalentries* parameter was not valid. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory was available to complete the operation. |
| **NERR_InvalidComputer** | The computer name is invalid. |
| **NERR_NotPrimary** | The operation is allowed only on the primary domain controller of the domain. |
| **NERR_GroupNotFound** | The global group name could not be found. |
| **NERR_InternalError** | An internal error occurred. |
| **NERR_SpeGroupOp** | The operation is not allowed on certain special groups. These groups include user groups, admin groups, local groups, and guest groups. |
| **NERR_UserNotFound** | The user name could not be found. |

## Remarks

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits only Domain Admins and Account Operators to call this function. On a member server or workstation, only Administrators and Power Users can call this function. For more information, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the Group object is used to perform the access check for this function.

You can replace the global group membership with an entirely new list of members by calling the
**NetGroupSetUsers** function. The typical sequence of steps to perform this follows.

**To replace the global group membership**

1. Call the
   [NetGroupGetUsers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupgetusers) function to retrieve the current membership list.
2. Modify the returned membership list to reflect the new membership.
3. Call the
   **NetGroupSetUsers** function to replace the old membership list with the new membership list.

To grant one user membership in an existing global group, you can call the
[NetGroupAddUser](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupadduser) function. To remove a user from a global group, call the
[NetGroupDelUser](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupdeluser) function.

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management group functions. For more information, see
[IADsGroup](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsgroup).

## See also

[GROUP_USERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_0)

[GROUP_USERS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_1)

[Group Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/group-functions)

[NetGroupAddUser](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupadduser)

[NetGroupDelUser](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupdeluser)

[NetGroupGetUsers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupgetusers)

[NetUserGetGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetgroups)

[NetUserSetGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusersetgroups)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)