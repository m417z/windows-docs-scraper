# TmPrepareEnlistment function

## Description

The **TmPrepareEnlistment** routine initiates the prepare operation for a specified enlistment's transaction.

## Parameters

### `Enlistment` [in]

A pointer to an [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects). Your component can receive this pointer as input to a [ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification) callback routine. Alternatively, your component can call [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) and supply the object handle that a previous call to [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment), [TmCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcreateenlistment), or [ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment) provided.

### `TmVirtualClock` [in]

A pointer to a [virtual clock value](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-virtual-clock-values). This parameter is optional and can be **NULL**.

## Return value

**TmPrepareEnlistment** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_ENLISTMENT_NOT_SUPERIOR** | The caller is not a [superior transaction manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/creating-a-superior-transaction-manager) for the enlistment. |
| **STATUS_TRANSACTION_RESPONSE_NOT_ENLISTED** | The caller did not register to receive TRANSACTION_NOTIFY_PREPARE_COMPLETE notifications. |
| **STATUS_TRANSACTION_REQUEST_NOT_VALID** | The enlistment's transaction is not in a state that allows it to enter the prepare phase. |
| **STATUS_ACCESS_DENIED** | The caller does not have appropriate access to the enlistment object. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **TmPrepareEnlistment** routine is a pointer-based version of the [ZwPrepareEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntprepareenlistment) routine.

Only superior transaction managers can call **TmPrepareEnlistment**.

For information about when to use KTM's **Tm*Xxx*** routines instead of **Zw*Xxx*** routines, see [Using TmXxx Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-tmxxx-routines).

## See also

[ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification)

[TmCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcreateenlistment)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment)

[ZwPrepareEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntprepareenlistment)