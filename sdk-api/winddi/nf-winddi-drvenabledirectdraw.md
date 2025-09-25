# DrvEnableDirectDraw function

## Description

The **DrvEnableDirectDraw** function enables hardware for DirectDraw use.

## Parameters

### `dhpdev`

Handle to the [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) returned by the driver's [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev) routine.

### `pCallBacks`

Points to the [DD_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_callbacks) structure to be initialized by the driver.

### `pSurfaceCallBacks`

Points to the [DD_SURFACECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surfacecallbacks) structure to be initialized by the driver.

### `pPaletteCallBacks`

Points to the [DD_PALETTECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_palettecallbacks) structure to be initialized by the driver.

## Return value

**DrvEnableDirectDraw** returns **TRUE** if it succeeds; otherwise, it returns **FALSE**.

## Remarks

GDI calls the driver's **DrvEnableDirectDraw** function to obtain pointers to the DirectDraw callbacks that the driver supports. The driver should set the function pointer members of [DD_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_callbacks), [DD_SURFACECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surfacecallbacks), and [DD_PALETTECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_palettecallbacks) to point to those functions that it implements. A driver should also set the corresponding bitfields in the **dwFlags** members of these structures for all supported callbacks.

A driver's **DrvEnableDirectDraw** implementation can also dedicate hardware resources such as display memory for use by DirectDraw only.

## See also

[DD_CALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_callbacks)

[DD_PALETTECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_palettecallbacks)

[DD_SURFACECALLBACKS](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surfacecallbacks)

[DrvDisableDirectDraw](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvdisabledirectdraw)

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)

[DrvGetDirectDrawInfo](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvgetdirectdrawinfo)