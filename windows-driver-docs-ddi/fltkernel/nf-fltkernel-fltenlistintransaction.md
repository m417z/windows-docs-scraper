# FltEnlistInTransaction function

## Description

The **FltEnlistInTransaction** routine enlists a minifilter driver in a given transaction.

## Parameters

### `Instance` [in]

An opaque instance pointer for the caller. This parameter is required and cannot be **NULL**.

### `Transaction` [in]

An opaque transaction pointer for the transaction.

### `TransactionContext` [in]

A pointer to the minifilter driver's transaction context. This parameter is required and cannot be **NULL**.

### `NotificationMask` [in]

Specifies the type of notifications that the filter manager is to send to the minifilter driver, as one or more of the values listed in the following table. This parameter is required and cannot be zero.

| Value | Meaning |
| --- | --- |
| TRANSACTION_NOTIFY_COMMIT | This notification is sent when the transaction is being committed. |
| TRANSACTION_NOTIFY_COMMIT_FINALIZE | For Windows Vista SP1 and later, this notification is sent when the transaction is fully committed (that is, when all of the [resource managers](https://learn.microsoft.com/previous-versions//aa365519(v=vs.85)) associated with the transaction, such as [TxF](https://go.microsoft.com/fwlink/p/?linkid=66161), have committed). |
| TRANSACTION_NOTIFY_PREPARE | This notification is sent when the transaction has entered the prepare for commit phase. |
| TRANSACTION_NOTIFY_PREPREPARE | This notification is sent when the transaction has entered the pre-prepare for commit phase. |
| TRANSACTION_NOTIFY_ROLLBACK | This notification is sent when the transaction is being rolled back or aborted. |
| FLT_MAX_TRANSACTION_NOTIFICATIONS | TRANSACTION_NOTIFY_COMMIT \| TRANSACTION_NOTIFY_PREPARE \| TRANSACTION_NOTIFY_PREPREPARE \| TRANSACTION_NOTIFY_ROLLBACK |

## Return value

**FltEnlistInTransaction** returns STATUS_SUCCESS or an appropriate NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_FLT_ALREADY_ENLISTED** | The caller is already enlisted in the transaction. This is an error code. |
| **STATUS_FLT_DELETING_OBJECT** | The instance specified in the *Instance* parameter is being torn down. This is an error code. |
| **STATUS_INSUFFICIENT_RESOURCES** | **FltEnlistInTransaction** encountered a pool allocation error. This is an error code. |
| **STATUS_INVALID_PARAMETER** | The caller did not register a *TransactionNotificationCallback* routine. This is an error code. |
| **STATUS_INVALID_PARAMETER_4** | The caller specified an invalid value for the *NotificationMask* parameter. This is an error code. |

## Remarks

A minifilter driver calls **FltEnlistInTransaction** to enlist in a transaction. Before calling **FltEnlistInTransaction**, the minifilter driver must have registered a *TransactionNotificationCallback* routine. Otherwise, the call to **FltEnlistInTransaction** will fail.

To register a *TransactionNotificationCallback* routine, a minifilter driver stores the address of a routine of type [PFLT_TRANSACTION_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_transaction_notification_callback) in the **TransactionNotificationCallback** member of the [FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration) structure that the minifilter driver passes as the *Registration* parameter of [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter).

To roll back or abort a transaction, call [FltRollbackEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrollbackenlistment).

To allocate a new transaction context, call [FltAllocateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

To retrieve a transaction context, call [FltGetTransactionContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettransactioncontext).

To delete a transaction context, call [FltDeleteTransactionContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletetransactioncontext) or [FltDeleteContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext).

To set a transaction context, call [FltSetTransactionContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsettransactioncontext).

## See also

[FltAllocateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[FltCommitComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcommitcomplete)

[FltDeleteContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[FltDeleteTransactionContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletetransactioncontext)

[FltGetTransactionContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettransactioncontext)

[FltPrePrepareComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltprepreparecomplete)

[FltPrepareComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltpreparecomplete)

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[FltReleaseContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[FltRollbackComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrollbackcomplete)

[FltRollbackEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrollbackenlistment)

[FltSetTransactionContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsettransactioncontext)

[PFLT_TRANSACTION_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_transaction_notification_callback)