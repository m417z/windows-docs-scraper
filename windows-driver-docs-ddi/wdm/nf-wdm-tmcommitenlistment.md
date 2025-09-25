# TmCommitEnlistment function

## Description

The **TmCommitEnlistment** routine initiates the commit operation for a specified enlistment's transaction.

## Parameters

### `Enlistment` [in]

A pointer to an [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects). Your component can receive this pointer as input to a [ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification) callback routine. Alternatively, your component can call [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) and supply the object handle that a previous call to [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment), [TmCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcreateenlistment), or [ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment) provided.

### `TmVirtualClock` [in]

A pointer to a [virtual clock value](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-virtual-clock-values). This parameter is optional and can be **NULL**.

## Return value

**TmCommitEnlistment** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_ENLISTMENT_NOT_SUPERIOR** | The caller is not a [superior transaction manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-superior-transaction-manager) for the enlistment. |
| **STATUS_TRANSACTION_RESPONSE_NOT_ENLISTED** | The caller did not register to receive TRANSACTION_NOTIFY_COMMIT_COMPLETE notifications. |
| **STATUS_TRANSACTION_REQUEST_NOT_VALID** | The enlistment's transaction is not in a state that enables it to be committed. |
| **STATUS_TRANSACTION_NOT_ACTIVE** | The commit operation for this transaction has already been started. |
| **STATUS_TRANSACTION_ALREADY_ABORTED** | The transaction cannot be committed because it has been rolled back. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **TmCommitEnlistment** routine is a pointer-based version of the [ZwCommitEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcommitenlistment) routine.

Only superior transaction managers can call **TmCommitEnlistment**.

For information about when to use KTM's **Tm*Xxx*** routines instead of **Zw*Xxx*** routines, see [Using TmXxx Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-tmxxx-routines).

## See also

[ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification)

[TmCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcreateenlistment)

[ZwCommitEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcommitenlistment)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment)