# TmReferenceEnlistmentKey function

## Description

The **TmReferenceEnlistmentKey** routine increments the reference count for the key of a specified [enlistment object](https://learn.microsoft.com/windows-hardware/drivers/kernel/enlistment-objects) and retrieves the key.

## Parameters

### `Enlistment` [in]

A pointer to an enlistment object. Your component can receive this pointer as input to a [ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification) callback routine. Alternatively, your component can call [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) and supply the object handle that a previous call to [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment), [TmCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcreateenlistment), or [ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment) provided.

### `Key` [out]

A pointer to a variable that receives the enlistment object's enlistment key. The caller assigns an enlistment key when it calls [ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment) or [TmCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcreateenlistment).

## Return value

**TmReferenceEnlistmentKey** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this routine might return one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The *Key* parameter's value is **NULL**. |
| **STATUS_UNSUCCESSFUL** | The reference count of the specified enlistment object has been decremented to zero, so the reference count cannot be incremented. |
| **STATUS_INSUFFICIENT_RESOURCES** | The reference count is at its maximum value (0xFFFFFFFF) and cannot be incremented. |

The routine might return other [NTSTATUS values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The **TmReferenceEnlistmentKey** routine increments the reference count for an enlistment object's key value, and the [TmDereferenceEnlistmentKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmdereferenceenlistmentkey) routine decrements the count.

If a resource manager has defined a key value for an enlistment, the resource manager receives the key value when it calls [ZwGetNotificationResourceManager](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntgetnotificationresourcemanager) or when KTM calls the [ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification) callback routine.

While a resource manager is processing a notification, it might use the key as a pointer to a temporary memory allocation, and it might use the reference count to determine when it should deallocate the memory.

For information about when to use KTM's **Tm*Xxx*** routines instead of **Zw*Xxx*** routines, see [Using TmXxx Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-tmxxx-routines).

## See also

[ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[ResourceManagerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-ptm_rm_notification)

[TmCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmcreateenlistment)

[TmDereferenceEnlistmentKey](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-tmdereferenceenlistmentkey)

[ZwCreateEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntcreateenlistment)

[ZwOpenEnlistment](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntopenenlistment)