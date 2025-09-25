# MmLockPagableDataSection function

## Description

The **MmLockPagableDataSection** routine locks an entire section of driver data into system space.

## Parameters

### `AddressWithinSection` [in]

Specifies the symbolic address of one item of data within the pageable section.

## Return value

**MmLockPagableDataSection** returns an opaque value that identifies the section. This value must be passed subsequently to **MmLockPagableSectionByHandle** or to **MmUnlockPagableImageSection**.

## Remarks

Drivers can use this routine, **MmLockPagableSectionByHandle**, and **MmUnlockPagableImageSection** to make their private data that is typically pageable locked into memory.

Data can be locked down if:

* The data is typically accessed at <= APC_LEVEL, but it might need to be accessed at higher IRQL levels for short periods.

* The driver uses the data infrequently and predictably.

For example, drivers for mixer devices use pageable-data sections. Because the driver uses sufficient data to make creating a pageable-data section worthwhile and the driver knows when the data is needed, such a driver uses **MmLockPagableDataSection**, **MmLockPagableSectionByHandle** and **MmUnlockPagableImageSection** to bring a data section into system space when needed and make it available to be paged out when not needed.

A single call to **MmLockPagableDataSection** causes the entire section, containing the referenced data, to be locked into system space.

It is an expensive operation to lock down a section. If a pageable-data section is locked down in more than one place by a driver, use **MmLockPagableDataSection** for the first request. Make subsequent lock requests by calling **MmLockPagableSectionByHandle**, passing the handle returned by **MmLockPagableDataSection**. Locking by handle significantly improves driver performance. A locked down section is unlocked by calling **MmUnlockPagableImageSection**.

The memory manager maintains a reference count on the section. A pageable-data section is only available to be paged out when the reference count is zero. Every lock request increments the count; every unlock request decrements the count. A driver must unlock a section as many times as it locks a section to ensure that such a section will be available to be paged out when the section is not needed. A handle is always valid, no matter what the count. If the count on a handle is zero and a call is made to **MmLockPagableSectionByHandle**, the count is set to one, and if the section has been paged out, it will be paged in.

Data in a pageable-data section is marked by a compiler directive. To create a pageable data section, use **#pragma data_seg ("PAGE")**, at the beginning of the data module, and **#pragma data_seg ()** at the end of the module. The keyword **PAGE** is case-sensitive, that is, **PAGE** must be capitalized.

Note that there is also a **#pragma data_seg("INIT")** that is used to make data discardable after system initialization. Except for the use of **INIT** rather than **PAGE**, the syntax is the same. However the result is not; use of the **PAGE** directive makes the data section pageable. When the **INIT** directive is used, the data in the section is discarded as soon as the driver returns from its driver entry routine or its reinitialization routine if the driver has one.

For more information about paging data, see [Making Drivers Pageable](https://learn.microsoft.com/windows-hardware/drivers/kernel/making-drivers-pageable).

## See also

[MmLockPagableCodeSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmlockpagablecodesection)

[MmLockPagableSectionByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmlockpagablesectionbyhandle)

[MmPageEntireDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmpageentiredriver)

[MmResetDriverPaging](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmresetdriverpaging)

[MmUnlockPagableImageSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunlockpagableimagesection)