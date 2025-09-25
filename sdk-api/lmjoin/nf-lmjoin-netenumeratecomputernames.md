# NetEnumerateComputerNames function

## Description

The
**NetEnumerateComputerNames** function enumerates names for the specified computer.

## Parameters

### `Server` [in, optional]

A pointer to a constant string that specifies the name of the computer on which to execute this function. If this parameter is **NULL**, the local computer is used.

### `NameType` [in]

The type of the name queried. This member can be one of the following values defined in the **NET_COMPUTER_NAME_TYPE** enumeration defined in the *Lmjoin.h* header file.

| Value | Meaning |
| --- | --- |
| **NetPrimaryComputerName** | The primary computer name. |
| **NetAlternateComputerNames** | Alternate computer names. |
| **NetAllComputerNames** | All computer names. |
| **NetComputerNameTypeMax** | Indicates the end of the range that specifies the possible values for the type of name to be queried. |

### `Reserved` [in]

Reserved for future use. This parameter should be **NULL**.

### `EntryCount` [out]

A pointer to a DWORD value that returns the number of names returned
in the buffer pointed to by the *ComputerNames* parameter if the function succeeds.

### `ComputerNames` [out]

A pointer to an array of pointers to names. If the function call is successful, this parameter will return the computer names that match the computer type name specified in the *NameType* parameter.

When the application no longer needs this array, this buffer should be freed by
calling [NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree) function.

## Return value

If the function succeeds, the return value is NERR_Success.

If the function fails, the return value can be one of the following error codes or one of the
[system error codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | Access is denied. This error is returned if the caller was not a member of the Administrators local group on the target computer. |
| **ERROR_INVALID_PARAMETER** | A parameter is incorrect. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory is available to process this command. |
| **ERROR_NOT_SUPPORTED** | The request is not supported. This error is returned if the target computer specified in the *Server* parameter on which this function executes is running on Windows 2000 and earlier. |
| **NERR_WkstaNotStarted** | The Workstation service has not been started. |
| **RPC_S_CALL_IN_PROGRESS** | A remote procedure call is already in progress for this thread. |
| **RPC_S_PROTSEQ_NOT_SUPPORTED** | The remote procedure call protocol sequence is not supported. |

## Remarks

The **NetEnumerateComputerNames** function is supported on Windows Vista and later.

The **NetEnumerateComputerNames** function is used to request the names a computer currently has configured.

The **NetEnumerateComputerNames** function requires that the caller is a member of the Administrators local group on the target computer.

## See also

[NetAddAlternateComputerName](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netaddalternatecomputername)

[NetJoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netjoindomain)

[NetRemoveAlternateComputerName](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netremovealternatecomputername)

[NetRenameMachineInDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netrenamemachineindomain)

[NetSetPrimaryComputerName](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netsetprimarycomputername)

[NetUnjoinDomain](https://learn.microsoft.com/windows/desktop/api/lmjoin/nf-lmjoin-netunjoindomain)

[SetComputerNameEx](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-setcomputernameexa)