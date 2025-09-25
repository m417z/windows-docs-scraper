# MmLockPagableSectionByHandle function

## Description

The **MmLockPagableSectionByHandle** routine locks a pageable code or data section into system memory by incrementing the reference count on the handle to the section.

## Parameters

### `ImageSectionHandle` [in]

The handle to a pageable code or data section. The caller obtained this handle from a previous call to the [MmLockPagableCodeSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmlockpagablecodesection) or [MmLockPagableDataSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmlockpagabledatasection) routine.

## Remarks

A driver initially calls **MmLockPagableCodeSection** or **MmLockPagableDataSection** to obtain a handle to a pageable code or data section. Thereafter, the driver can call **MmLockPagableSectionByHandle** and [MmUnlockPagableImageSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunlockpagableimagesection) to increment and decrement the reference count on the handle.

The **MmLockPagableCodeSection** or **MmLockPagableDataSection** call locks the pageable section into system memory, returns a handle to the section, and initializes the reference count on the handle to one. **MmLockPagableSectionByHandle** increments the reference count by one, and **MmUnlockPagableImageSection** decrements the reference count by one.

If the reference count on the handle is nonzero, the pageable section is locked. If the reference count is zero, the section is unlocked.

The handle to the pageable section remains valid as long as the driver stays loaded in memory. The driver can use the same handle to repeatedly lock and unlock the section. That is, the driver can reuse a handle whose reference count is zero. **MmLockPagableSectionByHandle** checks to see if the referenced section is resident in the caller's address space and, if it is, simply increments the reference count on the section. If the section is not resident, **MmLockPagableSectionByHandle** pages in the section, locks it in system space, and sets the reference count to one.

To avoid leaking system memory, the reference count on the handle must be zero when the driver is unloaded from memory. Otherwise, the pageable section will stay locked into system memory after the driver unloads.

If the driver is preparing to unload, and the reference count on the handle is nonzero, the driver should call **MmUnlockPagableImageSection** to decrement the count to zero before the unload occurs.

A driver cannot call **MmLockPagableSectionByHandle** to lock down user buffers passed in IRPs. Use **MmProbeAndLockPages** instead.

For more information about paging code and data, see [Making Drivers Pageable](https://learn.microsoft.com/windows-hardware/drivers/kernel/making-drivers-pageable).

## See also

[MmLockPagableCodeSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmlockpagablecodesection)

[MmLockPagableDataSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmlockpagabledatasection)

[MmPageEntireDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmpageentiredriver)

[MmProbeAndLockPages](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmprobeandlockpages)

[MmResetDriverPaging](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmresetdriverpaging)

[MmUnlockPagableImageSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunlockpagableimagesection)