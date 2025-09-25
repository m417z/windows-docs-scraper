# TmRollbackTransaction function

## Description

The **TmRollbackTransaction** routine initiates a rollback operation for a specified transaction.

## Parameters

### `Transaction` [in]

A pointer to a [transaction object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-objects). To obtain this pointer, your component must call [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) and supply the object handle that a previous call to [ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction) or [ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction) provided.

### `Wait` [in]

A Boolean value that the caller sets to **TRUE** for synchronous operation or **FALSE** for asynchronous operation. If this parameter is set to **TRUE**, the call does not return until the rollback operation is complete.

## Return value

**TmRollbackTransaction** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_TRANSACTION_ALREADY_COMMITTED** | The transaction cannot be rolled back because it has already been committed. |
| **STATUS_TRANSACTION_REQUEST_NOT_VALID** | The transaction has not been committed but its current state does not permit rollback. |
| **STATUS_PENDING** | Rollback notifications have been queued to resource managers, and the caller specified **FALSE** for the *Wait* parameter. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **TmRollbackTransaction** routine is a pointer-based version of the [ZwRollbackTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrollbacktransaction) routine.

For information about when to use KTM's **Tm*Xxx*** routines instead of **Zw*Xxx*** routines, see [Using TmXxx Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-tmxxx-routines).

## See also

[ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction)

[ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction)

[ZwRollbackTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntrollbacktransaction)