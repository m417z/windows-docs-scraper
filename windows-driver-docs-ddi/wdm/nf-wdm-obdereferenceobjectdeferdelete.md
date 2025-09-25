## Description

The **ObDereferenceObjectDeferDelete** routine decrements the reference count for the given object, checks for object retention, and avoids deadlocks.

## Parameters

### `Object` [in]

A pointer to the body of the object.

## Remarks

**ObDereferenceObjectDeferDelete** is similar to [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) except that, when the reference count of the object reaches zero, the object manager passes the object deletion request to a worker thread. Therefore, the deletion later occurs at IRQL = PASSIVE_LEVEL.

Use **ObDereferenceObjectDeferDelete** for any object when the immediate deletion by the current thread of the object (by using **ObDereferenceObject**) might result in a deadlock.

For example, such a deadlock can occur if **ObDereferenceObject** is used to dereference a [Kernel Transaction Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-kernel-transaction-manager) (KTM) object when a higher level driver on the driver stack is holding a lock.

To avoid such deadlocks, use **ObDereferenceObjectDeferDelete** instead of **ObDereferenceObject** to dereference KTM object.

For information about object permanence and attributes, see [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject).

## See also

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)

[ObReferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obfreferenceobject)