# MmPageEntireDriver function

## Description

The **MmPageEntireDriver** routine causes all of a driver's code and data to be made pageable, overriding the attributes of the various sections that make up the driver's image.

## Parameters

### `AddressWithinSection` [in]

Pointer to a virtual address within the driver (for example, the address of the [DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) routine).

## Return value

**MmPageEntireDriver** returns a pointer to the beginning of the driver image in memory.

## Remarks

Use this routine to force a driver to be completely pageable. Drivers that call **MmPageEntireDriver** must not have an [InterruptService](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-kservice_routine) routine (ISR) registered for any interrupts. If the interrupt occurs while the driver is paged out, the system issues a bug check.

The effect of a call to **MmPageEntireDriver** can be undone by calling [MmResetDriverPaging](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmresetdriverpaging).

If the driver is already completely pageable, calling **MmPageEntireDriver** has no effect. For more information about paging an entire driver, see [Making Drivers Pageable](https://learn.microsoft.com/windows-hardware/drivers/kernel/making-drivers-pageable).

## See also

[MmLockPagableCodeSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmlockpagablecodesection)

[MmLockPagableDataSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmlockpagabledatasection)

[MmLockPagableSectionByHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-mmlockpagablesectionbyhandle)

[MmResetDriverPaging](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmresetdriverpaging)

[MmUnlockPagableImageSection](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-mmunlockpagableimagesection)