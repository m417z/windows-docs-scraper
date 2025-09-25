# NetLocalGroupSetMembers function

## Description

The
**NetLocalGroupSetMembers** function sets the membership for the specified local group. Each user or global group specified is made a member of the local group. Users or global groups that are not specified but who are currently members of the local group will have their membership revoked.

## Parameters

### `servername` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `groupname` [in]

Pointer to a constant string that specifies the name of the local group in which the specified users or global groups should be granted membership. For more information, see the following Remarks section.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Specifies the [security identifier](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-identifiers) (SID) associated with a local group member. The *buf* parameter points to an array of [LOCALGROUP_MEMBERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_members_info_0) structures. |
| **3** | Specifies the account and domain names of the local group member. The *buf* parameter points to an array of [LOCALGROUP_MEMBERS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_members_info_3) structures. |

### `buf` [in]

Pointer to the buffer that contains the member information. The format of this data depends on the value of the *level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `totalentries` [in]

Specifies a value that contains the total number of entries in the buffer pointed to by the *buf* parameter.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **NERR_GroupNotFound** | The group specified by the *groupname* parameter does not exist. |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_NO_SUCH_MEMBER** | One or more of the members doesn't exist. The local group membership was not changed. |
| **ERROR_INVALID_MEMBER** | One or more of the members cannot be added because it has an invalid account type. The local group membership was not changed. |

## Remarks

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits only Domain Admins and Account Operators to call this function. On a member server or workstation, only Administrators and Power Users can call this function. For more information, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the LocalGroup object is used to perform the access check for this function.

You can replace the local group membership with an entirely new list of members by calling the
**NetLocalGroupSetMembers** function. The typical sequence of steps to perform this follows.

**To replace the local group membership**

1. Call the
   [NetLocalGroupGetMembers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupgetmembers) function to retrieve the current membership list.
2. Modify the returned membership list to reflect the new membership.
3. Call the
   **NetLocalGroupSetMembers** function to replace the old membership list with the new membership list.

To add one or more existing user accounts or global group accounts to an existing local group, you can call the
[NetLocalGroupAddMembers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupaddmembers) function. To remove one or more members from an existing local group, call the
[NetLocalGroupDelMembers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupdelmembers) function.

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management local group functions. For more information, see
[IADsGroup](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsgroup).

## See also

[LOCALGROUP_MEMBERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_members_info_0)

[LOCALGROUP_MEMBERS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_members_info_3)

[Local Group
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/local-group-functions)

[NetLocalGroupAddMembers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupaddmembers)

[NetLocalGroupDelMembers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupdelmembers)

[NetLocalGroupGetMembers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupgetmembers)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)