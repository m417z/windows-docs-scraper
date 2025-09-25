# NetGetDisplayInformationIndex function

## Description

The
**NetGetDisplayInformationIndex** function returns the index of the first display information entry whose name begins with a specified string or whose name alphabetically follows the string. You can use this function to determine a starting index for subsequent calls to the
[NetQueryDisplayInformation](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netquerydisplayinformation) function.

## Parameters

### `ServerName` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the remote server on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `Level` [in]

Specifies the level of accounts to query. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **1** | Query all local and global (normal) user accounts. |
| **2** | Query all workstation and server user accounts. |
| **3** | Query all global groups. |

### `Prefix` [in]

Pointer to a string that specifies the prefix for which to search.

### `Index` [out]

Pointer to a value that receives the index of the requested entry.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes.

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | The user does not have access to the requested information. |
| **ERROR_INVALID_LEVEL** | The value specified for the *Level* parameter is invalid. |
| **ERROR_NO_MORE_ITEMS** | There were no more items on which to operate. |
| **NERR_InvalidComputer** | The computer name is invalid. |

## Remarks

If you call this function on a domain controller that is running Active Directory, access is allowed or denied based on the access control list (ACL) for the [securable object](https://learn.microsoft.com/windows/desktop/SecAuthZ/securable-objects). The default ACL permits all authenticated users and members of the "[Pre-Windows 2000 compatible access](https://learn.microsoft.com/windows/desktop/SecAuthZ/allowing-anonymous-access)" group to view the information. If you call this function on a member server or workstation, all authenticated users can view the information. For information about anonymous access and restricting anonymous access on these platforms, see
[Security Requirements for the Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/security-requirements-for-the-network-management-functions). For more information on ACLs, ACEs, and access tokens, see
[Access Control Model](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-model).

The function only returns information to which the caller has Read access. The caller must have List Contents access to the Domain object, and Enumerate Entire SAM Domain access on the SAM Server object located in the System container.

## See also

[Get Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/get-functions)

[NetQueryDisplayInformation](https://learn.microsoft.com/windows/desktop/api/lmaccess/nf-lmaccess-netquerydisplayinformation)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)