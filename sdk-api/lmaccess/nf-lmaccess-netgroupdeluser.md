# NetGroupDelUser function

## Description

The
**NetGroupDelUser** function removes a user from a particular global group in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory.

## Parameters

### `servername` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `GroupName` [in]

Pointer to a constant string that specifies the name of the global group from which the user's membership should be removed. For more information, see the following Remarks section.

### `Username` [in]

Pointer to a constant string that specifies the name of the user to remove from the global group. For more information, see the following Remarks section.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **NERR_InvalidComputer** | The computer name is invalid. |
| **NERR_NotPrimary** | The operation is allowed only on the primary domain controller of the domain. |
| **NERR_SpeGroupOp** | The operation is not allowed on certain special groups. These groups include user groups, admin groups, local groups, and guest groups. |
| **NERR_UserNotFound** | The user name could not be found. |
| **NERR_GroupNotFound** | The global group name could not be found. |
| **NERR_UserNotInGroup** | The user does not belong to this global group. |

## Remarks

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits only Domain Admins and Account Operators to call this function. On a member server or workstation, only Administrators and Power Users can call this function. For more information, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the Group object is used to perform the access check for this function.

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management group functions. For more information, see
[IADsGroup](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsgroup).

## See also

[Group Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/group-functions)

[NetGroupAdd](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupadd)

[NetGroupAddUser](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupadduser)

[NetGroupDel](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupdel)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)