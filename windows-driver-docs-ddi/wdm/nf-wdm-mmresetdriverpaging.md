# MmResetDriverPaging function

## Description

The **MmResetDriverPaging** routine resets the pageable status of a driver's sections to that specified when the driver was compiled.

## Parameters

### `AddressWithinSection` [in]

A pointer to a virtual address in the driver (for example, the address of the [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine).

## Remarks

**MmResetDriverPaging** causes those routines that would not normally be pageable, to be locked into memory. Hence, image sections such as .text and .data will be locked in memory if this routine is called.

A driver that calls this routine must do so before enabling interrupts on its device.

A call to [MmPageEntireDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmpageentiredriver) is not a prerequisite to calling this routine. However, calls to **MmResetDriverPaging** do nothing if the driver's image-section attributes have never been overridden by a call to **MmPageEntireDriver**.

For more information about paging an entire driver, see [Making Drivers Pageable](https://learn.microsoft.com/windows-hardware/drivers/kernel/making-drivers-pageable).

## See also

[MmLockPagableCodeSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmlockpagablecodesection)

[MmLockPagableDataSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmlockpagabledatasection)

[MmLockPagableSectionByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmlockpagablesectionbyhandle)

[MmPageEntireDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmpageentiredriver)

[MmUnlockPagableImageSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunlockpagableimagesection)