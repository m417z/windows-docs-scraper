# FltCommitFinalizeComplete function

## Description

The **FltCommitFinalizeComplete** routine acknowledges a TRANSACTION_NOTIFY_COMMIT_FINALIZE notification.

## Parameters

### `Instance` [in]

Opaque pointer to an instance of a minifilter driver. This parameter is required and cannot be **NULL**.

### `Transaction` [in]

Opaque pointer to the transaction the minifilter driver is currently enlisted in. This parameter is required and cannot be **NULL**.

### `TransactionContext` [in, optional]

Pointer to the minifilter driver's context for the transaction. This parameter is optional and can be **NULL**.

## Return value

**FltCommitFinalizeComplete** returns STATUS_SUCCESS or an appropriate NTSTATUS value, such as the following:

| Return code | Description |
| --- | --- |
| **STATUS_NOT_FOUND** | The minifilter driver did not set a context on the transaction. This is an error code. |

## Remarks

A minifilter driver that is enlisted in a transaction can receive a TRANSACTION_NOTIFY_COMMIT_FINALIZE notification when the transaction is fully committed (that is, when all of the [resource managers](https://learn.microsoft.com/previous-versions//aa365519(v=vs.85)) associated with the transaction, such as [TxF](https://go.microsoft.com/fwlink/p/?linkid=66161), have committed). For an antivirus minifilter driver that performs scans outside of transactions, you can use this notification value to determine when the driver should begin scanning files.

To send the TRANSACTION_NOTIFY_COMMIT_FINALIZE notification to the minifilter driver, the filter manager calls the minifilter driver's *TransactionNotificationCallback* routine. The minifilter driver acknowledges this notification in one of two ways:

* The minifilter driver's *TransactionNotificationCallback* routine performs any required processing and returns STATUS_SUCCESS. (In this case, the minifilter driver does not call **FltCommitFinalizeComplete**.)
* The minifilter driver's *TransactionNotificationCallback* routine posts any required processing to a worker thread and returns STATUS_PENDING. After performing the processing asynchronously, the minifilter driver's worker thread routine must call **FltCommitFinalizeComplete** to indicate that it has finished this processing. If the minifilter driver's worker thread routine does not call **FltCommitFinalizeComplete**, certain system resources will be leaked.

To register a *TransactionNotificationCallback* routine, a minifilter driver stores the address of a routine of type [PFLT_TRANSACTION_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_transaction_notification_callback) in the **TransactionNotificationCallback** member of the [FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration) structure that the minifilter driver passes as the *Registration* parameter of [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter).

To enlist in a transaction, call [FltEnlistInTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenlistintransaction).

To allocate a new transaction context, call [FltAllocateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext).

To retrieve a transaction context, call [FltGetTransactionContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettransactioncontext).

To delete a transaction context, call [FltDeleteTransactionContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletetransactioncontext) or [FltDeleteContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext).

To set a transaction context, call [FltSetTransactionContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsettransactioncontext).

For more information, see [Transaction Notifications](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-notifications).

## See also

[FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[FltAllocateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatecontext)

[FltCommitComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcommitcomplete)

[FltDeleteContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletecontext)

[FltDeleteTransactionContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltdeletetransactioncontext)

[FltEnlistInTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltenlistintransaction)

[FltGetTransactionContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgettransactioncontext)

[FltPrePrepareComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltprepreparecomplete)

[FltPrepareComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltpreparecomplete)

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[FltReleaseContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltreleasecontext)

[FltRollbackComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrollbackcomplete)

[FltRollbackEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrollbackenlistment)

[FltSetTransactionContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsettransactioncontext)

[PFLT_TRANSACTION_NOTIFICATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_transaction_notification_callback)