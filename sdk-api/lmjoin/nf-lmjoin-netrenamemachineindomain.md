# NetRenameMachineInDomain function

## Description

The
**NetRenameMachineInDomain** function changes the name of a computer in a domain.

## Parameters

### `lpServer` [in]

A pointer to a constant string that specifies the DNS or NetBIOS name of the computer on which to call the function. If this parameter is **NULL**, the local computer is used.

### `lpNewMachineName` [in]

A pointer to a constant string that specifies the new name of the computer. If specified, the local computer name is changed as well. If this parameter is **NULL**, the function assumes you have already called the
[SetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernameexa) function.

### `lpAccount` [in]

A pointer to a constant string that specifies an account name to use when connecting to the domain controller. If this parameter is **NULL**, the caller's context is used.

### `lpPassword` [in]

If the *lpAccount* parameter specifies an account name, this parameter must point to the password to use when connecting to the domain controller. Otherwise, this parameter must be **NULL**.

### `fRenameOptions` [in]

The rename options. If this parameter is NETSETUP_ACCT_CREATE, the function renames the account in the domain.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes or one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned if the account name passed in the *lpAccount* parameter did not have sufficient access rights for the operation. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. |
| **NERR_SetupNotJoined** | The computer is not currently joined to a domain. |
| **NERR_SetupDomainController** | This computer is a domain controller and cannot be unjoined from a domain. |

## Remarks

Renaming a domain computer can be performed only by a user that is a member of the Administrators local group on the target computer and that also is a member of the Administrators group on the domain or has the Account Operator privilege on the domain. If you call the
**NetRenameMachineInDomain** function remotely, you must supply credentials because you cannot delegate credentials under these circumstances.

Different processes, or different threads of the same process, should not call the
**NetRenameMachineInDomain** function at the same time. This situation can leave the computer in an inconsistent state.

The **NERR_SetupNotJoined** and **NERR_SetupDomainController** return values are defined in the Lmerr.h header file. This header file is automatically included by the Lm.h header file and should not be included directly.

A system reboot is required after calling the **NetRenameMachineInDomain** function for the operation to complete.

## See also

[NetAddAlternateComputerName](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netaddalternatecomputername)

[NetEnumerateComputerNames](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netenumeratecomputernames)

[NetRemoveAlternateComputerName](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netremovealternatecomputername)

[NetSetPrimaryComputerName](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netsetprimarycomputername)

[NetUnjoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netunjoindomain)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)

[SetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernameexa)