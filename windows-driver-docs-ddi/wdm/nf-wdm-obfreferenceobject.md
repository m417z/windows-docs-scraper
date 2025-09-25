# ObfReferenceObject function

## Description

The **ObfReferenceObject** routine increments the reference count to the given object.

## Parameters

### `Object` [in]

Pointer to the object. The caller obtained this parameter either when it created the object or from a preceding call to [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) after it opened the object.

## Return value

**ObfReferenceObject** returns a value that is reserved for system use. Drivers must treat this value as VOID.

## Remarks

**ObfReferenceObject** simply increments the pointer reference count for an object, without making any access checks on the given object, as [ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle) and [ObReferenceObjectByPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbypointer) do.

**ObfReferenceObject** prevents deletion of the object at least until the driver subsequently calls its reciprocal, **ObDereferenceObject**, or closes the given object. The caller must decrement the reference count with **ObDereferenceObject** as soon as it is done with the object.

When the reference count for an object reaches zero, a kernel-mode component can remove the object from the system. However, a driver can remove only those objects that it created, and a driver should never attempt to remove any object that it did not create.

## See also

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)

[ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[ObReferenceObjectByPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbypointer)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)