# DrvDisableDirectDraw function

## Description

The **DrvDisableDirectDraw** function disables hardware for DirectDraw use.

## Parameters

### `dhpdev`

Handle to the [PDEV](https://learn.microsoft.com/windows-hardware/drivers/) that was returned by the driver's [DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev) routine.

## Remarks

GDI calls the driver's **DrvDisableDirectDraw** function when the last DirectDraw application has finished running. A driver's **DrvDisableDirectDraw** implementation should clean up any software resources and reclaim any hardware resources that the driver dedicated to DirectDraw in its [DrvEnableDirectDraw](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenabledirectdraw) function.

**DrvDisableDirectDraw** can be called with a disabled [PDEV](https://learn.microsoft.com/windows-hardware/drivers/). A PDEV is disabled or enabled by calling the display driver's [DrvAssertMode](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvassertmode) function. See [Managing PDEVs](https://learn.microsoft.com/windows-hardware/drivers/display/managing-pdevs) for more information.

## See also

[DrvEnableDirectDraw](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenabledirectdraw)

[DrvEnablePDEV](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenablepdev)