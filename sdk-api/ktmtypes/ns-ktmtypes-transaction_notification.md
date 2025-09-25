# TRANSACTION_NOTIFICATION structure

## Description

Contains the data that is associated with a transaction notification.

## Members

### `TransactionKey`

The user-defined, opaque ID for this transaction.

### `TransactionNotification`

The [NOTIFICATION_MASK](https://learn.microsoft.com/windows/desktop/Ktm/notification-mask) value for this
transaction.

### `TmVirtualClock`

The latest virtual clock value that is associated with this transaction. See
[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1).

### `ArgumentLength`

Indicates the number of bytes for the
[TRANSACTION_NOTIFICATION_RECOVERY_ARGUMENT](https://learn.microsoft.com/windows/win32/api/ktmtypes/ns-ktmtypes-transaction_notification_recovery_argument)
structure that follow this
**TRANSACTION_NOTIFICATION** structure.

## See also

[CreateEnlistment](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createenlistment)

[GetNotificationResourceManager](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-getnotificationresourcemanager)

[GetNotificationResourceManagerAsync](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-getnotificationresourcemanagerasync)

[Kernel Transaction Manager Structures](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-structures)

[NOTIFICATION_MASK](https://learn.microsoft.com/windows/desktop/Ktm/notification-mask)

[TRANSACTION_NOTIFICATION_RECOVERY_ARGUMENT](https://learn.microsoft.com/windows/win32/api/ktmtypes/ns-ktmtypes-transaction_notification_recovery_argument)