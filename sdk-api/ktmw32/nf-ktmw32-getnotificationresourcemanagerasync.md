# GetNotificationResourceManagerAsync function

## Description

Requests and receives asynchronous notification for a resource manager (RM). This function is used by
the RM register to receive notifications when a transaction changes state.

## Parameters

### `ResourceManagerHandle` [in]

A handle to the resource manager.

### `TransactionNotification` [out]

A pointer to a
[TRANSACTION_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/ktmtypes/ns-ktmtypes-transaction_notification) structure that
receives the first available notification.

### `TransactionNotificationLength` [in]

The size of the *TransactionNotification* buffer, in bytes.

### `ReturnLength` [out]

A pointer to a variable that receives the actual size of the notification received by the
*TransactionNotification* parameter.

### `lpOverlapped` [in]

A pointer to an [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure that is
required for asynchronous operation.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero (0). To get extended error information, call the
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

The following list identifies the possible error codes:

## Remarks

All resource managers must register to receive **TRANSACTION_NOTIFY_PREPREPARE**,
**TRANSACTION_NOTIFY_PREPARE**, and **TRANSACTION_NOTIFY_COMMIT**
notifications, even if they subsequently call
[ReadOnlyEnlistment](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-readonlyenlistment) to mark an enlistment as
read-only. Resource managers can support **TRANSACTION_NOTIFY_SINGLE_PHASE_COMMIT**, but
they must also support the multi-phase pre-prepare, prepare, and commit notifications. For the list of all
notifications that resource managers can receive, see
[TRANSACTION_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/ktmtypes/ns-ktmtypes-transaction_notification).

Resource managers (RM) may want to call this function more than once to provide multiple buffers for KTM to
use when delivering notifications. The number of calls to this function depends on how much load your RM is
carrying.

This function must be called after the
[SetResourceManagerCompletionPort](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-setresourcemanagercompletionport)
function is called.

## See also

[CreateEnlistment](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-createenlistment)

[Kernel Transaction Manager Functions](https://learn.microsoft.com/windows/desktop/Ktm/kernel-transaction-manager-functions)

[NOTIFICATION_MASK](https://learn.microsoft.com/windows/desktop/Ktm/notification-mask)

[SetResourceManagerCompletionPort](https://learn.microsoft.com/windows/desktop/api/ktmw32/nf-ktmw32-setresourcemanagercompletionport)

[TRANSACTION_NOTIFICATION](https://learn.microsoft.com/windows/desktop/api/ktmtypes/ns-ktmtypes-transaction_notification)

[TRANSACTION_NOTIFICATION_RECOVERY_ARGUMENT](https://learn.microsoft.com/windows/win32/api/ktmtypes/ns-ktmtypes-transaction_notification_recovery_argument)