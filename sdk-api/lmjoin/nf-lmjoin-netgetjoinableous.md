# NetGetJoinableOUs function

## Description

The
**NetGetJoinableOUs** function retrieves a list of organizational units (OUs) in which a computer account can be created.

## Parameters

### `lpServer` [in]

Pointer to a constant string that specifies the DNS or NetBIOS name of the computer on which to call the function. If this parameter is **NULL**, the local computer is used.

### `lpDomain` [in]

Pointer to a constant string that specifies the name of the domain for which to retrieve the list of OUs that can be joined.

### `lpAccount` [in]

Pointer to a constant string that specifies the account name to use when connecting to the domain controller. The string must specify either a domain NetBIOS name and user account (for example, "REDMOND\user") or the user principal name (UPN) of the user in the form of an Internet-style login name (for example, "someone@example.com"). If this parameter is **NULL**, the caller's context is used.

### `lpPassword` [in]

If the *lpAccount* parameter specifies an account name, this parameter must point to the password to use when connecting to the domain controller. Otherwise, this parameter must be **NULL**.

### `OUCount` [out]

Receives the count of OUs returned in the list of joinable OUs.

### `OUs` [out]

Pointer to an array that receives the list of joinable OUs. This array is allocated by the system and must be freed using a single call to the
[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function. For more information, see
[Network Management Function Buffers](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffers) and
[Network Management Function Buffer Lengths](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-function-buffer-lengths).

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes or one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough storage is available to process this command. |
| **NERR_DefaultJoinRequired** | The destination domain controller does not support creating computer accounts in OUs. |

## Remarks

No special group membership is required to successfully execute the
**NetGetJoinableOUs** function.

For more information about organizational units, see
[Managing Users](https://learn.microsoft.com/windows/desktop/AD/managing-users) in the Active Directory documentation.

## See also

[NetGetJoinInformation](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netgetjoininformation)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)