# OpenTransactionManager function

## Description

Opens an existing transaction manager.

## Parameters

### `LogFileName` [in]

The name of the log stream. This stream must exist within a CLFS log file.

### `DesiredAccess` [in]

The access requested. See [Transaction Manager Access Masks](https://learn.microsoft.com/windows/desktop/Ktm/transaction-manager-access-masks) for a list of valid values.

### `OpenOptions` [in, optional]

Reserved; specify zero.

## Return value

If the function succeeds, the return value is a handle to the transaction manager.

If the function fails, the return value is INVALID_HANDLE_VALUE. To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## Remarks

Immediately after calling this function, you must call [RecoverTransactionManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-recovertransactionmanager).

The *LogFileName* must be specified using the NT file format. For example: *\??\<drive>:\<path>*. Do not use the .BLF extension.

## See also

[CreateTransactionManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createtransactionmanager)

[GetCurrentClockTransactionManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-getcurrentclocktransactionmanager)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)

[OpenTransactionManagerById](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-opentransactionmanagerbyid)

[Transaction Manager Access Masks](https://learn.microsoft.com/windows/desktop/Ktm/transaction-manager-access-masks)