# TmRecoverTransactionManager function

## Description

The **TmRecoverTransactionManager** routine reconstructs the state of the transaction manager object (including all transactions, enlistments, and resource managers) from the recovery information that is in the log stream.

## Parameters

### `Tm` [in]

A pointer to a [transaction manager object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-manager-objects). To obtain this pointer, your TPS component must call [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) and supply the object handle that a previous call to [ZwCreateTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransactionmanager) or [ZwOpenTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransactionmanager) provided.

### `TargetVirtualClock` [in]

A pointer to a [virtual clock value](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-virtual-clock-values). This parameter is optional and can be **NULL**. For more information about this parameter, see the following Remarks section. For Windows Vista, this parameter must be **NULL**.

## Return value

**TmRecoverTransactionManager** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_NOT_IMPLEMENTED** | For Windows Vista, the caller specified a non-**NULL** value for the *TargetVirtualClock* parameter. |
| **STATUS_TM_VOLATILE** | The specified transaction manager object does not have a log file, so recovery is not available. |
| **STATUS_UNSUCCESSFUL** | The specified transaction manager object is in an unexpected state. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **TmRecoverTransactionManager** routine is a pointer-based version of the [ZwRecoverTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrecovertransactionmanager) routine.

Calling **TmRecoverTransactionManager** with a *TargetVirtualClock* parameter value of **NULL** is functionally equivalent to calling **ZwRecoverTransactionManager**. Calling **TmRecoverTransactionManager** with a non-**NULL** *TargetVirtualClock* parameter value is functionally equivalent to calling [ZwRollforwardTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrollforwardtransactionmanager).

For more information about recovery operations, see [Handling Recovery Operations](https://learn.microsoft.com/windows-hardware/drivers/kernel/handling-recovery-operations).

For information about when to use KTM's **Tm*Xxx*** routines instead of **Zw*Xxx*** routines, see [Using TmXxx Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-tmxxx-routines).

## See also

[ZwRecoverTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrecovertransactionmanager)

[ZwRollforwardTransactionManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrollforwardtransactionmanager)