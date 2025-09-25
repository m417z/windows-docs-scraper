# CreateTransaction function

## Description

Creates a new transaction object.

## Parameters

### `lpTransactionAttributes` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)
structure that determines whether the returned handle can be inherited by child processes. If this parameter is
**NULL**, the handle cannot be inherited.

The **lpSecurityDescriptor** member of the structure specifies a
[security descriptor](https://learn.microsoft.com/windows/desktop/winstation/desktop-security-and-access-rights) for the new
event. If *lpTransactionAttributes* is **NULL**, the object gets
a default security descriptor. The access control lists (ACL) in the default security descriptor for a
transaction come from the primary or impersonation token of the creator.

### `UOW` [in, optional]

Reserved. Must be zero (0).

### `CreateOptions` [in, optional]

Any optional transaction instructions.

| Value | Meaning |
| --- | --- |
| **TRANSACTION_DO_NOT_PROMOTE** | The transaction cannot be distributed. |

### `IsolationLevel` [in, optional]

Reserved; specify zero (0).

### `IsolationFlags` [in, optional]

Reserved; specify zero (0).

### `Timeout` [in, optional]

The time-out interval, in milliseconds. If a nonzero value is specified, the transaction will be aborted when the interval elapses if it has not already reached the prepared state.

Specify zero (0) or INFINITE to provide an infinite time-out.

### `Description` [in, optional]

A user-readable description of the transaction.

## Return value

If the function succeeds, the return value is a handle to the transaction.

If the function fails, the return value is **INVALID_HANDLE_VALUE**. To get extended
error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## Remarks

Use the [CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle) function to close the transaction
handle. If the last transaction handle is closed before a client calls the
[CommitTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-committransaction) function with the transaction
handle, then KTM rolls back the transaction.

If the transaction might need to be promotable to a distributed transaction, then you must grant the Distributed Transaction Coordinator (DTC) access rights to enlist in the transaction. To do this, the *lpTransactionAttributes* parameter needs to contain an access control entry with the DTC’s SID (S-1-5-80-2818357584-3387065753-4000393942-342927828-138088443) and the TRANSACTION_ENLIST right. For more information, see [Distributed Transaction Coordinator](https://learn.microsoft.com/previous-versions/windows/desktop/ms684146(v=vs.85)) and [Access Control Components](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-components).

## See also

[CommitTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-committransaction)

[Distributed Transaction Coordinator](https://learn.microsoft.com/previous-versions/windows/desktop/ms684146(v=vs.85))

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)

[RollbackTransaction](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-rollbacktransaction)

[SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)

[SetTransactionInformation](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-settransactioninformation)