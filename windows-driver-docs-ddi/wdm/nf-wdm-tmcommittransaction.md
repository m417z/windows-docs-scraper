# TmCommitTransaction function

## Description

The **TmCommitTransaction** routine initiates a commit operation for a specified transaction.

## Parameters

### `Transaction` [in]

A pointer to a [transaction object](https://learn.microsoft.com/windows-hardware/drivers/kernel/transaction-objects). To obtain this pointer, your TPS component must call [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) and supply the object handle that a previous call to [ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction) or [ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction) provided.

### `Wait` [in]

A Boolean value that the caller sets to **TRUE** for synchronous operation or **FALSE** for asynchronous operation. If this parameter is **TRUE**, the call returns after the commit operation is complete.

## Return value

**TmCommitTransaction** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_TRANSACTION_SUPERIOR_EXISTS** | The caller cannot commit the transaction because a [superior transaction manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-superior-transaction-manager) exists. |
| **STATUS_TRANSACTION_ALREADY_ABORTED** | The transaction cannot be committed because it has been rolled back. |
| **STATUS_TRANSACTION_ALREADY_COMMITTED** | The transaction is already committed. |
| **STATUS_TRANSACTION_REQUEST_NOT_VALID** | The commit operation for this transaction has already been started. |
| **STATUS_PENDING** | Commit notifications have been queued to resource managers, and the caller specified **FALSE** for the *Wait* parameter. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **TmCommitTransaction** routine is a pointer-based version of the [ZwCommitTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcommittransaction) routine.

For information about when to use KTM's **Tm*Xxx*** routines instead of **Zw*Xxx*** routines, see [Using TmXxx Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-tmxxx-routines).

## See also

[ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[ZwCommitTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcommittransaction)

[ZwCreateTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreatetransaction)

[ZwOpenTransaction](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopentransaction)