# NetLocalGroupSetInfo function

## Description

The
**NetLocalGroupSetInfo** function changes the name of an existing local group. The function also associates a comment with a local group.

## Parameters

### `servername` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `groupname` [in]

Pointer to a constant string that specifies the name of the local group account to modify. For more information, see the following Remarks section.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Specifies the local group name. The *buf* parameter points to a [LOCALGROUP_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_0) structure. Use this level to change the name of an existing local group. |
| **1** | Specifies the local group name and a comment to associate with the group. The *buf* parameter points to a [LOCALGROUP_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_1) structure. |
| **1002** | Specifies a comment to associate with the local group. The *buf* parameter points to a [LOCALGROUP_INFO_1002](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_1002) structure. |

### `buf` [in]

Pointer to a buffer that contains the local group information. The format of this data depends on the value of the *level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `parm_err` [out]

Pointer to a value that receives the index of the first member of the local group information structure that caused the ERROR_INVALID_PARAMETER error. If this parameter is **NULL**, the index is not returned on error. For more information, see the following Remarks section.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_PARAMETER** | One of the function parameters is invalid. For more information, see the following Remarks section. |
| **ERROR_NO_SUCH_ALIAS** | The specified local group does not exist. |
| **NERR_NotPrimary** | The operation is allowed only on the primary domain controller of the domain. |
| **NERR_InvalidComputer** | The computer name is invalid. |

## Remarks

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits only Domain Admins and Account Operators to call this function. On a member server or workstation, only Administrators and Power Users can call this function. For more information, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the LocalGroup object is used to perform the access check for this function. Typically, callers must have write access to the entire object for calls to this function to succeed.

To specify the new name of an existing local group, call
**NetLocalGroupSetInfo** with
[LOCALGROUP_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_0) and specify a value using the **lgrpi0_name** member. If you call the
**NetLocalGroupSetInfo** function with
[LOCALGROUP_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_1) and specify a new value using the **lgrpi1_name** member, that value will be ignored.

If the
**NetLocalGroupSetInfo** function returns ERROR_INVALID_PARAMETER, you can use the *parm_err* parameter to indicate the first member of the local group information structure that is invalid. (A local group information structure begins with LOCALGROUP_INFO_ and its format is specified by the *level* parameter.) The following table lists the values that can be returned in the *parm_err* parameter and the corresponding structure member that is in error. (The prefix lgrpi*_ indicates that the member can begin with multiple prefixes, for example, lgrpi0_ or lgrpi1_.)

| Value | Member |
| --- | --- |
| LOCALGROUP_NAME_PARMNUM | lgrpi*_name |
| LOCALGROUP_COMMENT_PARMNUM | lgrpi*_comment |

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management local group functions. For more information, see
[IADsGroup](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsgroup).

## See also

[LOCALGROUP_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_0)

[LOCALGROUP_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_1)

[LOCALGROUP_INFO_1002](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_1002)

[Local Group
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/local-group-functions)

[NetLocalGroupGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupgetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)