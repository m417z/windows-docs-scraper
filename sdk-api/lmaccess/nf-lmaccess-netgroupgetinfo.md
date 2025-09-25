# NetGroupGetInfo function

## Description

The
**NetGroupGetInfo** function retrieves information about a particular global group in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory.

## Parameters

### `servername` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `groupname` [in]

Pointer to a constant string that specifies the name of the global group for which to retrieve information. For more information, see the following Remarks section.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return the global group name. The *bufptr* parameter points to a [GROUP_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_0) structure. |
| **1** | Return the global group name and a comment. The *bufptr* parameter points to a [GROUP_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_1) structure. |
| **2** | Return detailed information about the global group. The *bufptr* parameter points to a [GROUP_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_2) structure. Note that on Windows XP and later, it is recommended that you use [GROUP_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_3) instead. |
| **3** | Return detailed information about the global group. The *bufptr* parameter points to a [GROUP_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_3) structure.<br><br>**Windows 2000:** This level is not supported. |

### `bufptr` [out]

Pointer to the address of the buffer that receives the global group information structure. The format of this data depends on the value of the *level* parameter. The system allocates the memory for this buffer. You must call the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function to deallocate the memory. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **NERR_InvalidComputer** | The computer name is invalid. |
| **NERR_GroupNotFound** | The global group name could not be found. |

## Remarks

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management group functions. For more information, see
[IADsGroup](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsgroup).

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits all authenticated users and members of the "[Pre-Windows 2000 compatible access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)" group to view the information. If you call this function on a member server or workstation, all authenticated users can view the information. For information about anonymous access and restricting anonymous access on these platforms, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the Group object is used to perform the access check for this function.

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

## See also

[GROUP_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_0)

[GROUP_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_1)

[GROUP_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_3)

[Group Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/group-functions)

[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree)

[NetGroupSetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupsetinfo)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)