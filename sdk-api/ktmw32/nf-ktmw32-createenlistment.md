# CreateEnlistment function

## Description

Creates an enlistment, sets its initial state, and opens a handle to the enlistment with the specified
access.

## Parameters

### `lpEnlistmentAttributes` [in, optional]

A pointer to a [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes)
structure that contains the security attributes for the enlistment manager. Specify
**NULL** to obtain the default attributes.

### `ResourceManagerHandle` [in]

A handle to the resource manager (RM) to enlist.

### `TransactionHandle` [in]

A handle to the transaction in which the RM is enlisting.

### `NotificationMask` [in]

The notifications this RM is requesting for the *TransactionHandle* parameter. For
a list of valid values, see [NOTIFICATION_MASK](https://learn.microsoft.com/windows/desktop/Ktm/notification-mask).

### `CreateOptions` [in, optional]

Any optional enlistment instructions.

| Value | Meaning |
| --- | --- |
| **ENLISTMENT_SUPERIOR**<br><br>1 | Enlist as a superior transaction manager. |

### `EnlistmentKey` [in, optional]

A pointer to a user-defined structure used by the RM that is returned when a notification is sent in the
[TRANSACTION_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/ktmtypes/ns-ktmtypes-transaction_notification) structure. This is
typically used to associate a private structure with this specific transaction.

## Return value

If the function succeeds, the return value is a handle to the enlistment.

If the function fails, the return value is **INVALID_HANDLE_VALUE**. To get extended
error information, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## Remarks

**Windows Vista:** Any attempt to enlist during the pre-prepare phase or later will fail.

If you do not specify within your notification mask that you accept a single-phase commit request, KTM always
performs a two-phase commit operation.

Keep the following notification rules in mind when enlisting in transactions:

* The RM must always request rollback notification.
* If the RM requests prepare notification, it must also request commit notification.
* If the RM requests a single-phase commit operation, it must also specify prepare and commit
  notifications.
* The only time an RM is not required to request commit notifications is when it is requesting at least a
  pair of prepare and rollback notifications.

## See also

[CommitComplete](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-commitcomplete)

[CommitEnlistment](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-commitenlistment)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)

[NOTIFICATION_MASK](https://learn.microsoft.com/windows/desktop/Ktm/notification-mask)

[OpenEnlistment](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-openenlistment)

[TRANSACTION_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/ktmtypes/ns-ktmtypes-transaction_notification)