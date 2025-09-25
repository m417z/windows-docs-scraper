# NetGroupEnum function

## Description

The
**NetGroupEnum** function retrieves information about each global group in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory.

The
[NetQueryDisplayInformation](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netquerydisplayinformation) function provides an efficient mechanism for enumerating global groups. When possible, it is recommended that you use
**NetQueryDisplayInformation** instead of the
**NetGroupEnum** function.

## Parameters

### `servername` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return the global group name. The *bufptr* parameter points to an array of [GROUP_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_0) structures. |
| **1** | Return the global group name and a comment. The *bufptr* parameter points to an array of [GROUP_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_1) structures. |
| **2** | Return detailed information about the global group. The *bufptr* parameter points to an array of [GROUP_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_2) structures. Note that on Windows XP and later, it is recommended that you use [GROUP_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_3) instead. |
| **3** | Return detailed information about the global group. The *bufptr* parameter points to an array of [GROUP_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_3) structures.<br><br>**Windows 2000:** This level is not supported. |

### `bufptr` [out]

Pointer to the buffer to receive the global group information structure. The format of this data depends on the value of the *level* parameter.

The system allocates the memory for this buffer. You must call the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function to deallocate the memory. Note that you must free the buffer even if the function fails with ERROR_MORE_DATA.

### `prefmaxlen` [in]

Specifies the preferred maximum length of the returned data, in bytes. If you specify MAX_PREFERRED_LENGTH, the function allocates the amount of memory required to hold the data. If you specify another value in this parameter, it can restrict the number of bytes that the function returns. If the buffer size is insufficient to hold all entries, the function returns ERROR_MORE_DATA. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

### `entriesread` [out]

Pointer to a value that receives the count of elements actually enumerated.

### `totalentries` [out]

Pointer to a value that receives the total number of entries that could have been enumerated from the current resume position. The total number of entries is only a hint. For more information about determining the exact number of entries, see the following Remarks section.

### `resume_handle` [in, out]

Pointer to a variable that contains a resume handle that is used to continue the global group enumeration. The handle should be zero on the first call and left unchanged for subsequent calls. If this parameter is **NULL**, no resume handle is stored.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **NERR_InvalidComputer** | The computer name is invalid. |
| **ERROR_MORE_DATA** | More entries are available. Specify a large enough buffer to receive all entries. |

## Remarks

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management group functions. For more information, see
[IADsGroup](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsgroup).

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits all authenticated users and members of the "[Pre-Windows 2000 compatible access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)" group to view the information. If you call this function on a member server or workstation, all authenticated users can view the information. For information about anonymous access and restricting anonymous access on these platforms, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The function only returns information to which the caller has Read access. The caller must have List Contents access to the Domain object, and Enumerate Entire SAM Domain access on the SAM Server object located in the System container.

To determine the exact total number of groups, you must enumerate the entire tree, which can be a costly operation. To enumerate the entire tree, use the *resume_handle* parameter to continue the enumeration for consecutive calls, and use the *entriesread* parameter to accumulate the total number of groups. If your application is communicating with a domain controller, you should consider using the
[ADSI LDAP Provider](https://learn.microsoft.com/windows/desktop/ADSI/adsi-ldap-provider) to retrieve this type of data more efficiently. The ADSI LDAP Provider implements a set of ADSI objects that support various ADSI interfaces. For more information, see
[ADSI Service Providers](https://learn.microsoft.com/windows/desktop/ADSI/adsi-system-providers).

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

## See also

[GROUP_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_0)

[GROUP_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_1)

[GROUP_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-group_info_3)

[Group Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/group-functions)

[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree)

[NetGroupGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupgetinfo)

[NetGroupGetUsers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netgroupgetusers)

[NetQueryDisplayInformation](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netquerydisplayinformation)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)