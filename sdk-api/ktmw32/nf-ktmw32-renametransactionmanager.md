# RenameTransactionManager function

## Description

Renames a transaction manager (TM) object. This function can only be used on named TM
handles. A new **GUID** for the TM is selected and can be retrieved using the
[GetTransactionManagerID](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-gettransactionmanagerid) function.

## Parameters

### `LogFileName` [in]

The name of the log stream. This stream must exist within a CLFS log file.

### `ExistingTransactionManagerGuid` [in]

A value that specifies the current name of the TM.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## See also

[GetTransactionManagerID](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-gettransactionmanagerid)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)