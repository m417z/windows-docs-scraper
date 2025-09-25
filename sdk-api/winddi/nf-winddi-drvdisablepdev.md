# DrvDisablePDEV function

## Description

The **DrvDisablePDEV** function is used by GDI to notify a driver that the specified [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) is no longer needed.

## Parameters

### `dhpdev`

Handle to the [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) of the physical device to be disabled. This value is the handle returned by [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev).

## Remarks

If the physical device has an enabled surface, GDI calls **DrvDisablePDEV** after calling [DrvDisableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdisablesurface). The driver should free any memory and resources used by the PDEV.

**DrvDisablePDEV** is required for graphics drivers.

## See also

[DrvAssertMode](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvassertmode)

[DrvDisableSurface](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdisablesurface)

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)