# ExSetResourceOwnerPointerEx function

## Description

The **ExSetResourceOwnerPointerEx** routine transfers the ownership of an executive resource from the calling thread to an owner pointer, which is a system address that identifies the resource owner.

## Parameters

### `Resource` [in, out]

A pointer to an executive resource (an opaque [ERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eresource-structures) structure) that is owned by the calling thread. The caller previously allocated this structure and initialized it by calling the [ExInitializeResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializeresourcelite) routine. For more information, see the following Remarks section.

### `OwnerPointer` [in]

A pointer value that identifies the resource owner. This parameter value is nominally a pointer to a value of type ERESOURCE_THREAD but is cast to type PVOID. The caller must set the two least significant bits of this pointer value to ones. For more information, see the following Remarks section.

### `Flags` [in]

A set of flags that can modify the operation of this routine. Set this parameter either to zero or to the following flag value:

* FLAG_OWNER_POINTER_IS_THREAD

If *Flags* = FLAG_OWNER_POINTER_IS_THREAD, *OwnerPointer* must point to a value of type ERESOURCE_THREAD, which is a pointer to an opaque thread object. If *Flags* = 0, *OwnerPointer* must point to a storage object in system memory that remains allocated until the resource is released. For more information, see the following Remarks section.

## Remarks

This routine is available in Windows 7 and later versions of the Windows operating system.

**ExSetResourceOwnerPointerEx** enables a thread, which acts as a resource manager, to transfer ownership of an executive resource, which the thread has already acquired, to another thread, which then uses the resource. The executive resource is represented by an [ERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eresource-structures) structure.

The caller must set the two least significant bits of the *OwnerPointer* parameter value to ones. The operating system uses these bits internally to distinguish an owner pointer that has been set by an **ExSetResourceOwnerPointerEx** call from a thread that has acquired a resource by calling the [ExAcquireResourceExclusiveLite](https://learn.microsoft.com/previous-versions/ff544351(v=vs.85)) or [ExAcquireResourceSharedLite](https://learn.microsoft.com/previous-versions/ff544363(v=vs.85)) routine.

The thread that calls **ExSetResourceOwnerPointerEx** to transfer ownership of a resource must be the same thread that previously called the **ExAcquireResource*Xxx*Lite** routine to acquire the resource.

If the resource-manager thread acquired the resource for exclusive access (by calling **ExAcquireResourceExclusiveLite**), the **ExSetResourceOwnerPointerEx** call transfers exclusive-access ownership to the resource-user thread. If the resource-manager thread acquired the resource for shared access (by calling **ExAcquireResourceSharedLite**), the **ExSetResourceOwnerPointerEx** call transfers shared-access ownership to the resource-user thread.

When the resource-user thread no longer needs the resource, the resource should be released. Typically, the resource-user thread releases the resource. To do so, it must call the [ExReleaseResourceForThreadLite](https://learn.microsoft.com/previous-versions/ff545585(v=vs.85)) routine. In this call, the *ThreadId* parameter value must match the value of the *OwnerPointer* parameter (including the two least significant bits) in the previous **ExSetResourceOwnerPointerEx** call that transferred ownership of the resource.

After a **ExSetResourceOwnerPointerEx** call transfers ownership of a resource, the only other [ERESOURCE routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-eresource-routines) that a driver can call for the specified resource is **ExReleaseResourceForThreadLite**. An attempt to call another **ERESOURCE** routine, such as [ExReleaseResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourcelite), for this resource is an error.

**ExSetResourceOwnerPointerEx** can operate in two significantly different modes. The mode is specified by the *Flags* parameter. To select the more versatile of the two modes, set *Flags* = FLAG_OWNER_POINTER_IS_THREAD. This *Flags* value informs the operating system that the *OwnerPointer* parameter is a pointer to the thread object of the resource-manager thread. The operating system can, if necessary, use this information to temporarily boost the priority of this thread to avoid priority inversion. To obtain the thread object pointer to use for the *OwnerPointer* value, a driver can call the [ExGetCurrentResourceThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread) routine. Remember to set the two least significant bits of the *OwnerPointer* value to ones.

If *Flags* is zero, the behavior of **ExSetResourceOwnerPointerEx** is the same as that of the legacy [ExSetResourceOwnerPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsetresourceownerpointer) routine, which is available in Windows 2000 and later versions of the Windows operating system. That is, the *OwnerPointer* parameter points to a storage object that the resource-manager thread allocates in system memory before it calls **ExSetResourceOwnerPointerEx**. In this case, the object type and value are not relevant because **ExSetResourceOwnerPointerEx** does not attempt to access the object itself. Instead, the routine simply uses the memory address of the object to identify the resource owner. The storage for the object must begin at an even four-byte boundary in memory. To prevent two drivers from inadvertently using the same owner pointer at the same time, the resource-manager thread must not release the storage for the object until the resource is released.

For more information about managing executive resources, see [Introduction to ERESOURCE Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/introduction-to-eresource-routines).

## See also

[ERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eresource-structures)

[ExAcquireResourceExclusiveLite](https://learn.microsoft.com/previous-versions/ff544351(v=vs.85))

[ExAcquireResourceSharedLite](https://learn.microsoft.com/previous-versions/ff544363(v=vs.85))

[ExGetCurrentResourceThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psgetcurrentthread)

[ExInitializeResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializeresourcelite)

[ExReleaseResourceForThreadLite](https://learn.microsoft.com/previous-versions/ff545585(v=vs.85))

[ExReleaseResourceLite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exreleaseresourcelite)

[ExSetResourceOwnerPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exsetresourceownerpointer)