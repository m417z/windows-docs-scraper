# NetGroupSetInfo function

## Description

The
**NetGroupSetInfo** function sets the parameters of a global group in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory.

## Parameters

### `servername` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `groupname` [in]

Pointer to a constant string that specifies the name of the global group for which to set information. For more information, see the following Remarks section.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Specifies a global group name. The *buf* parameter points to a [GROUP_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_0) structure. |
| **1** | Specifies a global group name and a comment. The *buf* parameter points to a [GROUP_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_1) structure. |
| **2** | Specifies detailed information about the global group. The *buf* parameter points to a [GROUP_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_2) structure. Note that on Windows XP and later, it is recommended that you use [GROUP_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_3) instead. |
| **3** | Specifies detailed information about the global group. The *buf* parameter points to a [GROUP_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_3) structure.<br><br>**Windows 2000:** This level is not supported. |
| **1002** | Specifies a comment only about the global group. The *buf* parameter points to a [GROUP_INFO_1002](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_1002) structure. |
| **1005** | Specifies global group attributes. The *buf* parameter points to a [GROUP_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_1005) structure. |

For more information, see the following Remarks section.

### `buf` [in]

Pointer to a buffer that contains the data. The format of this data depends on the value of the *level* parameter. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers).

### `parm_err` [out]

Pointer to a value that receives the index of the first member of the group information structure in error following an ERROR_INVALID_PARAMETER error code. If this parameter is **NULL**, the index is not returned on error. For more information, see the following Remarks section.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_PARAMETER** | One of the function parameters is invalid. For more information, see the following Remarks section. |
| **NERR_InvalidComputer** | The computer name is invalid. |
| **NERR_NotPrimary** | The operation is allowed only on the primary domain controller of the domain. |
| **NERR_GroupNotFound** | The global group name could not be found. |
| **NERR_SpeGroupOp** | The operation is not allowed on certain special groups. These groups include user groups, admin groups, local groups, and guest groups. |

## Remarks

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management group functions. For more information, see
[IADsGroup](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsgroup).

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits only Domain Admins and Account Operators to call this function. On a member server or workstation, only Administrators and Power Users can call this function. For more information, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the Group object is used to perform the access check for this function. Typically, callers must have write access to the entire object for calls to this function to succeed.

The correct way to set the new name of a global group is to call the
**NetGroupSetInfo** function, using a
[GROUP_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_0) structure. Specify the new value in the **grpi0_name** member. If you use a
[GROUP_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_1) structure and specify the value in the **grpi1_name** member, the new name value is ignored.

If the
**NetGroupSetInfo** function returns ERROR_INVALID_PARAMETER, you can use the *parm_err* parameter to indicate the first member of the group information structure that is invalid. (A group information structure begins with GROUP_INFO_ and its format is specified by the *level* parameter.) The following table lists the values that can be returned in the *parm_err* parameter and the corresponding structure member that is in error. (The prefix grpi*_ indicates that the member can begin with multiple prefixes, for example, grpi1_ or grpi2_.)

| Value | Member |
| --- | --- |
| GROUP_NAME_PARMNUM | grpi*_name |
| GROUP_COMMENT_PARMNUM | grpi*_comment |
| GROUP_ATTRIBUTES_PARMNUM | grpi*_attributes |

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

## See also

[GROUP_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_0)

[GROUP_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_1)

[GROUP_INFO_1002](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_1002)

[GROUP_INFO_1005](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_1005)

[GROUP_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_3)

[Group Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/group-functions)

[NetGroupGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupgetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)