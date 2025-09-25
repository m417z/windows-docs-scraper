# DrvDisableSurface function

## Description

The **DrvDisableSurface** function is used by GDI to notify a driver that the surface created by [DrvEnableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablesurface) for the current device is no longer needed.

## Parameters

### `dhpdev`

Handle to the physical device's [PDEV](https://learn.microsoft.com/windows-hardware/drivers/). This is the handle to the device whose surface is to be released.

## Remarks

The driver should free any memory and resources used by the surface associated with the PDEV as soon as the physical device is disabled.

If the driver has been disabled by a call to [DrvAssertMode](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvassertmode), the driver must not access the hardware during **DrvDisableSurface** because another active PDEV might be in use. Any necessary hardware changes should have been performed during the call to **DrvAssertMode**. A driver should keep track of whether it has been disabled by **DrvAssertMode** so that it can perform proper cleanup operations in **DrvDisableSurface**.

If the physical device has an enabled surface, GDI calls **DrvDisableSurface** before calling [DrvDisablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdisablepdev).

**DrvDisableSurface** is required for graphics drivers.

## See also

[DrvAssertMode](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvassertmode)

[DrvDisableDriver](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdisabledriver)

[DrvDisablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdisablepdev)

[DrvEnableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablesurface)