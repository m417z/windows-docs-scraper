# NetLocalGroupEnum function

## Description

The
**NetLocalGroupEnum** function returns information about each local group account on the specified server.

## Parameters

### `servername` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return local group names. The *bufptr* parameter points to an array of [LOCALGROUP_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_0) structures. |
| **1** | Return local group names and the comment associated with each group. The *bufptr* parameter points to an array of [LOCALGROUP_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_1) structures. |

### `bufptr` [out]

Pointer to the address of the buffer that receives the information structure. The format of this data depends on the value of the *level* parameter. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. Note that you must free the buffer even if the function fails with ERROR_MORE_DATA.

### `prefmaxlen` [in]

Specifies the preferred maximum length of returned data, in bytes. If you specify MAX_PREFERRED_LENGTH, the function allocates the amount of memory required for the data. If you specify another value in this parameter, it can restrict the number of bytes that the function returns. If the buffer size is insufficient to hold all entries, the function returns ERROR_MORE_DATA. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

### `entriesread` [out]

Pointer to a value that receives the count of elements actually enumerated.

### `totalentries` [out]

Pointer to a value that receives the approximate total number of entries that could have been enumerated from the current resume position. The total number of entries is only a hint. For more information about determining the exact number of entries, see the following Remarks section.

### `resumehandle` [in, out]

Pointer to a value that contains a resume handle that is used to continue an existing local group search. The handle should be zero on the first call and left unchanged for subsequent calls. If this parameter is **NULL**, then no resume handle is stored. For more information, see the following Remarks section.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_MORE_DATA** | More entries are available. Specify a large enough buffer to receive all entries. |
| **NERR_InvalidComputer** | The computer name is invalid. |
| **NERR_BufTooSmall** | The return buffer is too small. |

## Remarks

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits all authenticated users and members of the "[Pre-Windows 2000 compatible access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)" group to view the information. If you call this function on a member server or workstation, all authenticated users can view the information. For information about anonymous access and restricting anonymous access on these platforms, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The function only returns information to which the caller has Read access. The caller must have List Contents access to the Domain object, and Enumerate Entire SAM Domain access on the SAM Server object located in the System container.

To determine the exact total number of local groups, you must enumerate the entire tree, which can be a costly operation. To enumerate the entire tree, use the *resumehandle* parameter to continue the enumeration for consecutive calls, and use the *entriesread* parameter to accumulate the total number of local groups. If your application is communicating with a domain controller, you should consider using the
[ADSI LDAP Provider](https://learn.microsoft.com/windows/desktop/ADSI/adsi-ldap-provider) to retrieve this type of data more efficiently. The ADSI LDAP Provider implements a set of ADSI objects that support various ADSI interfaces. For more information, see
[ADSI Service Providers](https://learn.microsoft.com/windows/desktop/ADSI/adsi-system-providers).

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management local group functions. For more information, see
[IADsGroup](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsgroup).

## See also

[LOCALGROUP_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_0)

[LOCALGROUP_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_info_1)

[Local Group
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/local-group-functions)

[NetLocalGroupGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupgetinfo)

[NetLocalGroupGetMembers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupgetmembers)

[NetQueryDisplayInformation](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netquerydisplayinformation)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)