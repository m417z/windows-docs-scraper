# NetGroupGetUsers function

## Description

The
**NetGroupGetUsers** function retrieves a list of the members in a particular global group in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory.

## Parameters

### `servername` [in]

A pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `groupname` [in]

A pointer to a constant string that specifies the name of the global group whose members are to be listed. For more information, see the following Remarks section.

### `level` [in]

The information level of the data requested. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return the global group's member names. The *bufptr* parameter points to an array of [GROUP_USERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_0) structures. |
| **1** | Return the global group's member names and attributes. The *bufptr* parameter points to an array of [GROUP_USERS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_1) structures. |

### `bufptr` [out]

A pointer to the address of the buffer that receives the information structure. The system allocates the memory for this buffer. You must call the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function to deallocate the memory. Note that you must free the buffer even if the function fails with ERROR_MORE_DATA.

### `prefmaxlen` [in]

The preferred maximum length of the returned data, in bytes. If you specify MAX_PREFERRED_LENGTH, the function allocates the amount of memory required to hold the data. If you specify another value in this parameter, it can restrict the number of bytes that the function returns. If the buffer size is insufficient to hold all entries, the function returns ERROR_MORE_DATA. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

### `entriesread` [out]

A pointer to a value that receives the count of elements actually enumerated.

### `totalentries` [out]

A pointer to a value that receives the total number of entries that could have been enumerated from the current resume position.

### `ResumeHandle` [in, out]

A pointer to a variable that contains a resume handle that is used to continue an existing user enumeration. The handle should be zero on the first call and left unchanged for subsequent calls. If *ResumeHandle* parameter is **NULL**, no resume handle is stored.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_LEVEL** | The system call level is not correct. This error is returned if the *level* parameter was specified as a value other than 0 or 1. |
| **ERROR_MORE_DATA** | More entries are available. Specify a large enough buffer to receive all entries. |
| **ERROR_NOT_ENOUGH_MEMORY** | Insufficient memory was available to complete the operation. |
| **NERR_InvalidComputer** | The computer name is invalid. |
| **NERR_GroupNotFound** | The global group name in the structure pointed to by *bufptr* parameter could not be found. |
| **NERR_InternalError** | An internal error occurred. |

## Remarks

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits all authenticated users and members of the "[Pre-Windows 2000 compatible access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)" group to view the information. If you call this function on a member server or workstation, all authenticated users can view the information. For information about anonymous access and restricting anonymous access on these platforms, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the Group object is used to perform the access check for this function.

To grant one user membership in an existing global group, you can call the
[NetGroupAddUser](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupadduser) function. To remove a user from a global group, call the
[NetGroupDelUser](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupdeluser) function. For information about replacing the membership of a global group, see
[NetGroupSetUsers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupsetusers).

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management group functions. For more information, see
[IADsGroup](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsgroup).

## See also

[GROUP_USERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_0)

[GROUP_USERS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_users_info_1)

[Group Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/group-functions)

[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree)

[NetGroupAddUser](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupadduser)

[NetGroupDelUser](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupdeluser)

[NetGroupSetUsers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupsetusers)

[NetQueryDisplayInformation](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netquerydisplayinformation)

[NetUserGetGroups](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netusergetgroups)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)