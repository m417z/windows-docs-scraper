# ObGetObjectSecurity function

## Description

The **ObGetObjectSecurity** routine gets the security descriptor for a given object.

## Parameters

### `Object` [in]

Pointer to the object.

### `SecurityDescriptor` [out]

Pointer to a caller-supplied variable that this routine sets to the address of a buffer containing the [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor) for the given object. If the given object has no security descriptor, this variable is set to **NULL** on return from **ObGetObjectSecurity**.

### `MemoryAllocated` [out]

Pointer to a caller-supplied variable that this routine sets to **TRUE** if it allocated a buffer to contain the security descriptor.

## Return value

**ObGetObjectSecurity** either returns STATUS_SUCCESS or an error status, such as STATUS_INSUFFICIENT_RESOURCES if it could not allocate enough memory to return the requested information.

## Remarks

A successful call to **ObGetObjectSecurity** either returns a self-relative security descriptor in the buffer at *\*SecurityDescriptor* or it returns **NULL** at *\*SecurityDescriptor* if the given object has no security descriptor. For example, any unnamed object, such as an event object, has no security descriptor.

If **ObGetObjectSecurity** returns STATUS_SUCCESS, the caller must save the value returned at *MemoryAllocated*. Such a caller must pass *MemoryAllocated* in a reciprocal call to [ObReleaseObjectSecurity](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreleaseobjectsecurity) eventually, thereby restoring the reference count on the security descriptor to its original value and releasing the buffer, if any, that was allocated by **ObGetObjectSecurity**.

**ObGetObjectSecurity** should only be called at IRQL Level = PASSIVE_LEVEL with APCs enabled, otherwise deadlocks or crashes may occur.

## See also

[ObReferenceObjectByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreferenceobjectbyhandle)

[ObReleaseObjectSecurity](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-obreleaseobjectsecurity)

[SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor)