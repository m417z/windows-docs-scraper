# PFLT_TRANSACTION_NOTIFICATION_CALLBACK callback function

## Description

A minifilter driver can register a routine of type PFLT_TRANSACTION_NOTIFICATION_CALLBACK as its *TransactionNotificationCallback* routine.

## Parameters

### `FltObjects` [in]

Pointer to an [FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects) structure that contains opaque pointers for the objects related to the current operation.

### `TransactionContext` [in]

Pointer to the minifilter driver's transaction context.

### `NotificationMask` [in]

Specifies the type of notifications that the filter manager is sending to the minifilter driver, as one of the following values.

| Value | Meaning |
| --- | --- |
| TRANSACTION_NOTIFY_COMMIT | This notification is sent when the transaction is being committed. |
| TRANSACTION_NOTIFY_COMMIT_FINALIZE | For Windows Vista SP1 and later, this notification is sent when the transaction is fully committed (that is, when all of the [resource managers](https://learn.microsoft.com/previous-versions//aa365519(v=vs.85)) associated with the transaction, such as [TxF](https://go.microsoft.com/fwlink/p/?linkid=66161), have committed). |
| TRANSACTION_NOTIFY_PREPARE | This notification is sent when the transaction enters the prepare for commit phase. |
| TRANSACTION_NOTIFY_PREPREPARE | This notification is sent when the transaction enters the pre-prepare for commit phase. |
| TRANSACTION_NOTIFY_ROLLBACK | This notification is sent when the transaction is being rolled back or aborted. |

## Return value

The PFLT_TRANSACTION_NOTIFICATION_CALLBACK routine returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | Returning this status value indicates that the minifilter driver is finished with the transaction. This is a success code. |
| **STATUS_PENDING** | Returning this status value indicates that the minifilter driver is not yet finished with the transaction. This is a success code. |

## Remarks

When a minifilter driver registers itself by calling [FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter) from its [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine, it can register a routine of type PFLT_TRANSACTION_NOTIFICATION_CALLBACK as the minifilter's *TransactionNotificationCallback* routine.

To register the *TransactionNotificationCallback* routine, the minifilter driver stores the address of a routine of type PFLT_TRANSACTION_NOTIFICATION_CALLBACK in the **TransactionNotificationCallback** member of the [FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration) structure that the minifilter driver passes as the *Registration* parameter of **FltRegisterFilter**.

The filter manager calls this routine to notify the minifilter driver about the status of a transaction that the minifilter driver is enlisted in.

If the minifilter driver returns STATUS_PENDING from this callback routine, it must eventually call one of the following routines to indicate that it has finished processing the notification:

[FltCommitComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcommitcomplete)

[FltPrepareComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltpreparecomplete)

[FltPrePrepareComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltprepreparecomplete)

[FltRollbackComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrollbackcomplete)

## See also

[FLT_REGISTRATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_registration)

[FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects)

[FltCommitComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcommitcomplete)

[FltPrePrepareComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltprepreparecomplete)

[FltPrepareComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltpreparecomplete)

[FltRegisterFilter](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltregisterfilter)

[FltRollbackComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltrollbackcomplete)