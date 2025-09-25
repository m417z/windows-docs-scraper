# NetLocalGroupGetMembers function

## Description

The
**NetLocalGroupGetMembers** function retrieves a list of the members of a particular local group in the security database, which is the security accounts manager (SAM) database or, in the case of domain controllers, the Active Directory. Local group members can be users or global groups.

## Parameters

### `servername` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `localgroupname` [in]

Pointer to a constant string that specifies the name of the local group whose members are to be listed. For more information, see the following Remarks section.

### `level` [in]

Specifies the information level of the data. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Return the [security identifier](https://learn.microsoft.com/windows/desktop/SecAuthZ/security-identifiers) (SID) associated with the local group member. The *bufptr* parameter points to an array of [LOCALGROUP_MEMBERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_members_info_0) structures. |
| **1** | Return the SID and account information associated with the local group member. The *bufptr* parameter points to an array of [LOCALGROUP_MEMBERS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_members_info_1) structures. |
| **2** | Return the SID, account information, and the domain name associated with the local group member. The *bufptr* parameter points to an array of [LOCALGROUP_MEMBERS_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_members_info_2) structures. |
| **3** | Return the account and domain names of the local group member. The *bufptr* parameter points to an array of [LOCALGROUP_MEMBERS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_members_info_3) structures. |

### `bufptr` [out]

Pointer to the address that receives the return information structure. The format of this data depends on the value of the *level* parameter. This buffer is allocated by the system and must be freed using the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. Note that you must free the buffer even if the function fails with ERROR_MORE_DATA.

### `prefmaxlen` [in]

Specifies the preferred maximum length of returned data, in bytes. If you specify MAX_PREFERRED_LENGTH, the function allocates the amount of memory required for the data. If you specify another value in this parameter, it can restrict the number of bytes that the function returns. If the buffer size is insufficient to hold all entries, the function returns ERROR_MORE_DATA. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

### `entriesread` [out]

Pointer to a value that receives the count of elements actually enumerated.

### `totalentries` [out]

Pointer to a value that receives the total number of entries that could have been enumerated from the current resume position.

### `resumehandle` [in, out]

Pointer to a value that contains a resume handle which is used to continue an existing group member search. The handle should be zero on the first call and left unchanged for subsequent calls. If this parameter is **NULL**, then no resume handle is stored.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **NERR_InvalidComputer** | The computer name is invalid. |
| **ERROR_MORE_DATA** | More entries are available. Specify a large enough buffer to receive all entries. |
| **ERROR_NO_SUCH_ALIAS** | The specified local group does not exist. |

## Remarks

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits all authenticated users and members of the "[Pre-Windows 2000 compatible access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)" group to view the information. If you call this function on a member server or workstation, all authenticated users can view the information. For information about anonymous access and restricting anonymous access on these platforms, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The security descriptor of the LocalGroup object is used to perform the access check for this function.

User account names are limited to 20 characters and group names are limited to 256 characters. In addition, account names cannot be terminated by a period and they cannot include commas or any of the following printable characters: ", /, \, [, ], :, |, <, >, +, =, ;, ?, *. Names also cannot include characters in the range 1-31, which are nonprintable.

If you are programming for Active Directory, you may be able to call certain Active Directory Service Interface (ADSI) methods to achieve the same functionality you can achieve by calling the network management local group functions. For more information, see
[IADsGroup](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsgroup).

If this function returns **ERROR_MORE_DATA**, then it must be repeatedly called until **ERROR_SUCCESS** or **NERR_success** is returned. Failure to do so can result in an RPC connection leak.

## See also

[LOCALGROUP_MEMBERS_INFO_0](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_members_info_0)

[LOCALGROUP_MEMBERS_INFO_1](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_members_info_1)

[LOCALGROUP_MEMBERS_INFO_2](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_members_info_2)

[LOCALGROUP_MEMBERS_INFO_3](https://learn.microsoft.com/windows/desktop/api/lmaccess/ns-lmaccess-localgroup_members_info_3)

[Local Group
Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/local-group-functions)

[NetLocalGroupEnum](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupenum)

[NetLocalGroupGetInfo](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupgetinfo)

[NetLocalGroupSetMembers](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netlocalgroupsetmembers)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)