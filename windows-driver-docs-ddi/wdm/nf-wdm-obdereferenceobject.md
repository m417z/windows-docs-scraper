## Description

The **ObDereferenceObject** routine decrements the given object's reference count and performs retention checks.

## Parameters

### `a` [in]

Pointer to the object's body.

## Remarks

**ObDereferenceObject** returns a value that is reserved for system use. Drivers must treat this value as VOID.

**ObDereferenceObject** decreases the reference count of an object by one. If the object was created as temporary (the OBJ_PERMANENT flag was not specified on creation), and the reference count reaches zero, the object can be deleted by the system.

A driver can delete a temporary object it created by decreasing its reference count to zero. A driver must never attempt to delete an object it did not create.

An object is permanent if it was created with the OBJ_PERMANENT object attribute flag specified. (For more information about object attributes, see [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes).) A permanent object is created with a reference count of one, so it is not deleted when the driver dereferences it. A driver can only delete a permanent object it created by using the [ZwMakeTemporaryObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwmaketemporaryobject) routine to make it temporary. Use the following steps to delete a permanent object that you created:

1. Call **ObDereferenceObject**.

1. Call the appropriate **ZwOpen*Xxx*** or **ZwCreate*Xxx*** routine to get a handle for the object, if necessary.

1. Call [ZwMakeTemporaryObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwmaketemporaryobject) with the handle obtained in step 2.

1. Call [ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) with the handle obtained in step 2.

Use [ObDereferenceObjectDeferDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobjectdeferdelete) instead of **ObDereferenceObject** for any object, particularly [Kernel Transaction Manager](https://learn.microsoft.com/windows-hardware/drivers/kernel/windows-kernel-mode-kernel-transaction-manager) (KTM) objects, when the immediate deletion by the current thread of the object (by using **ObDereferenceObject**) might result in a deadlock.

## See also

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[IoGetDeviceObjectPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetdeviceobjectpointer)

[ObDereferenceObjectDeferDelete](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obdereferenceobjectdeferdelete)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwMakeTemporaryObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-zwmaketemporaryobject)