# TmDereferenceEnlistmentKey function

## Description

The **TmDereferenceEnlistmentKey** routine decrements the reference count for the key of a specified [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects).

## Parameters

### `Enlistment` [in]

A pointer to an enlistment object. Your component can receive this pointer as input to a [ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification) callback routine. Alternatively, your component can call [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) and supply the object handle that a previous call to [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment), [TmCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcreateenlistment), or [ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment) provided.

### `LastReference` [out, optional]

A pointer to a BOOLEAN-typed variable. This variable receives **TRUE** if the reference count is zero after **TmDereferenceEnlistmentKey** decrements it. Otherwise, the variable receives **FALSE**.

## Return value

**TmDereferenceEnlistmentKey** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_UNSUCCESSFUL** | The reference count of the specified enlistment object is zero and cannot be decremented. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The [TmReferenceEnlistmentKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmreferenceenlistmentkey) routine increments the reference count for an enlistment object's key, and the **TmDereferenceEnlistmentKey** routine decrements the count.

For information about when to use KTM's **Tm*Xxx*** routines instead of **Zw*Xxx*** routines, see [Using TmXxx Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-tmxxx-routines).

## See also

[ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification)

[TmCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcreateenlistment)

[TmReferenceEnlistmentKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmreferenceenlistmentkey)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment)