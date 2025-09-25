## Description

The *DdUnLock* callback function releases the lock held on the specified surface.

## Parameters

### `unnamedParam1`

Points to a [DD_UNLOCKDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_unlockdata) structure that contains the information required to perform the lock release.

## Return value

*DdUnLock* returns one of the following callback codes:

## Remarks

The driver does not need to verify that the memory was previously locked down by [DdLock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_lock), because DirectDraw does parameter validation before calling this routine.

*DdUnLock* can be called with a disabled [PDEV](https://learn.microsoft.com/windows-hardware/drivers/). A PDEV is disabled or enabled by calling the display driver's [DrvAssertMode](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvassertmode) function. See [Managing PDEVs](https://learn.microsoft.com/windows-hardware/drivers/display/managing-pdevs) for more information.

## See also

[DD_UNLOCKDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_unlockdata)

[DdLock](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_lock)