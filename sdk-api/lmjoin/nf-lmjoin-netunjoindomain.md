# NetUnjoinDomain function

## Description

The
**NetUnjoinDomain** function unjoins a computer from a workgroup or a domain.

## Parameters

### `lpServer` [in]

A pointer to a constant string that specifies the DNS or NetBIOS name of the computer on which the function is to execute. If this parameter is **NULL**, the local computer is used.

### `lpAccount` [in]

A pointer to a constant string that specifies the account name to use when connecting to the domain controller. The string must specify either a domain NetBIOS name and user account (for example, *REDMOND\user*) or the user principal name (UPN) of the user in the form of an Internet-style login name (for example, "someone@example.com"). If this parameter is **NULL**, the caller's context is used.

### `lpPassword` [in]

If the *lpAccount* parameter specifies an account name, this parameter must point to the password to use when connecting to the domain controller. Otherwise, this parameter must be **NULL**.

### `fUnjoinOptions` [in]

Specifies the unjoin options. If this parameter is NETSETUP_ACCT_DELETE, the account is disabled when the unjoin occurs. Note that this option does not delete the account. Currently, there are no other unjoin options defined.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes or one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. |
| **NERR_SetupNotJoined** | The computer is not currently joined to a domain. |
| **NERR_SetupDomainController** | This computer is a domain controller and cannot be unjoined from a domain. |

## Remarks

Unjoining (and joining) a computer to a domain or workgroup can be performed only by a member of the Administrators local group on the target computer. If you call the
**NetUnjoinDomain** function remotely, you must supply credentials because you cannot delegate credentials under these circumstances.

Different processes, or different threads of the same process, should not call the
**NetUnjoinDomain** function at the same time. This situation can leave the computer in an inconsistent state.

A system reboot is required after calling the [NetRenameMachineInDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrenamemachineindomain) function for the operation to complete.

## See also

[NetJoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netjoindomain)

[NetRenameMachineInDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrenamemachineindomain)

[Network
Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management
Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)