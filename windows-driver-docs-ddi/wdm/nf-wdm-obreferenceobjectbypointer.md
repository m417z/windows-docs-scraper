## Description

The **ObReferenceObjectByPointer** routine increments the pointer reference count for a given object.

## Parameters

### `Object` [in]

Pointer to the object's body.

### `DesiredAccess` [in]

Specifies a mask representing the requested access to the object.

### `ObjectType` [in, optional]

Pointer to the object type. *ObjectType* can be ***ExEventObjectType**, ***ExSemaphoreObjectType**, ***IoFileObjectType**, ***PsProcessType**, ***PsThreadType**, ***SeTokenObjectType**, ***TmEnlistmentObjectType**, ***TmResourceManagerObjectType**, ***TmTransactionManagerObjectType**, or ***TmTransactionObjectType**.

This parameter can also be **NULL** if *AccessMode* is **KernelMode**.

### `AccessMode` [in]

Indicates the access mode to use for the access check. It must be either **UserMode** or **KernelMode**. Lower-level drivers should specify **KernelMode**.

## Return value

**ObReferenceObjectByPointer** returns STATUS_SUCCESS when the routine has successfully incremented the reference count of the target object's body. The routine performs object type validation if the call is being performed in user mode and if the type requested by the caller doesn't match with the one from the object's body, STATUS_OBJECT_TYPE_MISMATCH is returned.
The same NTSTATUS code is returned if the requested type is a symbolic link type (**ObpSymbolicLinkObjectType**) which is not allowed by the routine, regardless of what kind of access mode is.

## Remarks

Calling this routine prevents the object from being deleted, possibly by another component's call to [ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject) or [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose). The caller must decrement the reference count with **ObDereferenceObject** as soon as it is done with the object.

## See also

[ObDereferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobject)

[ObReferenceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obfreferenceobject)

[ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)