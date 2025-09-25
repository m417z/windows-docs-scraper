# NetLocalGroupAdd function

## Description

The
**NetLocalGroupAdd** function creates a local group in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory.

## Parameters

### `servername` [in]

A pointer to a string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `level` [in]

The information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | A local group name. The *buf* parameter points to a [LOCALGROUP_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_0) structure. |
| **1** | A local group name and a comment to associate with the group. The *buf* parameter points to a [LOCALGROUP_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_1) structure. |

### `buf` [in]

A pointer to a buffer that contains the local group information structure. The format of this data depends on the value of the *level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `parm_err` [out]

A pointer to a value that receives the index of the first member of the local group information structure to cause the ERROR_INVALID_PARAMETER error. If this parameter is **NULL**, the index is not returned on error. For more information, see the Remarks section in the
[NetLocalGroupSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupsetinfo) topic.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The caller does not have the appropriate access to complete the operation. |
| **ERROR_ALIAS_EXISTS** | The specified local group already exists. This error is returned if the group name member in the structure pointed to by the *buf* parameter is already in use as an alias. |
| **ERROR_INVALID_LEVEL** | A *level* parameter is invalid. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if one or more of the members in the structure pointed to by the *buf* parameter is invalid. |
| **NERR_GroupExists** | The group name exists. This error is returned if the group name member in the structure pointed to by the *buf* parameter is already in use as a group name. |
| **NERR_InvalidComputer** | The computer name is invalid. |
| **NERR_NotPrimary** | The operation is allowed only on the primary domain controller of the domain. |
| **NERR_UserExists** | The user name exists. This error is returned if the group name member in the structure pointed to by the *buf* parameter is already in use as a user name. |

## Remarks

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits only Domain Admins and Account Operators to call this function. On a member server or workstation, only Administrators and Power Users can call this function. For more information, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the user container is used to perform the access check for this function. The caller must be able to create child objects of the group class.

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

If the
**NetLocalGroupAdd** function returns **ERROR_INVALID_PARAMETER** and a **NULL** pointer was not passed in *parm_err* parameter, on return the *parm_err* parameter indicates the first member of the local group information structure that is invalid. The format of the local group information structure is specified in the *level* parameter. A pointer to the local group information structure is passed in *buf* parameter. The following table lists the values that can be returned in the *parm_err* parameter and the corresponding structure member that is in error.

| Value | Member |
| --- | --- |
| LOCALGROUP_NAME_PARMNUM | If the *level* parameter was 0, the **lgrpi0_name** member of the [LOCALGROUP_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_0) structure was invalid.<br><br>If the *level* parameter was 1, the **lgrpi1_name** member of the [LOCALGROUP_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_1) structure was invalid. |
| LOCALGROUP_COMMENT_PARMNUM | If the *level* parameter was 1, the **lgrpi1_comment** member of the [LOCALGROUP_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_1) structure was invalid. |

When making requests to a domain controller and Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same results as the network management local group functions. For more information, see
[IADsGroup](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsgroup).

## See also

[LOCALGROUP_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_0)

[LOCALGROUP_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_1)

[Local Group
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/local-group-functions)

[NetLocalGroupAddMembers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupaddmembers)

[NetLocalGroupDel](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupdel)

[NetLocalGroupSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupsetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers)