# TmReadOnlyEnlistment function

## Description

The **TmReadOnlyEnlistment** routine sets a specified enlistment to be read-only.

## Parameters

### `Enlistment` [in]

A pointer to an [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects). Your component can receive this pointer as input to a [ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification) callback routine. Alternatively, your component can call [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) and supply the object handle that a previous call to [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment), [TmCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcreateenlistment), or [ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment) provided.

### `TmVirtualClock` [in]

A pointer to a [virtual clock value](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-virtual-clock-values). This parameter is optional and can be **NULL**.

## Return value

**TmReadOnlyEnlistment** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_TRANSACTION_NOT_REQUESTED** | The transaction or its enlistment is not in the correct state. For example, an enlistment cannot be read-only if the ENLISTMENT_SUPERIOR flag was specified to [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment). |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **TmReadOnlyEnlistment** routine is a pointer-based version of the [ZwReadOnlyEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntreadonlyenlistment) routine.

For information about when to use KTM's **Tm*Xxx*** routines instead of **Zw*Xxx*** routines, see [Using TmXxx Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-tmxxx-routines).

## See also

[ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification)

[TmCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcreateenlistment)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment)

[ZwReadOnlyEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntreadonlyenlistment)