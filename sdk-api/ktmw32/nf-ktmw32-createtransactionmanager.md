# CreateTransactionManager function

## Description

Creates a new transaction manager (TM) object and returns a handle with the specified access.

## Parameters

### `lpTransactionAttributes` [in, optional]

The transaction [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) (ACLs) for the TM object.

### `LogFileName` [in, optional]

The log file stream name. If the stream does not exist in the log, it is created. To create a volatile TM, this parameter must be **NULL** and *CreateOptions* must specify TRANSACTION_MANAGER_VOLATILE, this transaction manager is considered volatile.

### `CreateOptions` [in, optional]

Any optional attributes for the new TM.

| Value | Meaning |
| --- | --- |
| **TRANSACTION_MANAGER_VOLATILE** | Indicates that the TM is volatile, and does not perform recovery. |

### `CommitStrength` [in, optional]

Reserved; specify zero.

## Return value

If the function succeeds, the return value is a handle to the transaction manager.

If the function fails, the return value is INVALID_HANDLE_VALUE. To get extended error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

 The following list identifies the possible error codes:

## Remarks

Immediately after calling this function, you must call [RecoverTransactionManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-recovertransactionmanager).

If your transaction manager is volatile, all your resource managers must also be volatile.

You must call [RecoverTransactionManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-recovertransactionmanager) after creating a TM in order for the TM to function correctly.

## See also

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)

[OpenTransactionManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-opentransactionmanager)

[RecoverTransactionManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-recovertransactionmanager)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)