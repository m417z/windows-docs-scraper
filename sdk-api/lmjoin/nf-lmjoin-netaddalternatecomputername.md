# NetAddAlternateComputerName function

## Description

The
**NetAddAlternateComputerName** function adds an alternate name for the specified computer.

## Parameters

### `Server` [in, optional]

A pointer to a constant string that specifies the name of the computer on which to execute this function. If this parameter is **NULL**, the local computer is used.

### `AlternateName` [in]

A pointer to a constant string that specifies the alternate name to add. This name must be in the form of a fully qualified DNS name.

### `DomainAccount` [in, optional]

A pointer to a constant string that specifies the domain account to use for accessing the
machine account object for the computer specified in the *Server* parameter in Active Directory. If this parameter is **NULL**, then the credentials of the user executing
this routine are used.

This parameter is not used if the server to execute this function is not joined to a domain.

### `DomainAccountPassword` [in, optional]

A pointer to a constant string that specifies the password matching the domain account passed in the *DomainAccount* parameter.
If this parameter is **NULL**, then the credentials of the user executing
this routine are used.

This parameter is ignored if the *DomainAccount* parameter is **NULL**. This parameter is not used if the server to execute this function is not joined to a domain.

### `Reserved` [in]

Reserved for future use. This parameter should be **NULL**.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes or one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned if the caller was not a member of the Administrators local group on the target computer. |
| **ERROR_INVALID_NAME** | A name parameter is incorrect. This error is returned if the *AlternateName* parameter does not contain valid name. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. This error is returned if the *DomainAccount* parameter does not contain a valid domain. This error is also returned if the *DomainAccount* parameter is not **NULL** and the *DomainAccountPassword* parameter is not **NULL** but does not contain a Unicode string. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory is available to process this command. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if the target computer specified in the *Server* parameter on which this function executes is running on Windows 2000 and earlier. |
| **NERR_WkstaNotStarted** | The Workstation service has not been started. |
| **RPC_S_CALL_IN_PROGRESS** | A remote procedure call is already in progress for this thread. |
| **RPC_S_PROTSEQ_NOT_SUPPORTED** | The remote procedure call protocol sequence is not supported. |

## Remarks

The **NetAddAlternateComputerName** function is supported on Windows XP and later.

The **NetAddAlternateComputerName** function is used to set secondary network names for computers. The primary name is the name used for authentication and maps to the machine account name.

The **NetAddAlternateComputerName** function requires that the caller is a member of the Administrators local group on the target computer.

## See also

[NetEnumerateComputerNames](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netenumeratecomputernames)

[NetJoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netjoindomain)

[NetRemoveAlternateComputerName](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netremovealternatecomputername)

[NetRenameMachineInDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrenamemachineindomain)

[NetSetPrimaryComputerName](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netsetprimarycomputername)

[NetUnjoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netunjoindomain)

[SetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernameexa)