# MmUnlockPagableImageSection function

## Description

The **MmUnlockPagableImageSection** routine releases a section of driver code or driver data, previously locked into system space with **MmLockPagableCodeSection**, **MmLockPagableDataSection** or **MmLockPagableSectionByHandle**, so the section can be paged out again.

## Parameters

### `ImageSectionHandle` [in]

Specifies the handle returned by a call to [MmLockPagableCodeSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmlockpagablecodesection) or [MmLockPagableDataSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmlockpagabledatasection).

## Remarks

The handle for a driver's pageable section must not be released if the driver has any outstanding IRPs in its device queue(s) or internal queue(s). A call to **MmUnlockPagableImageSection** restores the pageability of that entire section when there are no more references to the handle for that section.

The memory manager maintains the reference count on the handle to a section. A pageable section is only available to be paged out when the reference count is zero. Every lock request increments the count; every unlock request decrements the count. A driver must unlock a section as many times as it locks a section to make the section available to be paged out.

A handle is always valid, no matter what the count. If the count on a handle is zero and a call is made to **MmLockPagableSectionByHandle**, the count is set to one, and if the section has been paged out, it will be paged in.

In most cases, **MmUnlockPagableImageSection** is called before a driver's *Unload* routine. That is, a driver with a pageable section is likely to have its *DispatchClose* and/or *DispatchShutdown* routine call **MmUnlockPagableImageSection** before its *Unload* routine is called. However, care should be taken in unloadable drivers to release any pageable section before the driver itself is unloaded from the system.

For more information about paging code and data, see [Making Drivers Pageable](https://learn.microsoft.com/windows-hardware/drivers/kernel/making-drivers-pageable).

## See also

[MmLockPagableCodeSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmlockpagablecodesection)

[MmLockPagableDataSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmlockpagabledatasection)

[MmLockPagableSectionByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmlockpagablesectionbyhandle)

[MmPageEntireDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmpageentiredriver)

[MmResetDriverPaging](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmresetdriverpaging)